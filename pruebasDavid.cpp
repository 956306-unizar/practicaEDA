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
void instrA( ifstream &fin, ofstream &fout, ColeccionITF<Anuncio> &c ){

    fin.ignore();   //CONSUMIMOS EL \n-------------------------------------------------------------------?? DEPENDE DE LA IMPLEMENTACION DEL BUCLE DE LECTURA
    //las siguientes 6 lineas contendran la informacion en el orden:
    //id, titulo, descripcion, categoria, publicacion, finalizacion
    string id, tit, desc, cat;
    Fecha startDate, endDate;

    getline(fin, id);   //!! getline hace un ignore del \n
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
    //COMPROBAR SI SON FECHAS VALIDAS?????????????????????????????????????????????(errorFinal, errorPubli)
    
    if(!esta(id, c)){   // si no esta ya, se añade
        Anuncio a = crearAnuncio(id, tit, desc, cat, startDate, endDate);
        anadir(c, a);
        fout << "INTRODUCIDO: ";

    }else{  //si ya estaba, no se añade
        fout << "NO INTRODUCIDO: ";
    }

    fout << id << ":::"
         << tit << ":::"
         << desc << ":::"
         << cat << ":::"
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
void instrE( ifstream &fin, ofstream &fout, ColeccionITF<Anuncio> &c ){
    
    fin.ignore();   //CONSUMIMOS EL \n-------------------------------------------------------------------?? DEPENDE DE LA IMPLEMENTACION DEL BUCLE DE LECTURA
    //la siguiente linea contendran el id
    string id;
    getline(fin, id);   //!! getline hace un ignore del \n
    if(esta(id, c)){   // si esta, existente
        fout << "EXISTENTE: ";

    }else{  //si no, no existente
        fout << "DESCONOCIDO: ";
    }
    fout << id << endl;
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
void instrB( ifstream &fin, ofstream &fout, ColeccionITF<Anuncio> &c ){
    
    fin.ignore();   //CONSUMIMOS EL \n-------------------------------------------------------------------?? DEPENDE DE LA IMPLEMENTACION DEL BUCLE DE LECTURA
    //la siguiente linea contendran el id
    string id;
    getline(fin, id);   //!! getline hace un ignore del \n
    if(esta(id, c)){   // si esta, se borra
        borrar(id,c);
        fout << "BORRADO: ";

    }else{  //si no esta, no se puede borrar
        fout << "NO BORRADO: ";
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

    string id = "ID0";
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
            << "2) añadir anuncio con ID ordenado" << endl
            << "3) borrar anuncio segun ID" << endl
            << "4) añadir anuncio con ID persolanizado" << endl
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
            case 2:{   //añadir anuncio por orden
                
                id = "ID" + to_string(contador);
                a1 = crearAnuncio(id, "Producto 1(tit)", "Descripcion del producto 1(desc)", "Ropa(cat)", ini, fin);
                anadir(col,a1);
                cout << "anuncio " << id << " añadido" << endl;
                contador++;

                break;
            }
            case 3:{   //eliminar producto
                
                string ident;
                cout << "Introduce ID a borrar:";
                cin >> ident;
                borrar(ident, col);
                break;
            }
            case 4:{   //añadir anuncio id personalizado
                
                cout << "Introduce el id personalizado: ";
                cin >> id;
                a1 = crearAnuncio(id, "Producto 4(tit)", "Descripcion del producto 4(desc)", "Ropa4(cat)", ini, fin);
                anadir(col,a1);
                cout << "anuncio " << id << " añadido" << endl;

                break;
            }
            default:{
                break;
            }
        }
    }while(opcion != 0);


}