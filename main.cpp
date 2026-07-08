#include "shell.hpp"
#include <cstring>
#include <iostream>

int main(int argc, char* argv[]){
    Shell myShell;
    myShell.run(argc, argv);
    return 0;
}