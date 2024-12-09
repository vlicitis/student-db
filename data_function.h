#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "struct.h"


void enter_data(student* db_ptr, uint8_t size) {
    if (db_ptr == NULL) {printf("NULLPTR !\n");return;};
    for (uint8_t i = 0; i < size; i++) {
    printf("Student %u \nEnter data (firstname, lastname, course, group): ",i);
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
