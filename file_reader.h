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
        std::ifstream fs;
    public:
        explicit FileReader(const std::string& file_name);

        void changeReadingFile(const std::string& file_name);

        std::map<std::string, int> getMapOfWorkers();

        std::list<char> getResources();

        ~FileReader();

    private:
        void addWorkerToMap(std::map<std::string, int>& workers,
                    const std::string& line) const;

        void isValidChar(char input_char) const;
};

#endif //TP2CLION_FILE_READER_H
