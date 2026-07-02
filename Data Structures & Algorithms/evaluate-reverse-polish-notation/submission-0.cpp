class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string op : tokens){
            if(op == "+" || op == "-" || op == "*" || op == "/" ){
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int result = 0;
                if(op == "+"){
                    result = b + a;
                }else if( op == "-"){
                    result = b - a;
                }else if(op == "*"){
                    result = b * a;
                }else if(op == "/"){
                    result = b / a;
                }

                st.push(result);

            }else{
                st.push(stoi(op));
            
            }
        }
        return st.top();
    }
    
};
