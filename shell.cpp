#include "shell.hpp"
#include "parse.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <cstring>
#include <cstdlib>

Shell::Shell(){
    signal(SIGCHLD, SIG_IGN);
}

// checks if '&' is present, if not then run normally
void Shell::executeCommand(){
    if (param.getBackground()){
        executeBackground();
    } else{
        executeForeground();
    }
}

// process runs in front of you
void Shell::executeForeground(){
    pid_t pid = fork();

    if (pid == 0){
        setupRedirection();
        char** args = param.getArguments();
        execvp(args[0], args);

        perror("execvp failed");
        exit(1);

    } else if (pid > 0){
        int status;
        waitpid(pid, &status, 0);
    } else {
        perror("fork failed");
    }
}

// process runs in the background
void Shell::executeBackground(){
    pid_t pid = fork();
    if (pid == 0){
        setupRedirection(); 
        char** args = param.getArguments();
        execvp(args[0], args);

        perror("execvp failed");
        exit(1);
    } else if (pid > 0){
        std::cout << "Background Process started " << pid << std::endl;
    } else {
        perror("fork failed");
    }
}

// checks for zombies
void Shell::checkBackgroundProcesses(){
    pid_t pid;
    int status;

    while((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        std::cout << "[" << pid << "]" << std::endl;
    }
}

// checksk for input or output redirection
void Shell::setupRedirection(){
    char* inputRedirect = param.getInputRedirect();
    char* outputRedirect = param.getOutputRedirect();
    
    if (outputRedirect != nullptr) {
        if (freopen(outputRedirect, "w", stdout) == nullptr) {
            perror("freopen for output failed");
            exit(1);
        }
    }
    
    if (inputRedirect != nullptr) {
        if (freopen(inputRedirect, "r", stdin) == nullptr) {
            perror("freopen for input failed");
            exit(1);
        }
    }
}

// the 'driver' for the shell
void Shell::run(int argc, char* argv[]){
    Parse parse;
    bool debug = false;
    if(argc > 1 && strcmp(argv[1], "-Debug") == 0){
        debug = true;
    }
    
    while(true) {
        std::cout << "ズズ ";
        std::string inputStr;
        std::getline(std::cin, inputStr);
        
        if (inputStr == "exit"){
            break;
        }
        
        if (inputStr.empty()) { 
            continue;
        }
        
        char input[1024];
        strcpy(input, inputStr.c_str());
        parse.tokenize(input, param);
        
        if(debug) {
            param.printParams();
        }
        executeCommand();
          
        param = Param();
    }
}