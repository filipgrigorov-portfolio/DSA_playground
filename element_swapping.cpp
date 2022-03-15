#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> findMinArray(vector <int> arr, int k) {
    if (k < arr.size() && k == 1 && arr[k] > arr[0]) {
        // find next smaller than arr[0]
        // I can do it linearly and optimize later
        int idx_min = -1;
        for (auto idx = k; idx < arr.size(); ++idx) {
            if (arr[idx] < arr[0]) {
                idx_min = idx;
                break;
            }
        }

        if (idx_min < 0) {
            return arr;
        }

        std::swap(arr[idx_min], arr[idx_min - 1]);
        return arr;
    }

    while (k > 0) {
        int idx_min = std::distance(arr.begin(), std::min_element(arr.begin(), arr.begin() + std::min(k + 1, int(arr.size()))));
        if (idx_min <= k) {
            while (idx_min > 0) {
                std::swap(arr[idx_min], arr[idx_min - 1]);
                idx_min--;
                k--;
            }
        }        
    }

    return arr;
}




/*

  input: arr of ints
  output: after k swaps (consecutive elements), min seq
  
  ex:
  
  n: 3
  k: 2 // swaps (consecutive)
  arr: [5 3 1]
  
  [5 1 3]
  [1 5 3]
  
  ex:
   0 1 2  3 4
  [8 9 11 2 1]
  
  For k indices inside the arr, arr[: k + 1], check which is min
  if i_min < k:
    swap until i_min = 0
    k--
    
  if k > 0:
    find next smallest and repeat
    
  pseudo:
  
  function findMinArray(arr, k):
    if k == 1 and k < arr.size:
      if arr[k] > arr[k - 1]:
        find the next smaller than arr[k - 1] and swap with its previous
        return arr

    while k > 0:
      find i_min within k steps excluding i_min that is in visited
      if i_min <= k:
        while i_min > 0:
          swap(arr[i_min], arr[i_min - 1])
          i_min--
          k--
    return arr
        
  edge case? what if I can find a smaller number, I cannot get to i=0 as k is too small
  Is that lexicographically smaller than if I move only the min number to i=0 instead
  
  Also, if k = 1, 1 swap and I have
  
  [11 12 1]
  i_min (0 - 1): 1
  
  [12 11 1] is not good but [11 1 12] is better?
  
  i_min: 1 which is 12 but 12 > 11
  
  
        
  test:
  
  [5 3 1] - 0 1 2
  
  k: 2
  visited: []
  i_min (0 to min(k, arr.size)):  val=1 and i_min: 2 0-2
  ? 2 > 0: yes
  
  swap(arr[2], arr[1])
  
  i_min: 1
  k: 1
  visited: [1, 1]
  
  swap(arr[1], arr[0])
  i_min: 0
  k: 0
  visited: [(0, 1)]
  
  arr: [1 5 3]


  test:
  
  arr: [8 9 11 2 1] - 0 1 2 3 4
  visited: []
  k: 3
  i_min: 0-3 (3 swaps)
  
  it 1:
  [8 9 2 11 1]
  i_min: 2
  
  it 2:
  [8 2 9 11 1]
  i_min: 1
  
  it 3:
  [2 8 9 11 1]
  i_min: 0

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

  int n_1 = 3, k_1 = 2;
  vector <int> arr_1{5, 3, 1};
  vector <int> expected_1{1, 5, 3};
  vector <int> output_1 = findMinArray(arr_1,k_1);
  check(expected_1, output_1);

  int n_2 = 5, k_2 = 3;
  vector <int> arr_2{8, 9 ,11, 2, 1};
  vector <int> expected_2{2, 8, 9, 11, 1};
  vector <int> output_2 = findMinArray(arr_2,k_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
