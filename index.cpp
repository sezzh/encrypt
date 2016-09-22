#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<char> original_alphabet = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
  'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

vector<char> Get_Encrypt_Array(char letter) {

  vector<char> aux_array;

  bool flag = true;
  for (size_t i = 0; i < original_alphabet.size(); i++) {
    size_t j = i + 1;
    if (original_alphabet[i] == letter) {
      aux_array.push_back(original_alphabet[i]);
      while (flag) {
        aux_array.push_back(original_alphabet[j]);
        j++;
        if (j == original_alphabet.size()) {
          flag = false;
        }
      }
      for (size_t h = 0; h < i; h++) {
        aux_array.push_back(original_alphabet[h]);
      }
    }
  }

  return aux_array;
}


char Encrypt_Letter(char letter_to_ecrypt, int position,
                        string encrypt_key) {
  char encrypt_letter = ' ';
  vector<char> encrypt_array = Get_Encrypt_Array(encrypt_key[position]);
  for (size_t i = 0; i < original_alphabet.size(); i++) {
    if (original_alphabet[i] == letter_to_ecrypt) {
      encrypt_letter = encrypt_array[i];
    }
  }
  return encrypt_letter;
}

char Decrypt_Letter(char letter_to_ecrypt, int position,
                        string encrypt_key) {
  char decrypt_letter = ' ';



  return decrypt_letter;
}


string Encrypt_Message(string encrypt_key, string message) {
  size_t j = 0;
  for (size_t i = 0; i < message.length(); i++) {
    if (i < encrypt_key.length()) {
      j = i;
    } else {
      j = 0;
    }
    message[i] = Encrypt_Letter(message[i], j, encrypt_key);
  }
  return message;
}

string Decrypt_Message(string encrypt_key, string message) {
  return " ";
}


int main() {
  string encrypt_key = "HILLARY";
  string word_to_encrypt = "";

  cout << "ingresa la clave de encriptacion" << endl;
  cin >> encrypt_key;
  encrypt_key = encrypt_key.erase(encrypt_key.find_last_not_of(" \n\r\t") + 1);
  cout << "ingresa la palabra a encriptar c:" << endl;
  cin >> word_to_encrypt;
  word_to_encrypt = word_to_encrypt.erase(
    word_to_encrypt.find_last_not_of(" \n\r\t") + 1
  );
  transform(
    word_to_encrypt.begin(), word_to_encrypt.end(), word_to_encrypt.begin(),
    ::toupper
  );
  transform(encrypt_key.begin(), encrypt_key.end(), encrypt_key.begin(),
  ::toupper
);

  cout << "palabra a encriptar: " << word_to_encrypt << endl;
  cout << "con llave de encrypt: " << encrypt_key << endl;

  string result = Encrypt_Message(encrypt_key, word_to_encrypt);

  cout << "resultado: " << endl;
  cout << result << endl;
  return 0;
}
