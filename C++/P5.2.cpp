//Problema 2
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;
void print(int *A,int m);

int main ()
{

	int n=6;
	int *A;
	A = new int [n];
	

  
	for (int i=0;i<n;i++)
	{	*(A+i)=i*i+3;
		}
	print(A,n);
	
	return 0;
}

void print(int *A,int m)
{	cout<<" "<<endl;
	for(int i=0;i<m;i++) 
	{
	cout<< *(A+i)<<"  ";		
	}
}
