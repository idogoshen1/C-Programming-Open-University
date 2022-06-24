#include <stdio.h>


int count_odd_bits(unsigned long );


int main() {
 int n;
printf("\n enter a number \n");
scanf("%d",&n);
printf("\n   number 1 in odd pos :  %d \n",count_odd_bits(n));
return 0;
}

int count_odd_bits(unsigned long x) {

int count = 0, i;/* insilized count and index */
int mask = 2; /* index start in 0 */
int length = sizeof(long); /* put the size of long into int */
for ( i =0; i<length; ++i) {

if((x&mask) != 0) /* condition to enter to the odd index and id musk equak to one*/
count++; /* summerize*d the odd bits */
mask<<=2; /* move the mask to the next comperation */
}
mask<<=2;
return count;
}











