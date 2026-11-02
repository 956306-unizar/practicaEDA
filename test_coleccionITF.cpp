#include "coleccionITF.hpp"
#include "anuncio.hpp"

// CABECERA - DECLARACIÓN DE FUNCIONES

// "Traducción" de las operaciones del parámetro formal.
string identificador(Anuncio anuncio);
string tema(Anuncio anuncio);
Fecha fecha(Anuncio anuncio);

// Funciones que permitirán probar cada una de las funciones implementadas en "coleccionITF".

void solicitarOpcionMenu(int &opcion);

void probarCrear(ColeccionITF<Anuncio> &c, bool &coleccionCreada);
void probarAnadir(ColeccionITF<Anuncio> &c);
void probarActualizar(ColeccionITF<Anuncio> &c);
void probarBorrar(ColeccionITF<Anuncio> &c);
void probarEsta(ColeccionITF<Anuncio> &c);
void probarObtenerITF(ColeccionITF<Anuncio> &c);
void probarObsoletos(ColeccionITF<Anuncio> &c);
void probarPurgar(ColeccionITF<Anuncio> &c);
void probarExisteTema(ColeccionITF<Anuncio> &c);
void probarDelTema(ColeccionITF<Anuncio> &c);
void probarZanjarTema(ColeccionITF<Anuncio> &c);
void probarEsVacia(ColeccionITF<Anuncio> &c);
void probarTamano(ColeccionITF<Anuncio> &c);


// Función principal.
int main(int argc, char* argv[]) {

    cout << "PRUEBAS DE 'coleccionITF.hpp'\n"; << endl;

    ColeccionITF<Anuncio> anuncios;

    bool coleccionCreada = false;

    int opcion = nullptr;

    while(opcion != 0) {

        solicitarOpcionMenu(opcion);

        // Switch que, según la opción elegida en el menú anteriormente, llamará a una función auxiliar
        // la cual hara todo tipo de pruebas para probar esa función concreta del TAD genérico "coleccionITF".
        switch(opcion) {

            case 1:

                probarCrear(anuncios, coleccionCreada);

                break;

        }

    }

    return 0;

}

string identificador(Anuncio anuncio) {

    return suIdentificador(anuncio);

}

string tema(Anuncio anuncio) {

    return suCategoria(anuncio);

}

Fecha fecha(Anuncio anuncio) {

    return suPublicacion(anuncio);

}

void solicitarOpcionMenu(int &opcion) {

        printf(
            "--- MENU ---\n"
            "1. Crear coleccion\n"
            "2. Anadir item\n"
            "3. Actualizar item\n"
            "4. Borrar item por identificador\n"
            "5. Comprobar si esta un item (esta)\n"
            "6. Obtener item por identificador\n"
            "7. Listar obsoletos anteriores a fecha\n"
            "8. Purgar items anteriores a fecha\n"
            "9. Comprobar si existe tema\n"
            "10. Listar identificadores de un tema\n"
            "11. Zanjar tema (eliminar todos del tema)\n"
            "12. Comprobar si la coleccion es vacia\n"
            "13. Mostrar tamano de la coleccion\n"
            "14. Iniciar iterador\n"
            "15. Comprobar si existe siguiente en iterador\n"
            "16. Obtener siguiente y avanzar iterador\n"
            "17. Recorrer y mostrar toda la coleccion (iterador)\n"
            "----------------------------------------\n"
            "0. Salir\n"
        );

        prinft("Seleccione una opción: ");
        cin >> opcion;

}

void probarCrear(ColeccionITF<Anuncio> &c, bool &coleccionCreada) {

    if(coleccionCreada) {

        cout << "La colección ya se encuentra creada." << endl;
        return;

    }

    cout << "Probando la función 'crear'... ";
    crear(c);
    cout << "ÉXITO" << endl;

    coleccionCreada = true;

}

void probarAnadir(ColeccionITF<Anuncio> &c) {

    Anuncio anunciosAAnadir[20];

}

void probarActualizar(ColeccionITF<Anuncio> &c) {

}

void probarBorrar(ColeccionITF<Anuncio> &c) {

}

void probarEsta(ColeccionITF<Anuncio> &c) {

}

void probarObtenerITF(ColeccionITF<Anuncio> &c) {

}

void probarObsoletos(ColeccionITF<Anuncio> &c) {

}

void probarPurgar(ColeccionITF<Anuncio> &c) {

}

void probarExisteTema(ColeccionITF<Anuncio> &c) {

}

void probarDelTema(ColeccionITF<Anuncio> &c) {

}

void probarZanjarTema(ColeccionITF<Anuncio> &c) {

}

void probarEsVacia(ColeccionITF<Anuncio> &c) {

}

void probarTamano(ColeccionITF<Anuncio> &c) {

}