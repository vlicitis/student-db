#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "struct.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

void enter_data(student* db_ptr, uint8_t size) {
    if (db_ptr == NULL) {printf("NULLPTR !\n");return;};
    for (uint8_t i = 0; i < size; i++) {
        printf("Student %u \nEnter data (firstname, lastname, course, group): ",i+1);
        scanf("%32s %32s %hu %hu", db_ptr[i].firstname, db_ptr[i].lastname, &db_ptr[i].kurs, &db_ptr[i].grupa);
    }        
}

void output_data(student* db_ptr, uint8_t size) {
    if (db_ptr == NULL) {printf("NULLPTR !\n");return;};
    printf("Student No\tFirstname\tLastname\tCourse\tGroup\n");
    for (uint8_t i = 0; i<size; i++) {
    printf("%d:\t\t%s\t\t%s\t\t%u\t\t%u\n", i, db_ptr[i].firstname, db_ptr[i].lastname, db_ptr[i].kurs, db_ptr[i].grupa);
    }
}



void save_db(const char* filename, student* db_ptr, uint8_t size) {
	if (!db_ptr) {printf("NULLPTR \n");return;};
	int file = open(filename, O_CREAT | O_WRONLY, 0600);
    if (file > 0) {
	    write(file, db_ptr, size * sizeof(student));
    };
	close(file);
}

student* load_db(const char* filename, uint8_t size) {
	int file = open(filename, O_RDONLY);
	if (file < 0) {printf("No existing database ! \n");return NULL;};
    student* return_ptr = malloc(size * sizeof(student));
    read(file, return_ptr, size * sizeof(student)); // read all
    if (errno) {
        free(return_ptr);
        return_ptr = NULL;
    }
	close(file);
    return return_ptr;
}