#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPrime(number)
{
	if (number <= 1)
		return 0;
	int divisor = 2;
	while (divisor*divisor <= number)
	{
		if (number%divisor == 0)
			return 0;
		divisor += 1;
	}
	return 1;
}



void readData(int numbers[], int* return_length)
{
	char input[100];
	char* token;
	const char delimiter[] = " ";
	int current_number, length = 0;

	scanf("%[^\n]s", &input);
	token = strtok(input, delimiter);

	while (token != NULL)
	{
		current_number = atoi(token);
		numbers[length] = current_number;
		length += 1;
		token = strtok(NULL, delimiter);
	}

	*return_length = length;
}

void findLogestSubsequenceWithPrimeDifference(int numbers[], int length, int* return_start, int* return_end)
{
	int global_start=0, global_end=0, current_start=0, current_end=0;
	while (current_end < length - 1)
	{
		while (isPrime(numbers[current_end + 1] - numbers[current_end]))
			current_end += 1;
		if (current_end - current_start > global_end - global_start)
		{
			global_start = current_start;
			global_end = current_end;
		}
		current_end = current_end + 1;
		current_start = current_end;

	}
	*return_start = global_start;
	*return_end = global_end;
}

void printResult(int numbers[], int start, int end)
{
	int i;
	for (i = start; i <= end; i++)
		printf("%d ", numbers[i]);
}



int main()
{
	int numbers[100], length, start, end;
	readData(numbers, &length);
	findLogestSubsequenceWithPrimeDifference(numbers, length, &start, &end);
	printResult(numbers, start, end);
	return 0;
}