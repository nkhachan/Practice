#include <iostream>
#include <vector>


int binarysearch(std::vector<int>arr, int beg, int end, int target){
  if (end >= beg){

    // Calculate Middle
    int mid = (beg + end)/2;
    // If element is found
    if (arr[mid] == target){
      return mid;
    }
    // Array is sorted
    // If less than middle, search left otherwise
    // search right
    if (target < arr[mid]){
      return binarysearch(arr, beg, mid - 1, target);
    } else {
      return binarysearch(arr, mid + 1, end, target);
    }
  }
  // Not found
  return -1;
}

int main(){
  std::vector<int> vect{ 3, 2, 1, 5, 6, 2, 6, 7, 9};
  int index = binarysearch(vect, 0, vect.size() - 1, 9);
  std::cout << index << std::endl;
  return 0;
}
