#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

double U1=110,U2=0,R1=5e-2,R2=10e-2;
void LUtridiag(double **A,double *f, double **L,double **U,double *x,int dim);
double p(double r){return(-2/r);}
double q(double r){return(0);}
double R(double r){return(0);}

int main(){
	double h=0.1e-2;
	
	int n=((R2-R1)/h)-1;
	//Reservamos memoria para las matrices L, U y A, así podremos pasarlas como punteros.
		double **L;
		double **U;
		double **A;
		//  Reserva dinamica de memoria. 
		//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
  		  L = new double * [n]; // Primera etapa.
  		  U = new double * [n];
  		  A = new double * [n];
		//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
   		 for(int i = 0; i < n; i++)
    	{
           	 L[i] = new double[n]; // Segunda etapa.
           	 U[i] = new double [n];
           	 A[i] = new double [n];
   		 }
double f[n-1];

 //Rellenamos matriz A
	for (int i=0; i<n; i++)
	{

		for (int j=0; j<n; j++)
		{	A[i][j]=0;	}
		
		A[i][i]=2+(h*h*q(R1+((i+1)*h)));
		A[i][i-1]=-1-(h*p(R1+((i+1)*h))/2);
		A[i][i+1]=-1+(h*p(R1+((i+1)*h))/2);		
	}
	
	f[0]=-(h*h*R(R1+(h)))+(1+(h*p(R1+h)/2))*U1;
	f[n-1]=-(h*h*R(R2-h))+(1-(h*p(R2-h)/2))*U2;
	
	for (int i=1; i<(n-1); i++){
	f[i]=-h*h*R(R1+((i+1)*h));
	}

double x[n-1];

//Calculamos L y U
LUtridiag(A,f,L,U,x,n);
//Guardamos el vector solución x

	ofstream datao;
	datao.open("Datos.dat");
	datao<< "%Radio R(cm)"<<setw(30)<<"Potencial U(V)"<< endl;
	datao<< R1<<setw(30)<<U1<< endl;
	for(int i=0;i<n;i++){	
		datao<<R1+((i+1)*h)<<setw(30)<< x[i] << endl;	
	}
	datao<< R2<<setw(30)<<U2 << endl;
	datao.close();

	//Liberamos memoria
	 for (int i = 0; i < n; i++)
    {
       delete [] L[i];
       delete [] U[i];
       delete [] A[i];
    }
    delete [] L;
	delete [] U;
	delete [] A;

	return 0;
}

void LUtridiag(double **A,double *f, double **L,double **U,double *x,int dim)
{	double z[dim-1];
	
	for (int i=0;i<dim-1;i++)
	{ U[i][i+1]=A[i][i+1];}
	
	U[0][0]=A[0][0];
	z[0]=f[0];

	for (int i=1;i<dim;i++)
	{
		L[i][i-1]=(A[i][i-1])/(U[i-1][i-1]);
		U[i][i]=A[i][i]-(L[i][i-1]*A[i-1][i]);
		z[i]=f[i]-(L[i][i-1]*z[i-1]);		
	}
	x[dim-1]=z[dim-1]/(U[dim-1][dim-1]);
	
	for (int i=(dim-2);i>=0;i--)
	{ 
		x[i]=(z[i]-(A[i][i+1]*x[i+1]))/(U[i][i]);	
		
	}
}



