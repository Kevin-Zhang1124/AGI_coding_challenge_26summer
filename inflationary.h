#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>


// DFA
// this DFA is used to recognize numbers while scanning through input text
class DFA {
    // define data structures to store information
    std::unordered_set<char> alphabet;
    std::unordered_set<std::string> states;
    std::string initialState;
    std::unordered_set<std::string> acceptingStates;
    std::unordered_map<std::string, std::unordered_map<char, std::string>> trans;

public:
    // constructor, read in a DFA file and fill up data structure above
    DFA();

    bool hasTransition(const std::string& currentState, char c);
    std::string getNextState(const std::string& currentState, char c);
    bool isAccepting(const std::string& currentState);
};


// Inflationary
class Inflationary {
    // store the input text
    std::string input;
    // store each number's corresponding +1 value, O(1) look up
    // {"one" : "two", "two" : "three", "three" : "four", ...}
    std::unordered_map<std::string, std::string> plusOneMap;
    // use DFA
    DFA dfa;

public:
    // constructor
    Inflationary(const std::string& input);

    // scan the input string and return the transformed string
    std::string scan();

private:
    void buildPlusOneMap();
};
