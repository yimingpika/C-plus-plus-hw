#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>


using namespace std;

int rFloor(){
    double r;
    int t;
    r = ((double)rand())/RAND_MAX;
    t = floor(r * 10);
//    cout<< "*" << t << "*" << endl;
    return t;
}
int rand2(){
    double r1, r2, r;
    int t;
    r1 = ((double)rand())/RAND_MAX;
    r2 = ((double)rand())/RAND_MAX;
    r = 0.5 * (r1 + r2);
    t = floor(r * 10);
    return t;
}
void printStars(int n) {
    for(int i=0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}/// printStars()


int main(){
    int N;
    cout<< "Please input your N: ";
    cin >> N;
    cout << "N = "<< N << endl;
    int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//    cout<< "**********************" <<endl;
//    for (int i = 0; i < 10; i++){
//        cout<<a[i];
//    }
//    cout<<endl;
    int t;
    double r;
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++ ){
        t = rFloor();
//        cout << "++" << t << "++"<< endl;
        switch (t){
            case 0:
                a[0] += 1;
                break;
            case 1:
                a[1] += 1;
                break;
            case 2:
                a[2] += 1;
                break;
            case 3:
                a[3] += 1;
                break;
            case 4:
                a[4] += 1;
                break;
            case 5:
                a[5] += 1;
                break;
            case 6:
                a[6] += 1;
                break;
            case 7:
                a[7] += 1;
                break;
            case 8:
                a[8] += 1;
                break;
            case 9:
                a[9] += 1;
                break;
            case 10:
                a[9] += 1;
                break;
            default:
                break;
        }
    }
//    cout<< "+*+*+*+*+*+*+*+*+*+*+*" <<endl;
//    for (int i = 0; i < 10; i++){
//        cout<<a[i]<<"**";
//    }
//    cout<<endl;
    int N_total;
    N_total = a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9];
    cout<<"Total bin count is: "<< N_total <<endl;
//    int nAsterisks;
    for (int i = 0; i < 10; i++){
//        nAsterisks = floor(100 * a[i]/N);
//        printStars(nAsterisks);

        printStars(a[i]);
    }
    cout<<"======================================"<<endl;
    int b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < N; i++){
        t = rand2();
        switch (t){
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
    int N_total2;
    N_total2 = b[0] + b[1] + b[2] + b[3] + b[4] + b[5] + b[6] + b[7] + b[8] + b[9];
    cout<<"Total bin count is: "<< N_total <<endl;
//    int nAsterisks;
    for (int i = 0; i < 10; i++){
        //        nAsterisks = floor(100 * a[i]/N);
        //        printStars(nAsterisks);
        
        printStars(b[i]);
    }

    return 0;
}






