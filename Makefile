common_word: main.o bruteforce.o heuristic.o wordlist.o tests.o
	g++ main.o bruteforce.o heuristic.o wordlist.o tests.o -o common_word

main.o: main.cpp
	g++ -c main.cpp

bruteforce.o: bruteforce.cpp
	g++ -c bruteforce.cpp

heuristic.o: heuristic.cpp
	g++ -c heuristic.cpp

wordlist.o: wordlist.cpp
	g++ -c wordlist.cpp

tests.o: tests.cpp
	g++ -c tests.cpp

clear: 
	rm *o common_word
