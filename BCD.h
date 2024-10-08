#pragma once

// Autor : Pierre Mandambu
// Date : 25.03.2024

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


/*!
@brief Klasse BCD

@class BCD dient zur Umrechnung von Dezimalzahlen in BCD-Zahlen.

Dar�ber hinaus bietet sie f�r die Anwender die M�glichkeit zwei Dezimalzahlen in BCD-Code zu addieren
und die komplette Berechnung zu verfolgen, und damit um zu sehen, wie man zwei Zahlen in BCD-Code addiert.

Zwei Funktionen, n�mlich vSumme und vAddition, spielen neben anderen Funktionen eine wichtige Rolle.
*/
class BCD
{
public:
	//Standard-Konstruktor
	BCD();

	//Konstruktor mit Initialisierung von p_iDecima1 und p_iDecimal2
	BCD(int, int);

	//Standard-Destruktor
	virtual ~BCD();

	// Diese Funktion f�gt ein String am Anfang eines Vectors hinzu
	void vPushFront(string sEingabe, int iPlace = 1, int iAnzahl = 1);

	// Diese Funktion rechnet eine Dezimalzahl in eine BCD-Zahl um
	void vDecToBin();

	// Diese Funktion rechnet eine BCD-Zahl in eine Dezimalzahl um
	void vBinToDec();

	/* Die BCD - Zahlen werden hier zerlegt, um die Berechnung zu erleichtern,
	und dann werden sie in den Vectoren p_vsPartition1, p_vsPartition2 gespeichert */
	void vPartition();

	/* Die Funktion vSumme addiert zwei Bin�rzahlen eines Block von den Partitionen
	oder von der ersten Summation mit dem Korrektur-String, falls j = 2 ist */
	void vSumme(int iCursor, int j = 1);

	// Die Funktion vAddition addiert zwei BCD-Zahlen
	void vAddition();

	// Diese Funktion zeigt den gesamten Prozess der Addition von BCD-Zahlen an
	void vAusgabe(ostream&);


private:
	int p_iDecimal1;                  // Erste Dezimalzahl (erste Eingabe)
	int p_iDecimal2;                  // Zweite Dezimalzahl (zweite Eingabe)
	int p_iUebertrag1;                // Erster �bertrag
	int p_iUebertrag2;                // Zweiter �bertrag

	string p_sDecimal1;               // Erste Dezimalzahl (erste Eingabe), gespeichert als string
	string p_sDecimal2;               // Zweite Dezimalzahl (zweite Eingabe), gespeichert als string
	string p_sUebertrag1;             // Speichert alle �bertr�ge der ersten Summation von einem Block
	string p_sUebertrag2;             // Speichert alle �bertr�ge der zweiten Summation von einem Block
	string p_sBinaer1;                // Erste Bin�rzahl
	string p_sBinaer2;                // Zweite Bin�rzahl
	string p_sSumme;                  // Speichert die Summe von zwei Bin�rzahlen
	string p_skorrektur;              // Speichert die Korrektur 0110, wenn die Zahl eine Pseudotetrade ist

	vector<int> p_viResult;           // Speichert das letzte Ergebnis in einer Dezimalzahl
	vector<string> p_vsPseudotetraden = { "1010", "1011", "1100", "1101", "1110", "1111" };   // Pseudotetrade
	vector<string> p_vsBCD_Code = { "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001" }; // 1 - 9 in BCD System
	vector<string> p_vsPartition1, p_vsPartition2, p_vsSummation1, p_vsSummation2, p_vsUebertrag1, p_vsUebertrag2, p_vsFrage1, p_vsFrage2;

};

ostream& operator<<(ostream&, BCD&);  //Operand kein Element der Klasse



