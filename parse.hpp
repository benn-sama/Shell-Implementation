/*
 * parse.hpp
 * Authors: Benjamin Green, Chris Jackson
 * Date: Fall 2025
 *
 * This header defines the Parse class used for tokenizing a user’s input string
 * into a Param object for the COP4634 shell project. It extracts command tokens,
 * detects input/output redirection, and prepares arguments for execution.
 *
 * Responsibilities:
 * - Split a command line string into individual tokens.
 * - Populate the Param object with command arguments, redirection, and flags.
 * - Provide an interface for the shell to parse commands before execution.
 */
#ifndef PARSE_HPP
#define PARSE_HPP

#include <cstddef>
#include "param.hpp"


class Parse {
  private:
    char *argumentVector[MAXARGS];
  public:
    void tokenize(char* input, Param& param);
};

#endif