all:
	g++ -std=c++17 -O2 -o main.out main.cpp -pthread -lgmpxx -lgmp -lmpfr -lgmp
