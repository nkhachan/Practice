/* Each node in the hash table (each bucket)
   is a Linked list.
*/
template <type K, type V>
class Node {

  K key;
  V value;
  // Link to next node that mapped to the same value.
  Node* next;

  public :
    Node (const K &key, const V &value) :
    key(key), value(value), next(NULL) {}

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

}


/* Hash Function to map the Key to an Index in the array.
*/

template <typename K>
struct HashFunction {
    unsigned long operator()(const K& key) const {
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
    }
};
