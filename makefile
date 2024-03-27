CC = g++
CFLAGS = 

all: transporte

transporte: main.o modelagem.o
	$(CC) $(CFLAGS) -o main main.o modelagem.o -o transporte

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

modelagem.o: modelagem.cpp modelagem.h
	$(CC) $(CFLAGS) -c modelagem.cpp

clean:
	rm -rf *.o main transporte
