#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node{
	char head[10];
	char tail[10];
};

int main(void){
	FILE *fp = fopen("testfile.csv","r");
	struct node reading[3];
	int i = 1;
	fscanf(fp,"%[^,],%[^,] \n", reading[i].head,reading[i].tail);
	printf("done\n");
	printf("%s %s",reading[i].head,reading[i].tail);
	return 0;
}
