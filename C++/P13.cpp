//					

// Ejercicio 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

double trapecio(double (*funcion)(double, double),double k,double a, double b, int n);
double simpson13(double (*funcion)(double, double),double k,double a, double b, int n);
double simpson38(double (*funcion)(double, double),double k,double a, double b, int n);
double quadgauss(double (*funcion)(double, double),double k,double a, double b);
double PI=4*atan(1.0);
double f(double x, double k){return (2.0/(PI*sqrt(1-(k*k*sin(x)*sin(x)))));}


int main ()
{
		// Crear un flujo de salida y llamarlo fsalida
	ofstream fsalidaa;
	fsalidaa.open("Datosa.dat");
	int theta=0;
	double k;
	double a=0,b=PI/2.0;
	fsalidaa<<"%Theta		"<<"Gaussian Quadrature (n=5)		"<<endl;
	for(int i=0;i<=30;i++) {
		k=sin(theta*PI/(2.0*180));
		fsalidaa <<theta<<"		"<<quadgauss(f,k,a,b)<<endl;
		theta+=5;
	}

	fsalidaa.close();
	
	
	
	
		// Crear un flujo de salida y llamarlo fsalida
	ofstream fsalidab;
	fsalidab.open("Datosb.dat");
	theta=0;
	int val=4; //Número de intervalos.

	fsalidab<<"%Theta		"<<"Trapz		"<<"Simpson1/3		"<<"Simpson3/8		"<<endl;
	for(int i=0;i<=30;i++) {
		k=sin(theta*PI/(2.0*180));
		fsalidab <<theta<<"		"<<trapecio(f,k,a,b,val)<<"		"<<simpson13(f,k,a,b,val)<<"		"<<simpson38(f,k,a,b,val)<<endl;
		theta+=5;
	}

	fsalidab.close();
	
	ofstream fsalidac;
	fsalidac.open("Datosc.dat");
	val=50; //Número de intervalos.
	theta=0;
	fsalidac<<"%Theta		"<<"Trapz		"<<"Simpson1/3		"<<"Simpson3/8		"<<endl;
	for(int i=0;i<=30;i++) {
		k=sin(theta*PI/(2.0*180.0));
		fsalidac <<theta<<"		"<<trapecio(f,k,a,b,val)<<"		"<<simpson13(f,k,a,b,val)<<"		"<<simpson38(f,k,a,b,val)<<endl;
		theta+=5;
	}

	fsalidac.close();
	
	return 0;
}


double trapecio(double (*funcion)(double, double),double k,double a, double b, int n){
	double h=(b-a)/double(n);
	double I,sum=0;
	for (int i=1;i<n;i++){
	sum=sum+(2*funcion(a+(i*h),k));
	}
	I=(h/2.0)*(funcion(a,k)+funcion(b,k)+sum);
		
return I;}

double simpson13(double (*funcion)(double, double),double k,double a, double b, int n){

	if(fmod(n,2)!=0){ //Necesitamos n múltiplo de 2, si n es múltiplo de 2, esto dá 0
		do{ n+=1;
		}while(fmod(n,2)!=0);	
	}
	double h=(b-a)/double(n);
	double I,sum1=0,sum2=0;
	for (int i=1;i<((n/2.0));i++){sum1=sum1+(2*funcion(a+(2*i*h),k));}
	for (int i=1;i<=(n/2.0);i++){sum2=sum2+(4*funcion(a+((2*i-1)*h),k));}
	
	I=(h/3.0)*(funcion(a,k)+funcion(b,k)+sum1+sum2);
		
return I;}

double simpson38(double (*funcion)(double, double),double k,double a, double b, int n){
	
	double I,sum1=0,sum2=0;
	if(fmod(n,3)!=0){ //Necesitamos n múltiplo de 3, si n es múltiplo de 3, esto dá 0
		do{ n+=1;
		}while(fmod(n,3)!=0);	
	}
	double h=(b-a)/double(n);
	for (int i=1;i<n;i++){if(fmod(i,3)!=0){sum1=sum1+(3*funcion(a+(i*h),k));}} //Los no divisibles entre 3
	for (int i=1;i<(n/3.0);i++){sum2=sum2+(2*funcion(a+(3*i*h),k));}
	
	I=(3.0*h/8.0)*(funcion(a,k)+funcion(b,k)+sum1+sum2);
		
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
	for (int i=0;i<5;i++){
		xx=(((b-a)/2)*x[i])+((b+a)/2);
		sum=sum+(w[i]*funcion(xx,k));
	}
	double I=((b-a)/2.0)*sum;
	return I;
}

