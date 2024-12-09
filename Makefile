CC = gcc
BIN = student_db

student_db: common.c data_function.h struct.h
	$(CC) common.c -o $@

clean:
	rm -f *.o student_db
