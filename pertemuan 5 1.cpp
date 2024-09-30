#include <iostream>
using namespace std;

// Constants
const int GAJI_POKOK_PER_JAM = 7500;
const int UANG_MAKAN = 10000;
const int UANG_TRANSPORT = 13000;
const float LEMBUR_RATE = 1.5;

// Function prototypes
int pokok(int jamKerja);
int lembur(int jamKerja);
int makan(int jamKerja);
int transport(int jamKerja);

int main() {
    // Variables
    string NIP, nama;
    int jamKerja;

    // Input
    cout << "Masukkan NIP: ";
    cin >> NIP;
    cout << "Masukkan Nama: ";
    cin.ignore(); // To handle the newline character after NIP input
    getline(cin, nama);
    cout << "Masukkan jumlah jam kerja: ";
    cin >> jamKerja;

    // Calculations
    int gajiPokok = pokok(jamKerja);
    int uangLembur = lembur(jamKerja);
    int uangMakan = makan(jamKerja);
    int uangTransport = transport(jamKerja);

    // Output
    cout << "\n--- Gaji Harian ---" << endl;
    cout << "NIP           : " << NIP << endl;
    cout << "Nama          : " << nama << endl;
    cout << "Gaji Pokok    : Rp. " << gajiPokok << endl;
    cout << "Uang Lembur   : Rp. " << uangLembur << endl;
    cout << "Uang Makan    : Rp. " << uangMakan << endl;
    cout << "Uang Transport: Rp. " << uangTransport << endl;

    return 0;
}

// Fungsi untuk kalkulasi gaji pokok
int pokok(int jamKerja) {
    return jamKerja * GAJI_POKOK_PER_JAM;
}

// Fungsi untuk kalkulasi uang lembur
int lembur(int jamKerja) {
    if (jamKerja > 8) {
        int jamLembur = jamKerja - 8;
        return jamLembur * GAJI_POKOK_PER_JAM * LEMBUR_RATE;
    } else {
        return 0;
    }
}

// Fungsi untuk kalkulasi uang makan
int makan(int jamKerja) {
    if (jamKerja >= 9) {
        return UANG_MAKAN;
    } else {
        return 0;
    }
}

// Fungsi untuk kalkulasi uang transport
int transport(int jamKerja) {
    if (jamKerja >= 10) {
        return UANG_TRANSPORT;
    } else {
        return 0;
    }
}
