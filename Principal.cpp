/* 
_798618_956306_956269

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
int main () {

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

            instrO(lectorFichero, escritorFichero, coleccionAnuncios);
            
        } else if (instruccionActual == "E") {

            instrE(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "EC") {

            instrEC(lectorFichero, escritorFichero, coleccionAnuncios);

        }
        /*
        else if (instruccionActual == "B") {

            instrB(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "BC") {

            instrBC(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "P") {

            instrP(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "LO") {

            instrLO(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "LC") {

            instrLC(lectorFichero, escritorFichero, coleccionAnuncios);

        } else if (instruccionActual == "LT") {

            instrLT(lectorFichero, escritorFichero, coleccionAnuncios);

        }
        */

    }

    lectorFichero.close();
    escritorFichero.close();

    return 0;

}

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

*/
// el caracter A tiene que haber sido consumido, pero el /n no.
void instrA( ifstream &fin, ofstream &fout, ColeccionITF<Anuncio> &c ){

    fin.ignore();   //CONSUMIMOS EL \n
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

        //COMPROBAR SI SON FECHAS VALIDAS????????????????????????????????????????????? - Abel: Yo diría que no, pero lo apunto como pregunta para la mujer.
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
*/
// el caracter A tiene que haber sido consumido, pero el /n no.
void instrE( ifstream &fin, ofstream &fout, ColeccionITF<Anuncio> &c ){
    
    fin.ignore();   //CONSUMIMOS EL \n
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

// -----------------------------------------------------------------------------------------------------

/*
    Por cada instrucción de tipo “O”, si existe algún anuncio en la colección con el identificador dado, se escribirá una
    línea que empiece con la cadena “LOCALIZADO: ”, seguida de la concatenación de todos los datos de la
    información del anuncio localizado en la colección, en la misma línea del fichero y en el siguiente orden:
    identificador, título, categoría, descripción, fecha de publicación y fecha de finalización (separados entre sí por la
    cadena “:::”, y con las fechas escritas en formato: aaaa-mm-dd).
    Si no existía ningún anuncio en la colección con identificador igual al dado, se escribirá en el fichero una línea que
    empiece con la cadena “NO LOCALIZADO: ”, seguida del identificador dado para la instrucción.

    // La siguiente linea contiene el identificador del anuncio sobre el que se actúa.

    Cuando se procese una instrucción “O”, el programa intentará obtener toda la
    información relativa al anuncio registrado en la colección con el identificador dado

*/
void instrO(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c) {

    lectorFichero.ignore();

    string id;
    getline(lectorFichero, id);

    // Si el anuncio no se encuentra en la colección, se imprime el mensaje que informa de ello
    // y se sale de la función.
    if(!esta(id, c)) {

        escritorFichero << "NO LOCALIZADO: " << id << endl;
        return;

    }

    Anuncio anuncioAMostrar = obtenerITF(id, c);

    Fecha fechaPublicacion = suPublicacion(anuncioAMostrar);
    Fecha fechaFinalizacion = suFinalizacion(anuncioAMostrar);

    escritorFichero << "LOCALIZADO: "
        << id << ":::"
        << suTitulo(anuncioAMostrar) << ":::"
        << suCategoria(anuncioAMostrar) << ":::"
        << suDescripcion(anuncioAMostrar) << ":::"
        << anyo(fechaPublicacion) << '-' << mes(fechaPublicacion) << '-' << anyo(fechaPublicacion) << ":::"
        << anyo(fechaFinalizacion) << '-' << mes(fechaFinalizacion) << '-' << anyo(fechaFinalizacion)
        << endl;

}

// -----------------------------------------------------------------------------------------------------

/*

    Por cada instrucción de tipo “EC”, si existe algún anuncio en la colección con una categoría igual a la dada para la
    instrucción, se escribirá una línea que empiece con la cadena “CATEGORIA CONOCIDA: ”, y si no existía
    ningún anuncio en la colección con categoría igual a la dada, se escribirá en el fichero de salida una línea con la
    cadena “CATEGORIA DESCONOCIDA: ”. En cualquiera de los dos casos, se seguirá escribiendo a continuación,
    y en la misma línea del fichero, la categoría dada para la instrucción.

    Cuando se procese la instrucción “EC”, el programa comprobará si en la colección existe algún anuncio con categoría igual a la dada

    La siguiente línea del fichero contendrá la categoría de los anuncios respecto a la cual se actúa o consulta.

*/
void instrEC(ifstream &lectorFichero, ofstream &escritorFichero, ColeccionITF<Anuncio> &c){

    lectorFichero.ignore();

    string categoria;
    getline(lectorFichero, categoria);

    if(existeTema(categoria, c)) {

        escritorFichero << "CATEGORIA CONOCIDA: " << categoria << endl;

    } else {

        escritorFichero << "CATEGORIA DESCONOCIDA: " << categoria << endl;

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
    string ano1, mes1, dia1;

    //Se consume también el separador
    getline(fin, ano1, '-'); 
    getline(fin, mes1, '-');
    getline(fin, dia1);

    

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