#include <iostream>
#include <vector>
#include <string> 


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
    Taisteluvaruste(const std::string& n, int vp, int vr, int hv, int pv)
        : Objekti{ n, vp, vr }, hyokkaysvoima{ hv }, puolustusvoima{ pv } {}

    int hyokkaysvoima;
    int puolustusvoima;
};

class MuuObjekti : public Objekti {
public:
    MuuObjekti(const std::string& n, int vp, int vr, const std::string& k)
        : Objekti{ n, vp, vr }, kyky{ k } {}

    std::string kyky;
};

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
    Maastotyyppi tie, metsa, vuoristo;
    tie.nimi = "Tie";
    tie.liikkumisvaikeuskerroin = 0.5;
    tie.taisteluvaikeuskerroin = 0.2;

    metsa.nimi = "Metsä";
    metsa.liikkumisvaikeuskerroin = 1.5;
    metsa.taisteluvaikeuskerroin = 1.0;

    vuoristo.nimi = "Vuoristo";
    vuoristo.liikkumisvaikeuskerroin = 3.0;
    vuoristo.taisteluvaikeuskerroin = 2.0;

    Karttapohja kartta;
    kartta.maastokartta = { {tie, tie, tie, tie},
                           {vuoristo, vuoristo, tie, metsa},
                           {vuoristo, metsa, tie, metsa} };

    Pelihahmo hilfred;
    hilfred.nimi = "Hilfred";
    hilfred.pelitaso = 1;
    hilfred.kuntopisteet = 70;
    hilfred.maksimiKuntopisteet = 100;
    hilfred.varallisuus = 0;

    kartta.objektit[0][0].push_back(Taisteluvaruste{ "Miekka", 5, 0, 10, 2 });
    kartta.objektit[0][0].push_back(MuuObjekti{ "Sormus", 5, 0, "Valtasormus - Tekee näkymättömäksi" });
    kartta.objektit[0][0].push_back(MuuObjekti{ "Rohto", 15, 0, "Aqua Vitis - Antaa kymmenen miehen voimat" });
    kartta.objektit[0][0].push_back(Taisteluvaruste{ "Haarniska", 0, 0, 0, 12 });

    kartta.viholliset[1][0] = { Vihollinen{"Orkki", 50, 30, 75} };
    kartta.viholliset[2][1] = { Vihollinen{"Orkki", 50, 30, 75} };
    kartta.viholliset[1][2] = { Vihollinen{"Vuorenpeikko", 60, 40, 100} };

    std::cout << "Kartta:\n";
    for (const auto& row : kartta.maastokartta) {
        for (const auto& maasto : row) {
            std::cout << maasto.nimi[0] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nPelihahmo:\n";
    std::cout << "Nimi: " << hilfred.nimi << "\n";
    std::cout << "Taso: " << hilfred.pelitaso << "\n";
    std::cout << "Kuntopisteet: " << hilfred.kuntopisteet << "/" << hilfred.maksimiKuntopisteet << "\n";
    std::cout << "Varallisuus: " << hilfred.varallisuus << " kultarahaa\n";

    return 0;
}
