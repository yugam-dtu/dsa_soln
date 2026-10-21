class Solution {
    bool issorted(string s){
        for(int i=0;i<s.length()-1;i++){
            if(s[i]>s[i+1]){return false;}
        }
        return true;
    }
public:
    int minOperations(string s) {
        int n=s.length();
        if(s.length()==0){return 0;}
        if(s.length()==1){return 0;}
        if(s.length()==2){
            if(issorted(s)){
                return 0;
            }
            else return -1;
        }

        char mini='z';
        char maxi='a';
        for(int i=0;i<s.length();i++){
            maxi=max(maxi,s[i]);
            mini=min(mini,s[i]);
        }
        if(mini==s[0]&&maxi==s[n-1]){
            if(issorted(s)){return 0;}
            else return 1;
        }
        if(mini==s[0]&&maxi!=s[n-1]){
             return 1;
        }
        if(mini!=s[0]&&maxi==s[n-1]){
            return 1;
        }
        //helped
        if(mini==s[n-1] && maxi==s[0]){
    int cntMax=0, cntMin=0;
    for(char c: s){
        if(c==maxi) cntMax++;
        if(c==mini) cntMin++;
    }
    if(cntMax==1 && cntMin==1) return 3;
    return 2;
}
return 2;

       

    }
};