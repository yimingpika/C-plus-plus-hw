#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class array2D{
protected:
    int xRes, yRes;
    float **xtable;
    
public:
    array2D(int xResolution = 1, int yResolution = 1){
        xRes = xResolution, yRes = yResolution;
        xtable = new float*[yRes];
        for(int i=0;i < yRes;i++) {
            xtable[i] = new float[xRes];
        }
        for(int i=0;i < yRes;i++){
            for(int j=0;j < xRes;j++){
                xtable[i][j]=45;
            }
        }
    }
    //        ~array2D(){delete[] xtable;}
    
    void getSize(int &xResolution, int &yResolution);
    // [at (x,y), store val (in xtable, y would be the rowID, x, the columnID)]
    void setValue(int x, int y, float val);
    float getValue(int x,int y);
    
    
};

void array2D::getSize(int &xResolution, int &yResolution){
    xResolution = xRes;
    yResolution = yRes;
}

void array2D::setValue(int x, int y, float val){
    xtable[y][x] = val;
}

float array2D::getValue(int x,int y){
    return xtable[y][x];
}

//
class PGMImage: public array2D {
private:
    string filename;
public:
    PGMImage(int xResolution, int yResolution, string imageFilename):array2D(xResolution, yResolution){
        array2D(xResolution, yResolution);
        filename = imageFilename;
    }
    
    void getResolution(int &xResolution, int &yResolution){
        getSize(xResolution, yResolution);
    }
    
    void setPixel(int x, int y, float val){
        setValue(x,y,val);
    }
    float getPixel(int x, int y){
        return getValue(x,y);
    }
    
    void writeFile(){
        ofstream pgmFile(filename);
        
        pgmFile << "P2" << endl;
        pgmFile << xRes << " " << yRes << endl; // how many columns, how many rows
        pgmFile << 255 << endl; // largest pixel value we'll be outputting (below)
        
        for(int i=0;i<yRes;i++){
            for(int j=0;j<xRes;j++){
                pgmFile << getPixel(j,i) << " ";
            }// next column
            pgmFile << endl;
        }// next row
        
        pgmFile.close();
    }
};


int main()
{
    PGMImage *a = new PGMImage(320,240, "text.pgm");
    int xRes, yRes;
    
    a->getResolution(xRes,yRes);
    
    for(int i=0;i < yRes;i++){
        for(int j=0;j < xRes;j++){
            a->setPixel(j,i,100); // constant value of 100 at all locations
        }
    }
    for(int i=0;i < yRes;i++){
        for(int j=0;j < xRes;j++){
            cout << a->getPixel(j,i) << " ";
        }
        cout << endl;
    }
    a -> writeFile();
    delete a;
    return 0;
}

