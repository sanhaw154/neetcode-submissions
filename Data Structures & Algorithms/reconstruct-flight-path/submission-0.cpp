class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(vector<string>& t : tickets)
        {

            adj[t[0]].push_back(t[1]);
        }
        for(auto& [airport,adjVector] : adj)
        {
            sort(adjVector.rbegin(), adjVector.rend());
        }

        vector<string> res;
        stack<string> s;
        s.push("JFK");
        while(!s.empty())
        {
            string cur = s.top();
            // s.pop();
            if(!adj[cur].empty())
            {
                
                s.push(adj[cur].back());
                adj[cur].pop_back();
            }
            else
            {
                s.pop();
                res.push_back(cur);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
