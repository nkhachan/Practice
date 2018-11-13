
struct Node {
  Node *left;
  Node *right;
  int value
}

int maxDepth (Node *node){
  if (node == null){
    return 0;
  } else {
    int rightDepth = maxDepth(node->right);
    int leftDepth  = maxDepth(node->left);

    if (rightDepth > leftDepth){
      return rightDepth;
    } else {
      return leftDepth
    }
  }
}
