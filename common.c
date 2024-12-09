#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "data_function.h"

int main() {
    printf("Enter students count: ");
    uint8_t student_cnt = 0;
    scanf("%u", &student_cnt);
    student* students = malloc(student_cnt * sizeof(student));
    FILE * file = fopen("db.bin", "r");
    
    file = fopen("db.bin", "r+");
    if (!file) {
       file = fopen("db.bin", "w");
       enter_data(students, student_cnt);
       fwrite(students,sizeof(student),student_cnt, file);
    }
    fread(students, sizeof(student), student_cnt, file);
    output_data(students, student_cnt);
    fclose(file);
}
