//
// Created by agustin on 29/5/20.
//

#ifndef TP2CLION_GAME_H
#define TP2CLION_GAME_H


#include "file_reader.h"

//cpplint
#include <string>
#include <map>

class Game {
private:
    FileReader file_reader;
    std::map<std::string, int> workers;

public:
    explicit Game(const char* argv[]);

    /*Crea todas las clases del programa y lanza los hilos*/
    void operator()();
};


#endif //TP2CLION_GAME_H
