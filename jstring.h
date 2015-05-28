#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace JCPP {
  std::string test() {
    return "Test";
  }

  std::string GetStringBetweenStrings(std::string data, std::string startDelim, std::string endDelim) {
    unsigned first = data.find(startDelim);
    unsigned last = data.find(endDelim);
    if (first != std::string::npos && last != std::string::npos) {
        std::string strNew = data.substr(first + startDelim.length(), last - first);
        return strNew;
    }
    else {
        return NULL;
    }
  }

  std::vector<std::string> GetStringsBetweenStrings(std::string data, std::string startDelim, std::string endDelim) {
    std::vector<std::string> stringsToReturn;
    unsigned int first = data.find(startDelim);
    unsigned int last = data.find(endDelim, first + 1);
    unsigned int startLoc = 0;

    while (first != std::string::npos && last != std::string::npos) {
      std::string strNew = data.substr(first + startDelim.length(), last - first - endDelim.length());
      std::cout << strNew;
      stringsToReturn.push_back(strNew);
      startLoc = last;
      first = data.find(startDelim, startLoc);
      last = data.find(endDelim, first + 1);
    }
    std::cout << "\n===\n";
    return stringsToReturn;
  }
}
