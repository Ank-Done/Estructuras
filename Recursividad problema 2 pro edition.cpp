#include <iostream>
#include <string>
using namespace std;

string pal(string pala){
    if (pala == pala){
        reverse(pala.begin(),pala.end());
        return pala;
    }else{
        return pal(pala);
    }
    }
int main(){
    string pala;
    cout<<"pon palaba ";
    cin>>pala;
    cout<<pal(pala);
}