CC=g++
CFLAGS=-c -Wall -std=c++11
SOURCES=main.cpp ./lib/Contact.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

run: $(EXECUTABLE)
	 ./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE) ./lib/*o output.txt

zip:
	zip -rX hw11.zip main.cpp makefile data.txt ./lib
