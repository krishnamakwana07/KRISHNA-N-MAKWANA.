#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

// Convert to lowercase (optional but recommended)
string toLowerCase(string word) {
    for(int i = 0; i < word.length(); i++) {
        if(word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] + 32;
        }
    }
    return word;
}

int main() {
    string sentence;

    cout << "Enter a sentence:\n";
    getline(cin, sentence);

    map<string, int> freq;

    stringstream ss(sentence);
    string word;

    // Extract words
    while(ss >> word) {
        word = toLowerCase(word);   // case handling
        freq[word]++;               // increment count
    }

    // Display results
    cout << "\nWord Frequencies:\n";
    for(map<string, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}