#include <string.h>
#include "funciones.h"

void presentacionJugadores(std::string nombres[]){

    for(int x = 0; x < 2; x++){

        std::cout << "COMO TE LLAMAS JUGADOR " << x + 1 << "?\n";
        std::cin >> nombres[x];
    }


}
int tirarDados(){
    int dado = rand() % 6 + 1;
    return dado;

}
int tiradaTurno(std::string nombres[]){
    int dado[2];
    int primerJugador;
    std::cout << "TIRADAS DE DADO PARA VER QUIEN COMIENZA\n" << "COMENZARA EL JUGADOR QUE SAQUE EL DADO MENOR\n\n";
    for(int x = 0; x < 2; x++){
        std::cout << nombres[x] << " PRESIONA UNA TECLA PARA TIRAR DADO\n";
        system("pause>null");
        dado[x] = rand() % 6 + 1;
        std::cout << dado[x] << "\n";
    }
    if(dado[0] < dado[1]){
        std::cout << "EMPEZARA JUGANDO " << nombres[0];
        //primerJugador = 0;
        return 0;
    }else{
        std::cout << "EMPEZARA JUGANDO " << nombres[1];
        //primerJugador = 1;
        return 1;
    }
    system("pause");
}
void desarrolloJuego(std::string nombres[], int puntos[]){
    const int MERCURIO = 0;
    const int VENUS = 1;
    const int TIERRA = 2;
    const int MARTE = 3;
    const int JUPITER = 4;
    const int SATURNO = 5;
    const int URANO = 6;
    const int NEPTUNO = 7;
    const int PLUTON = 8;
    int mazo[40] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3};
    int manoCartas[2][5] = {};
    bool ganador = false;
    bool plaTierra[2];
    int puntosAux;
    int contadorPluton[2] = {};
    int estadoPlanetas[2][9] = {};
    int primerJugador;
    int opcionJugadas;
    int opcionApostar;
    int turno = 0;
    int jugadorActual;
    int otroJugador;
    int contadorJugadas = 0;
    char urano;

    primerJugador = tiradaTurno(nombres);

    if(primerJugador == 0){
        turno = 0;
    }else{
        turno = 1;
    }
    std::cout << "COMIENZA EL JUEGO\n\n";
    while(ganador == false){
        contadorJugadas = 0;
        if(turno % 2 == 0){
            jugadorActual = 0;
            otroJugador = 1;
        }else{
            jugadorActual = 1;
            otroJugador = 0;
        }
        if(estadoPlanetas[jugadorActual][URANO] == 1){
                std::cout << "POR ESTAR EN URANO PODES ELEGIR HACER UNA JUGADA ESPECIAL, DEBES TIRAR LOS DADOS PARA SACAR UNA ESCALERA.\n";
                std::cout << "EN CASO DE ELEGIR ESTA OPCION NO PODRAS HACER UNA APUESTA COMUN O USO DE CARTAS. (S: SI - N: NO)";
                std::cin >> urano;

                if(urano == 's' || urano == 'S'){
                    puntos[jugadorActual] += escalera();
                    contadorJugadas = 2;
                }else if(urano == 'n' || urano == 'N')
                    std::cout << "ELEGIS JUGADA COMUN\n";
            }
        while(contadorJugadas < 2){
            if(estadoPlanetas[jugadorActual][TIERRA] == 1){
                plaTierra[jugadorActual] = true;
                std::cout << nombres[jugadorActual] << " RECORDA QUE POR ESTAR EN LA TIERRA NO PODRAS SUMAR CARTAS POR MAS QUE ACIERTES LA APUESTA\n";
            }else{
                plaTierra[jugadorActual] = false;
            }
            if(estadoPlanetas[jugadorActual][VENUS] == 1){
                std::cout << "POR ESTAR EN EL PLANETA VENUS SE LE SUMAN 10 PUNTOS A TU RIVAL\n";
                puntos[otroJugador] += 10;
            }
            if(estadoPlanetas[jugadorActual][SATURNO] == 1){
                std::cout << "POR ESTAR EN EL PLANETA SATURNO SE TE RESTARA LA MITAD DE TUS PUNTOS\n";
                puntos[jugadorActual] /= 2;
            }
            if(estadoPlanetas[jugadorActual][PLUTON] == 1){
                contadorPluton[jugadorActual]++;
                std::cout << "ESTAS EN EL PLANETA PLUTON, TENES " << 5 - contadorPluton[jugadorActual] << " PARA CANJEARLO O RETROCEDERAS A JUPITER\n";
            }
            if(contadorPluton[jugadorActual] > 4){
                estadoPlanetas[jugadorActual][PLUTON] = 0;
                estadoPlanetas[jugadorActual][JUPITER] = 1;
            }

            std::cout << "------------------------------------------------------------------------------\n";
            std::cout << "Jugador 1: " << nombres[0] << "\t\tPuntos: " << puntos[0] << "\t\tPlaneta: " << locacion(estadoPlanetas, 0) << "\n";
            std::cout << "Jugador 2: " << nombres[1] << "\t\tPuntos: " << puntos[1] << "\t\tPlaneta: " << locacion(estadoPlanetas, 1) << "\n";
            std::cout << "------------------------------------------------------------------------------\n";
            std::cout << "TURNO DE " << nombres[jugadorActual] << "\n";
            std::cout << "MENU DE JUGADAS\n";
            std::cout << "1. APOSTAR\n";
            std::cout << "2. CANJEAR PLANETAS\n";
            std::cout << "3. USAR CARTA\n";
            std::cin >>opcionJugadas;

            switch(opcionJugadas){
                case 1:

                    contadorJugadas = 2;
                    std::cout << "1. SUMAR 8 \n";
                    std::cout << "2. DOS PARES\n";
                    std::cout << "3. PAR E IMPAR\n";
                    std::cout << "4. SUMAR NUMERO PRIMO\n";
                    std::cout << "5. MULTIPLOS\n";
                    std::cin >> opcionApostar;

                    switch(opcionApostar){
                        case 1:
                            puntosAux = puntos[jugadorActual];
                            puntos[jugadorActual] += sumar8();
                            if(puntosAux < puntos[jugadorActual] && plaTierra[jugadorActual] == false){
                                darCarta(manoCartas, mazo, jugadorActual);
                            }
                            if(estadoPlanetas[otroJugador][MERCURIO] == 1 && puntosAux == puntos[jugadorActual]){
                                puntos[jugadorActual] += sumar8();
                            }
                            if(estadoPlanetas[jugadorActual][MARTE] == 1 && puntosAux < puntos[jugadorActual]){
                                puntos[jugadorActual] += 5;
                                std::cout << "POR ESTAR EN EL PLANETA MARTE Y HABER ACERTADO LA APUESTA SUMARAS 5 PUNTOS EXTRA\n";
                            }
                            if(estadoPlanetas[jugadorActual][JUPITER] == 1){
                                if(puntosAux == puntos[jugadorActual]){
                                    darCarta(manoCartas, mazo, jugadorActual);
                                    std::cout << "POR ESTAR EN EL PLANETA JUPITER OBTIENES CARTA AUNQUE NO ACIERTES LA APUESTA\n";
                                }
                            }
                            if(estadoPlanetas[jugadorActual][NEPTUNO] == 1 && puntosAux == puntos[jugadorActual]){
                                puntos[jugadorActual] += 2;
                                std::cout << "POR ESTAR EN EL PLANETA NEPTUNO Y NO HABER ACERTADO SUMARAS 2 PUNTOS\n";
                            }

                            break;
                        case 2:
                            puntosAux = puntos[jugadorActual];
                            puntos[jugadorActual] += dosPares();
                            if(puntosAux < puntos[jugadorActual] && plaTierra[jugadorActual] == false){
                                darCarta(manoCartas, mazo, jugadorActual);
                            }
                            if(estadoPlanetas[otroJugador][MERCURIO] == 1 && puntosAux == puntos[jugadorActual]){
                                puntos[jugadorActual] += dosPares();
                            }
                            if(estadoPlanetas[jugadorActual][MARTE] == 1 && puntosAux < puntos[jugadorActual]){
                                puntos[jugadorActual] += 5;
                                std::cout << "POR ESTAR EN EL PLANETA MARTE Y HABER ACERTADO LA APUESTA SUMARAS 5 PUNTOS EXTRA\n";
                            }
                            if(estadoPlanetas[jugadorActual][JUPITER] == 1){
                                if(puntosAux == puntos[jugadorActual]){
                                    darCarta(manoCartas, mazo, jugadorActual);
                                    std::cout << "POR ESTAR EN EL PLANETA JUPITER OBTIENES CARTA AUNQUE NO ACIERTES LA APUESTA\n";
                                }
                            }
                            if(estadoPlanetas[jugadorActual][NEPTUNO] == 1 && puntosAux == puntos[jugadorActual]){
                                puntos[jugadorActual] += 2;
                                std::cout << "POR ESTAR EN EL PLANETA NEPTUNO Y NO HABER ACERTADO SUMARAS 2 PUNTOS\n";
                            }
                            break;
                        case 3:
                            puntosAux = puntos[jugadorActual];
                            puntos[jugadorActual] += parImpar();
                            if(puntosAux < puntos[jugadorActual] && plaTierra[jugadorActual] == false){
                                darCarta(manoCartas, mazo, jugadorActual);
                            }
                            if(estadoPlanetas[otroJugador][MERCURIO] == 1 && puntosAux == puntos[jugadorActual]){
                                puntos[jugadorActual] += parImpar();
                            }
                            if(estadoPlanetas[jugadorActual][MARTE] == 1 && puntosAux < puntos[jugadorActual]){
                                puntos[jugadorActual] += 5;
                                std::cout << "POR ESTAR EN EL PLANETA MARTE Y HABER ACERTADO LA APUESTA SUMARAS 5 PUNTOS EXTRA\n";
                            }
                            if(estadoPlanetas[jugadorActual][JUPITER] == 1){
                                if(puntosAux == puntos[jugadorActual]){
                                    darCarta(manoCartas, mazo, jugadorActual);
                                    std::cout << "POR ESTAR EN EL PLANETA JUPITER OBTIENES CARTA AUNQUE NO ACIERTES LA APUESTA\n";
                                }
                            }
                            if(estadoPlanetas[jugadorActual][JUPITER] == 1){
                                if(puntosAux == puntos[jugadorActual]){
                                    darCarta(manoCartas, mazo, jugadorActual);
                                }
                            }
                            if(estadoPlanetas[jugadorActual][NEPTUNO] == 1 && puntosAux == puntos[jugadorActual]){
                                puntos[jugadorActual] += 2;
                                std::cout << "POR ESTAR EN EL PLANETA NEPTUNO Y NO HABER ACERTADO SUMARAS 2 PUNTOS\n";
                            }
                            break;
                        case 4:
                            puntosAux = puntos[jugadorActual];
                            puntos[jugadorActual] += primo();
                            if(puntosAux < puntos[jugadorActual] && plaTierra[jugadorActual] == false){
                                darCarta(manoCartas, mazo, jugadorActual);
                            }
                            if(estadoPlanetas[otroJugador][MERCURIO] == 1 && puntosAux == puntos[jugadorActual]){
                                puntos[jugadorActual] += primo();
                            }
                            if(estadoPlanetas[jugadorActual][MARTE] == 1 && puntosAux < puntos[jugadorActual]){
                                puntos[jugadorActual] += 5;
                                std::cout << "POR ESTAR EN EL PLANETA MARTE Y HABER ACERTADO LA APUESTA SUMARAS 5 PUNTOS EXTRA\n";
                            }
                            if(estadoPlanetas[jugadorActual][JUPITER] == 1){
                                if(puntosAux == puntos[jugadorActual]){
                                    darCarta(manoCartas, mazo, jugadorActual);
                                    std::cout << "POR ESTAR EN EL PLANETA JUPITER OBTIENES CARTA AUNQUE NO ACIERTES LA APUESTA\n";
                                }
                            }
                            if(estadoPlanetas[jugadorActual][NEPTUNO] == 1 && puntosAux == puntos[jugadorActual]){
                                puntos[jugadorActual] += 2;
                                std::cout << "POR ESTAR EN EL PLANETA NEPTUNO Y NO HABER ACERTADO SUMARAS 2 PUNTOS\n";
                            }
                            break;
                        case 5:
                            puntosAux = puntos[jugadorActual];
                            puntos[jugadorActual] += multiplos();
                            if(puntosAux < puntos[jugadorActual] && plaTierra[jugadorActual] == false){
                                darCarta(manoCartas, mazo, jugadorActual);
                            }
                            if(estadoPlanetas[otroJugador][MERCURIO] == 1 && puntosAux == puntos[jugadorActual]){
                                puntos[jugadorActual] += multiplos();
                            }
                            if(estadoPlanetas[jugadorActual][MARTE] == 1 && puntosAux < puntos[jugadorActual]){
                                puntos[jugadorActual] += 5;
                                std::cout << "POR ESTAR EN EL PLANETA MARTE Y HABER ACERTADO LA APUESTA SUMARAS 5 PUNTOS EXTRA\n";
                            }
                            if(estadoPlanetas[jugadorActual][JUPITER] == 1){
                                if(puntosAux == puntos[jugadorActual]){
                                    darCarta(manoCartas, mazo, jugadorActual);
                                    std::cout << "POR ESTAR EN EL PLANETA JUPITER OBTIENES CARTA AUNQUE NO ACIERTES LA APUESTA\n";
                                }
                            }
                            if(estadoPlanetas[jugadorActual][NEPTUNO] == 1 && puntosAux == puntos[jugadorActual]){
                                puntos[jugadorActual] += 2;
                                std::cout << "POR ESTAR EN EL PLANETA NEPTUNO Y NO HABER ACERTADO SUMARAS 2 PUNTOS\n";
                            }
                        break;
                    }
                    break;
                case 2:
                    std::cout << "CANJEAR\n";
                    if(puntos[jugadorActual] < 50){
                        std::cout << "NO TENES PUNTOS SUFICIENTES PARA CANJEAR\n";
                    }else{
                        canjearPlanetas(estadoPlanetas, jugadorActual);
                        contadorJugadas++;
                    }
                    if(estadoPlanetas[jugadorActual][PLUTON] == 1){
                        contadorJugadas = 2;
                        ganador = true;
                        endGame(nombres, jugadorActual);
                        return;
                    }
                    break;
                case 3:
                    std::cout << "USAR CARTA \n";
                    mostrarMano(manoCartas, jugadorActual, puntos);

                    contadorJugadas++;
                    break;
            }
        }///while jugadas
            turno++;
    } ///while ganador

}

int sumar8(){
    int dados[2] = {};
    std::cout << "APUESTA ELEGIDA: SUMAR 8 CON LOS DADOS\n";

    std::cout << "PRESIONA UNA TECLA PARA TIRAR LOS DADOS\n";
    system("pause>null");
    for(int x = 0; x < 2; x++){
        dados[x] = tirarDados();
        std::cout << "DADO " << x + 1 << ": " << dados[x] << "\n";
    }
    if(dados[0] + dados[1] == 8){
        std::cout << "APUESTA ACERTADA! SUMAS 5 PUNTOS\n";

        return 5;
    }else{
        std::cout << "SUERTE PARA LA PROXIMA\n";
        return 0;
    }
}
int dosPares(){
int dados[2] = {};
    std::cout << "APUESTA ELEGIDA: SACAR DOS DADOS PARES\n";

    std::cout << "PRESIONA UNA TECLA PARA TIRAR LOS DADOS\n";
    system("pause>null");
    for(int x = 0; x < 2; x++){
        dados[x] = tirarDados();
        std::cout << "DADO " << x + 1 << ": " << dados[x] << "\n";
    }
    if(dados[0] % 2 == 0 && dados[1] % 2 == 0){
        std::cout << "APUESTA ACERTADA! SUMAS 7 PUNTOS\n";
        return 7;
    }else{
        std::cout << "SUERTE PARA LA PROXIMA\n";
        return 0;
    }
}
int parImpar(){
int dados[2] = {};
    std::cout << "APUESTA ELEGIDA: SACAR DADO PAR Y DADO IMPAR\n";

    std::cout << "PRESIONA UNA TECLA PARA TIRAR LOS DADOS\n";
    system("pause>null");
    for(int x = 0; x < 2; x++){
        dados[x] = tirarDados();
        std::cout << "DADO " << x + 1 << ": " << dados[x] << "\n";
    }
    if(dados[0] % 2 == 0 && dados[1] % 2 != 0){
        std::cout << "APUESTA ACERTADA! SUMAS 5 PUNTOS\n";
        return 5;
    }else{
        std::cout << "SUERTE PARA LA PROXIMA\n";
        return 0;
    }

}
int primo(){
int dados[2] = {};
    std::cout << "APUESTA ELEGIDA: SUMAR UN DADO PRIMO CON LOS DOS DADOS\n";

    std::cout << "PRESIONA UNA TECLA PARA TIRAR LOS DADOS\n";
    system("pause>null");
    for(int x = 0; x < 2; x++){
        dados[x] = tirarDados();
        std::cout << "DADO " << x + 1 << ": " << dados[x] << "\n";
    }
    if(dados[0] + dados[1] == 2 || dados[0] + dados[1] == 3 || dados[0] + dados[1] == 5 || dados[0] + dados[1] == 7 || dados[0] + dados[1] == 11 ){
        std::cout << "APUESTA ACERTADA! SUMAS 10 PUNTOS\n";
        return 10;
    }else{
        std::cout << "SUERTE PARA LA PROXIMA\n";
        return 0;
    }
}
int multiplos(){
int dados[2] = {};
    std::cout << "APUESTA ELEGIDA: SACAR DOS DADOS MULTIPLOS ENTRE SI\n";

    std::cout << "PRESIONA UNA TECLA PARA TIRAR LOS DADOS\n";
    system("pause>null");
    for(int x = 0; x < 2; x++){
        dados[x] = tirarDados();
        std::cout << "DADO " << x + 1 << ": " << dados[x] << "\n";
    }
    if(dados[0] % dados[1] == 0 || dados[1] % dados[0] == 0 ){
        std::cout << "APUESTA ACERTADA! SUMAS 9 PUNTOS\n";
        return 9;
    }else{
        std::cout << "SUERTE PARA LA PROXIMA\n";
        return 0;
    }
}
int canjearPlanetas(int estadoPlanetas[][9], int jugador){
    int planetaActual;
    for(int x = 0; x < 9; x++){
        if(estadoPlanetas[jugador][x] == 1){
            planetaActual = x;
        }
    }
    estadoPlanetas[jugador][planetaActual] = 0;
    estadoPlanetas[jugador][planetaActual + 1] = 1;
}
void darCarta(int manoCartas[][5], int mazo[], int jugadorActual){
    int carta;
    bool bandera = false;
    int posicion = 0;
    int contadorValidacion = 0;

    for(int x = 0; x < 5; x++){
        if(manoCartas[jugadorActual][x] > 0){
            contadorValidacion++;
        }
    }
    if(contadorValidacion == 5){
        std::cout << "NO PUEDES OBTENER MAS CARTAS HASTA QUE USES ALGUNA DE TU MANO\n";
        return;
    }
    while(bandera == false){
        carta = rand() % 40;
        if(mazo[carta] != 0){
            if(manoCartas[jugadorActual][posicion] == 0){
                manoCartas[jugadorActual][posicion] == mazo[carta];
                mazo[carta] = 0;
                bandera = true;
            }else{
                posicion++;
            }
        }
    }
    std::cout << "GANASTE UNA CARTA\n";
}

void mostrarMano(int manoCartas[][5], int jugadorActual, int puntos[]){
    bool bandera = false;
    int opcion;
    int otroJugador;

    if(jugadorActual == 0){
        otroJugador = 1;
    }else{
        otroJugador = 0;
    }
    while(bandera != true){
        for(int x = 0; x < 5; x++){
            if(manoCartas[jugadorActual][x] == 1){
                std::cout << x + 1 << ". SUMAR 5 PUNTOS\n";
            }else if(manoCartas[jugadorActual][x] == 2){
                std::cout << x + 1 << ". ROBAR 2 PUNTOS\n";
            }else if(manoCartas[jugadorActual][x] == 3){
                std::cout << x + 1 << ". RESTAR AL OPONENTE 3 PUNTOS\n";
            }else{
                std::cout << x + 1 << ". VACIO\n";
            }
        }
        std::cout << "6. VOLVER\n";
        std::cin >> opcion;
        if(manoCartas[jugadorActual][opcion - 1] == 1){
            puntos[jugadorActual] += 5;
            bandera = true;
        }else if(manoCartas[jugadorActual][opcion - 1] == 2){
            puntos[jugadorActual] += 2;
            puntos[otroJugador] -= 2;
            bandera = true;
        }else if(manoCartas[jugadorActual][opcion - 1] == 3){
            puntos[otroJugador] -= 3;
            bandera = true;
        }else if(opcion == 6){
            return;
        }else{
            std::cout << "NO HAY CARTA EN ESA OPCION\n";
        }
    }
}
int escalera(){
    int dados[6] = {};
    int aux;
    int contador = 0;
    for(int x = 0; x < 6; x++){
        dados[x] = rand() % 6 + 1;
    }
    for(int x = 0; x < 6; x++){
        for(int z = 0; z < 5; z++){
            if(dados[x] > dados[x + 1]){
                aux = dados[x];
                dados[x] = dados[x + 1];
                dados[x + 1] = aux;
            }
        }
    }
    for(int x = 0; x < 5; x ++){
        if(dados[x + 1] == dados[x] + 1){
            contador++;
        }
    }
    if(contador == 5){
        std::cout << "ESCALERA OBTENIDA! SUMAS 100 PUNTOS\n";
        return 100;
    }else{
        std::cout << "NO OBTUVISTE ESCALERA\n";
        return 0;
    }
}
void endGame(std::string nombres[], int jugadorActual){
    std::cout << "FELICITACIONES " << nombres[jugadorActual] << " GANASTE EL JUEGO!!!\n";
}
std::string locacion(int estadoPlaneta[][9], int jugador){
    std::string nombrePlanetas[9] = {"Mercurio", "Venus", "Tierra", "Marte", "Jupiter", "Saturno", "Urano", "Neptuno", "Pluton"};
    std::string actual;

    for(int x = 0; x < 9; x++){
        if(estadoPlaneta[jugador][x] == 1){
            actual = nombrePlanetas[x];
        }
    }
    return actual;
}
