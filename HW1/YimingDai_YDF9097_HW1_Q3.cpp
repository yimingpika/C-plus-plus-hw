#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

void printStars(int n) {
    for(int i=0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}/// printStars()


int main(){
    int N;
    double a;
    int seed;

    cout<< "Please input your N: ";
    cin >> N;
    cout << "your N is "<< N << endl;
    cout<< "Please input Pareto Distribution parameter a: ";
    cin >> a;
    cout << "your a is "<< a << endl;
    cout<< "Please input seed: ";
    cin >> seed;
    cout << "your seed is "<< seed << endl;
    int b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


    double value[N];
    double zero_one[N];
    int floorSet;
    double r;
    double d;
    int t;
    double largestVal = -10000000, smallestVal = 10000000;

//    srand((unsigned int)time(NULL));
    srand(seed);
    for (int i = 0; i < N; i++){
        r = ((double)rand())/RAND_MAX;
//        cout<< "r: " << r << endl;
        d = pow(r, 1 / a);
//        cout<< "d: " << d << endl;
        value[i] = 1 / d;
        if (value[i] > largestVal){
            largestVal = value[i];
        }
        if (value[i] < smallestVal){
            smallestVal = value[i];
        }
//        cout<< "value: " << value[i] << endl;
    }
//    cout<< "largest: " <<largestVal<< endl;
//    cout<< "smallest: " <<smallestVal<< endl;
    
    for (int i = 0; i < N; i++ ){
        zero_one[i] = (value[i] - smallestVal) / (largestVal - smallestVal);
        floorSet = floor(zero_one[i] * 10);
//        cout<< "floorSet: " <<floorSet<< endl;
        switch (floorSet){
            case 0:
                b[0] += 1;
                break;
            case 1:
                b[1] += 1;
                break;
            case 2:
                b[2] += 1;
                break;
            case 3:
                b[3] += 1;
                break;
            case 4:
                b[4] += 1;
                break;
            case 5:
                b[5] += 1;
                break;
            case 6:
                b[6] += 1;
                break;
            case 7:
                b[7] += 1;
                break;
            case 8:
                b[8] += 1;
                break;
            case 9:
                b[9] += 1;
                break;
            case 10:
                b[9] += 1;
                break;
            default:
                break;
        }
    }

    int N_total;
    N_total = b[0] + b[1] + b[2] + b[3] + b[4] + b[5] + b[6] + b[7] + b[8] + b[9];
    cout<<"Total bin count is: "<< N_total <<endl;
    int nAsterisks;
    for (int i = 0; i < 10; i++){
//        int nAsterisks = floor(100 * b[i]/N);
//        printStars(nAsterisks);
        printStars(b[i]);
    }
    return 0;
}






