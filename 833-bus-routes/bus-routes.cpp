class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if (source == target)
            return 0;

        // stop -> buses that visit this stop
        unordered_map<int, vector<int>> busStopToBus;

        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                busStopToBus[routes[i][j]].push_back(i);
            }
        }

        // visited buses
        unordered_set<int> visited;

        queue<int> q;

        // Start with every bus that contains source
        for (int bus : busStopToBus[source]) {
            q.push(bus);
            visited.insert(bus);
        }

        int ans = 1;

        while (!q.empty()) {

            int len = q.size();

            while (len--) {

                int busInd = q.front();
                q.pop();

                // Explore every stop of this bus
                for (int stop : routes[busInd]) {

                    // We can reach target using this bus
                    if (stop == target)
                        return ans;

                    // Find all buses that also visit this stop
                    for (int nextBus : busStopToBus[stop]) {

                        if (!visited.count(nextBus)) {
                            visited.insert(nextBus);
                            q.push(nextBus);
                        }
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};