/* 
_798618_956306_956269

Comando de compilación en Windows11: g++ .\fecha.cpp .\anuncio.cpp .\coleccionITF.hpp .\Principal.cpp -Wall -Wextra -std=c++11 -o Principal

*/

#include <iostream>
#include <fstream>

#include "fecha.hpp"
#include "anuncio.hpp"
#include "coleccionITF.hpp"

using namespace std;

string identificador(const Anuncio& a){
    return suIdentificador(a);
}

string tema(const Anuncio& a){
    return suCategoria(a);
}

Fecha fecha(const Anuncio& a){
    return suPublicacion(a);
}

// Cabeceras funciones auxiliares para las instrucciones
void instrA(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c);
void instrC(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c);
void instrO(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c);
void instrE(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c);
void instrEC(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c);
void instrB(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c);
void instrBC(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c);
void instrP(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c);
void instrLO(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c);
void instrLC(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c);
void instrLT(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c);


// --- PROGRAMA PRINCIPAL ---
int main() {

    ifstream lectorFichero("entrada.txt");
    ofstream escritorFichero("salida.txt");

    if(!lectorFichero.is_open()) {

        cerr << "ERROR: No se ha podido abrir el archivo 'entrada.txt'"
            << "\nAsegurese de que se encuentra en el mismo nivel del directorio en el que esta este ejecutable." << endl;

        return 1;

    } else if(!escritorFichero.is_open()) {

        cerr << "ERROR: No se ha podido abrir o crear el archivo 'salida.txt'" << endl;

        return 1;
    }

    ColeccionITF<Anuncio> coleccionAnuncios;

    string instruccionActual;

    while(getline(lectorFichero, instruccionActual)) {

        if (instruccionActual == "A") {

            instrA(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "C") {

            instrC(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "O") {

            //instrO(lectorFichero, escritorFichero, coleccionAnuncios);
            
        } else if (instruccionActual == "E") {

            instrE(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "EC") {

            //instrEC(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "B") {

            instrB(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "BC") {

            instrBC(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "P") {

            instrP(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "LO") {

            //instrLO(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "LC") {

            //instrLC(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "LT") {

            //instrLT(lectorFichero, escritorFichero, coleccionAnuncios);

        }
        

    }

    lectorFichero.close();
    escritorFichero.close();

    return 0;

}

//-----------------------------------------------------------------------------------------------------A
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
    o:
        NO INTRODUCIDO: ID40:::Maleta pequeña:::En venta:::Maleta con ruedas, pequeña, buen estado.:::2026-09-20:::2026-09-01
    }
    IMPORTANTE: consume el ultimo \n tambien, cuando vuelva de intrA() el siguiente caracter a leer sera la siguiente intruccion

*/
// el caracter A ha sido consumido.
void instrA( ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c ){

    //las siguientes 6 lineas contendran la informacion en el orden:
    //id, titulo, descripcion, categoria, publicacion, finalizacion
    string id, tit, desc, cat;
    Fecha startDate, endDate;

    getline(lectorFichero, id);   //!! getline hace un ignore del \n
    getline(lectorFichero, tit);
    getline(lectorFichero, desc);
    getline(lectorFichero, cat);

    //ahora la fecha de publicacion
    string ano1, mes1, dia1;
    getline(lectorFichero, ano1, '-');  //tb consume el separador
    getline(lectorFichero, mes1, '-');
    getline(lectorFichero, dia1);
    bool errorFecha;
    crear(stoi(dia1), stoi(mes1), stoi(ano1), startDate, errorFecha);

    //ahora la fecha de finalizacion
    string ano2, mes2, dia2;
    getline(lectorFichero, ano2, '-');  //tb consume el separador
    getline(lectorFichero, mes2, '-');
    getline(lectorFichero, dia2);
    crear(stoi(dia2), stoi(mes2), stoi(ano2), endDate, errorFecha);
    
    if(!esta(id, c)){   // si no esta ya, se añade
        Anuncio a = crearAnuncio(id, tit, desc, cat, startDate, endDate);
        anadir(c, a);
        escritorFichero << "INTRODUCIDO: ";

    }else{  //si ya estaba, no se añade
        escritorFichero << "NO INTRODUCIDO: ";
    }
    //identificador, título, categoría, descripción, fecha de publicación y fecha de finalización
    escritorFichero
        << id << ":::"
        << tit << ":::"
        << cat << ":::"
        << desc << ":::"
        << ano1 << "-" << mes1 << "-" << dia1 << ":::"
        << ano2 << "-" << mes2 << "-" << dia2 << endl;
}

//-----------------------------------------------------------------------------------------------------C
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
    o:
        NO CAMBIADO: ID40
    }
    IMPORTANTE: consume el ultimo \n tambien, cuando vuelva de intrC() el siguiente caracter a leer sera la siguiente intruccion

*/
// el caracter C ha sido consumido.
void instrC( ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c ){

    //las siguientes 6 lineas contendran la informacion en el orden:
    //id, titulo, descripcion, categoria, publicacion, finalizacion
    string id, tit, desc, cat;
    Fecha startDate, endDate;

    getline(lectorFichero, id);   //!! getline hace un ignore del \n
    
    if(esta(id, c)){    //si esta ya, se cambia

        getline(lectorFichero, tit);
        getline(lectorFichero, desc);
        getline(lectorFichero, cat);

        //ahora la fecha de publicacion
        string ano1, mes1, dia1;
        getline(lectorFichero, ano1, '-');  //tb consume el separador
        getline(lectorFichero, mes1, '-');
        getline(lectorFichero, dia1);
        bool errorFecha;
        crear(stoi(dia1), stoi(mes1), stoi(ano1), startDate, errorFecha);

        //ahora la fecha de finalizacion
        string ano2, mes2, dia2;
        getline(lectorFichero, ano2, '-');  //tb consume el separador
        getline(lectorFichero, mes2, '-');
        getline(lectorFichero, dia2);
        crear(stoi(dia2), stoi(mes2), stoi(ano2), endDate, errorFecha);

        Anuncio a = crearAnuncio(id, tit, desc, cat, startDate, endDate);
        anadir(c, a);

        //identificador, título, categoría, descripción, fecha de publicación y fecha de finalización
        escritorFichero << "CAMBIADO: "
            << id << ":::"
            << tit << ":::"
            << cat << ":::"
            << desc << ":::"
            << ano1 << "-" << mes1 << "-" << dia1 << ":::"
            << ano2 << "-" << mes2 << "-" << dia2 << endl
        ;

    }else{  //si no estaba, no se puede cambiar
        escritorFichero << "NO CAMBIADO: "
             << id << endl;
    }
}

//-----------------------------------------------------------------------------------------------------E
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
    IMPORTANTE: consume el ultimo \n tambien, cuando vuelva de intrE() el siguiente caracter a leer sera la siguiente intruccion
*/
// el caracter E ha sido consumido.
void instrE( ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c ){
    
    //la siguiente linea contendran el id
    string id;
    getline(lectorFichero, id);   //!! getline hace un ignore del \n
    if(esta(id, c)){   // si esta, existente
        escritorFichero << "EXISTENTE: ";

    }else{  //si no, no existente
        escritorFichero << "DESCONOCIDO: ";
    }
    escritorFichero << id << endl;
}

//-----------------------------------------------------------------------------------------------------B
/*
    Por cada instrucción de tipo “B”, si existía algún anuncio en la colección con un identificador igual al dado y este
    es borrado de la colección, se escribirá una línea que empiece con la cadena “BORRADO: ”, y si no existía ningún
    anuncio en la colección con un identificador igual al dado o este no es borrado de la colección, se escribirá en el
    fichero una línea que empiece con la cadena “NO BORRADO: ”. En cualquiera de los dos casos, se seguirá
    escribiendo a continuación, y en la misma línea del fichero, el identificador dado para la instrucción.

    EJEMPLO{
    IN:
        B
        ID25
    
    OUT:
        BORRADO: ID25
    o:
        NO BORRADO: ID25
    }
    IMPORTANTE: consume el ultimo \n tambien, cuando vuelva de intrB() el siguiente caracter a leer sera la siguiente intruccion
*/
// el caracter B ha sido consumido.
void instrB( ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c ){
    
    //la siguiente linea contendran el id
    string id;
    getline(lectorFichero, id);   //!! getline hace un ignore del \n
    if(esta(id, c)){   // si esta, se borra
        borrar(id,c);
        
        if(!esta(id,c)){//si no esta ya, se ha borrado correctamente
            escritorFichero << "BORRADO: ";
        }else{          //si sigue estando, no se ha borrado correctamente
            escritorFichero << "NO BORRADO: ";
        }

    }else{  //si no esta, no se puede borrar
        escritorFichero << "NO BORRADO: ";
    }
    escritorFichero << id << endl;
}

// -----------------------------------------------------------------------------------------------------

/*

    Por cada instrucción de tipo “BC”, si existían anuncios en la colección con categoría igual a la dada, se escribirá
    una línea que empiece con la cadena “ELIMINADOS: ”, si no existía ningún anuncio en la colección con categoría
    igual a la dada, se escribirá una línea que empiece con la cadena “NO ELIMINADOS: ”. En ambos casos, la
    cadena escrita irá seguida a continuación, y en la misma línea del fichero, por la categoría dada para la instrucción.

    Cuando se procese una instrucción “BC”, el programa deberá eliminar de la colección todos los anuncios cuya
    categoría sea igual a la dada.

*/
void instrBC(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c) {

    lectorFichero.ignore();

    string categoria;
    getline(lectorFichero, categoria); // Lectura de la categoría a buscar

    if(existeTema(categoria, c)) {

        zanjarTema(categoria, c);

        escritorFichero << "ELIMINADOS: " << categoria << endl;

    } else {

        escritorFichero << "NO ELIMINADOS: " << categoria << endl;

    }

}

// -----------------------------------------------------------------------------------------------------

/*

    Por  cada  instrucción  de  tipo  “P”,  si  existían  anuncios  en  la  colección  con  fecha  de  publicación  estrictamente  
    anterior a la dada, se escribirá una línea que empiece con la cadena “PURGADOS: ”, si no existía ningún anuncio 
    en la colección con fecha de publicación estrictamente anterior a la dada, se escribirá una línea que empiece con la 
    cadena “NO PURGADOS: ”. En ambos casos, la cadena escrita irá seguida a continuación, y en la misma línea 
    del fichero, por la fecha utilizada en la operación (formato: aaaa-mm-dd ).

*/
void instrP(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c) 
{  
    lectorFichero.ignore();     // Consume el \n

    // Obtenemos la fecha para purgar
    string ano, mes, dia;
    Fecha fechaPurgar;

    //Se consume también el separador
    getline(lectorFichero, ano, '-'); 
    getline(lectorFichero, mes, '-');
    getline(lectorFichero, dia);

    bool errorFecha;
    crear(stoi(dia), stoi(mes), stoi(ano), fechaPurgar, errorFecha);

    string obsoletosString; //si se llama obsoletos (igual que la funcion) confunde al compilador
    
    obsoletosString = obsoletos(fechaPurgar, ":::", c);

    if (obsoletosString != "")
    {
        purgar(fechaPurgar, c);

        escritorFichero << "PURGADOS: " << ano << "-" << mes << "-" << dia << endl;
    }

    else 
    {
        escritorFichero << "NO PURGADOS: " << ano << "-" << mes << "-" << dia << endl;
    }
}

// -----------------------------------------------------------------------------------------------------

/*

    Por cada instrucción de tipo “LO”, se escribirá una línea que empiece con la cadena “ANTERIORES A: ” seguida 
    de la fecha utilizada en la operación (con formato: aaaa-mm-dd), seguida de la cadena “ --- ”, seguida por la 
    concatenación de los identificadores de los anuncios de la colección con fecha de publicación estrictamente anterior 
    a la dada, separados entre sí por la cadena “:::”. Para finalizar, se concatenará otra vez la cadena “ --- ”.

*/
void instrLO(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c) 
{

}

// -----------------------------------------------------------------------------------------------------

/*

    Por cada instrucción de tipo “LC”, se escribirá una línea que empiece con la cadena “DE CATEGORIA: ” seguida
    de la categoría utilizada con la operación, seguida de la cadena “ --- ”, seguida por la concatenación de los
    identificadores de los anuncios de la colección con categoría igual a la dada, separados entre sí por la cadena “:::”.
    Antes de finalizar la línea se concatenará otra vez la cadena “ --- ”. 

*/
void instrLC(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c) {

}

// -----------------------------------------------------------------------------------------------------

/*

    Por cada instrucción de tipo “LT”, se escribirá una primera línea con la cadena “-----LISTADO: ”, seguida
    del número total de anuncios registrados en la colección, y a continuación, por cada anuncio almacenado en la
    colección, y siguiendo el orden (lexicográfico) creciente según el identificador, se escribirá otra línea con la
    información de todos los datos relativos al anuncio en la colección, de acuerdo al formato que se describe a
    continuación:
    [ identificador -de-> categoría ;;; título ] (publicado) --- descrip --- (finaliza)
    siendo identificador, categoría, título y descrip, respectivamente el identificador, la categoría, el
    título y la descripción del anuncio, y siendo publicado y finaliza respectivamente las fechas de publicación y
    de finalización del anuncio, con dichas fechas escritas en formato: aaaa-mm-dd. El listado finalizará con una línea
    con la cadena “-----”. 

*/
void instrLT(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c) {

}

// -----------------------------------------------------------------------------------------------------