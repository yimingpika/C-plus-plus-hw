#include<iostream>
#include<cmath>

using namespace std;

struct complex{
    double m,n;
    void add(complex b){
        m=m+b.m;
        n=n+b.n;
    } // adds b into our number
    void multiply(complex b){
        m=m*b.m-n*b.n;
        n=n*b.m+m*b.n;
    } // multiplies b into our number
    void conjugate(){
        m=m*1;
        n=-n;
    } // creates the complex conjugate
    void print(/*double m,double n*/){
        cout<<m<<"+"<<n<<"i"<<endl;
    }// outputs the number as m+ni (eg. 0.25-0.123i), if m and n are our real and imaginary parts [see note below]
};
int main(){
    complex x={3,4};
    complex y={1,-0.25};
    x.print();
    y.print();
    
    x.add(y);
    x.print();
    
    y.multiply(x);
    y.print();
    
    x.conjugate();
    x.print();
    
    y.conjugate();
    y.print();
    return 0;
}
