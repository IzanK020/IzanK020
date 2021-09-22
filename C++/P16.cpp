// Ejercicio 2
// Método de RK de orden 4 para una edo de la forma;
//  dx/dt=f(x,t)

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
void RK4(double &x,double t,double h);
void Euler(double &x,double t,double h);
double f(double x,double t);

//Definimos varibales globales.
double vlim=57;
double g=9.8; 
double gamma=g/(vlim*vlim);


int main(){
	double vE=0,vRK=0;
	double t=0;
	double h=0.01;
	//Creamos un flujo de salida para guardar los datos de posicion y tiempo.
	ofstream fsalida("data.dat", ios::out);
	fsalida<<"%Tiempo(segundos)"<<setw(20)<<"Velocidad Euler"<<setw(20)<<"Velocidad RK4"<<endl;
	fsalida<<t<<setw(30)<<vE<<setw(30)<<vRK<<endl;	
	//Iniciamos el método RK
	do{	
	t+=h;
	RK4(vRK,t,h);	
	Euler(vE,t,h);
	fsalida<<t<<setw(30)<<vE<<setw(30)<<vRK<<endl;			
	}while(t<25);
	fsalida.close();
	
	
	
	
	return 0;
}

void RK4(double &x,double t,double h){
 
double k1,l1,k2,l2,k3,l3,k4,l4;

	k1=h*f(x,t);
    k2=h*f(x+(k1/2.0),t+(h/2.0));
    k3=h*f(x+(k2/2.0),t+(h/2.0));
    k4=h*f(x+k3,t+h);

    x+=((k1+(2.0*k2)+(2.0*k3)+k4)/6.0);
 
}

void Euler(double &x,double t,double h){
 
    x+=h*f(x,t);
 
}

double f(double x,double t){

//F Función que contiene la derivada de la posición.
//   f(x,t)=x'

return (g-(gamma*x*x));
}


