class Solution {
public:
    int minAddToMakeValid(string s) {
        int depth=0,count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                depth++;
            }
            else depth--;
            if(depth<0){
                depth=0;
                count++;
            }

        }
        count=count+depth;
        return count;
    }
};