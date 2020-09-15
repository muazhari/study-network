#include <cstdio>
#include <cstring>
#define ll long long int
#define lf double

// 1. buatlah algo fibb
//    a. looping
//    b. rekursi
//    c. rekursi + dp
//    d. compare time and space complexity from all of 3 above
// 2. tower of hanoi
//    a. base case
//    b. draw recursive tree
//    c. codes
//    d. implement dp

// a.
// space : O(n), dikarenakan menyimpan setiap hasil pengoperasian angka 1..n
// time  : O(n), dikarenakan hanya mengkalkulasikan 1..n operasi akibat
//             variable angka yg berulang dapat langsung diakses O(1) menggunakan dp
ll fib1(ll n)
{
    ll dp1[99999] = {0};

    for (ll i = 0; i <= n; i++)
        if (i == 0)
            dp1[i] = 0;
        else if (i == 1)
            dp1[i] = 1;
        else
            dp1[i] = dp1[i - 1] + dp1[i - 2];

    return dp1[n];
}

// b.
// space : O(n), dikarenakan menyimpan setiap stack function call 1..n
// time  : O(n), dikarenakan tiap fib2(n) melakukan pemanggilan 2 fungsi kembali,
//       jadi O(2^n)

ll fib2(ll n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;

    return fib2(n - 1) + fib2(n - 2);
}

// c.
// space : O(n), dikarenakan menyimpan setiap hasil pengoperasian angka 1..n
// time  : O(n), dikarenakan hanya mengkalkulasikan 1..n operasi akibat
//             variable angka yg berulang dapat langsung diakses O(1) menggunakan dp

ll dp3[99999] = {0};

ll fib3(ll n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;

    if (!dp3[n])
        dp3[n] = fib3(n - 1) + fib3(n - 2);

    return dp3[n];
}

int main()
{
    ll res1 = fib1(5);
    printf("%lld", res1);

    ll res2 = fib2(5);
    printf("%lld", res2);

    ll res3 = fib3(5);
    printf("%lld", res3);

    // d. compare time and space complexity from all of 3 above
    //    pengoperasian function dengan mengimplementasikan dynamic programming
    //    dapat mengoptimalkan time complexity recursion berkat teknik memoization
    //    menjadi O(n) dikarenakan menyimpan subsolution dan mencegah pemanggilan
    //    function kembali yg redundant.
    //    sedangkan untuk space complexity masih tetap O(n) dikarenakan maximum
    //    call function stack sebesar 1..n.

    return 0;
}