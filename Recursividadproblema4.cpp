// Equipo es Fabian Orta y Fransisco Gonzalez

#include <iostream>
#include <string>
using namespace std;

int ss = 0;

int pir(int n){

    if(n<1){
        cout <<  " \n fin";
        return 0;
    } else{
        for (int cont = 0; cont < n; cont++){
            cout <<  " ";
        }
        for (int contt = 0; contt < ss; contt++){
            cout <<  "**";
        }
        cout << "*";

        cout << endl;
        ss = ss + 1;

        return pir(n-1);
    }
}

int main(){

    int l;
    cout << "q tantos niv quieres? ";
    cin >> l;
    pir(l);

    return 0;

}