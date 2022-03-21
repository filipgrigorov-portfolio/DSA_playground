#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
    int val;
    std::vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

bool isProcessed(Node* node, const std::vector<Node*>& processed) {
    return std::find_if(processed.begin(), processed.end(), 
        [node](Node* elem) { return elem->val == node->val; }) != processed.end();
}

bool isProcessed(int idx, const std::vector<Node*>& processed) {
    return std::find_if(processed.begin(), processed.end(), 
        [&idx](Node* node) { return node->val == idx; }) != processed.end();
}

bool areNeighboursAllProcessed(Node* node, const std::vector<Node*>& processed) {
    for (const auto& neighbour : node->neighbors) {
        if (!isProcessed(neighbour, processed)) {
            return false;
        }
    }
    return true;
}

void allocateNodes(Node* node, std::vector<Node*>& allocated) {
    // If node has all its neighbours visited, return
    if (isProcessed(node->val, allocated) && areNeighboursAllProcessed(node, allocated)) {
        return;
    }
    
    // Otherwise, allocate a new node and add it allocated
    if (!isProcessed(node->val, allocated)) {
        allocated.push_back(new Node(node->val));
    }
    
    for (const auto& neighbour : node->neighbors) {
        if (!isProcessed(neighbour->val, allocated)) {
            allocateNodes(neighbour, allocated);
        }
    }
}

Node* findByIdx(const std::vector<Node*>& arr_of_nodes, int idx) {
    auto found = std::find_if(arr_of_nodes.begin(), arr_of_nodes.end(), 
        [&idx](Node* node) { return node->val == idx; });
    return found != arr_of_nodes.end() ? *found : nullptr;
}

void assignNeighbours(Node* node, const std::vector<Node*>& allocated, std::vector<Node*>& visited) {
    // for each node, find equivalent in allocated, then, find the neighbouring nodes
    // get them, as well, from allocated, and add them to the new node (pointerwise)
    // The goal would be to have the allocated contain all the nodes with assigned neighbours

    // if all neighbours are visited, return
    if (isProcessed(node, visited) && areNeighboursAllProcessed(node, visited)) {
        return;
    }

    // otherwise, continue assigning recursevly
    if (!isProcessed(node, visited)) {
        visited.push_back(node);
    }
    
    Node* found_equivalent = findByIdx(allocated, node->val);
    if (found_equivalent) {
        if (found_equivalent->neighbors.empty()) {
            for (const auto& neighbour : node->neighbors) {
                Node* equivalent_neighbour = findByIdx(allocated, neighbour->val);
                found_equivalent->neighbors.push_back(equivalent_neighbour);
            }
        }
    }

    for (const auto& neighbour : node->neighbors) {
        if (!isProcessed(neighbour, visited)) {
            assignNeighbours(neighbour, allocated, visited);
        }
    }
}

Node* cloneGraph(Node* node) {
    std::vector<Node*> allocated;
    // Allocate each node first
    allocateNodes(node, allocated);
    // Assign neighbours from the allocated nodes
    std::vector<Node*> visited;
    assignNeighbours(node, allocated, visited);
    return findByIdx(allocated, node->val);
}

/*

    input:
    connected undirected graph
    
    node: val + neighbours
    
    adjacency lis: {i : j, k, ..., n}
    
    ex:
    
    graph: [ [2,4], [1,3], [2,4], [1,3] ]
    
    N = 4, so 4 nodes in the graph
    
    
    new node start at node=1
    
    we search for its children, and create new nodes, if they do not exist
    
    repeat for each child
    
    pseudo:
    
    
    function cloneGraph(graph, node, visited):
        if node is none or node in visited:
            return
        
        if node has children:
            graph = new(node.val, node.children)
        else:
            graph = new(node.val)
        visited.append(node)
        
        // call the function on each neighbour
        for each neighbour in node:
            cloneGraph(graph.neighbour, neighbour)
    
    function cloneGraph(node):
        // this is the first node
        graph = none
        visited = []
        cloneGraph(graph, node, visited)
        return graph
*/

int main(void) {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);

    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Node* graph = cloneGraph(node1);
    
    return EXIT_SUCCESS;
}
