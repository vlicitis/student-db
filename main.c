#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "data_function.h"
#define MAX_STUDENTS (UINT8_MAX-1) // 254
#define db_filename "db.bin"

uint8_t student_cnt = 0;
int main() {
    printf("Enter students count: ");
    scanf("%hhu", &student_cnt);
    
    char input_char;
    student* students;
    printf("Read existing database (y/n)? ");
    scanf(" %[yn]c", &input_char);
    //printf("%#d \n", input_char);
    if (input_char == 'y' || input_char == 'Y') {
   
        students = load_db(db_filename, student_cnt);
        output_data(students, student_cnt);
        if (students) {
            free(students);
            students = NULL;
        }
    }
    printf("Save new database (y/n) ?");
    scanf(" %[yn]c", &input_char);
    //printf("%d \n", input_char);
    if (input_char == 'y' || input_char == 'Y') {
      
        students = calloc(student_cnt, sizeof(student));
        enter_data(students, student_cnt);
        save_db(db_filename, students, student_cnt);
    }
}
