//
// Created by agustin on 8/5/20.
//

#include "resource.h"
#include "storage.h"

void Wheat::sayWhatResourceYouAre() {
    std::cout << "I'm Wheat" << std::endl;
}

void Wheat::addYourselfTo(Storage *p_storage) {
    p_storage->addResource(this);
}

void Wood::sayWhatResourceYouAre() {
    std::cout << "I'm Wood" << std::endl;
}

void Wood::addYourselfTo(Storage *p_storage) {
    p_storage->addResource(this);
}

void Iron::sayWhatResourceYouAre() {
    std::cout << "I'm Iron" << std::endl;
}

void Iron::addYourselfTo(Storage *p_storage) {
    p_storage->addResource(this);
}

void Carbon::sayWhatResourceYouAre() {
    std::cout << "I'm Carbon" << std::endl;
}

void Carbon::addYourselfTo(Storage *p_storage) {
    p_storage->addResource(this);
}

Resource::~Resource() = default;
