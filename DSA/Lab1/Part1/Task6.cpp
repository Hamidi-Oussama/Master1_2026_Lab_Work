#include <iostream>
using namespace std;


void scanArray(int A[], int n){
    cout << "Input the elements of the 1D array: "; 
    for(int i=0; i<n;i++){
        cin >> A[i];
    } 
}

void printArray(int A[], int n){
    cout << "The elements of the array: ";
    for(int i=0;i<n;i++){
        cout << A[i] <<" ";
    }
    cout<<endl;
}

void switching(int &x, int &y){
    int tmp;
    tmp = x;
    x=y;
    y=tmp;
}

int MinValueIndex(int A[], int n, int b){
    int index = b;
    for(int i = b+1; i<n; i++){
        if (A[index] > A[i]){
            index = i;
        }
    }
    return index;
}

void SelectionSort(int A[], int n){

    // for(int i = 0; i<n-1; i++){
    //     for(int j = i +1; j<n; j++){
    //         if(A[j] < A[i]){
    //             switching(A[j], A[i]);
    //         } 
    //     }
    // }

    for(int i = 0; i<n-1;i++){
        int index_of_min = MinValueIndex(A,n,i);
        switching(A[i], A[index_of_min]);
    }

}

void BubbleSort(int A[], int n){
    bool swap = true;
    while(swap == true){
        swap = false;
        for(int i = 0; i < n-1; i++){
            if(A[i] > A[i+1]){
                switching(A[i], A[i+1]);
                swap = true;
            }
        }
    }
}

void InsertionSort(int A[], int n){
    int key;
    int j;
    for (int i = 1 ; i < n; i++){
        key = A[i];
        j = i-1;
        while((j >= 0 ) & (A[j] > key)){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void CountingSort(int A[], int n){
    int Max = A[0];
    
    int Output[n];
    //Finding max value in the array
    for(int i = 1; i<n; i++){
        if(A[i]>Max){
            Max=A[i];
        }
    }
    int Count[Max+1];

    //Filing the count array with zeroes
    for(int i = 0; i<= Max; i++){
        Count[i] = 0;
    }

    //Finding the count of each element in the array
    for(int i = 0; i<=n; i++){
        Count[A[i]] += 1;
    }
    //The cumaltive sum of the count array stores in the same array
    for(int i = 1; i<=Max; i++){
        Count[i] += Count[i-1];
    }
    //index the cumaltive sum array count using the elements 
    //of A[] starting from the last one then index the output array using the indexed values in count while 
    //decrementing the the index in ouput by 1 each time we find the index of the output
    for(int i = n-1; i>=0; i--){
        Count[A[i]] -= 1;
        Output[Count[A[i]]] = A[i];  
    }

    for(int i = 0; i<n; i++){
        A[i] = Output[i];
    }
}


void CountingSort2(int A[], int n){
    int Output[n];
    int Max = A[0];

//finding the max value in the array
    for(int i =0 ; i<n;i++){
        if (Max < A[i]){
            Max = A[i];
        }
    }
 
    int Count[Max+1];
    
    //intinlazing all Count elements to 0;
    for(int i= 0; i<=Max; i++){
        Count[i] = 0;
    }

    //finding the number of occurences of each elements and inserting it in count
    for(int i=0; i < n; i++){
        Count[A[i]] += 1;
    }

    //Cumaltive sum of Count 
    for(int i = 0; i <= Max; i++){
        Count[i+1] += Count[i];
    }

    //indexing output by the 
    for(int i =0 ;i<n;i++){
        Count[A[i]]--;
        Output[Count[A[i]]] = A[i];
    }

    for(int i=0; i<n;i++){
        A[i] = Output[i];
    }
    
}


int main(){
    int A[9], n = 9;
    scanArray(A,n);
    printArray(A,n);
    //SelectionSort(A,n);
    //BubbleSort(A,n);
    InsertionSort(A,n);
    //CountingSort2(A,n);
    printArray(A,n);
}