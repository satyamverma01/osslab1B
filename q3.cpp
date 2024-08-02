#include <iostream>
#include <sstream>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
string removePunctuation(string str) {
    str.erase(remove_if(str.begin(), str.end(), ::ispunct), str.end());
    return str;
}
int main() {
    string paragraph;
    map<string, int> wordFrequency;
    string word;
    cout << "Enter a paragraph (press Ctrl+D or Ctrl+Z to end input):" << endl;
    while (getline(cin, paragraph)) {
    
        stringstream ss(paragraph);
        while (ss >> word) {
            word = removePunctuation(word); 
            word = toLowerCase(word);        
            if (!word.empty()) {
                wordFrequency[word]++;
            }
        }
    }
    cout << "Word Frequencies:" << endl;
    for (const auto& pair : wordFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
