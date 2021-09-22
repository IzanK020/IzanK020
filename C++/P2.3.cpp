// Ejercicio 3
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main ()
{
	int m;
	cout<< "Numero de datos a introducir: ";
	cin>> m ;
	cout <<endl<<"Datos cargados"<<endl;
	double data[m-1];
	ifstream datai;
	datai.open("Datos.dat");
	cout<< "Iniciando calculos..."<<endl;
	for(int i=0;i<=(m-1);i++) {
		datai >> data[i];
		cout<<data[i]<<endl;
	}
	
	
	//int comprobacion[10];
	//comprobacion=data>1;
	//data=data*comprobacion;
	//data=sqrt(data);
	
	ofstream datao;
	datao.open("Datos2.dat");

	for(int i=0;i<=(m-1);i++) {
		if (data[i]>1) {
			data[i]=sqrt(data[i]);
			cout<<data[i]<<endl;
			datao<< data[i] << endl;
		
		}
		
		
	}
	cout<< endl<< "Guardando archivos..."<<endl;
	cout<< "Archivos guardados..."<<endl;
	datai.close();
	datao.close();
	return 0;
}
