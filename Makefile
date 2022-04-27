lab1: 
	cd lab01 && g++ main.cpp -o main -std=c++98 && ./main
	cd lab01 && rm main
lab2:
	cd lab02 && g++ main.cpp -o main -std=c++11 && ./main
	cd lab02 && rm main
lab3:
	cd lab03/src/io && g++ io.cpp -c -std=c++14 && rm *.o
	cd lab03/src/aggregation && g++ aggregation.cpp -c -std=c++14 && rm *.o
	cd lab03/src && g++ main.cpp -o main -std=c++14 && ./main
	