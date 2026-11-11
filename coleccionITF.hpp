/* ---- NOMBRES Y NIPS ----
    Arián Lajara Bueno - 798618
    Abel Martínez Zárate - 956306
    David Maza Luengo - 956269
*/

#ifndef COLECCIONITF_HPP
#define COLECCIONITF_HPP

#include "fecha.hpp"
#include <string>
using namespace std;

// PREDECLARACION DEL TAD GENERICO coleccionITF--------------------------------------------------------------------------

//usa booleanos, naturales, cadenas, fechas

/* 
   Los valores del TAD coleccionITF representan una colleción de Items Temáticos Fechados (T),
   con identificadores no repetidos, guardando estos en la agrupación de forma ordenada lexicográficamente.
   Además cuenta con un iterador para recorrer en orden la colección. 
   
   Los Items Temáticos Fechados T necesitan de las siguientes operaciones:
    -identificador: devuelve un string con el identificador del item
        string identificador(const T &i);

    -tema: devuelve una cadena con el tema del Item
        string tema(const T &i);

    -fecha: devuelve un tipo fecha asociada al Item
        Fecha fecha(const T &i);
*/
template<typename T> struct ColeccionITF;

//operaciones--------------------------------------------------------------------------------------

/*
    Prepara la colleccion c para poder usarse. Importante llamar a crear() antes de empezar a usarla.
*/
template<typename T> void crear(ColeccionITF<T> &c);
 

/*
    Si en c no hay ningún ítem con identificador igual al de i, en c se añade el item i.
    En caso contrario, c no se modifica.
*/
template<typename T> void anadir(ColeccionITF<T> &c, const T &i);


/*
    Si en c no hay ningún ítem con identificador igual al de i, c no se modifica.
    En caso contrario, sustituye en c el ítem que tenía identificador igual al de i, por el ítem i.
*/
template<typename T> void actualizar(ColeccionITF<T> &c, const T &i);


/*
    Si en c hay algún ítem con identificador igual a ident, elimina ese item de c.
    En caso contrario, c no se modifica.
*/
template<typename T> void borrar(const string ident, ColeccionITF<T> &c);


/*
    Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a ident.
*/
template<typename T> bool esta(const string ident, const ColeccionITF<T> &c);


/*
    Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
    PARCIAL: operación no definida si en c no hay ningún ítem con identificador igual a ident.
*/
template<typename T> T obtenerITF(const string ident, const ColeccionITF<T> &c);


/*
    Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
    con fecha estrictamente anterior a f, y separados entre sí por la cadena separador.
*/
template<typename T> string obsoletos(const Fecha &f, const string separador, const ColeccionITF<T> &c);
 

/*
    Elimina de c todos los ítems con fecha estrictamente anterior a f.
*/
template<typename T> void purgar(const Fecha &f, ColeccionITF<T> &c);


/*
    Devuelve verdad si y sólo si en c hay algún ítem i con tema igual a t.
*/
template<typename T> bool existeTema(const string t, const ColeccionITF<T> &c);


/*
    Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
    con tema igual a t, y separados entre sí por la cadena separador.
*/
template<typename T> string delTema(const string t, const string separador, const ColeccionITF<T> &c);


/*
    Elimina de c todos los ítems i cuyo tema es igual a t.
*/
template<typename T> void zanjarTema(const string t, ColeccionITF<T> &c);



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
    ítem a visitar sea el que tiene el identificador (lexicográficamente) más pequeño de todo c
    (situación de no haber visitado ningún ítem).
*/
template<typename T> void iniciarIterador(ColeccionITF<T> &c);


/*
    Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c, devuelve
    falso si ya se ha visitado el último ítem.
*/
template<typename T> bool existeSiguiente(const ColeccionITF<T> &c);


/*
    Si existe un elemento por visitar en c devuelve verdadero, devuelve dicho elemento por e y avanza el iterador.
    Si no, devuelve falso.
*/
template<typename T> bool siguienteYavanza(ColeccionITF<T> &c, T &e);


// FIN predeclaracion del TAD GENERICO coleccionITF (Fin INTERFAZ)============================================================================




// DECLARACION DEL TAD GENERICO coleccionITF
template<typename T> struct ColeccionITF{

    friend void crear<T>(ColeccionITF<T> &c);
    friend void anadir<T>(ColeccionITF<T> &c, const T &i);
    friend void actualizar<T>(ColeccionITF<T> &c, const T &i);
    friend void borrar<T>(const string ident, ColeccionITF<T> &c);
    friend bool esta<T>(const string ident, const ColeccionITF<T> &c);
    friend T obtenerITF<T>(const string ident, const ColeccionITF<T> &c);
    friend string obsoletos<T>(const Fecha &f, const string separador, const ColeccionITF<T> &c);
    friend void purgar<T>(const Fecha &f, ColeccionITF<T> &c);
    friend bool existeTema<T>(const string t, const ColeccionITF<T> &c);
    friend string delTema<T>(const string t, const string separador, const ColeccionITF<T> &c);
    friend void zanjarTema<T>(const string t, ColeccionITF<T> &c);
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
       //llamar a nodos asi: typename ColeccionITF<T>::Nodo
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
void crear(ColeccionITF<T> &c)
{
    c.primero = nullptr;
    c.nElem = 0;
    c.iter = nullptr;
}


/*
    Si en c no hay ningún ítem con identificador igual al de i, en c se añade el item i.
    En caso contrario, c no se modifica.
    Además actualizara nElem apropiadamente.
*/
template<typename T> void anadir(ColeccionITF<T> &c, const T &i)
{    
    string ident = identificador(i);

    // Si es lista vacia o el primero es mayor, INSERCION AL PRINCIPIO
    //IMPORTANTE! EVAL. CORTOCIRCUITADA: si c.primero == nullptr no evaluará c.primero->dato con lo que no hara accesos indebidos
    if (c.primero == nullptr || identificador(c.primero->dato) > ident)
    {
        c.nElem++;
        typename ColeccionITF<T>::Nodo* nuevoElem = new typename ColeccionITF<T>::Nodo;
        nuevoElem->dato = i;
        nuevoElem->sig = c.primero;
        c.primero = nuevoElem;   
    }
    
    // En este caso estaremos ante una lista NO vacía y una lista donde NO vamos a insertar al inicio. 
    else if (identificador(c.primero->dato) < ident)    //sabemos que no es mayor, y si es igual no hay que añadir
    {
        // Se necesitan dos punteros oruga, para saber la direccion de ambos elementos adyacentes al que vayamos a insertar.
        // (Al ser enlazada unidireccional no podemos ir hacia atrás)
        typename ColeccionITF<T>::Nodo* pAux = c.primero;
        typename ColeccionITF<T>::Nodo* pSig = pAux->sig;

        // Terminaremos cuando pSig sea nullptr (insertar al final) ó cuando encontremos la posición exacta donde insertar (por el medio)
        while (pSig != nullptr && identificador(pSig->dato) < ident)
        { 
            pAux = pSig;
            pSig = pAux->sig;
        }

        // Insertamos si hemos llegado al final ó si el identificador no existe
        if (pSig == nullptr || identificador(pSig->dato) != ident)
        {
            c.nElem++;
            typename ColeccionITF<T>::Nodo* nuevoElem = new typename ColeccionITF<T>::Nodo;
            nuevoElem->dato = i;
            nuevoElem->sig = pSig;
            pAux->sig = nuevoElem;
        }
    }
}

/*
    Busca si existe un dato de tipo T, en los nodos que almacena la coleccionITF, que tenga el mismo identificador que el dato de tipo T
    proporcionado (i). De ser así, el dato que ya se encuentra en la coleccionITF se actualizará con el del parámetro i.
    Al solo cambiarse el valor de la variable "dato" dentro del nodo que se encuentra en dicha posición, no hará falta hacer más cambios
    en ninguna otra parte.
*/
template<typename T> void actualizar(ColeccionITF<T> &c, const T &i) {

    // Si la lista se encuentra vacía automáticamente dejaremos de intentar buscar el elemento del género T a actualizar.
    if(c.primero != nullptr) {

        string identificadorDelNuevoDato = identificador(i);
        string identificadorDatoActual = identificador(c.primero->dato);

        if(identificadorDelNuevoDato > identificadorDatoActual) {

            // Empezamos comprobando el segundo elemento de la colección, ya que ya se comprobó el primero.
            typename ColeccionITF<T>::Nodo* pAux = c.primero->sig;

            bool actualizado = false;
            bool busquedaAunValida = true; // Mientras tenga sentido buscar el elemento debido al orden de los IDs, se seguirá buscando.

            while(pAux != nullptr && !actualizado && busquedaAunValida) {

                identificadorDatoActual = identificador(pAux->dato);

                if(identificadorDelNuevoDato < identificadorDatoActual) {

                    busquedaAunValida = false;

                } else if(identificadorDatoActual == identificadorDelNuevoDato) {

                    pAux->dato = i;
                    actualizado = true;

                } else {
                    pAux = pAux->sig;

                }

            }

        } else if(identificadorDelNuevoDato == identificadorDatoActual){

            c.primero->dato = i;

        }

    } 

}


/*
    Si en c hay algún ítem con identificador igual a ident, elimina ese item de c.
    En caso contrario, c no se modifica.

    También se encarga de actualizar nElem y resuelve posibles casos conflictivos con el iterador
    Ejemplo: [   si ">X<" es la ubicacion del iterador: (1 >2< 3 4 5 6) y borramos el 2 --> (1 >3< 4 5 6)   ]
*/
template<typename T> void borrar(const string ident, ColeccionITF<T> &c){

    if(c.primero != nullptr){   //si LISTA VACÍA, no hacemos nada (solo hacemos algo si lista no vacia)

        if(identificador(c.primero->dato) == ident){  //si EL PRIMERO YA ES IGUAL: borrar el primero y fin

            typename ColeccionITF<T>::Nodo* pKiller = c.primero;    //puntero mercenario apunta al objetivo para poder reasignar c.primero sin perder la direccion
            //COMPROBAR ITERADOR!!
            if(c.iter == pKiller){      //si el iterador esta en el elemento a borrar, mover el iterador al siguiente elem por visitar.
                c.iter = pKiller->sig;  //si ">X<" es el iterador: (1 >2< 3 4 5 6) y borramos el 2 -> (1 2 >3< 4 5 6) -> (1 >3< 4 5 6)
                //si la lista era de tamaño 1 el iterador pasará a ser NIL y las operaciones de este sabrán que ha terminado.
            }
            c.primero = pKiller->sig;      //el nuevo primero es el que fue segundo
            delete pKiller;                //matas al elem en el puntero mercenario
            c.nElem--;                     //hay 1 elemento menos

        }else{  //seguir buscando un igual mas adelante en la lista con oruga de dos punteros
                //(Dos para poder actualizar los adyacentes al que borremos) (Al ser enlazada unidireccional no podemos ir hacia atrás)
            typename ColeccionITF<T>::Nodo* pAux = c.primero;
            typename ColeccionITF<T>::Nodo* pSig = pAux->sig;
            
            bool encontradoYborrado = false;
            while(pSig != nullptr && !encontradoYborrado){ //mientras el pAux no sea el ultimo y no hayamos borrado al objetivo
            
                //sabemos que pAux->dato != ident
                if(identificador(pSig->dato) == ident){ //el SIGUIENTE ES EL QUE BUSCAMOS: borrar pSig y fin
                    
                    //COMPROBAR ITERADOR!!
                    if(c.iter == pSig){      //si el iterador esta en el elemento a borrar, mover el iterador al siguiente elem por visitar.
                        c.iter = pSig->sig;  //si ">X<" es el iterador: (1 >2< 3 4 5 6) y borramos el 2 -> (1 2 >3< 4 5 6) -> (1 >3< 4 5 6)
                        //si *pSig es el ultimo elem el iterador pasará a ser NIL y las operaciones de este sabrán que ha terminado.
                    }
                    pAux->sig = pSig->sig;  //el anterior apunta al siguiente de pSig
                    delete pSig;            //borras el elem en pSig
                    c.nElem--;              //hay 1 elem menos
                    encontradoYborrado = true;                 //fin - avisar al bucle de que salga

                }else{
                    //actualizar oruga de punteros
                    pAux = pSig;
                    pSig = pAux->sig;
                }
            }
        }
    }
}


/*
    Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a ident.
*/
template<typename T>
bool esta(const string ident, const ColeccionITF<T> &c) {

    bool estaEnColeccion = false;

    bool busquedaAunValida = true;

    if(c.primero != nullptr){

        typename ColeccionITF<T>::Nodo* pAux = c.primero;
        string identificadorActual;

        while(pAux != nullptr && !estaEnColeccion && busquedaAunValida) {

            identificadorActual = identificador(pAux->dato);

            if(ident < identificadorActual) {

                busquedaAunValida = false;

            } else if(ident == identificadorActual) {

                estaEnColeccion = true;

            } else {

                pAux = pAux->sig;

            }

        }

    }

    return estaEnColeccion;

}

/*
    Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
    PARCIAL: operación no definida si en c no hay ningún ítem con identificador igual a ident.
*/
template<typename T>
T obtenerITF(const string ident, const ColeccionITF<T> &c) {

    typename ColeccionITF<T>::Nodo* pAux = c.primero;

    bool encontrado = false;

    while(!encontrado) {

        if(identificador(pAux->dato) == ident) {

            encontrado = true;

        } else {

            pAux = pAux->sig;

        }

    }

    T itfObtenido = pAux->dato;

    return itfObtenido;
    
}


/*
    Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
    con fecha estrictamente anterior a f, y separados entre sí por la cadena separador.
*/
template<typename T>
string obsoletos(const Fecha &f, const string separador, const ColeccionITF<T> &c) {

    string ids = "";

    if(c.primero != nullptr) {

        typename ColeccionITF<T>::Nodo* pAux = c.primero;

        while(pAux != nullptr) {

            if(anterior(fecha(pAux->dato), f)) {

                if(ids != "") {

                    ids += separador;

                }

                ids += identificador(pAux->dato);
            }
            
            pAux = pAux->sig;
        }

    }

    return ids;

}
 

/*
    Devuelve una colección igual a la resultante de eliminar de c todos los ítems con fecha
    estrictamente anterior a f.
*/
template<typename T>
void purgar(const Fecha &f, ColeccionITF<T> &c) {

    if(c.primero != nullptr) {

        typename ColeccionITF<T>::Nodo* pAnt = nullptr;
        typename ColeccionITF<T>::Nodo* pAux = c.primero;

        typename ColeccionITF<T>::Nodo* pDeleter;

        while(pAux != nullptr) {

            if(anterior(fecha(pAux->dato), f)) {

                if(pAux == c.primero) {

                    c.primero = c.primero->sig;

                } else {

                    pAnt->sig = pAux->sig;

                }

                pDeleter = pAux;
                pAux = pAux->sig;

                if(c.iter == pDeleter) {

                    c.iter = pAux;

                }

                delete(pDeleter);
                c.nElem--;

            } else {

                pAnt = pAux;
                pAux = pAux->sig;

            }

        }

    } 

}

/*
    Devuelve verdad si y sólo si en c hay algún ítem i con tema igual a t.
*/
template<typename T>
bool existeTema(const string t, const ColeccionITF<T> &c) {

    bool existe = false;

    typename ColeccionITF<T>::Nodo* pAux = c.primero;

    while(pAux != nullptr && !existe) {

        if(tema(pAux->dato) == t) {
            existe = true;

        } else {

            pAux = pAux->sig;

        }

    }

    return existe;

}


/*
    Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
    con tema igual a t, y separados entre sí por la cadena separador.
*/
template<typename T>
string delTema(const string t, const string separador, const ColeccionITF<T> &c) {

    string ids = "";

    // Si la coleccion está vacía se devuelve una cadena vacía directamente.
    if(c.primero != nullptr) {

        typename ColeccionITF<T>::Nodo* pAux = c.primero;

        while(pAux != nullptr) {

            if(tema(pAux->dato) == t) {

                if(ids != "") {

                    ids += separador;

                }

                ids += identificador(pAux->dato);

            }

            pAux = pAux->sig;

        }

    }

    return ids;

}


/*
    Devuelve una colección igual a la resultante de eliminar de c todos los ítems i cuyo tema es igual a t.
*/
template<typename T>
void zanjarTema(const string t, ColeccionITF<T> &c) {

    if(c.primero != nullptr) {

        typename ColeccionITF<T>::Nodo* pAnt = nullptr;
        typename ColeccionITF<T>::Nodo* pAux = c.primero;

        typename ColeccionITF<T>::Nodo* pDeleter;

        while(pAux != nullptr) {

            if(tema(pAux->dato) == t) {

                if(pAux == c.primero) {

                    c.primero = c.primero->sig;

                } else {

                    pAnt->sig = pAux->sig;

                }

                pDeleter = pAux;
                pAux = pAux->sig;

                if(c.iter == pDeleter) {

                    c.iter = pAux;

                }

                delete(pDeleter);
                c.nElem--;

            } else {

                pAnt = pAux;
                pAux = pAux->sig;

            }

        }

    }

}



/*
    Devuelve verdad si y sólo si c no contiene ningún ítem.
*/
template<typename T>
bool esVacia(const ColeccionITF<T> &c) {

    return c.nElem == 0;

}


/*
    Devuelve el número de ítems que hay en la colección c.
*/
template<typename T>
int tamano(const ColeccionITF<T> &c) {

    return c.nElem;

}



// --- FUNCIONES DEL ITERADOR ---


/*
    Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente
    ítem a visitar sea el que tiene el identificador (lexicográficamente) más pequeño de todo c
    (situación de no haber visitado ningún ítem).
    
    El "siguiente a visitar" el el dato en el nodo al que apunta el iterador.
*/
template<typename T>
void iniciarIterador(ColeccionITF<T> &c){

    c.iter = c.primero;
}


/*
    Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c, devuelve
    falso si ya se ha visitado el último ítem.
    
    El "siguiente a visitar" el el dato en el nodo al que apunta el iterador.
*/
template<typename T>
bool existeSiguiente(const ColeccionITF<T> &c){

    return (c.iter != nullptr);
}


/*
    Si existe un elemento por visitar en c devuelve verdadero, devuelve dicho elemento por e y avanza el iterador.
    Si no, devuelve falso.

    El "siguiente a visitar" el el dato en el nodo al que apunta el iterador.
*/
template<typename T>
bool siguienteYavanza(ColeccionITF<T> &c, T &e){

    if(existeSiguiente(c)){ //(si no apunta a NIL)

        e = c.iter->dato;
        c.iter = c.iter->sig;
        return true;

    }else{
        return false;
    }
}


#endif //fin de coleccionITF.hpp