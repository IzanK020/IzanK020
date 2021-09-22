#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
void RK4(double &x, double &y, double &t,double h);
double f(double x,double y,double t);
double g(double x,double y,double t);
double U1=110,U2=0,R1=5e-2,R2=10e-2;
double F(double y){return(y);}


int main(){
	double precision=1e-10;
//Condiciones de contorno
double u1,u2,r1,r2,r;
//Vamos a partir de u(r1)=u1, u'(r1)=p
double p0=(U2-U1)/(R2-R1),p1,p00=p0,p11; 
//Resolvemos el sistema para estos valores de p 
u1=U1;u2=U1;r=R1;
r1=r;
double h=0.1e-2;
//Resolvemos rk
do{RK4(u1,p00,r1,h);}while (r1<R2);

if((p0*F(u1))>0){p1=p0/2;}
else if((p0*F(u1)<0)){p1=2*p0;}
double rnew,pnew,unew; //Candidato a raiz
int n=0;
do{
//Resolvemos rk
r1=R1;r2=R1;rnew=R1;p00=p0;p11=p1;u1=U1;u2=U1,unew=U1;
do{
	RK4(u1,p00,r1,h);
	RK4(u2,p11,r2,h);
  }while (r1<=R2);
	
pnew=p1-(F(u2)*((p1-p0)/(F(u2)-F(u1))));  //Definimos xnew
p0=p1;		//Redefinimos puntos
p1=pnew;

//Resolvemos rk
do{
	RK4(unew,pnew,rnew,h);
  }while (rnew<R2);
	
n++;
}while(unew>precision); //Es raiz?
cout<<"Tras "<<n<<" iteraciones obtenemos ";
cout<<"un valor de p inicial: "<<p1<<endl;
double p=p1;
double u=U1;
r=R1;
	//Creamos un flujo de salida para guardar los datos de posicion y tiempo.
	ofstream fsalida("data.dat", ios::out);
	fsalida<<"%Radio(m))"<<setw(30)<<"Potencial (V)"<<setw(30)<<"Derrivada potencial (V)"<<endl;
	fsalida<<r<<setw(30)<<u<<setw(30)<<p<<endl;
	//Iniciamos el método RK
	do{	
	RK4(u,p,r,h);
	fsalida<<r<<setw(30)<<u<<setw(30)<<p<<endl;			
	}while(r<=R2);
	
	fsalida.close();
return 0;
}
     

void RK4(double &x, double &y, double &t,double h){

double k1,l1,k2,l2,k3,l3,k4,l4;

    k1=h*f(x,y,t);
    l1=h*g(x,y,t);

    k2=h*f(x+(k1/2.0),y+(l1/2.0),t+(h/2.0));
    l2=h*g(x+(k1/2.0),y+(l1/2.0),t+(h/2.0));

    k3=h*f(x+(k2/2.0),y+(l2/2.0),t+(h/2.0));
    l3=h*g(x+(k2/2.0),y+(l2/2.0),t+(h/2.0));
    
    k4=h*f(x+k3,y+l3,t+h);
    l4=h*g(x+k3,y+l3,t+h);
    
    t+=h;
    x+=((k1+(2.0*k2)+(2.0*k3)+k4)/6.0);
    y+=((l1+(2.0*l2)+(2.0*l3)+l4)/6.0);
   
}

double f(double x,double y,double t){

//F Función que contiene la derivada del potencial.
//   f(x,t)=x'

return (y);
}
double g(double x,double y,double t){

//F Función que contiene la segunda derivada del potencial.
//   f(x,t)=x'

return (-2*y/t);
}
