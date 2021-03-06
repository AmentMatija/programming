﻿#include "pch.h"
#include <iostream>
#include<stdlib.h>
#include<string>
#include <ctime>
using namespace std;

const int r = 10;
const int c = 10;

int tries = 25;
int shipCount = 0;
bool hitMessage = false;
bool missMessage = false;
int enemyShips = 0;

void placeShip(int arr[r][c], int shipLen);
void directions();
void printRealBattlefield(int arr[r][c]);
void inputCoor(int arr[r][c], string arrs[r][c]);
void printBoard(string arrs[r][c]);
void initBoard(string arrs[r][c]);

int main()	
{
	srand(time(NULL));

	int battlefield[10][10] = { 0 };	// polje sa polozajima brodova
	string boardPrint[10][10];		// polje koje ce se ispisivati
	
	initBoard(boardPrint);			// dodavanje razmaka " " u svaki clan stringa koji ispisuje
	directions();				//uvodni tekst
	printBoard(boardPrint);			//ispisivanje polja
	//---------------------------------------------------------------------//postavljanje brodova na plocu
	while (shipCount < 3) {
		placeShip(battlefield, 1);
	}
	while (shipCount < 5) {
		placeShip(battlefield, 2);
	}
	while (shipCount < 7) {
		placeShip(battlefield, 3);
	}
	while (shipCount < 8) {
		placeShip(battlefield, 4);
	}
	//----------------------------------------------------------------------//postavljanje brodova na plocu
	//printRealBattlefield(battlefield);					//prikazuje polozaj brodova
	while (enemyShips < 25 && tries > 0)					//igra traje dok ima brodova ili pokusaja(bojnih glava)
	{
		inputCoor(battlefield, boardPrint);
	}

	if (enemyShips >=25)							//ispis pobjede ako nema brojeva(unisteno 25 polja)
	{
		cout << "\n***********************************************" << endl;
		cout << "** Pobjeda!!! Okupatorska flota je unistena! **" << endl;
		cout << "***********************************************" << endl;
		cout << "\n\n\n";
	}
	if(tries<=0)								//ispis izgubljene igre ako vise nema pokusaja(bojnih glava)
	{		
		cout << "\n************************************" << endl;
		cout << "** Izgubili ste! Igra je gotova.. **" << endl;
		cout << "************************************" << endl;
		cout << "\n\n\n";
	}
}
void placeShip(int arr[r][c], int shipLen)
{
	bool fieldTaken = false;
	int HVSwitch = rand() % 10;								//horizontal - vertical switch
	int randFieldX = rand() % 10;								//random x coordinates
	int randFieldY = rand() % 10;								//random y coordinates
	
	if (HVSwitch % 2 == 0) {								//horizontal - vertical switch 1.st state (vertical)
		if (randFieldY <= 5)								//ako je y manji od 5		
		{
			for (int y = randFieldY; y <= randFieldY + shipLen; y++)		//projera jesu li polja slobodna
			{	
				if (arr[y][randFieldX] != 0)
				{
					fieldTaken = true;	
				}				
			}
			
			if(!fieldTaken)									
			{
				for (int y = randFieldY; y <= randFieldY + shipLen; y++)	//zapisivanje u polja
				{
					arr[y][randFieldX] = 1;						
				}
				shipCount += 1;							//inkrementacija brojaca
			}
		}
		else										//ako je y veci od 5
		{
			for (int y = randFieldY; y >= randFieldY - shipLen; y--)		//provjera jesu li polja slobodna
			{
				if (arr[y][randFieldX] != 0)
				{																
					fieldTaken = true;
				}
			}

			if (!fieldTaken)
			{
				for (int y = randFieldY; y >= randFieldY - shipLen; y--)	//zapisivanje u polja
				{
					arr[y][randFieldX] = 1;					
				}
				shipCount += 1;
			}				
		}
	}
	else											//horizontal - vertical switch 2nd state (horizontal)
	{
		if (randFieldX <= 5)								//ako je x manji od 5
		{
			for (int x = randFieldX; x <= randFieldX + shipLen; x++)		//provjera jesu li polja slobodna
			{
				if (arr[randFieldY][x] != 0)
				{
					fieldTaken = true;
				}
			}		

			if (!fieldTaken)
			{
				for (int x = randFieldX; x <= randFieldX + shipLen; x++)	//zapisivanje u polja
				{					
						arr[randFieldY][x] = 1;					
				}
				shipCount += 1;
			}				
		}
		else										//ako je x veci od 5
		{
			for (int x = randFieldX; x >= randFieldX - shipLen; x--)		//proje
			{
				if (arr[randFieldY][x] != 0)
				{
					fieldTaken = true;
				}
			}

			if (!fieldTaken)
			{
				for (int x = randFieldX; x >= randFieldX - shipLen; x--)
				{
					arr[randFieldY][x] = 1;					
				}
				shipCount += 1;
			}				
		}
	}	
}
void directions()
{
	cout << "Pozdrav Generale!\nNeprijateljske snage okupirale su 1/4 naseg mora!\nNarodna obrana donirala je 25 bojnih glava za koordinirani napad pod Vasim vodstvom \n	te ce donirati jos po jednu za svaku koja pronadje vojni cilj!"<<endl;
	cout << "\nPodaci nase obavjestajne sluzbe o sastavu neprijateljske flote:" << endl;
	cout << "	1 nosac zrakoplova	[5 polja]" << endl;
	cout << "	2 bojna broda		[4 polja]" << endl;
	cout << "	2 razaraca		[3 polja]" << endl;
	cout << "	3 fregate		[2 polja]" << endl;
	cout << "	-----------------------------" << endl;
	cout << "	8 brodova		[25 polja]" << endl;
	cout << "\nNarodna obrana predaje Vam komandu i ocekuje potpuno unistenje neprijateljskih jedinica!\nPozdrav Generale!\n\n\n\n";
	
	system("pause");
	system("cls");
}
void printRealBattlefield(int arr[r][c])	//ispisuje polozaje postavljenih brodova
{
	cout << "-1-2-3-4-5-6-7-8-9-10		x-koordinata" << endl;
	cout << "---------------------" << endl;
	for (int x = 0; x <= 9; x++)
	{
		cout << "|";
		for (int y = 0; y <= 9; y++)
		{
			cout << arr[x][y] << "|";
		}

		cout << " " << x + 1 << endl;
	}	cout << "--------------------- y-koordinata" << endl;
}
void inputCoor(int arr[r][c], string arrs[r][c])
{
	bool validInput = false;
	int cX;
	int cY;

	while (!validInput)
	{
		cout << "\nUnesi koordinatu: X:	";
		cin >> cX;
		cout << "\nUnesi koordinatu: Y:	";
		cin >> cY;
	
		if(cX<=10 && cX>=1 && cY<=10 && cY>=1)
		{
			validInput = true;				
		}
		else { cout << "\nPogresan unos!"; }
	}
	
	if (arr[cY-1][cX-1] == 0)
	{
		arrs[cY-1][cX-1] = ".";
		tries -= 1;
		missMessage = true;
	}
	else 
	{
		enemyShips += 1;
		arrs[cY-1][cX-1] = "@";
		hitMessage = true;
	}
	printBoard(arrs);	
}
void printBoard(string arrs[r][c]) {
	system("cls");
	cout << "X-1-2-3-4-5-6-7-8-9-10" << endl;
	cout << " --------------------- Y" << endl;
	
	for (int x = 0; x <= 9; x++)
	{
		cout << " |";
		for (int y = 0; y <= 9; y++)
		{
			
			cout << arrs[x][y] << "|";
		}
		cout << " " << x + 1 << endl;	
	}	
	cout << " ---------------------" << endl;
	cout << "X-1-2-3-4-5-6-7-8-9-10" << endl;
	
	if (hitMessage == true)
	{
		cout << "\nPogodak!\nGenerale, kurir donosi dobre vijesti!\nNarodna obrana cestita na uspjehu i salje jednu bojnu glavu u znak podrske nasoj oslobodilackoj borbi!\n";
		hitMessage = false;
	}
	if (missMessage == true)
	{
		cout << "\nPromasaj!\nOkupatorske jedinice ostaju operativne!\n";
		missMessage = false;
	}
	cout << "\nBojne glave: " << tries << endl;
	cout << "Unistena neprijateljska flota: " << enemyShips << "/25\n\n\n";	
}
void initBoard(string arrs[r][c]) //dodaje razmak u svaki clan string liste
{
	for (int x = 0; x <= 9; x++)
	{
		for (int y = 0; y <= 9; y++)
		{
			arrs[x][y] = " ";
		}
	}
}

