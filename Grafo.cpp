#include "Grafo.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
Grafo::Grafo(){}
void Grafo::InsVertice(string v,int id){
  Vertice nuevo;
  nuevo.setValor(v);
  nuevo.setId(id);
  vertices.push_back(nuevo);
}
void Grafo::InsArco(int v1, int v2, int c){
   list<Vertice>::iterator it;
  for(it=vertices.begin();it!=vertices.end();it++){
    if(it->getId() == v1){
      it->agregarAdyacente(v2,c);
    }
  }
}
void Grafo::ElimArco(int v1, int v2){
  list<Vertice>::iterator it;
  for(it=vertices.begin();it!=vertices.end();it++){
    if(it->getId() == v1){
      it->eliminarAdyacente(v2);
    }
  }
}
void Grafo::ElimVertice(int v) {
    std::list<Vertice>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); ++it) {
        if (it->getId() == v) {
            vertices.erase(it);
            return;
        }
    }
}
void Grafo::MarcarVertice(int v){
  list<Vertice>::iterator it;
  for(it=vertices.begin();it!=vertices.end();it++){
    if(it->getId() == v){
      it->marcar();
    }
  }
}
void Grafo::DesmarcarVertice(int v){
  list<Vertice>::iterator it;
  for(it=vertices.begin();it!=vertices.end();it++){
    if(it->getId() == v){
      it->desmarcar();
    }
  }
}
void Grafo::DesmarcarGrafo(){
 list<Vertice>::iterator it;
  for(it=vertices.begin();it!=vertices.end();it++){
    it->desmarcar();
  }
}
bool Grafo::MarcadoVertice(int v){
  list<Vertice>::iterator it;
  for(it=vertices.begin();it!=vertices.end();it++){
    if(it->getId() == v){
      return it->getSeVisito();
    }
  }
  return false;
}
string Grafo::InfoVertice(int v){
  list<Vertice>::iterator it;
  for(it=vertices.begin();it!=vertices.end();it++){
    if(it->getId() == v){
      return it->getValor();
    }
  }
  return "";
}
int Grafo::idVertice(string V){
  list<Vertice>::iterator it;
  for(it=vertices.begin();it!=vertices.end();it++){
    if(it->getValor() == V){
      return it->getId();
    }
  }
  return -1;
}
int Grafo::OrdenGrafo() const{
  return vertices.size();
}
int Grafo::CostoArco(int v1, int v2){
  list<Vertice>::iterator it;
  for(it=vertices.begin();it!=vertices.end();it++){
    if(it->getId() == v1){
      return it->getCosto(v2);
    }
  }
  return -1;
}
std::list<int> Grafo::sucesores(int v1){
  std::list<int>aux;
  list<Vertice>::iterator it;
  for(it=vertices.begin();it!=vertices.end();it++){
    if(it->getId() == v1){
      aux= it->sucesores();
    }
  }
  return aux;
}
std::list<string> Grafo::getvertices(){
  std::list<string>aux;
  for(Vertice vt:vertices){
    aux.push_back(vt.getValor());
  }
  return aux;
}
