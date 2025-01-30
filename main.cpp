#include <algorithm>
#include <iostream>
#include <string>
#include "bmplib.cpp"

// SIZE = 256

unsigned char image[SIZE][SIZE];

// functions
int loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Please enter file name of the image to process: ";
    
    cin >> imageFileName;
    

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    if (readGSBMP(imageFileName, image)==1) {
        return 0;
    }
    return 1;
}

void saveImage () {

    char imageFileName[100];
    // Get gray scale image target file name
    cout << "\nEnter the target image file output name: ";

    cin.ignore();
    cin.getline(imageFileName,99);

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}



int main(){
    unsigned char image[SIZE][SIZE];
    if(readGSBMP("photographer144.bmp", image) == 1){
        cout << "error";
    }
    
    writeGSBMP("photographer3.bmp", image);
}