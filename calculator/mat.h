
#define SIZE 4 /*defining a fixed all over the plan SIZE */

typedef double matrix [SIZE][SIZE]; /*deining MATRIX 2D array in SIZE 4*4 */

void read_mat(matrix* mat, char* command);
void print_mat(matrix* mat);
void add_mat(matrix* mat1, matrix* mat2, matrix* result);
void sub_mat(matrix* mat1, matrix* mat2, matrix* result);
void mul_mat(matrix* mat1, matrix* mat2, matrix* result);
void mul_scalar(matrix* mat1, double scalar, matrix* result);
void trans_mat(matrix* mat1, matrix* result);

int only_spaces(char* str);
int number_of_commans(char* str);
int is_number(char* number);


