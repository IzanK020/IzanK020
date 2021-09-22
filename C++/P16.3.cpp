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
double f2(double r){return((U1*R1/r)*((R2-r)/(R2-R1)));}

int main(){
	
double precision=1e-10;
//Condiciones de contorno
double u1,u2,r1,r2,r;
//Vamos a partir de u(r1)=u1, u'(r1)=p
double p0=(U2-U1)/(R2-R1),p1,p00=p0,p11; 
u1=U1;u2=U1;r=R1;
r1=r;r2=r;
double h=0.1e-2;
//Resolvemos RK para p0
do{RK4(u1,p00,r1,h);}while (r1<R2);
//Calcuamos p1
if((p0*F(u1))>0){p1=p0/2;}
else if((p0*F(u1)<0)){p1=2*p0;}
if(p0==0){
	if(F(p0)>0){p1=1;}
	if(F(p0)<0){p1=-1;}
}
//Reolvemos RK para p1
p11=p1;
do{RK4(u2,p11,r2,h);}while (r2<R2);

double rnew,pnew,unew; //Candidatos a solución
int n=0; //Establecemos un contador
do{
pnew=p1-(F(u2)*((p1-p0)/(F(u2)-F(u1))));  //Definimos pnew
//Reestablecemos condiciones
rnew=R1;unew=U1;
//Redefinimos puntos
p0=p1;		
p1=pnew;
u1=u2;
//Resolvemos rk para pnew
do{RK4(unew,pnew,rnew,h);}while (rnew<R2);

u2=unew;
n++;
}while(fabs(F(unew))>precision); //Es raiz?

cout<<"Tras "<<n<<" iteraciones obtenemos ";
cout<<"un valor de p inicial: "<<p1<<endl;

//Con esto, guardamos la solución
double p=p1;
double u=U1;
r=R1;
//Creamos un flujo de salida para guardar los datos de 
//posicion y tiempo.
ofstream fsalida("data.dat", ios::out);
fsalida<<"%Radio(m))"<<setw(30)<<"Potencial (V)"<<setw(30);
fsalida<<"Derrivada potencial (V)"<<setw(30)<<"Error"<<endl;
fsalida<<r<<setw(30)<<u<<setw(30)<<p<<setw(30);
fsalida<<setprecision(16)<<fabs(u-f2(r))<<endl;
//Iniciamos el método RK
do{	
RK4(u,p,r,h);
fsalida<<r<<setw(30)<<u<<setw(30)<<p<<setw(30)<<setprecision(16)<<fabs(u-f2(r))<<endl;			
}while(r<R2);
	
fsalida.close();
return 0;}
     

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

return (-2*y/t+2*x+8);
}
