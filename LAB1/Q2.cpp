#include <iostream>
using namespace std;

//int factorial(int n) {
//    if(n==0)
//        return 1;                // bottom out!
//    else
//        return n*factorial(n-1); // recurse!
//}// factorial()

int main() {
    int N;
    int nFact = 1;
    cout << "Please input N: "<< endl;
    cin >> N;
    if (N == 0)
        return 1;
    
    for (int i = 1; i <= N; i++){
        nFact *= i;
    }

    cout << "N! result is "<< nFact << endl;
    
    return 0;
}// main()
