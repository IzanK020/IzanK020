//Problema 3
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

float F(double x,float(*funcion)(double));
float loge( double a);
float sen(double a);
float exponencial(double a );
int main ()
{ 
double x;
cout<< "Define un valor x:";
cin>> x;
	
cout<< "Los valores del funcional son"<<endl;

cout<<"g(x)=sin(x), F(g(x))="<<F(x,sen)<<endl;
cout<<"g(x)=exp(5x), F(g(x))="<<F(x,exponencial)<<endl;
cout<<"g(x)=ln(x), F(g(x))="<<F(x,loge)<<endl;

	
	
	
	return 0;
}

float F(double x,float(*funcion)(double))
{	float g=funcion(x);
	if (g<1)
		return 2.5;
	else if (g<2)
		return 2.0;
	else if (g<3)
		return 1.5;
	else 
		return 1.0;
}

float sen(double a)
{return sin(a);}

float exponencial(double a)
{return exp(5*a);}

float loge( double a)
{return log(0.01+a);}
