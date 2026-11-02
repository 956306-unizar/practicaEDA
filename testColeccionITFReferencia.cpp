#include <iostream>
#include <cassert>
#include <string>
#include "coleccionITF.hpp"
#include "anuncio.hpp"

using namespace std;

// CABECERA - DECLARACIÓN DE FUNCIONES

// Funciones ligadas a los requisitos del TAD genérico
string identificador(Anuncio anuncio);
string tema(Anuncio anuncio);
Fecha fecha(Anuncio anuncio);

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

int main(int argc, char* argv[]) {
    cout << "PRUEBAS DE 'coleccionITF.hpp'\n" << endl;

    ColeccionITF<Anuncio> anuncios;
    bool coleccionCreada = false;
    int opcion = -1;

    while (opcion != 0) {
        solicitarOpcionMenu(opcion);

        // Bloqueo de seguridad: no permitir operar si no se ha llamado a 'crear'
        if (opcion > 1 && opcion <= 17 && !coleccionCreada) {
            cout << "\n[AVISO] Primero debes inicializar la coleccion (Opcion 1).\n\n";
            continue;
        }

        switch (opcion) {
            case 1:  probarCrear(anuncios, coleccionCreada); break;
            case 2:  probarAnadir(anuncios); break;
            case 3:  probarActualizar(anuncios); break;
            case 4:  probarBorrar(anuncios); break;
            case 5:  probarEsta(anuncios); break;
            case 6:  probarObtenerITF(anuncios); break;
            case 7:  probarObsoletos(anuncios); break;
            case 8:  probarPurgar(anuncios); break;
            case 9:  probarExisteTema(anuncios); break;
            case 10: probarDelTema(anuncios); break;
            case 11: probarZanjarTema(anuncios); break;
            case 12: probarEsVacia(anuncios); break;
            case 13: probarTamano(anuncios); break;
            case 0:
                cout << "Saliendo del programa de pruebas...\n";
                break;
            default:
                cout << "Opcion no valida. Intentalo de nuevo.\n";
                break;
        }
        cout << "\n";
    }

    return 0;
}

// -------------------------------------------------------------
// OPERACIONES DEL PARÁMETRO FORMAL
// -------------------------------------------------------------

string identificador(Anuncio anuncio) {
    return suIdentificador(anuncio);
}

string tema(Anuncio anuncio) {
    return suCategoria(anuncio);
}

Fecha fecha(Anuncio anuncio) {
    return suPublicacion(anuncio);
}

// -------------------------------------------------------------
// MENÚ
// -------------------------------------------------------------

void solicitarOpcionMenu(int &opcion) {
    cout << "--- MENU ---\n"
         << "1. Crear coleccion\n"
         << "2. Anadir item\n"
         << "3. Actualizar item\n"
         << "4. Borrar item por identificador\n"
         << "5. Comprobar si esta un item (esta)\n"
         << "6. Obtener item por identificador\n"
         << "7. Listar obsoletos anteriores a fecha\n"
         << "8. Purgar items anteriores a fecha\n"
         << "9. Comprobar si existe tema\n"
         << "10. Listar identificadores de un tema\n"
         << "11. Zanjar tema (eliminar todos del tema)\n"
         << "12. Comprobar si la coleccion es vacia\n"
         << "13. Mostrar tamano de la coleccion\n"
         << "----------------------------------------\n"
         << "0. Salir\n"
         << "Seleccione una opcion: ";
    cin >> opcion;
}

// -------------------------------------------------------------
// IMPLEMENTACIÓN DE PRUEBAS
// -------------------------------------------------------------

void probarCrear(ColeccionITF<Anuncio> &c, bool &coleccionCreada) {
    cout << "Probando 'crear'... ";
    crear(c);
    assert(esVacia(c));
    assert(tamano(c) == 0);
    coleccionCreada = true;
    cout << "EXITO\n";
}

void probarAnadir(ColeccionITF<Anuncio> &c) {
    cout << "Probando 'anadir'...\n";
    crear(c); // Empezamos en estado limpio
    
    // Instanciar anuncios de prueba (ajusta al constructor de tu TAD Anuncio)
    Anuncio a1, a2; 
    // Suponiendo a1 con id "A1" y a2 con id "A2"

    cout << "  - Anadir primer elemento... ";
    anadir(c, a1);
    assert(tamano(c) == 1);
    assert(esta(identificador(a1), c));
    cout << "OK\n";

    cout << "  - Anadir segundo elemento... ";
    anadir(c, a2);
    assert(tamano(c) == 2);
    assert(esta(identificador(a2), c));
    cout << "OK\n";

    cout << "  - Intentar anadir duplicado (id repetido)... ";
    anadir(c, a1);
    assert(tamano(c) == 2); // No debe crecer
    cout << "OK\n";

    cout << "Resultado: EXITO\n";
}

void probarActualizar(ColeccionITF<Anuncio> &c) {
    cout << "Probando 'actualizar'...\n";
    crear(c);
    Anuncio a1, a1_mod, a_inexistente;

    anadir(c, a1);

    cout << "  - Actualizar item existente... ";
    actualizar(c, a1_mod);
    assert(tamano(c) == 1);
    // Verificar que el dato ahora coincide con la version modificada
    cout << "OK\n";

    cout << "  - Actualizar item que no existe (debe ignorarse)... ";
    actualizar(c, a_inexistente);
    assert(tamano(c) == 1);
    cout << "OK\n";

    cout << "Resultado: EXITO\n";
}

void probarBorrar(ColeccionITF<Anuncio> &c) {
    cout << "Probando 'borrar'...\n";
    crear(c);
    Anuncio a1, a2;
    anadir(c, a1);
    anadir(c, a2);

    cout << "  - Borrar identificador que no existe... ";
    borrar("ID_FANTASMA", c);
    assert(tamano(c) == 2);
    cout << "OK\n";

    cout << "  - Borrar identificador existente... ";
    borrar(identificador(a1), c);
    assert(tamano(c) == 1);
    assert(!esta(identificador(a1), c));
    assert(esta(identificador(a2), c));
    cout << "OK\n";

    cout << "Resultado: EXITO\n";
}

void probarEsta(ColeccionITF<Anuncio> &c) {
    cout << "Probando 'esta'...\n";
    crear(c);
    Anuncio a1;

    assert(!esta(identificador(a1), c));
    anadir(c, a1);
    assert(esta(identificador(a1), c));

    cout << "Resultado: EXITO\n";
}

void probarObtenerITF(ColeccionITF<Anuncio> &c) {
    cout << "Probando 'obtenerITF'...\n";
    crear(c);
    Anuncio a1;
    anadir(c, a1);

    // Solo se debe llamar si 'esta' es verdadero
    if (esta(identificador(a1), c)) {
        Anuncio obtenido = obtenerITF(identificador(a1), c);
        assert(identificador(obtenido) == identificador(a1));
    }

    cout << "Resultado: EXITO\n";
}

void probarObsoletos(ColeccionITF<Anuncio> &c) {
    cout << "Probando 'obsoletos'...\n";
    crear(c);
    // Poblar con anuncios con fechas anteriores y posteriores a una fecha de corte
    // Fecha limite(...);
    // string lista = obsoletos(limite, ", ", c);
    // assert(...)