#include <iostream>
#include <fstream>
#include "image-processor.h"
using namespace std;

//return the data for a specified file
unsigned char* read_file(string fileName){
    ifstream inStream1(fileName,ios::binary);
    if(!inStream1.is_open()) cout<<"can't open file";
    Header headerData1;
    get_header(inStream1,headerData1);
    int size1=headerData1.width*headerData1.height*3;
    unsigned char *data1= new unsigned char[size1];
    inStream1.read((char*)data1,size1);
    inStream1.close();
    return data1;
}
//return the length of a file
int get_file_length(string fileName){
    ifstream inStream1(fileName,ios::binary);
    if(!inStream1.is_open()) cout<<"can't open file";
    Header headerData1;
    get_header(inStream1,headerData1);
    int size1=headerData1.width*headerData1.height*3;
    inStream1.close();
    return size1;
}
//return a header object storing all the header information
Header get_header_object(string fileName){
    ifstream inStream1(fileName,ios::binary);
    if(!inStream1.is_open()) cout<<"can't open file";
    Header headerData1;
    get_header(inStream1,headerData1);
    return headerData1;
}
void get_header(ifstream &inStream,Header &theHeader){
    inStream.read(&theHeader.idLength, sizeof(theHeader.idLength));
    inStream.read(&theHeader.colorMapType, sizeof(theHeader.colorMapType));
    inStream.read(&theHeader.dataTypeCode, sizeof(theHeader.dataTypeCode));
    inStream.read((char*)&theHeader.colorMapOrigin, sizeof(theHeader.colorMapOrigin));
    inStream.read((char*)&theHeader.colorMapLength, sizeof(theHeader.colorMapLength));
    inStream.read((char*)&theHeader.colorMapDepth, sizeof(theHeader.colorMapDepth));
    inStream.read((char*)&theHeader.xOrigin, sizeof(theHeader.xOrigin));
    inStream.read((char*)&theHeader.yOrigin, sizeof(theHeader.yOrigin));
    inStream.read((char*)&theHeader.width, sizeof(theHeader.width));
    inStream.read((char*)&theHeader.height, sizeof(theHeader.height));
    inStream.read(&theHeader.bitsPerPixel, sizeof(theHeader.bitsPerPixel));
    inStream.read(&theHeader.imageDescriptor, sizeof(theHeader.imageDescriptor));
}
void fill_header(ofstream &outStream,Header &theHeader){
    outStream.write(&theHeader.idLength, sizeof(theHeader.idLength));
    outStream.write(&theHeader.colorMapType, sizeof(theHeader.colorMapType));
    outStream.write(&theHeader.dataTypeCode, sizeof(theHeader.dataTypeCode));
    outStream.write((char*)&theHeader.colorMapOrigin, sizeof(theHeader.colorMapOrigin));
    outStream.write((char*)&theHeader.colorMapLength, sizeof(theHeader.colorMapLength));
    outStream.write((char*)&theHeader.colorMapDepth, sizeof(theHeader.colorMapDepth));
    outStream.write((char*)&theHeader.xOrigin, sizeof(theHeader.xOrigin));
    outStream.write((char*)&theHeader.yOrigin, sizeof(theHeader.yOrigin));
    outStream.write((char*)&theHeader.width, sizeof(theHeader.width));
    outStream.write((char*)&theHeader.height, sizeof(theHeader.height));
    outStream.write(&theHeader.bitsPerPixel, sizeof(theHeader.bitsPerPixel));
    outStream.write(&theHeader.imageDescriptor, sizeof(theHeader.imageDescriptor));
}
//C=A*B
unsigned char* mutiply_blending(unsigned char* data1,unsigned char* data2, int size){
    unsigned char* data3=new unsigned char[size];
    for(int i=0;i<size;i++){
        float temp=(float)data1[i]/255*(float)data2[i]/255*255+0.5f;
        data3[i]=(unsigned char)temp;
    }
    return data3;
}
//C=A-B car-layer2
unsigned char* subtract_blending(unsigned char* carData,unsigned char* layerData, int const size){
    unsigned char* data3=new unsigned char[size];
    for(int i=0;i<size;i++){
        char temp;
        if (carData[i]<layerData[i]) temp=0;
        else temp=carData[i]-layerData[i];
        data3[i]=temp;
    }
    return data3;
}
//C=1-(1-A)*(1-B)
unsigned char* screen_blending(unsigned char* dataA,unsigned char* dataB, int size){
    unsigned char* data3=new unsigned char[size];
    for(int i=0;i<size;i++){
        float temp=(1-((1-(((float)dataA[i])/255))*(1-(float)dataB[i]/255)))*255+0.5f;
        data3[i]=(unsigned char)temp;
    }
    return data3;
}
//B<=0.5: C=2*A*B
//B>0.5: C=1-2*(1-A)*(1-B)
unsigned char* overlay_blending(unsigned char* dataA, unsigned char* dataB, int size){
    unsigned char* data3=new unsigned char[size];
    for(int i=0;i<size;i++){
        if((float)dataB[i]/255<=0.5){
            float temp=2*(float)dataA[i]/255*(float)dataB[i]/255*255+0.5f;
            data3[i]=(unsigned char)temp;
        }
        else{
            float temp=(1-2*((1-(((float)dataA[i])/255))*(1-(float)dataB[i]/255)))*255+0.5f;
            data3[i]=(unsigned char)temp;
        }
    }
    return data3;
}
