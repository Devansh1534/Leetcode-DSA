class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        istringstream ss(s);
        string word;
        int i = 0;
        
        while (ss >> word) {
            if (i == pattern.size()) return false;  
            
            char c = pattern[i];
            
            if (charToWord.count(c)) {
                if (charToWord[c] != word) return false;
            } else {
                charToWord[c] = word;
            }
            
            if (wordToChar.count(word)) {
                if (wordToChar[word] != c) return false;
            } else {
                wordToChar[word] = c;
            }
            
            i++;
        }
        
        return i == pattern.size();  
    }
};
