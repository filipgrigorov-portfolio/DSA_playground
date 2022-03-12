#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
int binarySearch(char x, std::string str, int low, int high) {
  if (low > high) {
    return -1;
  }

  int mid = low + ((high - low) / 2);
  if (str[mid] == x) {
    return mid;
  }

  if (x < str[mid]) {
    return binarySearch(x, str, low, mid - 1);
  }

  return binarySearch(x, str, mid + 1, high);
}

int minLengthSubstring(string s, string t) {
  // Write your code here
  std::vector<int> sub_indices;
  for (auto idx = 0; idx < t.size(); ++idx) {                               // O[M] or t.len
    int low = 0, high = s.size() - 1;
    auto ch = t[idx];
    auto found_idx_in_s = s.find_first_of(ch);                                // O[logN]
    const auto ch_occs_in_s = std::count(s.cbegin(), s.cend(), ch);         // O[N]
    const auto ch_occs_in_t = std::count(t.cbegin(), t.cend(), ch);         // O[M]
    if (ch_occs_in_s != ch_occs_in_t) {
      return -1;
    }

    if (found_idx_in_s == std::string::npos) {
        return -1;
    }

    sub_indices.push_back(found_idx_in_s);
  }

  std::sort(sub_indices.begin(), sub_indices.end(), std::less<int>());    // O[logN]

  return sub_indices.back() - sub_indices.front() + 1;
}



/*
  Input: s and t (strings)
  
  Select any sub_s + rearrange sub_s -> min len of sub_s, so t is substr of sub_s
  
  t_dict = []
  find and allocate indices to t strings keys (1st found is ok):
    if even one letter is no foud, we return -1
    if no enough number of repeating letters are present, we also return -1
    t_dict.append(letter_1,idx_1)
    t_dict.append(letter_2,idx_2)
    .
    .
    .
    t_dict.append(letter_N,idx_N)
    
   sort(t_dict by idx)
   
   return t_dict[last] - t_dict[first] + 1
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

  string s_1 = "dcbefebce";
  string t_1 = "fd";
  int expected_1 = 5;
  int output_1 = minLengthSubstring(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf";
  string t_2 = "cbccfafebccdccebdd";
  int expected_2 = -1;
  int output_2 = minLengthSubstring(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
