#include <iostream>
#include <string>
#include <vector>
using namespace std;

int algit(int arr[], int n){
    int sum = 0;
    for(int i = 0; i<n ; i++){
        sum += arr[i];
    }
   return sum;

}
int algrec(int arr[],int n){ //este va a llamar a la suma del array, la suma total la represanta el return de algrec
    if (n == 0){//cuando el numero total es 0
        return 0;
    }else{
        return algrec(arr, n-1)+arr[n-1];

    }
 return 0;
}
int main(){

    int n;
    int arr[100] = {};
    int num;
    cout<<"Cuantos numeros vas a poner en el array?";
    cin>>n;

    for (int i = 0; i<n; i++){
        cout<<"escribe el numero "<< i+1<<endl;
        cin>>num;
        arr[i] = num;
    }

    cout<<algit(arr, n)<<endl;
    cout<<algrec(arr, n);
}