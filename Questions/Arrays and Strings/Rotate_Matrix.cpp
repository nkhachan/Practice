#include <iostream>
#include <vector>
/*
Make an algorithm that rotates a NxN matrix where each image is 4 bytes
Rotate by 90 degrees

Start by rotating each of the layers

Outer layer
x x x x
x o o x
x o o x
x x x x

Inner layer
o o o o
o x x o
o x x o
o o o o
*/

const int COLUMN_SIZE = 4;

void printMatrix(std::vector<std::vector<int>> matrix){
  for (int i = 0; i < matrix.size(); ++i){
    for (int j = 0; j < matrix.size(); ++j){
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

/*

a x x b
x x x x
x x x x
d x x c

temp   = a
pos(a) = d
pos(d) = c
pos(c) = b
pos(b) = a

*/
bool rotate(std::vector<std::vector<int>> &matrix){
  /* Ensure square and not empty*/
  if ((matrix[0].size() != matrix.size()) && matrix.size() == 0)
    return false;
  int length = matrix.size();

  // Iterate through each layer
  for (int layer = 0; layer < length/2; ++layer){

    int last = length - layer - 1;
    // Iterate through each element on a side
    for (int elmt = layer; elmt < last; ++elmt){

      int offset = elmt - layer;

      // Save "a"
      int temp = matrix[layer][elmt];

      // Move d -> a
      matrix[layer][elmt] = matrix[last - offset][layer];

      // Move c -> d
      matrix[last - offset][layer] = matrix[last][last - offset];

      // Move b -> c
      matrix[last][last - offset] = matrix[elmt][last];

      // Move a -> b
      matrix[elmt][last] = temp;
    }
  }
}


int main(){
  std::vector<std::vector<int>> matrix =
  {
     {1,2,3,4},
     {5,6,7,8},
     {9,10,11,12},
     {13,14,15,16}
  };
  printMatrix(matrix);
  rotate(matrix);
  printMatrix(matrix);
  return 0;
}
