#include <iostream>
#include <math.h>
using namespace std;

double mySqrt(double x){
    if(x == 0){
        return 0;
    }
    double estimate;
    double newEstimate;
    estimate = 1.0;
    newEstimate = 0.5*(estimate + x/estimate);
    while(abs(newEstimate - estimate) > 0.000001){
        estimate = newEstimate;
        newEstimate = 0.5*(estimate + x/estimate);
    }
    return newEstimate;
}

int main()
{
    
    double s = mySqrt(5); 
    cout << s << endl; // expect 2.236

    return 0;
}
