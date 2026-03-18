#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string prefixToInfix(string s) {
        reverse(s.begin(), s.end());
        stack<string> st;

        for(char c: s){
            if(isalnum(c)){
                string temp = "";
                temp += c;
                st.push(temp);
            }
            else{
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();

                string ans = "(" + op1 + c + op2 + ")";
                st.push(ans);
            }
        }
        return st.top();
    }
};

int main() {
    Solution obj;
    
    string s;
    cout << "Enter prefix expression: "; //*+AB-CD
    cin >> s;

    string result = obj.prefixToInfix(s); 
    cout << "Infix expression: " << result << endl;

    return 0;
}