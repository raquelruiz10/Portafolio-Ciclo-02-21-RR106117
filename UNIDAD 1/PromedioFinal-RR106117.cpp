#include <iostream>
#include <string>

using namespace std;

void elpromedio(int x);

int main(){

cout<<" **** EL PROMEDIO DE NUMEROS QUE TU INGRESES: " << "\n";
cout<<"   *** Nombre: Raquel Alejandra Ruiz Rivas ----- Carnet: RR106117  **** : " << "\n";

int numeros; 

cout <<" Ingrese los numeros que desee para obtener promedio final :  "; cin >>numeros;
elpromedio(numeros);
}

void elpromedio(int numeros){
float totalpromedio;
int a,b;
	for(int i=0;i<numeros;i++){
	cout<<" Ingresar los numeros correspondientes: " << i << ": "<< "\n"; 
	cin >> b;
	a=a+b;
	}
totalpromedio = a/b;
std::cout<<" El promedio final es:  " << totalpromedio;
}

