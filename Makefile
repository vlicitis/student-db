CC = gcc
BIN = student_db

student_db: main.c data_function.h struct.h
	$(CC) main.c -o $@

clean:
	rm -f *.o student_db db.bin

help:
	@echo "make $(BIN) or make - build project"
	@echo "make clean - clean output files"
	@echo "make help - help"
