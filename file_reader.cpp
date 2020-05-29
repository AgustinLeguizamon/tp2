//
// Created by agustin on 7/5/20.
//

#include "file_reader.h"
//cpplint
#include <map>
#include <string>
#include <list>

#define VALID_RESOURCE_CHARACTERS "TMHC"

FileReader::FileReader(const std::string &workers, const std::string &map) {
    this->fs_workers.open(workers);
    this->fs_resources.open(map);
}

void FileReader::changeReadingFile(const std::string &file_name) {
    fs_workers.close();
    fs_workers.clear();
    this->fs_resources.open(file_name);
}

std::map<std::string, int> FileReader::getMapOfWorkers(){
    std::map<std::string, int> workers;
    std::string line;

    if (!fs_workers.is_open()){
        throw FailedToOpenFileException();
    }

    while (getline(this->fs_workers, line)){
        this->addWorkerToMap(workers, line);
    }

    return workers;
}

void FileReader::addWorkerToMap(std::map<std::string, int>& workers,
        const std::string& line) const {
    unsigned long pos = line.find_first_of('=', 0);
    if (pos == std::string::npos){
        throw InvalidWorkerSyntaxException();
    }

    std::string worker = line.substr(0,pos);
    std::string s_qty = line.substr(pos+1,line.size());
    int qty = std::stoi(s_qty, nullptr,10);

    workers.insert({worker, qty});
}


std::list<char> FileReader::getResources() {
    std::list<char> resources;

    if (!fs_resources.is_open()){
        throw FailedToOpenFileException();
    }

    char input_char = fs_resources.get();
    while (input_char != EOF){
        if (input_char != '\n'){
            //checkea si es un caracter valido
            this->isValidChar(input_char);
            resources.push_back(input_char);
        }
        input_char = fs_resources.get();
    }

    return resources;
}

void FileReader::isValidChar(const char input_char) const {
    std::string valid_chars = VALID_RESOURCE_CHARACTERS;
    if (valid_chars.find(input_char) == std::string::npos){
        throw InvalidMapCharacterException();
    }
}

FileReader::~FileReader(){
    fs_resources.close();
    fs_workers.close();
}
