/* 
_798618_956306_956269

g++ -std=c++11 Principal.cpp anuncio.cpp fecha.cpp -o P3_EDA
*/

#include "anuncio.hpp"



Anuncio crearAnuncio(string &ID, string &tit, string &descrip, string &categ, Fecha &publi, Fecha &final)
{
    Anuncio e;

    e.ID = ID;
    e.titulo = tit;
    e.descripcion = descrip;
    e.categoria = categ;
    e.publicacion = publi;
    e.finalizacion = final;

    return e;
}

string suIdentificador(const Anuncio &e)
{
    return e.ID;
}

string suTitulo(const Anuncio &e)
{
    return e.titulo;
}

void cambiarTitulo(Anuncio &e, string &n)
{
    e.titulo = n;
}

string suDescripcion(const Anuncio &e)
{
    return e.descripcion;
}

void cambiarDescripcion(Anuncio &e, string &n)
{
    e.descripcion = n;
}

string suCategoria(const Anuncio &e)
{
    return e.categoria;
}

void cambiarCategoria(Anuncio &e, string &n)
{
    e.categoria = n;
}

Fecha suPublicacion(const Anuncio &e)
{
    return e.publicacion;
}

Fecha suFinalizacion(const Anuncio &e)
{
    return e.finalizacion;
}



