#include "fach.hh"

Fach::Fach(std::string name, std::string kuerzel, unsigned int ects) {
    this->name = name;
    this->kuerzel = kuerzel;
    this->ects = ects;
    this->note = 0.0;
}

bool Fach::noteEintragen(double note) {
    if (!bestanden() && 1.0 <= note && 5.0 >= note) {
        this->note = note;
        return true;
    }
    return false;

}

// ein Fach ist bestanden, wenn eine valide Note eingetragen, und diese besser oder gleich 4.0 ist
bool Fach::bestanden() const {
    return (note != 0.0 && note <= 4.0 && note >= 1.0);
}

// gibt die Note mal ECTS zurück, wenn das Fach bestanden ist, sonst 0
double Fach::gewerteteNote() const {
    if (bestanden()) {
        return this->ects * this->note;
    }
    return 0;
};

// gibt ECTS zurück, wenn Fach bestanden ist, sonst 0
unsigned int Fach::getECTS() const {
    if (bestanden()) {
        return ects;
    }
    return 0;
};

// gibt name zurück
std::string Fach::getName() const {
    return this->name;
};

// gibt kuerzel zurück
std::string Fach::getKuerzel() const {
    return this->kuerzel;
};

// gibt eine Repräsentation der Form "KÜR (name) [ects]: note" zurück
// ects soll auch stimmen, wenn nicht bestanden!

// Was soll bedeuten, dass die ects auch stimmen? Dass sie noch 0 sind? Wenn nicht, dann wieso machen wir, dass getECTS() 0 rausgibt???
// Wir machen mit 0 weiter, die Aufgabenstellung sollte präziser sein imo
std::string Fach::toString() const {
    std::string output;
    if (bestanden()) {
        output += getKuerzel() + " (" + getName() + ") [" + std::to_string(getECTS()) + "]: " + std::to_string(note);
    } else {
        output += getKuerzel() + " (" + getName() + ") [" + std::to_string(getECTS()) + "]: Nicht bestanden";
    }
    return output;
};