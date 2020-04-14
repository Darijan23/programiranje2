#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


typedef struct{
    char name[32];
    int pc;
    int oc;
} article;


void parse_name(char name[]){
    int n = 0, i;
    name[0] = toupper(name[0]);
    for(i = 1; i < strlen(name); i++){
        if(!isalpha(name[i])){
            n++;
        } else {
            name[i - n] = tolower(name[i]);
        }
    }
    name[i - n] = '\0';
}

void check_price(article p[], int n, int c, char name[]) {
	for (int i = 0; i < n; ++i) {
		if (!strcmp(p[i].name, name) && c >= p[i].pc && c >= p[i].oc) {
			p[i].oc = c;
		}
	}
}

int artcomp(article p1, article p2) {
	if (p1.oc == p2.oc)	{
		return strcmp(p1.name, p2.name);
	}
	return p1.oc < p2.oc;
}

void sort(article p[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int max = i;

		for (int j = i + 1; j < n; ++j) {
			if (artcomp(p[max], p[j]) > 0) {
				max = j;
			}
		}

		article temp = p[max];
		p[max] = p[i];
		p[i] = temp;
	}
}

int profit(article p[], int n){
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += p[i].oc;
    }

    return sum;
}

int main() {
	article p[100];
	int n, size, c;
	char name[32];

	FILE *fp;

	size = 0;

	scanf("%s ", p[size].name);

	while (p[size].name[0] != '-') {
		scanf("%d ", &p[size].pc);
		parse_name(p[size].name);
		p[size].oc = 0;
		size++;
		scanf("%s", p[size].name);
	}

	fp = fopen("input.dat", "r");

	while(fscanf(fp, " %s %d ", name, &n) > 0) {
		for (int i = 0; i < n; ++i) {
			fscanf(fp, "%s %d", name, &c);
			parse_name(name);
			check_price(p, size, c, name);
		}

	}

	fclose(fp);
	sort(p, size);
	fp = fopen("output.dat", "w");

	printf("%d\n", profit(p, size));
	fprintf(fp, "%d\n", profit(p, size));

	for (int i = 0; i < size; i++) {
		if (p[i].oc > 0) {
			printf("%s %d\n", p[i].name, p[i].oc);
			fprintf(fp, "%s %d\n", p[i].name, p[i].oc);
		}
	}

	fclose(fp);

	return 0;
}
