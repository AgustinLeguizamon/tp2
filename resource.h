//
// Created by agustin on 8/5/20.
//

#ifndef TP2CLION_RESOURCE_H
#define TP2CLION_RESOURCE_H

#include <iostream>
#include <map>
#include <queue>

class Storage;

class Resource {
    public:
        virtual void addYourselfTo(Storage *p_storage) = 0;
        virtual ~Resource();
};

class Wheat: public Resource {
    public:
        void addYourselfTo(Storage *p_storage) override;
};

class Wood : public Resource {
    public:
        void addYourselfTo(Storage *p_storage) override;
};

class Iron: public Resource {
    public:
        void addYourselfTo(Storage *p_storage) override;
};

class Carbon : public Resource {
    public:
        void addYourselfTo(Storage *p_storage) override;
};


#endif //TP2CLION_RESOURCE_H
