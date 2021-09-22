// Ejercicio 1
// Método de RK de orden 4 para una edo de la forma;
//  dx/dt=f(x,t)

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
void RK4(double &x, double &t,double h);
double f(double x,double t);

//Definimos varibales globales.
double Rp=0.586; // En AU
double Vp=11.513; // En AU/año
double GM=39.489326;
double L=Rp*Vp, E=(0.5*Vp*Vp)-(GM/Rp);

int main(){
	double x=1.0001*Rp;
	double t=0;
	double h=0.01;
	//Creamos un flujo de salida para guardar los datos de posicion y tiempo.
	ofstream fsalida("data.dat", ios::out);
	fsalida<<"%Tiempo(años)"<<setw(20)<<"Radio(AU)"<<endl;
	fsalida<<t<<setw(30)<<x<<endl;
	//Iniciamos el método RK
	do{	
	RK4(x,t,h);	
	fsalida<<t<<setw(30)<<x<<endl;			
	}while(f(x,t)*f(x,t)>1e-7);
	
	fsalida.close();
	cout<< "Periodo calculado: "<<2*t<<endl;
	cout<< "Ra= "<<x<<endl;
	
	
	
	return 0;
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

return (sqrt((2.0*E)-(L*L/(x*x))+(2.0*GM/x)));
}


