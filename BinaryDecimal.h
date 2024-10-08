#pragma once

// Autor : Pierre Mandambu

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <locale>
#include <cmath>

using namespace std;

class BinaryDecimal
{
private:
	int p_iDecimal;                  // Erste Dezimalzahl (erste Eingabe)
	int p_iBinary;                  // Zweite Dezimalzahl (zweite Eingabe)

public:
	//Standard-Konstruktor
	BinaryDecimal();

	//Konstruktor mit Initialisierung von p_iDecima1 und p_iDecimal2
	BinaryDecimal(int);

	//Standard-Destruktor
	virtual ~BinaryDecimal();

};

ostream& operator<<(ostream&, BinaryDecimal&);  //Operand kein Element der Klasse
