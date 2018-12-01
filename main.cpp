#include "TEXT.h"

int main() {

	using namespace::std;

	TEXT * start = new TEXT();
	int Pos = 0;

	char schmitz[]  = { "Schmitz,Josef" };
	char mueller[]  = { "Mueller, Josi" };
	char schmitzA[] = { "Schmitz,Anna"  };
	char muellerA[] = { "Mueller, Josef"};
	char schmitzB[] = {"Schmitz,Josi"};
	char muellerB[] = {"Mueller,Anna"};
	char meier[]    = { "Meier,Josef" };
	char zacher[]   = {"Zacher,Josi"};
	char anker[] = { "Anker,Anna" };
	char eingabe[1024];

	EVKD * newElement;
	EVKD * newElementCopyCheck;
	

	start->anhaenge(schmitz);
	start->anhaenge(mueller);
	start->anhaenge(schmitzA);
	start->anhaenge(muellerA);
	start->anhaenge(schmitzB);
	start->anhaenge(muellerB);
	start->anhaenge(meier);
	start->anhaenge(zacher);
	start->anhaenge(anker);
	

	cout << "Willkommen, bitte waehlen sie einen der folgenden Programmpunkten !" << endl;;
	int wahl;
	while (1) {
		cout << "Welches Option wollen sie ausfuehren ?"<<endl;
		cout << "__________________________________"    <<endl;
		cout << "| 1| Listenobjekt erstellen     ||"    <<endl;
		cout << "| 2| Liste anzeigen             ||"    <<endl;
		cout << "| 3| Element anhaengen          ||"    <<endl;
		cout << "| 4| Element sortiert einfuegen ||"    <<endl;
		cout << "| 5| Element loeschen           ||"    <<endl;
		cout << "| 6| Liste sortieren            ||"    <<endl;
		cout << "|12| Ende !                     ||"    <<endl;
		cout << "__________________________________"    <<endl;
		cin >> wahl;
		switch (wahl){
		case 1 :
			cout << "Bitte geben sie einen Namen ein den sie einfuegen wollen"<<endl;
			cin >> eingabe;
			newElement = new EVKD(eingabe,nullptr);
			cout << "Element erstellt" <<endl;
			break;
		case 2 :	
			start->zeigeDich();
			break;
		case 3 :
			start->anhaenge(newElement->getDaten());
			cout << "Element " << newElement->getDaten() << "wurde angehaengt" << endl;
			break;
		case 4 : 
			/*
			cout << "Bite geben sie den Namen des Elementes ein" << endl;
			cin >> eingabe;
			newElement = new EVKD(eingabe,nullptr);
			*/
			start->einfuegeSortiert(newElement,start->getAnzTexte());
			cout << "Element: " << newElement->getDaten() << "eingefuegt" << endl;
			break;
		case 5 :
			cout << "Bitte geben sie die Position den Elementes ein das sie loeschen wollen" << endl;
			cin >> Pos;
			if (Pos > start->getAnzTexte() || Pos < 0 ) {
				cout << "Bitte geben sie eine gueltige Position ein" << endl;
				break;
			}
			start->decrementAnzTexte();
			newElement =  start->loesche(Pos);
			cout << "Sie haben das Element " << newElement->getAnz() << " " << newElement->getDaten() << " erfolgreich geloescht "<< endl;
			break;
		case 6 :
			start->iSort();
			break;
		case 12:
			return 1;
			break;

		default:
			break;
		}
	
	}

}