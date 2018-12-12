### #SizesCalc
| C++ | QT |
|--|--|



**SizesCalc** application allows to calculate length or height of the bar, depending on the choosen option. 


### #Application structure
The application consists of three main user windows:

> Program configuration window and action selection,

> Spreadsheet window,

> Database window


![Okno wyboru](https://github.com/DKrakowczyk/SizesCalc/blob/master/screenshots/main.PNG?raw=true)


### #Connection to the database
To connect to a local database:
- Click on the "Add database" button and then select the file **database.db** from the subdirectory **_ database**

The path to the database will be automatically loaded each time the program is started. The configuration is only required for the first run
	
### #Spreadsheet

In order to obtain the length of the bar, it is necessary to supplement the values ​​of the left or right part of the window, depending on the input parameters.

By default, calculations are made for a bar whose cross-section is a square. After clicking on any part of the interface and changing data, the program will automatically calculate the set values ​​and display the result.
 
It is also possible to change the set waste volume or to adopt its default value. 

![Okno arkusza kalkulacyjnego](https://github.com/DKrakowczyk/SizesCalc/blob/master/screenshots/calculate.PNG?raw=true)

If it is necessary to save measurement data and results in the database, in order to use them later, it is necessary to press the button **"Save to the database"**.

## #Baza danych

Press the button **"Data Base"**, and then select **"View database"** in the main program window.
 
![Baza](https://github.com/DKrakowczyk/SizesCalc/blob/master/screenshots/database.PNG?raw=true)

Browsing the contents of the database is possible using the ** slider ** at the bottom of the table.

In order to remove an item from the database, double-click on ** any record cell ** that we want to delete. We will then receive a message about the correct course of the operation.
