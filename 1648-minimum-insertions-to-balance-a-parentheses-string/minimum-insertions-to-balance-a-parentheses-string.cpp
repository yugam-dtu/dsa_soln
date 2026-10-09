class Solution {
public:
    int minInsertions(string s) {
        int depth=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                depth++;
            }
            else if(i+1<s.length() && s[i+1]==')'){   
                depth--;
                i=i+1;
            }
            else{                                      
                ans++;                               
                depth--;
            }

            if(depth<0){
                ans++;                                
                depth=0;
            }
        }
        ans += depth*2;                           

        return ans;
    }
};