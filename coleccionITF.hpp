/* NOMBRES Y NIPS ---- David Maza Luengo 956269
*/

#ifndef COLECCIONITF_HPP
#define COLECCIONITF_HPP

#include "fecha.hpp"
#include "anuncio.hpp"
#include <string>
using namespace std;

// PREDECLARACION DEL TAD GENERICO coleccionITF--------------------------------------------------------------------------

//usa booleanos, naturales, cadenas, fechas

/* 
   Los valores del TAD coleccionITF representan una colleción de Items Temáticos Fechados (T),
   con identificadores no repetidos, guardando estos en la agrupación de forma ordenada lexicográficamente.
   Además cuenta con un iterador para recorrer en orden la colección. 
   
   Los Items Temáticos Fechados T necesitan de las siguientes operaciones:
    identificador: devuelve un string con el identificador del item
    tema: devuelve una cadena con el tema del Item
    fecha: devuelve un tipo fecha asociada al Item
*/
template<typename T> struct ColeccionITF;

//operaciones--------------------------------------------------------------------------------------

/*
    Crea una colección de ITF vacía, sin ítems.
*/
template<typename T> void crear(ColeccionITF<T> &c);
 

/*
    Si en c no hay ningún ítem con identificador igual al de i, devuelve una colección igual a la
    resultante de añadir el ítem i a la colección c. En caso contrario, devuelve una colección igual a c.
*/
template<typename T> void anadir(ColeccionITF<T> &c, const T &i);


/*
    Si en c no hay ningún ítem con identificador igual al de i, devuelve una colección igual a c. En
    caso contrario, devuelve una colección igual a la resultante de sustituir en c el ítem que tenía
    identificador igual al de i, por el ítem i.
*/
template<typename T> void actualizar(ColeccionITF<T> &c, const T &i);


/*
    Si en c hay algún ítem con identificador igual a ident, devuelve una colección igual a la
    resultante de borrar ese ítem de la colección c. En caso contrario, devuelve una colección igual a c.
*/
template<typename T> void borrar(const string &ident, ColeccionITF<T> &c);


/*
    Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a ident.
*/
template<typename T> bool esta(const string &ident, const ColeccionITF<T> &c);


/*
    Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
    PARCIAL: operación no definida si en c no hay ningún ítem con identificador igual a ident.
*/
template<typename T> T obtenerITF(const string &ident, const ColeccionITF<T> &c);


/*
    Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
    con fecha estrictamente anterior a f, y separados entre sí por la cadena separador.
*/
template<typename T> string obsoletos(const Fecha &f, const string &separador, const ColeccionITF<T> &c);
 

/*
    Devuelve una colección igual a la resultante de eliminar de c todos los ítems con fecha
    estrictamente anterior a f.
*/
template<typename T> void purgar(const Fecha &f, ColeccionITF<T> &c);


/*
    Devuelve verdad si y sólo si en c hay algún ítem i con tema igual a t.
*/
template<typename T> bool existeTema(const string &t, const ColeccionITF<T> &c);


/*
    Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
    con tema igual a t, y separados entre sí por la cadena separador.
*/
template<typename T> string delTema(const string &t, const string &separador, const ColeccionITF<T> &c);


/*
    Devuelve una colección igual a la resultante de eliminar de c todos los ítems i cuyo tema es igual a t.
*/
template<typename T> void zanjarTema(const string &t, ColeccionITF<T> &c);



/*
    Devuelve verdad si y sólo si c no contiene ningún ítem.
*/
template<typename T> bool esVacia(const ColeccionITF<T> &c);


/*
    Devuelve el número de ítems que hay en la colección c.
*/
template<typename T> int tamano(const ColeccionITF<T> &c);


//OPERACIONES DEL ITERADOR-----------------------------------------------------------
/*
Las siguientes operaciones constituyen un iterador que permite visitar los elementos de la
colección de forma que siempre se visiten antes los elementos con identificador anterior (i.e.
lexicográficamente menor) a los que se visitarán más tarde:
*/

/*
    Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente
    ítem a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no
    haber visitado ningún ítem).
*/
template<typename T> void iniciarIterador(ColeccionITF<T> &c);


/*
    Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c, devuelve
    falso si ya se ha visitado el último ítem.
*/
template<typename T> bool existeSiguiente(const ColeccionITF<T> &c);


/*
parcial siguiente: colecciónITF c  ITF
{Devuelve el siguiente ítem a visitar con el iterador de la colección c.
Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c)).}

parcial avanza: colecciónITF c  colecciónITF
{Prepara el iterador de la colección c para que se pueda visitar el siguiente ítem, entendiendo
por siguiente aquel ítem con (lexicográficamente) menor identificador de los todavía no
visitados.
Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c)).}

COMBINADAS de manera NO PARCIAL en "siguienteYavanza".
*/

/*
    Devuelve por e el siguiente elemento de la coleccionITF c. Además intenta avanza el iterador
    y devuelve true si y solo si el iterador ha podido avanzar.
*/
template<typename T> bool siguienteYavanza(ColeccionITF<T> &c, T &e);


// FIN predeclaracion del TAD GENERICO coleccionITF (Fin INTERFAZ)============================================================================



// DECLARACION DEL TAD GENERICO coleccionITF
template<typename T> struct ColeccionITF{

    friend void crear<T>(ColeccionITF<T> &c);
    friend void anadir<T>(ColeccionITF<T> &c, const T &i);
    friend void actualizar<T>(ColeccionITF<T> &c, const T &i);
    friend void borrar<T>(const string &ident, ColeccionITF<T> &c);
    friend bool esta<T>(const string &ident, const ColeccionITF<T> &c);
    friend T obtenerITF<T>(const string &ident, const ColeccionITF<T> &c);
    friend string obsoletos<T>(const Fecha &f, const string &separador, const ColeccionITF<T> &c);
    friend void purgar<T>(const Fecha &f, ColeccionITF<T> &c);
    friend bool existeTema<T>(const string &t, const ColeccionITF<T> &c);
    friend string delTema<T>(const string &t, const string &separador, const ColeccionITF<T> &c);
    friend void zanjarTema<T>(const string &t, ColeccionITF<T> &c);
    friend bool esVacia<T>(const ColeccionITF<T> &c);
    friend int tamano<T>(const ColeccionITF<T> &c);

    friend void iniciarIterador<T>(ColeccionITF<T> &c);
    friend bool existeSiguiente<T>(const ColeccionITF<T> &c);
    friend bool siguienteYavanza<T>(ColeccionITF<T> &c, T &e);


    private: //declaracion de la representacion interna del tipo
       /*
        Lista enlazada en memoria dinámica.
        "primero" es un puntero apunta al primer nodo de la lista. Si la colección está vacía apuntará a NIL.
        "nElem" lleva la cuenta de cuantos elementos hay en la colección.
        "iter" es un puntero que servirá como iterador ÚNICAMENTE para las operaciones de este.

        "Nodo" es un contenedor para el tipo de dato T y un puntero sig que apunte al siguiente Nodo de la lista. Si
        no hay más elementos, sig apuntará a NIL.
        */
        struct Nodo{
            T dato;
            Nodo* sig;
        };
        
        Nodo* primero;
        int nElem;
        //CAMPOS ITERADOR
        Nodo* iter;

};


//IMPLEMENTACION DE LAS OPERACIONES DEL TAD GENERICO coleccionITF=============================================================================

/*
    Crea una colección de ITF vacía, sin ítems.
*/
template<typename T>
void crear(ColeccionITF<T> &c){

/////////////////////////////////////////////
}


/*
    Si en c no hay ningún ítem con identificador igual al de i, catualiza c a una colección igual a la
    resultante de añadir (oredenadamente) el ítem i a la colección c inicial.
    En caso contrario, devuelve una colección igual a c.
    Además actualizara nElem apropiadamente.
*/
template<typename T> void anadir(ColeccionITF<T> &c, const T &i){
    
    string ident = suIdentificador(i);

    if( c.primero == nullptr || suIdentificador(c.primero->dato) > ident ){ //si es lista vacia o el primero es mayor, INSERCION AL PRINCIPIO
        //IMPORTANTE! EVAL. CORTOCIRCUITADA: si c.primero == nullptr no evaluará c.primero->dato con lo que no hara accesos indebidos
        c.nElem++;
        Nodo* nuevoElem = new Nodo;
        nuevoElem->dato = i;
        nuevoElem->sig = c.primero;
        c.primero = nuevoElem;
        

    }else if(suIdentificador(c.primero->dato) == ident){ //si el primero == i volvemos sin hacer nada
        return;
    
    }else{  //si no (primero.dato < i), otro punto de inserción(ENTRE MEDIO O FINAL)

        //se necesitan dos punteros oruga, para saber la direccion de ambos elementos adyacentes al que vayamos a insertar.
        //(Al ser enlazada unidireccional no podemos ir hacia atrás)
        Nodo * pAux = c.primero;
        Nodo * pSig = pAux->sig;

        while(pSig != nullptr){ //mientras el pAux no sea el ultimo
            //sabemos que pAux.dato es menor estricto que i

            if(suIdentificador(pSig->dato) > ident){ //si el siguiente.dato > i: insertar antes de pSig y fin
                c.nElem++;
                Nodo* nuevoElem = new Nodo;
                nuevoElem->dato = i;
                nuevoElem->sig = pSig;
                pAux->sig = nuevoElem;
                return;
            }else if(suIdentificador(pSig->dato) == ident){ //si el siguiente.dato == i acabamos sin hacer nada
                return;
            }
            //avanzamos punteros de recorrido
            pAux = pSig;
            pSig = pAux->sig;
        }
        //si sale es que (pAux->dato = ultimo elem) < i -> INSERCIÓN AL FINAL y fin
        c.nElem++;
        Nodo* nuevoElem = new Nodo;
        nuevoElem->dato = i;
        nuevoElem->sig = pSig; // = nullptr
        pAux->sig = nuevoElem;
    }
}




//AQUI VA ACTUALIZAR-----------------------------------------------------------------------------------------!!!!!!!!





/*
    Si en c hay algún ítem con identificador igual a ident, actualiza la collecion c a una coleccion igual
    pero sin ese ítem. En caso contrario, c se queda como está.

    También se encarga de actualizar nElem y resuelve posibles casos conflictivos con el iterador
    Ejemplo: [   si ">X<" es el iterador: (1 >2< 3 4 5 6) y borramos el 2 --> (1 >3< 4 5 6)   ]
*/
template<typename T> void borrar(const string &ident, ColeccionITF<T> &c){

    if(c.primero == nullptr){   //si LISTA VACÍA, no hacemos nada
        return;                 //fin

    }else if(suIdentificador(c.primero->dato) == ident){  //si EL PRIMERO YA ES IGUAL: borrar el primero y fin

        Nodo * pKiller = c.primero;    //puntero mercenario apunta al objetivo para poder reasignar c.primero sin perder la direccion
        //COMPROBAR ITERADOR!!
        if(c.iter == pKiller){      //si el iterador esta en el elemento a borrar, mover el iterador al siguiente elem por visitar.
            c.iter = pKiller->sig;  //si ">X<" es el iterador: (1 >2< 3 4 5 6) y borramos el 2 -> (1 2 >3< 4 5 6) -> (1 >3< 4 5 6)
            //si la lista era de tamaño 1 el iterador pasará a ser NIL y las operaciones de este sabrán que ha terminado.
        }
        c.primero = pKiller->sig;      //el nuevo primero es el que fue segundo
        delete pKiller;                //matas al elem en el puntero mercenario
        c.nElem--;                     //hay 1 elemento menos
        


        return;                     //fin

    }else{  //seguir buscando un igual mas adelante en la lista con oruga de dos punteros
            //(Dos para poder actualizar los adyacentes al que borremos) (Al ser enlazada unidireccional no podemos ir hacia atrás)
        Nodo * pAux = c.primero;
        Nodo * pSig = pAux->sig;
        while(pSig != nullptr){ //mientras el pAux no sea el ultimo
            
            //sabemos que pAux->dato != ident
            if(suIdentificador(pSig->dato) == ident){ //el SIGUIENTE ES EL QUE BUSCAMOS: borrar pSig y fin
                
                //COMPROBAR ITERADOR!!
                if(c.iter == pSig){      //si el iterador esta en el elemento a borrar, mover el iterador al siguiente elem por visitar.
                    c.iter = pSig->sig;  //si ">X<" es el iterador: (1 >2< 3 4 5 6) y borramos el 2 -> (1 2 >3< 4 5 6) -> (1 >3< 4 5 6)
                    //si *pSig es el ultimo elem el iterador pasará a ser NIL y las operaciones de este sabrán que ha terminado.
                }
                pAux->sig = pSig->sig;  //el anterior apunta al siguiente de pSig
                delete pSig;            //borras el elem en pSig
                c.nElem--;              //hay 1 elem menos
                return;                 //fin

            }else{
                //actualizar oruga de punteros
                pAux = pSig;
                pSig = pAux->sig;
            }
        }
        //si sale ya ha evaluado todos los elem y no ha encontrado el elemento "ident": FIN
    }
}


//etc......................................................................................................



/*
    Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente
    ítem a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no
    haber visitado ningún ítem).
*/
template<typename T> void iniciarIterador(ColeccionITF<T> &c){


}


/*
    Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c, devuelve
    falso si ya se ha visitado el último ítem.
*/
template<typename T> bool existeSiguiente(const ColeccionITF<T> &c){


}


/*
    Devuelve por e el siguiente elemento de la coleccionITF c. Además intenta avanza el iterador
    y devuelve true si y solo si el iterador ha podido avanzar.
*/
template<typename T> bool siguienteYavanza(ColeccionITF<T> &c, T &e){


}


#endif //fin de coleccionITF.hpp