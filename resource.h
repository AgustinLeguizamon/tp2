//
// Created by agustin on 8/5/20.
//

#ifndef TP2CLION_RESOURCE_H
#define TP2CLION_RESOURCE_H


class Storage;
class Resource {
    public:
        /*DoubleDispatch: el recurso se agrega a si mismo al
         * inventario de @param storage*/
        virtual void addYourselfTo(Storage &storage) = 0;
        virtual ~Resource();
};

class Wheat: public Resource {
    public:
        void addYourselfTo(Storage &storage) override;
};

class Wood : public Resource {
    public:
        void addYourselfTo(Storage &storage) override;
};

class Iron: public Resource {
    public:
        void addYourselfTo(Storage &storage) override;
};

class Carbon : public Resource {
    public:
        void addYourselfTo(Storage &storage) override;
};


#endif //TP2CLION_RESOURCE_H
