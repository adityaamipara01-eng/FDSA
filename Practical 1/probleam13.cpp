#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string word = "";
    string longestWord = "";
    int maxLength = 0;

    sentence = sentence + " ";

    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ') {
            word = word + sentence[i];
        } else {
            if (word.length() > maxLength) {
                maxLength = word.length();
                longestWord = word;
            }
            word = "";
        }
    }

    cout << "Longest Word: " << longestWord << endl;
    cout << "Length: " << maxLength << endl;

    return 0;
}