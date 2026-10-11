class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tg=0,tc=0;
        int st=0,cg=0;
        for(int i=0;i<gas.size();i++){
            tg+=gas[i];
            tc+=cost[i];
            cg+=(gas[i]-cost[i]);
            if(cg<0){
                st=i+1;
                cg=0;
            }
        }
        if(tg<tc) return -1;
        return st;
    }
};