#include "coleccionITF.hpp"
#include "anuncio.hpp"

// CABECERA - DECLARACIoN DE FUNCIONES

// "Traduccion" de las operaciones del parámetro formal.
string identificador(Anuncio anuncio);
string tema(Anuncio anuncio);
Fecha fecha(Anuncio anuncio);

void mostrarColeccion(ColeccionITF<Anuncio> &c);
void evaluacionFuncion(bool exito, string mensajeError = "");

const int NUM_ANUNCIOS_INICIALES = 20;

// Funcion principal.
int main(int argc, char* argv[]) {

    bool masInfo = 0;

    if(argc == 2) {

        // En caso de que se quiera más info a la hora de ver las pruebas, el usuario deberá pasar un 1 como único parámetro de ejecución.
        masInfo = atoi(argv[1]);

    }

    cout << "PRUEBAS DE 'coleccionITF.hpp'\n" << endl;

    ColeccionITF<Anuncio> anuncios;

    cout << "Probando la funcion 'crear'... ";
    crear(anuncios);
    cout << "EXITO (Ejecucion sin errores)" << endl;

    // Tambien sirve para comprobar que 'crear' haya implementado su logica correctamente.
    cout << "\nProbando las funciones 'esVacia' y 'tamano' cuando la coleccion se encuentra vacia...";
    if(masInfo) cout << endl;

    bool vacia = esVacia(anuncios);
    int tamanoColeccion = tamano(anuncios);

    if(masInfo) {

        cout << "Resultados esperados: true, 0" << endl;
        cout << "Resultado obtenidos: " << vacia << ", " << tamanoColeccion << endl;

    }

    evaluacionFuncion(vacia && tamanoColeccion == 0);

    if(masInfo) {
        cout << "\nCreando " << NUM_ANUNCIOS_INICIALES <<  "anuncios genericos... " << endl;
    }

    Anuncio anunciosGenericos[20];
    string categorias[3] = {"Coche", "Juguete", "Perfume"};

    srand(time(nullptr)); // Para fechas aleatorias.

    for(int i = 1; i <= NUM_ANUNCIOS_INICIALES; i++) {

        string id = "ID";

        if(i < 10) {
            id += "0";
        }

        id += to_string(i);

        string titulo = "Anuncio";
        string descripcion = "Descripcion";
        string categoria = categorias[i % 3];

        Fecha fecha;
        bool error;
        crear(i % 29, i % 13, 2000 + i, fecha, error);

        anunciosGenericos[i - 1] = crearAnuncio(id, titulo, descripcion, categoria, fecha, fecha);

    }

    if(masInfo) {

        cout << "Anuncios creados:" << endl;

        for(int i = 0; i < NUM_ANUNCIOS_INICIALES; i++) {

            Anuncio anuncioAMostrar = anunciosGenericos[i];

            cout << "ID: " << identificador(anuncioAMostrar) << " Tema: " << tema(anuncioAMostrar);
            cout << " Fecha: " << dia(fecha(anuncioAMostrar)) << '-' << mes(fecha(anuncioAMostrar)) << '-' << anyo(fecha(anuncioAMostrar)) << endl;

        }

    }

    cout << "\nProbando la funcion 'anadir'... ";

    for(int i = 0; i < 20; i++) {

        anadir(anuncios, anunciosGenericos[i]);

    }

    cout << "EXITO" << endl;

    if(masInfo) {
        mostrarColeccion(anuncios);
    }


    cout << "\nProbando la funcion 'esta'... ";

    evaluacionFuncion(esta("ID01", anuncios));


    cout << "\nProbando la funcion 'obtenerITF'... ";

    Anuncio anuncio = obtenerITF("ID01", anuncios);

    evaluacionFuncion(identificador(anuncio) == "ID01");


    cout << "\nProbando la funcion 'actualizar'... ";

    cambiarCategoria(anuncio, "Telefono");

    actualizar(anuncios, anuncio);

    anuncio = obtenerITF("ID01", anuncios);

    if(tema(anuncio) == "Telefono") {

        cout << "EXITO" << endl;

    } else {

        cout << "ERROR" << endl;
        return 1;

    }

    cout << "\nProbando la funcion 'borrar'... ";

    borrar("ID02", anuncios);

    if(esta("ID02", anuncios)) {
        
        cout << "ERROR - El anuncio sigue estando en la coleccion" << endl;
        return 1;

    }

    Anuncio anuncio2;

    iniciarIterador(anuncios);

    siguienteYavanza(anuncios, anuncio);
    siguienteYavanza(anuncios, anuncio2);

    string idAnuncio1 = identificador(anuncio);
    string idAnuncio2 = identificador(anuncio2);

    if(masInfo) {
        cout << "Resultado esperado: ID01, ID03" << endl;
        cout << "Resultado obtenido: " << idAnuncio1 << ", " << idAnuncio2 << endl;
    }

    evaluacionFuncion(idAnuncio1 == "ID01" && idAnuncio2 == "ID03", "El anuncio con ID01 no está seguido por el de ID03 ahora que se borró el de ID02");


    cout << "\nProbando la funcion 'obsoletos'... ";
    if(masInfo) cout << endl;

    Fecha fecha;
    bool error;
    crear(1, 1, 2010, fecha, error);

    string resultadoEsperado = "ID01,ID03,ID04,ID05,ID06,ID07,ID08,ID09";
    string cadenaIDs = obsoletos(fecha, ",", anuncios);

    if(masInfo) {
        cout << "Resultado esperado: " << resultadoEsperado << endl;
        cout << "Resultado obtenido: " << cadenaIDs << endl;
    }

    evaluacionFuncion(cadenaIDs == resultadoEsperado, "El resultado obtenido no coincide con el esperado.");


    cout << "\nProbando la funcion 'purgar'... ";

    purgar(fecha, anuncios);

    resultadoEsperado = "";
    cadenaIDs = obsoletos(fecha, ",", anuncios);

    evaluacionFuncion(cadenaIDs == resultadoEsperado);


    cout << "\nProbando la funcion 'existeTema'... ";

    evaluacionFuncion(existeTema("Coche", anuncios));


    cout << "\nProbando la funcion 'delTema'... ";
    if(masInfo) cout << endl;

    resultadoEsperado = "ID12,ID15,ID18";
    cadenaIDs = delTema("Coche", ",", anuncios);

    if(masInfo) {
        cout << "Resultado esperado: " << resultadoEsperado << endl;
        cout << "Resultado obtenido: " << cadenaIDs << endl;
    }

    evaluacionFuncion(cadenaIDs == resultadoEsperado);


    cout << "\nProbando la funcion 'zanjarTema'... ";

    zanjarTema("Coche", anuncios);

    resultadoEsperado = "";
    cadenaIDs = delTema("Coche", ",", anuncios);

    evaluacionFuncion(cadenaIDs == resultadoEsperado);


    cout << "\nTodas las funciones de coleccionITF funcionan CORRECTAMENTE." << endl;


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

void mostrarColeccion(ColeccionITF<Anuncio> &c) {

    iniciarIterador(c);

    while(existeSiguiente(c)) {

        Anuncio anuncioAMostrar;
        siguienteYavanza(c, anuncioAMostrar);

        cout << "ID: " << identificador(anuncioAMostrar) << " Tema: " << tema(anuncioAMostrar);
        cout << " Fecha: " << dia(fecha(anuncioAMostrar)) << '-' << mes(fecha(anuncioAMostrar)) << '-' << anyo(fecha(anuncioAMostrar)) << endl;

    }

}

void evaluacionFuncion(bool exito, string mensajeError) {

    if(exito) {

        cout << "EXITO" << endl;

    } else {

        cout << "ERROR";

        if(mensajeError != "") {

            cout << " - " << mensajeError;

        }

        cout << endl;

        exit(1);

    }

}