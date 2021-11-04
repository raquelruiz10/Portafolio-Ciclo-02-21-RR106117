#include<iostream>
 
using namespace std;
void mayor();
int main(void){
	cout<<" EJERCICIO DEL NUMERO MAYOR " << "\n";
    cout<<" Nombre:Raquel Alejandra Ruiz Rivas      ........ Carnet: RR106117 ....." << "\n";
    cout<<" Ingresa 8 numeros y conoceras el mayor: " << "\n"; 
 	mayor();
}
void mayor(){
	int IngresoNumeros=8, Numero,Mayor=0;
	
	for(int i=0;i<IngresoNumeros;i++){
		cout<< "Ingrese el numero " << i+1 << " :";
		cin>>Numero;
		if(Numero > Mayor){
			Mayor = Numero;
		}
	}
	std::cout<<"EL NUMERO MAYOR ES ------- ****: " << Mayor;
	
	 
    }


