class Solution {
public:
    bool ip(string &s, int i){
        int n = s.size();
        if(i >= n/2) return true;

        if(s[i] != s[n-i-1]){
            return false;
        }
        return ip(s,i+1);
    }
    string clean(const string &s) {
    string result;
    for (char c : s) {
        if (isalnum((unsigned char)c)) {          
            result += tolower((unsigned char)c);   
        }
    }
    return result;
    }
   
    bool isPalindrome(string s) {
        // s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){return !isalpha[c];}),  s.end);
        s = clean(s);
        return ip(s,0);
    }
};