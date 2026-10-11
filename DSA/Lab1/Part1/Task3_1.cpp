#include <iostream>
using namespace std;


bool PRIME(int n){
    for(int i=n-1;i>1;i--){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

void all_PRIMES_on_an_interval(int &a, int &b){
    cout <<"Input the lower number in the interval: ";
    cin >> a;
    cout<<"Input the highest number in the interval: ";
    cin >> b;
    for(int i=a;i<=b;i++){
        if(PRIME(i)==true){
            cout<<i<<endl;
        };
    }
}

int returning_the_nTH_PRIME_number(int n){
    int prime_number_counter = 0;
    int i = 1;

    while(prime_number_counter < n){
        i++;
        if (PRIME(i) == true){
            prime_number_counter +=1;
        }         
    }
    return i;
}


int main(){
    int x, y, z;

    cout<<"Input the number you want to check if prime: ";
    cin >> x;
    if(RRIME(x)==true){
        cout<<x<< " is not a prime number!"<<endl;
    }
    else{
        cout<< x << " is a Prime Number"<<endl;
    }


    all_PRIMES_on_an_interval(y, z);
   
   
   
   
    cout<<"Input the nTH prime number you want to calculate: ";
    cin >> x;
    int i = returning_the_nTH_PRIME_number(x);
    cout<<"The nTH Prime Number is: "<< i << endl;



    return 0;

    
}