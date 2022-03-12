#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

void addPenalty(std::vector<int> arr, int& sum) {
    if (arr.size() == 1) {
        return;
    }

    auto sub_arr = std::vector<int>(arr.cbegin(), arr.cbegin() + arr.size() - 2);
    sub_arr.push_back(arr[arr.size() - 2] + arr[arr.size() - 1]);
    sum += sub_arr.back();
    addPenalty(sub_arr, sum);
}

int getTotalTime(std::vector<int> arr) {
  // Write your code here
  std::sort(arr.begin(), arr.end(), std::less<int>());
  int sum = arr[arr.size() - 2] + arr[arr.size() - 1];
  auto sub_arr = std::vector<int>(arr.cbegin(), arr.cbegin() + arr.size() - 2);
  sub_arr.push_back(arr[arr.size() - 2] + arr[arr.size() - 1]);
  addPenalty(sub_arr, sum);
  return sum;
}




/*
  Input: list of N numbers
  Output: repeat op until 1 number
  
  replace any 2 numbers with their sum + penalty = sum
  
  sort(arr)                                                   // O[logN]
  sum = arr[-2] + arr[-1]

  function addPenalty(arr, sum):
    if arr.size == 1:
      return

    sub_arr = arr[: -2]
    sub_arr.append(arr[-2] + arr[-1])
    sub_arr += arr[-1]
  
    addPenalty(sub_arr, sum)

    O[logN] + O[n] = O[n]
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

  vector <int> arr_1{4, 2, 1, 3};
  int expected_1 = 26;
  int output_1 = getTotalTime(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 3, 9, 8, 4};
  int expected_2 = 88;
  int output_2 = getTotalTime(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}