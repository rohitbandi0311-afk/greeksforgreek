class Solution {
public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        int n = l.size();
        vector<long long> pref(n);

        // Build prefix sum of element counts in each interval
        long long current_total = 0;
        for (int i = 0; i < n; ++i) {
            current_total += (r[i] - l[i] + 1);
            pref[i] = current_total;
        }

        vector<int> ans;
        ans.reserve(rank.size());

        // Find corresponding mark for each rank using binary search
        for (int rk : rank) {
            auto it = lower_bound(pref.begin(), pref.end(), rk);
            int idx = distance(pref.begin(), it);

            long long prev_count = (idx > 0) ? pref[idx - 1] : 0;
            long long offset = rk - prev_count - 1;

            ans.push_back(l[idx] + offset);
        }

        return ans;
    }
};