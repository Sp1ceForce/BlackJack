#include <iostream>
#include "Controller.h"
int main() {
    Controller* GameController = new Controller();
    GameController->GameLoop();
    return 0;
}
