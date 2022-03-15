#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


int getBillionUsersDay(vector <float> growthRates) {
  if (growthRates.size() == 1) {
    return std::log(1e9) / std::log(growthRates[0]);
  }

  int target_user_base = 1e9;
  int current_total_user_base = 0;
  // Good initial guess
  int t = std::log(1e9) / std::log(*std::min_element(growthRates.begin(), growthRates.end()) / growthRates.size());
  while (current_total_user_base <= target_user_base) {
    current_total_user_base = 0;
    t++;
    for (auto idx = 0; idx < growthRates.size(); ++idx) {
      current_total_user_base += std::pow(growthRates[idx], t);
    }
  }
  return t;
}




/*
  
  input: N apps with diff growth rates
  t: days
  @ any t, g^t users where g is growth rate
  
  * apps launched at the same time
  * one user per one app at a time
  
  simple case: 2 apps
  
  app 1: n users
  app 2: m users
  
  number of total users for all apps=?
  
  Namely, (n + m) = ?
  
  Given: 
  * num_users = 1e9 = x
  
    x = g^t
    log(x) = tlog(g)
    t = log(x) / log(g)
  
  * N apps
  * g^t users at any given t using an app
  * one user one app
  * num_growth_rates = num_apps = N
  
  ex:
  
  G = [1.5]
  t = floor(log(x) / log(G[0])) = floor(log(1e9) / log(G[0])) = 51
    
    
  G: [1.01 1.02]
  
  1e6 = g1^t + g2^t
  
  t1 = t2 = t
  t_tot = 2t

  X = 1e9
  x = 0
  t = 0
  while x <= X:
    t += 1
    x = 0
    for each xi for each app:
      x += gi^t
      
      
  test:
  
  x: 0
  t: 1
  
  x: x1 + x2
  is x <= 1e9: if yes we are done and if no, we continue
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

  vector <float> test_1{1.1, 1.2, 1.3};
  int expected_1 = 79;
  int output_1 = getBillionUsersDay(test_1);
  check(expected_1, output_1);

  vector <float> test_2{1.01, 1.02};
  int expected_2 = 1047;
  int output_2 = getBillionUsersDay(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
