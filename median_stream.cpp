#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> findMedian(vector <int> arr) {
  std::vector<int> outputs;

  for (auto idx = 0; idx < arr.size(); ++idx) {
    // arr of size 1
    if (idx == 0) {
      outputs.push_back(arr[idx]);
      continue;
    } 
    // arr of size 2
    else if (idx == 1) {
      outputs.push_back((arr[0] + arr[1]) / 2);
      continue;
    }

    std::vector<int> subarr(arr.begin(), arr.begin() + idx + 1);
    std::sort(subarr.begin(), subarr.end());
    const auto half_size = subarr.size() / 2;
    auto median = (subarr.size() % 2 == 0) ? (subarr[half_size - 1] + subarr[half_size]) / 2 : subarr[half_size];
    outputs.push_back(median);
  }

  return outputs;
}




/*

  input:
  
  arr: N
  
  output:
  
  out: N
  
  out_i: median(arr[: i])
  
  3 4 5
  if odd # ints: med = 4; i = n / 2 = 3 / 2 = 1 -> arr[1] = 4
  
  3 4 5 6
  if even # ints: med = (4 + 5) / 2 = 4; i = n / 2 and n / 2 - 1
  i1: 4 / 2 = 2
  i2: 4 / 2 - 1 = 1
  
  ex:
  
  [5 15 1 3]
  
  function findMedian(arr):
  
    outputs = []

    // O[1]
    if arr.size == 1:
      return [arr[0]]

    // O[1]
    if arr.size == 2:
      return (arr[0] + arr[1]) / 2

    // O[N]
    for i=0 to N-1 in arr:
      subarr = arr[: i]
      
      // O[1]
      if arr.size == 1:
        outputs.append([arr[0]])
        continue

      // O[1]
      if arr.size == 2:
        outputs.append((arr[0] + arr[1]) / 2)
        continue
      
      // O[MlogM]
      sort(subarr)

      // O[1]
      half_size = subarray.size / 2
      median = (subarray[half_size - 1] + subarray[half_size]) / 2 if i + 1 % 2 == 0 else subarray(half_size)
      outputs.append(median)
      
  test:
  
  arr: [5 15 1 3]
  n: 4
  
  outputs: [5]
  
  
  outputs: [5 10]
  
  
  subarr: [ 5 15 1 ]
  subarr: [ 1 5 15 ]
  hs: 1
  median = 5
  outputs: [ 5 10 5 ]
  
  
  subarr: [ 5 15 1 3 ]
  subarr: [ 1 3 5 15 ]
  hs: 2
  median: (3 + 5) / 2 = 4
  outputs: [ 5 10 5 4 ]
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
  vector <int> arr_1{5, 15, 1, 3};
  vector <int> expected_1{5, 10, 5, 4};
  vector <int> output_1 = findMedian(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{2, 3, 4, 3, 4, 3};
  vector <int> output_2 = findMedian(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
