#include <iostream>
#include <string>
#include <fstream>
#include <array>

using namespace std;

bool buscarEnArchivo(string archive, string valorBuscado){
   bool encontrado = false;
   string linea;
   ifstream miArchivo(archivo);
   if(miArchivo.is_open()){
    while(getline(miArchivo,linea)){
        if(valorBuscador == linea){
          encontrado = true;
          break;
       }
    }
    miArchivo.close();
  } else {
     cout << "No se pudo abrir el archivo.";
  }
return encontrado;
}
int main(int num_args, char** arg_strings){
  string document = arg_strings[1];
  string valorAbuscar =arg_strings[2];
  if(buscarEnArchivo(documento, valorAbuscar)){
    cout << valorAbuscar << "esta en el arreglo" << endl;
  } else {
     cout << valorAbuscar << "no esta en el arreglo" << endl;
  }
  return 0;
}

