#include <iostream>
#include <math.h>
using namespace std;

void compute_root(double a, double b, double c, double *x){
    x[0] = (-b + sqrt(pow(b,2)-4*a*c))/2*a;
    x[1] = (-b - sqrt(pow(b,2)-4*a*c))/2*a;
}

int main() {
    double a=2.0, b=5, c=3.1;
//    double a = 1, b = 4, c = 4;
    double x[2] = {0, 0};
    if (pow(b, 2) - 4*a*c < 0){
        cout << "no real root"<< endl;
    }else{
        compute_root(a, b, c, x);
        cout << "x1: " << x[0] << " x2: " << x[1] << endl;
    }
    return 0;
}
