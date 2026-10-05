class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth=0;
        int score=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('&&s[i+1]==')'){
                score+=(1<<depth);
                depth++;
            }
            else if(s[i]=='('&&s[i+1]=='('){
                depth++;
            }
            else if(s[i]==')') {
                depth--;
            }
            
        }
    return score;}
};