//Problema 1
// Ejercicio 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

void Jacobi(double **A,double *x,double *b,int dim,int &k,double tolerancia);
void GaSe(double **A,double *x,double *b,int dim,int &k,double tolerancia);
void GaSeW(double **A,double *x,double *b,int dim,int &k,double tolerancia,double w);
double norm(double *v,int dim);
int main ()
{
	int n=5; //Dimensión de la matriz.
//Reservamos memoria para la matriz A, así podremos pasarlas como punteros.
	double **A;
	//  Reserva dinamica de memoria. 
	//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
  		  A = new double * [n];
		//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
   		 for(int i = 0; i < n; i++)
    	{
           	 A[i] = new double [n];
   		 }

 //Rellenamos matriz A
	// Crear un flujo de entrada y llamarlo fentrada
	ifstream fentrada("matriz.dat", ios::in);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			fentrada >> A[i][j];
		}
	}
	fentrada.close(); // cerrar el archivo


// Definimos el vector x (incógnita) y el vector b (Términos indept.)
double x1[5]; //Almacenará en valor mediante el método de Jacobi.
double x2[5]; //Almacenará en valor mediante el método de Gauss-Seidel.
double b[5]={14,-10,4,6,12};
int k1=0;
int k2=0;
double tolerancia=1e-7;

cout<<"Dada una tolerancia de " <<tolerancia<<endl;
//Resolvemos mediante Jacobi 
Jacobi(A,x1,b,n,k1,tolerancia);
cout<<"La solucion mediante el metodo de jacobi es x: "<<endl;
for (int i=0;i<n;i++)
{
	cout<<x1[i]<<endl;
}
cout<<"Tras "<<k1<<" interacciones."<<endl;
cout<<" "<<endl;
//Resolvemos mediante Gauss-Seidel. 
GaSe(A,x2,b,n,k2,tolerancia);
cout<<"La solucion mediante el metodo de jacobi es x: "<<endl;
for (int i=0;i<n;i++)
{
	cout<<x2[i]<<endl;
}
cout<<"Tras "<<k2<<" interacciones."<<endl;
cout<<" "<<endl<<"Estudiemos la convergencia"<<endl;
cout<<"Tolerancia    Jacobi    Gauss-Seidel"<<endl;
//Estudiemos ahora la convergendia para distintos valores de la tolerancia.
for (int j=1;j<=10;j++)
{	double tolerancia=pow(10,-j); 
	k1=0;  //Contadores a cero
	k2=0;
	//	cout<<"Dada una tolerancia de " <<tolerancia<<endl;
	//Resolvemos mediante Jacobi 
	Jacobi(A,x1,b,n,k1,tolerancia);
	//Resolvemos mediante Gauss-Seidel. 
	GaSe(A,x2,b,n,k2,tolerancia);
	//Comentamos
	//cout<<"El metodo de Jacobi converge tras "<<k1<<" interacciones."<<endl;
	//cout<<"El metodo de Gauss-Seidel converge tras "<<k2<<" interacciones."<<endl;
	cout<<tolerancia<<"            "<<k1<<"            "<<k2<<endl;
}

//Veamos como afecta el factor w a la convergencia
cout<<" "<<endl<<"Estudiemos los efectos de w"<<endl;
cout<<" w   Gauss-Seidel  Con sobrerrelajacion"<<endl;
for (double j=1.0;j<10;j++)
{	double tolerancia=1e-7; 
	double w=1+(0.1*j);
	k1=0;  //Contadores a cero
	k2=0;

	GaSe(A,x2,b,n,k1,tolerancia);
	GaSeW(A,x2,b,n,k2,tolerancia,w);
	//Comentamos
	cout<<w<<"      "<<k1<<"        "<<k2<<endl;

}



//Liberamos memoria
	 for (int i = 0; i < n; i++)
    {
       delete [] A[i];
    }
	delete [] A;
		
	return 0;
}
double norm(double *v,int dim)
{	double n=0;
	for(int i=0;i<dim;i++)
 	{
		n=n+(v[i]*v[i]);
 	}
 	return n;
}

void Jacobi(double **A,double *x,double *b,int dim,int &k,double tolerancia)
{ // La magnitud i presente en el 5º argumento es el contador, este se pasa por referencia para disponer de su valor en el main.
 double newx[dim];
 double oldx[dim];
//Primera aprox.
for(int i=0;i<dim;i++)
{
	oldx[i]=b[i]/A[i][i];
	newx[i]=oldx[i];
}
//Iniciamos el método iterativo
do{
	for(int i=0;i<dim;i++) {oldx[i]=newx[i];} //Asignamos a oldx el valor de newx etras el bucle anterior.
	for(int i=0;i<dim;i++)
	{	double sum=0;
		for(int j=0;j<dim;j++) //Cáclulamos el sumatorio.
		{
			if (i!=j) { sum= sum+(A[i][j]/A[i][i]*oldx[j]);}
		}
		newx[i]=(b[i]/A[i][i])-sum;
	}
	
	k++; //Una iteración más.	
} while(fabs(norm(newx,dim)-norm(oldx,dim))>tolerancia);
	
//Una vez fuera del bucle, la solución es newx, asignamos dichos valores al vector x	
for(int i=0;i<dim;i++)
 {
	x[i]=newx[i];
 }

}


void GaSe(double **A,double *x,double *b,int dim,int &k,double tolerancia)
{ // La magnitud i presente en el 5º argumento es el contador, este se pasa por referencia para disponer de su valor en el main.
 double newx[dim];
 double oldx[dim];
//Primera aprox.
for(int i=0;i<dim;i++)
{
	oldx[i]=b[i]/A[i][i];
	newx[i]=oldx[i];
}
//Iniciamos el método iterativo
do{
	for(int i=0;i<dim;i++) {oldx[i]=newx[i];} //Asignamos a oldx el valor de newx etras el bucle anterior.
	for(int i=0;i<dim;i++)
	{	double sum=0;
		for(int j=0;j<dim;j++) //Cáclulamos el sumatorio.
		{
			if (i!=j) { sum= sum+(A[i][j]/A[i][i]*newx[j]);}
		}
		newx[i]=(b[i]/A[i][i])-sum;
	}
	
	k++; //Una iteración más.	
} while(fabs(norm(newx,dim)-norm(oldx,dim))>tolerancia);
	
//Una vez fuera del bucle, la solución es newx, asignamos dichos valores al vector x	
for(int i=0;i<dim;i++)
 {
	x[i]=newx[i];
 }

}


void GaSeW(double **A,double *x,double *b,int dim,int &k,double tolerancia,double w)
{ // La magnitud i presente en el 5º argumento es el contador, este se pasa por referencia para disponer de su valor en el main.
 double newx[dim];
 double oldx[dim];
//Primera aprox.
for(int i=0;i<dim;i++)
{
	oldx[i]=b[i]/A[i][i];
	newx[i]=oldx[i];
}
//Iniciamos el método iterativo
do{
	for(int i=0;i<dim;i++) {oldx[i]=newx[i];} //Asignamos a oldx el valor de newx etras el bucle anterior.
	for(int i=0;i<dim;i++)
	{	double sum=0;
		for(int j=0;j<dim;j++) //Cáclulamos el sumatorio.
		{
		 sum= sum+(A[i][j]/A[i][i]*newx[j]);
		}
		newx[i]=oldx[i]+(w*((b[i]/A[i][i])-sum));;
	}
	
	k++; //Una iteración más.	
} while(fabs(norm(newx,dim)-norm(oldx,dim))>tolerancia);
	
//Una vez fuera del bucle, la solución es newx, asignamos dichos valores al vector x	
for(int i=0;i<dim;i++)
 {
	x[i]=newx[i];
 }

}

