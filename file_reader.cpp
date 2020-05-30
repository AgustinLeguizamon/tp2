//
// Created by agustin on 7/5/20.
//

#include "file_reader.h"
//cpplint
#include <map>
#include <string>


FileReader::FileReader(const std::string &workers, const std::string &map) {
    this->fs_workers.open(workers);
    this->fs_resources.open(map);
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

char FileReader::getResource(){
    char input_char = fs_resources.get();
    while (input_char == '\n'){
        input_char = fs_resources.get();
    }

    return input_char;
}

FileReader::~FileReader(){
    fs_resources.close();
    fs_workers.close();
}
