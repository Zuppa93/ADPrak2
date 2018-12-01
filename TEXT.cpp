#include "TEXT.h"

//Done
TEXT::TEXT():AnzTexte(0) {
	this->Start[0] = nullptr;
}
//Done
void TEXT::anhaenge(char * ln) {
	int help = this->AnzTexte;
	//int length = strLen(ln);
	
	EVKD * textObjekt = new EVKD(ln,nullptr);
	// Möglicher Fehler, weil u.U. das Objekt nach return Befehl gelöscht wird
	this->Start[help] = textObjekt;
	// Pointer des letzten Objektes auf neues Objekt biegen
	if (help == 0) {
		this->AnzTexte++;
	}else {
		this->Start[help - 1]->setNext(textObjekt);
		// Möglich dass wir hier nur Call by Value haben (ggfs. setAnzTexte(int Anz) erstellen)
		this->AnzTexte++;
	}

	return;
	
}
// Done
void TEXT::iSort() {
	int counter = 0;
	int help = this->AnzTexte;
	EVKD * hilfe;
	for (int i = 1; i < help;i++) {
		if (this->Start[i-1]->getDaten()[0] > this->Start[i]->getDaten()[0]) {
			for (int k = i; k > 0;k--) {
				if (this->Start[k-1]->getDaten()[0] > this->Start[k]->getDaten()[0]  ) {
					hilfe = new EVKD(this->Start[k-1]->getDaten(), this->Start[k-1]->getNext());
					this->Start[k-1] = this->Start[k];
					this->Start[k] = hilfe;
				}
			}
			
		}
	}



}
// Done
void TEXT::einfuegeSortiert(EVKD * ln, int MAX) {
	// Sortiert nur nach dem ersten Buchstaben und ignoriert Gleichheit der Chars
	// Neue Elemente werden immer nach dem Element mit dem gleichen Char eingetragen
	this->anhaenge(ln->getDaten());
	this->iSort();
	return;
}

EVKD * TEXT::loesche(int pos) {
	EVKD * deletedElement = new EVKD(*this->Start[pos]);
	this->Start[pos]->~EVKD();
	for (int i = pos; i < this->AnzTexte;i++) {
		this->Start[i] = this->Start[i + 1];
	}
	return deletedElement;
}
// Done
void TEXT::zeigeDich() {

	using namespace::std;

	cout << "ICh bin eine Testausgabe"<< endl;
	cout << "Nun zu dem spannendem Teil der Ausgabe" << endl;
	cout << "Anzahl der Einträge: " << this->AnzTexte << endl;
	for (int i = 0; i < this->AnzTexte;i++) {
		cout << "|| Pos: " << i << " || Pointer: " << this->Start[i] <<"|| Next: "<< this->Start[i]->getNext() <<" || Text: "<< this->Start[i]->getDaten() << endl;
	}
	return;

}

/////////////////////
//Custom Functions //
/////////////////////

int TEXT::getAnzTexte() {
	return this->AnzTexte;
}

void TEXT::decrementAnzTexte() {
	this->AnzTexte--;
}
