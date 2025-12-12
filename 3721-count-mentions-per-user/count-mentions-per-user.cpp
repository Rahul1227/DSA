class Solution {
private:
    static bool compare(const vector<string>& a, const vector<string>& b) {
        int ta = stoi(a[1]);
        int tb = stoi(b[1]);
        if (ta != tb)
            return ta < tb;

        return a[0] > b[0];
    }

public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), compare);
        for (auto it : events) {
            cout << it[0] << " " << it[1] << " " << it[2] << endl;
        }
        vector<int> mentions(n, 0);
        vector<int> commingOnline(n, 0);
        unordered_map<int, int> mp;

        // making all the users online
        for (int i = 0; i < n; i++) {
            mp[i] = 1;
        }

        for (int i = 0; i < events.size(); i++) {
            // auto[msg, timestamp, ids] = events[i];
            string msg = events[i][0];
            string timestp = events[i][1];
            string ids = events[i][2];
            int timestamp = stoi(timestp);
            // cout<<timestamp;

            // checking if any user can become online
            for (int i = 0; i < n; i++) {
                if (commingOnline[i] <= timestamp) {
                    mp[i] = 1;
                    commingOnline[i] = 0;
                }
            }
            if (msg == "OFFLINE") {
                int newTimeStamp = timestamp + 60;
                // cout<<newTimeStamp<<endl;
                int indInd = stoi(ids);
                commingOnline[indInd] = newTimeStamp;
                mp[indInd] = 0;
            } else {
                if (ids == "ALL") {
                    for (int i = 0; i < n; i++) {
                        mentions[i]++;
                    }
                } else if (ids == "HERE") {
                    for (auto [key, val] : mp) {
                        if (val == 1) {
                            mentions[key]++;
                        }
                    }
                } else {
                    vector<int> id;
                    stringstream idToken(ids);
                    string currId;
                    while(getline( idToken, currId, ' ')){
                        string currNum;
                        for(char c: currId){
                            if(c >= '0' && c<='9'){
                                currNum += c;
                            }
                        }
                        id.push_back(stoi(currNum));
                    }

                    for(auto it: id){
                        mentions[it]++;
                    }
                }
            }
        }

        return mentions;
    }
};