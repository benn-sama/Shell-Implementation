#include "./param.hpp"
#include <iostream>

void test_param_1() {
  Param param;
  char *vector[32];
  char word1[] = "ab";
  char word2[] = "cd";
  char word3[] = "ef";
  char word4[] = "hi";;
  char word5[] = "ab";
  char word6[] = "\0";

  std::cout << "ASSIGNING vector to char arrays" << std::endl;
  vector[0] = word1;
  vector[1] = word2;
  vector[2] = word3;
  vector[3] = word4;
  vector[4] = word5;
  vector[5] = word6;
  std::cout << "FINISHED vector to char arrays" << std::endl << std::endl;

  std::cout << "ADDING ARGUMENTS to the param" << std::endl;
  for (int i = 0; i < 5; ++i) {
    param.addArgument(vector[i]);
  }
  std::cout << "FINISHED adding arguments to the param" << std::endl << std::endl;

  std::cout << "RETURNING param.getArguments()" << std::endl;
  char** returnedVector = param.getArguments();
  std::cout << "RETURNED param.getArguments()" << std::endl << std::endl;
  
  std::cout << "OUTPUTTING returned vector" << std::endl;
  int j = 0;
  while (returnedVector[j] != nullptr) {
    std::cout << j << ":" << returnedVector[j] << std::endl;
    ++j;
  }
  std::cout << "FINISHED OUTPUTTING returned vector" << std::endl << std::endl;
}

int main() {
  std::cout << "testing param" << std::endl;
  test_param_1();
}