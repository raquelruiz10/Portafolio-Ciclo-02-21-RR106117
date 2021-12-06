#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <iterator>

#include "digrafo.h"
#include "rutaBFS.h"

using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::stoi;
using std::endl;
using std::istringstream;
using std::vector;
using std::map;
using std::pair;
using std::list;
using std::iterator;

//RAQUEL ALEJANDRA RUIZ RIVAS -RR106117
map<string, int> codigoCiudades;
vector<string> ciudades;

Digrafo rutas;

void procesarArchivoCiudades(string nombreArchivo) {
	cout << "Abriendo archivo de ciudades: " << nombreArchivo << "..." << endl;
	ifstream archivo(nombreArchivo);
	string ciudad;
	
	if (!archivo.is_open()) {
		cout << "No se pudo abrir el archivo de ciudades.\n";
		return;
	}
	
	cout << "\nProcesando archivo de ciudades..." << endl;
	
	vector<string> fila;
	int numeroVertices = 0;
	while(getline(archivo, ciudad)) {
		codigoCiudades.insert(pair<string, int>(ciudad, numeroVertices++));
		ciudades.push_back(ciudad);
		cout << "Se agrego la ciudad " << ciudad << endl;
	}
	
	cout << "Cerrando archivo ciudades " << nombreArchivo << "..." << endl;
	archivo.close();
	
	cout << endl;
}

void procesarArchivoVuelos(string nombreArchivo) {
	cout << "Abriendo archivo de vuelos " << nombreArchivo << "..." << endl;
	ifstream archivo(nombreArchivo);
	string linea, token;
	string origen, destino;
	
	if (!archivo.is_open()) {
		cout << "No se pudo abrir el archivo de vuelos.\n";
		return;
	}
	
	cout << "\nProcesando archivo vuelos..." << endl;
	
	rutas.setVertices(ciudades.size());
	
	vector<string> fila;
	while(getline(archivo, linea)) {
		fila.clear();
		istringstream ss(linea);
		while(getline(ss, token, ',')) {
			fila.push_back(token);
		}
		
		origen = fila[0];
		destino = fila[1];
		rutas.agregarArista(codigoCiudades[origen], codigoCiudades[destino]);
		cout << "Se agrego el vuelo " << origen << " -> " << destino << endl;
	}
	
	cout << "Cerrando archivo de vuelos " << nombreArchivo << "..." << endl;
	archivo.close();
	
	cout << endl;
	
	cout << "Se creo el siguiente grafo: " << endl;
	
	rutas.imprimir();
	
	cout << endl;
}


void procesarSolicitudVuelo() {
	string ciudadOrigen, ciudadDestino;
	
	cout << "Ciudad origen: ";
	getline(cin, ciudadOrigen);
	
	if (codigoCiudades.count(ciudadOrigen) == 0) {
		cout << "Lo siento, no volamos desde esa ciudad." << endl;
		return;
	}
	
	cout << "Ciudad destino: ";
	getline(cin, ciudadDestino);
	
	if (codigoCiudades.count(ciudadDestino) == 0) {
		cout << "Lo siento, no volamos hacia esa ciudad." << endl;
		return;
	}
	
	RutaBFS itinerario(rutas, codigoCiudades[ciudadOrigen]);
	
	if (!itinerario.existeCaminoHacia(codigoCiudades[ciudadDestino])) {
		cout << "No se pudo encontrar un itinerario de vuelo." << endl;
	} else {
		cout << "Itinerario sugerido: " << endl;
		list<int>::iterator it;
		list<int> conexiones = itinerario.getRutaHacia(codigoCiudades[ciudadDestino]);
		for (it = conexiones.begin(); it != conexiones.end(); it++) {
			int codigo = *it;
			if (codigo == codigoCiudades[ciudadDestino]){
				cout << ciudadDestino << endl;
			} else {
				cout << ciudades[codigo] << " -> ";
			}
		}
	}
}

int mostrarMenu() {
	string eleccion;
	cout << "\nMenu principal" << endl;
	cout << "1- Buscar un vuelo" << endl;
	cout << "2- Salir" << endl;
	cout << "Su eleccion: ";
	getline(cin, eleccion);
	cout << endl;
	return stoi(eleccion);
}

int main() {
	procesarArchivoCiudades("ciudades.txt");
	procesarArchivoVuelos("vuelos.txt");
	
	int opcion = mostrarMenu();
	
	while (opcion != 2) {
		procesarSolicitudVuelo();
		opcion = mostrarMenu();
	}
	
	return 0;
}
