#include <iostream>
#include <string>
#include <unordered_map>

void enterPair(std::unordered_map<std::string, std::string>&hashmap, const std::string& s1, 
const std::string& s){
  hashmap[s1] = s;
}

void lookUp(const std::unordered_map<std::string, std::string>&hashmap,const std::string& line){
  std::unordered_map<std::string, std::string>::const_iterator got = hashmap.find(line);
  
  if (got != hashmap.end())
    std::cout << got->second << std::endl;
  else
    std::cout<< "Not found" << std::endl;
}


int main() {

  std::string delimiter = "=";
  std::string s;
  std::string s1;
  size_t pos = 0;
  std::unordered_map<std::string, std::string>hashmap;

  for(std::string line; std::getline(std::cin, line);){
    s = line;
    /* check for empty input */
    if (line.empty()) 
      continue;
    if (line.at(0) == '!'){
      s1 = line.substr(1);
      hashmap.erase(s1);
      continue;
    }
    pos = s.find(delimiter);
    /* empty key */
    if (pos == 0)
      continue;
    if (pos != std::string::npos){
      s1 = s.substr(0, pos);
      std::unordered_map<std::string, std::string>::const_iterator got = hashmap.find(s1);
      /* if no entry yet */
      if (got == hashmap.end()) {
        s.erase(0, pos + delimiter.length());
        /* empty value */
        if (s.empty())
          continue;
        enterPair(hashmap, s1, s);
      }
      else
      /* ignore second entry if key already exists*/
        continue;
    }
    else 
      lookUp(hashmap, line);
  }
}