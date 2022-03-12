#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> CountSubarrays(vector <int> arr) {
  // Write your code here
  std::vector<int> counts(arr.size(), 0);
  for (auto i = 0; i < arr.size(); ++i) {
    counts[i] = 1;
    for (auto j = 0; j < arr.size(); ++j) {
      if (j < i) {
        counts[i] += int(*std::max_element(arr.cbegin() + j, arr.cbegin() + i + 1) == arr[i]);
      } else if (j > i) {
        counts[i] += int(*std::max_element(arr.cbegin() + i, arr.cbegin() + j + 1) == arr[i]);
      }
    }
  }  
  return counts;
}



/*
  Input: array with N elements -> a[]
  
  * for each a[i] is max of a_sub[]
  * a_sub[] start at i or end at i
  
  For each element in the array:
    - check if there is subarray that ends at i, when a[i] is max starting at i=0
    - check if there is subarray that starts at i, when a[i] is max till i=N-1
    - count all of the eligible subarrays and return

  Note: Always going to be at least one (the number by itself)
  counts = []
  for each element at i=0 to N-1:       O[N]
    counts[i] = 1
    for each element at j=0 to N-1:     O[N] -> this could be O[m]
        if j < i:
          counts[i] += int(max(a[j : i + 1]) == a[i])   O[n] n < N
        elif j > i:
          counts[i] += int(max(a[i : j + 1]) == a[i])        O[n] where n < N
  return counts

  O[N^2] or O[Nm]
*/








// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  vector <int> test_1{3, 4, 1, 6, 2};
  vector <int> expected_1{1, 3, 1, 5, 1};
  vector <int> output_1 = CountSubarrays(test_1);
  check(expected_1, output_1);

  vector <int> test_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{1, 2, 6, 1, 3, 1};
  vector <int> output_2 = CountSubarrays(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
