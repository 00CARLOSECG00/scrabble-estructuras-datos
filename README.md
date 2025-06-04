# 🧠 Proyecto Scrabble en C++
**Pontificia Universidad Javeriana**  
**Curso: Estructuras de Datos**  
Desarrollado por: Carlos Caicedo  

---

## 🎯 Descripción del proyecto

Este proyecto implementa un sistema de apoyo para el juego **Scrabble**, usando estructuras de datos avanzadas en C++. El sistema permite interactuar por consola con comandos que evalúan palabras, generan posibles combinaciones, puntajes y sugerencias de juego.

El objetivo principal fue aplicar árboles, grafos y diccionarios para procesar un archivo de palabras y construir funcionalidades similares a las de un “Scrabble Word Finder”.

---

## 🛠️ Tecnologías y herramientas

- Lenguaje: **C++**
- Compilador: `g++ (C++11 o superior)`
- Estructuras utilizadas:
  - Árboles para búsqueda por prefijo/sufijo
  - Grafos de palabras (conexión por una letra)
  - Diccionario en listas
- Herramientas: VS Code, GitHub

---

## 📁 Estructura del repositorio
📦 scrabble-ed-cpp/
├── ArbolGeneral.cpp / .h → Implementación de árbol de prefijos y sufijos
├── Diccionario.cpp / .h → Funciones de inicialización y validación de palabras
├── Grafo.cpp / .h → Implementación del grafo de palabras
├── Vertice.cpp / .h → Representación de nodos del grafo
├── main.cpp → Controlador principal y menú interactivo
├── diccionario.txt → Diccionario base
├── contenidoDiccionario.txt → Copia o muestra de contenido del diccionario
├── README.md → Este archivo