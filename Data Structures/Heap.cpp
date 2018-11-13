/*
* MinHeap Implementation
*         0
*       /   \
*      3     6
*    /  \   /
*   5   9  8
*
*  Breadth First List
*  Array : 0 3 6 5 9 8
*
*  Follows Rules:
*  Parent Node is at index (i - 1)/2
*  Left Child Node is at index (2*i) + 1
*  Right Child Node is at index (2*i) + 2
*
*/

class MinHeap {
  int capacity;  // maximum possible size of heap
  int heap_size; // current size
  int *arr       // pointer to array of elements

  public :
    MinHeap(int capacity) : capacity(capacity){}

    int parent(int i){
      return (i - 1)/2;
    }

    int leftchild(int i){
      return ((2*i) + 1)
    }

    int rightchild(int i){
      return ((2*i) + 2)
    }

    void swap (int &a, int &b){
      int temp = a;
      a = b;
      b = temp;
    }

    // Time complexity : Worst Case O(log(n))
    void insertKey(int k){
      // At capacity
      if (heap_size == capacity){ return; }

      // Put element at the end
      ++heap_size;
      int i = heap_size - 1;
      arr[i] = k;

      // Bubble up till you reach the top
      // or parent is larger than child
      while (i!=0 && arr[parent(i)] > arr[i]){
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
      }
    }

}
