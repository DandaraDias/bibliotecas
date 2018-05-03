CC=gcc
CFLAGS=-I. -O2
DEPS=linalg.h
OBJ=main.o ler.o imprime.o triangularizacao.o determinante.o gauss.o inversa.o multiplicacao.o jacobi.o
TARGET=liblinalg
LIBS=-lm 

%.o: %.c $(DEPS)
	$(CC) -c -fpic -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm $(OBJ)
