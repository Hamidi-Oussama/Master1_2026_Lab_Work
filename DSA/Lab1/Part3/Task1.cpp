#include <iostream>
#include "My_Sorting_Algorithms.h"
using namespace std;

void scanArray(int A[], int n){
    for(int i =0; i<n; i++){
        cout<<"Input the "<<i<< " element of the Array: ";
        cin>>A[i];
    }
}

void printArray(int A[], int n){
    cout<<"These are the array's elements: ";
    for(int i=0; i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int A[6], n=6;
    scanArray(A,n);
    printArray(A,n);
    //SelectionSort(A,n);
    //BubbleSort(A,n);
    //nsertionSort(A,n);
    //TranspositionSort(A,n);
    ShellSort(A,n);
    printArray(A,n);

}