#include <iostream>
#include <math.h>
using namespace std;

// 2 input version
double AM(double x, double y) {
    return 0.5*(x+y);
}// average()

double GM(double x, double y) {
    return sqrt(x*y);
}// average()

double HM(double x, double y) {
    return pow((pow(x, -1)+ pow(y, -1))/2, -1);
}// average()


int main() {
    cout << "The arithmetic mean of 3 and 5 is: " << AM(3,5) << endl;
    cout << "The geometric  mean of 3 and 5 is: " << GM(3,5) << endl;
    cout << "The harmonic   mean of 3 and 5 is: " << HM(3,5) << endl;
    return 0;
}// main()
