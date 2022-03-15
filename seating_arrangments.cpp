#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

/*
  original_max_idx = 1
  prev_idx = original_max_idx
  [ 5 10 6 8 ]
  5 4 2 3
  
  next_idx = (++prev_idx) % N - 1
  if next_idx == original_max_idx:
    stop
  swap(prev_idx, next_idx)
  
  ...
  
  [ 5 6 10 8 ]
  1 4 2 3
  
  [ 5 6 8 10 ]
  1 2 2 5
  
  [ 10 5 6 8 ]
  5 1 2 2
  
  Move the max around only: O[N]
  
  a = inf
  for each pos that h_max can take:
    d = [ compute each h_diff for given position ]
    diff = max(d)
    if diff < a:
      a = diff
  return a
*/

int minOverallAwkwardness(vector <int> arr) {
  const int original_max_index = std::distance(arr.begin(), std::max_element(arr.begin(), arr.end()));
  int idx = original_max_index;

  int min_akw = std::numeric_limits<int>::max();

  int n = arr.size() - 1;
  do {
    std::vector<int> diffs;
    for (auto i = 0; i < n; ++i) {
      diffs.push_back(std::abs(arr[i] - arr[i + 1]));
    }
    diffs.push_back(std::abs(arr.back() - arr.front()));

    const int max_height_diff = *std::max_element(diffs.begin(), diffs.end());
    if (max_height_diff < min_akw) {
      min_akw = max_height_diff;
    }
    
    int next_idx = (idx + 1) % (n + 1);
    std::swap(arr[idx], arr[next_idx]);
    idx = next_idx;
  } while (idx != original_max_index);

  return min_akw;
}

// O[N^2]

/*
  test:
    h = [1 2 5 3 7]

    oidx: 4
    idx: 4

    [ 6 1 3 2 4 ]

    pi: 8 % 7 = 0

    [ 7 1 2 5 3 ]

*/


/*

  input:
  
  n guests (1-indexed)
  guest_i - height of arr[i - 1]
  
  circular table
  one per seat
  
  n! possible permuations
  
  a_i = diff(h_i, h_i+1)

  1 and N are adjacent
  
  n pairs of adjacent guests:
  
  ex: 5 guests
  
  p = [1-2, 2-3, 3-4, 4-5, 5-1]
  
  a = [a_1, a_2, a_3, a_4, a_5]
  
  5! = 120 permutations
  
  a_overall = max(a)
  
  min(a)|5! = ?
  
  goal: minimize the seating arrangment
  
  ex:
  
  n = 4
  np = n! = 4! = 24 permutations
  h = [5 10 6 8]
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

  vector <int> arr_1{5, 10, 6, 8};
  int expected_1 = 4;
  int output_1 = minOverallAwkwardness(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{1, 2, 5, 3, 7};
  int expected_2 = 4;
  int output_2 = minOverallAwkwardness(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
