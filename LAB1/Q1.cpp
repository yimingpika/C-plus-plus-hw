#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int xRes=100, yRes=100;
    
    float **xtable; // pointer to pointer[s]
    xtable = new float*[yRes]; // NOTE how we do this!
    
    for(int i=0;i<yRes;i++) {
        xtable[i] = new float[xRes]; // each row points to xRes elements ("columns")
    }
    
    for(int i=0;i<yRes/2;i++){
        for(int j=0;j<xRes/2;j++){
            xtable[i][j]=0;
        }
    }
    
    for(int i=yRes/2;i<yRes;i++){
        for(int j=0;j<xRes/2;j++){
            xtable[i][j]=255;
        }
    }
    
    for(int i=0;i<yRes/2;i++){
        for(int j=xRes/2;j<xRes;j++){
            xtable[i][j]=255;
        }
    }
    
    for(int i=yRes/2;i<yRes;i++){
        for(int j=xRes/2;j<xRes;j++){
            xtable[i][j]=0;
        }
    }
    
    ofstream pgmFile("myImg.pgm");
    // header
    pgmFile << "P2" << endl;
    pgmFile << xRes << " " << yRes << endl; // how many columns, how many rows
    pgmFile << 255 << endl; // largest pixel value we'll be outputting (below)
    
    // pixel data
    for(int i=0;i<yRes;i++){
        for(int j=0;j<xRes;j++){
            pgmFile << xtable[i][j] << " ";
        }// next column
        pgmFile << endl;
    }// next row
    
    // all done!
    pgmFile.close();
    
    return 0;
}
