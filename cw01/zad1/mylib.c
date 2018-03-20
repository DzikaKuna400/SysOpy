#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "limits.h"

#include "mylib.h"

//Static arrays functions

char static_arr[MAX_ARR_SIZE][MAX_BLOCK_SIZE];
int static_arr_size=0;
int static_block_size=0;

bool is_free[MAX_ARR_SIZE];

char* create_array_static(int arr_size, int block_size){
	if (arr_size>MAX_ARR_SIZE || block_size>MAX_BLOCK_SIZE)
		return NULL;
	static_arr_size=arr_size;
	static_block_size=block_size;
	for (int i=0; i<arr_size; i++)
		is_free[i]=true;
	return static_arr[0];
}

void delete_array_static(){
	for (int i=0; i<static_arr_size; i++)
		is_free[i]=false;
	static_arr_size=0;
	static_block_size=0;
	return;
}

char* add_block_static(int index){
	if (!is_free[index]) return NULL;
	is_free[index] = false;
}

void delete_block_static(int index){	
	if (index>=static_arr_size) return;	
	is_free[index]=true;
	return;
}

char* find_eq_block_static(int index){
	if (is_free[index]) return NULL;
	int ref_sum=0;
	int diff=INT_MAX;
	char* result = NULL;
	for (int i=0; i<static_block_size; i++)
		ref_sum+=static_arr[index][i];
	
	for (int i=0; i<index; i++){
		int sum=0;
		for (int j=0; j<static_block_size; j++)
			sum+=static_arr[i][j];
		if (abs(sum-ref_sum)<diff){
			diff = abs(sum-ref_sum);
			result = static_arr[i];
		}
	}
	
	for (int i=index+1; i<static_arr_size; i++){
		int sum=0;
		for (int j=0; j<static_block_size; j++)
			sum+=static_arr[i][j];
		if (abs(sum-ref_sum)<diff){
			diff = abs(sum-ref_sum);
			result = static_arr[i];
		}
	}

	return result;
}

void print_array_static(){
	for (int i=0; i<static_arr_size; i++){
		printf("Row %d: ", &i);
		if (!is_free[i]){
			for (int j=0; j<static_block_size; j++)
				printf("%c",&static_arr[i][j]);
			printf("\n");
		} else {
		printf("FREE BLOCK\n");
		}	
	}
	return;
}

//Dynamic arrays functions

char** create_array_dynamic(int arr_size){
	char** dyn_arr = (char**) calloc(arr_size, sizeof(char*));
	for (int i=0; i<arr_size; i++)
		dyn_arr[i]=NULL;
	return dyn_arr;
}

void delete_array_dynamic(char** arr, int arr_size){
	for (int i=0; i<arr_size; i++)
		free(arr[i]);
	free(arr);
	return;
}

char* add_block_dynamic(char** arr, int arr_size, int index, int block_size){
	if (index>=arr_size || arr[index]!=NULL)
		return NULL;
	arr[index] = (char*) calloc(block_size,sizeof(char));
	return arr[index];
}

void delete_block_dynamic(char** arr, int arr_size, int index){
	if (index>=arr_size) return;
	free(arr[index]);
	return;
}

char* find_eq_block_dynamic(char** arr, int arr_size, int block_size, int index){
	if (arr[index]==NULL) return NULL;
	int ref_sum=0;
	int diff=INT_MAX;
	char* result = NULL;
	for (int i=0; i<arr_size; i++)
		ref_sum+=arr[index][i];
	
	for (int i=0; i<index; i++){
		int sum=0;
		for (int j=0; j<block_size; j++)
			sum+=arr[i][j];
		if (abs(sum-ref_sum)<diff){
			diff = abs(sum-ref_sum);
			result = arr[i];
		}
	}
	
	for (int i=index+1; i<arr_size; i++){
		int sum=0;
		for (int j=0; j<block_size; j++)
			sum+=arr[i][j];
		if (abs(sum-ref_sum)<diff){
			diff = abs(sum-ref_sum);
			result = arr[i];
		}
	}

	return result;
}

void print_array_dynamic(char** arr, int arr_size, int block_size){
	for (int i=0; i<arr_size; i++){
		printf("Row %d: ", &i);
		if (arr[i]!=NULL){
			for (int j=0; j<block_size; j++)
				printf("%c",&arr[i][j]);
			printf("\n");
		} else {
		printf("FREE BLOCK\n");
		}
	}
	return;
}
