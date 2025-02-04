#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE] ;

void loadimagetwo() ;
void loadImage();
void saveImage();
void makephotoblackwhite();
void makephotoinverted() ;
void makephotofliped() ;
void makephotomerge();
void makephotodarkerorlighter();

int main(){
    while(true){
        loadImage();
        int filternumber ;
        cout << "please select a filter to apply :\n" ;
        cout << "1- BLACK & WHITE FILTER\n" ;
        cout << "2- INVERT FILTER\n" ;
        cout << "3- flip image\n" ;
        cout << "4- make merge\n" ;
        cout << "5- make photo darker or lighter\n" ;
        cout << "please enter the filter number :/" ;
        cin >> filternumber ;
        if ( filternumber == 1 ){
            makephotoblackwhite();
        }
        else if ( filternumber == 2 ){
            makephotoinverted();
        }
        else if ( filternumber == 3){
            makephotofliped();
        }
        else if ( filternumber == 4 ){
            makephotomerge();
        }
        else if ( filternumber == 5 ){
            makephotodarkerorlighter();
        }

        saveImage();
        cout << "please choose from 1 or 0 to exit ; " ;
        int x ;
        cin >> x ;
        if ( x == 0 ){
            break ;
        }
    }
}


void loadImage(){
    char imageFileName[100];
    // Get gray scale image file name
    cout << "please Enter file name of the image to process: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}


void loadimagetwo(){
    char  imageFileNametwo[100] ;
    // Get gray scale image file name
    cout << "please Enter THE SECONED file name of the image to process: ";
    cin >> imageFileNametwo;

    // Add to it .bmp extension and load image
    strcat(imageFileNametwo, ".bmp");
    readGSBMP(imageFileNametwo, image2);
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
            image[i][j] = 255-image[i][j] ;
        }
    }
}


void makephotofliped(){
    int x ;
    cout << "choose number to flip the iamge from \n1-horizontal\n2-vertical\n" ;
    cin >> x ;
    unsigned char image2[SIZE][SIZE] ;
    for ( int i = 0 ; i < SIZE ; i++ ){
        for ( int j = 0 ; j < SIZE ; j++ ){
            image2[i][j]= image[i][j] ;
        }
    }
    if ( x == 2 ){
        for ( int i = 0 ; i < SIZE ; i++ ){
            for ( int j = 0 ; j < SIZE ; j++ ){
                if ( i < 126 ){
                image[i][j] = image[255-i][j] ;
                }
                if ( i > 126){
                    image[i][j] = image2[255-i][j] ;
                }
            }
        }
    }
    if ( x == 1 ){
        for ( int i = 0 ; i < SIZE ; i++ ){
            for ( int j = 0 ; j < SIZE ; j++ ){
                if ( j < 126){
                image [i][j] = image[i][255-j] ;
                }
                if ( j > 126 ){
                    image[i][j] = image2[i][255-j] ;
                }
            }
        }
    }
}


void makephotomerge(){
    loadimagetwo() ;
    for( int i = 0 ; i < SIZE ; i++ ){
        for( int j = 0 ; j < SIZE ; j++ ){
            image[i][j] = (image[i][j]+image2[i][j]) / 2;
        }
    }
}


void makephotodarkerorlighter(){
    int x ;
    cout << "choose the number to make the filter\n1_light up the photo\n2_make the photo more dark" ;
    cin >> x ;
    for ( int i = 0 ; i < SIZE ; i++ ){
        for ( int j = 0 ; j < SIZE ; j++ ){
            if ( x == 1 ){
                if (image[i][j] < 126)
                    image[i][j] = (image[i][j]) * 2 ;
            }
            else if ( x == 2 ){
                image[i][j] =  (image[i][j]) / 2 ;
            }
        }
    }
}