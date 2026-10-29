#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <cstring>

void Ticket::copyStr(char*& dest, const char* src) {
    if (!src || !src[0]) {
        dest = new char[1];
        dest[0] = '\0';
        return;
    }
    int len = (int)strlen(src);
    dest = new char[len + 1];
    strcpy(dest, src);
}

Ticket::Ticket() {
    minutes = 0;
    reys = nullptr;
    fio = nullptr;
    punkt = nullptr;
    copyStr(reys, "");
    copyStr(fio, "");
    copyStr(punkt, "");
}

Ticket::Ticket(const char* r, const char* f, const char* p, double m) {
    minutes = m;
    reys = nullptr;
    fio = nullptr;
    punkt = nullptr;
    copyStr(reys, r);
    copyStr(fio, f);
    copyStr(punkt, p);
}

Ticket::Ticket(const Ticket& other) {
    minutes = other.minutes;
    reys = nullptr;
    fio = nullptr;
    punkt = nullptr;
    copyStr(reys, other.reys);
    copyStr(fio, other.fio);
    copyStr(punkt, other.punkt);
}

Ticket::~Ticket() {
    delete[] reys;
    delete[] fio;
    delete[] punkt;
}

Ticket& Ticket::operator=(const Ticket& other) {
    if (this != &other) {
        delete[] reys;
        delete[] fio;
        delete[] punkt;

        minutes = other.minutes;
        reys = nullptr;
        fio = nullptr;
        punkt = nullptr;
        copyStr(reys, other.reys);
        copyStr(fio, other.fio);
        copyStr(punkt, other.punkt);
    }
    return *this;
}

bool Ticket::read(std::ifstream& fin) {
    char rBuf[50], fBuf[100], iBuf[20], pBuf[100];
    double m;

    if (!(fin >> rBuf >> fBuf >> iBuf >> pBuf >> m)) return false;

    char fullFio[150];
    strcpy(fullFio, fBuf);
    strcat(fullFio, " ");
    strcat(fullFio, iBuf);

    minutes = m;
    copyStr(reys, rBuf);
    copyStr(fio, fullFio);
    copyStr(punkt, pBuf);
    return true;
}

void Ticket::show() const {
    std::cout << "Рейс: " << reys 
              << "   Пассажир: " << fio 
              << "   Пункт: " << punkt 
              << "   Время: " << minutes << " мин.\n";
}

bool Ticket::isSidorov() const {
    return strncmp(fio, "Сидоров", 7) == 0;
}