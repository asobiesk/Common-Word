Adam Sobieski, 283767
Analiza Algorytm�w - projekt
Temat projektu: Wsp�lny napis

1.Opis problemu
Program otrzymuje na wejsciu zestaw n sl�w m-literowych nad alfabetem {0, 1, *}. Celem programu jest odnalezienia
slowa wynikowego X nad alfabetem {0,1}, ktore b�dzie mialo zgodnosc na co najmniej jednej pozycji z kazdym slowem
z zadanego zestawu.

2.Mozliwe opcje uruchomienia programu:
	
	-> Tryb pomocniczy
	skladnia: ./common_word -help
	opis: 	Na ekranie konsoli wyswietlone zostaja wszystkie mozliwe tryby uzycia programu wraz z parametrami
	      	i kr�tkim opisem.

	-> Tryb por�wnawczy
	skladnia: ./common_word -compare [filename] [word_lenght]
	opis: 	Komenda ta wywoluje dla zadanego przypadku testowego dwa algorytmy - algorytm silowy i heurystyczny.
	      	Dla obu algorytm�w podaje znalezione rozwiazanie i szacunkowy czas dzialania.
	parametry:	[filename] - nazwa pliku z danymi testowymi
			[word_lenght] - liczba znak�w w slowie
	Jako, ze algorytm silowy do swojego wykonania musi wygenerowac list� wszystkich mozliwych sl�w binarnych
	o dlugosci word_lenght, tryb ten nalezy stosowac wylacznie do rozpatrywania przypadk�w zawierajacych kr�tkie 
	slowa (do 20 znak�w w slowie). Liczba sl�w w liscie jest jednak nieograniczona.

	-> Tryb z generowaniem danych
	skladnia: ./common_word -generate [filename] [word_number] [word_lenght]
	opis: 	Tryb ten w pierwszej kolejnosci generuje w pliku [filename] zestaw losowych danych testowych (sl�w
		nad alfabetem {0,1,*}) o zadanym rozmiarze i dlugolci sl�w. Nast�pnie na tych danych zostaje wykonany
		algorytm heurystyczny. Program wypisuje na ekran znalezione rozwiazanie i szacunkowy czas dzialania.
	parametry:	[filename] - nazwa pliku, w kt�rym maja zostac utworzone dane testowe
			[word_number] - liczba sl�w w generowanej liscie
			[word_lenght] - liczba znak�w w slowie

	-> Tryb z analiza czasu wykonania algorytmu przy rosnacej liczbie sl�w w liscie
	skladnia: ./common_word -test_word_number [filename] [starting_word_number] [word_lenght]
	opis:	Tryb ten bada zaleznosc mi�dzy czasem wykonania algorytmu a liczba sl�w w liscie. Liczba znak�w w
		slowie jest tu stala. Program wykonuje 9 pomiar�w, z kazdym kolenym pomiarem generujac dwukrotnie
		wi�kszy zestaw sl�w. Na wyjscie podawana jest tabela o trzech kolumnach. W kolumnie [n] podawana
		jest aktualna liczba sl�w w liscie. W kolumnie [t(n)] podawany jest zmierzony czas wykonania
		danej pr�by. W kolumnie [q(n)] podawany jest wsp�lczynnik zgodnosci oceny teoretycznej z pomiarem
		czasu znormalizowany do mediany. W biezacej wersji programu zalozona zlozonosc teoretyczna dla 
		n sl�w w liscie jest liniowa, wynosi O(n) = n. 	
	parametry:	[filename] - nazwa pliku, w kt�rym tworzone b�da dane testowe
			[starting_word_number] - poczatkowa liczba sl�w w liscie. Z kazdym kolejnym pomiarem b�dzie
			ona wzrastac dwukrotnie.
			[word_lenght] - stala liczba znak�w w slowie.

	-> Tryb z analiza czasu wykonania algorytmu przy rosn�cej liczbie znak�w w slowie
	skladnia: ./common_word -test_word_lenght [filename] [starting_word_number] [word_lenght]
	opis:	Tryb analogiczny do wariantu powyzej, tym razem jednak stala jest liczba sl�w w liscie, a kazdorazowemu
		podwojeniu ulega liczba znak�w w slowie. W biezacej wersji programu zalozona zlozonosc teoretyczna dla
		m znak�w w slowie jest liniowa, wynosi O(m) = m.

3. Pliki zr�dlowe.

	-> main.cpp            - zawiera implementacj� konsolowego interfejsu uzytkownika, zapewnia mozliwosc wywolywania programu
		                 z odpowiednimi opcjami i parametrami
	
	-> step.h	       - zawiera implementacj� struktury Step sluzacej do zapami�tywania krok�w dokonywanych przez
				 algorytm heurystyczny

	[W ponizszych parach plik�w plik example.h zawiera deklaracje funkcji, zas example.cpp - definicje funkcji\

	-> wordlist[.h/.cpp]   - zawiera implementacj� generatora danych losowych i wczytywania danych z pliku

	-> bruteforce[.h/.cpp] - zawiera implementacj� algorytmu silowego wraz z generacja listy wszystkich sl�w
				 binarnych o zadanej dlugosci

	-> heuristic[.h/.cpp]  - zawiera implementacj� wlasciwego algorytmu wraz z funkcjami pomocnicznymi

	-> tests[.h/.cpp]      - zawiera implementacje metod pozwalajacych na testowanie algorytm�w pod wzgl�dem poprawnosci wyniku
				 i czasu wykonywania.

4. Kompilacja.
W folderze z programem znajduje sie plik Makefile. W celu kompilacji nalezy wywolac komende make w katalogu programu. Program uruchamia sie konsolowo.				  

