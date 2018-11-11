/**
* AVL Tree is a type of self-balancing tree
* where the difference of the left and
* right subtrees isn't more than one
* for any of the nodes
*/

/* A single node in the tree
*
*/
class Node {

  int value;
  // Link to left and right children.
  Node* left;
  Node* right;
  // Height of the node
  int height;

  public :
    Node (int value):value(value), left(nullptr), right(nullptr), height(0){}
};

class AVLTree {

  Node* root;

  int height(Node* node){
    if (node){
      return node->height;
    }
    return nullptr;
  }

  // Private (Recursive) Functions

  Node* insert(int value, Node* node){
    // If tree is empty
    if (node == nullptr){
      node = new Node(value);
    }
    // If value is less than current node
    // then insert to the left
    else if (x < node->value){
      node->left = insert(value, node->left);
      // Re-balance
      if (height(node->left)-height(node->right) == 2){

      }
    }
    // If value is greater than current node
    // then insert to the right
    else if (x > node->value){
      node->right = insert(value, node->right);
      // Re-balance
      if (height(node->right)-height(node->left) == 2){
        if (x < node->right->data){
          
        }
      }
    }
    return node;
  }


}
