// Made by Sp1ceForce

#include "ConsoleHelpers.h"
#include <stdlib.h>


void ConsoleHelpers::ClearConsole() {
#ifdef _WIN32
    system("cls");
#endif
#ifdef __linux__
    system("clear");
#endif
}
