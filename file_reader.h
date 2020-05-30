//
// Created by agustin on 7/5/20.
//

#ifndef TP2CLION_FILE_READER_H
#define TP2CLION_FILE_READER_H

#include <fstream>
#include <map>
//cpplint
#include <string>

class FailedToOpenFileException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Failed to open";
    }
};

class InvalidMapCharacterException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Map has an invalid character";
    }
};

class InvalidWorkerSyntaxException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Workers file invalid syntax";
    }
};

class FileReader{
private:
    std::ifstream fs_workers;
    std::ifstream fs_resources;

public:
    /*Abre los dos archivos de nombre @param workers y @param map */
    explicit FileReader(const std::string &workers, const std::string &map);

    /*Devuelve un mapa con key: nombre de los trabajadores y value: cantidad*/
    std::map<std::string, int> getMapOfWorkers();

    /*Devuelve el siguiente caracter del mapa de recursos*/
    char getResource();

    ~FileReader();

private:
    /*Agrega al mapa el trabajador y la cantidad que vienen
     * en el string @param line*/
    void addWorkerToMap(std::map<std::string, int>& workers,
                const std::string& line) const;
};

#endif //TP2CLION_FILE_READER_H
