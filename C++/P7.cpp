//Problema 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
void print(double **A,int dim);
void LU(double **A, double **L,double **U,int dim);
void sistdiag(double **A,int dim,double *x,double *b);

int main ()
{	int n=5;
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

 //Rellenamos matriz A
	char archivo_entrada[30];
	cout << "Introduzca nombre del archivo de entrada: ";
	cin >> archivo_entrada;

	// Crear un flujo de entrada y llamarlo fentrada
	ifstream fentrada(archivo_entrada, ios::in);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			fentrada >> A[i][j];
		}
	}
	fentrada.close(); // cerrar el archivo
	
//Calculamos L y U
LU(A,L,U,n);
//Pintamos en pantalla

cout<<endl<<"Matriz L: "<<endl;
print(L,n);
cout<<"Matriz U: "<<endl;
print(U,n);

	
//Teniendo L y U, solo nos queda resolver dos sistemas triangulares.
//Resolvemos primero el sistema Lz=b
double b[5]={14,-10,4,6,12};
double x[5];
double z[5];
sistdiag( L,n,z,b);

//Resolvemos el sistema Ux=z
sistdiag(U,n,x,z);

cout<<"La solucion es x: "<<endl;
for (int i=0;i<n;i++)
{
	cout<<x[i]<<endl;
}

	
	
	
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


void sistdiag(double **A,int dim,double *x,double *b)
{//¿Triangular superior o inferior?

	if(A[0][dim-1]==0) //Triangular inferior
	{	
		for ( int i=0;i<5;i++)
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

	if(A[dim-1][0]==0) //Triangular superior
	{
		for (int i=(dim-1);i>=0;i--)
		{	double sumx=0;
			for (int j=i+1;j<dim;j++)
			{	double a=(A[i][j]*x[j]);
			sumx=sumx+a;
			}
			x[i]=(1.0/A[i][i])*(b[i]-sumx);
		}
	}

	
}



void LU(double **A, double **L,double **U,int dim)
{
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
}

void print(double **A,int dim)
{	cout<<" "<<endl;

	for(int i=0;i<dim;i++) {
		for(int j=0;j<dim;j++) {
		cout<< A[i][j]<<"  ";		
	}
	cout<<" "<<endl;
}
}


