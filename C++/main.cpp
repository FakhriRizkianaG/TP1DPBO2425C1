#include <iostream>
#include <string>
#include "BarangElektronik.cpp"
using namespace std;

int main() {
    const int MAX_BARANG = 999;
    BarangElektronik stok[MAX_BARANG];
    int jumlahBarang = 0;
    int pilihan;

    do {
        cout << "\n===== MENU =====\n";
        cout << "[1] Tampilkan stok yang tersedia\n";
        cout << "[2] Cari barang\n";
        cout << "[3] Tambah barang\n";
        cout << "[4] Edit barang\n";
        cout << "[5] Hapus barang\n";
        cout << "[0] Exit\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            if (jumlahBarang == 0) {
                cout << "Belum ada barang yang tersimpan.\n";
            } else {
                for (int i = 0; i < jumlahBarang; i++) {
                    cout << "\nBarang ke-" << i + 1 << ":\n";
                    stok[i].tampilkanInfo();
                }
            }
            break;

        case 2: {
            int idCari;
            cout << "Masukkan ID barang yang dicari: ";
            cin >> idCari;
            bool ditemukan = false;
            for (int i = 0; i < jumlahBarang; i++) {
                if (stok[i].getId() == idCari) {
                    stok[i].tampilkanInfo();
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan)
                cout << "Barang tidak ditemukan.\n";
            break;
        }

        case 3: {
            if (jumlahBarang >= MAX_BARANG) {
                cout << "Stok penuh!\n";
                break;
            }
            int id, harga;
            string nama, manufaktur;
            cout << "Masukkan ID: ";
            cin >> id;
            cin.ignore();
            cout << "Masukkan Nama: ";
            getline(cin, nama);
            cout << "Masukkan Manufaktur: ";
            getline(cin, manufaktur);
            cout << "Masukkan Harga: ";
            cin >> harga;

            stok[jumlahBarang] = BarangElektronik(id, nama, manufaktur, harga);
            jumlahBarang++;
            cout << "Barang berhasil ditambahkan!\n";
            break;
        }

        case 4: {
            int idEdit;
            cout << "Masukkan ID barang yang akan diedit: ";
            cin >> idEdit;
            bool ditemukan = false;
            for (int i = 0; i < jumlahBarang; i++) {
                if (stok[i].getId() == idEdit) {
                    string nama, manufaktur;
                    int harga;
                    cin.ignore();
                    cout << "Masukkan Nama baru: ";
                    getline(cin, nama);
                    cout << "Masukkan Manufaktur baru: ";
                    getline(cin, manufaktur);
                    cout << "Masukkan Harga baru: ";
                    cin >> harga;

                    stok[i].setNama(nama);
                    stok[i].setManufaktur(manufaktur);
                    stok[i].setHarga(harga);
                    cout << "Barang berhasil diperbarui!\n";
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan)
                cout << "Barang tidak ditemukan.\n";
            break;
        }

        case 5: {
            int idHapus;
            cout << "Masukkan ID barang yang akan dihapus: ";
            cin >> idHapus;
            bool ditemukan = false;
            for (int i = 0; i < jumlahBarang; i++) {
                if (stok[i].getId() == idHapus) {
                    for (int j = i; j < jumlahBarang - 1; j++) {
                        stok[j] = stok[j + 1];
                    }
                    jumlahBarang--;
                    cout << "Barang berhasil dihapus!\n";
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan)
                cout << "Barang tidak ditemukan.\n";
            break;
        }

        case 0:
            cout << "Have a nice day :D\n";
            return 0;

        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}