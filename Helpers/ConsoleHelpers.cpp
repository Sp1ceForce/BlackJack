//
// Created by Ugay1 on 06.03.2022.
//

#include "ConsoleHelpers.h"


#include <stdlib.h>
#include <iostream>

void ConsoleHelpers::ClearConsole() {
#ifdef _WIN32
    system("cls");
#endif
#ifdef __linux__
    system("clear");
#endif
}
