#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED


#include "Vertice.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
class Grafo {
private:
  std::list<Vertice> vertices;
public:
  Grafo();
  void InsVertice(string v,int id);
  void InsArco(int v1, int v2, int c);
  void ElimArco(int v1, int v2);
  void ElimVertice(int v);
  void MarcarVertice(int v);
  void DesmarcarVertice(int v);
  void DesmarcarGrafo();

  bool MarcadoVertice(int v);
  string InfoVertice(int v);
  int idVertice(string V);
  int OrdenGrafo() const;
  int CostoArco(int v1, int v2);
  std::list<int> sucesores(int v1);
  std::list<string> getvertices();
};
#endif // GRAFO_H_INCLUDED
