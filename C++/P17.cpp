// Ejercicio 1
// Método de RK de orden 2 para un sistema de ecs;
//  dx/dt=f(x,y,t)
//  dy/dt=g(x,y,t)
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;
void RK4(double &t, double *x, double tau);
double f(double t,double *x,int i);


double km1=2.5,km2=3.5,m1=2,m2=3.5;


int main(){
	//Condiciones iniciales
	double y[4]={3,4,0,0},t=0,tau=0.1;
	//Creamos un flujo de salida
	fstream fsalida("data.dat",ios::out);
	fsalida<<"%Tiempo "<<setw(30)<<"y1"<<setw(30)<<"y2"<<setw(30)<<"vy1"<<setw(30)<<"vy2"<<endl;
	fsalida<<t<<setw(30)<<y[0]<<setw(30)<<y[1]<<setw(30)<<y[2]<<setw(30)<<y[3]<<endl;
	do{

	RK4(t,y,tau);		
	fsalida<<t<<setw(30)<<y[0]<<setw(30)<<y[1]<<setw(30)<<y[2]<<setw(30)<<y[3]<<endl;
	}while(t<(100));
	fsalida.close();
	

	return 0;
}

void RK4(double &t,double *x, double tau){

double k1[4],k2[4],k3[4],k4[4],h2[4],h3[4],h4[4];

for ( int i=0;i<4;i++){
	k1[i]=tau*f(t,x,i);
}
for ( int i=0;i<4;i++){
	for( int k=0;k<4;k++){h2[k]=x[k]+(0.5*k1[k]);}
    k2[i]=tau*f(t,h2,i);
}
for ( int i=0;i<4;i++){
    for( int k=0;k<4;k++){h3[k]=x[k]+(0.5*k2[k]);}
    k3[i]=tau*f(t,h3,i);
}
for ( int i=0;i<4;i++){
	for( int k=0;k<4;k++){h4[k]=x[k]+(k3[k]);} 
    k4[i]=tau*f(t,h4,i);
}
for ( int i=0;i<4;i++){
    x[i]+=((k1[i]+(2.0*k2[i])+(2.0*k3[i])+k4[i])/6.0);
}
	t+=tau;
}

double f(double t,double *x,int i){
if(i==0){return(x[2]);}
if(i==1){return(x[3]);}
if(i==2){return(-(km1*x[0]/m1)-((km2/m1)*(x[0]-x[1])));}
if(i==3){return((km2/m2)*(x[0]-x[1]));}

}

