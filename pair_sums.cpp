#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

bool binarySearch(int x, const std::vector<int>& arr) {
  // If we hit a leaf, check if equal to x
  if (arr.size() == 1) {
    return arr.front() == x;
  }
  // Split arr in the middle
  const auto half_size = std::max(0, int(0.5 * (arr.size() - 1)));
  auto left = std::vector<int>(arr.cbegin(), arr.cbegin() + half_size + 1);
  // Recurse through left half and check if found
  if (binarySearch(x, left)) {
    return true;
  }
  // When left half returns, check if the split node is equal to x
  if (arr[half_size] == x) {
    return true;
  }
  // Recurse through right half and check if found
  auto right = std::vector<int>(arr.cbegin() + half_size + 1, arr.cend());
  if (binarySearch(x, right)) {
    return true;
  }

  return false;
}

int numberOfWays(vector<int>& arr, int k) {
  // Write your code here
  int count = 0;
  for (auto i = 0; i < arr.size(); ++i) {
    auto x = k - arr[i];
    
    // find all occurences (count twice and divide by two after)
    for (auto j = 0; j < arr.size(); ++j) {
      if (x == arr[j] && i != j) {
        count++;
      }
    }
  }

  return count / 2;
}



/*
  Input: array of N ints
  Output: array of pairs s.t. a_t + a_t+1 = k where at least one index varies
  
  check for each element, if there is another one that, added to which, the sum is k
  if both indices are already visited as a pair, skip adding this pair
  
  pairs = {}
  for i=0 to N-1:                                     O[N]
    a_t+1 = k - a_t
    if binary_search(a_t+1) in array of ints:         O[NlogN]
      sorted_pair = sort(a_t.idx, a_t+1.idx)          O[1]

      pairs[sorted_pair] = [a_t, a_t+1]               O[1]

  return pairs.size                                   O[1]

  O[NlogN]

  N/2, N/4, N/6 ... N/2^D -> log(N/2^D) = log(N) - Dlog(2)
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

  int k_1 = 6;
  vector <int> arr_1{1, 2, 3, 4, 3};
  int expected_1 = 2;
  int output_1 = numberOfWays(arr_1, k_1);
  check(expected_1, output_1);

  int k_2 = 6;
  vector <int> arr_2{1, 5, 3, 3, 3};
  int expected_2 = 4;
  int output_2 = numberOfWays(arr_2, k_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
