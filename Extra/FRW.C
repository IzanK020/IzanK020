// Ejercicio 2
// Método de RK de orden 4 para una edo de la forma;
//  dx/dt=f(x,t)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"
using namespace std;
void RK4(double &x, double &t,double h);
double f(double x,double t);
double g(double x);
double simpson38(double (*funcion)(double),double a, double b, int n);
double Onr=0,Or=0,Ol=0,Ok=0;

void FRW(){
//int main(){
	do{
		// Primero introducimos datos de nuestro universo.
		cout<<"Introducimos los parametros de nuestro universo."<<endl;
		cout<<"Omega no relativista = ";
		cin>> Onr; 
		cout<<endl<<"Omega relativista = ";
		cin>> Or; 
		cout<<endl<<"Omega Lambda = ";
		cin>> Ol; 
		cout<<endl<<"Omega curvatura = ";
		cin>> Ok; 
		cout<<endl;
		// Suman uno??
		if (Onr+Or+Ol+Ok-1>1e-6){
		cout<<"Error. Las omegas deben sumar uno."<<endl;}
	}while(Onr+Or+Ol+Ok-1>1e-6);
	
	double x=1.0;
	double ti=0.0;
	double h=0.1;
	//Creamos un array para guardar los datos de posicion y tiempo.
	// Define two vectors.
	std::vector<double_t> a,t,ea,et;
	
	a.push_back(x);
	t.push_back(ti);
	ea.push_back(0.0);
	et.push_back(0.0);
	int i=0;
	//Iniciamos el método de integración
	do{	
	//RK4(x,ti,h);
	ti=simpson38(g,1.0,x,50);	
	a.push_back(x);
	t.push_back(ti);
	ea.push_back(0.0);
	et.push_back(0.0);

	i++;	
	x+=h;
	}while(i<1000);
	auto gr = new TGraph(i, &t[0], &a[0]);
	gr->Draw("ACP");
	//return(0);
}

void RK4(double &x, double &t,double h){
 
double k1,l1,k2,l2,k3,l3,k4,l4;

	k1=h*f(x,t);
   	k2=h*f(x+(k1/2.0),t+(h/2.0));
   	k3=h*f(x+(k2/2.0),t+(h/2.0));
    	k4=h*f(x+k3,t+h);

    	t+=h;
    	x+=((k1+(2.0*k2)+(2.0*k3)+k4)/6.0);
 
}

double f(double x,double t){

//F Función que contiene la derivada de la posición.
//   f(x,t)=x'
double preans=(Or*pow(x,-4))+(Onr*pow(x,-3))+(Ok*pow(x,-2))+(Ol);
double ans=x*sqrt((preans));
if (preans>0){return(ans);}
else {return(ans);}
}

double g(double x){

//F Función que contiene la derivada de la posición.
//   f(x,t)=x'
double preans=(Or*pow(x,-4))+(Onr*pow(x,-3))+(Ok*pow(x,-2))+(Ol);
double ans=x*70*sqrt(preans);
return(1/ans);
}


double simpson38(double (*funcion)(double),double a, double b, int n){
	
	if(a==b){return 0.0;}
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
