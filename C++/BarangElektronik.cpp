#include <iostream>
#include <string>
using namespace std;

class BarangElektronik {
private:
    int id;
    string nama;
    string manufaktur;
    int harga;

public:
    // ✅ Constructor default WAJIB ada kalau pakai array of object
    BarangElektronik() {
        id = -1;
        nama = "";
        manufaktur = "";
        harga = 0;
    }
    
    // Constructor
    BarangElektronik(int _id, string _nama, string _manufaktur, int _harga) {
        id = _id;
        nama = _nama;
        manufaktur = _manufaktur;
        harga = _harga;
    }

    // Getter dan Setter untuk id
    int getId() {
        return id;
    }
    void setId(int _id) {
        id = _id;
    }

    // Getter dan Setter untuk nama
    string getNama() {
        return nama;
    }
    void setNama(string _nama) {
        nama = _nama;
    }

    // Getter dan Setter untuk manufaktur
    string getManufaktur() {
        return manufaktur;
    }
    void setManufaktur(string _manufaktur) {
        manufaktur = _manufaktur;
    }

    // Getter dan Setter untuk harga
    int getHarga() {
        return harga;
    }
    void setHarga(int _harga) {
        harga = _harga;
    }

    // Method untuk menampilkan informasi barang
    void tampilkanInfo() {
        cout << "ID: " << id << endl;
        cout << "Nama: " << nama << endl;
        cout << "Manufaktur: " << manufaktur << endl;
        cout << "Harga: Rp" << harga << endl;
    }
};