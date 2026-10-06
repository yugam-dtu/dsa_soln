  
       
       class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int count = 0;

        // pehle k cards left se
        for (int i = 0; i < k; i++) count += cardPoints[i];

        int best = count;
        int a = k - 1;   // left ka last taken index
        int b = n - 1;   // right ka next index

        while (a >= 0) {
            count -= cardPoints[a];
            count += cardPoints[b];
            a--;
            b--;
            best = max(best, count);
        }
        return best;
    }
};
       
       
       
       
       
       
       
       
        // int n = cardPoints.size();
        // int a = 0;
        // int b = n - 1;
        // int count = 0;

        // while (k--) {
        //     if (cardPoints[a] > cardPoints[b]) {
        //         count += cardPoints[a];
        //         a++;
        //     } else {
        //         count += cardPoints[b];
        //         b--;
        //     }
        // }
        // return count;
    