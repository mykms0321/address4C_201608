#include "Person.h"
#include <stdlib.h>
#include <stdio.h>



Person::Person(char *n, int y)
{
	name = n;
	year = y;
}


Person::~Person()
{
}


char* Person::ToString() {
	char *s = (char*)malloc(sizeof(char)*LEN_PERSON_STR);
	sprintf(s, "| %s | %d |", name, year);
	return s;
}
