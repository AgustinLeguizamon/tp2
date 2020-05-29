//
// Created by agustin on 8/5/20.
//

#include "resource.h"
#include "storage.h"


void Wheat::addYourselfTo(Storage &storage) {
    storage.addResource(this);
}

void Wood::addYourselfTo(Storage &storage) {
    storage.addResource(this);
}

void Iron::addYourselfTo(Storage &storage) {
    storage.addResource(this);
}

void Carbon::addYourselfTo(Storage &storage) {
    storage.addResource(this);
}

Resource::~Resource() = default;
