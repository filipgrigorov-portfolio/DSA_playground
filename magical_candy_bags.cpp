#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


void addPieces(std::vector<int> arr, int k, int& sum) {
  if (k-- == 0) {
    return;
  }

  // find max value and idx
  auto max_itr = std::max_element(arr.begin(), arr.end());
  auto idx = std::distance(arr.begin(), max_itr);
  // add to sum
  sum += *max_itr;
  // update value at idx
  arr[idx] = std::floor(arr[idx] / 2);

  addPieces(arr, k, sum);
}

int maxCandies(std::vector<int> arr, int k) {
  int sum = 0;
  addPieces(arr, k, sum);
  return sum;
}



/*
N bags of candy
1 candy: arr[N] pieces

time to eat: 1 min or 60 sec

bag refills after all is eaten

start with x pieces per bag -> eat -> refills with floor(x / 2) pieces

total time to eat: k mins or 60*k sec


How many pieces of candy can I eat in k min?
  
1 min for 1 bag
k min for x bags

x = k bags
  
edge: arr[1], so t_max: 1min
edge: arr[k], so k


anything <= k, return k bags


ex:

5 bags, each bag containss 2 1 7 4 2
  
2 - 1min 1st bag -> 1
1 - 1min 2nd bag -> 0
7 - 1min         -> 3
4 - 1min         -> 2
2 - 1min 5th bag -> 1

Always eat the next maximum bag.

2
1
7 -> 3 -> 1
4 -> 2
2

7 + 4 + 3 = 14

data structure: 

eaten = []
npieces, idx: max(arr)
add npieces to eaten
arr[idx] = floor(npieces / 2)

reiterate
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

  int k_1 = 3;
  vector <int> arr_1{2, 1, 7, 4, 2};
  int expected_1 = 14;
  int output_1 = maxCandies(arr_1, k_1);
  check(expected_1, output_1);

  int k_2 = 3;
  vector <int> arr_2{19, 78, 76, 72, 48, 8, 24, 74, 29};
  int expected_2 = 228;
  int output_2 = maxCandies(arr_2, k_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
