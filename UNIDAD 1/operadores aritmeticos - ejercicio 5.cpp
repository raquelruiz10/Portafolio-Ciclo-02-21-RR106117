#include <iostream>
using namespace std;

int main(){
	
	double x;
	double y;
	
	cout << " *** Calcula operaciones aritmeticas de dos numeros *** \n";
	
	cout << " Inserte un numero:";
	cin >> x;
	
	cout << " Inserte el otro numero: ";
	cin >> y;
	
	cout << "Suma: " << x + y << endl;     // suma de x + y
	cout << "Resta: " << x - y << endl;     // suma de x - y
	cout << "Multiplicaci�n: " << x * y << endl;     // suma de x * y
	cout << "Divisi�n: " << x / y << endl;     // suma de x / y
		
	int z = x;
	int w = y;
	cout << "Residuo de diivisi�n: " << z % w << endl;  //residuo de dividir x % y
	
	--x;
	--y;
	cout << "Decremento en uno: " << "x: " << x <<  "y: " << y << endl;
	
	return 0;
	
}
