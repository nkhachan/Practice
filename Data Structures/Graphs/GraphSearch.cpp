#include <iostream>

struct Node {
  int value;
  bool visited;
  Node[] adjacent;
};


// Breadth First Search
void BFsearch (Node node){
  if (node == nullptr){ return; }
  // Visit node
  std::cout << node.value << std::endl;
  child.visited = true;
  for (Node child : node.adjacent){
    if (!child.visited){
      BFsearch(child)
    }
  }
}


// Depth First Search
// NOT RECURSIVE, USE QUEUE!
void DFsearch (Node node){
  queue <int> q;

  // Put root into queue
  node.visited = true;
  q.push(node);

  // Go through the queue
  // and look at each of their children
  // enqueue them, and dekete the
  // original node
  while (!queue.empty()){
    Node n = queue.front();
    queue.pop();

    // Visit node
    std::cout << n.value << std::endl;

    for (Node child : n.adjacent){
      if (!child.visited){
        child.visited = true;
        queue.push(child);
      }
    }
  }
}
