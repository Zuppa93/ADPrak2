#pragma once
#include "EVKD.h"
#include <iostream>

class TEXT {
	private:
		EVKD * Start[99];
		int AnzTexte;

	public:
		TEXT();
		//TEXT(EVKD *N);
		void anhaenge(char * ln);
		//int strLen(char * text);
		void einfuegeSortiert(EVKD * ln,int MAX);
		EVKD * loesche(int Pos);
		void zeigeDich();
		void iSort();

		//////////////////////
		// Custom Functions //
		//////////////////////

		int getAnzTexte();
		void decrementAnzTexte();
};