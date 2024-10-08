// main.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
// Autor : Pierre Mandambu
// Date : 25.03.2024

#include "BCD.h"


int main()
{
	char cEingabe = ' ';

	cout << "Herzlichen Willkommen zu unserem Programm"
		<< endl << "Es dient zur Addition von Zwei BCD-Zahlen"
		<< endl << "-----------------------------------------"
		<< endl << endl;
	do
	{
		cout << "Geben Sie zwei positive Zahlen  ein" << endl;
		int in1, in2;
		bool BExam = true;

		while (BExam)
		{
			cin >> in1 >> in2;

			if (in1 < 0 || in2 < 0)
			{
				cout << "Fehler bei der Eingabe. Bitte wiederholen Sie" << endl;
				cin >> in1 >> in2;
			}
			else
			{
				BExam = false;
			}
		}

		BCD bEingabe(in1, in2);
		bEingabe.vAddition();
		cout << bEingabe << endl;

		cout << "Druecken Sie 'e' oder 'E', wenn Sie das Programm verlassen wollten."
			<< endl << "Sonst druecken Sie ein beliebiges Zeichen" << endl;

		cin >> cEingabe;
		cin.ignore(5, '\n');
		cout << endl << endl << endl << endl;
	} while (cEingabe != 'e' && cEingabe != 'E');

	return 0;
}
