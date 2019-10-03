#include <iostream>

using namespace std;

class array2D{
    private:
        int xRes, yRes;
        float **xtable;
    
    public:
    
        array2D(int xResolution, int yResolution){
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
        ~array2D(){delete[] xtable;}

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

int main()
{
    
    array2D *a = new array2D(320,240);
    int xRes, yRes;
//    cout << "xR: " << xRes; 0
//    cout << "yR: " << yRes; 0
    a->getSize(xRes,yRes);
//    cout << "xR: " << xRes; 320
//    cout << "yR: " << yRes; 240
    //NOTE the j,i ordering below (twice), since we specify coords as (x,y) [not (y,x)]
    for(int i=0;i < yRes;i++){
        for(int j=0;j < xRes;j++){
            a->setValue(j,i,100); // constant value of 100 at all locations
        }
    }
    for(int i=0;i < yRes;i++){
        for(int j=0;j < xRes;j++){
            cout << a->getValue(j,i) << " ";
        }
        cout << endl;
    }
    
    delete a;

    return 0;
}
