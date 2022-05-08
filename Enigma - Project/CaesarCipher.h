#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CaesarCipher {

public:
    ofstream CaesarTxtFile;
    
    char* CaesarEncrypt(char str[])
    {
        for (int i = 0 ; (str[i]!='\0') ; i++)
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
                str[i] = str[i] + 3;    // this is the key of encryption
            }
        }        
        return str;
    }


    char* CaesarDecrypt(char str[])
    {
        for (int i = 0 ; (str[i]!='\0') ; i++)
        {
            if (str[i]=='a' || str[i]=='A')
            {
                str[i] = 'x';
            }
            else if (str[i]=='b' || str[i]=='B')
            {
                str[i] = 'y';
            }
            else if (str[i]=='c' || str[i]=='C')
            {
                str[i] = 'z';
            }
            else if (str[i]==' ')
            {
                str[i] = ' ';
            }
            else
            {
                str[i] = str[i] - 3;    // this is the key of decryption
            }
        }
        return str;
    }

    void CaesarEncryptSave(char str[])
    {
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
        }
        cout << "Done! The Encrypted Text has been saved in a Text file" << endl;
        CaesarTxtFile.open("output.txt", ios::out | ios::app);
        CaesarTxtFile << "Caesar Encrypted Text : " << str << "\n";
        CaesarTxtFile.close();
    }

    void CaesarDecryptSave(char str[])
    {
        for (int i=0 ; (str[i]!='\0') ; i++)
        {
            if (str[i]=='a' || str[i]=='A')
            {
                str[i] = 'x';
            }
            else if (str[i]=='b' || str[i]=='B')
            {
                str[i] = 'y';
            }
            else if (str[i]=='c' || str[i]=='C')
            {
                str[i] = 'z';
            }
            else if (str[i]==' ')
            {
                str[i] = ' ';
            }
            else
            {
                str[i] = str[i] - 3;  
            }
        }
        cout << "Done! The Decrypted Text has been saved in a Text file" << endl;
        CaesarTxtFile.open("output.txt", ios::out | ios::app);
        CaesarTxtFile << "Caesar Decrypted Text : " << str << "\n";
        CaesarTxtFile.close();
    }
};