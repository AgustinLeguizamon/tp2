//
// Created by agustin on 29/5/20.
//

#ifndef TP2CLION_GAME_H
#define TP2CLION_GAME_H


#include "file_reader.h"

//cpplint
#include <string>
#include <map>
#include <list>

class Game {
private:
    FileReader file_reader;
    std::map<std::string, int> workers;
    std::list<char> resources;

public:
    explicit Game(const char* argv[]);

    void operator()();
};


#endif //TP2CLION_GAME_H
