#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> findMaxProduct(vector <int> arr) {
  // Write your code here
  if (arr.size() < 2) {
    return std::vector<int>{-1};
  }

  std::vector<int> output = {-1, -1};
  for (auto idx = 2; idx < arr.size(); ++idx) {
    auto sub_arr = std::vector<int>(arr.cbegin(), arr.cbegin() + idx + 1);
    std::sort(sub_arr.begin(), sub_arr.end(), std::less<int>());
    output.push_back(
      sub_arr[sub_arr.size() - 1] * 
      sub_arr[sub_arr.size() - 2] * 
      sub_arr[sub_arr.size() - 3]);
  }

  return output;
}



/*
  Input: n ints
  Output: 
  
  arr = [1, 2, 3, 4, 5]
  out = [-1 -1 arr[2] * arr[1] * arr[0] arr[3] * arr[2] * arr[1] arr[4] * arr[3] * arr[2]]
  
  out = [-1 -1 arr[i + 2] * arr[i + 1] * arr[i] arr[i + 1 + 2] * arr[i + 1 + 1] * arr[i + 1 + 0] arr[i + 2 + 2] * arr[i + 2 + 1] * arr[i + 2 + 0]]
  
  if arr.size < 2: // fewer than 3 elements
    return [-1]
  out = [-1, -1]
  for i=2 to N-1:
    sub_arr = arr[: i]
    sort(sub_arr)[-3 :]
    out.append(sub_arr[i + 2] * sub_arr[i + 1] * sub_arr[i])
  return out
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
  vector <int> arr_1{1, 2, 3, 4, 5};
  vector <int> expected_1{-1, -1, 6, 24, 60};
  vector <int> output_1 = findMaxProduct(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{-1, -1, 56, 56, 140, 140};
  vector <int> output_2 = findMaxProduct(arr_2);
  check(expected_2, output_2);

  /* 
    arr = [ 1, 2, 3, 4, 5, 7 ] - 0, 1, 2, 3, 4, 5
    out = [-1, -1]
    for i=0 to 3:
      out.append(arr[2] * arr[1] * arr[0])
  */

  // Add your own test cases here
  
}
