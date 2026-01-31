#include "inflationary.h"

// embedded DFA structure to recognize numbers
const char* dfaText = R"(
.ALPHABET
...
.STATEs
...
.TRANSITIONS
...
)";


// DFA
// DFA constructor
DFA::DFA() {
    // define input string stream to read in embedded DFA
    std::istringstream dfa_in(dfaText);
    // construct the DFA, fill up the data structure
    // ...
}

// hasTransition
bool DFA::hasTransition(const std::string& currentState, char c) {
    auto itState = trans.find(currentState);
    if (itState != trans.end()) {
        auto itChar = itState->second.find(c);
        if (itChar != itState->second.end()) {
            return true;
        }
    }
    return false;
}

std::string DFA::getNextState(const std::string& currentState, char c) {
    auto itState = trans.find(currentState);
    auto itChar = itState->second.find(c);
    return itChar->second;
}

bool DFA::isAccepting(const std::string& currentState) {
    return acceptingStates.find(currentState) != acceptingStates.end();
}


// Inflationary
// constructor
Inflationary::Inflationary(const std::string& input)
  :  dfa{}, input{input} {
    buildPlusOneMap();
}

// buildPlusOneMap
void Inflationary::buildPlusOneMap() {
    plusOneMap["one"] = "two";
    plusOneMap["two"] = "three";
    // ...
}

std::string Inflationary::scan() { 
    // scan through the input text, apply maximal munch (greedy algorithm) to
    // recognize numbers.

    // starting from i = 0, j = 1 and use j to track the dfa path
    // end loop when get into error state, then increment i by 1, start the dfa again

    // once recognize a number, use i and j to do string slicing, use plusOneMap to look
    // up new string
}
