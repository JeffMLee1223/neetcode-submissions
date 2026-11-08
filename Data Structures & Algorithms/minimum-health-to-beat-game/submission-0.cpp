class Solution {
   public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long totalDamage = 0;
        int biggestDamage = 0;

        for (int i = 0; i < damage.size(); i++) {
            totalDamage += damage[i];

            if (damage[i] > biggestDamage) {
                biggestDamage = damage[i];
            }
        }

        int blockedDamage = min(biggestDamage, armor);

        return totalDamage - blockedDamage + 1;



    }
};
