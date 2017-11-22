#include <stdio.h>
#include <string.h>

struct data_t{
	char time[10];
	char offense[60];
};
struct node_t{
	int time;
	int count;
	struct node_t * left;
	struct node_t * right;
};

char searchArray[50];
struct node_t offense_count[];
void split(char * to_split, char * split_on){
	int i, j;
	char * word;
	char * reset;
	int len = strlen(to_split);
	j=0;
	for(i=0; i<=len;i++){
		if(to_split[i]!= split_on){
			word[i]=to_split[i];
		}
		else{
			searchArray[j]=word;
			j++;
			*word = *reset;	
		}
	}
}

int contains(char * offense, char * search){
	split(offense, ",");
	int i=0;
	while(searchArray[i]!=search){
		i++;
		if(i>strlen(searchArray)){
			exit(0);
		}
	}
	exit(1);
}
struct node_t* insert(struct node_t * toinsert, struct node_t * curnode){
	if(curnode==NULL){
		return toinsert;
	}
	else if(curnode->time == toinsert->time){
		curnode->count+=1;
		return curnode;
	}
	else if (curnode->time> toinsert->time){
		insert(toinsert, curnode->right);
		return curnode;
	}
	else{
		insert(toinsert, curnode->left);
		return curnode;
	}
}
struct node_t * addtime(struct data_t toadd){
	int i;
	char * hour;
	int ihour;
	i=0;
	while(toadd.time[i] !=':'){
		hour[i]=toadd.time[i];
		i++;
	}
	ihour= (int)hour;
	struct node_t * toinsert;
	toinsert->time = ihour;	toinsert->count =1; toinsert->left=NULL; toinsert->right=NULL;
	struct node_t * toreturn;
	toreturn = insert(toinsert, offense_count);
	return toreturn;
}
int countlines(FILE * fptr){
	int lines=0;
	char ch;
	while(!feof(fptr)){
		ch= fgetc(fptr);
		if(ch=='\n'){
			lines++;
			printf("%d\n", lines);
		}
	}
	return lines;
}
int main(char * argc, char **argv){
	FILE * fptr = fopen(argv[1],"r");
	printf("Starting:\n");
	int i,numlines;
	struct data_t * readarray[60];
	numlines= 60;//countlines(fptr);
	printf("loaded numlines: \n");
	struct data_t * reading= (struct data_t *)malloc(sizeof(struct data_t));
	i=0;
	printf("%d \n",numlines);
	while(fscanf(fptr, ",%[^:],,,,%[^,], \n",reading->time,reading->offense)>0){
		i++;
		readarray[i]= reading;
		printf("i: %d \n",i);
	}
	printf("numlines: %d, i: %d \n",numlines,i);
	for(i=0; i<numlines;i++){
		printf("%s,%s\n",reading->time,reading->offense);
		printf("%s, %s \n",readarray[i]->time,readarray[i]->offense);
	}
	fclose(fptr);
	return 0;
}

