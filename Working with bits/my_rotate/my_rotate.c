#include <stdio.h>
unsigned short my_rotate(unsigned short,char);
void print_short_bin(unsigned short);

int main() {
int a,b;
printf("please enter the number you want to convert\n");
scanf("%d", &a);
printf("please enter the number of bits you to shift\n");
scanf("%d", &b);
printf("\n the result is: %d \n", my_rotate((unsigned short)a,(char)b));

return 0;
}

void print_short_bin(unsigned short x){
unsigned short mask = 1 <<(8*sizeof(unsigned short)-1);
while(mask) {

if((x&mask) ==0)
printf("0");
else
printf("1");
mask>>=1;
}
}

unsigned short my_rotate(unsigned short a, char b){

short n = sizeof(unsigned short)*8; 		/* size of short*/				
							/*check puting in a the size of short */
if(b>=0){ 						/* condition to  if bits i want to shift is positive*/
printf("\nthe number before rotate\n");
print_short_bin(a);

a = (a << b) | (a >> (n-b));    /* a shift -right- b times entering '0' insted of the bits that moves and do betwisw | to the rest of bits in -left- side and entering '0' and*/  

printf("\nthe number after rotate right\n");
print_short_bin(a);

}else{							/*subtrahend  (b) the bits i want to shift */
  							/* b is unpositive */
b = b*-1;

printf("\nthe number before rotate left\n");
print_short_bin(a);

a = (a >> b) |(a << (n-b));

printf("\nthe number after rotate left\n");
print_short_bin(a);

}
return a; 

}






                                             

















