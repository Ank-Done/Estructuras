    #include <iostream>
    #include <string>
    using namespace std;

    string pal(string pala){
        string rev = pala;
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
        cout<<endl;
        cout<<pal(pala);
        if (pala == pal(pala)){
            cout<<"Palindromo";
        }else{
            cout<<"No palindromo";
        }
    }