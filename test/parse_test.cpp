#include "parse.hpp"
#include "param.hpp"
#include <iostream>
#include <cstring>

void test_parse_simple_command() {
    std::cout << "=== TESTING SIMPLE COMMAND PARSING ===" << std::endl;
    Parse parse;
    Param param;
    
    std::cout << "CREATING parse and param objects" << std::endl;
    std::cout << "FINISHED creating objects" << std::endl << std::endl;
    
    std::cout << "TESTING simple command: 'ls'" << std::endl;
    char input[] = "ls";
    std::cout << "CALLING tokenize with: " << input << std::endl;
    parse.tokenize(input, param);
    std::cout << "FINISHED tokenizing" << std::endl << std::endl;
    
    std::cout << "OUTPUTTING parsed results:" << std::endl;
    param.printParams();
    std::cout << "FINISHED simple command test" << std::endl << std::endl;
}

void test_parse_command_with_args() {
    std::cout << "=== TESTING COMMAND WITH ARGUMENTS ===" << std::endl;
    Parse parse;
    Param param;
    
    std::cout << "TESTING command with multiple arguments: 'ls -l -a /home'" << std::endl;
    char input[] = "ls -l -a /home";
    std::cout << "CALLING tokenize with: " << input << std::endl;
    parse.tokenize(input, param);
    std::cout << "FINISHED tokenizing" << std::endl << std::endl;
    
    std::cout << "OUTPUTTING parsed results:" << std::endl;
    param.printParams();
    std::cout << "FINISHED command with arguments test" << std::endl << std::endl;
}

void test_parse_input_redirection() {
    std::cout << "=== TESTING INPUT REDIRECTION PARSING ===" << std::endl;
    Parse parse;
    Param param;
    
    std::cout << "TESTING input redirection: 'wc < input.txt'" << std::endl;
    char input[] = "wc < input.txt";
    std::cout << "CALLING tokenize with: " << input << std::endl;
    parse.tokenize(input, param);
    std::cout << "FINISHED tokenizing" << std::endl << std::endl;
    
    std::cout << "OUTPUTTING parsed results:" << std::endl;
    param.printParams();
    std::cout << "Input redirect file: " << (param.getInputRedirect() ? param.getInputRedirect() : "NULL") << std::endl;
    std::cout << "FINISHED input redirection test" << std::endl << std::endl;
}

void test_parse_output_redirection() {
    std::cout << "=== TESTING OUTPUT REDIRECTION PARSING ===" << std::endl;
    Parse parse;
    Param param;
    
    std::cout << "TESTING output redirection: 'ls -l > output.txt'" << std::endl;
    char input[] = "ls -l > output.txt";
    std::cout << "CALLING tokenize with: " << input << std::endl;
    parse.tokenize(input, param);
    std::cout << "FINISHED tokenizing" << std::endl << std::endl;
    
    std::cout << "OUTPUTTING parsed results:" << std::endl;
    param.printParams();
    std::cout << "Output redirect file: " << (param.getOutputRedirect() ? param.getOutputRedirect() : "NULL") << std::endl;
    std::cout << "FINISHED output redirection test" << std::endl << std::endl;
}

void test_parse_background_command() {
    std::cout << "=== TESTING BACKGROUND COMMAND PARSING ===" << std::endl;
    Parse parse;
    Param param;
    
    std::cout << "TESTING background command: 'sleep 5 &'" << std::endl;
    char input[] = "sleep 5 &";
    std::cout << "CALLING tokenize with: " << input << std::endl;
    parse.tokenize(input, param);
    std::cout << "FINISHED tokenizing" << std::endl << std::endl;
    
    std::cout << "OUTPUTTING parsed results:" << std::endl;
    param.printParams();
    std::cout << "Background flag: " << param.getBackground() << std::endl;
    std::cout << "FINISHED background command test" << std::endl << std::endl;
}



int main() {
    std::cout << "=== STARTING PARSE TESTING ===" << std::endl << std::endl;
    
    try {
        test_parse_simple_command();
        test_parse_command_with_args();
        test_parse_input_redirection();
        test_parse_output_redirection();
        test_parse_background_command();
        
        std::cout << "=== ALL PARSE TESTS COMPLETED SUCCESSFULLY ===" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "TEST FAILED with exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}