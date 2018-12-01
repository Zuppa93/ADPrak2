#pragma once

#include "EVKD.h"

EVKD::EVKD(char * LPSZDaten, EVKD * N) {
	
	this->AnzChars = 0;
	while (LPSZDaten[AnzChars] != '\0') {
		AnzChars++;
	}
	AnzChars--; //(Falls Stringendezeichen nicht als Element des Arrays zählt)
	for (int i = 0; i < AnzChars;i++) {
		this->Daten[i] = &LPSZDaten[i];
	}
	this->Next = N;
}
EVKD::~EVKD() {
	//delete this;
}

//EVKD::EVKD(EVKD &C):Anz(C.Anz),Daten(C.Daten),Next(C.Next) {}

EVKD::EVKD(EVKD &C) :EVKD(*C.Daten, C.Next) {}

int    EVKD::getAnz  ()      { return  this->AnzChars;   }
char * EVKD::getDaten()      { return *this->Daten; }
EVKD * EVKD::getNext ()      { return  this->Next;  }
/*
char * EVKD::getChar(int pos) {
	return this->Daten[pos];
}
*/

void EVKD::setNext(EVKD * N) { 
	/*
	Anscheinend doch nicht so einfach
	*/
	this->Next = N;
}

bool EVKD::operator==(EVKD * Rechts) {
	int help = 0;
	if (this->AnzChars != Rechts->AnzChars) {
		return false;
	}
	help = strcmp(this->getDaten(),Rechts->getDaten());
	if (help == 0){
		return true;
	}
	return false;
}

bool EVKD::operator>(EVKD * Rechts) {
	int help = 0;
	help = strcmp(this->getDaten(), Rechts->getDaten());
	if (help > 0 ) {
		return true;
	}
	return false;
}
