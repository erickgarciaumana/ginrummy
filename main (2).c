#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "naipe.h"

char valorcombina;


int main()


{
  printf("==============================================\n");
  printf("Para consultar las reglas de Gin Rummy vaya a la dirección:\n");
  printf("https://en.wikipedia.org/wiki/Gin_rummy\n");
  printf("==============================================\n");  
  printf("\n");
  printf("==============================================\n");
   printf("Tipos de Palos de la Baraja de Naipes:\n");
  printf("Diamantes = 0\n");
  printf("Corazones = 1\n");
  printf("Flores    = 2\n");
  printf("Espadas   = 3\n");
  printf("==============================================\n");  
  printf("\n");
  printf("==============================================\n");
  printf("Baraja:\tAS=1, 2,3,4,5,6,7,8,9,10\n");
  printf("\t\tJota=11, Quina=12, Ka=13\n");
  printf("==============================================\n");  
  printf("\n");
  
  
  srand(time(0));

    Baraja *baraja = crear_baraja(); // imprimir_baraja(baraja);

    //Carta **mano = repartir(baraja, 53); // mano == NULL
    //imprimir_mano(mano, 53);

    printf("==============================================\n");
    printf("Jugador 1\n"); 
    printf("==============================================\n");
    Carta **mano2 = repartir(baraja, 10);
    imprimir_mano(mano2, 10);
     
    printf("\n");
    printf("==============================================\n");
    printf("Jugador 2\n"); 
    printf("==============================================\n");
    Carta **mano3 = repartir(baraja, 10);
    imprimir_mano(mano3, 10);

    printf("\n");
    printf("==============================================\n");
    printf("Jugador 1: tiene alguna combinacion de cartas \n");
    printf("Opciones Y/N \n");
    printf("==============================================\n");

    scanf("%c", &valorcombina);
  
  switch(valorcombina){
    case 'Y':
    printf("Value of i = %c\n",valorcombina);
      break;

    case 'N':
    printf("Sigue el jugador 2\n");
     break; 
  
    default:
    printf("Error! Respuesta erronea\n");
    
    }
  
  return 0;
}