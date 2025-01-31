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
void makephotoinverted() ;
    int filternumber ;

int main(){
    loadImage();
    if ( filternumber == 1 ){
        makephotoblackwhite();
    }
    else if ( filternumber == 2 ){
        makephotoinverted();
    }
    saveImage();
}

void loadImage(){
    char imageFileName[100];
    // Get gray scale image file name
    cout << "ahlan ya user ya habibi :) \nplease Enter file name of the image to process: \n\n";
    cout << "please select a filter to apply or 0 to exit:\n" ;
    cout << "1_BLACK & WHITE FILTER\n2_INVERT FILTER\n" ;
    cout << "please enter the filter number :/" ;
    cin >> filternumber ;
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

//________________________________________
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
void makephotoinverted(){
    for( int i = 0 ; i < SIZE ; i++ ){
        for( int j = 0 ; j < SIZE ; j++ ){
            if ( image[i][j] <= 126 ){
                image[i][j] = 255 ;
            }
            else if ( image[i][j] > 126 ){
                image[i][j] = 0 ;
            }
         }
    }
}

