#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#ifdef _WINDOWS
#include <atlstr.h>
#endif

namespace JCPP {
  static std::string test() {
    return "Test";
  }

  static std::string GetStringBetweenStrings(std::string data, std::string startDelim, std::string endDelim) {
    size_t first = data.find(startDelim);
    size_t last = data.find(endDelim);
    if (first != std::string::npos && last != std::string::npos) {
        std::string strNew = data.substr(first + startDelim.length(), last - first);
        return strNew;
    }
    else {
        return NULL;
    }
  }

  static std::string StripWhitespace(std::string data) {
    unsigned int indexer = 0;

    while (indexer < data.size()) {
      if (data[indexer] == ' ') {
        data.erase(indexer, 1);
      } else {
        indexer++;
      }
    }

    return data;
  }

  static std::string StripLeadingCharacter(std::string data, char car) {
    int posToStart = 0;

    for (int i = 0; i < data.size(); i++) {
      if (data[i] != car) {
        break;
      }
      else {
        posToStart++;
      }
    }

    data = data.substr(posToStart, std::string::npos);
    return data;
  }

  static std::string StripLeadingWhitespace(std::string data) {
    return StripLeadingCharacter(data, ' ');
  }

  static std::string StripTrailingWhitespace(std::string data) {
    int posToEnd = data.size() - 1;
    for (int i = data.size() - 1; i >= 0; i--) {
      if (data[i] != ' ') {
        posToEnd = i;
        break;
      } else {
        posToEnd--;
      }
    }

    data = data.substr(0, posToEnd + 1);
    return data;
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
          size_t loc = data.find(substring);
          stringsToReturn.push_back(data.substr(0, loc));
          data.erase(0, loc + substring.length());
      }

      if (data != "") {
          stringsToReturn.push_back(data);
      }

      return stringsToReturn;
  }

  static std::string StringToLower(std::string data) {
    for (int i = 0; i < data.size(); i++) {
      data[i] = tolower(data[i]);
    }

    return data;
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

  static std::string ULLToString(unsigned long long aULL) {
    std::stringstream ss;
    ss << aULL;
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
	  size_t first = data.find(substring);
	  if (first != std::string::npos) {
        return data.substr(first + substring.length(), std::string::npos);
	  } else {
		    return "NOTFOUND";
	  }
  }

  static std::string GetStringBeforeSubstring(std::string data, std::string substring) {
    size_t first = data.find(substring);
    if (first != std::string::npos) {
      return data.substr(0, first);
    }
    else {
      return "NOTFOUND";
    }
  }

  static std::string GetNumbersFromString(std::string data) {
    std::string returnData = "";

    for (int i = 0; i < data.size(); i++) {
      if (data[i] > 47 && data[i] < 58) {
        returnData += data[i];
      }
    }

    return returnData;
  }

  static std::string WStringToString(std::wstring wString) {
    std::string returnValue(wString.begin(), wString.end());
    return returnValue;
  }

#ifdef _WINDOWS
  std::string ToSTDS(CString cString)
  {
    // Convert a TCHAR string to a LPCSTR
    CT2CA pszConvertedAnsiString(cString);
    // construct a std::string using the LPCSTR input
    std::string strStd(pszConvertedAnsiString);
    return strStd;
  }

  CString ToCS(std::string stdString)
  {
    CString cs(stdString.c_str());

    return cs;
  }
#endif

#ifdef _UNICODE
  static const wchar_t* StringToProperChar(std::string someString) {
    wchar_t returnData[512];
    mbstowcs(returnData, someString.c_str(), 512);

    return returnData;
  }

  static const std::wstring StringToProperString(std::string someString) {
    wchar_t returnData[512];
    mbstowcs(returnData, someString.c_str(), 512);

    std::wstring returnString = std::wstring(returnData);
    return returnString;
  }

  static std::string ProperCharToString(wchar_t* someCString) {
    std::wstring ws(someCString);
    std::string test(ws.begin(), ws.end());

    return test;
  }
#else

  static const char* StringToProperChar(std::string someString) {
    return someString.c_str();
  }

  static const std::string StringToProperString(std::string someString) {
    return someString;
  }

  static std::string ProperCharToString(char* someCString) {
    return std::string(someCString);
  }
#endif
}
