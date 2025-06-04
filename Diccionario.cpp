#include "Diccionario.h"
#include "ArbolGeneral.h"
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <string>
using namespace std;
/**************************************************************************************************************************************FUNCIONES**GETTERS*****************************************************************************************************************************************/
// constructor por defecto
Diccionario::Diccionario() {}
// getter de la lista de palabras
list<string> Diccionario::getPalabras() { return palabras; }
//getter del arbol general
ArbolGeneral Diccionario::getArbol(){return arbol;}
/**************************************************************************************************************************************FUNCIONES**AUXILIARES**************************************************************************************************************************************/
/* Según la letra ingresada, ya sea mayuscula o minuscula, retorna su valor
  en puntos*/
int Diccionario::puntaje(char c) {
  c = toupper(c);
  if(c == 'E' || c == 'A' || c == 'I' || c == 'O' || c == 'N' || c == 'R' ||
      c == 'T' || c == 'L' || c == 'S' || c == 'U'){
    return 1;
  }
  if(c == 'D' || c == 'G') {
    return 2;
  }
  if(c == 'B' || c == 'C' || c == 'M' || c == 'P'){
    return 3;
  }
  if(c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y'){
    return 4;
  }
  if(c == 'K'){
    return 5;
  }
  if(c == 'J' || c == 'X'){
    return 8;
  }
  if(c == 'Q' || c == 'Z'){
    return 10;
  }
  return 0;
}
//calcula el puntaje de una palabra
int Diccionario::puntaje(string palabra){
  int puntos = 0;
  for(int i = 0; i < palabra.size(); i++){
    puntos = puntos + puntaje(palabra[i]);
  }
  return puntos;
}
//invierte una palabra
string Diccionario::invertirPalabra(string palabra){
  stack<char> pila;
  for(int i = 0; i < palabra.size(); i++){
    pila.push(palabra[i]);
  }
  string aux;
  while(!pila.empty()){
    aux = aux + pila.top();
    pila.pop();
  }
  return aux;
}
//  Busca una palabra en el diccionario y si la encuentra, retorna true
bool Diccionario::esta(string palabra) {
  for (int i = 0; i < palabra.size(); i++) {
    palabra[i] = toupper(palabra[i]);
  }
  for (auto it = palabras.begin(); it != palabras.end(); it++) {
    string aux = *it;
    for (int i = 0; i < aux.size(); i++) {
      aux[i] = toupper(aux[i]);
    }
    if (palabra == aux) {
      return true;
    }
  }
  return false;
}
//comprueba si una palabra contiene caracteres invalidos
bool Diccionario::valido(string palabra) {
  for (char c: palabra){
    if (!((c >= 65 && c <= 90) ||  (c >= 97 && c <= 122))) {
      return false;
    }
  }
  return true;
}
/**************************************************************************************************************************************LISTAS*****************************************************************************************************************************************************/
// inicializa la lista de palabras con las palabras del archivo
bool Diccionario::inicializar(string file,bool inverso) {
  ifstream archivo(file);
  string linea;
  if (!archivo.is_open()) {
    cout << "El archivo: " << file << " no existe o no puede ser leido" << endl;
    archivo.close();
    return false;
  }
  while (getline(archivo, linea)) {
    bool sirve;
    sirve=valido(linea);
    if (sirve) {
      if(inverso)
        linea=invertirPalabra(linea);
      palabras.push_back(linea);
    }
  }
  archivo.close();
  return true;
}
// imprime la lista de palabras para verificar que se haya cargado correctamente
void Diccionario::imprimir() {
  for (auto it = palabras.begin(); it != palabras.end(); it++) {
    cout << *it << endl;
  }
}
// comprueba sí la lista de palabras está vacía
bool Diccionario::lleno() {
  if (palabras.size() == 0) {
    return false;
  } else {
    return true;
  }
}
/**************************************************************************************************************************************ARBOLES****************************************************************************************************************************************************/
// comprueba sí el arbol de palabras está vacía
bool Diccionario::llenoArbol() {
  if (arbol.subArbolGeneral().size() == 0) {
    return false;
  } else {
    return true;
  }
}
//imprime el arbol para combrobar que se lleno correctamente
void Diccionario::imprimirArbol() { arbol.preOrden(); }
// inicializa el arbol de palabras con las palabras del archivo
bool Diccionario::inicializarArbol(string file,bool inverso) {
  ifstream archivo(file);
  string linea;
  if (!archivo.is_open()) {
    cout << "El archivo: " << file << " no existe o no puede ser leido" << endl;
    archivo.close();
    return false;
  }
  while (getline(archivo, linea)) {
    bool sirve;
    sirve=valido(linea);
    if (sirve) {
      if(inverso)
        linea=invertirPalabra(linea);
      arbol.llenarArbol2(linea, 0, 0);
    }
  }
  archivo.close();
  return true;
}
//Funcion auxiliar que llana a la funcion que busca palabras por prefijo
void Diccionario::pre(string pre) { 
  list<string>lista;
  string aux = pre;
  arbol.prefsufijo(aux, 0, 0,lista);
  for(string g:lista){
    imprimirAux(g);
  }
}
//Funcion auxiliar que llana a la funcion que busca palabras por sufijo
void Diccionario::suf(string suf) {
  list<string>lista;
  string aux = invertirPalabra(suf);
  arbol.prefsufijo(aux, 0, 0,lista);
  for(string g:lista){
    g=invertirPalabra(g);
    imprimirAux(g);
  }
}
//imprime la informacion de las palabras encontradas con un sufijo
void Diccionario::imprimirAux(string pala){
  int puntos = puntaje(pala);
  string pal = pala;
  int tam = pal.size();
  cout << "palabra: " << pala << " puntaje: " << puntos<< " tamanio: " << tam << endl;
}
/**************************************************************************************************************************************GRAFOS*****************************************************************************************************************************************************/
bool Diccionario::grafoLleno(){
  if(grafo.getvertices().size()==0){
    return false;
  }
  else{
    return true;
  }
}
void Diccionario::llenarGrafo(){
  llenarVertices();
  llenarAristas();
}
void Diccionario::llenarVertices(){
  int i=1;
  for(string s: palabras){
    grafo.InsVertice(s,i);
    i++;
  }
}
void Diccionario::llenarAristas(){
  for(string s: palabras){
    int id = grafo.idVertice(s);
    list<string>::iterator it;
    list<string> gr=grafo.getvertices();
    for(it=gr.begin();it!=gr.end();it++){
      int idg = grafo.idVertice(*it);
      if(coinciden(s,*it)){
        grafo.InsArco(id, idg, 1);
      }
    }
  }
}
void Diccionario::imprimirGrafo(){
  cout<<"VERTICE\t\t\tSUCESORES"<<endl;
  for(string s:grafo.getvertices()){
    int id = grafo.idVertice(s);
    cout<<s<<"\t\t\t";
    for(int i: grafo.sucesores(id)){
      cout<<grafo.InfoVertice(i)<<" ";
    }
    cout<<endl;
  }
}
bool Diccionario::coinciden(string palabra, string palabra2){
  int tam = palabra.size(),igual=0;
  if (palabra.size()==palabra2.size()){
    for(int i=0;i<tam;i++){
      if(palabra[i]==palabra2[i]){
        igual++;
      }
    }
    if(igual==tam-1){
      return true;
    }
  }else if(palabra.size()+1==palabra2.size()) {
    for(int i=0;i<tam;i++){
      if(palabra[i]==palabra2[i]){
        igual++;
      }
    }
    if(igual==tam){
      return true;
    }
  }else if(palabra.size()==palabra2.size()+1){
    for(int i=0;i<tam;i++){
      if(palabra[i]==palabra2[i]){
        igual++;
      }
    }
    if(igual==tam){
      return true;
    }
  }
  return false;
}