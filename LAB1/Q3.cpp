#include <iostream>
using namespace std;

// 2 input version
double average(double x, double y) {
    return 0.5*(x+y);
}// average()

// 3 input version
double average(double wt, double a, double b) {
    return wt*(a-b) + b;
}// average()

int main() {
    double a = average(4,5);
    cout << a << endl;
    a = average(0.5,4,5); // same as average(4,5)
    cout << a << endl;
    a = average(0.2,4,5);
    cout << a << endl;
    return 0;
}// main()
