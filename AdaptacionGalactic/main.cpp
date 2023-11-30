#include <iostream>
#include "funciones.h"
#include <ctime>
int main(){
    srand(time(NULL));
    int opcionMenuPrincipal;
    std::string nombres[2];
    int puntos[2] = {};
    int contadorPlantetas[3];
    std::cout << "\t\t\t*******ACTUALIZACION*******\n";
    std::cout << "LUEGO DE HABER MANDADO EL REPOSITORIO A LOS PROFESORES MODIFICAMOS LA POSIBILIDAD DE QUE LOS DADOS SE PUEDAN\n";
    std::cout << "INGRESAR DE MANERA MANUAL. A LA HORA DE TIRAR LOS DADOS SE PREGUNTA QUE MODALIDAD SE QUIERE ELEGIR\n";
    std::cout << "POR OTRO LADO, SE AGREGO CANTIDAD DE CARTAS Y EL PLANETA EN EL QUE SE ENCUENTRAN LOS JUGADORES EN EL ENCABEZADO\n";
    std::cout << "\n\n\n\n\n PRESIONAR TECLA PARA COMENZAR EL JUEGO\n";
    system("pause>null");
    system("cls");
    while(true){
        system("cls");
        std::cout << "\t\t\tGALACTIC RACE LITE\n";
        std::cout << "\t\tMENU PRINCIPAL\n";
        std::cout << "\t1. JUGAR\n";
        std::cout << "\t2. CREDITOS\n";
        std::cout << "\t3. ESTADISTICAS\n";
        std::cout << "\t4. SALIR\n";

        std::cin >> opcionMenuPrincipal;

        switch(opcionMenuPrincipal){
            case 1:
                system("cls");
                presentacionJugadores(nombres);
                system("cls");
                desarrolloJuego(nombres, puntos);
                break;
            case 2:
                system("cls");
                std::cout << "GALACTIC RACE LITE es una adaptacion de GALACTIC RACE, juego desarrollado\n";
                std::cout << "por los alumnos Martin Alejandro Garcia y Juan Pablo Rajoy para la materia\n";
                std::cout << "Laboratorio de Computacion 2. Adaptada en conjunto con los profesores de \n";
                std::cout << "de Laboratorio de Computacion 1.";
                system("pause>null");
                break;
            case 3:
                break;
            case 4:
                std::cout << "ADIOS TERRICOLAS";
                return 0;
        }
    }
    return 0;
}
