#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data; /* the result of the fibinacci */
	int value; /* the number that data in its fibinacci */
	struct node* next;
};

typedef struct node link;

link* head = NULL;
link* tail = NULL;
int isNumber(char a[]);
void initializeList();
int fib(int n);
void printList();
void freeList();

int main() {
	char a[50];

	printf("Please enter num to calculate Fibonacci: ");
	fgets(a, 50, stdin);
	/* remove the \n that the fgets put in the end of the string */
	a[strlen(a)-1]='\0';
	if (!isNumber (a))
		return 0;
	initializeList();
	fib(atoi(a));
	printf("The Fibonacci list for %s is:\n", a);
	printList(head);
	freeList();
	return 0;
}

/* check if the string is a number */
int isNumber(char a[]) {
	int i = 0;

	/* checking for negative numbers */
	if (a[0] == '-')
	{
		printf("Number is negative\n");
		return 0;
	}
	for (; a[i] != 0; i++)
	{
		/* if (number[i] > '9' || number[i] < '0') */
		if (!isdigit(a[i]))
		{
			printf("INVALID NUMBER\n");
			return 0;
		}
	}
	return 1;
}

/* create list with one node for fibonacci of 0 */
void  initializeList() {
	head = (link*)malloc(sizeof(link));
	tail = head;
	head->data = 1;
	head->value = 0;
	head->next = head;
}

/* return the fibonacci number that is kept in the list.
if it is not in the list, return 0 */
int getFromList(int n) {
	link* p1;
	if (head->value == n)
		return head->data;
	p1 = head->next;
	while(p1 != head)
	{
		if (p1->value == n)
			return p1->data;
		p1 = p1->next;
	}
	return 0; /* not found */
}

/* add a fibonacci number to the end of the list */
void addToList(int n, int value) {
	link* p1;

	p1 = (link*)malloc(sizeof(link));

	tail->next = p1;
	p1->data = value;
	p1->value = n;
	p1->next = head;
	tail = p1;
}

/* calculate fibonacci */
int fib(int n)
{
	int value;
	/* check if it is already in the list */
	value = getFromList(n);
	if (value != 0)
		return value;
	if (n == 1)
	{
		value = 1;
		/* add the new value to the list for efficiency */
		addToList(1, 1);
		return value;
	}
	value = fib(n - 2) + fib(n - 1);
	/* add the new value to the list for efficiency */
	addToList(n, value);
	return value;
}

/* print the list in recurssion because we need to print from the end to the beginning */
void printList(link* l) {
	if (l != tail)
		printList(l->next);

	printf("%d", l->data);
	if (l != head)
		printf(" ==> ");
	else
		printf("\n");
}

/* free the all list */
void freeList() {
	link* p1, *p2;
	tail->next = NULL; /* make the list not circular */
	p1 = head;
	while(p1 != NULL)
	{
		p2 = p1;
		p1 = p1->next;
		free(p2);
	}
}

