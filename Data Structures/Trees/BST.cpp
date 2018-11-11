#include <iostream>

/* A single node in the tree
*
*/
class Node {

  int value;
  // Link to left and right children.
  Node* left;
  Node* right;

  public :
    Node (int value):value(value), left(nullptr), right(nullptr), height(0){}
};


class BST {

  Node* root;

  void preOrderTraversal(Node* node){
    if (node == nullptr){
      return;
    } else {
      // Parent
      std::cout << node->value << std::endl;
      // Left
      preOrderTraversal(node->left);
      // Right
      preOrderTraversal(node->right);
    }
  }

  void inOrderTraversal(Node* node){
    if (node == nullptr){
      return;
    } else {
      // Left
      inOrderTraversal(node->left);
      // Parent
      std::cout << node->value << std::endl;
      // Right
      inOrderTraversal(node->right);
    }
  }

  void postOrderTraversal(Node* node){
    if (node == nullptr){
      return;
    } else {
      // Left
      postOrderTraversal(node->left);
      // Right
      postOrderTraversal(node->right);
      // Parent
      std::cout << node->value << std::endl;
    }
  }

  

}
