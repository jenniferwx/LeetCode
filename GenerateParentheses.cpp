/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()" 
*/
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        res.clear();
        generateParenthesisRe(n, n, "");
        return res;
    }

    void generateParenthesisRe(int left, int right, string s) {
        if (left == 0 && right == 0)
            res.push_back(s);
        if (left > 0)
            generateParenthesisRe(left - 1, right, s + "(");
        if (right > left)
            generateParenthesisRe(left, right - 1, s + ")");
    }
};
