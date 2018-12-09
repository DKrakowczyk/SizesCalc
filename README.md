### #SizesCalc
| C++ | QT |
|--|--|
|

Aplikacja **SizesCalc** pozwala na obliczanie, w zależności od wybranej opcji, długości pręta lub wysokości wykorzystanego wlewka w procesach kucia i wyciskania. 


### #Struktura aplikacji
Aplikacja składa się z trzech głównych okien użytkownika :
> Okno konfiguracji programu oraz wyboru akcji, 

> Okno arkusza kalkulacyjnego, 

> Okno bazy danych


![Okno wyboru](https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/intermediary/f/839692c5-d86c-4b15-b617-6aedeb893d5d/dcu0e9y-b84736bf-7f7b-4774-82fd-6de887e432ee.png)


### #Połączenie z bazą danych
Aby połączyć się z lokalną bazą danych należy:
-  Kliknąć w przycisk “Dodaj bazę danych”, a następnie wybrać plik **database.db** z podkatalogu **_database**

Ścieżka do bazy danych zostanie automatycznie wczytana przy każdym kolejnym uruchomieniu programu. jej konfiguracja jest wymagana wyłącznie w przypadku pierwszego uruchomienia 
	
### #Arkusz kalkulacyjny
W celu uzyskania długości pręta konieczne jest uzupełnienie wartościami pól lewej lub prawej części okna, w zależności od posiadanych parametrów wejściowych.

 Domyślnie obliczenia dokonywane są dla pręta, którego przekrój jest kwadratem. Po kliknięciu w jakąkolwiek część interfejsu oraz zmianie danych, program automatycznie przeliczy zadane wartości oraz wyświetli wynik. 
 
Możliwa jest również zmiana zadanej objętości odpadu lub przyjęcie jej domyślnej wartości. 

![Okno arkusza kalkulacyjnego](https://lh3.googleusercontent.com/FbJGDzL1SBMnTBSKNhq4_j4Cjb0KSsVogiOjzdVOU9ZroTpIYLrdbUdB_yBan6jXqF9dLsaGgPV7NzD6nz31=w1366-h657-rw)

W razie konieczności zapisu danych pomiarowych oraz wyników w bazie danych, w celu ich późniejszego wykorzystania, konieczne jest wciśnięcie przycisku **“Zapisz do bazy danych”**.

## #Baza danych

 Wcisnąć przycisk **“Baza Danych”**, a następnie wybrać **“Wyświetl bazę danych”** w głównym oknie programu.
 
![Baza](https://lh4.googleusercontent.com/N0FUzRrwAMi5eXEJUzAOQPbjOpK45iQk8dUKtXSgFTVSquki6l5uU7Ob7FJrkFG4cvjsmsh-3SL-S9WsnZu5=w1366-h657)

Przeglądanie zawartości bazy danych możliwe jest za pomocą **suwaka** na dole tabeli.

 W celu usunięcia elementu z bazy, należy dwukrotnie kliknąć w **jakąkolwiek komórkę rekordu**, który chcemy usunąć. Otrzymamy wtedy komunikat o poprawnym przebiegu operacji.
