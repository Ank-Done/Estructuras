#include <iostream>
using namespace std;

int bacteriaIterativa(int n){ //nombres
	n = (n*3.78)-(n*2.34);
return n;
}
int bacteriaRecursiva(int n){ //población
	if (n == 0)
		return 1;
	else
		return bacteriaRecursiva(n-1) + bacteriaIterativa(n);
}


int main(){
int n;
cout << "dame dias de evolucion ";
cin >> n;
cout<<bacteriaRecursiva(n)<<endl;

	//for(int i = 0; i<n; i++){ //este código lo usé para determinar que todos los valores que pedía si se estaban realizando al instante
	//	cout<<bacteriaRecursiva(i)<<endl;
	//}
}