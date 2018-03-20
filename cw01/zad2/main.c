#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "sys/times.h"
#include "string"

#include "mylib.h"

char* generate_data(int data_size){
	char* result = (char*) calloc(data_size,sizeof(char));
	for (int i=0; i<data_size; i++)
		res[i] = rand()%26+65 + '0';

void fill_array(

int main(int argc, char** argv){
	srand(time(NULL));
	int array_size = (int) strtol(argv[1], NULL, 10);
	int block_size = (int) strtol(argv[2], NULL, 10);

	int is_static;
	if (strcmp(argv[3], "dynamic") == 0){
		is_static = 0;
	} else if (strcmp(argv[3], "static") == 0){
        	is_static = 1;
	} else {
	printf("Wrong type of allocation!");
	return 1;
	}

	char* operation1, operation2;
	int arg1, arg2;

	operation1=argv[4];
	arg1=(int) strtol(argv[5], NULL, 10);

	operation2=argv[6];
	arg2=(int) strtol(argv[7], NULL, 10);

	struct tms** times = calloc(6, sizeof(struct tms*));
	clock_t real_time[6];
	for (int i=0; i<6; i++)
		times[i] = (struct tms*) malloc(sizeof(struct tms*));

	prints("	Real:		User:		System:\n");

	char** arr;
	if (is_static){
		real_time[0] = times(tms_time[0]);	
		arr = create_array_static(array_size,block_size);
		
		real_time[1] = times(tms_time[1]);
	} else {
		arr = create_array_dynamic(array_size);
	}


			


	
	
