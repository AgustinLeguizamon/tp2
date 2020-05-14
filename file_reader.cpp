//
// Created by agustin on 7/5/20.
//

#include <iostream>
#include "file_reader.h"
//cpplint
#include <map>
#include <string>
#include <list>

FileReader::FileReader(const std::string& file_name) {
    this->fs.open(file_name);
}

void FileReader::changeReadingFile(const std::string &file_name) {
    this->fs.close();
    this->fs.open(file_name);
}

std::map<std::string, int> FileReader::getMapOfWorkers() {
    std::map<std::string, int> workers;

    std::string line;

    while (getline(this->fs, line)){
        this->addWorkerToMap(workers, line);
    }

    return workers;
}

void FileReader::addWorkerToMap(std::map<std::string, int>& workers,
        const std::string& line) {
    unsigned long pos;
    std::string worker;
    int qty;

    pos = line.find_first_of('=', 0);
    worker = line.substr(0,pos);
    //resto ascci 0 para llevarlo al valor numerico correspondiente
    qty = (int) line[line.size()-1] - '0';

    workers.insert({worker, qty});
}

std::map<char, int> FileReader::getMapOfResources(){
    std::map<char, int> resources;

    char input_char = fs.get();

    while (input_char != -1){
        this->addResourceToMap(resources, input_char);
        input_char = fs.get();
    }

    return resources;
}

void FileReader::addResourceToMap(std::map<char, int>& resources,
        char input_char) {
    resources[input_char] = resources[input_char] + 1;
}

std::list<char> FileReader::getResources() {
    std::list<char> resources;

    char input_char = fs.get();
    while (input_char != -1){
        if (input_char != '\n'){
            resources.push_back(input_char);
        }
        input_char = fs.get();
    }

    return resources;
}



