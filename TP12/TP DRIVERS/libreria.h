
#ifndef LIB
#define LIB
#include <stdint.h>


typedef struct
{
	uint8_t a0	:1;
	uint8_t	a1	:1;
	uint8_t	a2	:1;
	uint8_t	a3	:1;
	uint8_t	a4	:1;
	uint8_t	a5	:1;
	uint8_t	a6	:1;
	uint8_t	a7	:1;
}BITSA;

typedef struct
{
	uint8_t	b0	:1;
	uint8_t	b1	:1;
	uint8_t	b2	:1;
	uint8_t	b3	:1;
	uint8_t	b4	:1;
	uint8_t	b5	:1;
	uint8_t	b6	:1;
	uint8_t	b7	:1;
}BITSB;

typedef union
{
	char a;
	BITSA	ai;
	
} PORTA;

typedef union
{
	char b;
	BITSB 	bi;
	
} PORTB;

typedef struct
{
	PORTB	lo;
	PORTA	hi;

}PORTAB;

typedef union
{
	int d;
	PORTAB 	ab;

}PORTD;




extern void bitSet (BITSA *, int);	//Pone en 1 el bit del puerto indicado
extern void bitClr (BITSA *, int);	//Pone en 0 el bit del puerto indicado
extern int bitGet (BITSA *, int);	//Obtiene el valor del bit del puerto indicado
extern void bitToggle (BITSA * , int);	//Cambia el valor del bit del puerto indicado
extern void maskOn (BITSA *,int);	//Pone 1s en un registro de 8 bits segun indique una mascara
extern void maskOff (BITSA *,int);	//Pone 0s en un registro de 8 bits segun indique una mascara
extern void maskToggle (BITSA *,int);	//Cambia el valor de los bits en un registro de 8 bits segun indique una mascara



#endif