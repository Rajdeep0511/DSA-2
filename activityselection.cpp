#include<bits/stdc++.h>
using namespace std;

// Function to find the maximum number of activities
void activitySelection(vector<int> start, vector<int> finish, int n) {
    vector<pair<int, int>> activities;

    // Pair up start and finish times
    for (int i = 0; i < n; i++) {
        activities.push_back({finish[i], start[i]});
    }

    // Sort activities based on finish times
    sort(activities.begin(), activities.end());

    // Select the first activity
    cout << "Selected activities: ";
    int lastFinish = activities[0].first;
    cout << "(" << activities[0].second << ", " << lastFinish << ") ";

    // Check for other non-overlapping activities
    for (int i = 1; i < n; i++) {
        if (activities[i].second >= lastFinish) {
            cout << "(" << activities[i].second << ", " << activities[i].first << ") ";
            lastFinish = activities[i].first;
        }
    }
    cout << endl;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    int n = start.size();

    activitySelection(start, finish, n);
    return 0;
}
