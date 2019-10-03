//
//  Q2.h
//  HW2 Q2standard
//
//  Created by Jiangrun Chen on 6/5/19.
//  Copyright © 2019 JiangrunChen. All rights reserved.
//

#ifndef Q3_h
#define Q3_h
#include <iostream>
#include <math.h>
using namespace std;
class array2D{
protected:
    int xRes, yRes;
    double **xtable;
public:
    array2D(int xResolution = 1, int yResolution = 1){
        xRes = xResolution;
        yRes = yResolution;
        xtable = new double*[yRes];
        for(int i=0;i < yRes;i++) {
            xtable[i] = new double[xRes];
        }
        for(int i=0;i < yRes;i++){
            for(int j=0;j < xRes;j++){
                xtable[i][j]=45;
            }
        }
    }
    void getSize(int &xResolution, int &yResolution);
    void setValue(int x, int y, double val);
    double getValue(int x,int y);
};

class PGMImage: public array2D {
private:
    string filename;
public:
    PGMImage(int xResolution, int yResolution, string imageFilename):array2D(xResolution, yResolution){
        array2D(xResolution, yResolution);
        filename = imageFilename;
    }
    
    void getResolution(int &xResolution, int &yResolution);
    void setPixel(int x, int y, double val);
    double getPixel(int x, int y);
    void writeFile();
};
class ComplexNumber{
private:
    double real;
    double imag;
public:
    ComplexNumber(double i,double j){
        real = i;
        imag = j;
    }
    ComplexNumber add(ComplexNumber c){
        double i, j;
        i = real + c.real;
        j = imag + c.imag;
        ComplexNumber t(i, j);
        return t;
    }
    ComplexNumber squared(){
        double i, j;
        i = pow(real,2)-pow(imag,2);
        j = 2*real*imag;
        ComplexNumber t(i, j);
        return t;
    }
    double abs(){
        double t;
        t = sqrt(real*real+imag*imag);
        return t;
    }
    void prt(){
        if (imag == 0)
            cout << real << endl;
        else if(imag > 0)
            cout << real << "+" << imag << "j" << endl;
        else
            cout << real << imag << "j" << endl;
    }
    void set_complex_value(double i, double j){
        real = i;
        imag = j;
    }
    double get_real(){
        return real;
    }
    double get_imag(){
        return imag;
    }
};

#endif /* Q3_h */
