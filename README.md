# AGI Coding Challenge 26 Summer

## 🧩 Problem Overview
Create a program (in any language) that performs an “inflationary” operation against strings.

**Input:**
String: text to manipulate.

**Output:**
Find numbers in the string and increase them by one; return the new string.

**Example:**
"Anyone up for tennis?" returns "Anytwo up for elevennis?"

## ⚙️ Compile
```bash
g++ -std=c++17 src/inflationary.cc src/main.cc -o inflationary
```

## ▶️ Run test
```bash
./inflationary < tests/input.txt
```

## 💡 My Thinking Process

### Challenge 1 - Scanning

How to recognize all the number in a text?

My first idea is to use maximal munch algorithm (greedy algorithm), which is similar to what we do when building up a compiler. Just change from recognizing assembly instructions to recognizing numbers. 

**Pros**    
The recognizing logic is clear.

**Cons**    
we need to build a Deterministic Finite Automata (DFA) and read this DFA structure into our data structure, which is very time consuming and we need a lot of code to implement the DFA construction part.

### Challenge 2 - Increment number by 1

How to get a number's successor

The approach used was to make a hash map that maps each number word to its successor (e.g., one → two, two → three, three → four) to enable constant-time lookup during replacement.

### Challenge 3 - Insert the number back to string

During scanning, I maintain two indices into the input string: a start index
indicating where a potential number word begins, and an end index that advances
while the DFA transitions remain valid. When a number word is recognized, these
indices are used to extract the matched substring via `std::string::substr`,
which is then replaced by its successor from the lookup map.


## 📊 AI Analysis on my approach - ChatGPT

The solution uses a DFA-based maximal munch (greedy) scan to recognize number
words and a hash map for constant-time successor lookup. This approach is
deterministic, efficient, and matches the example behavior where number words
may appear inside larger words (e.g., "ten" in "tennis").

However, for a small fixed set of number words, this design is more complex than
necessary. A trie-based or direct substring approach would be simpler and easier
to maintain. Additionally, the greedy strategy replaces number substrings inside
larger words, which may not be desirable without additional boundary checks.


## 💬 Prompts I used when using AI tools
- "Is maximal munch a good algorithm for this problem?"
- "What simpler alternatives could replace a DFA for recognizing a small set of number words?"
- "For this problem, do you have a better algorithm or solution?"
- "Can you show me an example how trie would work in this case?"


## ✨ AI Solution (Alternative Approach)

### Overview
In addition to the DFA-based maximal munch approach, an AI-assisted analysis
suggests a **Trie (prefix tree)** as a simpler and more maintainable solution
for this problem.

The Trie-based approach achieves the same **longest-match (greedy) behavior**
while reducing implementation complexity. Instead of mutating original input string, we create a new string called result as we go through the input string.

pseudo-code:

```text
while j < length(input) and node has child input[j]:
    node = node.child(input[j])
    if node represents a complete word:
        lastMatchEnd = j
        lastMatchWord = substring(input, i, j)
    j++

if lastMatchEnd != -1:
    result += successor[lastMatchWord]
    i = lastMatchEnd + 1
else:
    result += input[i]
    i++
```

## 🎯 Conclusion
Through this assignment, I explore a new approach to string scanning - Trie (prefix tree). AI tools were used to assist with reasoning and decision making. This exercise emphasized the value of selecting algorithms that align with both problem constraints and long-term maintainability.