class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long sum=0;
        for(int x:target){
            pq.push(x);
            sum+=x;
        }
        while(true){
            long long largest=pq.top();
            pq.pop();
            long long rest=sum-largest;
            if(largest==1||rest==1)
                return true;
            if(rest==0||largest<=rest)
                return false;
            long long prev=largest%rest;
            if(prev==0)
                return false;
            pq.push(prev);
            sum=rest+prev;
        }
    }
};