#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


string rotationalCipher(string input, int rotationFactor) {
  // Write your code here
  for (auto idx = 0; idx < input.size(); ++idx) {
    auto rot_factor = rotationFactor;
    if (std::isalpha(input[idx])) {
      if (rot_factor >= 26) {
        rot_factor %= 26;
      }
      if (std::islower(input[idx])) {
        input[idx] = ((input[idx] - 'a' + rot_factor) % 26) + 'a';
      } else {
        input[idx] = ((input[idx] - 'A' + rot_factor) % 26) + 'A';
      }
    } else if (std::isdigit(input[idx])) {
      if (rot_factor >= 10) {
        rot_factor %= 10;
      }
      input[idx] = ((input[idx] - '0' + rot_factor) % 10) + '0';
    }
  }
  return input;
}




/*
  Zebra-493? >> 3 -> Cheud-726?
  Z -> 90 - 65 + 3 = 25 + 3 = 28 % 25 = 3 + 65 = 68 - 1 = 67 -> C

  Z -> 90 + 3 = 93 % 90 = 3 + 65 = 68 - 1 = 67 -> C

  Y -> 89 - 65 + 4 = 24 + 4 = 28 % 25 = 3 + 65 = 68 - 1 = 67 -> C

  Y -> 89 + 4 = 93 % 90 = 3 + 65 = 68 - 1 = 67

  k = 200
  Z -> R: 90 - 65 + 200 = 225 % 25 = 0 + 65 = 65 - 1 = 64
  X -> P
  Y -> Q

  e -> 101 - 97 + 3 = 4 + 3 = 7 % 25 = 7 + 97 = 104 - 1 = 103 -> g vs h (104)
  b -> 98 - 97 + 3 = 1 + 3 = 4 % 25 = 4 + 97 = 101 -1 = 100 -> d vs e (101)

  e -> 101 + 3 = 104 % 122 = 104 + 122 = 224 % 122 = 102 
  
  (4 + 3) % 10 = 7 % 10 = 7
  (9 + 3) % 10 = 12 % 10 = 2 (including the zero)
  (3 + 3) % 10 = 6
*/







// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printString(expected); 
    cout << " Your output: ";
    printString(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string input_1 = "All-convoYs-9-be:Alert1.";
  int rotationFactor_1 = 4;
  string expected_1 = "Epp-gsrzsCw-3-fi:Epivx5.";
  string output_1 = rotationalCipher(input_1, rotationFactor_1);
  check(expected_1, output_1);

  string input_2 = "abcdZXYzxy-999.@";
  int rotationFactor_2 = 200;
  string expected_2 = "stuvRPQrpq-999.@";
  string output_2 = rotationalCipher(input_2, rotationFactor_2);
  check(expected_2, output_2);
}
