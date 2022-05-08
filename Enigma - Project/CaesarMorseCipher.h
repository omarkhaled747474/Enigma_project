#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class CaesarMorseCipher{
public:
void encrypt(string str)
    {
    	cout << "The Encrypted Text is : ";
        for (int i=0 ; (str[i]!='\0') ; i++)
        {
            if (str[i]=='x' || str[i]=='X')
            {
                str[i] = 'a';
            }
            else if (str[i]=='y' || str[i]=='Y')
            {
                str[i] = 'b';
            }
            else if (str[i]=='z' || str[i]=='Z')
            {
                str[i] = 'c';
            }
            else if (str[i]==' ')
            {
                str[i] = ' ';
            }
            else
            {
                str[i] = str[i] + 3;
            }
            cout << textEncode(str[i]);
        }
    }

	string textEncode(char x) {

    x = tolower(x);

  switch (x) { 
  case 'a': 
    return ".- "; 
    break;
  case 'b': 
    return "-... "; 
    break;
  case 'c': 
    return "-.-. ";
	break; 
  case 'd': 
    return "-.. ";
	break; 
  case 'e': 
    return ". ";
	break; 
  case 'f': 
    return "..-. ";
	break; 
  case 'g': 
    return "--. ";
	break; 
  case 'h': 
    return ".... ";
	break; 
  case 'i': 
    return ".. "; 
    break;
  case 'j': 
    return ".--- ";
	break; 
  case 'k': 
    return "-.- ";
	break; 
  case 'l': 
    return ".-.. "; 
    break;
  case 'm': 
    return "-- "; 
    break;
  case 'n': 
    return "-. "; 
    break;
  case 'o': 
    return "--- ";
	break; 
  case 'p': 
    return ".--. ";
	break; 
  case 'q': 
    return "--.- ";
	break; 
  case 'r': 
    return ".-. ";
	break; 
  case 's': 
    return "... "; 
    break;
  case 't': 
    return "- ";
	break; 
  case 'u': 
    return "..- "; 
    break;
  case 'v': 
    return "...- ";
	break; 
  case 'w': 
    return ".-- "; 
    break;
  case 'x': 
    return "-..- "; 
    break;
  case 'y': 
    return "-.-- "; 
    break;
   
  case 'z': 
    return "--.. ";
    break;
    // for space
  case ' ' :
  	return "| ";
  	break;

  default:
	return " ";
	break;
  
  } 
} 

void encryptWithSave(string str)
    {
    	
    	ofstream out("output.txt" , ios::out | ios::app);
    	out <<"Caesar-Morse Encrypted Text : ";
        for (int i = 0 ; ( str[i] != '\0' ) ; i++)
        {
            if (str[i]=='x' || str[i]=='X')
            {
                str[i] = 'a';
            }
            else if (str[i]=='y' || str[i]=='Y')
            {
                str[i] = 'b';
            }
            else if (str[i]=='z' || str[i]=='Z')
            {
                str[i] = 'c';
            }
            else if (str[i]==' ' || str[i] < 65 || str[i] > 122)
            {
                str[i] = ' ';
            }
			else if (str[i] < 65 || str[i] > 122)
			{
				str[i] = ' ';
			}
            else
            {
                str[i] = str[i] + 3; //this is the key of encryption
            }
            
        out << textEncode(str[i]);
        
        }
        out<<endl;
        out.close();
    }
    
void decrypt(string str) { 

  char tr;
  string token;
  vector <string> tokens;
  istringstream tokenStream (str);
  while (getline(tokenStream,token,' ')){
  tokens.push_back(token);
  }
  cout<< "The Decrypted Text is : " ;
  for(int i = 0; i < tokens.size(); i++){
    	
    	if (tokens[i]==".-"){
		
		tr = 'x';
	}
	
	else if (tokens[i]=="-..."){
		
		tr = 'y';
	}
	
	else if (tokens[i]=="-.-."){
		
	    tr = 'z';
	}
	
	else if (tokens[i]=="-.."){
		
		tr='d';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="."){
		
		tr='e';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="..-."){
		
		tr='f';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="--."){
		
		tr='g';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="...."){
		
		tr='h';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".."){
		
		tr='i';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".---"){
		
		tr='j';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="-.-"){
		
		tr='k';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".-.."){
		
		tr='l';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="--"){
		
		tr='m';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="-."){
		
		tr='n';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="---"){
		
		tr='o';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".--."){
		
		tr='p';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="--.-"){
		
		tr='q';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".-."){
		
		tr='r';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="..."){
		
		tr='s';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="-"){
		
		tr='t';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="..-"){
		
		tr='u';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="...-"){
		
		tr='v';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".--"){
		
		tr='w';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="-..-"){
		
		tr='x';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="-.--"){
		
		tr='y';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="--.."){
		
		tr='z';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="|"){
		
		tr=' ';
		}
	
	else
	{
		tr = ' ';
	}
	
	cout << tr;	

} 
}

void decryptWithSave(string str)
    {
  ofstream out("output.txt",ios::out | ios::app);
  char tr;
  string token;
  vector <string> tokens;
  istringstream tokenStream (str);
  while (getline(tokenStream,token,' ')){
  tokens.push_back(token);
  }
  out<< "Caesar-Morse Decrypted Text : " ;
  for(int i = 0; i < tokens.size(); i++){
    	
    	if (tokens[i]==".-"){
		
		tr = 'x';
	}
	
	else if (tokens[i]=="-..."){
		
		tr = 'y';
	}
	
	else if (tokens[i]=="-.-."){
		
	    tr = 'z';
	}
	
	else if (tokens[i]=="-.."){
		
		tr='d';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="."){
		
		tr='e';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="..-."){
		
		tr='f';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="--."){
		
		tr='g';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="...."){
		
		tr='h';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".."){
		
		tr='i';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".---"){
		
		tr='j';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="-.-"){
		
		tr='k';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".-.."){
		
		tr='l';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="--"){
		
		tr='m';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="-."){
		
		tr='n';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="---"){
		
		tr='o';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".--."){
		
		tr='p';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="--.-"){
		
		tr='q';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".-."){
		
		tr='r';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="..."){
		
		tr='s';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="-"){
		
		tr='t';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="..-"){
		
		tr='u';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="...-"){
		
		tr='v';
		tr = tr - 3;
	}
	
	else if (tokens[i]==".--"){
		
		tr='w';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="-..-"){
		
		tr='x';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="-.--"){
		
		tr='y';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="--.."){
		
		tr='z';
		tr = tr - 3;
	}
	
	else if (tokens[i]=="|"){
		
		tr=' ';
	}
		
	else
	{
		tr = ' ';
	}
	
	out<< tr;	

}
        out<<endl;
        out.close();
    }

};