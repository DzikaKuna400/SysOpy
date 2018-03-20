#ifndef MYLIB_H
#define MYLIB_H

#define MAX_ARR_SIZE 1000000
#define MAX_BLOCK_SIZE 100

char* create_array_static(int, int); //(array size, block size)
void delete_array_static(void);
char* add_block_static(int); //(index) 
void delete_block_static(int); //(index)
char* find_eq_block_static(int); //(referent index)
void print_array_static(void);


char** create_array_dynamic(int); //(array size)
void delete_array_dynamic(char**, int); //(array, array size)
char* add_block_dynamic(char**, int, int, int); //(array, array size, index, block size)
void delete_block_dynamic(char**, int, int); //(array, array size, index)
char* find_eq_block_dynamic(char**, int, int, int); //(array, array size, block size, referent index)
void print_array_dynamic(char**, int, int); //(array, array size, block size)

#endif

