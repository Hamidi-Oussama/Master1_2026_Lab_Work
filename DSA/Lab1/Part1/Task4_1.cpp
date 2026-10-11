#include<iostream>
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

int minArray(int A[], int n, int &low){
    low = 0;
    for(int i=1; i<n; i++){
        if(A[i]<A[low]){
            low = i;
        }
    }
    return low;
}

bool F(int A[], int n){
    int B[n] = {0};
    for(int i=0; i < n; i++){
        if((0<=A[i]) and (10>=A[i])){
            B[i] = 1;
        }
    }
    for(int i=0;i<n;i++){
        if(B[i]==0){
            return false;
        }
    }
    return true;
}

void scanArray0to20(int A[], int n){
    cout<< "Input the size of the array: ";
    cin >> n;
    cout<< "Input the elements of the Array(must be between 0 and 20): ";
    for(int i=0; i<n; i++){
        do{ 
            cout<< "enter the value of element: " << i;
            cin>>A[i];
        }while(!((A[i]<0)) || (20<A[i])); 
    }    
}

bool is_in(int v, int A[], int n){
    bool exist = false;
    for(int i=0; i<n;i++){
        if (A[i] == v){
            exist = true;
        }    
    }
    return exist;
}

void print0occurrence(int A[], int n){
    int occur[n] = {0};
    int occur_index = 0;
    int occurence;

    for(int i = 0;i<n ;i++ ){
        if(! (is_in(A[i],occur,n))){
            occurence=0;
            for(int j = i; j<n; j++){
                if(A[j]==A[i]){
                    occurence ++;
                }
            }
        occur[occur_index] = A[i];
        occur_index ++; 
        cout<<"the value: "<< A[i] << " occurs: "<< occurence<<" times."<<endl;
        }
    }

    
    for(int i=0;i<=n;i++){
        int i_occurreence = 0;
        int j = 0;
        for(int j=0; j<n; j++){
            if(A[j]==i){
                i_occurreence +=1;
            }
        }
    }

}

void removeElementArray(int v, int A[], int n){
    int v_index;
    bool v_exist = false;

    cout<< "Input the value you want removed: ";
    cin >> v;

    for(int i =0;i<n;i++){
        if(A[i] == v){
            v_exist = true;
            v_index = i;
             break;    
        }
    }
    if(v_exist = false){
        cout<<"v does'nt exist in the array";
    }
    else{
        for(int i =v_index;i<n-1;i++){
            A[i] = A[i + 1];
        }
        A[n-1] = 0;}
}

//The last element got deleted sir
void insertElementArray(int e, int p, int A[], int n){
    cout<<"Input the value you want to replace into the array: ";
    cin >> e;
    cout<<endl<<"Input the position of the value: ";
    cin >> p;
    cout<<endl;
    for(int i = n-1; i>=p; i--){
        A[i+1] = A[i];
    }
    A[p] = e;
}




int main(){ 
    int A[7], n= 7, low, v, e, p;
    scanArray(A,n);
    //printArray(A,n);
    //minArray(A,n, low);
    //F(A,n);
    //scanArray0to20(A,n);
    printArray(A,n);
    //print0occurrence(A,n);
    //removeElementArray(v,A,n);
    //printArray(A,n);
    insertElementArray(e, p, A, n);
    printArray(A, n);
  return 0;  
}