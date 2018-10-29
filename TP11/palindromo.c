
/* 
 * File:   palindromo.c
 * Author: nacho
 * 
 * Created on 28 de octubre de 2018, 18:17
 */

#include "palindromo.h"

int palindromo (const char *str)
{s
    int resultado,i=0,j=0,cambio=0;
    char mat1 [100];
    char mat2 [100];
    if (*str == '\0')
    {
        cambio = 2;
        return 0;
    }
    else
    {
        int len;
        len = 1 + palindromo(str+1);
        if (cambio = 0)
        {
            mat1 [j] = len;
            j++;
        }
        else
        {
            mat2 [i] = len;
            i++;
        }
        len = 1 + palindromo(str+1);
      
        return len;
    }
}


