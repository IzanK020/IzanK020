//Problema 1
// Ejercicio 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
void Dnum(double **A,int n);
void D2num(double **A,int n);
double velocidad(double t);
double aceleracion(double t);



int main ()
{
int n=500;
int m=4;
//Reservamos memoria.
	
double **A;
double **B;
double **C;
//  Reserva dinamica de memoria. 
//  Primera etapa: Se reserva memoria para el array de punteros que apuntan a las filas de A.
// Primera etapa.
A = new double * [n];
B = new double * [n];
C = new double * [n];
//  Segunda etapa: Se reserva memoria para cada uno de los ca elementos que forman cada una de las filas fa de la matriz A.
for(int i = 0; i < n; i++){
A[i] = new double [m]; // Segunda etapa.
B[i] = new double [m];
C[i] = new double [m];

}

 //Rellenamos matriz A	
 // Crear un flujo de entrada y llamarlo fentrada	
 ifstream fentrada("distancia.dat", ios::in);
//Tambien se puede hacer 

for (int i=0; i<n; i++){
	for (int j=0; j<2; j++){
	fentrada >> A[i][j];
	C[i][j]=A[i][j];
	}
	B[i][0]=A[i][0];
}
fentrada.close(); // cerrar el archivo
	
	Dnum(A,n);
	
ofstream fsalida("velocidad.dat",ios::out);	
fsalida <<"%Tiempo(s)"<<setw(30)<<"Velocidad(m/s) O(h^2)"<<setw(30)<<"Error cometido"<<setw(30)<<"Velocidad(m/s) O(h^4)"<<setw(30)<<"Error cometido"<<setw(30)<<"Velocidad analítica(m/s)"<<endl;

double v;
for (int i=0; i<n; i++){
	v=velocidad(A[i][0]);
	 fsalida << A[i][0]<<setw(30)<<A[i][2]<<setw(30)<<(A[i][2]-v)<<setw(30)<<A[i][3]<<setw(30)<<(A[i][3]-v)<<setw(30)<<v<<endl;
	B[i][1]=A[i][2];
}
	fsalida.close();
	
	Dnum(B,n);
	
ofstream fsalida2("aceleracion.dat",ios::out);	
fsalida2 <<"%Tiempo(s)"<<setw(30)<<"Aceleracion(m/s^2) O(h^2)"<<setw(30)<<"Error cometido"<<setw(30)<<"Aceleracion(m/s^2) O(h^4)"<<setw(30)<<"Error cometido"<<setw(30)<<"Aceleracion analítica(m/s^2)"<<endl;

double a;
for (int i=0; i<n; i++){
	a=aceleracion(B[i][0]);
	  fsalida2 << B[i][0]<<setw(30)<<B[i][2]<<setw(30)<<(B[i][2]-a)<<setw(30)<<B[i][3]<<setw(30)<<(B[i][3]-a)<<setw(30)<<a<<endl;
	
}
	fsalida2.close();

	D2num(C,n);
	
ofstream fsalida3("aceleracion2.dat",ios::out);	
fsalida3 <<"%Tiempo(s)"<<setw(15)<<"Aceleracion(s) O(h^4)"<<endl;

	
for (int i=0; i<n; i++){
	 fsalida3 << C[i][0]<<setw(15)<<C[i][3]<<endl;
}
	fsalida3.close();

//Liberamos memoria
for (int i = 0; i < n; i++){
	 delete [] A[i];
	 delete [] B[i];
	 delete [] C[i];
}

delete [] A;
delete [] B;
delete [] C;
return 0;}

double velocidad(double t){return(7.0-(7.0*exp(-t/10.0)));}
double aceleracion(double t){return((0.7*exp(-t/10.0)));}




void Dnum(double **A,int n){
//	if (k==0){
	
	double h=A[1][0]-A[0][0];
	A[0][2]=(-A[2][1]+4*A[1][1]-3*A[0][1])/(2*h);   //Fordward O(h^2)
	A[n-1][2]=(3*A[n-1][1]-4*A[n-2][1]+A[n-3][1])/(2*h); //Backward O(h^2)
	for (int i=1;i<(n-1);i++){	
		A[i][2]=(A[i+1][1]-A[i-1][1])/(2.0*h); //Centered O(h^2)
	}
	
//	}	
	
//	if (k==1){
	
	
	A[0][3]=(-3*A[4][1]+16*A[3][1]-36*A[2][1]+48*A[1][1]-25*A[0][1])/(12*h);   //Fordward O(h^4)
	A[1][3]=(-3*A[5][1]+16*A[4][1]-36*A[3][1]+48*A[2][1]-25*A[1][1])/(12*h); 
	A[n-2][3]=-(-3*A[n-6][1]+16*A[n-5][1]-36*A[n-4][1]+48*A[n-3][1]-25*A[n-2][1])/(12*h); 	//Backward O(h^4)
	A[n-1][3]=-(-3*A[n-5][1]+16*A[n-4][1]-36*A[n-3][1]+48*A[n-2][1]-25*A[n-1][1])/(12*h); 
	for (int i=2;i<(n-2);i++){	
		A[i][3]=(A[i-2][1]-8*A[i-1][1]+8*A[i+1][1]-A[i+2][1])/(12.0*h); //Centered O(h^4)
	}
	
//	}
	
	
}



void D2num(double **A,int n){
/*	if (k==0){
	
	double h=A[1][0]-A[0][0];
	A[0][2]=(-A[2][1]+4*A[1][1]-3*A[0][1])/(h);   //Fordward O(h^2)
	A[n-1][2]=(3*A[n-1][1]-4*A[n-2][1]+A[n-3][1])/(h); //Backward O(h^2)
	for (int i=1;i<(n-1);i++){	
		A[i][2]=(A[i+1][1]-A[i-1][1])/(h); //Centered O(h^2)
	}
	
//	}	
	
	if (k==1){*/
	
	double h=A[1][0]-A[0][0];
	A[0][3]=((-(5.0/6.0)*A[5][1])+((61.0/12.0)*A[4][1])-(13.0)*A[3][1]+(107.0/6.0)*A[2][1]-(77.0/6.0)*A[1][1]+(15.0/4.0)*A[0][1])/(h*h);   //Forward O(h^4)
	A[1][3]=(-(5.0/6.0)*A[6][1]+((61.0/12.0)*A[5][1])-(13.0)*A[4][1]+(107.0/6.0)*A[3][1]-(77.0/6.0)*A[2][1]+(15.0/4.0)*A[1][1])/(h*h);
	A[n-2][3]=(-(5.0/6.0)*A[n-7][1]+(61.0/12.0)*A[n-6][1]-(13.0)*A[n-5][1]+(107.0/6.0)*A[n-4][1]-(77.0/6.0)*A[n-3][1]+(15.0/4.0)*A[n-2][1])/(h*h); 	//Backward O(h^4)
	A[n-1][3]=(-(5.0/6.0)*A[n-6][1]+(61.0/12.0)*A[n-5][1]-(13.0)*A[n-4][1]+(107.0/6.0)*A[n-3][1]-(77.0/6.0)*A[n-2][1]+(15.0/4.0)*A[n-1][1])/(h*h);
	for (int i=2;i<(n-2);i++){	
		A[i][3]=(-(1.0/12.0)*A[i-2][1]+((4.0/3.0)*A[i-1][1])-((5.0/2.0)*A[i][1])+((4.0/3.0)*A[i+1][1])-((1.0/12.0)*A[i+2][1]))/(h*h); //Centered O(h^4)
	}
	
//	}
	
	
}




