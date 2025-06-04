#include "Vertice.h"
#include <iostream>
#include<utility>
#include <list>
#include <string>
using namespace std;
Vertice::Vertice(){ this->seVisito=false; }

void Vertice::marcar(){
  this->seVisito=true;
}
void Vertice::desmarcar(){
  this->seVisito=false;
}
int Vertice::getId(){
  return id;
}
void Vertice::setId(int id){
  this->id=id;
}
string Vertice::getValor(){
  return valor;
}
void Vertice::setValor(string valor){
  this->valor=valor;
}
bool Vertice::getSeVisito(){
  return seVisito;
}
std::list<std::pair<int,int>> Vertice::getAdyacentes(){
  return adyacentes;
}
void Vertice::agregarAdyacente(int ID, int Coste){
  pair<int,int>pareja;
  pareja.first = ID;
  pareja.second = Coste;
  adyacentes.push_back(pareja);
}
void Vertice::eliminarAdyacente(int ID){
  std::list< pair<int,int>>::iterator it;
  for (it = adyacentes.begin(); it != adyacentes.end(); ++it) {
    if(it->first == ID){
      adyacentes.erase(it);
    }
  }
}
int Vertice::getCosto(int ID){
  std::list< pair<int,int>>::iterator it;
  for (it = adyacentes.begin(); it != adyacentes.end(); ++it) {
    if(it->first == ID){
      return it->second;
    }
  }
  return -1;
}
std::list<int> Vertice::sucesores(){
  std::list<int>aux;
  typename std::list< pair<int,int>>::iterator it;
  for (it = adyacentes.begin(); it != adyacentes.end(); ++it) {
    aux.push_back(it->first);
  }
  return aux;
}
