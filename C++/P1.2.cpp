// Ejercicio 2
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
	

int main ()
{
	for (int i=0; i<=9; i++) {   //Aqui le he dicho for i=[1:1:10^4]     
        //(defino i y su valor inicial, defino hasta donde va i, defino el paso de cambio de i)
    	for (int j=0; j<=9; j++) {   //Aqui le he dicho for i=[1:1:10^4]     
        //(defino i y su valor inicial, defino hasta donde va i, defino el paso de cambio de i)
    		for (int k=0; k<=9; k++) {   //Aqui le he dicho for i=[1:1:10^4]     
        	//(defino i y su valor inicial, defino hasta donde va i, defino el paso de cambio de i)
            int a=(i*100)+(j*10)+k;
            int b=pow(i,3)+pow(j,3)+pow(k,3);
            
            	if (a==b)
             		{ cout <<a <<endl;
					 }
			}	
		}
	
	}
	;
	return 0;
}
