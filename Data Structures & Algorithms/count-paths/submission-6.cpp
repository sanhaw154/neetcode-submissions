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
        long long res = 1;

        for(int i = 1; i <= k ; i++)
        {
            int a = n-i+1;
            int b = i ;

            int g = gcd(a,b);
            a /= g;
            b /= g;

            g = gcd(res,b);
            res /= g;
            b /= g;

            res = res * a;
        }

        return  res;
    }
};
