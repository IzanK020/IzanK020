//Problema 1
// Método LU para matrices tridiagonales.
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

void LUtridiag(double **A,double *f, double **L,double **U,double *x,int dim);

int main ()
{	int n=1000;
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
		if (i==0) {f[i]=100;}
		else if (i==(n-1)) {f[i]=100;}
		else	{f[i]=200;}
		for (int j=0; j<n; j++)
		{	A[i][j]=0;	}
		
		A[i][i]=4;
		A[i][i-1]=-1;
		A[i][i+1]=-1;
			
	}

double x[n-1];

//Calculamos L y U
LUtridiag(A,f,L,U,x,n);
//Guardamos el vector solución x

	ofstream datao;
	datao.open("Datos.dat");

	for(int i=0;i<n;i++)
	{	
		datao<<i<<"  "<< x[i] << endl;	
	}
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


