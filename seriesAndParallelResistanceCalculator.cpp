/* 
	Filename: FUNCTION AND PASS BY DATA, ADDRESS AND REFRENCE
	Author: Talha Tallat (D18124645)
	Date Started: 02/10/2019
	Description: * This program allows user to enter3 resistor valess and calculte and displayes the series and parallel resistance.
				 * The program includes 3 seprate functions that illustrate pass by data, pass by address and pass by reference.
				 * Debuging, verifying and validating the application. 
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h> 

using namespace std;

void explain_program(void);
void askUserTheSeriesResistance (float &res1, float &res2, float &res3);

float calculate_series_resistance_by_data (float res1, float res2, float res3);
float calculate_Parallel_resistance_by_data (float Res1, float Res2, float Res3);

float calculate_series_resistance_by_address (float *res1, float *res2, float *res3);
float calculate_Parallel_resistance_by_address (float *res1, float *res2, float *res3);

float calculate_series_resistance_by_Reference ( float &resistor1, float &resistor2, float &resistor3);
float calculate_Parallel_resistance_by_Reference ( float &resistor1, float &resistor2, float &resistor3);


void main ()
{
	float resistor1;
	float resistor2;
	float resistor3;
	float totalResistance;

	
	explain_program();
	askUserTheSeriesResistance (resistor1 , resistor2 , resistor3);

	totalResistance = calculate_series_resistance_by_data (resistor1, resistor2, resistor3);
	printf("\n\nTotal series resistance by data => %f", totalResistance);

	totalResistance = calculate_Parallel_resistance_by_data (resistor1, resistor2, resistor3);
	printf("\nTotal Parallel resistance by data => %f", totalResistance);

	calculate_series_resistance_by_address ( &resistor1, &resistor2, &resistor3);
	calculate_Parallel_resistance_by_address ( &resistor1, &resistor2, &resistor3);

	calculate_series_resistance_by_Reference ( resistor1, resistor2, resistor3);
	calculate_Parallel_resistance_by_Reference ( resistor1, resistor2, resistor3);
}

/*--------------------------------------Function Defination----------------------------------------------*/
void explain_program()
{
	printf ("\nThis program will ask you to enter three resistor values to\ncalculate series and parallel resistance. ");
	printf ("\nThe program includes 3 seprate funations for series and\nparallel calculations that show, pass by data, pass by address and\npass by reference.");
} // end of the explain_program 

/*--------------------------Get funtion asking user for the vales----------------------------------------*/
void askUserTheSeriesResistance (float &resistance1, float &resistance2, float &resistance3)
{
	float firstResistance;
	float secoundResistance;
	float thiredResistance;
	
	printf ("\n\nInput the 1st resistor value in ohms => ");
	scanf_s ("%f", &firstResistance);
	printf ("\nInput the 2nd resistor value in ohms => ");
	scanf_s ("%f", &secoundResistance);
	printf ("\nInput the 3rd resistor value in ohms => ");
	scanf_s ("%f", &thiredResistance);
	
	resistance1 = firstResistance;
	resistance2 = secoundResistance;
	resistance3 = thiredResistance;	
}

/*--------------------------------------Pass by Data-----------------------------------------------------*/
//Series resistance
float calculate_series_resistance_by_data (float resistor1, float resistor2, float resistor3)
{
	return (resistor1 + resistor2 + resistor3);
}

//Parallel resistance
float calculate_Parallel_resistance_by_data (float resistor1, float resistor2, float resistor3)
{
	return (1/((1/resistor1) + (1/ resistor2) + (1/ resistor3)));
}

/*--------------------------------------Pass by Address--------------------------------------------------*/
//Series resistance
float calculate_series_resistance_by_address (float *resistor1, float *resistor2, float *resistor3)
{
	float totalResistance = (*resistor1) + (*resistor2) + (*resistor3);
	printf("\n\nTotal series resistance by address => %f", totalResistance);
	return totalResistance ;
}

//Parallel resistance
float calculate_Parallel_resistance_by_address (float *resistor1, float *resistor2, float *resistor3)
{
	float total_Parallel_Resistance = (1/((1/ *resistor1) + (1/ *resistor2) + (1/ *resistor3)));
	printf("\nTotal Parallel resistance by address => %f", total_Parallel_Resistance );
	return total_Parallel_Resistance;
}

/*--------------------------------------Pass by Reference-----------------------------------------------*/
//Series resistance
float calculate_series_resistance_by_Reference (float &resistor1, float &resistor2, float &resistor3)
{
	float totalResistance1 = (resistor1) + (resistor2) + (resistor3);
	printf("\n\nTotal series resistance by Reference => %f", totalResistance1);
	return totalResistance1 ;
}

//Parallel resistance
float calculate_Parallel_resistance_by_Reference (float &resistor1, float &resistor2, float &resistor3)
{
	float total_Parallel_Resistance1 = (1/((1/ resistor1) + (1/ resistor2) + (1/ resistor3)));
	printf("\nTotal Parallel resistance by Reference => %f", total_Parallel_Resistance1 );
	return total_Parallel_Resistance1;
}
