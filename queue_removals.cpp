#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


using Num2Idx = std::pair<int, int>;
std::vector <int> findPositions(std::vector<int> arr, int x) {
  std::vector<Num2Idx> new_arr;
  // O[N]
  for (auto idx = 0; idx < arr.size(); ++idx) {
    new_arr.emplace_back(arr[idx], idx + 1);
  }

  // we keep arr as idx ref
  std::vector<Num2Idx> temp(new_arr.begin(), new_arr.end());
  std::vector<int> indices;

  // go through x iters
  // O[x]*(O[x] + O[N] + O[N])
  for (auto itr = 0; itr < x; ++itr) {
    // pop x ints from temp
    std::vector<Num2Idx> popped;
    if (x >= temp.size()) {
      popped = std::vector<Num2Idx>(temp.begin(), temp.end());
      temp = std::vector<Num2Idx>();
    } else {
      popped = std::vector<Num2Idx>(temp.begin(), temp.begin() + x);
      temp.erase(temp.begin(), temp.begin() + x);
    }

    // find the max value and original idx
    const auto max_val_itr = std::max_element(popped.begin(), popped.end(), 
      [](const auto& n1, const auto& n2) { return n1.first < n2.first; });
    indices.push_back((*max_val_itr).second);

    // remove max_val from popped
    // O[N]
    popped.erase(std::remove(popped.begin(), popped.end(), *max_val_itr), popped.end());

    // decrement if condition is met
    // O[x]
    std::for_each(popped.begin(), popped.end(), [](auto& n) { if (n.first > 0) n.first -= 1; });

    // compose new temp
    // if temp is empty
    if (temp.empty()) {
      temp = std::vector<Num2Idx>(popped.begin(), popped.end());
    } else {
      temp.insert(temp.end(), popped.begin(), popped.end());
    }
  }

  return indices;
}

/*
1 2 2 3 4 5

[1-1, 2-2, 2-3 3-4, 4-5, 5-6]

itr 1:

temp: [1-1, 2-2, 2-3 3-4, 4-5, 5-6]

popped: [1-1, 2-2, 2-3 3-4, 4-5 ]

max: 4-5

indices: [5]

popped: [0-1 1-2 1-3 2-4 3-5]

temp: [5-6 0-1 1-2 1-3 2-4 3-5]

itr2:

popped: [5-6 0-1 1-2 1-3 2-4]

max: 5-6

indices: [5 6]

....
*/


// O[N^2]

/*
1, 2, 2, 3, 4, 5     1 2 3 4 5 6

itr 1:

x > temp.size -> popped = [1 2 2 3 4]
max_val_itr: 4
max_val: 4
original_idx: 5
indices = [5]
temp = [1 2 2 3]
temp = [0 1 1 2]

temp is not empty -> temp = [5] + [0 1 1 2] = [5 0 1 1 2]

....
*/

/*
  input: arr of ints (queue)
  x iters
  
  pop x ints from front of queue
  max(popped ints) = ?; if n such ints, take the earliest (first encountered); remove it
  popped[i] -= 1 if popped[i] > 0; add back to queue (to the back)
  
  What about popped[i] < 0? Do we decrement or leave it alone? Do we assume all 0 and + ints?
  
  output:
  
  x ints???
  `
  ex:
  
  n = 6
  x = 5
  arr = [1 2 2 3 4 5]
  
  output = [5 6 4 1 2]
  
  itr 1:
  
  pop 5 front -> popped = [1 2 2 3 4] -> arr = [5]
  max(popped) = 4 (idx = 4 + 1 = 5; original arr) -> remove it
  if popped[i] > 0 => decrement by 1`-> popped = [0 1 1 2]
  arr = [5 0 1 1 2]
  
  itr 2:
  
  pop 5 front -> popped = [5 0 1 1 2] -> arr = []
  max(popped) = 5 (idx = 5 + 1 = 6; original arr) -> remove it
  if popped[i] > 0 => decrement by 1`-> popped = [0 0 0 1]
  arr = [0 0 0 1]
  
  itr 3:
  
  pop 5 front -> popped = [0 0 0 1] -> arr = []
  max(popped) = 1 (idx = 3 + 1 = 4; original arr) -> remove it
  if popped[i] > 0 => decrement by 1`-> popped = [0 0 0]
  arr = [0 0 0]
  
  itr 4:
  
  pop 5 front -> popped = [0 0 0] -> arr = []
  max(popped) = 0 -> remove first (idx = 0 + 1 = 1; original arr)
  arr = [0 0]
  
  itr 5: (same as x)
  
  pop 5 front -> popped = [0 0] -> arr = []
  max(popped) = 0 -> remove first (idx = 1 + 1 = 2; original arr) -> remove it
  arr = [0]
  
  end
  
  Data structure: queue with pairs? O[N] space complexity
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
    cout << rightTick << " Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << " Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
  int n_1 = 6;
  int x_1 = 5;
  vector <int> arr_1{1, 2, 2, 3, 4, 5};
  vector <int> expected_1{5, 6, 4, 1, 2 };
  vector <int> output_1 = findPositions(arr_1, x_1);
  check(expected_1, output_1);

  int n_2 = 13;
  int x_2 = 4;
  vector <int> arr_2{2, 4, 2, 4, 3, 1, 2, 2, 3, 4, 3, 4, 4};
  vector <int> expected_2{2, 5, 10, 13};
  vector <int> output_2 = findPositions(arr_2, x_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
