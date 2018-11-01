#include <stdio.h>
#include <string.h>
#include "led_board.h"


void display_port (BITSA *port) 
{ 
	if(port->a0)
	{
		put_command(DIREC(17),VALUE(17),"17",'1');
	}
	else
	{
		put_command(DIREC(17),VALUE(17),"17",'0');
	
	}
	if(port->a1)
	{
		put_command(DIREC(4),VALUE(4),"4",'1');
	}
	else
	{
		put_command(DIREC(4),VALUE(4),"4",'0');
	
	}
	if(port->a2)
	{
		put_command(DIREC(18),VALUE(18),"18",'1');
	}
	else
	{
		put_command(DIREC(18),VALUE(18),"18",'0');
	
	}
	if(port->a3)
	{
		put_command(DIREC(23),VALUE(23),"23",'1');
	}
	else
	{
		put_command(DIREC(23),VALUE(23),"23",'0');
	
	}
	if(port->a4)
	{
		put_command(DIREC(24),VALUE(24),"24",'1');
	}
	else
	{
		put_command(DIREC(24),VALUE(24),"24",'0');
	
	}
	if(port->a5)
	{
		put_command(DIREC(25),VALUE(25),"25",'1');
	}
	else
	{
		put_command(DIREC(25),VALUE(25),"25",'0');
	
	}
	if(port->a6)
	{
		put_command(DIREC(22),VALUE(22),"22",'1');
	}
	else
	{
		put_command(DIREC(22),VALUE(22),"22",'0');
	
	}
	if(port->a7)
	{
		put_command(DIREC(27),VALUE(27),"27",'1');
	}
	else
	{
		put_command(DIREC(27),VALUE(27),"27",'0');
	
	}
}


void put_command (char* dir,char* val, char* pin, char state) //prende o apaga el led indicado
{	
	FILE *archivo;
   /***************************
	*			EXPORT		  *
	***************************/
	archivo =  fopen(EXPORT,"w");
	fprintf(archivo,"%s", pin); 
	fflush(archivo);	
  	fclose(archivo);
   /***************************
	*			OUTPUT		  *
	***************************/
   	archivo = fopen(dir,"w");	
	fputs("out",archivo);
	fclose(archivo); 

   /***************************
	*			SETPIN	  	  *
	***************************/
	archivo = fopen(val,"w");
	fputc(state ,archivo);
	fclose(archivo);
}