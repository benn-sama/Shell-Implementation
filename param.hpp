/*
 * param.hpp
 * Authors: Benjamin Green, Chris Jackson
 * Date: Fall 2025
 *
 * This header defines the Param class used to store parsed components
 * of a command line entered into the COP4634 shell. It includes fields
 * for input/output redirection, argument tokens, and background execution.
 *
 * Responsibilities:
 * - Store redirection file names and argument tokens.
 * - Track whether the command should be run in the background.
 * - Provide getters and setters for command execution.
 * - Format parsed command data for debugging.
 */

#ifndef PARAM_HPP
#define PARAM_HPP
#define MAXARGS 32

class Param {
  private:
    char *inputRedirect;           // file name || NULL
    char *outputRedirect;          // file name || NULL
    int   background;              // either 0 || 1
    int   argumentCount;           // same as argc in main()
    char *argumentVector[MAXARGS]; // array of strings
  
  public:
    // Constructs an empty Param object.
    Param();

    /* @param void addArgument()
     * Adds an argument string to the argument list in thei object.
     * This DOES NOT create a string copy of the original string.
     * If NULL, nothing will be added
     */
    void addArgument(char *newArgument); 
    
    /* @param getArguments()
     * Returns an argument list referencing char* strings. 
     * The last element list is NULL to mark the end of list elements.
     * This makes the size of the list one larger than the number of arguments added to this
     * NOTE:
     *  Caller must deallocated memory for the list.
     */
    char** getArguments();
    void setInputRedirect(char *newInputRedirect);
    void setOutputRedirect(char *newOutputRedirect);
    void setBackground(int newBackground);
    char* getInputRedirect();
    char* getOutputRedirect();
    int getBackground();
    void printParams();
};

#endif