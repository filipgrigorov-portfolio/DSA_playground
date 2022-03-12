#include<bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std; 

// Add any helper functions you may need here

// O[NlogN]
void quicksort(std::vector<int>& arr, int left_idx, int right_idx) {
  int split_idx = left_idx + (right_idx - left_idx) / 2;

  if (split_idx < 1) {
    return;
  }

  while (left_idx <= right_idx) {
    if (arr[left_idx] >= arr[split_idx]) {
      std::swap(arr[left_idx], arr[split_idx]);
    }

    if (arr[right_idx] <= arr[split_idx]) {
      std::swap(arr[right_idx], arr[split_idx]);
    }

    left_idx++;
    right_idx--;
  }

  quicksort(arr, 0, split_idx - 1);
  quicksort(arr, split_idx + 1, arr.size() - 1);
}
 

/*
  def quicksort(arr):
    if arr.size == 1:
      return

    li = 0
    ri = 0
    si = arr.size // 2

    while li <= ri:
      if arr[li] > arr[si]:
        swap arr[li] with arr[si]

      if arr[ri] < arr[si]:
        swap arr[ri] with arr[si]

      li += 1
      ri -= 1

    quicksort(arr[: si])
    quicksort(arr[si :])
*/

void quicksort(std::vector<int>& arr){
  int left_idx = 0;
  int right_idx = arr.size() - 1;
  quicksort(arr, left_idx, right_idx);
}








// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(vector<int> expected, vector<int> output) {
  bool is_same = false;
  for (auto idx = 0; idx < expected.size(); ++idx) {
    if (expected[idx] != output[idx]) {
      is_same = false;
      break;
    }
  }
  
  std::cout << "Test: " << is_same << std::endl;
}

int main(){
  vector<int> arr_2{3, 6, 3, 4, 4};
  vector<int> expected_2{3, 3, 4, 4, 6};
  quicksort(arr_2); 
  check(expected_2, arr_2); 

  // Add your own test cases here
  
  return 0; 
}