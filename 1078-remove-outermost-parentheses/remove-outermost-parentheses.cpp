class Solution {
    string corrcted (string s ){
        int depth=0;int curr=0;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='('){depth++;}
            if(s[i]==')'){depth--;}
            if(depth==0){
                s[curr]='#';
                s[i]='#';
                curr=i+1;   // fix: next primitive ka start
            }
            
        }
        return s;           // fix: return missing tha
    }

public:
    string removeOuterParentheses(string s) {
        string a=corrcted(s);
        string res;         // fix: alag result string
        for(int i=0;i<s.length();i++){
            if(a[i]!='#'){  // fix: a check karna hai, s nahi
                res.push_back(a[i]);
            }
        }
        return res;         // fix: return missing tha
    }
};