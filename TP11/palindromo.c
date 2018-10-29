
/* 
 * File:   palindromo.c
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "palindromo.h"

int palindromo ( char *cadena,char *inver)
{      ;
	if ( cadena[0]=='\0' ) //caso base si es una sola letra o sin letras
	{	
            return 1; //valido
	}
	else if (cadena[0]!= inver[0]) // primera y ultima letra distintas
	{
		
            return 0; //no valido
	}
        else
        {
            return (palindromo(cadena+1,inver-1)); //prueba toda la cadena
        }
}