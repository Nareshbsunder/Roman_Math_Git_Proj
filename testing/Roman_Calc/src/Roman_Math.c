#include "Roman_Math.h"
#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static const int MAX_POSSIBLE_LENGTH_OF_NUMERAL = 16;
static bool FoundCluster = false;

// This function Takes the number and changes it into
// a Roman Numeral.
char *convert_to_Roman(int number)
{
	char *roman = calloc(MAX_POSSIBLE_LENGTH_OF_NUMERAL, sizeof(char));
	while (number > 0)
	{
	    strcat(roman,"\0");
		if (number >= 1000)
		{
			strcat(roman,"M");
			number -= 1000;
		}
		else if (number>=900)
        {
            strcat(roman,"CM");
			number -= 900;
        }
		else if (number >= 500)
		{
			strcat(roman,"D");
			number -= 500;
		}
		else if (number >= 400)
		{
			strcat(roman,"CD");
			number -= 400;
		}
		else if (number >= 100)
		{
			strcat(roman,"C");
			number -= 100;
		}
		else if (number >= 90)
		{
			strcat(roman,"XC");
			number -= 90;
		}
		else if (number >= 50)
		{
			strcat(roman,"L");
			number -= 50;
		}
		else if (number >= 40)
		{
			strcat(roman,"XL");
			number -= 40;
		}
		else if (number >= 10)
		{
			strcat(roman,"X");
			number -= 10;
		}
		else if (number >= 9)
		{
			strcat(roman,"IX");
			number -= 9;
		}
		else if (number >= 5)
		{
			strcat(roman,"V");
			number -= 5;
		}
		else if (number >= 4)
		{
			strcat(roman,"IV");
			number -= 4;
		}
		else
		{
			strcat(roman,"I");
			number -= 1;
		}
	}
	return roman;
}

int convert_Roman_Cluster(char *roma)
{
	int number = 0;
	if(strcmp(roma,"CM")==0)
    {
		number = 900;
	}
	else if(strcmp(roma,"CD")==0)
    {
		number = 400;
	}
	else if(strcmp(roma,"XC")==0)
    {
		number = 90;
	}
	else if(strcmp(roma,"XL")==0)
    {
		number = 40;
	}
	else if(strcmp(roma,"IX")==0)
    {
		number = 9;
	}
	else if(strcmp(roma,"IV")==0)
    {
		number = 4;
	}
	else
	{
		FoundCluster = false;
	}
	if(number>0)
	{
		FoundCluster = true;
	}
	return number;
}

//This function Takes the Roman Numeral and changes it into a
//number and it also tests to find if a bad value is
//present.
int convert_to_decimal(char *roman)
{
	int number = 0;
	int i;
	char arr[3]="";
	int clusternumber;
	for (i = 0; i<strlen(roman); i++)
	{
		arr[0] = roman[i];
		arr[1] = roman[i+1];
		arr[2] = '\0';
		clusternumber = convert_Roman_Cluster(arr);
		number = number+clusternumber;
		if(FoundCluster)
		{
			i = i+1;
			FoundCluster = false;
			continue;
		}
		else
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
				printf("Data error\n");
			}
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

