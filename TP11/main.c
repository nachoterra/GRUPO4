/*
 * TP11 EJERCICIO 2
 */

/* 
 * File:   main.c
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "palindromo.h"

#define MAX_CADENA 100		//Máxima cantidad de letras de la palabra a ingresar
#define CONVERT 32		// se define una constante para convertir a las mayusculas en minusculas
#define ERROR -1
int obtener_cadena (char cadena[MAX_CADENA]);

int main(int argc, char** argv) 
{
    
    char cadena[MAX_CADENA];
    int largo=1, valid;
    
    while (largo != ERROR)  //si hay error termina
    {
        printf("Introducir cadena:");
        largo= obtener_cadena(cadena);
        if (largo != ERROR)             //si hay un error lo imprime
        {
            printf("Ingreso a evaluar:%s\n", cadena);
            valid= palindromo (cadena, &cadena[largo-1]); //verifica si la cadena cumple lo pedido
            if (valid)
            {
                printf("La cadena es un polindromo\n");
            }
            else
            {
                printf("La cadena NO es un polindromo\n");
            }
        }
        else
        {
            printf("ERROR: supero largo maximo de la cadena\n");
        } 
   
    }
   
    return 0;
}

int obtener_cadena (char cadena[MAX_CADENA]) // guarda las letras y numeros de la cadena ingresada, cualquier otro simbolo no es permitido
{   
    int i=0;
    char  caracter=0;
    while(((caracter=getchar()) != '\n') && (i<MAX_CADENA))
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
    
    if (i== MAX_CADENA)
    {
        return ERROR;  //devuelve error si la cadena introducida supera el alrgo establecido
    }
    else
    {
        return (i); //devuelve el largo de la cadena
    }
        
    
    
}

