using namespace std;
#include <fstream>
#include <iostream>
#include <bitset>

class Convertor
{

public:

  string original, ascii , binary;
  ofstream ConvTxtFile;

  string FromStringToASCII(string original)
  {
    char x;
    string ascii = "";
    for (int i = 0; i < original.length(); ++i)
    {
      x;
      x = original.at(i);
      cout << int(x);
    }
    return ascii;
  }

  void FromASCIIToString(string ascii)
  {
	
    int n = 0; 
    char x;
    for (int i = 0; i < ascii.length(); i++) { 
  
        n = n * 10 + (ascii[i] - '0'); 
  
        if (n >= 32 && n <= 122) { 
  
            x = (char) n;     // x is a character in the String
            cout << x;
            n = 0; 
        } 
    }
  }

  string FromStringToBinary(string original)
  {
    string binary = "";
    for (int i = 0; i < original.length(); ++i)
    {
      binary += (bitset<8>(original[i])).to_string();
    }

    ConvTxtFile.open("output.txt" , ios::out | ios::app);
    ConvTxtFile << "Binary From Text : " <<binary << "\n";
    ConvTxtFile.close();
    
    return binary;
  }

  string FromBinaryTString(string binary)
  {
    string original = "";
    for (int i = 0; i < binary.length(); i += 8)
    {
      string SingleChar = "";
      for (int j = i; j < i + 8; j++)
      {
        SingleChar += binary[j];
      }
      int num = 1, final = 0;
      for (int j = 7; j >= 0; --j)
      {
        int val = num *
                  (SingleChar[j] - '0');
        num *= 2;
        final += val;
      }
      char c = (char) final;
      original += c;
    }
    
    ConvTxtFile.open("output.txt" , ios::out | ios::app);
    ConvTxtFile << "Text From Binary : " << original << "\n";
    ConvTxtFile.close();
    
    return original;
  }

};
