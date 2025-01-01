#include "struct.h"
#include <stdint.h>

void enter_data(student* db_ptr, uint8_t size);

void output_data(student* db_ptr, uint8_t size);

void save_db(const char* filename, student* db_ptr, uint8_t size);

student* load_db(const char* filename, uint8_t* ret_num_entries);

