// Izan Kevin Fdez. Tostado
// Ejercicio 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

void DiagJacobi(double **A, double **U, double **D,double *O,double *Traza, int n, double tolerancia);
void print(double **A,int dim);
double Off(double **A, int dim);
double FTraza(double **A, int dim);

int main ()
{
	
int n=5;
double tolerancia=1e-10;
	
		double **D;
		double **U;
		double **A;
		//  Reserva dinamica de memoria. 
		//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
  		  D = new double * [n]; // Matriz Diagonalizada
  		  U = new double * [n]; //Matriz cambio de base, contiene los autovec
  		  A = new double * [n]; //Matriz a diagonalizar
		//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
   		 for(int i = 0; i < n; i++)
    	{
           	 D[i] = new double[n]; // Segunda etapa.
           	 U[i] = new double [n];
           	 A[i] = new double [n];
   		 }
   		 
 //Rellenamos matriz A
	// Crear un flujo de entrada y llamarlo fentrada
	ifstream fentrada("data.dat", ios::in);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			fentrada >> A[i][j];
		}
	}
	fentrada.close(); // cerrar el archivo

	double O[32];
	double Traza[32];
	cout<<"Matriz a diagonalizar:"<<endl;
	print(A,n);
	
	DiagJacobi(A,U,D,O,Traza,n,tolerancia);
	
	cout<<" Autovalores:"<<endl;
	print(A,n);
	
	cout<<"Autovec:"<<endl;
	print(U,n);
	

	
	
	ofstream datao;
	datao.open("Resultados.dat");
	double Ok; //Variable que contendra log(Off(Ak)/Off(A))
	double Ot; //Teórico; klog(1-(2/(n^2-n))) donde n es la dimension de la matriz
	for (int k=1;k<32;k++) {
		
	Ok=log10(O[k]/O[0]);
	Ot=k*log10(1.0-(2.0/((double(n)*double(n))-double(n))));
	datao<< k<<"	"<< Ok<<"	"<< Ot << endl;
			
	}

	datao.close();

	ofstream datao2;
	datao2.open("Traza.dat");
	

	for (int k=0;k<32;k++) {
	
	datao2<< k<<"	"<< Traza[k]<< endl;
			
	}

	datao2.close();

		
		

	return 0;
}


void DiagJacobi(double **A, double **U, double **D, double *O, double *Traza,int n, double tolerancia)
{
	
	//Vamos a rellenar la matriz U con la identidad
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{ 
			if(i==j){U[i][j]=1;	}
			if(i!=j){U[i][j]=0;	}
		}
	}
	
	//Definimos unas cuantas variables...
	
	O[0]=Off(A,n);
	Traza[0]=FTraza(A,n);
	int contador=0;
	int i;
	int j;
	double max,theta,uki,ukj,aki,akj,aii,ajj;
	//Que empiece el bucle!
	do
	{
		//Buscamos el elemento maximo encima de la diagonal
		max=0; i=0; j=1; //Valor inicial, este va a cambiar luego.
		//Recorremos la matriz por ENCIMA de la diagonal
		for(int ib=0;ib<n;ib++){	
			for(int jb=ib+1;jb<n;jb++){ //Cuando i=0, j empieza en 1; Cuando i=1, j empieza en 2(la diagonal será el 0,0; 1,1;
				if(fabs(A[ib][jb])>=max){max=fabs(A[ib][jb]);i=ib;j=jb;} //Si este valor es mayor que el max anterior lo guardamos como el max.
			}
		}
		//Tenemos ahora el valor max que es el A[i][j].
		
		//Calcúlese \theta
		if(A[i][i]!=A[j][j]){theta=0.5*atan(2*A[i][j]/(A[i][i]-A[j][j]));}
		if(A[i][i]==A[j][j]){theta=atan(1.0);}
		// Pues ya tenemos theta.
		
		//Ahora calculamos los nuevos elementos de U
		for (int k=0;k<n;k++){
			uki=U[k][i];
			ukj=U[k][j];
			U[k][i]=uki*cos(theta)+ukj*sin(theta);
			U[k][j]=-uki*sin(theta)+ukj*cos(theta);	
		}
		cout<<max<<" "<<i<<""<<j<<endl;
		//Cálculamos la nueva A(la cual esperamos que se convierta en la diagonal D)
		for (int k=0;k<n;k++){
			if (k!=j && k!=i){ //Condición dada por el método
			
			aki=A[i][k];
			akj=A[j][k];
			A[k][i]=(aki*cos(theta))+(akj*sin(theta));  //7b
			A[i][k]=A[k][i];
			A[k][j]=(-aki*sin(theta))+(akj*cos(theta));	//7c
			A[j][k]=A[k][j];
			
			}	
			}
		
		    aii=A[i][i];
			ajj=A[j][j];
			A[i][i]=(aii*cos(theta)*cos(theta))+(ajj*sin(theta)*sin(theta))+(2*A[i][j]*sin(theta)*cos(theta)); //7d
			A[j][j]=(aii*sin(theta)*sin(theta))+(ajj*cos(theta)*cos(theta))-(2*A[i][j]*sin(theta)*cos(theta)); //7e
			
			
			A[i][j]=0;  //Como dice la ecuación (7a'), se escoge theta tq esto sea 0.
			A[j][i]=0;
			
		//Buscamos el nuevo maximo encima de la diagonal
		max=0; i=0; j=1; //Valor inicial, este va a cambiar luego.
		//Recorremos la matriz por ENCIMA de la diagonal
		for(int ib=0;ib<n;ib++){	
			for(int jb=ib+1;jb<n;jb++){ //Cuando i=0, j empieza en 1; Cuando i=1, j empieza en 2(la diagonal será el 0,0; 1,1;
				if(fabs(A[ib][jb])>=max){max=fabs(A[ib][jb]);i=ib;j=jb;} //Si este valor es mayor que el max anterior lo guardamos como el max.
			}
		}
		
		contador ++;
		O[contador]=Off(A,n);
		Traza[contador]=FTraza(A,n);
		
	}while(fabs(max)>tolerancia);//Es el máximo mayor que la tolerancia?; Si no lo es pues de vuelta al bucle.
	
	//Hemos salido del Bucle!!!
	// Ahora deberiamos tener una matriz U que no dé los vectores y una matriz A que sea diagonal.
	cout<< "N de iteraciones totales "<< contador <<endl;
	
	
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

double FTraza(double **A, int dim)
{	double sum=0;
	double s=0;
	for(int i=0;i<dim;i++) {
		for(int j=0;j<dim;j++) {
			if	(i==j){
			s=A[i][j];
			sum=sum+s;
			}			
		}
	}
	return sum;
}

double Off(double **A, int dim)
{ 	double sum=0;
	double s=0;
	
	for(int i=0;i<dim;i++) {
		for(int j=0;j<dim;j++) {
			if	(i!=j){
			s=(fabs(A[i][j])*fabs(A[i][j]));
			sum=sum+s;
			}			
		}
	}
	return sum;
}


