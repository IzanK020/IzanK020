// Ejercicio 2
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
	cout<<"Iniciando bucle for..."<<endl;
	for(int i=1;i<=10;i++) {
		int a=i*10;
		cout<<a<<endl;
	}
		cout<<endl<<"Iniciando bucle while..."<<endl;
	int i2=1;
	while(i2<=10) {
		int b=i2*10;
		cout<<b<<endl;
		i2++;
	}
		cout<<endl<<"Iniciando bucle do while..."<<endl;
	int i3=1;
	do {
		int c=i3*10;
		cout<<c<<endl;
		
		i3++;
	} while(i3<=10);
	
	
	return 0;
}

