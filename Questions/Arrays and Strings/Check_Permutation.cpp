#include <iostream>
#include <algorithm>
#include <vector>
/*
Make an algorithm that checks if a string is a permutation of another string
which means that one has all the same letters as the other
*/

void printArray(std::vector<int> arr){
  for (int i = 0; i < arr.size(); ++i){
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

/*O(n)
Array that maps characters to the frequency, and increase the frequency
from one string and decrease frequency based on other string
*/
bool checkpermutation(std::string s1, std::string s2){
  if (s1.length() != s2.length()){
    return false;
  }

  std::vector<int> letters(128);
  int length = s1.length();
  for (int i = 0; i < length; ++i){
    int x = (int)s1[i] - 48;
    letters[x]++;
  }

  for (int i = 0; i < length; ++i){
    int x = (int)s2[i] - 48;
    letters[x]--;
    if (letters[x] < 0){
      return false;
    }
  }
  return true;
}

/*O(nlogn)*/
bool checkpermutationbysorting(std::string s1, std::string s2){
  if (s1.length() != s2.length()){
    return false;
  }

  /*Each of the sorts are O(nlogn) */
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());

  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
  if (s1 == s2)
    return true;
  return false;
}

int main(){
  std::string s1 = "dogdd";
  std::string s2 = "goddd";

  std::cout << checkpermutation(s1, s2) << std::endl;
  return 0;
}
