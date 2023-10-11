//
// Created by User on 11/14/2022.
//
#ifndef PROJECT_3_IMAGE_PROCESSOR_H
#define PROJECT_3_IMAGE_PROCESSOR_H
#include <iostream>
#include <string>
using namespace std;
struct Header
{
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
};

unsigned char* read_file(string fileName);
int get_file_length(string filename);
Header get_header_object(string fileName);
void get_header(ifstream &inStream,Header &theHeader);
void fill_header(ofstream &outStream,Header &theHeader);
unsigned char* mutiply_blending(unsigned char* data1,unsigned char* data2, int size);
unsigned char* subtract_blending(unsigned char* carData,unsigned char* layerData, int const size);
unsigned char* screen_blending(unsigned char* dataA,unsigned char* dataB, int const size);
unsigned char* overlay_blending(unsigned char* dataA, unsigned char* dataB, int size);


#endif //PROJECT_3_IMAGE_PROCESSOR_H
