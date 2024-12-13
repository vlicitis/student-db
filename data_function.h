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
	int file = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0600);
    if (file > 0) {
	    write(file, db_ptr, size * sizeof(student));
    };
	close(file);
}

student* load_db(const char* filename, uint8_t* ret_num_entries) {
    uint8_t num_entries = 0;
    uint8_t bytes_read = 0;
	int file = open(filename, O_RDONLY);
	if (file < 0) {printf("No existing database ! \n");return NULL;};

    student* return_ptr = malloc(sizeof(student));
    while(1) {
        bytes_read = read(file, return_ptr + num_entries, sizeof(student)); // read one
        if (bytes_read < sizeof(student)) {
            close(file);
            *ret_num_entries = num_entries;
            return return_ptr;
        }
        num_entries++;
        return_ptr = realloc(return_ptr, (num_entries + 1) * sizeof(student));
        if (!return_ptr) {
            printf("CANT MALLOC\n");
            return NULL;
        }
    }
}