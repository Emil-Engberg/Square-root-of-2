all:
	g++ -march=native -std=c++20 -O2 -o main.out main.cpp -pthread -lgmpxx -lgmp -lmpfr -lgmp
	g++ -march=native -std=c++20 -O2 -o frac_to_dec.out frac_to_dec.cpp -pthread -lgmpxx -lgmp -lmpfr -lgmp
