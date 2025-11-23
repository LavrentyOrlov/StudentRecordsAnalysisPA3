/*
Programmer: Lavrenty "Larry" Orlov
Class: CptS 121; Lab Section 10L
Programming Assignment: Programming Assignment 3 - Statistical Analysis of Student Records
Date: 9/16/2025
Description: This program uses functions to read numerical records for five students from a 
.txt file, perform calculations based on that input data, and return the results of those 
calculations to a second .txt file.
*/

#include "StudentRecords.h"

// Reads one double precision floating-point number from the input file
// Preconditions: file only contains real numbers and must already be open
double read_double(FILE* infile)
{
	double input_value = 0.0;
	fscanf(infile, "%lf", &input_value);
	return input_value;
}

// Reads one integer number from the input file
// Preconditions: file only contains real numbers and must already be open
int read_integer(FILE* infile)
{
	int input_value = 0;
	fscanf(infile, "%d", &input_value);
	return input_value;
}

// Finds the sum of number1, number2, number3, number4, and number5 and returns the result
// Preconditions: all numbers are double precision floating-point values
double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
	return number1 + number2 + number3 + number4 + number5;
}

// Determines the mean through the calculation sum / number and returns the result
// Preconditions: the sum is a positive double precision floating-point value, while the number is an integer;
double calculate_mean(double sum, int number)
{
	double mean = -1.0;
	if (number != 0)
	{
		mean = sum / number;
	}
	return mean;
}

// Determines the deviation of number from the mean and returns the result
// Preconditions: the number and mean are double precision floating-point values
double calculate_deviation(double number, double mean)
{
	return number - mean;
}

// Determines the variance from the average of the squared deviations and returns the result
// Preconditions: all the deviations are double precision floating-point values, while the number is an integer
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	double squared_variance_sum = pow(deviation1, 2.0) + pow(deviation2, 2.0) + pow(deviation3, 2.0) + pow(deviation4, 2.0) + pow(deviation5, 2.0);
	return calculate_mean(squared_variance_sum, number);
}

// Calculates the standard deviation as square root of the variance and returns the result
// Preconditions: the variance is a double precision floating-point value greater than or equal to zero
double calculate_standard_deviation(double variance)
{
	return sqrt(variance);
}

// Determines the maximum number out of five input numbers passed into the function and returns the result
// Preconditions: All numbers are double precision floating-point values
double find_max(double number1, double number2, double number3, double number4, double number5)
{
	double max = number1;
	if (number2 > max)
	{
		max = number2;
	}
	if (number3 > max)
	{
		max = number3;
	}
	if (number4 > max)
	{
		max = number4;
	}
	if (number5 > max)
	{
		max = number5;
	}
	return max;
}

// Determines the minimum number out of five input numbers passed into the function and returns the result
// Preconditions: All numbers are double precision floating-point values
double find_min(double number1, double number2, double number3, double number4, double number5)
{
	double min = number1;
	if (number2 < min)
	{
		min = number2;
	}
	if (number3 < min)
	{
		min = number3;
	}
	if (number4 < min)
	{
		min = number4;
	}
	if (number5 < min)
	{
		min = number5;
	}
	return min;
}

// Prints a double precision floating-point number to the hundredths place to an output file
// Preconditions: The number is a double precision floating-point number, while the file must already be open
void print_double(FILE* outfile, double number)
{
	fprintf(outfile, "%.2lf\n", number);
}