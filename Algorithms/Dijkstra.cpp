/**
* Code for Dijkstra's Algorithm
* (Graph from CTCI)
* Graph represented as adjacency matrix
*/
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <queue>

#define NUM_NODES 9
int int_max = std::numeric_limits<int>::max();
#define n int_max


// Priority queue object

class Node {
  public :
    int node;
    int priority;

    // Constructor
    Node (int node, int priority) : node(node), priority(priority) {}

    bool operator< (const Node &otherNode) const{
      return this->priority < otherNode.priority;
    }
};

/**
* Returns the shortest length from 0 -> i
**/
int djikstras(int graph[][NUM_NODES]){
  std::vector <int> weight(9);
  std::vector <int> prevNode(9);
  std::vector <int> remainingNodes = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  std::priority_queue <Node> nextNode;

  // Initialize length for a node (from initial "0" node) to "infinity"
  weight[0] = 0;
  for (int i = 1; i < NUM_NODES; ++i){
    weight[i] = int_max;
  }

  while (remainingNodes.size() != 0){

    // Find minimum path from first point
    auto minimum = std::min_element(weight.begin(), weight.end());
    int currNode = *minimum;
    std::cout << *minimum << std::endl;

    for (int i = 0; i < NUM_NODES; ++i){

      if (graph[currNode][i] < n){
        
        int weight = graph[currNode][i];

        // Add weight
        if (weight[i] == int_max){
          weight[i] = weight;
        } else {
          weight[i] += weight;
        }
        prevNode[i] = currNode;

        // Add all the adjacent nodes to priority queue
        Node *node = new Node(i, graph[currNode][i]);
        nextNode.push(*node);
      }

    }
  }



  //


}


int main(){

  int graph [NUM_NODES][NUM_NODES] =
  {
    {n, 5, 3, n, 2, n, n, n, n}, // a
    {n, n, n, 2, n, n, n, n, n}, // b
    {n, 1, n, 1, n, n, n, n, n}, // c
    {1, n, n, n, n, n, 2, 1, n}, // d
    {1, n, n, n, n, n, n, 4, 7}, // e
    {n, 3, n, n, n, n, 1, n, n}, // f
    {n, n, 3, n, n, n, n, n, 2}, // g
    {n, n, 2, n, n, 2, 2, n, n}, // h
    {n, n, n, n, n, n, n, n, n}  // i
  };

  djikstras(graph);
  return 0;
}
