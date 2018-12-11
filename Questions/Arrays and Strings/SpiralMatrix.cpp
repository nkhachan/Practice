#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

void printSpiral(std::vector<std::vector<int>> matrix){
  int width = matrix[0].size();
  int height = matrix.size();
  int totallayer = ceil(std::min(width, height)/float(2));
  int total = width * height;
  for (int layer = 0; layer < totallayer; ++layer){

    if (total > 0){
      for (int i = layer; i < width-layer; ++i){
        std::cout << matrix[layer][i] << " ";
        total--;
      }
    }

    if (total > 0){
      for (int i = layer + 1; i < height-layer; ++i ){
        std::cout << matrix[i][width-layer-1] << " ";
        total--;
      }
    }

    if (total > 0){
      for (int i = width-layer-2; i >= layer; --i){
        std::cout << matrix[height-layer-1][i] << " ";
        total--;
      }
    }

    if (total > 0){
      for (int i = height-layer-2; i > layer; --i){
        std::cout << matrix[i][layer] << " ";
        total--;
      }
    }
  }
  std::cout << std::endl;

}

int main(){
  std::vector<std::vector<int>> field = { {1,  2,  3,  4,  5,  6},
                                          {7,  8,  9,  10, 11, 12},
                                          {13, 14, 15, 16, 17, 18}
                                        };
  printSpiral(field);
  return 0;
}
