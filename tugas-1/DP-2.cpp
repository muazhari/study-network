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

// a. base case
//    terjadi base case saat n==1 atau ketika mencapai tree leaf.
//    dengan tiap pemanggil function memanggil 2 function kembali,
//    maka time complexity nya adalah O(2^n).
//    dan karena memiliki maximum stack pemanggilan function dari 1..n,
//    maka space complexity nya adalah O(n)

// b. draw recursive tree
//    ***ada dilampiran***
//    pola recursive berurutan secara in-order

// c. codes
void towerOfHanoi1(ll n, char src, char dst, char aux)
{
    // base case
    if (n == 1)
    {
        printf("move disk %lld from tower %c to %c\n", n, src, dst);
        return;
    }

    towerOfHanoi1(n - 1, src, aux, dst);
    // in-order print
    printf("move disk %lld from tower %c to %c\n", n, src, dst);
    towerOfHanoi1(n - 1, aux, dst, src);
}

// d. implement dp
//    tidak bisa diimplementasikan dengan biasanya,
//    dikarenakan tiap kali operasi pemanggilan function
//    memiliki parameter masukan yg berbeda. jadi tidak bisa dimemoize kan
//    kecuali hanya merespresentasikan hanya berapa step yang diperlukan.

ll dp[99999] = {0};
ll towerOfHanoi2(ll n)
{
    if (n < 2)
        return 2;
    else if (n == 2)
        return 3;

    if (!dp[n])
        dp[n] = 1 + towerOfHanoi2(n - 1) + towerOfHanoi2(n - 1);
    return dp[n];
}

int main()
{
    ll disk = 3;
    towerOfHanoi1(disk, 'A', 'C', 'B');

    ll steps = towerOfHanoi2(disk);

    printf("%lld", steps);

    return 0;
}