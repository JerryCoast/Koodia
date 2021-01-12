#include <iostream>
#include "kirjasto.h"
#include <vector>
#include <random>
#include <string>
using namespace std;




int main() {
	string varatutHuoneet = "Varaamasi huoneiden numerot:";
	int koko;
	int oidenMaara;
	double lasku = 0.0;
	vector<Hotellihuone> hotelli;
	int x = arvoHuoneidenMaara(); //muuttuja on hotellihuoneiden m‰‰r‰ v‰lill‰ 40-80
	for (int i = 0; i < x; i++) { //hotelliin lis‰t‰‰n huoneet
		if (i < x / 2) {

			hotelli.push_back(uusiHuone(i + 1, 1, 100)); //1hh
		}
		else {
			hotelli.push_back(uusiHuone(i + 1, 2, 150)); //2hh
		}
	}
	
	//t‰st‰ alkaa k‰ytt‰j‰lle n‰kyv‰ osa
	cout << "Tervetuloa vektorihotellin varausjarjestelmaan!\n";
	cout << "\nHotellin koko: " << hotelli.size() << " huonetta.\n"; //hotellihuoneiden kokonaism‰‰r‰
	cout << "-----------------------------------------------\n";

	while (true) { //looppi joka pyˆrii siihen saakka kunnes k‰ytt‰j‰ p‰‰tt‰‰ poistua ohjelmasta
		cout << "Komennot:\t 1= Varaa yhden hengen huone.\t 2= Kahden hengen huone.\t 0 = poistu jarjestelmasta  " <<"\n";
		koko = syotteenTarkastus(3);
		if (koko == 0) {
			break;
		}
		int huone = arvoVarattavaHuone(hotelli, koko);
		if (huone != 0) {	//jos edellisess‰ muuttujassa oleva arpa palauttaa 0 arvon huonetta ei varata mutta looppi ei katkea.
			hotelli[huone - 1].onkoVapaa = false;	 //muuttaa edell‰ saadun huoneen statuksen varatuksi
			varatutHuoneet.append(" "); varatutHuoneet.append(to_string(huone)); //varatut huoneet ker‰t‰‰n listalle
			cout << "Kuinka monta yota? ";
			oidenMaara = syotteenTarkastus(30);

			if (koko == 1) { //arvotaan alennuksen m‰‰r‰ ja lis‰t‰‰n kunkin varauksen lopullinen hinta laskuun
				lasku += 100.0 * oidenMaara * alennusArpa();
			}
			else if (koko == 2) {
				lasku += 150.0 * oidenMaara * alennusArpa();
			}
		}
		else {
			continue; //mik‰li haluamalla huonekoolla ei ole varattuja huoneita, t‰m‰ jatkaa ohjelmaa mik‰li k‰ytt‰j‰ haluaa varata eri kokoisen huoneen
		}

	}
	cout << "\t" << varatutHuoneet << "\n "; //varattujen huoneiden numerot k‰ytt‰j‰n n‰ht‰ville
	cout << "\tYhteensa: " << lasku << " euroa\n "; //laskun kokonaissumma
	cout << "\tKiitos asioinnistasi, mukavaa paivanjatkoa!\n";



	return 0;
} 