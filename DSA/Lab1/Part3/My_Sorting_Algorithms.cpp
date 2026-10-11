#include <iostream>
#include "My_Sorting_Algorithms.h"

void switching(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b= tmp;
}

int MinValueIndex(int A[], int n, int index){
    int index_max = index; 
    for(int i = index + 1 ; i <n; i++){
        if(A[index_max] > A[i]){
            index_max = i; 
        }
    } 
    return index_max;
}


void SelectionSort(int A[], int n){
    int min_index; 
    for(int i = 0; i< n-1; i++){  
        min_index = MinValueIndex(A,n,i);
        switching(A[i],A[min_index]);
    }

}

void BubbleSort(int A[], int n){
    bool swap = true;

    while(swap == true){
        swap = false;
        for(int i = n-2; i>=0; i--){
            if(A[i+1]<A[i]){
                switching(A[i], A[i+1]);
                swap = true;
            }
        }
    }
}

void InsertionSort(int A[], int n){
    int Key;
    int j;
    //keep sorting the algoritms from the key and first element to the second key and 2  previous elements that are became sorted to the 3 key and the 3 elements ... 
    //by insreting the key in the correct place of the array(it and the previous elements). 
    for(int i= 1;i<n;i++){
        Key = A[i];
        j = i-1;
        while((j>=0) && (A[j]> Key)){
            A[j+1] = A[j];
            j--;
        }   
        A[j+1] = Key;
    }
}

void TranspositionSort(int A[], int n){
    bool flag = false;

    while(flag==false){
        flag=true;
        
        for(int i =0; i<n-1; i+=2){
            if(A[i]>A[i+1]){
                switching(A[i], A[i+1]);
                    flag = false;
            }
        }
    

        for(int i=1; i<n-1;i+=2){
            if(A[i]>A[i+1]){
                switching(A[i], A[i+1]);
                    flag = false;    
            }
        }
    }
}

void ShellSort(int A[], int n){
    int temp;
    int j;
    for(int gap = n/2; gap>0; gap=gap/2){
        for(int i = gap; i<n; i++){
            temp = A[i];
            j =  i;
            while((j>=gap) && (A[j-gap])>temp){
                A[j] = A[j - gap];
                j = j-gap;
            }
            A[j] = temp;
        }
    }
}




