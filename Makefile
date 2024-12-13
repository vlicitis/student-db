CC = gcc
BIN = student_db
SOURCES = data_function.c main.c
HEADERS = functions.h struct.h
OBJECTS = $(SOURCES:.c=.o)

$(BIN): $(OBJECTS) $(HEADERS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -f $(BIN) $(OBJECTS) db.bin

help:
	@echo "make $(BIN) or make - build project"
	@echo "make clean - clean output files"
	@echo "make help - help"
