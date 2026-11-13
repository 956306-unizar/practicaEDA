/* 
_798618_956306_956269

g++ -std=c++11 Principal.cpp anuncio.cpp fecha.cpp -o P3_EDA
*/

#include "anuncio.hpp"


Anuncio crearAnuncio(string ID, string tit, string descrip, string categ, Fecha &publi, Fecha &final)
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

void cambiarTitulo(Anuncio &e, string n)
{
    e.titulo = n;
}

string suDescripcion(const Anuncio &e)
{
    return e.descripcion;
}

void cambiarDescripcion(Anuncio &e, string n)
{
    e.descripcion = n;
}

string suCategoria(const Anuncio &e)
{
    return e.categoria;
}

void cambiarCategoria(Anuncio &e, string n)
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

// Función auxiliar para el formateo de fechas aaaa-mm-dd
string formatearFecha(const Fecha &f)
{
    string format_fecha = "";

    int dia_f = dia(f);
    int mes_f = mes(f);

    string dia_str = "";
    string mes_str = "";

    // Formatear "dia"
    if (dia_f < 10)
    {
        dia_str = "0" + to_string(dia_f);    
    } 

    else 
    {
        dia_str = to_string(dia_f);    
    }

    // Formatear "mes"
    if (mes_f < 10)
    {
        mes_str = "0" + to_string(mes_f);    
    } 

    else 
    {
        mes_str = to_string(mes_f);    
    }

    format_fecha = to_string(anyo(f)) + "-" + mes_str + "-" + dia_str;  

    return format_fecha;
}

// Función auxiliar para el "pintado" de la estructra de la instrucción LT
string mostrarAnuncio(const Anuncio &e)
{
    string resultado = "";

    resultado += "[ " + suIdentificador(e) + " -de-> " + suCategoria(e) +
                 " ;;; " + suTitulo(e) + " ] (" + formatearFecha(suPublicacion(e)) +        
                 ") --- " + suDescripcion(e) + " --- (" + formatearFecha(suFinalizacion(e)) + ")";

    return resultado;
}


