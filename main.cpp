#include "game.h"

int main(int argc, char const *argv[]){
    try{
        Game game(argv);
        game();
    } catch(std::exception &e){
        printf("%s", e.what());
        return 1;
    } catch(...){
        printf("Unknow error");
        return 1;
    }

    return 0;
}
