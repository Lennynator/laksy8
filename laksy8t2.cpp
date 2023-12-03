#include <iostream>
#include <string>
#include <vector>

class Maastotyyppi {
public:
    std::string nimi;
    double liikkumisvaikeuskerroin;
    double taisteluvaikeuskerroin;
};

class Objekti {
public:
    std::string nimi;
    int vaikutusKuntopisteisiin;
    int vaikutusRahaan;
};

class Taisteluvaruste : public Objekti {
public:
    int hyokkaysvoima;
    int puolustusvoima;
};

class MuuObjekti : public Objekti {};

class Vihollinen {
public:
    std::string tyyppi;
    int hyokkaysvoima;
    int puolustusvoima;
    int kuntopisteet;
};

class Pelihahmo {
public:
    std::string nimi;
    int pelitaso;
    int kuntopisteet;
    int maksimiKuntopisteet;
    int varallisuus;
};

class Karttapohja {
public:
    std::vector<std::vector<Maastotyyppi>> maastokartta;
    std::vector<std::vector<std::vector<Objekti>>> objektit;
    std::vector<std::vector<Vihollinen>> viholliset;
};

int main() {

    Pelihahmo pelaaja;
    pelaaja.nimi = "Pelaaja1";
    pelaaja.pelitaso = 1;
    pelaaja.kuntopisteet = 100;
    pelaaja.maksimiKuntopisteet = 150;
    pelaaja.varallisuus = 50;

    Maastotyyppi tie, heinikko, metsa, suo, vuoristo, vesi;
    tie.nimi = "Kuninkaatie";
    tie.liikkumisvaikeuskerroin = 0.5;
    tie.taisteluvaikeuskerroin = 0.2;


    Karttapohja kartta;

    Objekti kultaharkko;
    kultaharkko.nimi = "Kultaharkko";
    kultaharkko.vaikutusKuntopisteisiin = 0;
    kultaharkko.vaikutusRahaan = 40;


    Taisteluvaruste kirves;
    kirves.nimi = "Kirves";
    kirves.hyokkaysvoima = 10;
    kirves.puolustusvoima = 2;
    kirves.vaikutusKuntopisteisiin = 0;
    kirves.vaikutusRahaan = 0;


    MuuObjekti sammakonreisirohto;
    sammakonreisirohto.nimi = "Sammakonreisirohto";
    sammakonreisirohto.vaikutusKuntopisteisiin = 15;
    sammakonreisirohto.vaikutusRahaan = 0;


    Vihollinen orkki;
    orkki.tyyppi = "Orkki";
    orkki.hyokkaysvoima = 50;
    orkki.puolustusvoima = 30;
    orkki.kuntopisteet = 75;


    return 0;
}