class Solution {
   public:
    string simplifyPath(string path) {
        string cur = "";
        vector<string> st;

        path += "/";  // Add this so the last section can be proccessed(go inside for loop)
        string result = "";
        for (int i = 0; i < path.size(); i++) {
            if (path[i] != '/') {  // keep select what to proccess until next /
                cur += path[i];
            } else {
                if (cur == "" || cur == ".") {
                    // ignore;
                } else if (cur == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                } else if (cur == "...") {
                    st.push_back(cur);
                } else {
                    st.push_back(cur);
                }
                cur = "";
            }
        }
        for (string dir : st) {
            result += "/" + dir;  // make sure every path start with //
        }

        if (result == "") {
            return "/";
        }

        return result;
    }
};