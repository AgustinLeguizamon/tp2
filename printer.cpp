//
// Created by agustin on 13/5/20.
//

#include "printer.h"

Printer::Printer(Storage &storage, Counter &profit_counter) :
    storage(storage),
    profit_counter(profit_counter)
    {}

void Printer::showResults() {
    unsigned int remaining_wheat = storage.freeRemainingResource
            (storage.WHEAT);
    unsigned int remaining_wood = storage.freeRemainingResource
            (storage.WOOD);
    unsigned int remaining_iron = storage.freeRemainingResource
            (storage.IRON);
    unsigned int remaining_carbon = storage.freeRemainingResource
            (storage.CARBON);

    std::cout << "Recursos restantes:" << std::endl;
    std::cout << "  - Trigo: " << remaining_wheat << std::endl;
    std::cout << "  - Madera: " << remaining_wood << std::endl;
    std::cout << "  - Carbon: " << remaining_carbon << std::endl;
    std::cout << "  - Hierro: " << remaining_iron << std::endl;
    std::cout << std::endl;
    std::cout <<"Puntos de Beneficio acumulados: " <<
        profit_counter.getPoints() << std::endl;
}
