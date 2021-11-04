#include <iostream>

using namespace std;

float operar(float x, float y, char op){
	float r = 0; 
	switch(op){
			case '+':
			r = x + y;
			break;
		case '-':
			r = x - y;
			break;
		case '*':
			r = x * y;
			break;
		case '/':
			r = x / y;
			break;
			
		default:
			cout << "operador no valido" << endl;
		
	}
}

int main () {
	float x; // el primero numero
	float y; // el segundo numero
	float r; // el resultado
	char op; // operador matematico a usar
	
	cout << "Calculadora sencilla " << endl;
	cout << "Numero 1: ";
	cin >> x;
	cout << "Numero 2: ";
	cin >> y;
	cout << "Operacion (+|-|*|/): ";
	cin >> op;
	
	r = operar ( x,y,op);
	
	cout << "x " << op << " y " << r << endl;
	
	return 0;
	

		 	 
}


