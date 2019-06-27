#ifndef JPEGDEFINEQUANTIZATIONTABLEMARKER_H
#define JPEGDEFINEQUANTIZATIONTABLEMARKER_H



#include <common/src/bits64/graphics/jpeg/jpegmarkerheader.h>
#include <common/src/bits64/graphics/jpeg/jpegquantizationtable.h>



struct JpegDefineQuantizationTableMarker
{
    JpegMarkerHeader      header;
    JpegQuantizationTable tables[0];
};



#endif // JPEGDEFINEQUANTIZATIONTABLEMARKER_H
