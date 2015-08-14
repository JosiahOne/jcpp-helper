#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

namespace JCPP {
  static std::string test() {
    return "Test";
  }

  static std::string GetStringBetweenStrings(std::string data, std::string startDelim, std::string endDelim) {
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


  static std::vector<std::string> GetStringsBetweenStrings(std::string data, std::string startDelim, std::string endDelim) {
    std::string thing1 = data;
    std::string thing2 = startDelim;
    std::string thing3 = endDelim;
    
    std::vector<std::string> stringsToReturn;
    std::string::size_type first = data.find(startDelim);
    std::string::size_type last = data.find(endDelim, first + startDelim.length());
    std::string::size_type startLoc = 0;

    while (first != std::string::npos && last != std::string::npos) {
      std::string strNew = data.substr(first + startDelim.length(), last - first - 1);
      std::cout << strNew;
      stringsToReturn.push_back(strNew);
      startLoc = last;
      first = data.find(startDelim, startLoc);
      last = data.find(endDelim, first + startDelim.length());
    }
    std::cout << "\n===\n";
    return stringsToReturn;
  }

  static std::vector<std::string> GetStringsSeparatedBySubstring(std::string data, std::string substring) {
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
  static std::string IntToString(int anInt) {
    std::stringstream ss;
    ss << anInt;
    std::string aString = ss.str();
    return aString;
  }

  static std::string FloatToString(float aFloat) {
    std::stringstream ss;
    ss << aFloat;
    std::string aString = ss.str();
    return aString;
  }

  static std::string BoolToString(bool aBool) {
    if (aBool) {
        return "1";
    }
    else {
        return "0";
    }
  }

  static std::string SizetToString(size_t aSizeT) {
    std::stringstream ss;

    ss << aSizeT;
    return ss.str();
  }

  static std::string GetStringAfterSubstring(std::string data, std::string substring) {
	  unsigned int first = data.find(substring);
	  if (first != std::string::npos) {
        return data.substr(first + substring.length(), std::string::npos);
	  } else {
		    return "NOTFOUND";
	  }
  }

  static std::string GetStringBeforeSubstring(std::string data, std::string substring) {
    unsigned int first = data.find(substring);
    if (first != std::string::npos) {
      return data.substr(0, first);
    }
    else {
      return "NOTFOUND";
    }
  }
}
