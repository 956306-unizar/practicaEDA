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
    crear(20, 2, 2001, ffin, error);

    Anuncio e = crearAnuncio(id, articulo, descripcion, categoria, fpubl, ffin);    

    //for (int i = 0; i < )

    cout << "";

    return 0;
}