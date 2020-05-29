//
// Created by agustin on 7/5/20.
//

#ifndef TP2CLION_FILE_READER_H
#define TP2CLION_FILE_READER_H

#include <fstream>
#include <map>
#include <vector>
#include <list>
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

    /*Devuelve una lista con todos los caracteres del archivo mapa*/
    std::list<char> getResources();

    ~FileReader();

private:
    /*Agrega al mapa el trabajador y la cantidad que vienen
     * en el string @param line*/
    void addWorkerToMap(std::map<std::string, int>& workers,
                const std::string& line) const;

    /*Lanza una excepcion si el caracter @param input_char no corresponde a ninguno
     * de los caracteres definidos para cada recurso (T,H,M,C)*/
    void isValidChar(char input_char) const;
};

#endif //TP2CLION_FILE_READER_H
