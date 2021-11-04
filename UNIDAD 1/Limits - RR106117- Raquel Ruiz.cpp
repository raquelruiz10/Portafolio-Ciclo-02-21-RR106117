#include <iostream>
#include <limits>

using namespace std;

int main(){
	
	double dmin = numeric_limits<double>::min(); // valor minimo que puede tener un integer
	double dmax = numeric_limits<double>::max(); // Valor maximo posible que puede tener un Integer
	
	cout << "dmin = " << dmin << endl;
	cout << "dmax = " << dmax << "\n";
	cout << "tamanio de double : " << sizeof(double) << endl;
	
	long lmin = std::numeric_limits<long>::min();
	long lmax = std::numeric_limits<long>::max();
	
	cout << "lmin = " << lmin << endl;
	cout << "lmax = " << lmax << "\n";
	cout << "tamanio de long : " << sizeof(long) << endl;
	
	string smin = numeric_limits<string>::min();
	string smax = numeric_limits<string>::max();
	
	cout << "smin = hola " << smin << endl;
	cout << "smax = hola " << smax << "\n";
	cout << "tamanio de string : " << sizeof(string) << endl;
	
    bool bmin = std::numeric_limits<bool>::min();
	bool bmax = std::numeric_limits<bool>::max();
	
	cout << "bmin = " << bmin << endl;
	cout << "bmax = " << bmax << "\n";
	cout << "tamanio de bool : " << sizeof(bool) << endl;
	
	return 0;
	
	
}
