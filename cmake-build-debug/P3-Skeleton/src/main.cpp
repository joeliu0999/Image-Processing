#include <iostream>
#include <fstream>
#include "image-processor.h"

int part1();
int part2();
int part3();
int part4();
int part5();
int part6();
int part7();
int part8();
int part9();
int part10();

bool compare(string filename,string filename2);
void test();

int main()
{
    part1();
    part2();
    part3();
    part4();
    part5();
    part6();
    part7();
    part8();
    part9();
    part10();

    test();
    return 0;
}
//mutiply blending
int part1(){
    //first file
    ifstream inStream1("P3-Skeleton/input/layer1.tga",ios::binary);
    if(!inStream1.is_open()) return(1);
    Header headerData1;
    get_header(inStream1,headerData1);
    int size1=headerData1.width*headerData1.height*headerData1.bitsPerPixel;
    unsigned char *data1= new unsigned char[size1];

    inStream1.read((char*)data1,size1);
    inStream1.close();

    //second file
    ifstream inStream2("P3-Skeleton/input/pattern1.tga",ios::binary);
    Header headerData2;
    if(!inStream2.is_open()) return(1);
    get_header(inStream2,headerData2);
    int size2=headerData2.width*headerData2.height*headerData2.bitsPerPixel;
    unsigned char *data2= new unsigned char[size2];

    inStream2.read((char*)data2,size2);
    inStream2.close();

    unsigned char* data4=new unsigned char[size1];
    data4=mutiply_blending(data1,data2,size1);
    ofstream outStream("P3-Skeleton/output/part1.tga",ios::binary);
    fill_header(outStream,headerData1);
    outStream.write((char*)data4,size2);
    outStream.close();

    delete[] data1;
    delete[] data2;
    delete[] data4;
    return 0;
}
//subtract blending
int part2(){
    ifstream inStream1("P3-Skeleton/input/car.tga",ios::binary);
    if(!inStream1.is_open()) return(1);
    Header headerData1;
    get_header(inStream1,headerData1);
    int size1=headerData1.width*headerData1.height*headerData1.bitsPerPixel;
    unsigned char *data1= new unsigned char[size1];
    inStream1.read((char*)data1,size1);
    inStream1.close();

    ifstream inStream2("P3-Skeleton/input/layer2.tga",ios::binary);
    Header headerData2;
    if(!inStream2.is_open()) return(1);
    get_header(inStream2,headerData2);
    int size2=headerData2.width*headerData2.height*headerData2.bitsPerPixel;
    unsigned char *data2= new unsigned char[size2];
    inStream2.read((char*)data2,size2);
    inStream2.close();

    unsigned char* data4=new unsigned char[size1];
    data4=subtract_blending(data1,data2,size1);
    ofstream outStream("P3-Skeleton/output/part2.tga",ios::binary);
    fill_header(outStream,headerData1);
    outStream.write((char*)data4,size2);
    outStream.close();
    return 0;
}
//mutiply blending & screen blending on layer1, pattern2, and text
int part3(){
    int size1=get_file_length("P3-Skeleton/input/layer1.tga");
    unsigned char* data1=read_file("P3-Skeleton/input/layer1.tga");

    int size2=get_file_length("P3-Skeleton/input/pattern2.tga");
    unsigned char* data2=read_file("P3-Skeleton/input/pattern2.tga");

    unsigned char* data3= read_file("P3-Skeleton/input/text.tga");
    Header headerData1=get_header_object("P3-Skeleton/input/text.tga");

    unsigned char* data4= mutiply_blending(data1,data2,size1);

    unsigned char* data5=screen_blending(data4,data3,size1);

    ofstream outStream("P3-Skeleton/output/part3.tga",ios::binary);
    fill_header(outStream,headerData1);
    outStream.write((char*)data5,size1);
    outStream.close();
    delete[] data1;
    delete[] data2;
    delete[] data3;
    delete[] data4;
    delete[] data5;
    return 0;
}
//mutiply blending & subtract blending on layer2, circles, and pattern2
int part4(){
    int size1=get_file_length("P3-Skeleton/input/layer2.tga");
    unsigned char* data1=read_file("P3-Skeleton/input/layer2.tga");

    int size2=get_file_length("P3-Skeleton/input/circles.tga");
    unsigned char* data2=read_file("P3-Skeleton/input/circles.tga");

    unsigned char* data3= read_file("P3-Skeleton/input/pattern2.tga");
    Header headerData1=get_header_object("P3-Skeleton/input/pattern2.tga");

    unsigned char* data4= mutiply_blending(data1,data2,size1);

    unsigned char* data5=subtract_blending(data4,data3,size1);

    ofstream outStream("P3-Skeleton/output/part4.tga",ios::binary);
    fill_header(outStream,headerData1);
    outStream.write((char*)data5,size1);
    outStream.close();
    delete[] data1;
    delete[] data2;
    delete[] data3;
    delete[] data4;
    delete[] data5;
    return 0;
}
//overlay layer1(top) & pattern1
int part5(){
    int size1=get_file_length("P3-Skeleton/input/layer1.tga");
    unsigned char* data1=read_file("P3-Skeleton/input/layer1.tga");

    int size2=get_file_length("P3-Skeleton/input/pattern1.tga");
    unsigned char* data2=read_file("P3-Skeleton/input/pattern1.tga");
    Header headerData1=get_header_object("P3-Skeleton/input/pattern1.tga");

    unsigned char* data3=overlay_blending(data1,data2,size1);
    ofstream outStream("P3-Skeleton/output/part5.tga",ios::binary);
    fill_header(outStream,headerData1);
    outStream.write((char*)data3,size1);
    outStream.close();
    return 0;
}
//add 200 to green channel
int part6(){
    int size1=get_file_length("P3-Skeleton/input/car.tga");
    unsigned char* data1=read_file("P3-Skeleton/input/car.tga");
    Header headerData1=get_header_object("P3-Skeleton/input/car.tga");

    for (int i=1;i<size1;i+=3){
        if(data1[i]+200>255) data1[i]=255;
        else data1[i]+=200;
    }

    ofstream outStream("P3-Skeleton/output/part6.tga",ios::binary);
    fill_header(outStream,headerData1);
    outStream.write((char*)data1,size1);
    outStream.close();
    delete[] data1;
    return 0;
}
//red channel*4, blue*0
int part7(){
    int size1=get_file_length("P3-Skeleton/input/car.tga");
    unsigned char* data1=read_file("P3-Skeleton/input/car.tga");
    Header headerData1=get_header_object("P3-Skeleton/input/car.tga");

    for (int i=2;i<size1;i+=3){
        if(data1[i]*4>255) data1[i]=255;
        else data1[i]*=4;
    }
    for(int i=0;i<size1;i+=3) data1[i]=0;

    ofstream outStream("P3-Skeleton/output/part7.tga",ios::binary);
    fill_header(outStream,headerData1);
    outStream.write((char*)data1,size1);
    outStream.close();
    delete[] data1;
    return 0;
}
//write different color to different channel
int part8(){
    int size1=get_file_length("P3-Skeleton/input/car.tga");
    unsigned char* data1=read_file("P3-Skeleton/input/car.tga");
    Header headerData1=get_header_object("P3-Skeleton/input/car.tga");

    //red
    unsigned char* dataR= new unsigned char[size1];
    for(int i=2;i<size1;i++){
        if(i%3==2) {
            dataR[i]=data1[i];
            dataR[i-1]=data1[i];
            dataR[i-2]=data1[i];
        }
    }
    ofstream outStream("P3-Skeleton/output/part8_r.tga",ios::binary);
    fill_header(outStream,headerData1);
    outStream.write((char*)dataR,size1);
    outStream.close();
    //green
    unsigned char* dataG= new unsigned char[size1];
    for(int i=1;i<size1;i++){
        if(i%3==1) {
            dataG[i]=data1[i];
            dataG[i-1]=data1[i];
            dataG[i+1]=data1[i];
        }
    }
    ofstream outStreamG("P3-Skeleton/output/part8_g.tga",ios::binary);
    fill_header(outStreamG,headerData1);
    outStreamG.write((char*)dataG,size1);
    outStreamG.close();
    //blue
    unsigned char* dataB= new unsigned char[size1];
    for(int i=0;i<size1;i++){
        if(i%3==0) {
            dataB[i]=data1[i];
            dataB[i+1]=data1[i];
            dataB[i+2]=data1[i];
        }
    }
    ofstream outStreamB("P3-Skeleton/output/part8_b.tga",ios::binary);
    fill_header(outStreamB,headerData1);
    outStreamB.write((char*)dataB,size1);
    outStreamB.close();
    delete[] dataR;
    delete[] dataB;
    delete[] dataG;
    delete[] data1;
    return 0;
}
//combine 3 different channel into one
int part9(){
    int size1=get_file_length("P3-Skeleton/input/layer_red.tga");
    unsigned char* dataR=read_file("P3-Skeleton/input/layer_red.tga");
    Header headerData1=get_header_object("P3-Skeleton/input/layer_red.tga");

    unsigned char* dataG=read_file("P3-Skeleton/input/layer_green.tga");
    unsigned char* dataB=read_file("P3-Skeleton/input/layer_blue.tga");

    unsigned char* data1=new unsigned char[size1];
    for(int i=0;i<size1;i++){
        if(i%3==0) data1[i]=dataB[i];
        if(i%3==1) data1[i]=dataG[i];
        if(i%3==2) data1[i]=dataR[i];
    }

    ofstream outStreamG("P3-Skeleton/output/part9.tga",ios::binary);
    fill_header(outStreamG,headerData1);
    outStreamG.write((char*)data1,size1);
    outStreamG.close();
    delete[] data1;
    delete[] dataB;
    delete[] dataG;
    delete[] dataR;
    return 0;
}
//flip image
int part10(){

    int size1=get_file_length("P3-Skeleton/input/text2.tga");
    unsigned char* data1=read_file("P3-Skeleton/input/text2.tga");
    Header headerData1=get_header_object("P3-Skeleton/input/text2.tga");


    unsigned char* dataFlip=new unsigned char[size1];
    for(int i=0;i<size1;i+=3){
        dataFlip[i+2]=data1[size1-1-i];
    }
    for(int i=1;i<size1;i+=3){
        dataFlip[i]=data1[size1-1-i];
    }
    for(int i=2;i<size1;i+=3){
        dataFlip[i-2]=data1[size1-1-i];
    }

    ofstream outStreamG("P3-Skeleton/output/part10.tga",ios::binary);
    fill_header(outStreamG,headerData1);
    outStreamG.write((char*)dataFlip,size1);
    outStreamG.close();
    delete[] data1;
    delete[] dataFlip;
}


bool compare(string filename1,string filename2){
    int size=get_file_length(filename1);
    unsigned char* data1=read_file(filename1);

    unsigned char* data2=read_file(filename2);

    for(int i=0;i<size;i++){
        if(data1[i]!=data2[i]) return false;
    }
    return true;

}
void test(){
    int passCount=0;
    if(compare("P3-Skeleton/output/part1.tga","P3-Skeleton/examples/EXAMPLE_part1.tga")){
        cout<<"Test #1...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #1...... Failed!"<<endl;

    if(compare("P3-Skeleton/output/part2.tga","P3-Skeleton/examples/EXAMPLE_part2.tga")){
        cout<<"Test #2...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #2...... Failed!"<<endl;

    if(compare("P3-Skeleton/output/part3.tga","P3-Skeleton/examples/EXAMPLE_part3.tga")){
        cout<<"Test #3...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #3...... Failed!"<<endl;

    if(compare("P3-Skeleton/output/part4.tga","P3-Skeleton/examples/EXAMPLE_part4.tga")){
        cout<<"Test #4...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #4...... Failed!"<<endl;

    if(compare("P3-Skeleton/output/part5.tga","P3-Skeleton/examples/EXAMPLE_part5.tga")){
        cout<<"Test #5...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #5...... Failed!"<<endl;

    if(compare("P3-Skeleton/output/part6.tga","P3-Skeleton/examples/EXAMPLE_part6.tga")){
        cout<<"Test #6...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #6...... Failed!"<<endl;

    if(compare("P3-Skeleton/output/part7.tga","P3-Skeleton/examples/EXAMPLE_part7.tga")){
        cout<<"Test #7...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #1...... Failed!"<<endl;

    if(compare("P3-Skeleton/output/part8_r.tga","P3-Skeleton/examples/EXAMPLE_part8_r.tga")){
        cout<<"Test #8...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #8...... Failed!"<<endl;

    if(compare("P3-Skeleton/output/part8_g.tga","P3-Skeleton/examples/EXAMPLE_part8_g.tga")){
        cout<<"Test #9...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #9...... Failed!"<<endl;

    if(compare("P3-Skeleton/output/part8_b.tga","P3-Skeleton/examples/EXAMPLE_part8_b.tga")){
        cout<<"Test #10...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #10...... Failed!"<<endl;

    if(compare("P3-Skeleton/output/part9.tga","P3-Skeleton/examples/EXAMPLE_part9.tga")){
        cout<<"Test #11...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #11...... Failed!"<<endl;

    if(compare("P3-Skeleton/output/part10.tga","P3-Skeleton/examples/EXAMPLE_part10.tga")){
        cout<<"Test #12...... Passed!"<<endl;
        passCount+=1;
    }
    else cout<<"Test #12...... Failed!"<<endl;

    cout<<"Test results: "<<passCount<<"/12";

}
//,write test/where is make file