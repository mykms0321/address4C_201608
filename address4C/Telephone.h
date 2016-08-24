#pragma once
#include "Person.h"
class Telephone :
	public Person
{
public:
	Telephone(int, char*, char*, char*, char*, int);
	~Telephone();
	virtual char* ToString();
protected:
	int id;
	char *phone;
	char *email;
	char *city;
};

