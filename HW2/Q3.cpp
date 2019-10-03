//
//  main.cpp
//  HW2 Q2standard
//
//  Created by Jiangrun Chen on 6/4/19.
//  Copyright © 2019 JiangrunChen. All rights reserved.
//
#include "Q3.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

void array2D::getSize(int &xResolution, int &yResolution){
    xResolution = xRes;
    yResolution = yRes;
}

void array2D::setValue(int x, int y, double val){
    xtable[y][x] = val;
}

double array2D::getValue(int x,int y){
    return xtable[y][x];
}

    
void PGMImage::getResolution(int &xResolution, int &yResolution){
    getSize(xResolution, yResolution);

}

void PGMImage::setPixel(int x, int y, double val){
        setValue(x,y,val);
    }
    double PGMImage::getPixel(int x, int y){
        return getValue(x,y);
    }
    
    void PGMImage::writeFile(){
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
    };

int main()
{
    

    double cxmin, cxmax, cymin, cymax;
    int maxIter, iter;
    ComplexNumber z(0,0);
    ComplexNumber c(0,0);
    
    cxmin = -0.75, cymin = 0.1, cxmax = -0.749, cymax = 0.101;
    for(int k = 0; k < 50; k++){
        string name = std::to_string(k)+".pgm";
        PGMImage *a = new PGMImage(640,480, name);
        int xRes, yRes;
        a->getResolution(xRes,yRes);
                
        for(int y=0;y < yRes;y++){
            for(int x=0;x < xRes;x++){
                double c_real = cxmin + (float)x/(xRes-1)*(cxmax-cxmin);
                double c_imag = cymin + (float)y/(yRes-1)*(cymax-cymin);
                
                c.set_complex_value(c_real,c_imag);
                z.set_complex_value(0,0);
                maxIter = 255;
                iter = 0;
                        
                while(iter < maxIter && z.abs() < 2){
                    ComplexNumber t1 = z.squared();
                    ComplexNumber t2 = t1.add(c);
                    double z1 = t2.get_real();
                    double z2 = t2.get_imag();
                    z.set_complex_value(z1,z2);
                    iter++;
                }
                //            cout<<iter<<endl;
                //            z.prt();
                if (z.abs() >= 2){
                    a->setPixel(x,y,iter);
                            
                }else{
                    a->setPixel(x,y,0);
                }
                        
                        
            }
        }
        a -> writeFile();
        delete a;
        cxmin += 0.000005, cymin += 0.000005,cxmax-=0.000005,cymax-=0.000005;
    }
        
    
    
    return 0;
}
