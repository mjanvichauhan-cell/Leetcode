class Solution {
public:
    bool canship(vector<int>& weights,int days,int capacity){
        int currentweight=0;
        int req=1;
        for(int weight:weights){
            if(currentweight+weight>capacity){
                req++;
                currentweight=weight;
            }
            else{
                currentweight+=weight;
            }
            
        }
        return (req<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=0;
        int high=0;
        for(int i=0;i<n;i++){
            low=max(weights[i],low);
            high+=weights[i];
        }
        while(low<high){
            int mid=low+(high-low)/2;
            if(canship(weights,days,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }

        }
        return low;

    }
};