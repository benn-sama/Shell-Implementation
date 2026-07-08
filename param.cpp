#include "param.hpp"
#include <iostream>

Param::Param() {
  inputRedirect = outputRedirect = nullptr;
  background = 0;
  argumentCount = 0;
}

void Param::addArgument(char *newArgument) {
  if (argumentCount < MAXARGS - 1) {
    argumentVector[argumentCount] = newArgument;
    ++argumentCount;
  }
}

char** Param::getArguments() {
    argumentVector[argumentCount] = nullptr;  // NULL terminate
    return argumentVector;  // Return original array (no new allocation)
}

void Param::setInputRedirect(char *newInputRedirect) {
  inputRedirect = newInputRedirect;
}

void Param::setOutputRedirect(char *newOutputRedirect) {
  outputRedirect = newOutputRedirect;
}

void Param::setBackground(int newBackground) {
  background = newBackground;
}

int Param::getBackground() {
  return background;
}

char* Param::getInputRedirect() {
  return inputRedirect;
}

char* Param::getOutputRedirect() {
  return outputRedirect;
}

void Param::printParams() {
    std::cout << "=== Parameters ===" << std::endl;

    for (int i = 0; i < argumentCount; ++i) {
        std::cout << "arg[" << i << "]: " << argumentVector[i] << std::endl;
    }

    std::cout << "inputRedirect: "
              << (inputRedirect ? inputRedirect : "None") << std::endl;
    std::cout << "outputRedirect: "
              << (outputRedirect ? outputRedirect : "None") << std::endl;
    std::cout << "background: " << background << std::endl;
    std::cout << "argumentCount: " << argumentCount << std::endl;
}
