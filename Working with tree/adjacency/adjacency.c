#include <stdio.h> 
#define  N 4 /*Size of matrix*/
#define true 1           
#define false 0

typedef int adjmat[N][N];/*typedef for arry 2d size NxN */

void printmatrix(int adjmat[N][N]);/* the function i want to use*/
int path(int adjmat[N][N] , int u,int v); /* the fuction i want to use*/

 int main(){
 
adjmat B; /*Creat new matrix*/

int i,j,e;
int u,v;

printf("Enter numbers for matrix\n");
printf("**Node the size of your matrix is %dx%d \nYou can insert the numbers in one line And use the space bar between numbers. \nOr press enter after each number separately\n",N,N);

/*Fills the array with variables*/
for(i=0; i<N; i++){   
 for (j =0; j<N;j++){
 scanf("%d",&e);
	B[i][j] = e;
 }

}

printf("\nThe matrix is \n");

/*print the matrix*/
printmatrix(B);

printf("please enter the parameters you want to check:\n");
scanf("%d",&u);
scanf("%d",&v);
printf(" the result is: %d\n\n" , path(B,u,v));

/*while that call the function agian the while stop run if  u and V equle to -1*/
while(u !=-1 && v!=-1){
printf("Enter agian the parameters you want to check\n");
scanf("%d",&u);
scanf("%d",&v);
printf(" the result is: %d\n\n" , path(B,u,v));
}
return 0;
}

/*checking if there is fother and the vorders of array*/
int path(int adjmat[N][N] ,int u,int v){  
int i;

    if(u > N || v > N)
       return false;

    if(u==N && v == N)
	return true;

    if (adjmat[u][v]==1){

	return true;
	
	 }else if(adjmat[u][v]==0){

       for(i=0; i< N; i++) 
   
	if(adjmat[i][v]==1) {

	  if(adjmat[u][i]==1)
	return true;
	}   	
    }
return false;
}

/* print arrey*/
void printmatrix(int adjmat[N][N]){

int i,j;
for (i =0; i<N; i++){
    for (j=0;j<N;j++){
	printf("%d\t",adjmat[i][j]);	
}
printf("\n");
}















}
