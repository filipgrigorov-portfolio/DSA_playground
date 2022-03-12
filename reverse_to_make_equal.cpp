#include<bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std; 

// Add any helper functions you may need here

bool areTheyEqual1(vector<int>& array_a, vector<int>& array_b){
  // Write your code here
  std::sort(array_a.begin(), array_a.end());
  std::sort(array_b.begin(), array_b.end());
  return array_a == array_b;
}

bool areTheyEqual(vector<int>& array_a, vector<int>& array_b){
  // Write your code here
  for (auto i = 0; i < array_a.size(); ++i) {
    for (auto j = 0; j < array_b.size(); ++j) {
      if (array_a[i] == array_b[j]) {
        std::swap(array_b[i], array_b[j]);
        break;
      }
    }
  }
  return array_a == array_b;
}

// O[n] * O[n] + O[1] = O[n^2]

/*
  Input: 2 arrays of equal len
  Output: A = B (make B equal to A)
  
  A = [1, 2, 3, 4] <=> [0, 1, 2, 3]
  B = [1, 4, 3, 2] <=> [0, 3, 2, 1]
  
  Make sure all numbers in A are present in B
  Map indices in B corresponding to A
  Swap pairs of corresponding indices:
  
   A[1] = 2
   B[3] = 2 <-> B[1]
   
   for each element in A:
      find equivalent in B:
        [val, idx_B]
        swap(B[idx_B], B[idx_A])
    return A == B
    
    OR
    
    count = 0
    sort(A)
    for i=0 to N-1:
      if A[i] == B[i]:
        count++
        skip
      find equivalent in B:
        swap(B[idx_B], B[idx_A])
        count++
     return A == B

     OR

     sort(A)  O[NlogN]
     sort(B)  O[NlogN]
     B == A   O[1] // if we hash
*/







// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

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
  vector <int> array_a_1{1, 2, 3, 4};
  vector <int> array_b_1{1, 4, 3, 2};
  bool expected_1 = true;
  bool output_1 = areTheyEqual(array_a_1, array_b_1); 
  check(expected_1, output_1); 

  vector <int> array_a_2{1, 2, 3, 4};
  vector <int> array_b_2{1, 4, 3, 3};
  bool expected_2 = false;
  bool output_2 = areTheyEqual(array_a_2, array_b_2); 
  check(expected_2, output_2); 


  // Add your own test cases here
  
  return 0; 
}
