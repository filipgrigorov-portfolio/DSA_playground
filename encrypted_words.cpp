#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


string findEncryptedWord(string s) {
  const auto len = s.size();
  auto mid_idx = len / 2;

  if (len % 2 == 0) {
    mid_idx--;
  }

  std::string r{""};
  r += s[mid_idx];

  auto left_side = s.substr(0, mid_idx);
  if (left_side.size() < 3) {
    r += left_side;
  } else {
    r += findEncryptedWord(left_side);
  }

  auto right_side = s.substr(mid_idx + 1, s.size() - 1);
  if (right_side.size() < 3) {
    r += right_side;
  } else {
    r += findEncryptedWord(right_side);
  }

  return r;
}

/*
  test:

  s: facebook

  len: 8
  mid_idx: 4
  mid_idx: 3

  r: e
  r: eafc
  r: eafcobok
*/




/*

  input: str
  output: shuffled str
  
  procedure:
  
  (1)
  half_size = S.zise / 2
  if S.size is even: mid_ch = S[half_size - 1]
  if S.size is odd: mid_ch = S[half_size]
  
  (2)
  S += S_(1)[: mid_ch]
  
  (3)
  S += S_(1)[mid_ch :]
  
  ex:
  
  abc
  S is odd: mid_ch=b
  R: b (1)
  R: ba (2)
  R: bac (3)
  
  S: abcxcba 0123456
  S is odd: mid_ch=x
  S: x (1)
  S: xabc (2)
  S: xabccba (3)
  
  pseudo:
  
  function findEncryptedWord(S):
    len = S.size
    
    half = len / 2
    if len is even:
      mid_ch = S[half - 1]
    else:
      mid_ch = S[half]

    R.append(mid_ch)
    
    if S[: mid_ch] < 3:
      R.append(S[: mid_ch])
    else:
      R.append(findEncryptedWord(S[: mid_ch], R))
    
    if S[mid_ch + 1 :].size < 3:
      R.append(S[mid_ch + 1 :])
    else:
      R.append(findEncryptedWord(S[mid_ch + 1 :], R))
  
  
  test:
  
  S: facebook
  mid_ch: e
  R: e
  
  S: fac
  mid_ch: a
  R: afc
  
  S: book
  mid_ch: o
  R: obok
  
  R: eafcobok
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
    cout << rightTick << " Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << " Test #" << test_case_number << ": Expected ";
    printString(expected); 
    cout << " Your output: ";
    printString(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string s_1 = "abc";
  string expected_1 = "bac";
  string output_1 = findEncryptedWord(s_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string expected_2 = "bacd";
  string output_2 = findEncryptedWord(s_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
