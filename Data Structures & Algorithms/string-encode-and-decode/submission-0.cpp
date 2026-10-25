class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;

        for(auto s : strs){
            int n = s.size();
            encoded_string += to_string(n);
            encoded_string += "#";
            encoded_string += s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
        int n = s.size(), i = 0;

        while(i < n){
            string l;
            while(s[i] != '#'){
                l += s[i];
                i++; 
            }
            int len = stoi(l);
            i++;
            decoded_string.push_back(s.substr(i,len));
            i += len;
        }
        return decoded_string;

        
    }
};
