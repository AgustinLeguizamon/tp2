//
// Created by agustin on 8/5/20.
//

#include "resource.h"
#include "storage.h"


void Wheat::addYourselfTo(Storage *p_storage) {
    p_storage->addResource(this);
}

void Wood::addYourselfTo(Storage *p_storage) {
    p_storage->addResource(this);
}

void Iron::addYourselfTo(Storage *p_storage) {
    p_storage->addResource(this);
}

void Carbon::addYourselfTo(Storage *p_storage) {
    p_storage->addResource(this);
}

Resource::~Resource() = default;
