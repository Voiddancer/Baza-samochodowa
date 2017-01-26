// Baza samochodowa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
class Dom
{
		private:
			string m_miasto;
			string m_kraj;
			int m_typ;
			int m_ile_m2;
			int m_ile_pokoji;
			int m_cena;
			int m_rok_budowy;
		public:
		//Dom::Dom() {}
		Dom::Dom (string kraj , string miasto, int rok_budowy, int cena, int ile_pokoji,int ile_m2, int typ)  // Konstruktor obiektów do klasy Dom 
		{
			string m_miasto = miasto;
			string m_kraj = kraj;
			int m_typ = typ;
			int m_ile_m2 = ile_m2;
			int m_ile_pokoji = ile_pokoji;
			int m_cena = cena;
			int m_rok_budowy = rok_budowy;
		}
		void Dom::przegladanie()
		{
			cout << "Kraj: \t\t\t"<< m_kraj << endl;		// << kraj << " " << miasto << " " << rok_budowy << " " << cena << " " << Ile_pokoji << " " << ile_m2 << " " << typ <<
			cout << "Miasto: \t\t\t"<< m_miasto << endl;
			cout << "Rok rokbudowy: \t\t" << m_rok_budowy << " rok" << endl;
			cout << "Wartosc: \t\t\t" << m_cena << " zl" << endl;
			cout << "Ile pokoi: \t\t" << m_ile_pokoji << endl;
			cout << "Ile m^2: \t\t"<< m_ile_m2 << endl;
			cout << "Typ zabudowy: \t";
			if (m_typ == 1)      //1.Kawalerka 2.Mieszkanie 3.Dom szeregowy 4.Dom jednorodzinny 5.Domek letniskowy
				cout << "Kawalerka" << endl << endl << endl << endl;
			else if (m_typ == 2)
				cout << "Mieszkanie" << endl << endl << endl << endl;
			else if (m_typ == 3)
				cout << "Dom szeregowy" << endl << endl << endl << endl;
			else if (m_typ == 4)
				cout << "Dom jednorodzinny" << endl << endl << endl << endl;
			else if (m_typ == 5)
				cout << "Domek letniskowy" << endl << endl << endl << endl;
			cout << "^-strzalka w gore = poprzedni    v-strzalka w dol = nastepny" << endl;
			cout << "ESC = wyjscie                   DELETE = usun wybrany element" << endl;
		}


};
void w_menu();
void w_pod_menu();
void w_menu_sortowanie();
void dodawanie_z_klawiatory();
void obsluga_pliku();
void czytanie_z_pliku(string, int&, vector <Dom>&);
void haslo();
void dodawanie_do_bazy(string, string& , string&, int& , int& , int& , int& , int& , vector <Dom> &);


int main()
{
	string nazwa_bazy="b_d_2000.dox";
	string Zapisane_haslo;
	vector <Dom> vekt;
	vector <Dom> vekt_szuk;
	fstream plik("haslo.txt", ios::in);
	int licznik = 0;
	if (plik.good())
		plik >> Zapisane_haslo;
	else
	{
		cout << "Blad 'brak pliku'";
		Sleep(2000);
		exit(0);
	}
	plik.close();
	string miasto;
	string kraj;
	int typ;
	int ile_m2;
	int ile_pokoji;
	int cena;
	int rok_budowy;

	system("cls");

	string podane_haslo;
		cout << "Podaj chaslo: ";
		cin >> podane_haslo;
		if (podane_haslo == Zapisane_haslo)
		{
			czytanie_z_pliku(nazwa_bazy, licznik, vekt);
			while (1 != 0)
			{
				system("cls");
				w_menu();

				char menu = _getch();
				switch (menu)
				{
				case '1':						// dodawanie do bazy dziala!!! :)
				{
					dodawanie_do_bazy(nazwa_bazy, kraj, miasto, rok_budowy, cena, ile_pokoji, ile_m2, typ, vekt);
					licznik ++;
					break;
				}
				case '2':						// sortowanie bazy
				{
					system("cls");
					cout << "jestes w 2";
					Sleep(2000);
					break;

				}
				case '3':						//przegl¹danie bazy
				{
					system("cls");
					if (licznik == 0)
					{
						cout << "baza jest pusta";
						Sleep(3000);
						break;
					}
					int przeg = 0;
					vekt[przeg].przegladanie();

					//cout << "jestes w 3";
					//Sleep(2000);
					//break;
					while (1!=0)
					{
						//if ();
					}
				}

				}
			}
		}
		else {
				cout << "bledne haslo";
				Sleep(2000);
				main();
			 }

    return 0;
}

void w_menu()
{
	cout << "\n\n\n\n\n"
		<< "\t\t\t\tWitaj w Bazie Mieszkan\n\n"
		<< "\t\t\t\t1.dodaj do bazy"
		<< "\t\t\t\t"
		<< "\t\t\t\t"
		<< "\t\t\t\t";
}

void w_pod_menu()
{
}

void w_menu_sortowanie()
{
}

void dodawanie_z_klawiatory()
{
}

void obsluga_pliku()
{
}

void czytanie_z_pliku(string nazwa, int &licznik, vector <Dom>&vektor)
{
	string wczytana_linia;
	string m_miasto;
	string m_kraj;
	string ulica;
	int m_typ;
	int m_ile_m2;
	int m_ile_pokoji;
	int m_cena;
	int m_rok_budowy;
	fstream wczytywane(nazwa, ios::in);
	if(wczytywane.good()==true)
	{
		while (!wczytywane.eof())
		{
			getline(wczytywane, wczytana_linia);
			licznik ++;
		}
		licznik -= 1;
		fstream wczytywane(nazwa, ios::in);

		for (int i = 0; i < licznik; i++)
		{
			wczytywane >> m_kraj;
			wczytywane >> m_miasto;
			wczytywane >> m_rok_budowy;
			wczytywane >> m_cena;
			wczytywane >> m_ile_pokoji;
			wczytywane >> m_ile_m2;
			wczytywane >> m_typ;
			vektor.push_back(Dom(m_kraj, m_miasto, m_rok_budowy , m_cena, m_ile_pokoji  , m_ile_m2, m_typ));
		}
		wczytywane.close();
	}
	else 
	{
		cout << "Bark poszukiwanego pliku\n"
			<< "chcesz stworzyc pusta baze?\n"
			<< "1 = tak / 2 = nie\n";
		int podana;
		while (!(cin >> podana) || podana > 2 || podana == 0)
		{
			cin.clear();
			cin.ignore();
		}
		wczytywane.close();
		if (podana == 2)
		{
			exit(0);
		}
	}
}

void haslo()
{

}

void dodawanie_do_bazy(string nazwa,string &kraj , string &miasto, int &rok_budowy , int &cena, int &Ile_pokoji, int &ile_m2, int &typ , vector <Dom> &v)
{
	getchar();
	cout << "podaj kraj: ";
	getline(cin, kraj);
	transform(kraj.begin(), kraj.end(), kraj.begin(), ::toupper);
	cout << "podaj miasto: ";
	getline(cin, miasto);
	transform(miasto.begin(), miasto.end(), miasto.begin(), ::toupper);
	cout << "podaj rok budowy: ";
	while (!(cin >> rok_budowy) || rok_budowy > 2017 || rok_budowy == 1730)
	{
		cin.clear();
		cin.ignore();
		cout << "Podaj prawidlowa wartosc" << endl;
	}
	cout << "podaj cene: ";
	while (!(cin >> cena) || cena > 99999999 || cena <= 5000)
	{
		cin.clear();
		cin.ignore();
		cout << "Podaj prawidlowa wartosc" << endl;
	}
	cout << "Podaj ile pokoji: ";
	while (!(cin >> Ile_pokoji) || Ile_pokoji > 35 || Ile_pokoji == 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Podaj prawidlowa wartosc" << endl;
	}
	cout << "Podaj ile m^2: ";
	while (!(cin >> ile_m2) || ile_m2 > 350 || ile_m2 <= 10)
	{
		cin.clear();
		cin.ignore();
		cout << "Podaj prawidlowa wartosc" << endl;
	}
	cout << "Typ"
		 << "1.Kawalerka 2.Mieszkanie 3.Dom szeregowy 4.Dom jednorodzinny 5.Domek letniskowy";
	while (!(cin >> typ) || typ > 5 || typ == 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Podaj prawidlowa wartosc" << endl;
	}
	v.push_back(Dom(kraj, miasto, rok_budowy, cena, Ile_pokoji, ile_m2, typ));
	fstream zapisz(nazwa, ios::out | ios::app);
	zapisz << kraj <<" "<< miasto <<" "<< rok_budowy<<" "<< cena <<" "<< Ile_pokoji<<" "<< ile_m2<<" "<<typ<< endl;

}


