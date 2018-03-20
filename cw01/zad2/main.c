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



void do_operation(char* operation_name, int arg, char** arr, int array_size, int block_size, int is_static) {


    if (strcmp(operation_name, "search_element") == 0) {
        if(is_static){
		char* result = find_eq_block_static(rand()%array_size);
	} else {
		char* result = find_eq_block_dynamic(arr, array_size, block_size, rand()%array_size);
	}
	

    } else if (strcmp(operation_name, "remove_then_add") == 0) {
	if(is_static){
	  for (int i=0; i<arg; i++) delete_block_static(i);
	  for (int i=0; i<arg; i++) {
		char* tmp = add_block_static(i); 
		tmp = generate_data(block_size);
	  }
	} else {
	  for (int i=0; i<arg; i++) delete_block_dynamic(arr,array_size,i);
	  for (int i=0; i<arg; i++) {
	 	char* tmp = add_block_dynamic(arr,array_size,i,block_size);
		tmp = generate_data(block_size);
	  }
	}
	


    } else if (strcmp(operation_name, "remove_and_add") == 0) {
        if(is_static){
	  for (int i=0; i<arg; i++) {
		delete_block_static(i);
	  	char* tmp = add_block_static(i);
		tmp = generate_data(block_size);
	  } 
	} else {
	  for (int i=0; i<arg; i++) {
		delete_block_dynamic(arr,array_size,i);
	  	char* tmp = add_block_dynamic(arr,array_size,i,block_size);
		tmp = generate_data(block_size);
	  }
	}

}



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

	struct tms** tms_time = calloc(6, sizeof(struct tms*));
	clock_t real_time[6];
	for (int i=0; i<6; i++)
		tms_time[i] = (struct tms*) malloc(sizeof(struct tms*));

	prints("	Real:		User:		System:\n");

	char** arr;
	if (is_static){
		real_time[0] = times(tms_time[0]);	
		arr = create_array_static(array_size,block_size);
		for (int i=0; i<arr_size; i++){
			char* block = add_block_static(i);
			block = generate_data(block_size);
		}
		real_time[1] = times(tms_time[1]);
	} else {
		real_time[0] = times(tms_time[0]);	
		arr = create_array_dynamic(array_size);
		for (int i=0; i<arr_size; i++){
			char* block = add_block_dynamic(arr,array_size,i,block_size);
			block = generate_data(block_size);
		}
		real_time[1] = times(tms_time[1]);
	}

 	printf("1) Creating:\n");
    	printf("%lf   ", calculate_time(real_time[0], real_time[1]));
    	printf("%lf   ", calculate_time(tms_time[0]->tms_utime, tms_time[1]->tms_utime));

	printf("%lf ", calculate_time(tms_time[0]->tms_stime, tms_time[1]->tms_stime));
	printf("\n");

	

	real_time[2] = times(tms_time[2]);
        do_operation(operation1, arg1, arr, array_size, block_size, is_static);
	real_time[3] = times(tms_time[3]);

	printf("2) %s:\n", operation1);
        printf("%lf   ", calculate_time(real_time[2], real_time[3]));
        printf("%lf   ", calculate_time(tms_time[2]->tms_utime, tms_time[3]->tms_utime));
        printf("%lf ", calculate_time(tms_time[2]->tms_stime, tms_time[3]->tms_stime));
	printf("\n");



	real_time[4] = times(tms_time[4]);
        do_operation(operation2, arg2, arr, array_size, block_size, 		is_static);
	real_time[5] = times(tms_time[5]);

	printf("2) %s:\n", operation1);
        printf("%lf   ", calculate_time(real_time[4], real_time[5]));
        printf("%lf   ", calculate_time(tms_time[4]->tms_utime, tms_time[5]->tms_utime));
        printf("%lf ", calculate_time(tms_time[4]->tms_stime, tms_time[5]->tms_stime));
printf("\n");

return 0;

}


			


	
	
