#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

void findFirstSmaller(int targetMoney, vector<int>& denominations, int& idx) {
  if (idx < 0) {
    idx = denominations.size() / 2;
  } else if (targetMoney > denominations[idx]) {
    idx = idx + (denominations.size() - idx) / 2;
  } else if (targetMoney < denominations[idx]) {
    idx /= 2;
  }
  
  if (targetMoney == denominations[idx]) {
    return;
  }

  if (denominations.size() % 2 != 0)  {
    idx++;
  }

  if (idx == 0 || idx == denominations.size() - 1) {
    if (denominations[idx] > targetMoney) {
      idx = -1;
    }
    return;
  }

  findFirstSmaller(targetMoney, denominations, idx);
}

/*


[5 10 25 100 200]
94

idx: 2
call func()

idx: 2
? 94 > 25: yes
idx: 2 + (2 - 2)  / 2 = 2

*/


bool canGetExactChange(int targetMoney, vector<int>& denominations){
  int idx = -1;
  findFirstSmaller(targetMoney, denominations, idx);

  if (idx < 0) {
    return (targetMoney > 0) ? false : true;
  }

  targetMoney %= denominations[idx];
  return canGetExactChange(targetMoney, denominations);
}


/*
  input:
  
  arr = [denominations]
  
  output:
  
  if possible to return exact change
  
  Is the den array always sorted?
  
  ex:
  
  den: [5 10 25 100 200]
  change: 94
  
  94 - 25 = 69
  69 - 25 = 44
  44 - 25 = 19
  19 - 10 = 9
  9 - 5 = 4
  4
  
  94 % 25 = 19
  19 % 10 = 9
  9 % 5 = 4
  4
  
  common divisor of den is 5 and 94 does not have this common divisor
  
  ex:
  
  den: [4 17 29]
  change: 75
  
  75 / 4 = 18.75
  75 / 17 = 4.41...
  75 / 29 = 2.586...
  
  29 + 29 + 17 = 58 + 17 = 75
  
  75 - 29 = 46
  46 - 29 = 17
  17 - 17 = 0
  
  
  75 % 29 = 17
  17 % 17 = 0
  
  Assumption: array is not sorted

  function findNextLargest(x, arr, idx):
    if idx == -1:
        idx = arr.size / 2
      if arr[idx] < x:
        findNextLargest(x, arr, idx + 1)
    return

  test:

  arr: [4 17 29]
  x: 29

  it 0:

  idx: 3 / 2 = 1
  ? arr[1] < x <=> 17 < 29 yes

  findNextLargest(x, arr, 2)

  it 1:

  idx: 2
  ? arr[2] < x <=> 29 < 29 no
  return

  arr: [4 17 29]
  x: 4



  sort(denominations)
  function canGetExactChange(targetMoney, denominations):
    idx = -1
    findNextLargest(targetMoney, denominations, idx)
    
    if idx == -1: // No number greater than targetMoney
      return false if targetMoney > 0 else true
      
    targetMoney = targetMoney % denominations[idx]
    canGetExactChange(targetMoney, denominations)
    
  test:
  
  [4 17 29]
  
  it 0:
  
    idx = 2
    targetMoney: 75 % denominations[2] = 75 % 29 = 17
    
  it 1:
      
     idx = 1
     targetMoney: 17 % denominations[1] = 17 % 17 = 0
     
  it 2:
      
      idx = -1
      return true
*/








// These are the tests we use to determine if the solutio


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
  int target_1 = 94;
  vector<int> arr_1{5, 10, 25, 100, 200};
  bool expected_1 = false;
  bool output_1 = canGetExactChange(target_1, arr_1); 
  check(expected_1, output_1);
  
  // Testcase 2
  int target_2 = 75;
  vector<int> arr_2{4, 17, 29};
  bool expected_2 = true;
  bool output_2 = canGetExactChange(target_2, arr_2); 
  check(expected_2, output_2); 

  // Add your own test cases here
  
  return 0; 
}
