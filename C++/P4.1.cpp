//Problema 1
// Ejercicio 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
double *media(double a[],int n);
double m[2];
int main ()
{
	int n=3;
	double a[]={1,2,3};	
	double *m;
	m=media(a,n);
	
	cout<<"La media cuadratica es: "<<m[0]<<endl<<"La media armonica es: "<< m[1]<<endl;
	
	return 0;
}

double *media(double a[],int n)
{  //Devuelve un vector cuyas componentes son las medias cuadratica y armónica
	// del vector a cuya dimensión es n
	
	double sc=0;
	double sa=0;
	for(int i=0;i<n;i++)
	{
		sc+=pow(a[i],2);
		sa+=pow(a[i],-1);
	}
	
	double mc,ma;
	mc=sqrt(sc/n);
	ma=n/sa;
	m[0]=mc;
	m[1]=ma;
	
	return m;
}





