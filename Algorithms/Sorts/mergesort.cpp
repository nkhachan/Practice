#include <iostream>
#include <vector>

void printVector(std::vector<int> arr){

  for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << std::endl;

}


void merge(std::vector<int> &arr, int beg, int mid, int end){

  // Find sizes of first and second half
  int firstsize = mid - beg + 1;
  int secondsize = end - mid;

  std::vector<int> Left(firstsize);
  std::vector<int> Right(secondsize);
  // Copy first half over
  for (int i = 0; i < firstsize; ++i){
    Left[i] = arr[beg + i];
  }
  // Copy second half over
  for (int i = 0; i < secondsize; ++i){
    Right[i] = arr[mid + 1 +  i];
  }

  // Indexes
  int firstindex = 0;
  int secondindex = 0;
  int mergedindex = beg;

  // While there are stil elements to loop through in each
  // array
  while ((firstindex < firstsize) && (secondindex < secondsize)){

    // Put the lower element in the current space
    if (Left[firstindex] <= Right[secondindex]){
      arr[mergedindex] = Left[firstindex];
      firstindex++;
    } else {
      arr[mergedindex] = Right[secondindex];
      secondindex++;
    }
    ++mergedindex;
  }

  // Copy over Left
  while (firstindex < firstsize){
    arr[mergedindex] = Left[firstindex];
    firstindex++;
    mergedindex++;
  }

  // Copy over Right
  while (secondindex < secondsize){
    arr[mergedindex] = Left[secondindex];
    secondindex++;
    mergedindex++;
  }

}


void mergesort(std::vector<int> &arr, int beg, int end){
  if (beg < end){
    // Find middle
    int mid = (beg + (end - beg))/2;

    // First Half
    std::cout << beg << " " << mid << std::endl;
    mergesort(arr, beg, mid);
    // Second half
    std::cout << mid + 1 << " " << end << std::endl;
    mergesort(arr, mid + 1, end);
    // Merge the two halves
    merge(arr, beg, mid, end);
  }
}

int main(){

  std::vector<int> vect{ 3, 2, 1};
  printVector(vect);
  mergesort(vect, 0, vect.size() - 1);
  printVector(vect);
  return 0;
}
