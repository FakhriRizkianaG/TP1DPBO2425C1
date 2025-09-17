from BarangElektronik import BarangElektronik

def tampilkan_stok(stok):
    print("\n=== Daftar Stok Barang ===")
    if len(stok) == 0:
        print("Belum ada barang yang tersimpan.")
    else:
        i = 0
        while i < len(stok):
            print(f"\nBarang ke-{i+1}:")
            stok[i].tampilkan_info()
            i += 1


def cari_barang(stok):
    id_cari = int(input("Masukkan ID barang yang dicari: "))
    ditemukan = False
    i = 0
    while i < len(stok) and not ditemukan:
        if stok[i].get_id() == id_cari:
            print("\nBarang ditemukan:")
            stok[i].tampilkan_info()
            ditemukan = True
        i += 1
    if not ditemukan:
        print(f"Barang dengan ID {id_cari} tidak ditemukan.")


def tambah_barang(stok):
    id_baru = int(input("Masukkan ID: "))
    i = 0
    id_duplikat = False
    while i < len(stok):
        if stok[i].get_id() == id_baru:
            id_duplikat = True
        i += 1

    if id_duplikat:
        print(f"Gagal menambahkan! ID {id_baru} sudah digunakan.")
        return

    nama = input("Masukkan Nama: ")
    manufaktur = input("Masukkan Manufaktur: ")
    harga = int(input("Masukkan Harga: "))

    stok.append(BarangElektronik(id_baru, nama, manufaktur, harga))
    print("Barang berhasil ditambahkan!")


def edit_barang(stok):
    id_edit = int(input("Masukkan ID barang yang akan diedit: "))
    ditemukan = False
    i = 0

    while i < len(stok) and not ditemukan:
        if stok[i].get_id() == id_edit:
            id_baru = int(input("Masukkan ID baru: "))
            # Validasi agar ID tidak duplikat
            k = 0
            id_duplikat = False
            while k < len(stok):
                if k != i and stok[k].get_id() == id_baru:
                    id_duplikat = True
                k += 1

            if id_duplikat:
                print(f"Gagal mengubah ID! ID {id_baru} sudah digunakan.")
            else:
                stok[i].set_id(id_baru)
                nama = input("Masukkan Nama baru: ")
                manufaktur = input("Masukkan Manufaktur baru: ")
                harga = int(input("Masukkan Harga baru: "))

                stok[i].set_nama(nama)
                stok[i].set_manufaktur(manufaktur)
                stok[i].set_harga(harga)

                print("Barang berhasil diperbarui!")
            ditemukan = True
        i += 1

    if not ditemukan:
        print(f"Barang dengan ID {id_edit} tidak ditemukan.")


def hapus_barang(stok):
    id_hapus = int(input("Masukkan ID barang yang akan dihapus: "))
    i = 0
    ditemukan = False

    while i < len(stok):
        if stok[i].get_id() == id_hapus:
            stok.pop(i)
            print("Barang berhasil dihapus!")
            ditemukan = True
            # tidak break agar bisa hapus semua barang dengan ID sama (jika ada)
        i += 1

    if not ditemukan:
        print(f"Barang dengan ID {id_hapus} tidak ditemukan.")


def main():
    stok = []
    while True:
        print("\n===== MENU =====")
        print("[1] Tampilkan stok yang tersedia")
        print("[2] Cari barang")
        print("[3] Tambah barang")
        print("[4] Edit barang")
        print("[5] Hapus barang")
        print("[0] Exit")
        pilihan = input("Pilih menu: ")

        if pilihan == "1":
            tampilkan_stok(stok)
        elif pilihan == "2":
            cari_barang(stok)
        elif pilihan == "3":
            tambah_barang(stok)
        elif pilihan == "4":
            edit_barang(stok)
        elif pilihan == "5":
            hapus_barang(stok)
        elif pilihan == "0":
            print("Have a nice day :D")
            break
        else:
            print("Pilihan tidak valid!")


if __name__ == "__main__":
    main()
