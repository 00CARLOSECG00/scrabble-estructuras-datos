#ifndef Diccionario_H
#define Diccionario_H
#include "ArbolGeneral.h"
#include "Grafo.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;
class Diccionario {
private:
  list<string> palabras;
  ArbolGeneral arbol;
  Grafo grafo;
public:
  Diccionario();
  list<string> getPalabras();
  ArbolGeneral getArbol();
  bool valido(string palabra);
  int puntaje(char c);
  int puntaje(string palabra);
  bool esta(string palabra);
  bool lleno();
  bool llenoArbol();
  bool inicializar(string file, bool inverso);
  bool inicializarArbol(string file, bool inverso);
  void imprimir();
  void imprimirArbol();
  void pre(string pre);
  void suf(string suf);
  bool grafoLleno();
  void llenarGrafo();
  void llenarVertices();
  void llenarAristas();
  void imprimirGrafo();
  bool coinciden(string palabra, string palabra2);
protected:
  string invertirPalabra(string palabra);
  void imprimirAux(string pal);
};
#endif