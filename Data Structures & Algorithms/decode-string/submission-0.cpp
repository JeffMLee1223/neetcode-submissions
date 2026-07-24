class Solution {
   public:
    string decodeString(string s) {
        stack<char> c;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {  // keep pushing
            if (s[i] != ']') {
                c.push(s[i]);
            } else {  // when we reach ], then we start to find out what should we pop and where to
                      // stop
                string temp = "";

                while (!c.empty() && c.top() != '[') {
                    temp += c.top();
                    c.pop();
                }
                reverse(temp.begin(), temp.end());
                c.pop();  // pop [

                int num = 0;
                int place = 1;
                while (!c.empty() &&
                       isdigit(c.top())) {  // to decide how many times it should be add
                    num += (c.top() - '0') * place;
                    c.pop();  // pop and contine to proccess next number
                    place *= 10;
                }


                string repeated = "";

                for (int i = 0; i < num; i++) {
                    repeated += temp;
                }

                for (char ch : repeated) {
                    c.push(ch);
                }
            }
        }  // after iterate, all char has been process, either just push, or being repeated
        string ans = "";
        while (!c.empty()) {
            ans += c.top();
            c.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};