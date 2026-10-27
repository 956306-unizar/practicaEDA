#include "coleccionITF.hpp"

void probarCrear();

int main(int argc, char* argv[]) {

    int opcion = nullptr;

    while(opcion != 0) {

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

        // Switch que, según la opción elegida en el menú anteriormente, llamará a una función auxiliar
        // la cual hara todo tipo de pruebas para probar esa función concreta del TAD genérico "coleccionITF".
        switch(opcion) {

            case 1:
                probarCrear();
                break;

        }

    }

    return 0;

}

void probarCrear() {

}