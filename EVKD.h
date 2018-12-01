#pragma once
#include "String.h"

class EVKD {

private:
	int AnzChars;
	char * Daten[99];
	EVKD * Next;
public:
	EVKD(char * LPSZDaten, EVKD * N);
	EVKD(EVKD&);
	~EVKD();

	int    getAnz();
	char * getDaten();
	EVKD * getNext();
	/*
	char * getChar(int Pos);
	*/
	//void setAnz  (int    Anz);
	//void setDaten(char * Daten);
	void setNext (EVKD * Next);

	
	bool operator==(EVKD * Rechts);
	bool operator> (EVKD * Rechts);
	
};