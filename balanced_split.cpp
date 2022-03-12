#include<bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std; 

// Add any helper functions you may need here

// O[NlogN]
void quicksort(std::vector<int>& arr, int left_idx, int right_idx) {
  int split_idx = left_idx + (right_idx - left_idx) / 2;
  int left_size = split_idx - left_idx;
  int right_size = right_idx - split_idx;

  if (split_idx == 0) {
    return;
  }

  while (left_idx < right_idx) {
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
  quicksort(arr, split_idx, right_size);
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


// O[N]
int sum(std::vector<int>& arr, int start_idx, int end_idx) {
  auto sum = std::accumulate(arr.cbegin() + start_idx, arr.cbegin() + end_idx, 0);
  return sum;
}

bool balancedSplitExists(std::vector<int>& arr){
  int left_idx = 0;
  int right_idx = arr.size() - 1;
  quicksort(arr, left_idx, right_idx);

  //std::sort(arr.begin(), arr.end());

  for (auto idx = arr.size() - 1; idx >= 1; --idx) {
    if (sum(arr, idx, arr.size()) == sum(arr, 0, idx) && arr[idx - 1] < arr[idx]) {
      return true;
    }
  }

  return false;
}



/*
  array of ints (may include duplicates)
  
  split in A and B where A.sum() == B.sum()
  
  A < B
  
  ex:
  
  [1 5 7 1]
  sort -> [1 1 5 7]
  split -> [1 1 5] = [7] <=> 7 = 7
  
  ex:
  
  [12 7 6 7 6]
  sort -> [6 6 7 7 12]                            O[NlogN]
  
  Can we split [] to 0? edge case
  
  arr = quicksort(arr)
  for i=N-1 to 1:                                 O[N]
    if arr[i :].sum() == arr[: i].sum():
      return true
   return false
*/








// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(bool expected, bool output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl; 
  }
  test_case_number++;
}

int main(){
  // Testcase 1
  /*std::vector<int> arr_1{2, 1, 2, 5};
  bool expected_1 = true;
  bool output_1 = balancedSplitExists(arr_1); 
  check(expected_1, output_1);*/
  
  // Testcase 2
  vector<int> arr_2{3, 6, 3, 4, 4};
  bool expected_2 = false;
  bool output_2 = balancedSplitExists(arr_2); 
  check(expected_2, output_2); 

  // Add your own test cases here
  
  return 0; 
}