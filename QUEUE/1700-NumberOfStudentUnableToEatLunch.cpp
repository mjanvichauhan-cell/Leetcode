//Method 1
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0;
        int count1 = 0;
        for (int student : students) {
            if (student == 0)
                count0++;
            else
                count1++;
        }
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (count0 == 0)
                    break;

                count0--;
            }
            else {
                if (count1 == 0)
                    break;

                count1--;
            }
        }
        return count0 + count1;
    }
};

//Method2
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int x : students) {
            q.push(x);
        }
        int i = 0;
        int count = 0;
        while (!q.empty() && count < q.size()) {
            if (q.front() == sandwiches[i]) {
                q.pop();
                i++;
                count = 0;
            }
            else {
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};