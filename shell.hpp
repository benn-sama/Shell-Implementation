/*
 * shell.hpp
 * Authors: Benjamin Green, Chris Jackson
 * Date: Fall 2025
 *
 * This header defines the Shell class which encapsulates the behavior
 * of the custom shell for the COP4634 project. It is responsible for 
 * managing the main execution loop, parsing commands, handling foreground 
 * and background execution, and managing I/O redirection.
 *
 * Responsibilities:
 * - Display a prompt and read user input.
 * - Parse commands and populate a Param object.
 * - Handle I/O redirection using freopen().
 * - Support background execution using fork().
 * - Wait for foreground and background processes appropriately.
 */
#ifndef SHELL_HPP
#define SHELL_HPP

#include "param.hpp"

class Shell {
  private:
    Param param;  
    void executeForeground();
    void executeBackground();
    void checkBackgroundProcesses();
    void executeCommand();
    void setupRedirection();

  public:
    Shell();
    void run(int argc, char* argv []);
};

#endif