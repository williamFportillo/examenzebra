//
// Created by WilliamPC on 14/8/2017.
//

#ifndef EXAMEN1PARCIAL_EVALUADOR_H
#define EXAMEN1PARCIAL_EVALUADOR_H
#include <iostream>
#include <fstream>
#include <math.h>
#include <list>
#include <vector>
using namespace std;

class Numero
{
public:
    int valor;
    Numero(int valor)
    {
        this->valor = valor;
    }
};

class Pais
{
public:
    string nombre;
    string capital;
    int habitantes;
    int superficie;

    Pais(string nombre, string capital, int habitantes, int superficie)
    {
        this->nombre = nombre;
        this->capital = capital;
        this->habitantes = habitantes;
        this->superficie = superficie;
    }
};

double evaluarEscondido();

int obtenerValor(Numero** arreglo, int pos);
bool sonMayusculas(list<string> palabras);
vector<int> eliminarRepetidos(vector<int> vector_a);
void guardar(string nombre_archivo, Pais* pais);
Pais* abrir(string nombre_archivo);

#endif //EXAMEN1PARCIAL_EVALUADOR_H
