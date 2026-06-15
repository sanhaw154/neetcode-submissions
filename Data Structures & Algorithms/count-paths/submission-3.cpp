class Solution {
public:
    int uniquePaths(int m, int n) {
      return (int)combination(m+n-2,n-1);
    }
    long long combination(int n ,int k)
    {
        if(n < k) return 0;
        if(k==0 || n==k) return 1;
        if(k > n-k) k = n-k;

        return combination(n-1,k) * n / (n-k) ;
    }
};
