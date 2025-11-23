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

int main(void)
{
	// Opens the input and output .txt file streams
	FILE* input_stream = fopen("input.txt", "r"),
		* output_stream = fopen("output.txt", "w");

	int student_id_1 = 0, student_id_2 = 0, student_id_3 = 0, student_id_4 = 0, student_id_5 = 0,
		class_standing_1 = 0, class_standing_2 = 0, class_standing_3 = 0, class_standing_4 = 0, class_standing_5 = 0;
	double gpa_1 = 0.00, gpa_2 = 0.00, gpa_3 = 0.00, gpa_4 = 0.00, gpa_5 = 0.00, age_1 = 0.0, age_2 = 0.0, age_3 = 0.0, 
		   age_4 = 0.0, age_5 = 0.0, sum_of_gpas = 0.0, sum_of_class_standings = 0.0, sum_of_ages = 0.0, mean_of_gpas = 0.0,
		   mean_of_class_standings = 0.0, mean_of_ages = 0.0, deviation_gpa_1 = 0.0, deviation_gpa_2 = 0.0, deviation_gpa_3 = 0.0,
		   deviation_gpa_4 = 0.0, deviation_gpa_5 = 0.0, gpa_variance = 0.0, gpa_standard_deviation = 0.0, minimum_gpa = 0.0,
		   maximum_gpa = 0.0;

	// Reads records about student ID, GPA, class standing, and age for student 1
	student_id_1 = read_integer(input_stream);
	gpa_1 = read_double(input_stream);
	class_standing_1 = read_integer(input_stream);
	age_1 = read_double(input_stream);
	
	// Reads records about student ID, GPA, class standing, and age for student 2
	student_id_2 = read_integer(input_stream);
	gpa_2 = read_double(input_stream);
	class_standing_2 = read_integer(input_stream);
	age_2 = read_double(input_stream);

	// Reads records about student ID, GPA, class standing, and age for student 3
	student_id_3 = read_integer(input_stream);
	gpa_3 = read_double(input_stream);
	class_standing_3 = read_integer(input_stream);
	age_3 = read_double(input_stream);

	// Reads records about student ID, GPA, class standing, and age for student 4
	student_id_4 = read_integer(input_stream);
	gpa_4 = read_double(input_stream);
	class_standing_4 = read_integer(input_stream);
	age_4 = read_double(input_stream);

	// Reads records about student ID, GPA, class standing, and age for student 5
	student_id_5 = read_integer(input_stream);
	gpa_5 = read_double(input_stream);
	class_standing_5 = read_integer(input_stream);
	age_5 = read_double(input_stream);

	// Calculates sums of GPAs, class standings, and ages of each student
	sum_of_gpas = calculate_sum(gpa_1, gpa_2, gpa_3, gpa_4, gpa_5);
	sum_of_class_standings = calculate_sum(class_standing_1, class_standing_2, class_standing_3, class_standing_4, class_standing_5);
	sum_of_ages = calculate_sum(age_1, age_2, age_3, age_4, age_5);

	// Calculates means of GPAs, class standings, and ages of each student; then write those results to the output .txt file
	mean_of_gpas = calculate_mean(sum_of_gpas, 5);
	print_double(output_stream, mean_of_gpas);
	mean_of_class_standings = calculate_mean(sum_of_class_standings, 5);
	print_double(output_stream, mean_of_class_standings);
	mean_of_ages = calculate_mean(sum_of_ages, 5);
	print_double(output_stream, mean_of_ages);
	fprintf(output_stream, "\n");

	// Calculates the deviation of each student's GPA from the mean
	deviation_gpa_1 = calculate_deviation(gpa_1, mean_of_gpas);
	deviation_gpa_2 = calculate_deviation(gpa_2, mean_of_gpas);
	deviation_gpa_3 = calculate_deviation(gpa_3, mean_of_gpas);
	deviation_gpa_4 = calculate_deviation(gpa_4, mean_of_gpas);
	deviation_gpa_5 = calculate_deviation(gpa_5, mean_of_gpas);

	// Calculates the variance of the student GPAs
	gpa_variance = calculate_variance(deviation_gpa_1, deviation_gpa_2, deviation_gpa_3, deviation_gpa_4, deviation_gpa_5, 5);

	// Calculates the standard deviation of the student GPAs and writes the result to the output .txt file
	gpa_standard_deviation = calculate_standard_deviation(gpa_variance);
	print_double(output_stream, gpa_standard_deviation);

	// Calculates the minimum and maximum of the student GPAs and writes the result to the output .txt file
	minimum_gpa = find_min(gpa_1, gpa_2, gpa_3, gpa_4, gpa_5);
	print_double(output_stream, minimum_gpa);
	maximum_gpa = find_max(gpa_1, gpa_2, gpa_3, gpa_4, gpa_5);
	print_double(output_stream, maximum_gpa);

	// Closes the input and output .txt file streams
	fclose(input_stream);
	fclose(output_stream);

	return 0;
}