#pragma once
#include "common.h"
class Person
{
public:
	Person(char *, int);
	~Person();
	virtual char* ToString();
protected:
	char *name;
	int year;
};

