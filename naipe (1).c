#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "naipe.h"

Baraja *crear_baraja()
{
    Baraja *baraja = malloc(sizeof(Baraja));

    baraja->cartas_disponibles = 52;
    memset(baraja->cartas_repartidas, 1, 53 * sizeof(short));

    for (int Palo = 0; Palo <= 3; Palo++)
    {
        for (int numero = 1; numero <= 13; numero++)
        {
            int num_carta = (Palo * 13) + numero;
            baraja->cartas[num_carta].mazo = Palo;
            baraja->cartas[num_carta].numero = numero;
        }
    }

    return baraja;
}

Carta **repartir(Baraja *baraja, int cantidad)
{
    if (cantidad > baraja->cartas_disponibles)
    {
        return NULL;
    }

    Carta **cartas_repartidas = malloc(sizeof(Carta *) * cantidad);

    int repartidas = 0;
    while (repartidas < cantidad)
    {
        int carta_aleatoria = rand() % 52;

        if (baraja->cartas_repartidas[carta_aleatoria] == 1)
        {
            continue;
        }

        cartas_repartidas[repartidas] = &baraja->cartas[carta_aleatoria];
        baraja->cartas_repartidas[carta_aleatoria] = 1;
        baraja->cartas_disponibles--;
        repartidas++;
    }

    return cartas_repartidas;
}

void imprimir_baraja(Baraja *baraja)
{
    printf("Baraja (%d):\n", baraja->cartas_disponibles);
    for (int carta = 0; carta < 52; carta++)
    {
        Carta actual = baraja->cartas[carta];
        printf(
            "%d - Numero: %d,Palo: %d, Repartida?: %d\n",
            carta,
            actual.numero,
            actual.mazo,
            baraja->cartas_repartidas[carta]);
    }
}

void imprimir_mano(Carta **mano, size_t cantidad)
{
    if (mano == NULL)
    {
        printf("No hay mano.\n");
        return;
    }

    for (int carta = 0; carta < cantidad; carta++)
    {
        Carta *actual = mano[carta];
        printf(
            "Numero: %d, Palo: %d\n",
            actual->numero,
            actual->mazo);
    }
}