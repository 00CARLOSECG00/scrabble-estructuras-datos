#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED

#include<utility>
#include <iostream>
#include <list>
#include <string>
using namespace std;
class Vertice {
  private:
    string valor;
    int id;
    bool seVisito;
    std::list<std::pair<int,int>> adyacentes;
  public:
    Vertice();
    void marcar();
    void desmarcar();
    int getId();
    void setId(int id);
    string getValor();
    void setValor(string valor);
    bool getSeVisito();
    std::list<std::pair<int,int>> getAdyacentes();
    void agregarAdyacente(int ID, int Coste);
    void eliminarAdyacente(int ID);
    int getCosto(int ID);
    std::list<int>sucesores();
};
#endif /* VERTICE_H */
