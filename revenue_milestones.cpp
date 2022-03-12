#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


std::vector<int> getMilestoneDays1(std::vector<int> revenues, std::vector<int> milestones) {
  std::vector<int> output;
  int count = 0, sum = 0;
  for (auto idx = 0; idx < revenues.size(); ++idx) {
    sum += revenues[idx];

    // check if we have passed all the milestones
    if (count > milestones.size() - 1) {
      break;
    }

    for(auto k = count; k < milestones.size(); ++k) {
      if (sum >= milestones[k]) {
        output.push_back(idx + 1);
        count++;
      } else break;
    }
  }

  // check if we have any uncompleted milestones
  if (count < milestones.size() - 1) {
    const auto diff = milestones.size() - 1 - count;
    for (auto idx = 0; idx < diff; ++idx) {
      output.push_back(-1);
    }
  }

  return output;
}

std::vector<int> getMilestoneDays(std::vector<int> revenues, std::vector<int> milestones) {
  std::vector<int> output;
  for (auto m = 0; m < milestones.size(); ++m) {
    int sum = 0;
    for (auto r = 0; r < revenues.size(); ++r) {
      sum += revenues[r];

      if (sum >= milestones[m]) {
        output.push_back(r + 1);
        break;
      }
    }

    if (sum == 0) {
      output.push_back(-1);
    }
  }
  return output;
}

// O[NK], so quadratic


/*
  ex:

  r = [100 200 300 400 500]
  m = [300 800 1000 1400]

  o = []

  i: 0
  sum: 100

  i: 1
  sum: 300
  m[0]: 300
  o: [2]
  count: 1

  ...

  i: 3
  sum: 1000
  m[1]: 800
  o: [2 4]
  count: 2

  m[2]: 1000
  o: [2 4 4]
  count: 3

  we would need to check if a single r[i] surpasses multiple m[i]'s
*/


/*
  intput: 
  
  revenue = [rev_d1, rev_d2, ... , rev_dn] N
  milestones = [m1, m2, ..., mn] K
  
  output:
  
  K array: Ki is the day, milestones[i] = sum(revenue[: x]) where x is to be determined
  
  ex:
  
  revenue: [10 20 30 40 50 60 70 80 90 100] - 0 1 2 3 4 5 6 7 8 9
  
  milestones: [100 200 500]
  
  output: [4 6 10]
  
  milestones[0] = 100 -> 10 + 20 + 30 + 40 = 100 -> idx -> 4
  
  milestones[1] = 200 -> ... + 50 + 60 = 100 + 50 + 60 = 210 > 200 -> idx -> 6
  
  milestones[2] = 500 -> ... + 70 + 80 + 90 + 100 = 210 + 70 + 80 + 90 + 100 = 400 + 70 + 80 = 500 + 50 = 550 > 500 -> idx = 10
  
  output = [4 6 10]

  function get_milestone_days():
    output = []; sum = 0; count = 0
    for i=0 to N-1:
      sum += revenue[i]
      if count >= milestones.size:
        break

      for i=count to K-1:
        if sum >= milestones[count]:
          output.append(i + 1)
          count += 1

    if count < milestones.size:
      diff = milestones.size - 1 - count
      for i=0 to diff:
        output.append(-1)

    return output

  test:

  output = []

  i: 0 (idx = 1)
  revenue[i]: 10
  sum: 10
  milestones[0]: 100

  ...

  i: 3 (idx = 4)
  revenue[i]: 40
  sum: 100
  count >= milestones.size: no
  sum >= milestones[0]: yes
  output: [4]
  count: 1

  ...

  O[N] time complexity
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
  // Testcase 1
  int n_1 = 5, k_1 = 4; 
  vector <int> revenues_1{100, 200, 300, 400, 500};
  vector <int> milestones_1{300, 800, 1000, 1400};
  vector <int> expected_1{2, 4, 4, 5};
  vector <int> output_1 = getMilestoneDays(revenues_1, milestones_1);
  check(expected_1, output_1);

  // Testcase 2
  int n_2 = 6, k_2 = 5; 
  vector <int> revenues_2{700, 800, 600, 400, 600, 700};
  vector <int> milestones_2{3100, 2200, 800, 2100, 1000};
  vector <int> expected_2{5, 4, 2, 3, 2};
  vector <int> output_2 = getMilestoneDays(revenues_2, milestones_2);
  check(expected_2, output_2);
  
  // Add your own test cases here
  
}
