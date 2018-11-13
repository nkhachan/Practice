#include <iostream>
#include <vector>

void printVector(std::vector<int> arr){
  for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << std::endl;
}

void swap (int &spot1, int &spot2){
    int temp = spot1;
    spot1 = spot2;
    spot2 = temp;
}

int partition(std::vector<int> &arr, int beg, int end){
  // Start with end, can also start with beginning, end, random,
  // or find the median and make that your pivot.
  int pivot = arr[end];
  // Index where pivot should be
  int pivotIndex = beg;
  // Loop through all elements
  for (int i = beg; i < end; ++i){
    // If the elment is less than the pivot, then
    // move it before the pivotIndex by swapping it
    // and then move the pivotIndex over, so that it points
    // back to a place where "higher than pivot" elements exist
    if (arr[i] <= pivot){
      swap(arr[pivotIndex], arr[i]);
      pivotIndex++;
    }
  }
  // Move pivot to the point where it belongs
  swap(arr[pivotIndex], arr[end]);
  return pivotIndex;
}


void quicksort(std::vector<int> &arr, int beg, int end){
  if (beg < end){
    // Index of Partition that is at correct place, meaning
    // All elements before it are less and all after are more.
    int part = partition(arr, beg, end);
    // Sort the first half
    quicksort(arr, beg, part - 1);
    // Sort the second half
    quicksort(arr, part + 1, end);
  }
}


int main(){

  std::vector<int> vect{ 3, 2, 1};
  printVector(vect);
  quicksort(vect, 0, vect.size() - 1);
  printVector(vect);
  return 0;
}
