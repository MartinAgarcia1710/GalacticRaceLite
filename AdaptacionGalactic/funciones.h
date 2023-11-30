#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <string>

void presentacionJugadores(std::string nombres[]);
int tiradaTurno(std::string nombres[]);
int tirarDados();
void desarrolloJuego(std::string nombres[], int puntos[]);
int sumar8();
int dosPares();
int parImpar();
int primo();
int multiplos();
int canjearPlanetas(int estadoPlanetas[][9], int jugador);
void darCarta(int manoCartas[][5], int mazo[], int jugadorActual);
void mostrarMano(int manoCartas[][5], int jugadorActual, int puntos[]);
int escalera();
void endGame(std::string nombres[], int jugadorActual);
std::string locacion(int estadoPlaneta[][9], int jugador);
#endif // FUNCIONES_H_INCLUDED
