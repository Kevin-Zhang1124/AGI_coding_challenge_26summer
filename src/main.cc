#include "inflationary.h"
#include <iostream>


int main() {
    std::string input;
    std::getline(std::cin, input);

    // create a Inflationary object
    Inflationary infl(input);
    // scan through input and mutate it
    std::string result = infl.scan();
    // output result
    std::cout << result << std::endl;
}
