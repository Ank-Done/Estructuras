#include <iostream>
using namespace std;

int suma(int n){
    if (n == 0){
        return 0;
    }else{
        return n+suma(n-1);
    }
}
int main(){
    int n;
    cout<<"pon numero ";
    cin>>n;
    cout<<suma(n);
}