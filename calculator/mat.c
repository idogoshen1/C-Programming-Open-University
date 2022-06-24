#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mat.h"

int number_of_commans(char* str)
{
	int num = 0;
	while(*str)
	{
		if (*str == ',')
			num++;
		str++;
	}
	return num;
}

int only_spaces(char* str)
{
	if (! *str)
		return 1;
	while(*str)
	{
		if (*str != ' ')
			return 0;
		str++;
	}
	return 1;
}

int is_number(char* number)
{
	while(*number)
	{
		if ((*number != '.') && (*number != '-') && (*number != ' ') && ((*number < '0') || (*number > '9')))
			return 0;
		number++;
	}
	return 1;
}

void read_mat(matrix* mat, char* command)
{
	char* token;
	int i, j;
	if (only_spaces(command))
	{
		printf("Missing parameter\n");
		return;
	}
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(*mat)[i][j] = 0;
		}
	}
	i = 0;
	j = 0;
	token = strtok(command, ",");
	while(token != NULL)
	{
		if (only_spaces(token))
		{
			printf("Extraneous text after end of command\n");
			return;
		}
		if (! is_number(token))
		{
			printf("Parameter not a real number\n");
			return;
		}
		(*mat)[i][j] = atof(token);
		j++;
		if (j == SIZE)
		{
			i++;
			j = 0;
		}
		token = strtok(NULL, ",");
	}
}

void print_mat(matrix* mat)
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			printf("%7.2f", (float)(*mat)[i][j]);
		}
		printf("\n");
	}
}

void add_mat(matrix* mat1, matrix* mat2, matrix* result)
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(*result)[i][j] = (*mat1)[i][j] + (*mat2)[i][j];
		}
	}
}

void sub_mat(matrix* mat1, matrix* mat2, matrix* result)
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(*result)[i][j] = (*mat1)[i][j] - (*mat2)[i][j];
		}
	}
}

void mul_mat(matrix* mat1, matrix* mat2, matrix* result)
{
	int i, j, k, sum;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			sum = 0;
			for (k = 0; k < SIZE; k++)
			{
				sum += (*mat1)[i][k] * (*mat2)[k][j];
			}
			(*result)[i][j] = sum;
		}
	}
}

void mul_scalar(matrix* mat1, double scalar, matrix* result)
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(*result)[i][j] = scalar * (*mat1)[i][j];
		}
	}
}

void trans_mat(matrix* mat1, matrix* result)
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(*result)[i][j] = (*mat1)[j][i];
		}
	}
}


