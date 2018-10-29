
/* 
 * File:   palindromo.c
 * Author: nacho
 * 
 * Created on 28 de octubre de 2018, 18:17
 */

#include "palindromo.h"

int palindromo (const char *str,int len)
{
	if ((*str == *(str[len-1])) && (*str != '\0'))
	{	
		int res;
		res = palindromo (str+1, len-1);
		printf ("valido");
		return res;
	}
	else
	{
		printf ("invalido");
		return 0;
	}
}