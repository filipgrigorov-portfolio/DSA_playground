#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


struct Node {
  int data; 
  Node* left ; 
  Node* right; 
  Node() {
    data = 0; 
    left = NULL; 
    right = NULL; 
  }
  Node(int data) {
    this->data = data; 
    this->left = NULL; 
    this->right = NULL; 
  }
};

// Add any helper functions you may need here

bool isLeaf(Node* node) {
    return node && !node->left && !node->right;
}

bool hasLeftChild(Node* node) {
    return node && node->left;
}

bool hasRightChild(Node* node) {
    return node && node->right;
}

bool hasLeftChildLeaf(Node* node) {
    return node && node->left && (!node->left->left && !node->left->right);
}

bool hasRightChildNonLeaf(Node* node) {
    return node && node->right && (node->right->left || node->right->right);
}

bool hasNoLeftChild(Node* node) {
  return node && (!node->left && node->right);
}

// Note: side: 0 (left) or 1 (right)
void findLeftVisibleNodes(Node* node, int side, int& count) {
    if (isLeaf(node)) {
      std::cout << "node " << node->data << " : " << side << std::endl;
      count++;
      return;
    }

    if (!node) {
      return;
    }

    findLeftVisibleNodes(node->left, 0, count);

    if ((hasLeftChild(node) || hasNoLeftChild(node)) && side == 0) {
      std::cout << "node " << node->data << " : " << side << std::endl;
      count++;
    }
    // check for if no left child, we can accept the right node
    if (hasNoLeftChild(node) && hasRightChild(node) && side == 1) {
      std::cout << "node " << node->data << " : " << side << std::endl;
      count++;
    }

    if (hasLeftChildLeaf(node) && hasRightChildNonLeaf(node)) {
        findLeftVisibleNodes(node->right, 1, count);
    }

    if (hasNoLeftChild(node) && hasRightChild(node)) {
      findLeftVisibleNodes(node->right, 1, count);
    }
}

int visibleNodes(Node* root) {
  // Write your code here
  int count = 0;
  findLeftVisibleNodes(root, 0, count);
  return count;
}



/*
  Input: binary tree with N nodes
  Output: Number of visible nodes at the left
   
  function find_left(node, side):
    if node is leaf:
      print node
      count++
      return
      
    find_left(node.left, left)
    
    if node has left child and side is left:
      print node
      count++

    if node has no left child but has right child and is right:
      print node
      count++
      
    if node has a left child that IS a leaf and has a right child that IS NOT a leaf:
      find_left(node.right, right)

    if node has no left child and has a right child:
      find_left(node.right, right)
  
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

  Node* root_1 = new Node(8); 
  root_1->left = new Node(3); 
  root_1->right = new Node(10); 
  root_1->left->left = new Node(1); 
  root_1->left->right = new Node(6); 
  root_1->right->right = new Node(14); 
  root_1->left->right->left = new Node(4); 
  root_1->left->right->right = new Node(7); 
  root_1->right->right->left = new Node(13); 
  int expected_1 = 4;
  int output_1 = visibleNodes(root_1);
  check(expected_1, output_1);

  Node* root_2 = new Node(10); 
  root_2->left = new Node(8);
  root_2->right = new Node(15);
  root_2->left->left = new Node(4);
  root_2->left->left->right = new Node(5);
  root_2->left->left->right->right = new Node(6);
  root_2->right->left = new Node(14);
  root_2->right->right = new Node(16);
  int expected_2 = 5;
  int output_2 = visibleNodes(root_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}