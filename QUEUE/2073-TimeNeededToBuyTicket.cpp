//Method1
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k)
                time += min(tickets[i], tickets[k]);
            else
                time += min(tickets[i], tickets[k] - 1);
        }
        return time;
    }
};

//Method2
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    queue<int> q;
    for (int i = 0; i < tickets.size(); i++)
      q.push(i);

    int time = 0;
    while (tickets[k] > 0) {
        int person = q.front();
        q.pop();
        tickets[person]--;
        time++;
    if (tickets[person] > 0)
        q.push(person);
    }
    return time;
    }
};