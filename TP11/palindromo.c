
/* 
 * File:   palindromo.c
 * Author: nacho
 * 
 * Created on 28 de octubre de 2018, 18:17
 */

#include "palindromo.h"

int palindromo (const char *str)
{s
    int i=0,j=0,cambio=0;
    char mat1 [100];
    char mat2 [100];
    if (*str == '\0')
    {
        cambio = 1;
        return 0;
    }
    else
    {
        int len;
        
        if (cambio == 0)
        {
            mat1 [j] = len;
            j++;
        }
        
        len = palindromo(str+1);
        mat2 [i] = len;
            i++;
      
        return len;
    }
}


