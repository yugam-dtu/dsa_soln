class Solution {
public:
    vector<string> res;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void backtrack(string& digits, int index, string& current) {
        if (index == digits.size()) {
            res.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);          // choose
            backtrack(digits, index + 1, current); // explore
            current.pop_back();            // unchoose (backtrack)
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        string current = "";
        backtrack(digits, 0, current);
        return res;
    }
};