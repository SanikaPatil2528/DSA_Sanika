class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // available rooms
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) available.push(i);

        // busy rooms: (endTime, room)
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<>> busy;

        vector<long long> count(n, 0);

        for (auto &m : meetings) {
            long long start = m[0];
            long long duration = m[1] - m[0];

            // free rooms
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                busy.push({start + duration, room});
                count[room]++;
            } else {
                auto [endTime, room] = busy.top();
                busy.pop();
                busy.push({endTime + duration, room});
                count[room]++;
            }
        }

        // find room with max meetings
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) ans = i;
        }
        return ans;
    }
};