// Ejercicio 1
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI =3.1415926535897932; //Defino una constante.	

int main ()
{
float sums1=0;
double sumd1=0;
float sums2=0;
double sumd2=0;
float sums3=0;
double sumd3=0;
float sums4=0;
double sumd4=0;
int i;
int i2;
double v_real=PI*PI/6;
for (int n=1; n<=10000; n++) {   //Aqui le he dicho for i=[1:1:10^4]     
        //(defino i y su valor inicial, defino hasta donde va i, defino el paso de cambio de i)
    i=n;
	float s=(1/(float(i)*float(i)));
    sums1+=s;
    double d=1/(pow(i,2));
	sumd1+=d;   
}
for (int n=10000; n>=1; n--) {   //Aqui le he dicho for i=[1:1:10^4]     
        //(defino i y su valor inicial, defino hasta donde va i, defino el paso de cambio de i)
    int i3=n;
	float s3=(1/(pow(i3,2)));
    sums2+=s3;
    double d3=1/(pow(i3,2));
	sumd2+=d3;   
}
for (int n=1; n<=10000000; n++) {   //Aqui le he dicho for i=[1:1:10^4]     
        //(defino i y su valor inicial, defino hasta donde va i, defino el paso de cambio de i)
    i2=n;
    
	float s2=(1/(pow(i2,2)));
    sums3+=s2;
    double d2=1/(pow(i2,2));
	sumd3+=d2;   
}
for ( int n=1000000; n>=1; n--) {   //Aqui le he dicho for i=[1:1:10^4]     
        //(defino i y su valor inicial, defino hasta donde va i, defino el paso de cambio de i)
    int i4=n;
    
	float s4=(1/(pow(i4,2)));
    sums4+=s4;
    double d4=1/(pow(i4,2));
	sumd4+=d4;   
}
float j=1/2;

cout << j<< endl;
cout << i <<" iteraciones"<<endl;
cout << "Precision simple(1) " << setprecision(8) <<sums1 <<endl;
cout << "Precision doble(1) "  << setprecision(17) <<sumd1 <<endl;
cout << "Precision simple(2) " << setprecision(8) << sums2 <<endl;
cout << "Precision doble(2) "  << setprecision(17) <<sumd2 <<endl;
cout << i2<<" iteraciones" <<endl;
cout << "Precision simple(1) " << setprecision(8) <<sums3 <<endl;
cout << "Precision doble(1) "  << setprecision(17) <<sumd3 <<endl;
cout << "Precision simple(2) " << setprecision(8) <<sums4 <<endl;
cout << "Precision doble(2) "  << setprecision(17) <<sumd4 <<endl;
cout << "Valor real " << setprecision(17) << v_real << endl;
// terminamos el programa
return 0;
}

