#pragma once

#include <vector>
#include <iostream>

struct Hotellihuone { //struct joka simuloi hotellihuonetta. muuttujat ovat huoneen numero, hinta, koko ja boolean- arvo onko huone vapaa
	int huoneenNro;
	int hloMaara;
	int hinta;
	bool onkoVapaa;
};

Hotellihuone uusiHuone(int, int, int); // palauttaa uuden hotellihuoneen

int arvoHuoneidenMaara(); //funktio joka arpoo n�enn�issatunaisen numeron v�lilt� 40-80

int arvoVarattavaHuone(std::vector <Hotellihuone> , int ); //arpoo vapaana olevan huoneen hotellista

double alennusArpa(); //arpoo alennuksen varaukselle 

int syotteenTarkastus(int); //tarkastaa ettei k�ytt�j� sy�ta muuta kuin haluttuja numeroita ja palauttaa sallituissa rajoissa olevan numeron p��ohjelmaan.
