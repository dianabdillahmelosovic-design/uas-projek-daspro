#include <iostream>
#include <string>
using namespace std;

const int JUMLAH_MENU = 5;

// Data menu restoran
string namaMenu[JUMLAH_MENU] = {
    "Nasi Goreng Spesial",
    "Ayam Geprek Sambal Ijo",
    "Mie Ayam Komplit",
    "Es Teh Manis",
    "Jus Alpukat"
};

int hargaMenu[JUMLAH_MENU] = {25000, 20000, 18000, 5000, 10000};
int jumlahPesanan[JUMLAH_MENU] = {0};
// =============================
//       FUNGSI-FUNGSI
// =============================

void tampilkanHeader() {
    cout << "=====================================\n";
    cout << "   SISTEM PEMESANAN RESTORAN - DineXpress\n";
    cout << "=====================================\n";
}

void tampilkanMenu() {
    cout << "\n=============================\n";
    cout << "     MENU RESTORAN DineXpress\n";
    cout << "=============================\n";
    for (int i = 0; i < JUMLAH_MENU; i++) {
        cout << i + 1 << ". " << namaMenu[i] << " - Rp " << hargaMenu[i] << endl;
    }
    cout << "=============================\n";
}

// Menghitung total & menampilkan rincian
int hitungTotalDanTampil(bool tampilkanRincian = true) {
    int total = 0;

    if (tampilkanRincian) {
        cout << "\n=============================\n";
        cout << "        PESANAN ANDA\n";
        cout << "=============================\n";
    }

    for (int i = 0; i < JUMLAH_MENU; i++) {
        if (jumlahPesanan[i] > 0) {
            int subtotal = jumlahPesanan[i] * hargaMenu[i];

            if (tampilkanRincian) {
                cout << "- " << namaMenu[i] << " (" << jumlahPesanan[i] 
                     << "x) = Rp " << subtotal << endl;
            }

            total += subtotal;
        }
    }

    if (tampilkanRincian) {
        cout << "-----------------------------\n";
        cout << "Total Sebelum Diskon : Rp " << total << endl;
    }

    // Hitung diskon
    if (total > 100000) {
        int diskon = total * 10 / 100;
        total -= diskon;

        if (tampilkanRincian) {
            cout << "Diskon 10% Diterapkan! (-Rp " << diskon << ")\n";
        }
    } else if (tampilkanRincian) {
        cout << "Maaf, tidak dapat diskon karena total di bawah Rp 100.000.\n";
    }

    if (tampilkanRincian) {
        cout << "Total Akhir : Rp " << total << endl;
        cout << "=============================\n";
    }

    return total;
}
