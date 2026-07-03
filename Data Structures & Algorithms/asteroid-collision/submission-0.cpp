class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int cur : asteroids) {
            bool alive = true;
            while (!st.empty() && st.back() > 0 && cur < 0 && alive) {  // keep collide
                if (abs(st.back()) < abs(cur)) {
                    st.pop_back();
                } else if (abs(st.back()) == abs(cur)) {
                    st.pop_back();
                    alive = false;
                } else {
                    alive = false;
                }
            }
            if (alive) {
                st.push_back(cur);
            }
        }
        return st;
    }
};