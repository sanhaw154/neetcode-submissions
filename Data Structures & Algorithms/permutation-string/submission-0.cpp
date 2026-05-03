class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int count[26] = {0};
        for(auto c : s1)
        {
            count[ c - 'a']++;
        }

        int left = 0;
        int right = 0;
        for(; right < s1.size() ; right++)
        {
            count[s2[right] - 'a']--;
        }
        if (allzero(count,26)) return true; //此時right == s1.size()

        for(; right < s2.size() ; right++)
        {   
            count[s2[right] - 'a']--;
            count[s2[left] - 'a']++;
            left++; 
            if (allzero(count,26)) return true;
        }
        return false;
    }
    bool allzero(int arr[], int n)
    {
        for(int i = 0; i<n ; i++)
        {
            if(arr[i] != 0) return false;
        }
        return true;
    }
};
