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

  Node* rightRotate(Node* node){
    // Save new "root"
    Node *newroot = node->left;
    // Move Leaf
    Node *leaf = newroot->right;

    // Make original root right to
    // the new root
    newroot->right = node;
    // Move the leaf from new root
    // to the old root
    node->left = leaf;

    // Update Height of new root
    newroot->height = max(newroot->left->height, newroot->right->height) + 1;
    // Update Height of the old root
    node->height = max(node->left->height, node->right->height) + 1;

    return newroot;
  }

  Node* leftRotate(Node* node){
    // Save new "root"
    Node *newroot = node->right;
    // Move Leaf
    Node *leaf = newroot->left;

    // Make original root right to
    // the new root
    newroot->left = node;
    // Move the leaf from new root
    // to the old root
    node->right = leaf;

    // Update Height of new root
    newroot->height = max(newroot->left->height, newroot->right->height) + 1;
    // Update Height of the old root
    node->height = max(node->left->height, node->right->height) + 1;

    return newroot;
  }


  int getbalance(Node* node){
    if (node != nullptr){
      return (node->left->height - node->right->height);
    }
    return nullptr
  }


  Node* insert(int value, Node* node){
    // If tree is empty
    if (node == nullptr){
      node = new Node(value);
    }

    // If value is less than current node
    // then insert to the left
    else if (x < node->value){
      node->left = insert(value, node->left);
    }

    // If value is greater than current node
    // then insert to the right
    else if (x > node->value){
      node->right = insert(value, node->right);
    }

    // Left Left
    // balance is positive for left leaning
    if (key < node->left->key && balance > 1){
      return rightRotate(node);
    }

    // Right Right
    if (key > node->right->key && balance < -1){
      return leftRotate(node);
    }

    // Left Right
    if (key > node->left->key && balance > 1){
      node->left = leftRotate(node);
      return rightRotate(node);
    }

    // Right Left
    if (key < node->right->key && balance < -1){
      node->right = rightRotate(node);
      return leftRotate(node);
    }

    return node;
  }


}
