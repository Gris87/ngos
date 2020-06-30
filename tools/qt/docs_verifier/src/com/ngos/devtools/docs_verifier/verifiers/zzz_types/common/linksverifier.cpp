#include "linksverifier.h"

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "src/other/docsverificationfiletype.h"



LinksVerifier::LinksVerifier()
    : BaseDocsVerifier(VERIFICATION_ANY_FILE_TYPE)
    , mLinkRegExp("http[s]?:\\/\\/[\\w\\-.\\/%?=]+")
{
    // Nothing
}

void LinksVerifier::verify(DocsWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore LinksVerifier");
        removeComments(line);



        QRegularExpressionMatchIterator matches = mLinkRegExp.globalMatch(line);

        while (matches.hasNext())
        {
            QRegularExpressionMatch match = matches.next();



            QString htmlLink = match.captured(0);

            if (
                !htmlLink.startsWith("http://localhost/")
                &&
                !htmlLink.startsWith("https://localhost/")
                &&
                !htmlLink.startsWith("https://%")
               )
            {
                QNetworkRequest request;
                request.setUrl(QUrl(htmlLink));

                QNetworkAccessManager  manager;
                QNetworkReply         *reply = manager.get(request);



                QEventLoop waitLoop;

                QObject::connect(reply, SIGNAL(metaDataChanged()),                  &waitLoop, SLOT(quit()));
                QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), &waitLoop, SLOT(quit()));

                waitLoop.exec();



                QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

                if (
                    statusCode.toInt() < 200
                    ||
                    statusCode.toInt() >= 400
                   )
                {
                    worker->addWarning(path, i, QString("Link is unavailable: %1 (%2)").arg(htmlLink).arg(statusCode.toInt()));
                }

                delete reply;
            }
        }
    }
}



LinksVerifier linksVerifierInstance;
