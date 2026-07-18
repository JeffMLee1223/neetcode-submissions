class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string op : tokens) {
            if (op == "+" || op == "-" || op == "*" || op == "/") {
                int result = 0;

                int right = stk.top();
                stk.pop();

                int left = stk.top();
                stk.pop();

                if (op == "+") {
                    result = result + left + right;

                } else if (op == "-") {
                    result = result + (left - right);
                } else if (op == "*") {
                    result = result + (left * right);
                } else {
                    result = result + (left / right);
                }

                stk.push(result);

            } else {
                stk.push(stoi(op));
            }
        }

        return stk.top();
    }
};
