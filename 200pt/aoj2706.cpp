// Let's Solve Geometric Problems (200)
// 2020/11/28

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

vector<int> get_prime_factors(int n)
{
    vector<int> prime_factors;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            if (prime_factors.empty() || prime_factors.back() != i)
                prime_factors.push_back(i);
            n /= i;
        }
    }
    if (n != 1)
        prime_factors.push_back(n);
    return prime_factors;
}

int main()
{
    int p, q;
    cin >> p >> q;
    int g = gcd(p, q);

    vector<int> primes = get_prime_factors(q / g);

    int ans = 1;
    for (int prime : primes)
        ans *= prime;

    cout << ans << endl;
}
