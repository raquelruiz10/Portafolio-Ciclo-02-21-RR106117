 #include <iostream>

using namespace std;

int main(){
	
	// Declaración de variables en C++
	
	//Estilo C
	int a = 10;
	double nuestroNumero = 564.4992;
	auto d = a;
	int f = 0;
	decltype(f) g;
	
	//Inicialización de constructor
	double b(54);
	
	//Inicialización uniforme
	double c {15.136};
	
	//Imprimir resultados
	
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << f << endl;
	cout << g << endl;
	
	//Proceso 
	c = a + nuestroNumero;
	cout << c << endl;
	c = b + nuestroNumero;
	cout << c << endl;
	
	// Termina el programa exitosamente 
	return 0;
	
}
