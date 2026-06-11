class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        sort(hand.begin(),hand.end());
        int target = 0;
        vector <bool> choosen(n,false);
        for(int i = 0 ; i < n ; i++)
        {
            if(!choosen[i])
            {
                int curCho = 1;
                target = hand[i]+1;
                choosen[i] = true;
                if(curCho == groupSize) continue;
                for(int j = i+1 ; j < n ; j++)
                {
                    if(hand[j] < target) continue;
                    else if(hand[j] > target ) return false;
                    else if(hand[j] == target && !choosen[j])
                    {
                        curCho++;
                        choosen[j] = true;
                        target += 1;
                        if(curCho == groupSize) break;
                    }
                }
                if(curCho < groupSize) return false;
            }
        }
        return true;
    }
};
