//Problema 1
// Ejercicio 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

double trapecio(double (*funcion)(double),double a, double b, int n);
double simpson13(double (*funcion)(double),double a, double b, int n);
double simpson38(double (*funcion)(double),double a, double b, int n);
double quadgauss(double (*funcion)(double),double a, double b);

double PI=4*atan(1.0);
double c=1.0/16.0;
double d=1.0/2.0/16.0;
double k=sqrt(c*c-d*d)/c;
double f(double x){return (4*c*(sqrt(1-(k*k*sin(x)*sin(x)))));}


int main ()
{
	int n=0;
	double I=0,Iold=0;
	double a=0,b=PI/2;
	do{
		n+=2;
		Iold=I;
		I=simpson13(f,a,b,n);
		
		
	}while(fabs(I-Iold)>1e-6);
	
	cout<<"Se ha alcanzado en el método de Simpson 1/3 la precisión con "<<n<<" particiones."<<endl;
	cout<<"Se ha obtenido un valor de la integral de "<<I;
	return 0;
}


double trapecio(double (*funcion)(double),double a, double b, int n){
	double h=(b-a)/double(n);
	double I,sum=0;
	for (int i=1;i<n;i++){
	sum=sum+(2*funcion(a+(i*h)));
	}
	I=(h/2.0)*(funcion(a)+funcion(b)+sum);
		
return I;}

double simpson13(double (*funcion)(double),double a, double b, int n){

	if(fmod(n,2)!=0){ //Necesitamos n múltiplo de 2, si n es múltiplo de 2, esto dá 0
		do{ n+=1;
		}while(fmod(n,2)!=0);	
	}
	double h=(b-a)/double(n);
	double I,sum1=0,sum2=0;
	for (int i=1;i<((n/2.0));i++){sum1=sum1+(2*funcion(a+(2*i*h)));}
	for (int i=1;i<=(n/2.0);i++){sum2=sum2+(4*funcion(a+((2*i-1)*h)));}
	
	I=(h/3.0)*(funcion(a)+funcion(b)+sum1+sum2);
		
return I;}

double simpson38(double (*funcion)(double),double a, double b, int n){
	
	double I,sum1=0,sum2=0;
	if(fmod(n,3)!=0){ //Necesitamos n múltiplo de 3, si n es múltiplo de 3, esto dá 0
		do{ n+=1;
		}while(fmod(n,3)!=0);	
	}
	double h=(b-a)/double(n);
	for (int i=1;i<n;i++){if(fmod(i,3)!=0){sum1=sum1+(3*funcion(a+(i*h)));}} //Los no divisibles entre 3
	for (int i=1;i<(n/3.0);i++){sum2=sum2+(2*funcion(a+(3*i*h)));}
	
	I=(3.0*h/8.0)*(funcion(a)+funcion(b)+sum1+sum2);
		
return I;}

double quadgauss(double (*funcion)(double, double),double k,double a, double b){
	//Hacemos con n=5
	double x1=((1.0/3.0)*sqrt(5.0+(2.0*sqrt(10.0/7.0))));
	double x2=((1.0/3.0)*sqrt(5.0-(2.0*sqrt(10.0/7.0))));
	double x[5]={-x2,-x1,0,x1,x2};
	double w1=128.0/225.0;
	double w2=(322.0+(13.0*sqrt(70.0)))/900;
	double w3=(322.0-(13.0*sqrt(70.0)))/900;
	double w[5]={w3,w2,w1,w2,w3};
	double sum=0;
	double xx=0;
	for (int i=1;i<=5;i++){
		xx=(((b-a)/2)*x[i])+((b+a)/2);
		sum=sum+(w[i]*funcion(xx,k));
	}
	double I=((b-a)/2.0)*sum;
	return I;
}

