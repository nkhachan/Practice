/*
Make an algorithm that determines if a string has only unique characters
*/
#include <vector>
/*
Chose set because we want to search with O(1)

You could also use an array where the indexes represent the characters
converted to an int and the bool represents if that character was found yet
*/
#include <set>
#include <iostream>


bool verifywithdatastructure(std::string str){
  std::set<char> pastchars;

  for (int i = 0; i < str.length(); ++i){
    // If the character isn't in the string, add it to the set.
    if(pastchars.find(str[i]) == pastchars.end())
      pastchars.insert(str[i]);
    else{
      std::cout << str[i] << std::endl;
      return false;
    }
  }
  return true;
}

bool verifywithoutdatastructure(std::string str){
  return true;
}

int main(){
  std::string str = "hlpme";
  bool val = verifywithdatastructure(str);
  std::cout << val << std::endl;


  return 0;
}
