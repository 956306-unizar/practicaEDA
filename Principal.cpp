/* 
_798618_956306_956269

g++ -std=c++11 Principal.cpp anuncio.cpp fecha.cpp -o P3_EDA
*/

#include "anuncio.hpp"
#include "fecha.hpp"

#include<iostream>
using namespace std;

int main ()
{
    bool error;

    Fecha fpubl;
    Fecha ffin;

    string id = "7888";
    string articulo = "Coche";
    string descripcion = "120000 km primer cliente";
    string categoria = "MOTOR";

    crear(20, 2, 2001, fpubl, error);
    crear(25, 4, 2002, ffin, error);

    // Prueba de las funciones creadas

    Anuncio e = crearAnuncio(id, articulo, descripcion, categoria, fpubl, ffin);  

    cout << "\n";
    cout << mostrarAnuncio(e);     
    cout << "\n";


    // Probar "cambiarTitulo"
    string nuevoTitulo = "Sudadera gris";

    cambiarTitulo(e, nuevoTitulo);

    cout << mostrarAnuncio(e); 

    // Probar "cambiarDescripcion"
    string nuevaDescripcion = "Sudadera gris, talla M estado deteriorado";

    cambiarDescripcion(e, nuevaDescripcion);

    cout << "\n";
    cout << mostrarAnuncio(e); 

    // Probar "cambiarCategoria"
    string nuevaCategoria = "ROPA";

    cambiarCategoria(e, nuevaCategoria);
    
    cout << "\n";
    cout << mostrarAnuncio(e); 

    return 0;
}