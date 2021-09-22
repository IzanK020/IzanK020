// Ejercicio 2
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
void print(int **A,int m, int n);
void transpuesta(int **A,int m,int n);
int main ()
{
 int **A;
    int fa=3, ca=3;

//  Reserva dinamica de memoria. 
//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
    A = new int * [fa]; // Primera etapa.
    

//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
    for(int i = 0; i < fa; i++)
    {
            A[i] = new int[ca]; // Segunda etapa.
    }

	// Rellenamos la matriz

               A[0][0] =2;A[0][1] =3;A[0][2] =8;
			   A[1][0] =2;A[1][1] =2;A[1][2] =4;
				A[2][0] =2;A[2][1] =2;A[2][2] =6;	
	
cout<<"Matriz A antes de la transposicion:"<<endl;
print(A,3,3);


transpuesta(A,3,3);

cout << "Matriz A despues de la transposicion: "<<endl;
print(A,3,3);
	return 0;
}

void print(int **A,int m, int n)
{	

for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
		cout<< A[i][j]<<"  ";		
	}
	cout<<" "<<endl;
}
}


void transpuesta(int **A,int m,int n)
{  
	if (n != m) { cout<< "No es una matriz cuadrada. Proceso abortado"<<endl;return;}
	
	for(int i=0;i<m;i++) {
		for(int j=i;j<n;j++) {
			if (i==j)
			{
			}
			else 
			{	int c,d;
				c=A[i][j];
				d=A[j][i];
				A[j][i]=c;
				A[i][j]=d;
			}
		}
	}
	
}

