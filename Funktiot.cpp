#include "kirjasto.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;


int arvoHuoneidenMaara() {	//funktio k‰ytt‰‰ hyˆdyksi valmista koodiblokkia(omilla raja-arvoilla) joka tuottaa enemm‰n satunnaiselta vaikuttavia lukuja
	std::random_device rd;		
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(40, 80);
	distrib(gen);
	
	int maara = distrib(gen); //jos arvottu numero on parillinen, se palautetaan. parittomasta v‰hennet‰‰n 1
	if (maara % 2 == 0) {
		return maara;
	}
	else {
		return maara - 1;
	}
	
}

int arvoVarattavaHuone(std::vector<Hotellihuone> hotelli, int x) { //ottaa parametrina hotellin ja joko 1 tai 2 hengen huoneen ja palauttaa vapaana olevan huoneen numeron
	int a = hotelli.size() / 2; //a ja b apumuuttujia selkeyden vuoksi
	int b = hotelli.size();


	if (x == 1) {
		int vapaanHuoneenNro = 0;
		int i = 0;
		while (i < a) {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> distrib(hotelli[0].huoneenNro, hotelli[a - 1].huoneenNro);
			distrib(gen);
			int huone = distrib(gen);

			if (hotelli[huone - 1].onkoVapaa) {
				vapaanHuoneenNro = huone;
				break;
			}
			i++;
		}
		if (vapaanHuoneenNro == 0) {
			cout << "Valitettavasti yhden hengen huoneita ei ole enaa vapaana\n";
			return 0;
		}
		else {
			
			return vapaanHuoneenNro;
		}
		
	}
	else if (x == 2) {
		int vapaanHuoneenNro = 0;
		int i = a;
		while (i < b) {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> distrib(hotelli[a].huoneenNro, hotelli[b - 1].huoneenNro);
			distrib(gen);
			int huone = distrib(gen);

			if (hotelli[huone - 1].onkoVapaa) {
				vapaanHuoneenNro = huone;
				break;
			}
			i++;
		}
		if (vapaanHuoneenNro == 0) {
			cout << "Valitettavasti kahden hengen huoneita ei ole enaa vapaana\n";
			return 0;
		}
		else {
			
			return vapaanHuoneenNro;
		}
	}

	
}

double alennusArpa() { //jokaisen yksitt‰isen huonevarauksen j‰lkeen t‰m‰ arpoo k‰ytt‰j‰lle alennuksen v‰lilt‰ 0-20%
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, 2);
	distrib(gen);
	int alennus = distrib(gen);
	if (alennus == 0) {
		return 1.0;
	}
	else if (alennus == 1) {
		return 0.9;
	}
	else {
		return 0.8;
	}
}

Hotellihuone uusiHuone(int nro, int hlo, int hinta) { //t‰ll‰ luodaan uusia huoneita p‰‰ohjelmassa vektoriin(hotelliin)
	Hotellihuone huone;
	huone.huoneenNro = nro;
	huone.hloMaara = hlo;
	if (hlo < 2) {
		huone.hinta = 100;
	}
	else {
		huone.hinta = 150;
	}
	huone.onkoVapaa = true;

	return huone;
}

int syotteenTarkastus(int raja) { //parametrina annettu raja m‰‰ritt‰‰ kummalla tavalla syˆte tarkastetaan
	bool virhe;
	int luku;

	if (raja < 4) {
		do {
			virhe = false;
			cin >> luku;
			if (cin.fail()) {
				cout << "Tarkista etta syottamasi luku oli oikein\nKomennot:\t 1= Varaa yhden hengen huone.\t 2= Kahden hengen huone.\t 0 = poistu jarjestelmasta\n";
				virhe = true;
				cin.clear();
				cin.ignore(100, '\n');
			}
			else if (luku > 2 || luku < 0) {
					cout << "Haluamaasi huonekokoa ei ole valitettavasti tarjolla\n";
					virhe = true;
					cin.clear();
					cin.ignore(100, '\n');
			}
		} while (virhe);
		return luku;
	}
	else {
		do {
			virhe = false;
			cin >> luku;
			if (cin.fail()) {
				cout << "Tarkista etta syottamasi luku oli oikein\nKomennot:\t 1= Varaa yhden hengen huone.\t 2= Kahden hengen huone.\t 0 = poistu jarjestelmasta\n";
				virhe = true;
				cin.clear();
				cin.ignore(100, '\n');
			}
			else if (luku > 30 || luku < 1) {
					cout << "Voit varata yhdella varauskerralla 1-30 yota\n";
					virhe = true;
					cin.clear();
					cin.ignore(100, '\n');
			}
		} while (virhe);
		return luku;
	}
	
}

