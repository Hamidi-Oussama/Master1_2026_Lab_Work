#include<iostream>
using namespace std;


void square(int *n) {
    *n = (*n) * (*n);
}

int main(){
    int x = 5;
    square(&x);
    cout << "Outside function:" << x << endl;
    cin >> x;
    cout << "Outside function:" << x << endl;
    return 0;
}   