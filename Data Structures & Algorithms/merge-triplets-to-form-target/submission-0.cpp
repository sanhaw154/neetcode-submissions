class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<bool> cantCho(n,false);
        vector<bool> isFindTar(3,false);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)//檢查是否可被選擇
            {   
                if(triplets[i][j] > target[j])
                {
                    cantCho[i] = true;
                }
            }
            if(cantCho[i]) continue;
            //triplets[i][j] <= target[j] forall j
            for(int j = 0 ; j < 3 ; j++) //可以被選 檢查是否target
            {
                if(triplets[i][j] == target[j])
                {
                    isFindTar[j] = true;
                }
                
            }    
        }

        for(int j = 0 ; j < 3 ; j++)
        {
            if(!isFindTar[j])return false; //沒有 則一定達不到target
        }
        return true;
    }
};
