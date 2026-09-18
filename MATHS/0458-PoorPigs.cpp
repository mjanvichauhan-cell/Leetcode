class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest / minutesToDie;
        long long capacity = 1;
        int pigs = 0;

        while (capacity < buckets) {
            capacity *= (rounds + 1);
            pigs++;
        }

        return pigs;
    }
};