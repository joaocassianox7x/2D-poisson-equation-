CC = g++
CFLAGS = -Ofast -lm -fopenmp -llapack -lblas -larmadillo
EXECUTAVEL = binario
main: main_with_armadillo.cpp
	$(CC) -o $(EXECUTAVEL) $< $(CFLAGS)

clean:
	 rm -rf charge/*.txt
	 rm -rf poisson/*.txt
	 rm $(EXECUTAVEL)