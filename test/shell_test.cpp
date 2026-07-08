#include "./shell.hpp"
#include "./param.hpp"
#include "./parse.hpp"
#include <iostream>
#include <cstring>


/* 
void test_shell_redirection() {
    std::cout << "=== TESTING REDIRECTION PARSING ===" << std::endl;
    Parse parse;
    
    std::cout << "TESTING output redirection parsing" << std::endl;
    Param param1;
    char input1[] = "ls -l > output.txt";
    parse.tokenize(input1, param1);
    param1.printParams();
    std::cout << "Output redirect file: " << (param1.getOutputRedirect() ? param1.getOutputRedirect() : "NULL") << std::endl;
    std::cout << "FINISHED output redirection parsing" << std::endl << std::endl;
    
    std::cout << "TESTING input redirection parsing" << std::endl;
    Param param2;
    char input2[] = "wc < input.txt";
    parse.tokenize(input2, param2);
    param2.printParams();
    std::cout << "Input redirect file: " << (param2.getInputRedirect() ? param2.getInputRedirect() : "NULL") << std::endl;
    std::cout << "FINISHED input redirection parsing" << std::endl << std::endl;
    
    std::cout << "FINISHED redirection testing" << std::endl << std::endl;
} */

void test_shell_components() {
    std::cout << "=== TESTING SHELL COMPONENTS ===" << std::endl;
    Shell shell;
    Parse parse;
    
    std::cout << "CREATING shell and parse objects" << std::endl;
    std::cout << "FINISHED creating objects" << std::endl << std::endl;
    
    // Test parsing different command types
    std::cout << "TESTING different command parsing..." << std::endl;
    
    std::cout << "TESTING simple command parsing" << std::endl;
    Param param1;
    char input1[] = "ls";
    parse.tokenize(input1, param1);
    param1.printParams();
    std::cout << "FINISHED simple command parsing" << std::endl << std::endl;
    
    std::cout << "TESTING command with multiple arguments" << std::endl;
    Param param2;
    char input2[] = "ls -l -a /home";
    parse.tokenize(input2, param2);
    param2.printParams();
    std::cout << "FINISHED multiple arguments parsing" << std::endl << std::endl;
    
    std::cout << "FINISHED component testing" << std::endl << std::endl;
}

void test_shell_background() {
    std::cout << "=== TESTING BACKGROUND PARSING ===" << std::endl;
    Parse parse;
    
    std::cout << "TESTING background command parsing" << std::endl;
    Param param1;
    char input1[] = "sleep 5 &";
    parse.tokenize(input1, param1);
    param1.printParams();
    std::cout << "Background flag: " << param1.getBackground() << std::endl;
    std::cout << "FINISHED background parsing" << std::endl << std::endl;
    
    std::cout << "TESTING foreground command parsing" << std::endl;
    Param param2;
    char input2[] = "sleep 5";
    parse.tokenize(input2, param2);
    param2.printParams();
    std::cout << "Background flag: " << param2.getBackground() << std::endl;
    std::cout << "FINISHED foreground parsing" << std::endl << std::endl;
    
    std::cout << "FINISHED background testing" << std::endl << std::endl;
}

void test_shell_output_redirect() {
    std::cout << "=== TESTING OUTPUT REDIRECT ===" << std::endl;
    Parse parse;
    
    std::cout << "TESTING output parsing" << std::endl;
    Param param1;
    char input1[] = "ls -l >file.txt";
    parse.tokenize(input1, param1);
    param1.printParams();

    char* output = param1.getOutputRedirect();
    if (output != "file.txt") {
      std::cout << "INCORRECT: Input redirect file name: " << output << std::endl;
    }
    
    std::cout << "FINISHED input redirect" << std::endl;
}

void test_shell_input_redirect() {
    std::cout << "=== TESTING OUTPUT REDIRECT ===" << std::endl;
    Parse parse;
    
    std::cout << "TESTING output parsing" << std::endl;
    Param param1;
    char input1[] = "ls -l <file.txt";
    parse.tokenize(input1, param1);
    param1.printParams();

    char* input = param1.getInputRedirect();
    if (input != "file.txt") {
      std::cout << "INCORRECT: Input redirect file name: " << input << std::endl;
    }
    
    std::cout << "FINISHED input redirect" << std::endl;
}


int main() {
    std::cout << "=== STARTING SHELL TESTING ===" << std::endl << std::endl;
    
    try {
        test_shell_components();
        //test_shell_redirection();
        test_shell_background();
        test_shell_output_redirect();
        test_shell_input_redirect();
        
        std::cout << "=== ALL TESTS COMPLETED SUCCESSFULLY ===" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "TEST FAILED with exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}