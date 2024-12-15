#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "functions.h"
#define MAX_STUDENTS (UINT8_MAX-1) // 254
#define db_filename "db.bin"

uint8_t student_cnt = 0;
int main() {
    char * input_char = malloc(sizeof(char));
    size_t * pointer_to_one = malloc(sizeof(size_t));
    *pointer_to_one = 1;
    student* students;
    printf("Read existing database (y/n)? \n");
    getline(&input_char, pointer_to_one, stdin);
    //printf("%#d \n", input_char);
    if (input_char[0] == 'y' || input_char[0] == 'Y') {
        
        students = load_db(db_filename, &student_cnt);
        if (students) {
            output_data(students, student_cnt);
            free(students);
            students = NULL;
        }
    }
    printf("Append to database (y/n)? \n");
    getline(&input_char, pointer_to_one, stdin);
	printf("\n");
    //printf("%d \n", input_char);
    if (input_char[0] == 'y' || input_char[0] == 'Y') {
        printf("Enter students count: \n");
        scanf("%hhu", &student_cnt);
        students = calloc(student_cnt, sizeof(student));
        enter_data(students, student_cnt);
        save_db(db_filename, students, student_cnt);
    }
    free(input_char);
    free(pointer_to_one);
}
