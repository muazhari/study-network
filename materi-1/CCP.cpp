#include <stdio.h>

// cari minimum dua ubah angka
int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    // deklarasi variabel
    // angka engga mungkin minus
    int input = 10, totalCoins = 3;

    // jumlah coins dari kasus ketika input = 0 sampai input yang ditanyakan (10)
    int dp[input + 1];

    // jumlah pecahan coins yang kita miliki
    int coins[] = {3, 4, 11};

    // inisialisasi semua input dp menjadi input+1
    // agar kita bisa bandingkan menggunakan min(a, b)
    for (int i = 0; i <= input; i++)
    {
        dp[i] = input + 1;
    }

    // isi base case
    dp[0] = 0;

    // ngisi tabelnya (fill in the subproblems)
    // fill in dari 1 sampai 11
    for (int i = 1; i <= input; i++)
    {
        // ngisi tiap kolom tabel berdasarkan possibility
        // possibility: available coins(1, 2, dan 5)
        for (int j = 0; j < totalCoins; j++)
        {
            // hanya mengecek jika kasus < coins
            // contoh kita punya kasus dimana dia lebih kecil
            // dari available coins, kita engga perlu masuk ke isi dari if
            if (i >= coins[j])
            {
                // mengisi tabel berdasarkan memory dan koin sekarang
                // dp[i]: ingatan pas koin sekarang (masih input+1) => PRESENT
                // dp[i-coins[j]: ingatan setelah kasus dikurang koin yg diberikan => PAST
                // +1: koin sekarang
                int currentCoinsNeeded = dp[i - coins[j]] + 1;

                // min() untuk mengambil jumlah koin terkecil dari semua possibility yang ada
                // bandingkan isi dp[i] dengan koin yang dibutuhkan untuk kasus saat ini
                dp[i] = min(dp[i], currentCoinsNeeded);
            }
        }
    }

    // print the main problem
    // cek apakah kita bisa memberikan kembalian

    // bisa memberikan kembalian -> dp[input] sudah bukan input+1 lagi
    // karena kita sudah overwrite nilainya saat mengisi tabel

    // tidak bisa memberikan kembalian -> dp[input] masih input+1
    // karena kita tidak overwite nilainya (tidak masuk dalam kondisi if)
    (dp[input] == input + 1) ? puts("Tidak bisa membuat kembalian") : printf("%d\n", dp[input]);

    return 0;
}