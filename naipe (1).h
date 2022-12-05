#include <stdlib.h>

typedef enum Palo
{
    Diamantes,
    Corazones,
    Flores,
    Espadas
} Palo;

typedef enum Numero
{
    As,
    Dos,
    Tres,
    Cuatro,
    Cinco,
    Seis,
    Siete,
    Ocho,
    Nueve,
    Diez,
    Jota,
    Quina,
    Ka
} Numero;

typedef struct Carta
{
    Palo mazo;
    Numero numero;
} Carta;

typedef struct Baraja
{
    Carta cartas[52];
    short cartas_repartidas[52];
    int cartas_disponibles;
} Baraja;

Baraja *crear_baraja();
Carta **repartir(Baraja *, int);
void imprimir_baraja(Baraja *);
void imprimir_mano(Carta **, size_t);