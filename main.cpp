#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage();
void saveImage();
void makephotoblackwhite();

int main(){
    loadImage();
    makephotoblackwhite();
    saveImage();
}

void loadImage(){
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage(){
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_________________________________________
void makephotoblackwhite(){
    for( int i = 0 ; i < SIZE ; i++ ){
        for( int j = 0 ; j < SIZE ; j++ ){
            if(image[i][j] <= 126 ){
                image[i][j]  = 0 ;
            }
            else if ( image[i][j] > 126 ){
                image[i][j] = 255 ;
            }
        }
    }
}
