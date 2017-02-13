#include "Roman_Math.h"
#include<string.h>
#include<stdio.h>
#include <stdlib.h>

static const int MAX_POSSIBLE_LENGTH_OF_NUMERAL = 16;

// This function Takes the number and changes it into
// a Roman Numeral.
char *convert_to_Roman(int number)
{
	char *roman = calloc(MAX_POSSIBLE_LENGTH_OF_NUMERAL, sizeof(char));
        if (number == 0)
        {
	    strcat(roman,"BADROMANNUMBER");
        }
	while (number > 0)
	{
	    strcat(roman,"\0");
		if (number >= 1000)
		{
			strcat(roman,"M");
			number -= 1000;
		}
		else if (number >= 500)
		{
			strcat(roman,"D");
			number -= 500;
		}
		else if (number >= 100)
		{
			strcat(roman,"C");
			number -= 100;
		}
		else if (number >= 50)
		{
			strcat(roman,"L");
			number -= 50;
		}
		else if (number >= 10)
		{
			strcat(roman,"X");
			number -= 10;
		}
		else if (number >= 5)
		{
			strcat(roman,"V");
			number -= 5;
		}
		else 
		{
			strcat(roman,"I");
			number -= 1;
		}
	}
	return roman;
}

//This function Takes the Roman Numeral and changes it into a
//number and it also tests to find if a bad value is
//present.
int convert_to_decimal(char *roman)
{
	int number = 0;
	int i;

	for (i = 0; i<strlen(roman); i++)
	{
		switch (roman[i])
		{
		case 'M':
			number += 1000;
			break;
		case 'D':
			number += 500;
			break;
		case 'C':
			number += 100;
			break;
		case 'L':
			number += 50;
			break;
		case 'X':
			number += 10;
			break;
		case 'V':
			number += 5;
			break;
		case 'I':
			number += 1;
			break;
		default:
			printf("Dataerror\n");
		}
	}
	return number;
}
//This function performs the roman calculation as it reads the smallest
//amount of Roman Numerals possible.
int calc_Romans(int num1, int num2, char oper)
{
	switch (oper)
	{
	case '+':
		return num1 + num2;
		break;
	case '-':
	    if(num1>=num2)
		{
			return num1 - num2;
		}
		else
		{
			return num2-num1;
		}
		break;
	case '*':
		return num1*num2;
		break;
	case '/':
		if (num2 != 0)
		{
			return num1 / num2;
		}
		else
			break;
	}
	return 0;
}
//Main function which integrates all roman calculations.
char *Compute_Roman_Math(char *romanOne, char *romanTwo, char oper)
{
	char *romanResult;
	int rmnum1, rmnum2, rmnumResult;
	rmnum1 = convert_to_decimal(romanOne);
	rmnum2 = convert_to_decimal(romanTwo);
	rmnumResult = calc_Romans(rmnum1, rmnum2, oper);
	romanResult = convert_to_Roman(rmnumResult);
	return romanResult;
}
