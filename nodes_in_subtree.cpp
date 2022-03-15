#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

class Node {
public:
  int val;
  vector<Node*> children;
  
  Node() {
    val = 0;
    children = vector<Node*>();
  }
  
  Node(int _val) {
    val = _val;
    children = vector<Node*>();
  }
  
  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

struct Query {
  int u; 
  char c; 
};

// Add any helper functions you may need here
Node* findNode(Node* node, int idx) {
  if (node && node->val == idx) {
    return node;
  }

  Node* found_node = nullptr;
  for (const auto& child : node->children) {
    found_node = findNode(child, idx);
    if (found_node) {
      break;
    }
  }

  return found_node;
}

void countNodesInSubtree(Node* node, char ch, std::string s, int& count) {
  if (!node) {
    return;
  }

  if (s[node->val - 1] == ch) {
    count++;
  }

  for (const auto& child : node->children) {
    countNodesInSubtree(child, ch, s, count);
  }
}

vector<int> countOfNodes(Node* root, vector<Query> queries, string s) {
  std::vector<int> outputs;
  for (auto idx = 0; idx < queries.size(); ++idx) {
    const auto node_index = queries[idx].u;
    const auto ch = queries[idx].c;

    auto subroot = findNode(root, node_index);
    if (!subroot) {
      continue;
    }

    int count = 0;
    countNodesInSubtree(subroot, ch, s, count);
    outputs.push_back(count);
  }
  
  return outputs;
}

/*
  query: 2 'b'
  subroot: 'b' with children 'a' and 'c'

  ? 'b' none: no
  does 'b' has 'b': yes
  count: 1

  for each child:

  'a'
  ! 'a' does not have 'b'
  children are none: exit


  'c'
  similar path
*/


/*
  input:
  
  tree containing a string of len N -> number of nodes = N for each char of string
  
  output:
  
  given a query = [u, c], count all the nodes with root having the data u, that have char s
  
  find the node with idx = u
  DTS from left to right, to count all the nodes having char c, including the split node
  return the counted nodes
  
  function findNode(node, idx):
    if node is none:
      return none
    
    if node.data = idx:
      return node
      
    for each child in node.children:
      found_node = findNode(child, idx)
      if found_node:
        return found_node
        
   function countNodesInSubtree(root, char, str, count):
      if root is None:
        return count
        
      if str[root.data] == char:
        count += 1
        
      for each child in root.children:
        countNodesInSubtree(child, char, str, count)
        
   function countOfNodes(root, queries, str):
      outputs = []
      for each query in queries:
         idx, char = query
         subroot = findNode(root, idx)
         
         if subroot is None:
            continue
            
         count = 0
         outputs.append(countNodesInSubtree(subroot, char, str, count))
       return outputs


    test:

    string s_2 = "abaacab"; // 1  2 3 7  4 5 6
    Node *root_2 = new Node(1); 
    root_2->children.push_back(new Node(2)); 
    root_2->children.push_back(new Node(3)); 
    root_2->children.push_back(new Node(7)); 
    root_2->children[0]->children.push_back(new Node(4)); 
    root_2->children[0]->children.push_back(new Node(5)); 
    root_2->children[1]->children.push_back(new Node(6));  
    vector<Query> queries_2{{1,'a'}, {2, 'b'}, {3, 'a'}};

    findNode: Node.val = b
    b
    children: a c




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
  int n_1 = 3, q_1 = 1;
  string s_1 = "aba";
  Node *root_1 = new Node(1);
  root_1->children.push_back(new Node(2)); 
  root_1->children.push_back(new Node(3));  
  vector<Query> queries_1{{1,'a'}};
  vector<int> output_1 = countOfNodes(root_1, queries_1, s_1); 
  vector<int> expected_1 = {2};
  check(expected_1, output_1); 
  
  // Testcase 2
  int n_2 = 7, q_2 = 3;
  string s_2 = "abaacab"; // 1  2 3 7  4 5 6  a  bab aca
  Node *root_2 = new Node(1); 
  root_2->children.push_back(new Node(2)); 
  root_2->children.push_back(new Node(3)); 
  root_2->children.push_back(new Node(7)); 
  root_2->children[0]->children.push_back(new Node(4)); 
  root_2->children[0]->children.push_back(new Node(5)); 
  root_2->children[1]->children.push_back(new Node(6));  
  vector<Query> queries_2{{1,'a'}, {2, 'b'}, {3, 'a'}};
  vector<int> output_2 = countOfNodes(root_2, queries_2, s_2); 
  vector<int> expected_2 = {4, 1, 2};
  check(expected_2, output_2); 

  // Add your own test cases here
  
}