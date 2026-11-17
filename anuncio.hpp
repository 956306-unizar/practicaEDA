/*
 * =================================
 * AUTOR DEL CÓDIGO Y SU NIP
 * =================================
 * Arián Lajara Bueno   - 798618
 * =================================
 */

#ifndef _ANUNCIO_HPP
#define _ANUNCIO_HPP

#include "fecha.hpp"

#include<iostream>
using namespace std;

struct Anuncio;


//Devuelve el tipo de dato Anuncio, sus datos rellenos con los parametros correspondientes.
Anuncio crearAnuncio(string ID, string tit, string descrip, string categ, Fecha &publi, Fecha &final);

//Devuelve la cadena Identificador del Anuncio
string suIdentificador(const Anuncio &e);

//Devuelve la cadena Titulo del Anuncio
string suTitulo(const Anuncio &e);

//cambia el Titulo del anuncio e por n
void cambiarTitulo(Anuncio &e, string n);

//Devuelve la cadena Descripcion del Anuncio
string suDescripcion(const Anuncio &e);

//cambia la Descripcion del anuncio e por n
void cambiarDescripcion(Anuncio &e, string n);

//Devuelve la cadena Categoria del Anuncio
string suCategoria(const Anuncio &e);

//cambia la Categoria del anuncio e por n
void cambiarCategoria(Anuncio &e, string n);

//Devuelve el tipo Fecha de la fecha de publicacion de e
Fecha suPublicacion(const Anuncio &e);

//Devuelve el tipo Fecha de la fecha de finalización de e
Fecha suFinalizacion(const Anuncio &e);

//Devuelve una cadena con la fecha f en formato "aaaa-mm-dd"
string formatearFecha(const Fecha &f);


struct Anuncio
{
    friend Anuncio crearAnuncio(string ID, string tit, string descrip, string categ, Fecha &publi, Fecha &final);
    friend string suIdentificador(const Anuncio &e);
    friend string suTitulo(const Anuncio &e);
    friend void cambiarTitulo(Anuncio &e, string n);
    friend string suDescripcion(const Anuncio &e);
    friend void cambiarDescripcion(Anuncio &e, string n);
    friend string suCategoria(const Anuncio &e);
    friend void cambiarCategoria(Anuncio &e, string n);
    friend Fecha suPublicacion(const Anuncio &e);
    friend Fecha suFinalizacion(const Anuncio &e);

    friend string formatearFecha(const Fecha &f);
    friend string mostrarAnuncio(const Anuncio &e);

    private:
        string ID;
        string titulo;
        string descripcion;
        string categoria;
        Fecha publicacion;
        Fecha finalizacion;        
};

#endif