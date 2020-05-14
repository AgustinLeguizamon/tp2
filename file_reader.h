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

class FileReader{
    private:
        std::ifstream fs;
    public:
        explicit FileReader(const std::string& file_name);

        void changeReadingFile(const std::string& file_name);

        std::map<std::string, int> getMapOfWorkers();

        std::map<char, int> getMapOfResources();

        std::list<char> getResources();

private:
        void addWorkerToMap(std::map<std::string, int>& workers,
                const std::string& line);

        void addResourceToMap(std::map<char, int>& resources,
                char input_char);
};

#endif //TP2CLION_FILE_READER_H
