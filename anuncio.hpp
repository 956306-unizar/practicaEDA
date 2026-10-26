/* 
_798618_956306_956269

g++ -std=c++11 Principal.cpp anuncio.cpp fecha.cpp -o P3_EDA
*/

#ifndef _ANUNCIO_HPP
#define _ANUNCIO_HPP

#include "fecha.hpp"

#include<iostream>
using namespace std;

struct Anuncio;


// Añadir las referencias a algunos parametros


Anuncio crearAnuncio(string &ID, string &tit, string &descrip, string &categ, Fecha &publi, Fecha &final);
string suIdentificador(const Anuncio &e);
string suTitulo(const Anuncio &e);
void cambiarTitulo(Anuncio &e, string &n);
string suDescripcion(const Anuncio &e);
void cambiarDescripcion(Anuncio &e, string &n);
string suCategoria(const Anuncio &e);
void cambiarCategoria(Anuncio &e, string &n);
Fecha suPublicacion(const Anuncio &e);
Fecha suFinalizacion(const Anuncio &e);

struct Anuncio
{
    friend Anuncio crearAnuncio(string &ID, string &tit, string &descrip, string &categ, Fecha &publi, Fecha &final);
    friend string suIdentificador(const Anuncio &e);
    friend string suTitulo(const Anuncio &e);
    friend void cambiarTitulo(Anuncio &e, string &n);
    friend string suDescripcion(const Anuncio &e);
    friend void cambiarDescripcion(Anuncio &e, string &n);
    friend string suCategoria(const Anuncio &e);
    friend void cambiarCategoria(Anuncio &e, string &n);
    friend Fecha suPublicacion(const Anuncio &e);
    friend Fecha suFinalizacion(const Anuncio &e);

    private:
        string ID;
        string titulo;
        string descripcion;
        string categoria;
        Fecha publicacion;
        Fecha finalizacion;        
};

#endif