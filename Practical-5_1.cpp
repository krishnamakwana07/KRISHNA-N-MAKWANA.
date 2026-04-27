#include <iostream>
#include <string>
using namespace std;

// 🔹 Convert string to lowercase manually
string toLowerCase(string str) {
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // ASCII conversion
        }
    }
    return str;
}

int main() {
    string paragraph;

    cout << "Enter a paragraph:\n";
    getline(cin, paragraph);

    string words[100];   // store unique words
    int freq[100] = {0}; // frequency array
    int wordCount = 0;

    string temp = "";

    // 🔹 Extract words manually
    for(int i = 0; i <= paragraph.length(); i++) {
        if(paragraph[i] != ' ' && paragraph[i] != '\0') {
            temp += paragraph[i];
        } else {
            if(temp != "") {
                temp = toLowerCase(temp);

                // 🔹 Check if word already exists
                int found = -1;
                for(int j = 0; j < wordCount; j++) {
                    if(words[j] == temp) {
                        found = j;
                        break;
                    }
                }

                if(found != -1) {
                    freq[found]++;
                } else {
                    words[wordCount] = temp;
                    freq[wordCount] = 1;
                    wordCount++;
                }

                temp = "";
            }
        }
    }

    // 🔹 Display results
    cout << "\nWord Frequencies:\n";
    for(int i = 0; i < wordCount; i++) {
        cout << words[i] << " : " << freq[i] << endl;
    }

    return 0;
}