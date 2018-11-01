#include <stdio.h>
#include <string.h>

#include "led_board.h"


#define LOW 0
#define HIGH 1
#define ERROR 9
#define FIN 10
#define MASC 0xFF 	//Mascara definida en FF ya que deben cambiar todos los los bits del puerto


int get_word (BITSA *);		//Funcion para obetener el caracter ASCII y controlar el programabra
int get_int(int c);			//Convierte el caracter ASCII en un entero


int main (void)
{
	int c,cond=HIGH;	
	BITSA porta; //defino la estructura 
	BITSA *p;
	p = &porta;
	while(cond)	
	{
		printf ("Ingrese su opción:");
		c = get_word(p);	//obtengo el caracter
		if (c != ERROR)
		{
			display_port(&porta); 
		}
		if (c == FIN)
		{
			cond = LOW;	//Condicion para salir del loop
		}
	}
	printf ("PROGRAMA FINALIZADO\n");
	return 0;
}	



int get_word (BITSA *porta)
{
	int c,letra,masc = MASC;	
	while ( (c = getchar()) != '\n' )
	{
		if ( (c >= '0') && (c <= '7'))
		{
			c = get_int(c);		//Conversion de ASCI a entero
			bitSet(porta,c);	
			letra=c;		//conservo el valor de la ultijma letra antes del enter	
		}
		else
		{
			switch	(c)
			{
				case 't':		
				maskToggle(porta,masc); 
				letra=c;
				break;
				case 'c':
				maskOff(porta,masc);
				letra=c;
				break;
				case 's':
				maskOn(porta,masc);
				letra=c;
				break;
				case 'q':
				c = FIN;
				letra=c;
				break;
				default:
				printf ("INGRESO INCORRECTO\n");
				letra = ERROR;
				break;
			}
		}
	}
	return letra;
}

int get_int (int c)
{
	c = c - '0';
	return c;
}















