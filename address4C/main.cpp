#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"
#include "Telephone.h"

Telephone *data[MAX_TELEPHONE] = { NULL };
int n = 0;

void load() {
	FILE *ifp = fopen(DATAFILE, "r");
	char temp[80];
	fscanf(ifp, "%s%s%s%s%s%s",
		&temp, &temp, &temp, &temp, &temp, &temp);
	for (int i = 0; 1; i++) {
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
	fclose(ifp);
}

void list() {
	printf("-------------------------------------------------------------------\n");
	for (int i = 0; i < n; i++)
		printf("%s\n", data[i]->ToString());
	printf("-------------------------------------------------------------------\n");
}

int list2(char *keyword) {
	int r = 0;
	printf("-------------------------------------------------------------------\n");
	for (int i = 0; i < n; i++) {
		char *str = data[i]->ToString();
		if (strstr(str, keyword)) {
			printf("%s\n", str);
			r++;
		}
	}
	printf("-------------------------------------------------------------------\n");
	return r;
}

void search(char *keyword) {
	int r = list2(keyword);
	printf("==> �˻���� �� : %d��\n", r);
}

void main(int argc, char **argv) {
	if (argc < 2) {
		printf("����: address4C ���\n");
		printf("  * ��� :\n");
		printf("    - LIST : �ּҷ� ����� �����ֱ�\n");
		printf("    - SEARCH �˻��� : �ּҷ� ����� �˻��ϱ�\n");
		return;
	}
	load();
	if (strcmp(argv[1], "LIST") == 0) {
		list();
	}
	else if (strcmp(argv[1], "SEARCH") == 0) {
		search(argv[2]);
	}
}
