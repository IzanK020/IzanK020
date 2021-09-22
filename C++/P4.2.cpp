//Problema 2
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
double prod_esc(double a[3],double b[3]);
double norm(double a[3]);
double cos_ang(double a[3],double b[3]);

int main ()
{
	double a[3];
	double b[3];
	cout<<"Bienvenid@ al programa de calculo del coseno del angulo de dos vectores."<<endl;
	cout<<"Primero introduzca el vector a (3 dimensiones):"<<endl;
	for(int i=0;i<3;i++)
	{
		cin>>a[i];
	}
	cout<<endl<<"Introduzca ahora el vector b (3 dimensiones):"<<endl;
	for(int i=0;i<3;i++)
	{
		cin>>b[i];
	}
	cout<<"Calculando..."<<endl;
	//double a[3]={1,0,0};
	//double b[3]={0,1,0};
	double cosa=cos_ang(a,b);
	cout<<"El coseno del angulo de los dos vectores es: "<<cosa<<endl;
	
	
	
	return 0;
}

double prod_esc(double a[3],double b[3])
{  
 	double p=0;
 	for(int i=0;i<3;i++) 
	 {
	 	p+=a[i]*b[i];
	 }	
	return p;
}
 
double norm(double a[3])
{
	double n=0;
	for(int i=0;i<3;i++)
	{
		n+=pow(a[i],2);
	}
	n=sqrt(n);
	return n;
}

double cos_ang(double a[3],double b[3])
{
	double prod=prod_esc(a,b);
	double norma=norm(a);
	double normb=norm(b);
	
	double cos=prod/(norma*normb);

	return cos;
}
