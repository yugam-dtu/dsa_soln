class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string result;
        int d=0;
        int s=0;
        while (s+9<sum){
            result+='9';
            d++;
            s+=9;
        }
        if ((sum-s)>0){
            result+=(sum-s)+'0';
            d++;
        }
        while (d<num){
            result+='0';
            d++;
        }
        if (d<=num){
            return result;
        }else{
            return "";
        }
    }
};