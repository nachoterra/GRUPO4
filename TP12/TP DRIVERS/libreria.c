#include <stdio.h>
#include "libreria.h"


#define LOW 0
#define HIGH 1
#define ERROR 9
#define FIN 10
#define MASC 0xFF 	//Mascara definida en FF ya que deben cambiar todos los los bits del puerto

void bitSet (BITSA *porta, int bit)
{
	switch (bit)				//Switch que determina que bit del puerto sera puesto en 1
	{
		case 0:
			porta->a0 = HIGH;
		break;
		case 1:
			porta->a1 = HIGH;
		break;
		case 2:
			porta->a2 = HIGH;
		break;
		case 3:
			porta->a3 = HIGH;
		break;
		case 4:
			porta->a4 = HIGH;
		break;
		case 5:
			porta->a5 = HIGH;
		break;
		case 6:
			porta->a6 = HIGH;
		break;
		case 7:
			porta->a7 = HIGH;
		break;
		default:
		printf ("Número de bit incorrecto\n");
		break;
	}
}

void bitClr (BITSA *porta, int bit)		//Switch que determina que bit del puerto sera puesto en 0
{
	switch (bit)
	{
		case 0:
			porta->a0 = LOW;
		break;
		case 1:
			porta->a1 = LOW;
		break;
		case 2:
			porta->a2 = LOW;
		break;
		case 3:
			porta->a3 = LOW;
		break;
		case 4:
			porta->a4 = LOW;
		break;
		case 5:
			porta->a5 = LOW;
		break;
		case 6:
			porta->a6 = LOW;
		break;
		case 7:
			porta->a7 = LOW;
		break;
		default:
		printf ("Número de bit incorrecto\n");	//proteccion contra ingresos incorrectos
		break;
	}
}

int bitGet (BITSA *porta, int bit)			//Switch que obtiene el valor del bit indicado del puerto 
{
	int bit_status;
	switch (bit)
	{
		case 0:
			bit_status = porta->a0;
		break;
		case 1:
			bit_status = porta->a1;
		break;
		case 2:
			bit_status = porta->a2;
		break;
		case 3:
			bit_status = porta->a3;
		break;
		case 4:
			bit_status = porta->a4;
		break;
		case 5:
			bit_status = porta->a5;
		break;
		case 6:
			bit_status = porta->a6;
		break;
		case 7:
			bit_status = porta->a7;
		break;
		default:
		printf ("Número de bit incorrecto\n");	//proteccion contra ingresos incorrectos
		break;
	}	
	return bit_status;
}

void bitToggle (BITSA *porta, int bit)		//Switch que invierte el valor del bit del puerto 
{
	int bit_status;	
	bit_status = bitGet (porta, bit);	//Obtengo el valor del bit 
	switch (bit)
	{
		case 0:
			if (bit_status == HIGH)
			{
				bitClr (porta,bit);
			}
			else
			{
				bitSet (porta,bit);
			}
		break;
		case 1:
			if (bit_status == HIGH)
			{
				bitClr (porta,bit);
			}
			else
			{
				bitSet (porta,bit);
			}
		break;
		case 2:
			if (bit_status == HIGH)
			{
				bitClr (porta,bit);
			}
			else
			{
				bitSet (porta,bit);
			}
		break;
		case 3:
			if (bit_status == HIGH)
			{
				bitClr (porta,bit);
			}
			else
			{
				bitSet (porta,bit);
			}
		break;
		case 4:
			if (bit_status == HIGH)
			{
				bitClr (porta,bit);
			}
			else
			{
				bitSet (porta,bit);
			}
		break;
		case 5:
			if (bit_status == HIGH)
			{
				bitClr (porta,bit);
			}
			else
			{
				bitSet (porta,bit);
			}
		break;
		case 6:
			if (bit_status == HIGH)
			{
				bitClr (porta,bit);
			}
			else
			{
				bitSet (porta,bit);
			}
		break;
		case 7:
			if (bit_status == HIGH)
			{
				bitClr (porta,bit);
			}
			else
			{
				bitSet (porta,bit);
			}
		break;
		default:
		printf ("Número de bit incorrecto\n");		//proteccion contra ingresos incorrectos
		break;
	}	
	

}

void maskOn (BITSA *porta,int masc)
{
	int cont ,cont1 = LOW,masc1;
	while (cont1 <= 7)		//cantidad de bits del puerto
	{
		cont = 2 ^ cont1;	//Bit de la mascara a analizar
		masc1 = cont || masc;
		if (masc1 == HIGH)	//si el bit de la mascara es un 1, procedo a poner el valor del puerto en 1	
		{
			bitSet (porta,cont1);	
		}
		cont1++;	
	}			
}

void maskOff (BITSA *porta,int masc)
{
	int cont ,cont1 = LOW,masc1;
	while (cont1 <= 7)
	{
		cont = 2 ^ cont1;
		masc1 = cont || masc;	//si el bit de la mascara es un 1, procedo a poner el valor del puerto en 0
		if (masc1 == HIGH)
		{
			bitClr (porta,cont1);	
		}
		cont1++;
	}			
}

void maskToggle (BITSA *porta, int masc)
{
	int cont ,cont1 = LOW,masc1;
	while (cont1 <= 7)
	{
		cont = 2 ^ cont1;
		masc1 = cont || masc;	//si el bit de la mascara es un 1, procedo a cambiar el valor del bit del puerto
		if (masc1 == HIGH)
		{
			bitToggle (porta,cont1);	
		}
		cont1++;	
	}			
}