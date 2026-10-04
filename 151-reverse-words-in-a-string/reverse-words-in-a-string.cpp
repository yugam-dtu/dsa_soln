class Solution {
public:
    string reverseWords(string s) {

        vector<string> v;

        stringstream ss(s);
        string word;
        while (ss >> word) {
            v.push_back(word);
        }
        string a;
        for(int i=v.size()-1;i>=0;i--){  
            a += v[i];              
            a.push_back(' ');
        }
        a.pop_back();              

        return a;
    }
};