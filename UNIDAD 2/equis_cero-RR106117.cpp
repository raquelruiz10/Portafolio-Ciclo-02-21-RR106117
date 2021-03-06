#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

//RAQUEL ALEJANDRA RUIZ RIVAS -RR106117

using namespace std;

const int LADO = 3;

//Prototipos de funciones
void imprimirTablero(char tablero[] [LADO]);
int marcarCasillaJugador(char Tablero[] [LADO]);
int leerNumero(string indicacion, string mensajeError , int min, int max);
int marcarCasillaComputadora( char tablero [] [LADO]);
char ganadorFilas(char tablero[] [LADO]);
char ganadorColumnas (char tablero [] [LADO]);
char ganadorDiagonales (char tablero [] [LADO]);
char determinarGanador (char tablero [] [LADO]);
void jugar();



int main() {
    char jugarDeNuevo;
    srand(time(0)); // Inicializa la semilla de los numeros aleatorios
    do{
     jugar ();
     cout << "Desea jugar de nuevo ---- SI O NO ?  " ;
     cin >> jugarDeNuevo;
     cout << endl;
   } while (toupper(jugarDeNuevo) == 'SI' );
   
    return 0;
}

void jugar() {
        char tablero[LADO][LADO] = {};
        char ganador = 0;
        
        cout << " nombre : raquel alejandra ruiz rivas --- rr106117" << endl;

        cout << "Juego de equis-cero" << endl;
        int casillasLibres = LADO * LADO;
        bool turnoJugador = true;
        imprimirTablero(tablero);
        
    while (casillasLibres > 0 && ganador == 0) {
        if  (turnoJugador) {
            casillasLibres -= marcarCasillaJugador(tablero);
        } else {
              casillasLibres -= marcarCasillaComputadora(tablero);
        }
        turnoJugador = !turnoJugador; // Turno del otro jugador
        ganador = determinarGanador(tablero);
   }
    switch (ganador) {
            case 'x':
               cout << "Usted gana !!! " << endl;
               break;
            case '0':
               cout << "La computadora gana 9 " << endl;
               break;
            default:
               cout << "Empate." << endl;               
    }
} 

void imprimirTablero (char tablero[][LADO])  {
     //Cuente los espacios usando los puntos
     // Guia: *******
    cout << "\n     0   1   2\n    ----" << endl;
    for (int fila = 0; fila < LADO; fila++) {
       cout << " " << fila << "|";
       for (int columna = 0; columna < LADO; columna++) {
          cout << " " << tablero[fila] [columna] << "|";
       }
       //Guia : ???..
       cout << "\n     ------------ " << endl;
   }
   cout << endl;    
}

int leerNumero(string indicacion,string mensajeError,int min,int max) {
   int numero;
   cout << indicacion << " : " ;
   
   // Valida que la entrada sea un entero
  while (!(cin >> numero) || (numero < min || numero >= max)) {
        cin.clear(); // limpia la entrada est?ndar
        cin.ignore(10000, '\n'); //descarta la entrada hasta encontrar un salto de l?nea
        cout << indicacion << " : " ; // le da otra oportunidad al usuario
   }
   
  return numero;
}

int marcarCasillaJugador(char tablero[][LADO]) {
   int fila,columna;
   cout << "Jugador:" << endl;
   string mensaje = "Ingrese un valor entre 0 y" ;
   fila = leerNumero("Fila", mensaje, 0 , LADO);
   columna = leerNumero("Columna", mensaje, 0 , LADO);
   while (tablero[fila][columna] != 0) {
        cout << "Casilla ocupada.  Intente de nuevo " << endl;
        fila = leerNumero( "Fila" , mensaje, 0, LADO);
        columna = leerNumero( "Columna" , mensaje, 0, LADO);
   }
   tablero[fila][columna] = 'x' ;
   imprimirTablero(tablero);
   return 1;
}

int marcarCasillaComputadora( char tablero [] [LADO]) {
    int fila, columna;
    fila = rand() % LADO;
    columna = rand() % LADO;
    while (tablero[fila][columna] != 0) {
       fila = rand() % LADO;
       columna = rand() % LADO; 
    }
    tablero[fila][columna] = '0' ;
    cout << "Computadora:" << endl;
    imprimirTablero(tablero);
    return 1;
    
    }
    
 char determinarGanador(char tablero[][LADO]){
 	 char ganador;
 	 
 	 // Ganador por filas
 	 ganador = ganadorFilas(tablero);
 	 
 	 //Ganador por columnas
 	 if (ganador == 0)
     ganador = ganadorColumnas(tablero);
     
     //Ganador por diagonales
      if (ganador == 0)
      ganador = ganadorDiagonales(tablero);
      
      return ganador;
    
 }
 
 char ganadorFilas(char tablero[][LADO]){
 	for (int fila = 0; fila < LADO;fila++){
 		//primer caracter de la fila
 		char caracter = tablero[fila][0];
 		int veces = 0;
 		if (caracter != 0){
 			//contar cuantas veces aparece el caracter en la fila
 			for (int columna = 0; columna < LADO; columna++){ 				
 				if (tablero[fila][columna] == caracter) {
 					veces++;
				}
			}
			 if (veces == LADO){
			 	return caracter;
			   }
	    } 
   }
	return 0;
 	
 }
 
 char ganadorColumnas (char tablero[][LADO]){
 	for (int columna = 0; columna < LADO; columna++){
 		//primer caracter de la columna
 		char caracter = tablero [0][columna];
 		int veces = 0;
 		if (caracter !=0){
 			//contar cuantas veces aparece el caracter en la columna
 		    for (int fila =0; fila < LADO; fila++){
 		    	if (tablero[fila][columna] == caracter){
 		    		veces++;
				 }
			 }
			 if (veces == LADO){
			 	return caracter;
			 }
		 }
	 }
	 return 0;
 }
 
char ganadorDiagonales (char tablero [][LADO]){
	char caracter;
	int veces;
	
	//Diagonal de izquiera a derecha
	caracter = tablero[0][0];
	veces = 0;
	if (caracter !=0){
		for (int i = 0; i < LADO; i++ )
		    if (tablero[i][i] == caracter)
		        veces++;
		if (veces == LADO)
		    return caracter;
	}
	
	//Diagonal de derecha a izquierda
	caracter = tablero[0] [LADO -1];
	veces = 0;
	if (caracter !=0){
		for (int i = 0; i < LADO; i++ )
		    if (tablero[i][i] == caracter)
		        veces++;
		if (veces == LADO)
		    return caracter;
	}
			
			
			
}
 

