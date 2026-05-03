class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col =  matrix[0].size();

        int left = 0;
        int right = row * col - 1;
        int cur = 0;
        
        while(left <= right)
        {
            cur = left + ((right - left) / 2);

            if(matrix[cur/col][cur%col] == target)
            {
                return true;
            }
            else if(matrix[cur/col][cur%col] < target)
            {
                left = cur + 1;
            }
            else
            {
                right = cur - 1;
            }
        }
        return false;
    }
};
