#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

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

  std::vector<std::string> GetStringsSeparatedBySubstring(std::string data, std::string substring) {
      std::vector<std::string> stringsToReturn;
      while (data.find(substring) != std::string::npos) {
          unsigned int loc = data.find(substring);
          stringsToReturn.push_back(data.substr(0, loc));
          data.erase(0, loc + substring.length());
      }

      if (data != "") {
          stringsToReturn.push_back(data);
      }

      return stringsToReturn;
  }

  // Type Conversions
  std::string IntToString(int anInt) {
    std::stringstream ss;
    ss << anInt;
    std::string aString = ss.str();
    return aString;
  }

  std::string FloatToString(float aFloat) {
    std::stringstream ss;
    ss << aFloat;
    std::string aString = ss.str();
    return aString;
  }

  std::string BoolToString(bool aBool) {
    if (aBool) {
        return "1";
    }
    else {
        return "0";
    }
  }

  std::string SizetToString(size_t aSizeT) {
    std::stringstream ss;

    ss << aSizeT;
    return ss.str();
  }

  std::string GetStringAfterSubstring(std::string data, std::string substring) {
	  unsigned int first = data.find(substring);
	  if (first != std::string::npos) {
        return data.substr(first + substring.length(), std::string::npos);
	  } else {
		    return "NOTFOUND";
	  }
  }

  std::string GetStringBeforeSubstring(std::string data, std::string substring) {
    unsigned int first = data.find(substring);
    if (first != std::string::npos) {
      return data.substr(0, first);
    }
    else {
      return "NOTFOUND";
    }
  }
}
