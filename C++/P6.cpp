//Problema 1
// Encontrar ceros de una funci�n mediante tres m�todos, bisecci�n, secante y newton
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
//Escribo prototipos de mis funciones
double f(double x);
double fp(double x);
double biseccion(double(*funcion)(double),double x11,double x22, double precision);
double secante(double(*funcion)(double),double x00,double x11, double precision);
double newton(double(*funcion)(double),double(*funcion2)(double),double x00, double precision);


int main ()
{
/* Mediante inspecci�n visual(haciendo plot en matlab). He encontrado dos raices.
Uno de ellas, est� en el intervalo (-6,-5), la otra, en el intervalo (-4,-3).
Con esta informaci�n podemos buscar raices.*/
 //Usemos primero el m�todo de bisecci�n.
 //Empezar� buscando la raiz en el primer intervalo.
double x1=-6.0;  //Intervalo 1
double x2=-5.0;
double x11=-4.0; //Intervalo 2
double x22=-3.0;
double r1,r2; //Raices
double precision=1e-7;
 //Usemos primero el m�todo de bisecci�n.
 //Empezar� buscando la raiz en el primer intervalo.
r1=biseccion(f,x1,x2,precision);
 //Buscamos ahora en el segundo intervalo.
r2=biseccion(f,x11,x22,precision);
 //Mostramos en pantalla
cout<<"Mediante el metodo de biseccion, hemos encontrado las raices: "<<endl;
cout<<" "<<setprecision(8)<<r1<<" con un valor de f(x1)= "<<setprecision(3)<<f(r1)<<endl;
cout<<" "<<setprecision(8)<<r2<<" con un valor de f(x2)= "<<setprecision(3)<<f(r2)<<endl;;
cout<<" "<<endl;
 //Pasemos ahora al m�todo de la secante.
 //Empezar� buscando la raiz en el primer intervalo.
r1=secante(f,x1,x2,precision);
 //Buscamos ahora en el segundo intervalo.
r2=secante(f,x11,x22,precision);
 //Mostramos en pantalla
cout<<"Mediante el metodo de la secante, hemos encontrado las raices: "<<endl;
cout<<" "<<setprecision(8)<<r1<<" con un valor de f(x1)= "<<setprecision(3)<<f(r1)<<endl;
cout<<" "<<setprecision(8)<<r2<<" con un valor de f(x2)= "<<setprecision(3)<<f(r2)<<endl;;
cout<<" "<<endl;
	
 //Por �ltimo, ejecutamos el m�todo de Newton.
 //Empezar� buscando la raiz en el primer intervalo.
r1=newton(f,fp,x2,precision);
 //Buscamos ahora en el segundo intervalo.
r2=newton(f,fp,x11,precision);
 //Mostramos en pantalla
cout<<"Mediante el metodo de newton, hemos encontrado las raices: "<<endl;
cout<<" "<<setprecision(8)<<r1<<" con un valor de f(x1)= "<<setprecision(3)<<f(r1)<<endl;
cout<<" "<<setprecision(8)<<r2<<" con un valor de f(x2)= "<<setprecision(3)<<f(r2)<<endl;;
cout<<" "<<endl;
	
	
	
	
	return 0;
}

double f(double x)		//Funci�n dada en el enunciado
{return (2.0*sin(x)-(exp(x)/4.0)-1.0);}  
//Pongo 2.0 y 4.0 para que me los tome como duble
double fp(double x)		//Derivada de la fuunci�n dada en el enunciado
{return (2.0*cos(x)-(exp(x)/4.0));}  
//Pongo 2.0 y 4.0 para que me los tome como duble



double biseccion(double(*funcion)(double),double x11,double x22, double precision)
{	//C�lculo de ceros de una funci�n mediante el m�todo de la bisecci�n
	/* Se recibe como argumentos la funcion en la cual buscamos el m�nimo,
		y dos puntos cercanos a esa raiz con signos contrarios de f. 
		Tambien se pide la precisi�n*/
double x1,x2; //negativo,positivo
//Primero vemos cual es negativo y cual positivo.
if (funcion(x11)<0) //Si x11 es el negativo y x22 el positivo, los asigno as�
	{x1=x11;		
	if(funcion(x22)>0)	
	{x2=x22;
	}
	else {
		cout<<"En el intervalo no existe un cambio de signo"<<endl;
		return 0;
		}
	}
if (funcion(x11)>0)	//Si x11 es el positivo y x22 el negativo, los asigno as�
	{x2=x11;		
	if(funcion(x22)<0)	
	{x1=x22;
	}
	else 
		{
		cout<<"En el intervalo no existe un cambio de signo"<<endl;
		return 0;
		}
	}

//Con esto, podemos empezar el m�todo.
double xnew; //Candidato a raiz
do{
	xnew=(x1+x2)/2.0;  //Definimos xnew
	if (funcion(xnew)*funcion(x1)<0)  //Si xnew es el positivo(x1 es el negativo).
		x2=xnew;					// Se convierte en el nuevo x2.
	else 	//Si xnew es el positivo, se convierte en el nuevo x1.
		x1=xnew;
	
}while(fabs(funcion(xnew))>precision); //Es raiz?

return xnew;	
}

double secante(double(*funcion)(double),double x00,double x11, double precision)
{	//C�lculo de ceros de una funci�n mediante el m�todo de la secante
	/* Se recibe como argumentos la funcion en la cual buscamos el m�nimo,
		y dos puntos cercanos a esa raiz. 
		Tambien se pide la precisi�n*/
double x0,x1; //Condicion del m�todo: abs(f(x0))<abs(f(x1)).
//Comprobemos la condici�n
if (fabs(funcion(x11))<fabs(funcion(x00))) 
	{x0=x00;	
	 x1=x11;		
	}
else 
	{x1=x00;	
	 x0=x11;
	}

//Con esto bien definido, podemos empezar el m�todo.
double xnew; //Candidato a raiz
do{
	xnew=x1-(funcion(x1)*((x0-x1)/(funcion(x0)-funcion(x1))));  //Definimos xnew
	x0=x1;		//Redefinimos puntos
	x1=xnew;
	
}while(fabs(funcion(xnew))>precision); //Es raiz?

return xnew;	
}

double newton(double(*funcion)(double),double(*funcion2)(double),double x0, double precision)
{	//C�lculo de ceros de una funci�n mediante el m�todo de Newton.
	/* Se recibe como argumentos la funcion en la cual buscamos el m�nimo,
		su derivada	y un punto cercano a esa raiz. 
		Tambien se pide la precisi�n*/
//Condicion del m�todo: f(x0)!=0 y f'(x0)!=0. Si no, no converge bien

//Podemos empezar el m�todo.
double xnew; //Candidato a raiz
do{
	if(funcion(x0)!=0 && funcion2(x0)!=0) /*Necesitamos que esto se cumpla.
						Si no, es facil ver que el m�todo no podr�a seguir*/
	{
											
	xnew=x0-(funcion(x0)/funcion2(x0));  //Definimos xnew
	x0=xnew;		//Redefinimos puntos
	}
	else //�Y si no se cumple?. Lo hacemos saber al programa.
	{
		cout<<"Error, o f(x0)=0 o f'(x0)!=0";
		break; //Rompemos el bucle
	}
}while(fabs(funcion(xnew))>precision); //Es raiz?

return xnew;	
}
