#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

bool findChar(char ch, std::string str) {
    if (str.size() == 1 && ch == str[0]) {
        return true;
    }

    if (str.empty()) {
        return false;
    }

    const int half_size = (str.size() - 1) / 2;
    if (findChar(ch, str.substr(0, half_size))) {
        return true;
    }

    if (ch == str[half_size]) {
        return true;
    }

    return findChar(ch, str.substr(half_size + 1, str.size() - 1));
}

int matchingPairs(string s, string t) {
    // O[N]
    const size_t len = s.size();
    int m = 0;
    int x = 0;
    for (auto idx = 0; idx < len; ++idx) {
        if (s[idx] == t[idx]) {
            ++m;
        } else {
            // binary search for s[idx] in t[idx]
            if (x < 1 && findChar(s[idx], t)) {
                ++x;
            }
        }
    }

    if (m == len) {
        return m - 2;
    }

    if (x > 0) {
        return m + 2;
    } else {
        return m;
    }
}




/*
  input:
  
  s and t
  
  output: find the max number of possible matching pairs
  
  ex:
  
  s = "abcd"
  t = "adcb"
    
  swap s[1] with s[3] -> one swap -> 4 mathcing pairs
  
  ex:
  
  s = "mno"
  t = "mno"
  
  mandatory swap:
  
  s = "mon"
  t = "mno"
  
  1 matching pair
  
  find how many chs match, initially:
  
  2/4: 4
  3/3: 1
  
  1st edge case:
  n/n: always lose 2 dof (max = n - 2)
  
  m/n: out of the (n - m), find number of mathing pairs, then, we cam maximally add 2 dofs out of those, as we can swap only once
  
  
  pseudo:
  
  find number of matching pairs: m
  if m == n:
    return n - 2
  find number of matching (n - m) pairs at different indices, x
  
  // if additional matching pairs, we can increase them by 2 as we can swap 1 pairs out of the x ones
  if x > 0:
    return m + 2
    
  // if not additional matching pairs, then, we must only have the m ones
  if x == 0:
    return m
  
  test:
  s: abcde
  t: adcbe
  
  m: 3
  ? m==n: no
  x: 2
  ? x > 0: yes
  return 3 + 2 = 5
  
  s: mno
  t: mno
  
  m: 3
  ? m==n: yes
  return 3 - 2 = 1
  
*/







// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
  string s_1 = "abcde";
  string t_1 = "adcbe";
  int expected_1 = 5;
  int output_1 = matchingPairs(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string t_2 = "abcd";
  int expected_2 = 2;
  int output_2 = matchingPairs(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
