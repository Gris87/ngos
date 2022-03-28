#include "linksverifier.h"                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QEventLoop>                                                                                                                                                                                    // Colorize: green
#include <QNetworkAccessManager>                                                                                                                                                                         // Colorize: green
#include <QNetworkReply>                                                                                                                                                                                 // Colorize: green
#include <QNetworkRequest>                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/docs_verifier/other/docsverificationfiletype.h>                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
LinksVerifier::LinksVerifier()                                                                                                                                                                           // Colorize: green
    : BaseDocsVerifier(VERIFICATION_ANY_FILE_TYPE)                                                                                                                                                       // Colorize: green
    , mLinkRegExp("http[s]?:\\/\\/[\\w\\-.\\/%?=]+") // https://yandex.ru                                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void LinksVerifier::verify(DocsWorkerThread *worker, const QString &path, const QString & /*content*/, const QStringList &lines)                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    for (qint64 i = 0; i < lines.size(); ++i)                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QString line = lines.at(i);                                                                                                                                                                      // Colorize: green
        VERIFIER_IGNORE(line, "// Ignore LinksVerifier");                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        QRegularExpressionMatchIterator matches = mLinkRegExp.globalMatch(line);                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        while (matches.hasNext())                                                                                                                                                                        // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            QRegularExpressionMatch match = matches.next();                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            QString htmlLink = match.captured(0);                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (                                                                                                                                                                                         // Colorize: green
                !htmlLink.startsWith("http://localhost/")                                                                                                                                                // Colorize: green
                &&                                                                                                                                                                                       // Colorize: green
                !htmlLink.startsWith("https://localhost/")                                                                                                                                               // Colorize: green
                &&                                                                                                                                                                                       // Colorize: green
                !htmlLink.startsWith("https://%")                                                                                                                                                        // Colorize: green
               )                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                QNetworkAccessManager  manager;                                                                                                                                                          // Colorize: green
                QNetworkReply         *reply;                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                // Send network request                                                                                                                                                                  // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    QNetworkRequest request;                                                                                                                                                             // Colorize: green
                    request.setUrl(QUrl(htmlLink));                                                                                                                                                      // Colorize: green
                    reply = manager.get(request);                                                                                                                                                        // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                // Wait for finish                                                                                                                                                                       // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    QEventLoop waitLoop;                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    QObject::connect(reply, SIGNAL(metaDataChanged()),                          &waitLoop, SLOT(quit()));                                                                                // Colorize: green
                    QObject::connect(reply, SIGNAL(errorOccurred(QNetworkReply::NetworkError)), &waitLoop, SLOT(quit()));                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    waitLoop.exec();                                                                                                                                                                     // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                // Check status code                                                                                                                                                                     // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                    if (                                                                                                                                                                                 // Colorize: green
                        statusCode.toInt() < 200                                                                                                                                                         // Colorize: green
                        ||                                                                                                                                                                               // Colorize: green
                        statusCode.toInt() >= 400                                                                                                                                                        // Colorize: green
                       )                                                                                                                                                                                 // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        worker->addWarning(path, i, QString("Link is unavailable: %1 (%2)")                                                                                                              // Colorize: green
                                                                .arg(htmlLink)                                                                                                                            // Colorize: green
                                                                .arg(statusCode.toInt())                                                                                                                  // Colorize: green
                        );                                                                                                                                                            // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                delete reply;                                                                                                                                                                            // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
LinksVerifier linksVerifierInstance;                                                                                                                                                                     // Colorize: green
