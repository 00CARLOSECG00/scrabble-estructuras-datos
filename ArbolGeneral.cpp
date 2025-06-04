#include "ArbolGeneral.h"
#include <iostream>
// Constructor por defecto
ArbolGeneral::ArbolGeneral() { raiz = new Nodo('#'); }

// Constructor con valor inicial para la raíz
ArbolGeneral::ArbolGeneral(char val) { raiz = new Nodo(val); }

// Constructor de copia
ArbolGeneral::ArbolGeneral(const ArbolGeneral &arbol) {
  copiar(arbol.raiz, raiz);
}

// Destructor
ArbolGeneral::~ArbolGeneral() { destruir(raiz); }

// Devuelve una lista de subárboles
std::list<ArbolGeneral> ArbolGeneral::subArbolGeneral() {
  std::list<ArbolGeneral> subarboles;
  if (raiz != nullptr) {
    for (auto hijo : raiz->hijos) {
      ArbolGeneral subarbol;
      subarbol.raiz = hijo;
      subarboles.push_back(subarbol);
    }
  }
  return subarboles;
}

// Verifica si el árbol está vacío
bool ArbolGeneral::esVacio() { return raiz == nullptr; }

// Obtiene el valor de la raíz
char ArbolGeneral::obtenerRaiz() {
  if (raiz != nullptr)
    return raiz->valor;
  else
    throw std::runtime_error("El árbol está vacío");
}

// Establece el valor de la raíz
void ArbolGeneral::fijarRaiz(char val) {
  if (raiz != nullptr)
    raiz->valor = val;
  else
    raiz = new Nodo(val);
}

// Sobrecarga del operador de asignación
ArbolGeneral &ArbolGeneral::operator=(const ArbolGeneral &arbol) {
  if (this != &arbol) {
    destruir(raiz);
    raiz = nullptr;
    copiar(arbol.raiz, raiz);
  }
  return *this;
}
// Busca un valor en el árbol
bool ArbolGeneral::buscar(char n) { return buscarNodo(n, raiz) != nullptr; }

// Calcula la altura del árbol
unsigned int ArbolGeneral::altura() { return altura(raiz); }

// Calcula el tamaño del árbol
unsigned int ArbolGeneral::tamano() { return tamano(raiz); }

// Devuelve el orden del árbol
unsigned int ArbolGeneral::orden() {
  return raiz != nullptr ? raiz->hijos.size() : 0;
}

// Recorrido en preorden
void ArbolGeneral::preOrden() { preOrden(raiz); }

// Recorrido en postorden
void ArbolGeneral::posOrden() { posOrden(raiz); }

// Recorrido por niveles
void ArbolGeneral::nivelOrden() { nivelOrden(raiz); }

// Función privada para copiar un árbol
void ArbolGeneral::copiar(const Nodo *nodo, Nodo *&nuevo) {
  if (nodo == nullptr)
    nuevo = nullptr;
  else {
    nuevo = new Nodo(nodo->valor);
    for (auto hijo : nodo->hijos) {
      Nodo *nuevoHijo = nullptr;
      copiar(hijo, nuevoHijo);
      nuevo->hijos.push_back(nuevoHijo);
    }
  }
}
// Función privada para destruir un árbol
void ArbolGeneral::destruir(Nodo *&nodo) {
  if (nodo != nullptr) {
    for (auto hijo : nodo->hijos) {
      destruir(hijo);
    }
    delete nodo;
    nodo=nullptr;
  }
}
// Función privada para calcular la altura del árbol
unsigned int ArbolGeneral::altura(Nodo *nodo) {
  if (nodo == nullptr)
    return 0;
  unsigned int maxAltura = 0;
  // Función privada para calcular la altura del árbol (continuación)
  for (auto hijo : nodo->hijos) {
    unsigned int alturaHijo = altura(hijo);
    if (alturaHijo > maxAltura)
      maxAltura = alturaHijo;
  }
  return maxAltura + 1;
}

// Función privada para calcular el tamaño del árbol
unsigned int ArbolGeneral::tamano(Nodo *nodo) {
  if (nodo == nullptr)
    return 0;
  unsigned int totalNodos = 1;
  for (auto hijo : nodo->hijos) {
    totalNodos += tamano(hijo);
  }
  return totalNodos;
}

// Función privada para realizar un recorrido en preorden
void ArbolGeneral::preOrden(Nodo *nodo) {
  if (nodo != nullptr) {
    std::cout << nodo->valor << " ";
    for (auto hijo : nodo->hijos) {
      preOrden(hijo);
    }
  }
}

// Función privada para realizar un recorrido en postorden
void ArbolGeneral::posOrden(Nodo *nodo) {
  if (nodo != nullptr) {
    for (auto hijo : nodo->hijos) {
      posOrden(hijo);
    }
    std::cout << nodo->valor << " ";
  }
}

// Función privada para realizar un recorrido por niveles
void ArbolGeneral::nivelOrden(Nodo *nodo) {
  if (nodo == nullptr)
    return;
  std::list<Nodo *> nivelActual, siguienteNivel;
  nivelActual.push_back(nodo);
  while (!nivelActual.empty()) {
    for (auto nodo : nivelActual) {
      std::cout << nodo->valor << " ";
      for (auto hijo : nodo->hijos) {
        siguienteNivel.push_back(hijo);
      }
    }
    std::cout << std::endl;
    nivelActual = std::move(siguienteNivel);
  }
}
// Función privada para buscar un nodo con valor n en el árbol y devuelve un
// puntero a dicho nodo
ArbolGeneral::Nodo *ArbolGeneral::buscarNodo(char n, Nodo *nodo) {
  if (nodo == nullptr)
    return nullptr;
  if (nodo->valor == n)
    return nodo;
  for (auto hijo : nodo->hijos) {
    Nodo *encontrado = buscarNodo(n, hijo);
    if (encontrado != nullptr)
      return encontrado;
  }
  return nullptr;
}
// Inserta un nodo en el árbol
bool ArbolGeneral::insertarNodo(char padre, char n) {
  Nodo *nodoPadre = buscarNodo(padre, raiz);
  if (nodoPadre != nullptr) {
    nodoPadre->hijos.push_back(new Nodo(n));
    return true;
  }
  return false;
}
//======================================================================
/*
Llena el el arbol con las palabras, ubicandolas en el mismo nivel que esta con respecto
a la posicion de una letra en la palabra

*/
void ArbolGeneral:: llenarArbol2(std::string palabra, int pos,int altura) {
  Nodo *padre = raiz;

  if (pos < palabra.size()) {
    if (padre == nullptr) {
      raiz = new Nodo(palabra[pos]);
      padre = raiz;
    } else {
      bool encontrado = false;

      for (Nodo *hijo : padre->hijos) {

       if (hijo->valor == palabra[pos] && altura==pos) {
          llenarArbol2(palabra, pos + 1,altura);
          encontrado = true;
          break;
        }
      }      
      if (!encontrado) {
        char papa;
        if(pos==0)
          papa = '#';
        else
          papa = palabra[pos-1];
        insertarNodof(papa, palabra[pos],pos);
        llenarArbol2(palabra, pos + 1,altura);
      }
    }
  } else {
    char papa = palabra[pos-1];
    this->insertarNodof(papa, '/',pos);
  }
}
// Inserta un nodo en el árbol
bool ArbolGeneral::insertarNodof(char padre, char n,int pos) {
  bool existe=false;
  Nodo *nodoPadre = buscarNodo2(padre, raiz,0,pos);
  //buscar en hijo la n y si esta retorna true else if...
  std::list<Nodo*> li= nodoPadre->hijos;
  for(Nodo* c:li){
    if(c->valor==n){
      existe=true;
    }
  }
  if(existe){
    return true;
  }
  else if (nodoPadre != nullptr) {
    nodoPadre->hijos.push_back(new Nodo(n));
    return true;
  }
  return false;
}
//busca un nodo, desde los ultimos agregados hasta los primeros
ArbolGeneral::Nodo *ArbolGeneral::buscarNodo2(char n, Nodo *nodo,int altura,int pos) {
  if (nodo == nullptr && altura==pos)
    return nullptr;
  if (nodo->valor == n && altura==pos)
    return nodo;
  for (auto it = nodo->hijos.rbegin(); it != nodo->hijos.rend(); ++it) {
    Nodo *encontrado = buscarNodo2(n, *it,altura+1,pos);
    if (encontrado != nullptr)
      return encontrado;
  }
  return nullptr;
}
/*recorre el arbol en preorden y cada vez que encuentra un '/', asume que terminó de leer una palabra, entonces la agrega a una lista*/
void ArbolGeneral::preOrden2(Nodo *nodo,std::string pre,std::list<std::string>&palabras) {
  if (nodo != nullptr) {
    std::string aux;
    if(nodo->valor!='/'){
      aux = pre + nodo->valor;
    }
    else{
      std::string aux = pre;
      palabras.push_back(aux);
    }
    for (Nodo *hijo : nodo->hijos) {
      preOrden2(hijo,aux,palabras);
    }
  }
}
/*busca la cadena letra por letra en el nodo y forma las palabras con sus hijos, agregandolos
a una lista de palabras*/
void ArbolGeneral::prefsufijo(std::string pre, Nodo *nodo, int pos,int encontrados,std::list<std::string> &palabras) {
  std::string aux = pre; 
  if (pos < aux.size()) {
    if (nodo != nullptr){   
      for (Nodo *hijo:nodo->hijos) {
        if (hijo->valor == '/') {
          prefsufijo(pre, hijo, pos, encontrados,palabras);
        }
        if (hijo->valor == pre[pos]) { 
          prefsufijo(pre, hijo, pos + 1, encontrados + 1,palabras);
        }
      }
    }
  }
  if (encontrados == aux.size()) {
    std::string re = pre.substr(0,pre.size()-1);
    preOrden2(nodo, re,palabras);
  }
}
//llamado a la funcion recursiva presufijo
void ArbolGeneral::prefsufijo(std::string pre, int pos,int encontrados,std::list<std::string> &palabras) {
  prefsufijo(pre,raiz,pos,encontrados,palabras);
}