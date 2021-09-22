// Ejercicio 1
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
	double x;
	cout <<"Inserte valor de x= " ;
	cin >> x;
	cout << endl;
	double a=1;
	double exp1;
	int i=0;
	double i2=1;  //Factorial de i
	double exp2=0;
	while(abs(a)>=0.00001) {
		a=pow(x,i)/i2;
		exp1=exp2;
		exp2=exp2+a;
		i++;
		i2=i2*i;
		cout << setprecision(4)<<exp1<<"+"<<setprecision(4)<<a<<"="<<setprecision(4)<<exp2<<endl;
	}
	
	double b=exp(x);
	
	cout << "exp(x)="<<setprecision(8)<< exp2 <<endl;
	cout<< "Valor real= "<<setprecision(8)<< b<<endl;
	return 0;
}


