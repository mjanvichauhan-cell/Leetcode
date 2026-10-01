class Solution {
public:
    void nextPermutation(vector<int>& a) {
         int n = a.size();
    int pivot = -1;
    for(int i = n-2; i >= 0; i--){
        if(a[i] < a[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1){
        reverse(a.begin(), a.end());
        return;
    }
    for(int i = n-1; i > pivot; i--){
        if(a[i] > a[pivot]){
            swap(a[i], a[pivot]);
            break;
        }
    }
    int m = pivot + 1, j = n - 1;
    while(m < j){
        swap(a[m++], a[j--]);
    }
    }
};