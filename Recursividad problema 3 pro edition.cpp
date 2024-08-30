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
string compro(string pala, string alap){
    if (pala == alap){
        return " es palindromo";
    }else{
        return " no es palindromo";
    }
    }
int main(){
    string pala;
    cout<<"pon palaba ";
    cin>>pala;
    cout<<pal(pala);
    cout<<compro(pala,pal(pala));
    
}