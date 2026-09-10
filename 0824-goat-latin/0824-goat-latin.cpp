
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }

    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word;
        string ans;
        int index = 1;

        while (ss >> word) {

            // If word starts with a consonant
            if (!isVowel(word[0])) {
                char first = word[0];
                word.erase(0, 1);
                word += first;
            }

            // Add "ma"
            word += "ma";

            // Add 'a' index times
            word += string(index, 'a');

            // Add space between words
            if (!ans.empty()) {
                ans += " ";
            }

            ans += word;
            index++;
        }

        return ans;
    }
};

