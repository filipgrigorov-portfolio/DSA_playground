#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};

Node* getLast(Node* head) {
  Node* node = head;
  Node* last_node = nullptr;
  while (node != nullptr) {
    last_node = node;
    node = node->next;
  }
  return last_node;
}

Node* getOneBefore(Node* node, Node* end_node) {
  if (!node) {
    return nullptr;
  }

  if (node && node->next && node->next == end_node) {
    return node;
  }

  return getOneBefore(node->next, end_node);
}

Node* getOneAfter(Node* node, Node* end_node) {
  if (!node) {
    return nullptr;
  }

  if (node && node == end_node) {
    return node->next;
  }

  return getOneAfter(node->next, end_node);
}

std::pair<Node*, Node*> sortReverse(Node* head, Node* tail) {
  auto last_node = tail;
  Node* new_head = new Node(last_node->data);
  
  Node* current_end = new_head;

  // When the last node is the same as the head, 
  // on the original linked list, stop the iteration
  while (last_node != head) {
    Node* next_current_end = getOneBefore(head, last_node);
    if (!next_current_end) {
      return std::make_pair(nullptr, nullptr);
    }

    // update new linked list
    Node* new_node = new Node(next_current_end->data);
    current_end->next = new_node;
    current_end = new_node;

    // keep separate count on original linked list to move along
    last_node = next_current_end;
  }

  // remove original pointers (avoid leaking)
  

  // update the head and tail
  head = new_head;
  tail = getLast(new_head);
  return std::make_pair(head, tail);
}

void del(Node* node) {
  if (node && !node->next) {
    delete node;
    return;
  }

  del(node->next);
}

// Add any helper functions you may need here
Node* find_first_node(Node* node) {
  if (!node) {
    return nullptr;
  }

  if (node->data % 2 == 0) {
    return node;
  }

  return find_first_node(node->next);
}

Node* find_last_node(Node* node) {
  if (!node) {
    return nullptr;
  }

  if (node->data % 2 == 0 && (!node->next || node->next->data % 2 != 0)) {
    return node;
  }

  return find_first_node(node->next);
}



Node* reverse(Node *head) {
  // Write your code here
  Node* current_node = head;
  while (1) {
    auto first_node_of_subgraph = find_first_node(current_node);
    if (!first_node_of_subgraph) {
      break;
    }

    auto last_node_of_subgraph = find_last_node(first_node_of_subgraph->next);
    if (!last_node_of_subgraph) {
      break;
    }

    /*
    a b c d 
    c -> b
    
    a -> c
    b -> d
    */

    Node* node_before = getOneBefore(head, first_node_of_subgraph); //a
    Node* node_after = getOneAfter(head, last_node_of_subgraph); //d
    Node* last_node = last_node_of_subgraph;

    auto pair = sortReverse(first_node_of_subgraph, last_node_of_subgraph);

    /*
    pair: 8, 2
    node_before: 1
    node_after: 9

    current_node: 9
    */

    if (node_before) {
      node_before->next = pair.first;
    } else head = pair.first;
    pair.second->next = node_after;

    current_node = last_node->next;
  };

  return head;
}



/*
  linked list -> find subparts neighbouring odd numbers or end of list
  reverse the subparts
  
  last_subpart = []
  function reverse(node, last_subpart):
    if last_subpart is empty and node exists and node is even:
      last_subpart.append(node)
  
    if node exists and node is odd and node.next exists:
      if node.next is even:
        last_subpart.append(node.next)
      return reverse(node.next, last_subpart)
       
    if last_subpart is not empty and node exists and node.next is odd:
      swap elements from back to forth
      last_subpart.clear
      return reverse(node.next, last_subpart)
      
    if last_subpart is not empty and node exists and node.next does not exist:
      swap elements from back to forth
      last_subpart.clear
      return
      
    OR
    
    function find_first_node_of_subpart(node):
      if node does not exist:
        return nullptr
        
      if node is even:
        return node
        
      return find_first_node_of_subpart(node.next)
      
        
    function find_last_node_of_subpart(node):
      if node does not exist:
        return nullptr
        
      if node is odd:
        return node
        
      return find_last_node_of_subpart(node.next)
      
      
    function reverse(node):
      do:
        first_node_of_subpart = find_first_node_of_subpart(rooreturn ;t)
        
        if first_node_of_subpart is nullptr:
          break
        
        if first_node_of_subpart != end_node:
          last_node_of_subpart = find_last_node_of_subpart(first_node_of_subpart.next)
          
          if last_node_of_subpart is nullptr:
            break
          
          reverse_nodes(first_node_of_subpart, last_node_of_subpart)
      while (first_node_of_subpart != nullptr or last_node_of_subpart != nullptr)
      
      return node
*/








// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printLinkedList(Node *head) {
  cout << "[";
  while (head != NULL) {
    cout << head -> data;
    head = head -> next;
    if (head != NULL)
      cout << " ";
  }
  cout << "]";
}

int test_case_number = 1;

void check(Node *expectedHead, Node *outputHead) {
  bool result = true;
  Node *tempExpectedHead = expectedHead;
  Node *tempOutputHead = outputHead;
  while (expectedHead != NULL && outputHead != NULL) {
    result &= (expectedHead -> data == outputHead -> data);
    expectedHead = expectedHead -> next;
    outputHead = outputHead -> next;
  }
  if (!(expectedHead == NULL && outputHead == NULL)) result = false;

  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printLinkedList(tempExpectedHead); 
    cout << " Your output: ";
    printLinkedList(tempOutputHead);
    cout << endl; 
  }
  test_case_number++;
}

Node* createLinkedList(vector<int> arr) {
  Node *head = NULL;
  Node *tempHead = head;
  for (auto &v : arr) {
    if (head == NULL) head = new Node(v), tempHead = head;
    else {
      head -> next = new Node(v);
      head = head -> next;
    }
  }
  return tempHead;
}

int main() {

  Node *head_1 = createLinkedList({1, 2, 8, 9, 12, 16});
  Node *expected_1 = createLinkedList({1, 8, 2, 9, 16, 12});
  Node *output_1 = reverse(head_1);
  check(expected_1, output_1);

  Node *head_2 = createLinkedList({2, 18, 24, 3, 5, 7, 9, 6, 12});
  Node *expected_2 = createLinkedList({24, 18, 2, 3, 5, 7, 9, 12, 6});
  Node *output_2 = reverse(head_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
