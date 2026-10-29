#pragma once
#include <iostream>
#include <fstream>

class Ticket {
private:
    char* reys;
    char* fio;
    char* punkt;
    double minutes;

    void copyStr(char*& dest, const char* src);

public:
    Ticket();
    Ticket(const char* r, const char* f, const char* p, double m);
    Ticket(const Ticket& other);
    ~Ticket();

    Ticket& operator=(const Ticket& other);

    bool read(std::ifstream& fin);
    void show() const;
    bool isSidorov() const;
};