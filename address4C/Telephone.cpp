#include "Telephone.h"
#include <stdlib.h>
#include <stdio.h>



Telephone::Telephone(int i, char *n, char *p, char *e, 
	char *c, int y) : Person(n, y)
{
	id = i;
	phone = p;
	email = e;
	city = c;
}


Telephone::~Telephone()
{
}


char * Telephone::ToString()
{
	char *s = (char*)malloc(sizeof(char)*LEN_TELEPHONE_STR);
	sprintf(s, "| %02d | %8s | %13s | %15s | %8s | %4d |", 
		id, name, phone, email, city, year);
	return s;
}
