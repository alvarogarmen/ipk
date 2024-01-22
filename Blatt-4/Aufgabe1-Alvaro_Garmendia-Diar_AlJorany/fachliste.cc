#include "fachliste.hh"
#include <iostream>

FachListe::FachListe() {
    this->_faecher = std::vector<Fach>();
}

FachListe::FachListe(std::vector<Fach> faecher) {
    for (auto fach: faecher) {
        this->_faecher.push_back(fach);
    }
}; // trägt die Fächer in faecher direkt in _faecher ein.
void FachListe::addFach(Fach fach) {
    this->_faecher.push_back(fach);
}; // fügt fach zu _faecher hinzu
unsigned int FachListe::summeECTS() {
    unsigned int summe = 0;
    for (auto fach: this->_faecher) {
        summe += fach.getECTS();
    }
    return summe;
}; // summiert die ECTS aller bestandenen Fächer
double FachListe::durchschnitt() {
    double schnitt = 0;
    for (auto fach: _faecher) {
        if (fach.gewerteteNote() == 0) {
            continue;
        }
        schnitt += fach.gewerteteNote();
    }
    schnitt = schnitt / summeECTS();
    return schnitt;
}; // nach ECTS gewertete Summe aller bestandenen Fächer
std::vector<std::string> FachListe::list() {
    std::vector<std::string> list;
    for (auto fach: _faecher) {
        list.push_back(fach.toString());
    }
    return list;
}; // gibt vector von Zustandsbeschreibungen aller Fächer zurück
bool FachListe::noteEintragen(std::string kuerzel, double note) {
    for (size_t i = 0; i < _faecher.size(); i++) {
        if (_faecher[i].getKuerzel() == kuerzel) {
            _faecher[i].noteEintragen(note);
            return true;
        }
    }
    return false;
}; // trägt für (das erste) Fach mit Kürzel kuerzel die Note note ein; gibt genau dann true zurück, wenn das funktioniert hat
