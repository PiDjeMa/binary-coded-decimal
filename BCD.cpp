#include "BCD.h"

// Autor : Pierre Mandambu
// Date : 25.03.2024

BCD::BCD() :
	p_viResult(0), p_vsPartition1(0), p_vsPartition2(0), p_vsSummation1(0), p_vsSummation2(0), p_vsUebertrag1(0), p_vsUebertrag2(0), p_vsFrage1(0), p_vsFrage2(0),
	p_sSumme(""), p_sUebertrag1("0"), p_sUebertrag2("0"), p_skorrektur("0110"), p_sDecimal1(""), p_sDecimal2(""), p_sBinaer1(""), p_sBinaer2(""),
	p_iDecimal1(0), p_iDecimal2(0), p_iUebertrag1(0), p_iUebertrag2(0)
{
}

BCD::BCD(int iDecimal1, int iDecimal2) :
	p_viResult(0), p_vsPartition1(0), p_vsPartition2(0), p_vsSummation1(0), p_vsSummation2(0), p_vsUebertrag1(0), p_vsUebertrag2(0), p_vsFrage1(0), p_vsFrage2(0),
	p_sSumme(""), p_sUebertrag1("0"), p_sUebertrag2("0"), p_skorrektur("0110"), p_sDecimal1(""), p_sDecimal2(""), p_sBinaer1(""), p_sBinaer2(""),
	p_iDecimal1(iDecimal1), p_iDecimal2(iDecimal2), p_iUebertrag1(0), p_iUebertrag2(0)
{
}



BCD::~BCD()
{
}

// Diese Funktion fügt ein String sEingabe am Anfang eines Vektors ein
void BCD::vPushFront(string sEingabe, int iPlace, int iAnzahl)
{
	switch (iPlace)
	{
	case 1:
		p_vsSummation1.insert(p_vsSummation1.begin(), iAnzahl, sEingabe);
		break;
	case 2:
		p_vsSummation2.insert(p_vsSummation2.begin(), iAnzahl, sEingabe);
		break;
	case 3:
		p_vsUebertrag1.insert(p_vsUebertrag1.begin(), iAnzahl, sEingabe);
		break;
	case 4:
		p_vsUebertrag2.insert(p_vsUebertrag2.begin(), iAnzahl, sEingabe);
		break;
	case 5:
		p_vsFrage1.insert(p_vsFrage1.begin(), iAnzahl, sEingabe);
		break;
	case 6:
		p_vsFrage2.insert(p_vsFrage2.begin(), iAnzahl, sEingabe);
		break;
	case 7:
		p_vsPartition1.insert(p_vsPartition1.begin(), iAnzahl, sEingabe);
		break;
	case 8:
		p_vsPartition2.insert(p_vsPartition2.begin(), iAnzahl, sEingabe);
		break;

	default:
		p_vsSummation1.insert(p_vsSummation1.begin(), iAnzahl, sEingabe);
		break;
	}
}

// Diese Funktion rechnet eine Dezimalzahl in eine BCD-Zahl um
void BCD::vDecToBin()
{
	// Umwandlung einer ganzen Zahl in ein String : Erste Eingabe
	p_sDecimal1 = to_string(p_iDecimal1);

	// Umwandlung des Strings in eine BCD-Zahl
	for (int i = 0; i < p_sDecimal1.length(); ++i)
	{
		switch (p_sDecimal1[i])
		{
		case '0':
			p_sBinaer1 += "0000";
			break;
		case '1':
			p_sBinaer1 += "0001";
			break;
		case '2':
			p_sBinaer1 += "0010";
			break;
		case '3':
			p_sBinaer1 += "0011";
			break;
		case '4':
			p_sBinaer1 += "0100";
			break;
		case '5':
			p_sBinaer1 += "0101";
			break;
		case '6':
			p_sBinaer1 += "0110";
			break;
		case '7':
			p_sBinaer1 += "0111";
			break;
		case '8':
			p_sBinaer1 += "1000";
			break;
		case '9':
			p_sBinaer1 += "1001";
			break;
		default:
			break;
		}
	}

	// Umwandlung einer ganzen Zahl in ein String : Zweite Eingabe
	p_sDecimal2 = to_string(p_iDecimal2);

	// Umwandlung des Strings in eine BCD-Zahl
	for (int i = 0; i < p_sDecimal2.length(); ++i)
	{
		switch (p_sDecimal2[i])
		{
		case '0':
			p_sBinaer2 += "0000";
			break;
		case '1':
			p_sBinaer2 += "0001";
			break;
		case '2':
			p_sBinaer2 += "0010";
			break;
		case '3':
			p_sBinaer2 += "0011";
			break;
		case '4':
			p_sBinaer2 += "0100";
			break;
		case '5':
			p_sBinaer2 += "0101";
			break;
		case '6':
			p_sBinaer2 += "0110";
			break;
		case '7':
			p_sBinaer2 += "0111";
			break;
		case '8':
			p_sBinaer2 += "1000";
			break;
		case '9':
			p_sBinaer2 += "1001";
			break;
		default:
			break;
		}
	}
}

// Diese Funktion rechnet eine BCD-Zahl in eine Dezimalzahl um
void BCD::vBinToDec()
{
	// Das letzte Ergebnis umwandeln
	for (auto it : p_vsSummation2)
	{
		int iResult = 0;

		for (int iCursor = 0; iCursor < it.length(); ++iCursor)
		{
			if (it.at(iCursor) == '1')
				iResult += pow(2, 3 - iCursor);
			else
				iResult += 0;
		}

		// Das Ergebnis wird in diesem Vector abgelegt
		p_viResult.push_back(iResult);
	}

}

/* Die BCD - Zahlen werden hier zerlegt, um die Berechnung zu erleichtern,
   und dann werden sie in den Vectoren p_vsPartition1, p_vsPartition2 gespeichert */
void BCD::vPartition()
{
	// Umwandlung einer Dezimalzahl in eine Binaerzahl
	vDecToBin();

	// Laenge von Strings ermitteln
	int iLength1 = p_sBinaer1.length();
	int iLenght2 = p_sBinaer2.length();

	// Falls das zweite String laenger ist, dann das erste mit '0' fuellen
	if (iLength1 < iLenght2)
	{
		p_sBinaer1.insert(p_sBinaer1.begin(), iLenght2 - iLength1, '0');
	}
	// Sonst, das zweite mit '0' fuellen 
	else if (iLength1 > iLenght2)
	{
		p_sBinaer2.insert(p_sBinaer2.begin(), iLength1 - iLenght2, '0');
	}

	int iLimit = p_sBinaer1.length() / 4;
	int iCursor = 0;

	string sInterim1 = "";
	string sInterim2 = "";

	// Die Binaerzahlen werden jetzt jeweils in einem Block von 4 Charakter gespeichert
	for (int i = 1; i <= iLimit; ++i)
	{
		for (iCursor; iCursor < 4 * i; ++iCursor)
		{
			sInterim1 += p_sBinaer1[iCursor];
			sInterim2 += p_sBinaer2[iCursor];

		}

		p_vsPartition1.push_back(sInterim1);
		p_vsPartition2.push_back(sInterim2);

		sInterim1 = "";
		sInterim2 = "";

	}

}

/* Die Funktion vSumme addiert zwei Binärzahlen eines Block von den Partitionen
	oder von der ersten Summation mit dem Korrektur-String, falls j = 2 ist */
void BCD::vSumme(int iCursor, int j)
{
	if (j == 1)  // 1. Summation
	{
		p_sSumme = "";

		// Ein block oder ein Element von den Partitionen addiert. Wir fangen von hinten an
		for (int i = 3; i >= 0; --i)
		{
			char cInterim1 = p_vsPartition1.at(iCursor).at(i);
			char cInterim2 = p_vsPartition2.at(iCursor).at(i);

			if (cInterim1 == '1' && cInterim2 == '1')   // falls 1 + 1
			{
				if (p_iUebertrag1 == 0)              // Ist der  bertrag 0 ? Dann ist die Summe 0 und der neue  bertrag 1
				{
					p_sSumme.insert(p_sSumme.begin(), 1, '0');
					p_sUebertrag1.insert(p_sUebertrag1.begin(), 1, '1');
					p_iUebertrag1 = 1;
				}
				else                                // Ist der  bertrag 1 ? Dann ist die Summe 1 und der  bertrag bleibt 1
				{
					p_sSumme.insert(p_sSumme.begin(), 1, '1');
					p_sUebertrag1.insert(p_sUebertrag1.begin(), 1, '1');
				}


			}
			else
			{
				/* Falls ein von beiden Charakter 1 ist und der  bertrag auch ist,
				dann ist die Summe 0 und der  bertrag bleibt 1
				*/
				if ((cInterim1 == '1' && p_iUebertrag1 == 1) || (cInterim2 == '1' && p_iUebertrag1 == 1))
				{
					p_sSumme.insert(p_sSumme.begin(), 1, '0');
					p_sUebertrag1.insert(p_sUebertrag1.begin(), 1, '1');
				}
				// Falls 0 + 0
				else if (cInterim1 == '0' && cInterim2 == '0')
				{
					if (p_iUebertrag1 == 0)
					{
						p_sSumme.insert(p_sSumme.begin(), 1, '0');
						p_sUebertrag1.insert(p_sUebertrag1.begin(), 1, '0');
					}
					else
					{
						p_sSumme.insert(p_sSumme.begin(), 1, '1');
						p_sUebertrag1.insert(p_sUebertrag1.begin(), 1, '0');
						p_iUebertrag1 = 0;
					}
				}

				// Ansonsten
				else
				{
					p_sSumme.insert(p_sSumme.begin(), 1, '1');
					p_sUebertrag1.insert(p_sUebertrag1.begin(), 1, '0');
					p_iUebertrag1 = 0;
				}
			}
		}

		// Das Ergebnis der ersten Summe in dem Vector p_vsSummation1 einf gen
		vPushFront(p_sSumme);

		//  Das Ergebnis der ersten  bertr ge in dem Vector p_vsUebertrag1 einf gen
		vPushFront(p_sUebertrag1, 3);

	}
	else   // 2. Summation. Falls wir eine Pseudotetrade oder einen Tetraden- bertrag haben : Gleiches Vorgehen wie oben
	{
		p_sSumme = "";

		for (int i = 3; i >= 0; --i)
		{
			char cInterim1 = p_vsSummation1.at(0).at(i);
			char cInterim2 = p_skorrektur.at(i);

			if (cInterim1 == '1' && cInterim2 == '1')
			{
				if (p_iUebertrag2 == 0)
				{
					p_sSumme.insert(p_sSumme.begin(), 1, '0');
					p_sUebertrag2.insert(p_sUebertrag2.begin(), 1, '1');
					p_iUebertrag2 = 1;
				}
				else
				{
					p_sSumme.insert(p_sSumme.begin(), 1, '1');
					p_sUebertrag2.insert(p_sUebertrag2.begin(), 1, '1');
				}
			}
			else
			{
				if ((cInterim1 == '1' && p_iUebertrag2 == 1) || (cInterim2 == '1' && p_iUebertrag2 == 1))
				{
					p_sSumme.insert(p_sSumme.begin(), 1, '0');
					p_sUebertrag2.insert(p_sUebertrag2.begin(), 1, '1');
				}
				else if (cInterim1 == '0' && cInterim2 == '0')
				{
					if (p_iUebertrag2 == 0)
					{
						p_sSumme.insert(p_sSumme.begin(), 1, '0');
						p_sUebertrag2.insert(p_sUebertrag2.begin(), 1, '0');
					}
					else
					{
						p_sSumme.insert(p_sSumme.begin(), 1, '1');
						p_sUebertrag2.insert(p_sUebertrag2.begin(), 1, '0');
						p_iUebertrag2 = 0;
					}
				}

				else
				{
					p_sSumme.insert(p_sSumme.begin(), 1, '1');
					p_sUebertrag2.insert(p_sUebertrag2.begin(), 1, '0');
					p_iUebertrag2 = 0;
				}
			}

		}

		// Das Ergebnis der zweiten Summe in dem Vector p_vsSummation2 einfuegen
		vPushFront(p_sSumme, 2);
		vPushFront(p_sUebertrag2, 4);

	}
}


// Die Funktion vAddition addiert zwei BCD-Zahlen
void BCD::vAddition()
{
	vPartition();

	// Da die zwei Partitionen die gleiche L nge, reicht es aus, nur die L nge von einer zu ermitteln
	int iCursor = p_vsPartition1.size() - 1;

	// Ermittlung der Laenge vom Vector p_vsPseudotetrade
	int iPseudoTetradenLaenge = p_vsPseudotetraden.size();

	// Die zwei Partitionen von hinten durchlaufen
	for (iCursor; iCursor >= 0; --iCursor)
	{
		int iVerification = 1;

		if (iCursor > 0)
		{
			// Erste Summation von einem Block
			vSumme(iCursor);

			// Falls bei der ersten Summation kein Tetraden- Uebertrag stattfindet
			if (p_iUebertrag1 == 0)
			{
				for (auto it : p_vsPseudotetraden)
				{
					// Ist die erste Summe eine Pseudotetrade?
					if (p_sSumme.compare(it) == 0)
					{
						// Die erste Summe mit 0110 addieren um diesen Fehler zu korrigieren 
						vSumme(iCursor, 2);

						// "Ja" in die erste Frage (p_vsFrage1) einfuegen
						vPushFront("Ja", 5);

						// "*" in die zweite Frage (p_vsFrage2) einfuegen
						vPushFront("*", 6);

						// Findet ein Tetraden- bertrag bei der zweiten Summation statt?
						if (p_iUebertrag2 == 1)
						{
							p_iUebertrag1 = 1;
							p_iUebertrag2 = 0;

							p_sUebertrag1 = "1";
							p_sUebertrag2 = "0";
							break;
						}
						else
						{
							p_sUebertrag1 = "0";
							p_sUebertrag2 = "0";
							break;
						}

					}

					// Ist die erste Summe keine Pseudotetrade, dann findet keine Korrektur statt
					else if (p_sSumme.compare(it) != 0 && iVerification == iPseudoTetradenLaenge)
					{
						vPushFront(p_sSumme, 2);      // Das erste Ergebnis in p_vsSummmation2 einf gen
						vPushFront("00000", 4);       // Kein  bertrag 
						vPushFront("Nein", 5);        // "Nein" in die erste Frage (p_vsFrage1) einf gen 
						vPushFront("Nein", 6);        // "*" in die zweite Frage (p_vsFrage2) einf gen

						p_sUebertrag1 = "0";
						p_sUebertrag2 = "0";

					}
					++iVerification;
				}
			}

			/* Bei der ersten Summation haben wir einen Tetraden- bertrag,
			dann muss eine Korrektur aufjedenfall stattfinden
			*/
			else
			{
				for (auto it : p_vsPseudotetraden)
				{
					// Ist die erste Summe eine Pseudotetrade?
					if (p_sSumme.compare(it) == 0)
					{
						// Die erste Summe mit 0110 addieren um diesen Fehler zu korrigieren 
						vSumme(iCursor, 2);

						// "Ja" in die erste Frage (p_vsFrage1) einf gen
						vPushFront("Ja", 5);

						// "*" in die zweite Frage (p_vsFrage2) einf gen
						vPushFront("*", 6);

						p_iUebertrag2 = 0;
						p_sUebertrag1 = "1";
						p_sUebertrag2 = "0";
						break;

						// Findet ein Tetraden- bertrag bei der zweiten Summation statt?
						/*if (p_iUebertrag2 == 1)
						{
							p_iUebertrag2 = 0;

							p_sUebertrag1 = "1";
							p_sUebertrag2 = "0";
							break;
						}
						else
						{
							p_sUebertrag1 = "1";
							p_sUebertrag2 = "0";
							break;
						}*/
					}

					/* Sind wir am Ende von p_vsPseudotetraden angelangt ohne zu finden,
					ob die erste Summe eine Pseudotetrade ist, dann m ssen wir trotzdem korriegieren
					*/
					else if (p_sSumme.compare(it) != 0 && iVerification == iPseudoTetradenLaenge)
					{
						// Die erste Summe mit 0110 addieren um diesen Fehler zu korrigieren 
						vSumme(iCursor, 2);

						// "Nein" in die erste Frage (p_vsFrage1) einf gen
						vPushFront("Nein", 5);

						// "Ja" in die zweite Frage (p_vsFrage2) einf gen
						vPushFront("Ja", 6);

						p_iUebertrag2 = 0;
						p_sUebertrag1 = "1";
						p_sUebertrag2 = "0";
					}
					++iVerification;
				}
			}
		}

		/* Das erste Element separat betrachten. Der Unterschied hier mit iCursor > 0 liegt darin,
		dass wir beim  bertrag p_iUebertrag1 = 1 oder p_iUebertrag2 = 1 "0001" in p_vsSummation1 und in p_vsSummation2,
		und auch "0000" in p_vsPartition1 und in p_vsPartition2 einf gen m ssen. Ansonsten gleiche Vorgehensweise
		*/
		else
		{
			vSumme(iCursor);

			if (p_iUebertrag1 == 0)
			{
				for (auto it : p_vsPseudotetraden)
				{
					if (p_sSumme.compare(it) == 0)
					{
						vSumme(iCursor, 2);
						vPushFront("Ja", 5);
						vPushFront("*", 6);

						if (p_iUebertrag2 == 1)
						{
							p_iUebertrag2 = 0;

							p_sUebertrag1 = "0";
							p_sUebertrag2 = "0";

							vPushFront("0001", 1);
							vPushFront("0001", 2);
							vPushFront("00001", 3);
							vPushFront("00000", 4);
							vPushFront("Nein", 5);
							vPushFront("Nein", 6);
							vPushFront("0000", 7);
							vPushFront("0000", 8);
							break;
						}
						else
						{
							p_sUebertrag1 = "0";
							p_sUebertrag2 = "0";
							break;
						}

					}
					else if (p_sSumme.compare(it) != 0 && iVerification == iPseudoTetradenLaenge)  // Keine Korrektur
					{
						this->vPushFront("00000", 4);
						this->vPushFront("Nein", 5);
						this->vPushFront("Nein", 6);
						this->vPushFront(p_sSumme, 2);

						p_iUebertrag2 = 0;
						p_sUebertrag1 = "0";
						p_sUebertrag2 = "0";

					}
					++iVerification;
				}
			}

			else
			{
				for (auto it : p_vsPseudotetraden)
				{
					if (p_sSumme.compare(it) == 0)
					{
						vSumme(iCursor, 2);
						vPushFront("Ja", 5);
						vPushFront("*", 6);

						vPushFront("0001", 1);
						vPushFront("0001", 2);
						vPushFront("00001", 3);
						vPushFront("00000", 4);
						vPushFront("Nein", 5);
						vPushFront("Nein", 6);
						vPushFront("0000", 7);
						vPushFront("0000", 8);

						p_iUebertrag1 = 0;
						p_iUebertrag2 = 0;

						p_sUebertrag1 = "0";
						p_sUebertrag2 = "0";


						break;

					}
					else if (p_sSumme.compare(it) != 0 && iVerification == iPseudoTetradenLaenge)
					{
						vPushFront("0001", 1);
						vPushFront("0001", 2);
						vPushFront("00001", 3);
						vPushFront("00000", 4);
						vPushFront("Nein", 5);
						vPushFront("Nein", 6);
						vPushFront("0000", 7);
						vPushFront("0000", 8);


						p_iUebertrag1 = 0;
						p_iUebertrag2 = 0;
						p_sUebertrag1 = "0";
						p_sUebertrag2 = "0";
					}
				}
			}
		}
	}

}

// Diese Funktion zeigt den gesamten Prozess der Addition von BCD-Zahlen an
void BCD::vAusgabe(ostream& out)
{
	out << resetiosflags(ios_base::adjustfield) << setiosflags(ios_base::right);

	out << setw(18) << p_iDecimal1 << " :  ";
	for (auto it : p_vsPartition1)
	{
		out << setw(5) << it << "  ";
	}
	out << endl;

	out << setw(18) << showpos << p_iDecimal2 << " :  ";
	for (auto it : p_vsPartition2)
	{
		out << setw(5) << it << "  ";
	}
	out << endl;

	out << setw(22) << " Betrag :  ";
	for (auto it : p_vsUebertrag1)
	{
		string sOut = "";

		for (int i = 0; i < 5; ++i)
		{
			if (it.at(i) != '0')
			{
				sOut += it.at(i);
			}
			else
			{
				sOut += " ";
			}
		}
		out << setw(5) << sOut << "  ";
	}

	out << endl << endl;

	out << setw(22) << "1. Summation :  ";
	for (auto it : p_vsSummation1)
	{
		out << setw(5) << it << "  ";
	}
	out << endl;

	out << setw(22) << "Pseudotetrade :  ";
	for (auto it : p_vsFrage1)
	{
		out << setw(5) << it << "  ";
	}
	out << endl;

	out << setw(22) << "Tetraden-Betrag :  ";
	for (auto it : p_vsFrage2)
	{
		out << setw(5) << it << "  ";
	}
	out << endl;

	out << setw(22) << "Korrektur :  ";
	for (int i = 0; i < p_vsPartition1.size(); ++i)
	{
		if (p_vsFrage1.at(i).compare("Ja") == 0 || p_vsFrage2.at(i).compare("Ja") == 0)
		{
			out << setw(5) << "+0110" << "  ";
		}
		else
		{
			out << setw(5) << "-" << "  ";
		}
	}
	out << endl;

	out << setw(22) << "Betrag :  ";
	for (auto it : p_vsUebertrag2)
	{
		string sOut = "";

		for (int i = 0; i < 5; ++i)
		{
			if (it.at(i) != '0')
			{
				sOut += it.at(i);
			}
			else
			{
				sOut += " ";
			}
		}
		out << setw(5) << sOut << "  ";
	}
	out << endl << endl;

	out << setw(22) << "2. Summation :  ";
	for (auto it : p_vsSummation2)
	{
		out << setw(5) << it << "  ";
	}

	out << endl;

	out << setw(18) << noshowpos << p_iDecimal1 + p_iDecimal2 << " :  ";

	this->vBinToDec();
	for (auto it : p_viResult)
	{
		out << setw(5) << it << "  ";
	}

	out << endl << endl << endl << endl;
}

ostream& operator<<(ostream& Out, BCD& bEingabe)
{
	bEingabe.vAusgabe(Out);
	return Out;
}
