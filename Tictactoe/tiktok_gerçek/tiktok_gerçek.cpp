#include <iostream>
#include <conio.h> // _getch() için
#include <stdlib.h>// system("cls") için
using namespace std;

int tur = 0;
char tahta[8][19];
void tahtayazdir();
void Imlec(int, int);
int Logic();
void Winner();



int main()
{
	int devam, x = 0;
	char restart;
	for (devam = 1; devam == 1;)
	{

		int i, j, imlecy = 3, imlecx = 9, sonuc = 0;

		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 19; j++)
			{
				if ((j == 5 || j == 6 || j == 12 || j == 13) && (i != 2 && i != 5))
				{
					tahta[i][j] = '|';
				}
				else if (i == 2 || i == 5)
				{
					tahta[i][j] = '=';
				}
				else
					tahta[i][j] = ' ';

			}
		}
		Imlec(imlecy, imlecx);
		tahtayazdir();
		for (tur = 0; tur < 9;)
		{

			unsigned char yon;

			yon = _getch();

			if (yon == 0xE0)
			{
				yon = _getch();
				switch (yon)
				{
				case 72:
				{
					if (imlecy != 0)
						imlecy -= 3; //up
					break;
				}
				case 80:
				{
					if (imlecy != 6)
						imlecy += 3; //down
					break;
				}
				case 75:
				{
					if (imlecx != 2)
						imlecx -= 7; //left
					break;
				}
				case 77:
				{
					if (imlecx != 16)
						imlecx += 7; //right
					break;
				}

				}
			}
			else if (yon == ' ')
			{
				if (tur % 2 == 0 && tahta[imlecy + 1][imlecx] == ' ')
				{

					tahta[imlecy + 1][imlecx] = 'O';
					tur++;
				}
				else if (tahta[imlecy + 1][imlecx] == ' ')
				{
					tahta[imlecy + 1][imlecx] = 'X';
					tur++;
				}
			}
			system("cls");

			Imlec(imlecy, imlecx);
			tahtayazdir();
			sonuc = Logic();
			if (sonuc == 1)
				break;

		}
		if (sonuc == 0)
		{
			system("cls");
			cout << "Game Over: Draw" << endl;
		}
		while (x == 0)
		{
			cout << "restart:Y/N ?";
			cin >> restart;
			if (restart == 'Y' || restart == 'y')
			{
				system("cls");
				break;
			}
			else if (restart == 'N' || restart == 'n')
			{
				devam = 0;
				break;
			}

		}

	}
}

void tahtayazdir()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 19; j++)
		{
			cout << tahta[i][j];
		}
		cout << endl;
	}
	if (tur % 2 == 0)
	{
		cout << "O's turn";
	}
	else
	{
		cout << "X's turn";
	}
	cout << endl << "Move with arrow keys" << endl << "Place symbols with space key";
}

void Imlec(int y, int x)
{
	tahta[0][2] = ' ';
	tahta[0][9] = ' ';
	tahta[0][16] = ' ';
	tahta[3][2] = ' ';
	tahta[3][9] = ' ';
	tahta[3][16] = ' ';
	tahta[6][2] = ' ';
	tahta[6][9] = ' ';
	tahta[6][16] = ' ';
	tahta[y][x] = '*';

}

int Logic()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 19; j++)
		{
			if (tahta[1][j] == tahta[4][j] && tahta[4][j] == tahta[7][j] && (tahta[1][j] == 'X' || tahta[1][j] == 'O'))
			{
				Winner();
				return 1;
			}
			else if (tahta[i][2] == tahta[i][9] && tahta[i][2] == tahta[i][16] && (tahta[i][2] == 'X' || tahta[i][2] == 'O'))
			{
				Winner();
				return 1;
			}
			else if (tahta[1][2] == tahta[4][9] && tahta[7][16] == tahta[1][2] && (tahta[1][2] == 'X' || tahta[1][2] == 'O'))
			{
				Winner();
				return 1;
			}
			else if (tahta[1][16] == tahta[4][9] && tahta[1][16] == tahta[7][2] && (tahta[1][16] == 'X' || tahta[1][16] == 'O'))
			{
				Winner();
				return 1;
			}
		}
	}
	return 0;

}

void Winner()
{
	system("cls");
	if ((tur + 1) % 2 == 0)
		cout << "Game Over: O wins" << endl;
	else
		cout << "Game Over: X wins" << endl;
}



