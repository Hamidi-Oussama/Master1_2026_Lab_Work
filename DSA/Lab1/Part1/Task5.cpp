#include <iostream>
using namespace std;

void scanSortedArray(int A[], int n){
    cout << "Input the elements of the 1D Sorted array: "; 
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

int LinearSearch(int A[], int n, int v){
    for(int i=0; i<n ;i++){
        if (A[i]== v){
            return i;
        }
    }
    return -1;    
}

int LinearSearch(int A[], int n, int positions[], int v){
    int freq = 0;
    fill(positions, positions+n, -1);

    for(int i=0; i<n ;i++){
        if (A[i]== v){
            positions[freq] = i;
            freq += 1;
        }
    }
    if(freq > 0){
        return freq;
    }
    else{
        return -1;
    }
}

int BinarySearch(int A[], int n, int v){
    int low = 0;
    int high = n-1;
    int mid = (high + low)/2;

    while(low <= high){
        if (A[mid] == v){
            return mid;
        }
        else if (A[mid] < v){
        low = mid + 1;
        }
        else{
        high = mid - 1;      
        }
        mid = (high + low)/2;
    }
    return -1;
}

int BinarySearch(int A[], int n, int v, int positions[]){
    int B[n];
    int low = 0;
    int high = n-1;
    int mid = (low + high) /2;
    int freq = 0;
    fill(positions, positions+n, -1);
    copy(A, A+n,B);

    while(low <= high){
        if(B[mid] == v){
            positions[freq] = mid;
            freq += 1;
            B[mid] = v - 1;
            
        }
        else if(B[mid]< v){
            low = mid +1;
        }
        else {
            high = mid -1;
        }
        mid = (low +high)/2;
    }
    if(freq>0){
        return freq;
    }
    else{
        return -1;
    }
    
}

int main(){
    int A[4],n = 4,v, positions[4];
    scanSortedArray(A,n);
    printArray(A,n);
    cout<<"Input the value to search for: ";
    cin>>v;
    //LinearSearch(A,n,v);
    //BinarySearch(A,n,v);
    LinearSearch(A,n,positions,v);
    printArray(positions,n);;
}