//
// Created by agustin on 13/5/20.
//

#ifndef TP2CLION_PRINTER_H
#define TP2CLION_PRINTER_H


#include "storage.h"
#include "counter.h"

class Printer {
private:
    Storage &storage;
    Counter &profit_counter;

public:
    Printer(Storage &storage, Counter &profit_counter);

    void showResults() const;
};


#endif //TP2CLION_PRINTER_H
