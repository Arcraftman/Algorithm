#include <unordered_map>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n % 2 == 1) return false;
        unordered_map<char,char> pairs = {
            {')','('},
            {']','['},
            {'}','{'}
        };
        stack<char> stk;
        for (char ch : s){
            if (pairs.count(ch)){
                if (stk.empty() || stk.top() != pairs[ch]){
                    return false;
                }
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};
