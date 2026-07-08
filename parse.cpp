#include "parse.hpp"
#include "param.hpp"
#include <cstring>
#include <iostream>

void Parse::tokenize(char* input, Param& params) {
    char* token = strtok(input, " \t\n"); // tokenizes input
    
    while (token != nullptr) {
        if (*token == '<') { // checks the char literal of the char pointer
            if (token != nullptr) {
                params.setInputRedirect(token + 1);
            }
        }
        else if (*token == '>') { // checks the char literal of the char pointer
            if (token != nullptr) {
                params.setOutputRedirect(token + 1);
            }
        }
        else if (strcmp(token, "&") == 0) {
            params.setBackground(true);
        }
        else {
            params.addArgument(token);
        }
        
        token = strtok(nullptr, " \t\n");
    }
}