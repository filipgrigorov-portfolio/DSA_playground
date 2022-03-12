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

/*  
  assign head to be end
  go through head until end - 1
  add end - 1 to end.next
  go through head until end - 2
  add end - 2 to (end - 1).next
  .
  .
  .
  go through head until end - n
  add end - n to (end - n - 1).next

  until end - n which is the same as head (until we reach head)

  function reverse(head)
  new_head = getLast(head)
  current_end = new_head
  while current_end is not head:
    next_current_end = getOneBefore(current_end)                        // node before current_end
    if next_current_end is nullptr:
      return head                                                       // fail gracefully
    current_end.next = next_current_end
    current_end = next_current_end
  return new_head

  def getOneBefore(node, end_node):
    if node is None:
      return None

    if node is not None and node.next is not None and node.next == end_node:
      return node

    return getOneBefore(node.next, end_node)
*/

Node* getOneBefore(Node* node, Node* end_node) {
  if (!node) {
    return nullptr;
  }

  if (node && node->next && node->next == end_node) {
    return node;
  }

  return getOneBefore(node->next, end_node);
}

Node* reverse(Node *head) {
  auto last_node = getLast(head);
  Node* new_head = new Node(last_node->data);
  
  Node* current_end = new_head;

  // When the last node is the same as the head, 
  // on the original linked list, stop the iteration
  while (last_node != head) {
    Node* next_current_end = getOneBefore(head, last_node);
    if (!next_current_end) {
      return head;
    }

    // update new linked list
    Node* new_node = new Node(next_current_end->data);
    current_end->next = new_node;
    current_end = new_node;

    // keep separate count on original linked list to move along
    last_node = next_current_end;
  }

  return std::move(new_head);
}

void del(Node* node) {
  if (node && !node->next) {
    delete node;
    return;
  }

  del(node->next);
}


// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printLinkedList(Node *head) {
  cout << "[";
  while (head != nullptr) {
    cout << head -> data;
    head = head -> next;
    
    if (head != nullptr)
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
  Node *head = nullptr;
  Node *tempHead = head;
  for (auto &v : arr) {
    if (head == nullptr) head = new Node(v), tempHead = head;
    else {
      head -> next = new Node(v);
      head = head -> next;
    }
  }
  return tempHead;
}

int main() {

  Node *head_1 = createLinkedList({1, 2, 8, 9});
  Node *expected_1 = createLinkedList({9, 8, 2, 1});
  Node *output_1 = reverse(head_1);
  check(expected_1, output_1);

  del(output_1);
}
