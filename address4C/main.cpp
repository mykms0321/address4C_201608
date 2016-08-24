#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Telephone.h"
void main() {
	Telephone *data[MAX_TELEPHONE] = { NULL };
	int n = 0;

	FILE *ifp = fopen(DATAFILE, "r");
	char temp[80];
	fscanf(ifp, "%s%s%s%s%s%s",
		&temp, &temp, &temp, &temp, &temp, &temp);
	for(int i=0; 1; i++) {
		int id;
		char *name = (char*)malloc(sizeof(char) * 20);
		char *phone = (char*)malloc(sizeof(char) * 20);
		char *email = (char*)malloc(sizeof(char) * 30);
		char *city = (char*)malloc(sizeof(char) * 20);
		int year;
		int res = fscanf(ifp, "%d%s%s%s%s%d",
			&id, name, phone, email, city, &year);
		if (res == EOF)	break;
		data[i] = new Telephone(id, name, phone, email, city, year);
		n++;
	}

	for (int i = 0; i < n; i++)
		printf("%s\n", data[i]->ToString());


}
