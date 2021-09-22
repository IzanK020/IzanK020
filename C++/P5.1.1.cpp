// Ejercicio 1a,1b
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main ()
{	cout<<"Programa que crea unos arrays dinamicos, uno unidimensional y otro bidimensional."<<endl;
	cout<<"Introduzca la dimension del array unidimensional:";
	int n;
	cin>>n;
	//Reserva dinámica de memoria
	int *B;
	B = new int [n];
	//Rellenamos el vector
	cout<<"Introduzca ahora los valores del vector:"<<endl;
		for (int i=0;i<n;i++)
		{
			cin>>B[i];		
		}
		
		
		
		
	int **A;
    int fa, ca;
    cout<<endl<<"Introduzca la dimension del array bidimensional."<<endl;
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
	//Rellenamos la matriz
	for (int i=0;i<fa;i++)
	{	cout<<"Introducimos fila "<<i+1<<endl;
		for (int j=0;j<ca;j++)
		{
			cin>>A[i][j];	
		}
	}
	
	
	
	
	
	//Liberamos memoria
	 for (int i = 0; i < fa; i++)
    {
       delete [] A[i];
    }
    delete [] A;
	delete [] B;
	return 0;
}
