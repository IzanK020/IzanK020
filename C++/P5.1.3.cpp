//Problema 1c

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
void multiplication(int **A,int m,int n,int **B,int m2,int n2,int **C);
void fill(int **A,int fa,int ca);
void print(int **A,int m, int n);

int main ()
{
	int **A;
    int fa, ca;
    cout<<endl<<"Introduzca la dimension de la matriz A."<<endl;
    cout<<"Filas:";
    cin>> fa;
    cout<<"Columnas:";
    cin>> ca;
    cout<<" "<<endl;
//  Reserva dinamica de memoria. 
//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
    A = new int * [fa]; // Primera etapa.
//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
    for(int i = 0; i < fa; i++)
    {
            A[i] = new int[ca]; // Segunda etapa.
    }
	cout<<"Introduzca los valores que se pidan de la matriz A."<<endl;
	fill(A,fa,ca);
	int **B;
    int fb, cb;
    cout<<endl<<"Introduzca la dimension de la matriz B."<<endl;
    cout<<"Filas:";
    cin>> fb;
    cout<<"Columnas:";
    cin>> cb;
    cout<<" "<<endl;
//  Reserva dinamica de memoria. 
//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
    B = new int * [fb]; // Primera etapa.
//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
    for(int i = 0; i < fb; i++)
    {
            B[i] = new int[cb]; // Segunda etapa.
    }
	cout<<"Introduzca los valores que se pidan de la matriz B."<<endl;
	fill(B,fb,cb);
	
	int **C;
	if (ca != fb) 
	{ 	cout<<"El producto de matrices no es posible."<<endl;
		cout<<" Columnas de A: "<<ca<<endl;
		cout<<" Filas de B: "<<fb<<endl;
		if (ca==cb)
		{cout<<"Si se transpone B,el producto se puede realizar, revise los datos y vuelva a intentar";
		}
	
	}
    int fc=fa, cc=cb;
//  Reserva dinamica de memoria. 
//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
    C = new int * [fc]; // Primera etapa.
//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
    for(int i = 0; i < fc; i++)
    {
            C[i] = new int[cc]; // Segunda etapa.
    }
	multiplication(A,fa,ca,B,fb,cb,C);
	if (ca != fb) { return 0;}
	cout<<"La matriz C=A*B es la siguiente:";
	print(C,fc,cc);
	
	
	 for (int i = 0; i < fa; i++)
    {
       delete [] A[i];
    }
    delete [] A;
    
	for (int i = 0; i < fb; i++)
    {
       delete [] B[i];
    }
    delete [] B;
    for (int i = 0; i < fc; i++)
    {
       delete [] C[i];
    }
    delete [] C;
	return 0;
}

void multiplication(int **A,int m,int n,int **B,int m2,int n2,int **C)
{  

	if (n != m2) { cout<< "la multiplicacion de estas matrices no es válida"<<endl;}
	for(int i=0;i<m;i++) {
		for(int j=0;j<n2;j++) {
				C[i][j]=0;
			for (int k=0;k<n;k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
}

void fill(int **A,int fa,int ca)
{
	//Rellenamos la matriz
	
	for (int i=0;i<fa;i++)
	{	cout<<"Introducimos fila "<<i+1<<endl;
		for (int j=0;j<ca;j++)
		{
			cin>>A[i][j];	
		}
	}
}
void print(int **A,int m, int n)
{	cout<<" "<<endl;

	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
		cout<< A[i][j]<<"  ";		
	}
	cout<<" "<<endl;
}
}

