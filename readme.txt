Adam Sobieski, 283767
Analiza Algorytmów - projekt
Temat projektu: Wspólny napis

1.Opis problemu
Program otrzymuje na wejsciu zestaw n slów m-literowych nad alfabetem {0, 1, *}. Celem programu jest odnalezienia
slowa wynikowego X nad alfabetem {0,1}, ktore bêdzie mialo zgodnosc na co najmniej jednej pozycji z kazdym slowem
z zadanego zestawu.

2.Mozliwe opcje uruchomienia programu:
	
	-> Tryb pomocniczy
	skladnia: ./common_word -help
	opis: 	Na ekranie konsoli wyswietlone zostaja wszystkie mozliwe tryby uzycia programu wraz z parametrami
	      	i krótkim opisem.

	-> Tryb porównawczy
	skladnia: ./common_word -compare [filename] [word_lenght]
	opis: 	Komenda ta wywoluje dla zadanego przypadku testowego dwa algorytmy - algorytm silowy i heurystyczny.
	      	Dla obu algorytmów podaje znalezione rozwiazanie i szacunkowy czas dzialania.
	parametry:	[filename] - nazwa pliku z danymi testowymi
			[word_lenght] - liczba znaków w slowie
	Jako, ze algorytm silowy do swojego wykonania musi wygenerowac listê wszystkich mozliwych slów binarnych
	o dlugosci word_lenght, tryb ten nalezy stosowac wylacznie do rozpatrywania przypadków zawierajacych krótkie 
	slowa (do 20 znaków w slowie). Liczba slów w liscie jest jednak nieograniczona.

	-> Tryb z generowaniem danych
	skladnia: ./common_word -generate [filename] [word_number] [word_lenght]
	opis: 	Tryb ten w pierwszej kolejnosci generuje w pliku [filename] zestaw losowych danych testowych (slów
		nad alfabetem {0,1,*}) o zadanym rozmiarze i dlugolci slów. Nastêpnie na tych danych zostaje wykonany
		algorytm heurystyczny. Program wypisuje na ekran znalezione rozwiazanie i szacunkowy czas dzialania.
	parametry:	[filename] - nazwa pliku, w którym maja zostac utworzone dane testowe
			[word_number] - liczba slów w generowanej liscie
			[word_lenght] - liczba znaków w slowie

	-> Tryb z analiza czasu wykonania algorytmu przy rosnacej liczbie slów w liscie
	skladnia: ./common_word -test_word_number [filename] [starting_word_number] [word_lenght]
	opis:	Tryb ten bada zaleznosc miêdzy czasem wykonania algorytmu a liczba slów w liscie. Liczba znaków w
		slowie jest tu stala. Program wykonuje 9 pomiarów, z kazdym kolenym pomiarem generujac dwukrotnie
		wiêkszy zestaw slów. Na wyjscie podawana jest tabela o trzech kolumnach. W kolumnie [n] podawana
		jest aktualna liczba slów w liscie. W kolumnie [t(n)] podawany jest zmierzony czas wykonania
		danej próby. W kolumnie [q(n)] podawany jest wspólczynnik zgodnosci oceny teoretycznej z pomiarem
		czasu znormalizowany do mediany. W biezacej wersji programu zalozona zlozonosc teoretyczna dla 
		n slów w liscie jest liniowa, wynosi O(n) = n. 	
	parametry:	[filename] - nazwa pliku, w którym tworzone bêda dane testowe
			[starting_word_number] - poczatkowa liczba slów w liscie. Z kazdym kolejnym pomiarem bêdzie
			ona wzrastac dwukrotnie.
			[word_lenght] - stala liczba znaków w slowie.

	-> Tryb z analiza czasu wykonania algorytmu przy rosn¹cej liczbie znaków w slowie
	skladnia: ./common_word -test_word_lenght [filename] [starting_word_number] [word_lenght]
	opis:	Tryb analogiczny do wariantu powyzej, tym razem jednak stala jest liczba slów w liscie, a kazdorazowemu
		podwojeniu ulega liczba znaków w slowie. W biezacej wersji programu zalozona zlozonosc teoretyczna dla
		m znaków w slowie jest liniowa, wynosi O(m) = m.

3. Pliki zródlowe.

	-> main.cpp            - zawiera implementacjê konsolowego interfejsu uzytkownika, zapewnia mozliwosc wywolywania programu
		                 z odpowiednimi opcjami i parametrami
	
	-> step.h	       - zawiera implementacjê struktury Step sluzacej do zapamiêtywania kroków dokonywanych przez
				 algorytm heurystyczny

	[W ponizszych parach plików plik example.h zawiera deklaracje funkcji, zas example.cpp - definicje funkcji\

	-> wordlist[.h/.cpp]   - zawiera implementacjê generatora danych losowych i wczytywania danych z pliku

	-> bruteforce[.h/.cpp] - zawiera implementacjê algorytmu silowego wraz z generacja listy wszystkich slów
				 binarnych o zadanej dlugosci

	-> heuristic[.h/.cpp]  - zawiera implementacjê wlasciwego algorytmu wraz z funkcjami pomocnicznymi

	-> tests[.h/.cpp]      - zawiera implementacje metod pozwalajacych na testowanie algorytmów pod wzglêdem poprawnosci wyniku
				 i czasu wykonywania.

4. Kompilacja.
W folderze z programem znajduje sie plik Makefile. W celu kompilacji nalezy wywolac komende make w katalogu programu. Program uruchamia sie konsolowo.				  

