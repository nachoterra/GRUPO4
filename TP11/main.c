/*
 * TP11 EJERCICIO 2
 */

/* 
 * File:   main.c
 * Author: nacho
 */

#include <stdio.h>
#include <stdlib.h>
#include "palindromo.h"

#define MAX_CADENA 100		//Máxima cantidad de letras de la palabra a ingresar
#define CONVERT 32		// se define una constante para convertir a las mayusculas en minusculas

void obtener_cadena (char cadena[MAX_CADENA]);

int main(int argc, char** argv) 
{
    
    char cadena[MAX_CADENA];
    obtener_cadena(cadena);
    
    printf("%s\n", cadena);
    return 0;
}

void obtener_cadena (char cadena[MAX_CADENA]) // guarda las letras y numeros de la cadena ingresada, cualquier otro simbolo no es permitido
{   
    int i=0;
    char  caracter=0;
    while((caracter=getchar()) != '\n')
    {
        if (((caracter >= 'a' ) && (caracter <= 'z')) || ((caracter >= 'A' ) && (caracter <= 'Z')))  //permite que la cadena sea solo de letras
	{
	    if (( caracter >= 'A') && (caracter <= 'Z'))
            {
		caracter = caracter + CONVERT;		//Convierte mayuscula en minuscula
            }
            cadena[i++] = caracter;	
	}
        else if ((caracter >= '0' ) && (caracter <= '9')) // tambien acepta numeros
        {
            cadena[i++] = caracter;
        }
        
    }
    cadena[i]=0; //terminador de la cadena
}

