// Ejercicio 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
//void print(double matriz[][],int m, int n);

void print(int **A,int m, int n);
void multiplication(int **A,int m,int n,int **B,int m2,int n2,int **C);

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

    int **B;
    int fb=3, cb=2;

//  Reserva dinamica de memoria. 
//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
    B = new int * [fb]; // Primera etapa.
    

//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
    for(int i = 0; i < fb; i++)
    {
            B[i] = new int[cb]; // Segunda etapa.
    }
   
	// Rellenamos la matriz

               B[0][0] =4;B[0][1] =6;
			   B[1][0] =3;B[1][1] =9;
				B[2][0] =1;B[2][1] =8;
				
				int **C;
    int fc=fa, cc=cb;

//  Reserva dinamica de memoria. 
//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
    C = new int * [fc]; // Primera etapa.
//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
    for(int i = 0; i < fc; i++)
    {
            C[i] = new int[cc]; // Segunda etapa.
    }







cout<< "Matriz A:"<<endl;
	print(A,3,3);
cout<< "Matriz B:"<<endl;
	print(B,3,2);
cout<< "Matriz C=A*B:"<<endl;
	multiplication(A,3,3,B,3,2,C);	
		print(C,fc,cc);
	
	
	// Y finalmente, se libera la memoria ocupada por A en dos etapas.
   for (int i = 0; i < fa; i++)
   {
       delete [] A[i];
   }
   delete [] A;
      for (int i = 0; i < fb; i++)
   {
       delete [] B[i];
   }
   delete [] C;
         for (int i = 0; i < fc; i++)
   {
       delete [] C[i];
   }
   delete [] C;
   
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








