//Problema 1
// Ejercicio 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

void LU(double **A, double *b,double *x, int dim);
void sistdiagU(double **A,int dim,double *x,double *b);
void sistdiagL(double **A,int dim,double *x,double *b);
double f(double x,double y, double z,int n);
void Jac(double **J,double *x1, int dim);
double norm(double *v,int dim);
void NR(double *x,double tolerancia,int dim);
void print(double **A,int m, int n);

int main ()
{	
	double x[3]={1,1,1};
	double tolerancia=1e-8;
	int dim=3;
	NR(x,tolerancia,dim);
	
cout<< " La solucion es : ";
    for (int i=0;i<dim;i++) {cout<<x[i]<<" ";}
    
	return 0;
	
}

double f(double x,double y, double z,int n)
{	
	
	if(n==0) {return ((6.0*x)-(2.0*cos(y*z))-1);}
	if(n==1) {return ((9.0*y)+sqrt(pow(x,2.0)+sin(z)+1.06)+0.9);}
	if(n==2) {return ((60.0*z)+(3.0*exp(-x*y))+(10.0*4.0*atan(1.0))-3);}
}

void Jac(double **J,double *x1, int dim)
{	
	double eps=1e-8;
	double h[dim];
	double x=x1[0];
	double y=x1[1];
	double z=x1[2];
	for (int i=0;i<dim;i++)
	{	
		for (int j=0; j<dim;j++)
		{
			for (int k=0;k<dim;k++)
			{ 
			if (k==j) {h[k]=eps;}
		   	else { h[k]=0;}
			}
		 J[i][j]=((f(x+h[0],y+h[1],z+h[2],i)-f(x-h[0],y-h[1],z-h[2],i))/(2*eps));
		}	
		
	}	
}

void NR(double *x,double tolerancia,int dim)
{	
	double xold[3];
	double deltax[3];
	double b[3];


	double **J;
//  Reserva dinamica de memoria. 
	//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
  		  J = new double * [dim]; // Primera etapa.
	//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
   		 for(int i = 0; i < dim; i++)
    	{
           	 J[i] = new double[dim];
           	
   		 }

	
	do{
		for (int i=0;i<dim;i++){xold[i]=x[i];}
		Jac(J,xold,dim);
		for (int j=0;j<dim;j++){b[j]=-f(xold[0],xold[1],xold[2],j);}
		LU(J,b,deltax,dim);

		for(int k=0;k<dim;k++){x[k]=xold[k]+deltax[k];}	
	
	} while(fabs(norm(x,dim)-norm(xold,dim))> tolerancia);
	
	
	 for (int i = 0; i < dim; i++)
    {
       delete [] J[i];
    }
    delete [] J;
}


double norm(double *v,int dim)
{	double n=0;
	for(int i=0;i<dim;i++)
 	{
		n=n+(v[i]*v[i]);
 	}
 	return n;
}

void LU(double **A, double *b,double *x, int dim)
{	
		double **L;
		double **U;

		//  Reserva dinamica de memoria. 
		//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
  		  L = new double * [dim]; // Primera etapa.
  		  U = new double * [dim];

		//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
   		 for(int i = 0; i < dim; i++)
    	{
           	 L[i] = new double[dim]; // Segunda etapa.
           	 U[i] = new double [dim];
   		 }


	for (int i=0;i<dim;i++)
	{ for (int j=0;j<dim;j++)
	  {
	  	if(i>j)
	  	{
	  		U[i][j]=0;
	  		double sumL=0;
	  		for (int k=0;k<j;k++)
	  		{	
	  			sumL=sumL+(L[i][k]*U[k][j]);
			}
	  		L[i][j]=(1.0/U[j][j])*(A[i][j]-sumL);
		}
		if (i<=j)
		{
	  	double sumU=0;
	  		for (int k=0;k<i;k++)
	  		{	
	  		sumU=sumU+(L[i][k]*U[k][j]);
			}
		U[i][j]=A[i][j]-sumU;
			if(i==j) {L[i][j]=1;}
			if(i!=j) {L[i][j]=0;}	
		}
	  }
	}
	
//Resolvemos primero el sistema Lz=b

	double z[dim];

	sistdiagL(L,dim,z,b);

//Resolvemos el sistema Ux=z
	sistdiagU(U,dim,x,z);
	
	
	//Liberamos memoria
	 for (int i = 0; i < dim; i++)
    {
       delete [] L[i];
       delete [] U[i];

    }
    delete [] L;
	delete [] U;
}





void sistdiagU(double **A,int dim,double *x,double *b)
{//Triangular superior 
	
		for (int i=(dim-1);i>=0;i--)
		{	double sumx=0;
			for (int j=i+1;j<dim;j++)
			{	double a=(A[i][j]*x[j]);
				sumx=sumx+a;
			}
			x[i]=(1.0/A[i][i])*(b[i]-sumx);
		}
}

void sistdiagL(double **A,int dim,double *x,double *b)
{//Triangular inferior
		for ( int i=0;i<dim;i++)
		{	
			double sumx=0;
			for (int j=0;j<i;j++)
			{
			double s=(A[i][j]*x[j]);
			sumx=sumx+s;
			}
			x[i]=b[i]-sumx;	
		}

}

void print(double **A,int m, int n)
{	

	for(int i=0;i<m;i++) 
	{
		for(int j=0;j<n;j++) 
		{
		cout<< A[i][j]<<"  ";		
		}
	cout<<" "<<endl;
	}
}

