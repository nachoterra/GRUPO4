

#ifndef LED_BOARD_H
#define LED_BOARD_H

#include <stdint.h>
#include "libreria.h"

#define VALUE(s)  	"/sys/class/gpio/gpio"#s"/value"		//string con la direccion de la carpeta value
#define DIREC(s) 	"/sys/class/gpio/gpio"#s"/direction"	//string con la direccion de la carpeta direction
#define EXPORT 		"/sys/class/gpio/export"				//string con la direccion de la carpeta export


void display_port (BITSA *);	//Muestra en pantalla los 8 bits de algun puerto
void put_command (char* dir,char* val, char* pin, char state);	//prende o apaga el led indicado



#endif /* LED_BOARD_H */