// programa para emplear "coleccionITF" y fechas
//David Maza Luengo 956269
//compilar con: g++ pruebasDavid.cpp fecha.cpp anuncio.cpp -std=c++11 -o pruebasDavid

#include <iostream>
#include <fstream>
using namespace std;

#include "anuncio.hpp"
#include "fecha.hpp"

/* ====================================================================================IMPLEMENTAR OPERACIONES DEL GENERICO
   Los Items Temáticos Fechados T necesitan de las siguientes operaciones:
    identificador: devuelve un string con el identificador del item
    tema: devuelve una cadena con el tema del Item
    fecha: devuelve un tipo fecha asociada al Item
*/

string identificador(const Anuncio& a){
    return suIdentificador(a);
}
string tema(const Anuncio& a){
    return suCategoria(a);
}
Fecha fecha(const Anuncio& a){
    return suPublicacion(a);
}

#include "coleccionITF.hpp"

// ============================================================================================INSTRUCCIONES DEL FICHERO

/*
    Por cada instrucción de tipo “A”, si es posible introducir los datos de un nuevo anuncio en la colección, se
    escribirá una línea en el fichero de salida que empiece con la cadena “INTRODUCIDO: ”; si no es posible
    introducir el anuncio en la colección, se escribirá una línea en el fichero de salida que empiece con la cadena
    “NO INTRODUCIDO: ”. En cualquiera de los dos casos, se seguirá escribiendo a continuación, y en la misma
    línea del fichero, la concatenación de los datos utilizados para el anuncio, y en el siguiente orden: identificador,
    título, categoría, descripción, fecha de publicación y fecha de finalización (separados entre sí por la cadena “:::”,
    y con las fechas escritas en formato: aaaa-mm-dd).

    EJEMPLO{
    IN:
        A
        ID40
        Maleta pequeña
        Maleta con ruedas, pequeña, buen estado.
        En venta
        2026-09-20
        2026-09-01

    OUT:
        INTRODUCIDO: ID40:::Maleta pequeña:::En venta:::Maleta con ruedas, pequeña, buen estado.:::2026-09-20:::2026-09-01
    }
    IMPORTANTE: consume el ultimo \n tambien, cuando vuelva de intrA() el siguiente caracter a leer sera la siguiente intruccion

*/
// el caracter A ha sido consumido.
void instrA( ifstream &fin, ofstream &fout, ColeccionITF<Anuncio> &c ){

    fin.ignore();   //CONSUMIMOS EL \n-------------------------------------------------------------------?? DEPENDE DE LA IMPLEMENTACION DEL BUCLE DE LECTURA
    //las siguientes 6 lineas contendran la informacion en el orden:
    //id, titulo, descripcion, categoria, publicacion, finalizacion
    string id, tit, desc, cat;
    Fecha startDate, endDate;
    getline(fin, id);   //!! getline hace un ignore del \n
    if(!esta(id, c)){   // si no esta ya, se añade

        getline(fin, tit);
        getline(fin, desc);
        getline(fin, cat);

        //ahora la fecha de publicacion
        string ano1, mes1, dia1;
        getline(fin, ano1, '-');  //tb consume el separador
        getline(fin, mes1, '-');
        getline(fin, dia1);
        bool errorPubli;
        crear(stoi(dia1), stoi(mes1), stoi(ano1), startDate, errorPubli);

        //ahora la fecha de finalizacion
        string ano2, mes2, dia2;
        getline(fin, ano2, '-');  //tb consume el separador
        getline(fin, mes2, '-');
        getline(fin, dia2);
        bool errorFinal;
        crear(stoi(dia2), stoi(mes2), stoi(ano2), endDate, errorFinal);

        Anuncio a = crearAnuncio(id, tit, desc, cat, startDate, endDate);
        anadir(c, a);

        //COMPROBAR SI SON FECHAS VALIDAS?????????????????????????????????????????????(errorFinal, errorPubli)
        fout << "INTRODUCIDO: "
            << id << ":::"
            << tit << ":::"
            << desc << ":::"
            << cat << ":::"
            << ano1 << "-" << mes1 << "-" << dia1 << ":::"
            << ano2 << "-" << mes2 << "-" << dia2 << endl
        ;

    }else{  //si ya estaba, no se añado
        fout << "NO INTRODUCIDO: "
             << id << endl;
    }
}

//-----------------------------------------------------------------------------------------------------

/*
    Por cada instrucción de tipo “C”, si es posible actualizar en la colección los datos del anuncio correspondiente
    al identificador dado, se escribirá una línea en el fichero de salida que empiece con la cadena “CAMBIADO: ”,
    seguida de la concatenación de todos los datos relativos a la nueva información del anuncio en la colección, en la
    misma línea del fichero y en el siguiente orden: identificador, título, categoría, descripción, fecha de publicación y
    fecha de finalización (separados entre sí por la cadena “:::”, y con las fechas escritas en formato: aaaa-mm-dd).
    Si no es posible actualizar el anuncio de dicho identificador en la colección, se escribirá una línea en el fichero
    de salida que empiece con la cadena “NO CAMBIADO: ”, seguida del identificador dado para la instrucción

    EJEMPLO{
    IN:
        C
        ID20
        Silla paseo bebe
        Vendo silla paseo plegable para bebe. Precio negociable
        En venta
        2026-10-21
        2026-10-21

    OUT:
        CAMBIADO: ID20:::Silla paseo bebe:::En venta:::Vendo silla paseo plegable para bebe. Precio negociable:::2026-10-21:::2026-10-21
    }
    IMPORTANTE: consume el ultimo \n tambien, cuando vuelva de intrA() el siguiente caracter a leer sera la siguiente intruccion

*/
// el caracter C ha sido consumido.
void instrC( ifstream &fin, ofstream &fout, ColeccionITF<Anuncio> &c ){

    fin.ignore();   //CONSUMIMOS EL \n-------------------------------------------------------------------?? DEPENDE DE LA IMPLEMENTACION DEL BUCLE DE LECTURA
    //las siguientes 6 lineas contendran la informacion en el orden:
    //id, titulo, descripcion, categoria, publicacion, finalizacion
    string id, tit, desc, cat;
    Fecha startDate, endDate;
    getline(fin, id);   //!! getline hace un ignore del \n
    if(esta(id, c)){    //si esta ya, se cambia

        getline(fin, tit);
        getline(fin, desc);
        getline(fin, cat);

        //ahora la fecha de publicacion
        string ano1, mes1, dia1;
        getline(fin, ano1, '-');  //tb consume el separador
        getline(fin, mes1, '-');
        getline(fin, dia1);
        bool errorPubli;
        crear(stoi(dia1), stoi(mes1), stoi(ano1), startDate, errorPubli);

        //ahora la fecha de finalizacion
        string ano2, mes2, dia2;
        getline(fin, ano2, '-');  //tb consume el separador
        getline(fin, mes2, '-');
        getline(fin, dia2);
        bool errorFinal;
        crear(stoi(dia2), stoi(mes2), stoi(ano2), endDate, errorFinal);

        Anuncio a = crearAnuncio(id, tit, desc, cat, startDate, endDate);
        anadir(c, a);

        //COMPROBAR SI SON FECHAS VALIDAS?????????????????????????????????????????????(errorFinal, errorPubli)
        fout << "CAMBIADO: "
            << id << ":::"
            << tit << ":::"
            << desc << ":::"
            << cat << ":::"
            << ano1 << "-" << mes1 << "-" << dia1 << ":::"
            << ano2 << "-" << mes2 << "-" << dia2 << endl
        ;

    }else{  //si no estaba, no se puede cambiar
        fout << "NO CAMBIADO: "
             << id << endl;
    }
}

//-----------------------------------------------------------------------------------------------------


/*
    Por cada instrucción de tipo “E”, si existe algún anuncio en la colección con un identificador igual al dado, se
    escribirá una línea en el fichero que empiece con la cadena “EXISTENTE: ”. Si no existía ningún anuncio en la
    colección con un identificador igual al dado, se escribirá en el fichero una línea que empiece con la cadena
    “DESCONOCIDO: ”. En cualquiera de los dos casos, se seguirá escribiendo a continuación, y en la misma línea
    del fichero, el identificador dado para la instrucción.

    EJEMPLO{
    IN:
        E
        ID25
        E
        iD20
        E
        ID20
    
    OUT:
        DESCONOCIDO: ID25
        DESCONOCIDO: iD20
        EXISTENTE: ID20
    }
    IMPORTANTE: consume el ultimo \n tambien, cuando vuelva de intrA() el siguiente caracter a leer sera la siguiente intruccion
*/
// el caracter E ha sido consumido.
void instrE( ifstream &fin, ofstream &fout, ColeccionITF<Anuncio> &c ){
    
    fin.ignore();   //CONSUMIMOS EL \n-------------------------------------------------------------------?? DEPENDE DE LA IMPLEMENTACION DEL BUCLE DE LECTURA
    //la siguiente linea contendran el id
    string id;
    getline(fin, id);   //!! getline hace un ignore del \n
    if(!esta(id, c)){   // si no esta ya, se añade

        fout << "EXISTENTE: ";

    }else{  //si ya estaba, no se añado
        fout << "DESCONOCIDO: ";
    }
    fout << id << endl;
}


// ==================================================================================================FUNCIONES PROPIAS



// ==================================================================================================
int main(){
    //pruebas coleccionITF---------------------------------------------------
    //AÑADIR, BORRAR, INICIARITERADOR, EXISTESIGUIENTE, SIGUIENTEYAVANZA


    ColeccionITF<Anuncio> col;
    crear(col);
    int contador = 1;
    Fecha ini, fin;
    bool placeholder;
    crear(1, 1, 2000, ini, placeholder);
    crear(1, 1, 2030, fin, placeholder);

    string id = "ID" + to_string(contador);
    Anuncio a1 = crearAnuncio(id, "Producto 1(tit)", "Descripcion del producto 1(desc)", "Ropa(cat)", ini, fin);    
    anadir(col, a1);

    cout << "Colceccion con anuncio de prueba creada" << endl;
    
    int opcion;
    do{
        

        cout << endl
            << "------------------------------------------------------------------------------------------" << endl
            << "¿Qué quieres hacer?:" << endl
            << "0) terminar" << endl 
            << "1) mostrarla" << endl
            << "2) añadir anuncio" << endl
            << "3) borrar anuncio segun ID" << endl
        ;
        cin >> opcion;
        cout << endl
        << "------------------------------------------------------------------------------------------" << endl;
        switch (opcion){
            case 1:{   //MOSTRAR LSITA
                
                Anuncio tempA;
                iniciarIterador(col);
                while(siguienteYavanza(col, tempA)){

                    cout << mostrarAnuncio(tempA) << endl;
                }

                break;
            }
            case 2:{   //meter producto nuevo por terminal
                
                contador++;
                id = "ID" + to_string(contador);
                a1 = crearAnuncio(id, "Producto 1(tit)", "Descripcion del producto 1(desc)", "Ropa(cat)", ini, fin);
                anadir(col,a1);
                cout << "anuncio " << contador << " añadido" << endl;
                break;
            }
            case 3:{   //eliminar producto
                
                string ident;
                cout << "Introduce ID a borrar:";
                cin >> ident;
                borrar(ident, col);
                break;
            }
            case 4:{   //buscar si está producto
                /*
                producto p;
                cout << "Introduzca el nombre(SIN ESPACIOS)(CASE SENSITIVE): ";
                string nombre;
                cin >> nombre;
                crear(nombre, 0, p);
                
                cout << endl;
                if(esta(l, p)){
                    cout << nombre << " está en la lista" << endl;
                }else{
                    cout << nombre << " no se encuentra en la lista" << endl;
                }
                */
                break;
            }
            default:{
                break;
            }
        }
    }while(opcion != 0);


}