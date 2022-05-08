using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class AffineCipher
{
    private:
        int day;
        int month;

    public:
        int d;
        int m;
        int Pointer {0};
        int modMultiInverse {0};
        string InputText;
        ofstream affineTxtFile;
        string EncryptedText;
        string decryptedText;
        AffineCipher(){
            d = 0;
            m = 0;
            InputText = "";
        }
        void setDay();
        void setMonth();
        int getDay();
        int getMonth();
        bool isUpperCase(string InputText);
        string toUpperCase(string InputText);
        string affineEncrypt(string InputText);
        string affineDecrypt(string EncryptedText);
        string affineEncrypt(string InputText , fstream &affineTxtFile);
        string affineDecrypt(string EncryptedText , fstream &affineTxtFile);

}; 

void AffineCipher::setDay(){
    cin >> d;
    day = d;
}

void AffineCipher::setMonth(){
    cin >> m;
    month = m;
}

int AffineCipher::getDay(){
    return day;
}

int AffineCipher::getMonth(){
    return month;
}

bool AffineCipher::isUpperCase(string InputText){
	
    int counter {0};
    for (int ch {0}; InputText[ch] != '\0'; ch++)
    {
        if (InputText[ch] >= 65 && InputText[ch] <= 90)
        {
            counter ++;
        }
        
         return counter == InputText.length() ? true : false;
    }
    
}

string AffineCipher::toUpperCase(string InputText){
    
    if (isUpperCase(InputText) != true)
        transform(InputText.begin(), InputText.end(),InputText.begin(),::toupper);
        string Text = InputText;
    
    return Text;
}

string AffineCipher::affineEncrypt(string InputText)
{   
   string EncryptedText = "";  
    for (int i {0}; InputText[i] != '\0'; i++) 
    { 
        if(InputText[i] < 65 || InputText[i] > 122) 
            EncryptedText += ' ';
        else if(InputText[i] != ' ')  
            EncryptedText = EncryptedText +  (char) ((((getDay() * (InputText[i] - 'A') ) + getMonth()) % 26) + 'A'); 
        else
            EncryptedText += InputText[i];      
    } 

    return EncryptedText; 

}

string AffineCipher::affineDecrypt(string EncryptedText)
{   
    
    for (int i {0}; i < 26; i++) 
    { 
        Pointer = (getDay() * i) % 26; 
          
        if (Pointer == 1)           // Check if ( a * i ) % 26 == 1, then i will be the multiplicative inverse of a  
        {  
            modMultiInverse = i; 
        } 
    } 
    for (int i {0}; i < EncryptedText.length(); i++) 
    { 
        if(EncryptedText[i] != ' ') 
            InputText = InputText + (char) (((modMultiInverse * ((EncryptedText[i] + 'A' - getMonth())) % 26)) + 'A'); 
        else    
            InputText += EncryptedText[i];  
    } 
    return InputText;
}

string AffineCipher::affineEncrypt(string InputText , fstream &affineTxtFile)       // Overloaded Method to Save the Encrypted output in a text file
{   
   string EncryptedText = "";  
    for (int i {0}; InputText[i] != '\0'; i++) 
    {  
        if(InputText[i] < 65 || InputText[i] > 122)
            EncryptedText += ' ';
        else if(InputText[i] != ' ')  
            EncryptedText = EncryptedText +  (char) ((((getDay() * (InputText[i] - 'A') ) + getMonth()) % 26) + 'A'); 
        else
            EncryptedText += InputText[i];       
    } 

    affineTxtFile.open("output.txt" , ios::out | ios::app);
    affineTxtFile << "Affine Encrypted Text : " << EncryptedText << " , Day => " << d << " , Month => " << m << "\n";
    affineTxtFile.close();
    cout << "Done! The Encrypted Text has been Saved in a text File\n" << endl;
}

string AffineCipher::affineDecrypt(string EncryptedText , fstream &affineTxtFile)       // Overloaded Method to Save the Decrypted Output in a text file 
{
    for (int i {0}; i < 26; i++) 
    { 
        Pointer = (getDay() * i) % 26; 
          
        if (Pointer == 1)       
        {  
            modMultiInverse = i; 
        } 
    } 
    for (int i {0}; i < EncryptedText.length(); i++) 
    { 
        if(EncryptedText[i] != ' ') 
            InputText = InputText + (char) (((modMultiInverse * ((EncryptedText[i] + 'A' - getMonth())) % 26)) + 'A'); 
        else    
            InputText += EncryptedText[i];  
    } 

    affineTxtFile.open("output.txt" , ios::out | ios::app);
    affineTxtFile << "Affine Decrypted Text : " << InputText << " , The Day was => " << d << " , The Month was => " << m <<"\n";
    affineTxtFile.close();
    cout << "Done! The Decrypted Text has been Saved in a text File\n" << endl;
}
