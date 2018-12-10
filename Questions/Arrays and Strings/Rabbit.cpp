#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

bool validPoint(std::vector<std::vector<int>> field, std::pair<int, int> point){
  int l = field.size();
  int w = field[0].size();
  if (point.first > l-1 || point.first < 0 || point.second > w-1 || point.second < 0){
    return false;
  }
  return true;
}

std::pair<int, int> findMaxPlace(std::vector<std::vector<int>> field, std::pair<int, int> p1, std::pair<int, int> p2){
  int l = field.size();
  int w = field[0].size();
  if (!validPoint(field, p1)){ return p2; }
  else if (!validPoint(field, p2)){ return p1; }
  else if (!validPoint(field, p1) && !validPoint(field, p2)){
    return std::make_pair(-1, -1);
  }
  else if (field[p1.first][p1.second] > field[p2.first][p2.second]){
    return p1;
  } else {
    return p2;
  }
}

std::pair<int, int> findMiddle(std::vector<std::vector<int>> &field){
  int l = field.size();
  int w = field[0].size();
  bool weven = (l%2) == 0;
  bool leven = (w%2) == 0;

  if (!weven && !leven){ return std::make_pair((w-1)/2, (l-1)/2);}
  else if (!weven && leven){ return findMaxPlace(field, std::make_pair((l-2)/2, (w-1)/2), std::make_pair(l/2, (w-1)/2));}
  else if (weven && !leven){ return findMaxPlace(field, std::make_pair((l-1)/2, w/2), std::make_pair((l-1)/2, (w-2)/2));}
  else { return findMaxPlace(field, findMaxPlace(field, std::make_pair((l-2)/2, w/2),  std::make_pair((l-2)/2, (w-2)/2)),
        findMaxPlace(field, std::make_pair(l/2, w/2),  std::make_pair(l/2, (w-2)/2))); }
}


std::pair<int, int> findNext(std::vector<std::vector<int>> &field, std::pair<int, int> currLocation){
  int y = currLocation.first;
  int x = currLocation.second;
  std::pair<int, int> next = findMaxPlace(field, findMaxPlace(field, std::make_pair(y, x + 1),  std::make_pair(y, x - 1)),
        findMaxPlace(field, std::make_pair(y + 1, x),  std::make_pair(y - 1, x)));
  return next;
}
/**
 Arguments :
    field A matrix of all the number of carrots on each of the tiles.
**/
std::vector<std::pair<int, int>> findPath(std::vector<std::vector<int>> &field){
  int sum = 0;
  std::pair<int, int> point = findMiddle(field);
  std::pair<int, int> next = findNext(field, point);
  std::pair<int, int> badpoint = std::make_pair(-1, -1);

  while (next != badpoint && field[next.first][next.second] != 0){
    sum += field[point.first][point.second];
    field[point.first][point.second] = -1;
    point = next;
    next = findNext(field, point);
  }
  sum += field[point.first][point.second];
}

int main(){
  std::vector<std::vector<int>> field = {{5, 7, 8, 6, 3},
                                         {0, 0, 7, 0, 4},
                                         {4, 6, 3, 4, 9},
                                         {3, 1, 0, 5, 8}};
  findPath(field);
  return 0;
}
