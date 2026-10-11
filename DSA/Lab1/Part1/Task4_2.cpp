#include <iostream>
using namespace std;

const int COLS = 3; 

void scanMatrix(int M[][COLS], int n, int m){
cout << "Input an elements of the matrix: ";    
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> M[i][j];
            cout<<" ";
        }
        cout<<endl;
    }    
}

void printMatrix(int M[][COLS], int n, int m){
    cout<<"[";
    for(int i = 0; i<n; i++){
        for(int j =0; j<m ; j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"]"<<endl;
}


void sperateEvenOdd(int M[][COLS], int n, int m, int A1[], int A2[], int &size1, int &size2){
    size1=0;
    size2=0;
    for(int i =0; i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j] % 2 == 0){
                A1[size1++] = M[i][j];
            }
            else{
                A2[size2++] = M[i][j];
            }
        }
    }
}

void printArray(int A[], int n){
    cout<<"The element of the array:";
    for(int i =0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


void CheckSumv2(int M[][COLS], int n, int m,  int SumROWS[], int SumCOLS[]){
    bool MatchFound = false;   
    //Finding the sum of ROWS.
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            SumROWS[i] += M[i][j];
        }
    }
    //Finding the sum of COLUMNS.
    for(int i = 0; i<m; i++){
        for(int j=0; j<n; j++){
            SumCOLS[i] += M[j][i];
        }
    }
    //Comparing all the possibilties of rows against columns.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(SumROWS[i] == SumCOLS[j]){
                cout << "Found a match between a row and a coulmn! The sum of the "<<i+1<<" row equals the sum of the "<<j+1<<" column."<<endl;
                MatchFound = true;
            }
        }
    }
    //Comparing all the possibilties of rows vs other rows and columns vs other columns.
    for(int i= 0; i<n-1;i++){
        for(int j =i+1; j<n;j++){ 
            if(SumROWS[i] == SumROWS[j]){
                cout<<"Found a match between rows! The sum of the "<<i+1<< " row equals the sum of the "<< j+1<< " row."<<endl; 
            }
        }   
    }

    for(int i=0; i<m-1; i++){
        for(int j=i+1; j<m; j++){
            if(SumCOLS[i] == SumCOLS[j]){
                cout<<"Found a match between columns! The sum of the "<< i+1<<" cloumn equals the sum of the "<< j+1<< "column."<<endl;
            }
        }
    }



    if(MatchFound == false){
        cout <<endl<<"Not a singe Match has been founded!";
    }


}

int main(){
    int ROWS=3, M[3][3], A1[9], A2[9], size1 = 0, size2 = 0, SumROWS[9]={0}, SumCOLS[9]={0};
    scanMatrix(M, ROWS, COLS);
    printMatrix(M, ROWS, COLS);
    sperateEvenOdd(M,ROWS, COLS, A1, A2, size1, size2);
    printArray(A1, size1);
    printArray(A2, size2);
    //CheckSum(M,ROWS,COLS);
    CheckSumv2(M,ROWS,COLS,SumROWS,SumCOLS);


}