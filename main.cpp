#include "Diccionario.h"
#include <iostream>
#include <string>
using namespace std;
/**************************************************************************************************************************************FUNCIONES**DECLARACION*************************************************************************************************************************************/
int calcularPuntaje(string palabra, Diccionario diccionario,
                    Diccionario diccionarioInverso);
bool valido(string palabra);
string minusculas(string palabra);
void menu(string comando, Diccionario &diccionario,
          Diccionario &diccionarioInverso);
/***************************************************************************************************************************************************MAIN******************************************************************************************************************************************/
int main() {
  Diccionario diccionario, diccionarioInverso;
  string comando;
  do {
    cout << endl;
    cout << "'ayuda' para ver comandos " << endl;
    cout << "'ayuda comando' para ver como poner cada comando " << endl;
    cout << "$ ";
    getline(cin, comando);
    menu(comando, diccionario, diccionarioInverso);

  } while (comando != "salir");
}
/*******************************************************************************************************************************************FUNCIONES*********************************************************************************************************************************************/
// calcula el puntaje de una palabra
int calcularPuntaje(string palabra, Diccionario diccionario,
                    Diccionario diccionarioInverso) {
  int puntaje = 0;
  if (!diccionario.esta(palabra)) {
    if (!diccionarioInverso.esta(palabra)) {
      return 0;
    } else {
      for (int i = 0; i < palabra.size(); i++) {
        puntaje = puntaje + diccionarioInverso.puntaje(palabra[i]);
      }
    }
  } else {
    for (int i = 0; i < palabra.size(); i++) {
      puntaje = puntaje + diccionario.puntaje(palabra[i]);
    }
  }
  return puntaje;
}
// pone los textos en minusculas
string minusculas(string palabra) {
  string aux;
  for (char c : palabra) {
    c = tolower(c);
    aux = aux + c;
  }
  return aux;
}
// muestra el menu
void menu(string comando, Diccionario &diccionario,
          Diccionario &diccionarioInverso) {
  int parte = 0;
  string aux, parametros;
  for (int i = 0; i < comando.size(); i++) {
    if (comando[i] == ' ') {
      parte = 1;
      break;
    }
    aux = aux + comando[i];
  }
  if (parte == 1) {
    for (int i = aux.size() + 1; i < comando.size(); i++) {
      parametros = parametros + comando[i];
    }
  }
  if (aux == "inicializar") {
    if (diccionario.lleno()) {
      cout << endl << "El diccionario ya ha sido inicializado" << endl;
    } else {
      diccionario.inicializar(parametros, false);
      diccionario.imprimir();
    }
  } else if (aux == "iniciar_inverso") {
    if (diccionarioInverso.lleno()) {
      cout << endl << "El diccionario ya ha sido inicializado" << endl;
    } else {
      diccionarioInverso.inicializar(parametros, true);
      diccionarioInverso.imprimir();
    }
  } else if (aux == "puntaje") {
    if (!diccionario.valido(parametros)) {
      cout << "la palabra contiene simbolos invalidos" << endl;
    } else {
      parametros = minusculas(parametros);
      int p = calcularPuntaje(parametros, diccionario, diccionarioInverso);
      if (p == 0) {
        cout << "La palabra no esta en el diccionario" << endl;
      } else {
        cout << "El puntaje de la palabra: " << parametros << " es: " << p
             << endl;
      }
    }
  } else if (aux == "salir") {
    cout << "Adios";
  } else if (aux == "iniciar_arbol") {
    if (diccionario.llenoArbol()) {
      cout << endl << "El arbol diccionario ya ha sido inicializado" << endl;
    } else {
      if (diccionario.inicializarArbol(parametros, false)) {
        cout << endl << "El arbol diccionario ha sido inicializado" << endl;
        diccionario.imprimirArbol();
      }
    }
  } else if (aux == "iniciar_arbol_inverso") {
    if (diccionarioInverso.llenoArbol()) {
      cout << endl
           << "El arbol diccionario inverso ya ha sido inicializado" << endl;
    } else {
      if (diccionarioInverso.inicializarArbol(parametros, true)) {
        cout << endl << "El arbol diccionario ha sido inicializado" << endl;
        diccionarioInverso.imprimirArbol();
      }
    }
  } else if (aux == "palabras_por_prefijo") {
    parametros = minusculas(parametros);
    diccionario.pre(parametros);
  } else if (aux == "palabras_por_sufijo") {
    parametros = minusculas(parametros);
    diccionarioInverso.suf(parametros);
  } else if (aux == "ayuda" && parametros == "") {
    cout << "inicializar diccionario.txt" << endl;
    cout << "iniciar_inverso diccionario.txt" << endl;
    cout << "puntaje palabra" << endl;
    cout << "iniciar_arbol diccionario.txt" << endl;
    cout << "iniciar_arbol_inverso diccionario.txt" << endl;
    cout << "palabras_por_prefijo prefijo" << endl;
    cout << "palabras_por_sufijo sufijo" << endl;
    cout << "grafo_de_palabras" << endl;
    cout << "posibles_palabras letras" << endl;
    cout << "salir" << endl;
  } else if (aux == "ayuda" && parametros == "inicializar") {
    cout << "debe poner:" << endl;
    cout << "inicializar 'nombre_del_archivo.txt'" << endl;
    cout << "con solo un espacio entre el comando y el nombre del archivo"
         << endl;
  } else if (aux == "ayuda" && parametros == "iniciar_inverso") {
    cout << "debe poner:" << endl;
    cout << "iniciar_inverso 'nombre_del_archivo.txt'" << endl;
    cout << "con solo un espacio entre el comando y el nombre del archivo"
         << endl;
  } else if (aux == "ayuda" && parametros == "puntaje") {
    cout << "debe poner:" << endl;
    cout << "puntaje 'Palabra_a_evaluar_sin_espacios'" << endl;
  } else if (aux == "ayuda" && parametros == "iniciar_arbol") {
    cout << "debe poner:" << endl;
    cout << "iniciar_arbol 'nombre_del_archivo.txt'" << endl;
    cout << "con solo un espacio entre el comando y el nombre del archivo"
         << endl;
  } else if (aux == "ayuda" && parametros == "iniciar_arbol_inverso") {
    cout << "debe poner:" << endl;
    cout << "iniciar_arbol_inverso 'nombre_del_archivo.txt'" << endl;
    cout << "con solo un espacio entre el comando y el nombre del archivo"
         << endl;
  } else if (aux == "ayuda" && parametros == "palabras_por_prefijo") {
    cout << "debe poner:" << endl;
    cout << "palabras_por_prefijo 'Prefijo_a_evaluar_sin_espacios'" << endl;
  } else if (aux == "ayuda" && parametros == "palabras_por_sufijo") {
    cout << "debe poner:" << endl;
    cout << "palabras_por_sufijo 'Sufijo_a_evaluar_sin_espacios'" << endl;
  } else if (aux == "ayuda" && parametros == "grafo_de_palabras") {
    cout << "debe poner:" << endl;
    cout << "grafo_de_palabras" << endl;
    cout << "sin espacios ni informacion adicional" << endl;
  } else if (aux == "ayuda" && parametros == "posibles_palabras") {
    cout << "debe poner:" << endl;
    cout << "posibles_palabras 'letras_a_evaluar_sin_espacios'" << endl;
    cout << "no usar simbolos que no sean letras ni informacion adicional" << endl;
    cout << "puede usar el comodin '?', que sirve como cualquier letra del abecedario" << endl;
  } else if (aux == "grafo_de_palabras") {
    if (!diccionario.lleno()) {
      cout << "La lista de palabras no ha sido inicializada" << endl;
    } else {
      if (diccionario.grafoLleno()) {
        cout << "El grafo ya fue inicializado" << endl;
      } else {
        diccionario.llenarGrafo();
        diccionario.imprimirGrafo();
        cout << "Grafo construido correctamente" << endl;
      }
    }
  } else if (aux == "posibles_palabras") {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  } else {
    cout << "Comando no reconocido" << endl;
  }
}