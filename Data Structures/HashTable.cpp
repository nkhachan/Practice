/* Each node in the hash table (each bucket)
   is a Linked list.
*/
template <typename K, typename V>
class Node {

  K key;
  V value;
  // Link to next node that mapped to the same value.
  Node* next;

  public :
    Node (const K &key, const V &value) :
    key(key), value(value), next(nullptr) {}

    K getKey() const {
      return key;
    }
    V getValue() const {
      return value;
    }
    Node *getNext() const {
      return next;
    }
    void setValue(V value) {
      Node::value = value;
    }
    void setNext(Node *next) {
      Node::next = next;
    }

};

template <typename K, typename V>
class HashMap {
  // Array of Nodes
  Node<K,V> **arr;
  // Capacity of array
  int capacity;
  // Current size of array
  int size;

  public :
    // Constructor
    HashMap(){
      // Initialize capacity some arbitrary
      capacity = 20;
      // Initialize size
      size = 0;
      // Create array
      arr = new Node<K,V>*[capacity]();
    }

    int hashFunction(K key){
      return  key % capacity;
    }

    V find(K key){
      int location = hashFunction(key);
      Node<K, V> *node = arr[location];
      while (node != nullptr){
        if (node->getKey() == key){
          return node->getValue();
        }
        node = node->getNext();
      }
      return nullptr;
    }

    void insert(K key, V value){
      // Find index where node should be placed
      int location = hashFunction(key);

      // Get the linkedlist at that location
      Node<K, V> *node = arr[location];
      // Keep track of previous Node
      Node<K, V> *prev = nullptr;

      // Search through linked list at location to add on node.
      // Keep track of first null node and node previous to that
      while(node != nullptr && node->getKey() != key){
        prev = node;
        node = node->getNext();
      }

      // If the key doesn't exist in the map
      if (node == nullptr){
        // Add new node
        node = new Node<K, V>(key, value);
        // If this is first element in LL
        if (prev == nullptr){
          arr[location] = node;
        }
        // If not first element in LL
        else {
          prev->setNext(node);
        }
      }
      else{
        // Update value for key "key"
        node->setValue(value);
      }
    }

    void remove(K key){
      int location = hashFunction(key);
      Node<K, V> *node = arr[location];
      // Keep track of previous Node
      Node<K, V> *prev = nullptr;

      while(node != nullptr && node->getKey() != key){
        prev = node;
        node = node->getNext();
      }

      if (node == nullptr){
          return;
      }
      // There is a node with the matching key
      else {
        // First element in LL
        if (prev == nullptr){
          arr[location] = entry->getNext();
        }
        else {
          prev->setNext(entry->getNext());
        }
      }

    }


};
