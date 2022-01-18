// Assn3-Encode-RyanMatthews.cpp 
#include "pch.h"
using namespace std;

string decryptedCaesarMessage;
char upperkey;
char lowerKey;

string xorEncryptDecrypt(string toEncryptDecrypt) {
    string output = toEncryptDecrypt;

    for (int i = 0; i < toEncryptDecrypt.size(); i++)
        output[i] = toEncryptDecrypt[i] ^ upperkey;

    return output;
}

string caesarEncryptDecrypt(string text, int shift) {
    string decryptedMessage = "";
    for (int i = 0; i < text.length(); i++) {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            decryptedMessage += char(int(text[i] + shift - 65) % 26 + 65);

        // Encrypt Lowercase letters
        else
            decryptedMessage += char(int(text[i] + shift - 97) % 26 + 97);
    }

    // Return the resulting string
    decryptedCaesarMessage = decryptedMessage;
    return decryptedMessage;
}


// This function generates the key in
// a cyclic manner until it's length is not
// equal to the length of original text
string generateKey(string str, string key) {
    int x = str.size();

    for (int i = 0;; i++) {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

int main() {
    int input;
    int input1;
    string encryptedMessage;
    string decryptedMessage;
    string message;
    int shift;
    bool enteredString = false;
    bool encryptString = false;
    string key;
    string keyword;

    do {
        cout << "\nPlease make your selection from the following" << endl;
        cout << "1. Enter the string data" << endl << "2. Encrypt the string" << endl << "3. Decrypt the string" << endl
            << "4. Exit" << endl << endl;
        cout << "Your selection: ";
        cin >> input;

        if (input == 1) {
            cout << "You Selected 1. Enter the string data" << endl;
            cout << "Please enter your original message: ";
            cin >> message;
            enteredString = true;
            cout << endl;

        }
        else if (input == 2) {
            cout << "You Selected 2. Encrypt the string" << endl;
            if (enteredString == false) {
                cout
                    << "No original data was found. Please ensure that you enter the string prior to encrypting or decrypting."
                    << endl;
            }
            else {
                encryptString = true;
                cout << "1. XOR Cypher \n2. Caesar Cypher" << endl;
                cout << "Your selection: ";
                cin >> input1;
                if (input1 == 1) {
                    //you have to have a lowercase message to work
                    cout << "You Selected 1. XOR Cypher" << endl;

                    cout << "Please enter a single letter for a key" << endl;
                    cin >> lowerKey;
                    upperkey = toupper(lowerKey);
                    cout << "Here is your string cyphered with XOR" << endl;
                    encryptedMessage = xorEncryptDecrypt(message);
                    cout << "Encrypted:" << encryptedMessage << "\n";

                }
                else if (input1 == 2) {
                    cout << "You Selected 2. Caesar Cypher" << endl;                 
                    cout << "How much would you like to shift (number)" << endl;
                    cin >> shift;
                    cout << "Text : " << message;
                    cout << "\nShift: " << shift;
                    decryptedCaesarMessage = caesarEncryptDecrypt(message, shift);
                    cout << "\nCipher: " << caesarEncryptDecrypt(message, shift);
                }              
                else if (input != 3) {
                    cout << "Invalid entry" << endl;
                }
            }
        }
        else if (input == 3) {
            cout << "You Selected 3. Decrypt the string" << endl << endl;
            if (encryptString == false) {
                cout
                    << "No original data was found. Please ensure that you enter the string prior to encrypting or decrypting." << endl;
            }
            else {
                cout << "How do you want to decrypt" << endl << "1. XOR Cypher " << endl << "2. Caesar Cypher " << endl;                 
                cout << "Your selection: ";
                cin >> input1;
                if (input1 == 1) {
                    cout << "You Selected 1. XOR Cypher" << endl;
                    cout << "Here is your string decrypt with XOR" << endl;
                    decryptedMessage = xorEncryptDecrypt(encryptedMessage);
                    cout << "Encrypted: " << encryptedMessage << endl;
                    cout << "Decrypted: " << decryptedMessage << endl;

                }
                else if (input1 == 2) {
                    int invertedShift = shift * -1;
                    cout << "You Selected 2. Caesar Cypher" << endl;
                    cout << "Here is your string decrypt with Caesar" << endl;
                    cout << "Your Shift" << shift << endl;
                    cout << "decrypt with Caesar: " << caesarEncryptDecrypt(decryptedCaesarMessage, invertedShift); cout << endl;

                }               
            }
        }
        else if (input != 4) {
            cout << "Invalid entry" << endl;
        }
    } while (input != 4);
    cout << "You Selected 4. Exit" << endl;
    cout << "Thank you." << endl;
    return 0;
}