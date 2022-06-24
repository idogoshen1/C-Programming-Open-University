#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mat.h"

matrix MAT_A = {{0}}; /*initialized the 2D array MAT_A all cell in {0}{0}*/
matrix MAT_B = {{0}}; /*initialized the 2D array MAT_B all cell in {0}{0}*/
matrix MAT_C = {{0}}; /*initialized the 2D array MAT_C all cell in {0}{0}*/
matrix MAT_D = {{0}}; /*initialized the 2D array MAT_Dall cell  in {0}{0}*/
matrix MAT_E = {{0}}; /*initialized the 2D array MAT_E all cell in {0}{0}*/
matrix MAT_F = {{0}}; /*initialized the 2D array MAT_F all cell in {0}{0}*/

#define MAX_COMMAND 1000
#define MAT_NAME_LENGTH 6

matrix* get_matrix_by_name(char mat_name[MAT_NAME_LENGTH])
{
	if (strcmp(mat_name, "MAT_A") == 0)
		return &MAT_A;
	if (strcmp(mat_name, "MAT_B") == 0)
		return &MAT_B;
	if (strcmp(mat_name, "MAT_C") == 0)
		return &MAT_C;
	if (strcmp(mat_name, "MAT_D") == 0)
		return &MAT_D;
	if (strcmp(mat_name, "MAT_E") == 0)
		return &MAT_E;
	if (strcmp(mat_name, "MAT_F") == 0)
		return &MAT_F;
	return NULL;
}

int has_consecutive_commas(char* str)
{
	int read_comma = 0;
	int ok = 1;
	while(*str)
	{
		if (*str == ',')
		{
			if (! ok)
				return 1;
			read_comma = 1;
			ok = 0;
		}
		else
		{
			if (read_comma && (*str != ' '))
				ok = 1;
		}
		str++;
	}
	return 0;
}

int main()
{
	char command[MAX_COMMAND], temp_command[50];
	char mat1_name[MAT_NAME_LENGTH], mat2_name[MAT_NAME_LENGTH], mat3_name[MAT_NAME_LENGTH];
	int i, j;
	matrix *mat1, *mat2, *mat3;
	char* token;
	double scalar;
	while(1)
	{
		fgets(command, MAX_COMMAND, stdin);
		command[strlen(command) - 1] = '\0'; /* remove the newline from the end */
		if (has_consecutive_commas(command))
		{
			printf("Multiple consecutive commas\n");
			continue;
		}
		i = 0;
		/* find where the command itself ends */
		while(command[i] && (command[i] != ' '))
			i++;
		for (j = 0; j < i; j++)
			temp_command[j] = command[j];
		temp_command[i] = '\0';
		if (strcmp(temp_command, "read_mat") == 0)
		{
			while(command[i] && command[i] == ' ') /* skip spaces */
				i++;
			j = 0;
			while(command[i] && command[i] != ',')
			{
				mat1_name[j] = command[i];
				i++;
				j++;
			}
			mat1_name[MAT_NAME_LENGTH - 1] = '\0';
			mat1 = get_matrix_by_name(mat1_name);
			if (mat1 == NULL)
			{
				printf("Undefined matrix name\n");
				continue;
			}
			i++; /* skip the comma */
			while(command[i] == ' ') /* skip spaces */
				i++;
			read_mat(mat1, &command[i]);
		}
		else
		if (strcmp(temp_command, "print_mat") == 0)
		{
			if (command[i] == ',')
			{
				printf("Illegal comma\n");
				continue;
			}
			while(command[i] && command[i] == ' ') /* skip spaces */
				i++;
			j = 0;
			while(command[i] != '\0')
			{
				mat1_name[j] = command[i];
				i++;
				j++;
			}
			mat1_name[MAT_NAME_LENGTH - 1] = '\0';
			mat1 = get_matrix_by_name(mat1_name);
			if (mat1 == NULL)
			{
				printf("Undefined matrix name\n");
				continue;
			}
			print_mat(mat1);
		}
		else
		if (strcmp(temp_command, "add_mat") == 0)
		{
			if (number_of_commans(command) < 2)
			{
				printf("Missing comma\n");
				continue;
			}
			while(command[i] == ' ') /* skip spaces */
				i++;
			token = strtok(&command[i], ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat1_name, token);
			token = strtok(NULL, ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat2_name, token);
			token = strtok(NULL, ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat3_name, token);

			mat1_name[MAT_NAME_LENGTH - 1] = '\0';
			mat2_name[MAT_NAME_LENGTH - 1] = '\0';
			mat3_name[MAT_NAME_LENGTH - 1] = '\0';
			mat1 = get_matrix_by_name(mat1_name);
			mat2 = get_matrix_by_name(mat2_name);
			mat3 = get_matrix_by_name(mat3_name);
			if (mat1 == NULL || mat2 == NULL || mat3 == NULL)
			{
				printf("Undefined matrix name\n");
				continue;
			}
			add_mat(mat1, mat2, mat3);
		}
		else
		if (strcmp(temp_command, "sub_mat") == 0)
		{
			if (number_of_commans(command) < 2)
			{
				printf("Missing comma\n");
				continue;
			}
			while(command[i] == ' ') /* skip spaces */
				i++;
			token = strtok(&command[i], ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat1_name, token);
			token = strtok(NULL, ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat2_name, token);
			token = strtok(NULL, ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat3_name, token);

			mat1_name[MAT_NAME_LENGTH - 1] = '\0';
			mat2_name[MAT_NAME_LENGTH - 1] = '\0';
			mat3_name[MAT_NAME_LENGTH - 1] = '\0';
			mat1 = get_matrix_by_name(mat1_name);
			mat2 = get_matrix_by_name(mat2_name);
			mat3 = get_matrix_by_name(mat3_name);
			if (mat1 == NULL || mat2 == NULL || mat3 == NULL)
			{
				printf("Undefined matrix name\n");
				continue;
			}
			sub_mat(mat1, mat2, mat3);
		}
		else
		if (strcmp(temp_command, "mul_mat") == 0)
		{
			if (number_of_commans(command) < 2)
			{
				printf("Missing comma\n");
				continue;
			}
			while(command[i] == ' ') /* skip spaces */
				i++;
			token = strtok(&command[i], ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat1_name, token);
			token = strtok(NULL, ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat2_name, token);
			token = strtok(NULL, ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat3_name, token);

			mat1_name[MAT_NAME_LENGTH - 1] = '\0';
			mat2_name[MAT_NAME_LENGTH - 1] = '\0';
			mat3_name[MAT_NAME_LENGTH - 1] = '\0';
			mat1 = get_matrix_by_name(mat1_name);
			mat2 = get_matrix_by_name(mat2_name);
			mat3 = get_matrix_by_name(mat3_name);
			if (mat1 == NULL || mat2 == NULL || mat3 == NULL)
			{
				printf("Undefined matrix name\n");
				continue;
			}
			mul_mat(mat1, mat2, mat3);
		}
		else
		if (strcmp(temp_command, "mul_scalar") == 0)
		{
			if (number_of_commans(command) < 2)
			{
				printf("Missing comma\n");
				continue;
			}
			while(command[i] == ' ') /* skip spaces */
				i++;
			token = strtok(&command[i], ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat1_name, token);
			token = strtok(NULL, ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			if (! is_number(token))
			{
				printf("Parameter not a scalar\n");
				continue;
			}
			scalar = atof(token);
			token = strtok(NULL, ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat2_name, token);

			mat1_name[MAT_NAME_LENGTH - 1] = '\0';
			mat2_name[MAT_NAME_LENGTH - 1] = '\0';
			mat1 = get_matrix_by_name(mat1_name);
			mat2 = get_matrix_by_name(mat2_name);
			if (mat1 == NULL || mat2 == NULL)
			{
				printf("Undefined matrix name\n");
				continue;
			}
			mul_scalar(mat1, scalar, mat2);
		}
		else
		if (strcmp(temp_command, "trans_mat") == 0)
		{
			if (number_of_commans(command) == 0)
			{
				printf("Missing comma\n");
				continue;
			}
			while(command[i] == ' ') /* skip spaces */
				i++;
			token = strtok(&command[i], ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat1_name, token);
			token = strtok(NULL, ", ");
			if (token == NULL)
			{
				printf("Missing parameter\n");
				continue;
			}
			strcpy(mat2_name, token);
			token = strtok(NULL, ", ");
			if ((token != NULL) && ! only_spaces(token))
			{
				printf("Extraneous text after end of command\n");
				continue;
			}

			mat1_name[MAT_NAME_LENGTH - 1] = '\0';
			mat2_name[MAT_NAME_LENGTH - 1] = '\0';
			mat1 = get_matrix_by_name(mat1_name);
			mat2 = get_matrix_by_name(mat2_name);
			if (mat1 == NULL || mat2 == NULL)
			{
				printf("Undefined matrix name\n");
				continue;
			}
			trans_mat(mat1, mat2);
		}
		else
		if (strcmp(command, "stop") == 0)
		{
			break;
		}
		else
		{
			printf("Undefined command name\n");
		}
	}
	return 0;

}

