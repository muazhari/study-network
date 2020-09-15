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

char dp[9999][9999];

// a. base case
//    terjadi base case saat n==1 atau ketika mencapai tree leaf.
//    dengan tiap pemanggil function memanggil 2 function kembali,
//    maka time complexity nya adalah O(2^n).
//    dan karena memiliki maximum stack pemanggilan function dari 1..n,
//    maka space complexity nya adalah O(n)

// b. draw recursive tree
//    ***ada dilampiran***

// c. codes
void towerOfHanoi(ll n, char src, char dst, char aux)
{
    if (n == 1)
    {
        printf("move disk %lld from tower %c to %c\n", n, src, dst);
        return;
    }

    towerOfHanoi(n - 1, src, aux, dst);
    printf("move disk %lld from tower %c to %c\n", n, src, dst);
    towerOfHanoi(n - 1, aux, dst, src);
}

// d. implement dp
//    tidak bisa diimplementasikan, dikarenakan tiap kali operasi pemanggilan function
//    memiliki parameter masukan yg berbeda. jadi tidak bisa dimemoize kan

int main()
{
    ll disk = 3;
    towerOfHanoi(disk, 'A', 'C', 'B');

      return 0;
}