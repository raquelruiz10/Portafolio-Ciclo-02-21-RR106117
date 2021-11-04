#include <iostream>
#include <string>
 
using namespace std;

 void VerificarTriangulo(int x, int y, int z){
 	if (x == y || x == z ){
 	 cout << "Es un triangulo Equilatero" << endl;
	 }else if(x == y || x == z || y == z){
	 	 
	 	 std::cout << "Es un triangulo Isoceles" << endl;
	 }
    else{
    	 std::cout << "Es un triangulo Escaleno" << endl;
	}
 }
 
 void area(int x, int y, int z){
 	double Area;
 	
 	Area = (x+y)/z;
 	
 	 std::cout << "El area es: " << Area << endl;;
 	
 }
 int main()
{
	
    int LadoA, LadoB, LadoC;
    
    cout << " TIPO DE TRIANGULO ..... NOMBRE: RAQUEL ALEJANDRA RUIZ RIVAS --RR106117 ";
 
    cout << " Ingrese el Primer lado: "; cin >> LadoA;
    cout << "Segundo lado: "; cin >> LadoB;
    cout << "Tercer lado: "; cin >> LadoC;
    
   VerificarTriangulo(LadoA,LadoB,LadoC);
   area(LadoA,LadoB,LadoC);
}

    
