#include <iostream>
#include <string>
using namespace std;

string pal(string pala){
    string rev = " lol ";
    for (int i = 0; i<=pala.length(); i++){
        rev[i] = pala[pala.length()-(i+1)];
    }
    pala = rev;

    return rev;
}
int main(){
    string pala;
    cout<<"pon palaba ";
    cin>>pala;
    for(int i = 0; i<=pala.length();i++){
        cout<<pala[i];
    }
    cout<<pal(pala);
}