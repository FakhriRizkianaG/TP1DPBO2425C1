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
        case 1: { // Tampilkan stok
            cout << "\n=== Daftar Stok Barang ===\n";
            if (jumlahBarang == 0) {
                cout << "Belum ada barang yang tersimpan.\n";
            } else {
                int i = 0;
                while (i < jumlahBarang) {
                    cout << "\nBarang ke-" << i + 1 << ":\n";
                    stok[i].tampilkanInfo();
                    i++;
                }
            }
            break;
        }
        case 2: { // Cari barang
            int idCari;
            cout << "Masukkan ID barang yang dicari: ";
            cin >> idCari;
            bool ditemukan = false;
            int i = 0;
            while (i < jumlahBarang && !ditemukan) {
                if (stok[i].getId() == idCari) {
                    cout << "\nBarang ditemukan:\n";
                    stok[i].tampilkanInfo();
                    ditemukan = true;
                }
                i++;
            }
            if (!ditemukan) {
                cout << "Barang dengan ID " << idCari << " tidak ditemukan.\n";
            }
            break;
        }
        case 3: { // Tambah barang
            if (jumlahBarang >= MAX_BARANG) {
                cout << "Stok penuh! Tidak bisa menambahkan barang baru.\n";
                break;
            }
            int id, harga;
            string nama, manufaktur;
            cout << "Masukkan ID: ";
            cin >> id;

            // ✅ Cek ID duplikat
            bool idDuplikat = false;
            int i = 0;
            while (i < jumlahBarang) {
                if (stok[i].getId() == id) {
                    idDuplikat = true;
                }
                i++;
            }

            if (idDuplikat) {
                cout << "Gagal menambahkan! ID " << id << " sudah digunakan.\n";
                break;
            }

            cout << "Masukkan Nama: ";
            cin.ignore();
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
        case 4: { // Edit barang
            int idEdit;
            cout << "Masukkan ID barang yang akan diedit: ";
            cin >> idEdit;
            bool ditemukan = false;
            int i = 0;
            while (i < jumlahBarang && !ditemukan) {
                if (stok[i].getId() == idEdit) {
                    int idBaru, harga;
                    string nama, manufaktur;

                    cout << "Masukkan ID baru: ";
                    cin >> idBaru;

                    // ✅ Validasi ID baru agar tidak duplikat
                    bool idDuplikat = false;
                    int k = 0;
                    while (k < jumlahBarang) {
                        if (k != i && stok[k].getId() == idBaru) {
                            idDuplikat = true;
                        }
                        k++;
                    }

                    if (idDuplikat) {
                        cout << "Gagal mengubah ID! ID " << idBaru << " sudah digunakan.\n";
                    } else {
                        stok[i].setId(idBaru);
                        cout << "Masukkan Nama baru: ";
                        cin.ignore();
                        getline(cin, nama);
                        cout << "Masukkan Manufaktur baru: ";
                        getline(cin, manufaktur);
                        cout << "Masukkan Harga baru: ";
                        cin >> harga;

                        stok[i].setNama(nama);
                        stok[i].setManufaktur(manufaktur);
                        stok[i].setHarga(harga);

                        cout << "Barang berhasil diperbarui!\n";
                    }
                    ditemukan = true;
                }
                i++;
            }
            if (!ditemukan) {
                cout << "Barang dengan ID " << idEdit << " tidak ditemukan.\n";
            }
            break;
        }
        case 5: { // Hapus barang
            int idHapus;
            cout << "Masukkan ID barang yang akan dihapus: ";
            cin >> idHapus;
            bool ditemukan = false;
            int i = 0;
            while (i < jumlahBarang) {
                if (stok[i].getId() == idHapus) {
                    int j = i;
                    while (j < jumlahBarang - 1) {
                        stok[j] = stok[j + 1];
                        j++;
                    }
                    jumlahBarang--;
                    cout << "Barang berhasil dihapus!\n";
                    ditemukan = true;
                }
                i++;
            }
            if (!ditemukan) {
                cout << "Barang dengan ID " << idHapus << " tidak ditemukan.\n";
            }
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