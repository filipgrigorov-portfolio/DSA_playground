#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


bool isBalanced(string s) {
  if (s.empty()) {
    return true;
  }

  // valid pairs
  std::unordered_map<char, char> mapping = {
    { ')', '(' },
    { ']', '[' },
    { '}', '{' }
  };

  std::deque<char> queue = {s.front()};
  for (auto idx = 1; idx < s.size(); ++idx) {
    if (mapping[s[idx]] == queue.back()) {
      // (B)
      if (queue.empty()) {
        return false;
      }

      queue.pop_back();
    } else {
      queue.push_back(s[idx]);
    }
  }

  // if we empty upon match, we have: (A) all lefties -> stack is not empty (B) all righties -> stack is empty
  // (A)
  if (!queue.empty()) {
    return false;
  }

  return true;
}



/*
  conditions:
    * sequence is []
    * sequence is superset of balanced sequences
    * ( and ) and subsequence is also balanced
    
    stack = []
    
    ex: {[()]}
    
    stack = [ { ]
    
    is [ != stack.last:
      stack = [ {,[ ]         stack = [ {,[ ]
    else:
      stack.pop               stack = [  ]
      
      
    is ( != stack.last
      stack = [ {,[,( ]       stack = [ {,[,( ]
    else:
      stack.pop               stack = [  ]
      
    is ) == stack.last:
      stack = [ {,[,(, ... ]       stack = [ {,[,(, .... ]
    else:
      stack.pop               stack = [ {,[, ]
      
     ......
     
     
     Now, with every other ch, the stack will be poped until empty
     
     
     Edge cases:
      * all left ones       -> stack will not be empty -> return false
      * all right ones      -> stack will not be empty -> return false
      * empty stack         -> return false
*/









// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(bool expected, bool output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string s_1 = "{[(])}";
  bool expected_1 = false;
  bool output_1 = isBalanced(s_1);
  check(expected_1, output_1);

  string s_2 = "{{[[(())]]}}";
  bool expected_2 = true;
  bool output_2 = isBalanced(s_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
