import java.util.ArrayList;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        ArrayList<BarangElektronik> stok = new ArrayList<>();
        Scanner input = new Scanner(System.in);
        int pilihan;

        do {
            System.out.println("\n===== MENU =====");
            System.out.println("[1] Tampilkan stok yang tersedia");
            System.out.println("[2] Cari barang");
            System.out.println("[3] Tambah barang");
            System.out.println("[4] Edit barang");
            System.out.println("[5] Hapus barang");
            System.out.println("[0] Exit");
            System.out.print("Pilih menu: ");
            pilihan = input.nextInt();

            switch (pilihan) {
                case 1 -> { // Tampilkan stok
                    System.out.println("\n=== Daftar Stok Barang ===");
                    if (stok.isEmpty()) {
                        System.out.println("Belum ada barang yang tersimpan.");
                    } else {
                        int i = 0;
                        while (i < stok.size()) {
                            System.out.println("\nBarang ke-" + (i + 1) + ":");
                            stok.get(i).tampilkanInfo();
                            i++;
                        }
                    }
                }
                case 2 -> { // Cari barang
                    System.out.print("Masukkan ID barang yang dicari: ");
                    int idCari = input.nextInt();
                    boolean ditemukan = false;
                    int i = 0;
                    while (i < stok.size() && !ditemukan) {
                        if (stok.get(i).getId() == idCari) {
                            System.out.println("\nBarang ditemukan:");
                            stok.get(i).tampilkanInfo();
                            ditemukan = true;
                        }
                        i++;
                    }
                    if (!ditemukan) {
                        System.out.println("Barang dengan ID " + idCari + " tidak ditemukan.");
                    }
                }
                case 3 -> { // Tambah barang
                    System.out.print("Masukkan ID: ");
                    int id = input.nextInt();

                    boolean idDuplikat = false;
                    int i = 0;
                    while (i < stok.size()) {
                        if (stok.get(i).getId() == id) {
                            idDuplikat = true;
                        }
                        i++;
                    }

                    if (idDuplikat) {
                        System.out.println("Gagal menambahkan! ID " + id + " sudah digunakan.");
                        break;
                    }

                    input.nextLine(); // clear buffer
                    System.out.print("Masukkan Nama: ");
                    String nama = input.nextLine();
                    System.out.print("Masukkan Manufaktur: ");
                    String manufaktur = input.nextLine();
                    System.out.print("Masukkan Harga: ");
                    int harga = input.nextInt();

                    stok.add(new BarangElektronik(id, nama, manufaktur, harga));
                    System.out.println("Barang berhasil ditambahkan!");
                }
                case 4 -> { // Edit barang
                    System.out.print("Masukkan ID barang yang akan diedit: ");
                    int idEdit = input.nextInt();
                    boolean ditemukan = false;
                    int i = 0;

                    while (i < stok.size() && !ditemukan) {
                        if (stok.get(i).getId() == idEdit) {
                            System.out.print("Masukkan ID baru: ");
                            int idBaru = input.nextInt();

                            boolean idDuplikat = false;
                            int k = 0;
                            while (k < stok.size()) {
                                if (k != i && stok.get(k).getId() == idBaru) {
                                    idDuplikat = true;
                                }
                                k++;
                            }

                            if (idDuplikat) {
                                System.out.println("Gagal mengubah ID! ID " + idBaru + " sudah digunakan.");
                            } else {
                                stok.get(i).setId(idBaru);
                                input.nextLine(); // clear buffer
                                System.out.print("Masukkan Nama baru: ");
                                String nama = input.nextLine();
                                System.out.print("Masukkan Manufaktur baru: ");
                                String manufaktur = input.nextLine();
                                System.out.print("Masukkan Harga baru: ");
                                int harga = input.nextInt();

                                stok.get(i).setNama(nama);
                                stok.get(i).setManufaktur(manufaktur);
                                stok.get(i).setHarga(harga);

                                System.out.println("Barang berhasil diperbarui!");
                            }
                            ditemukan = true;
                        }
                        i++;
                    }

                    if (!ditemukan) {
                        System.out.println("Barang dengan ID " + idEdit + " tidak ditemukan.");
                    }
                }
                case 5 -> { // Hapus barang
                    System.out.print("Masukkan ID barang yang akan dihapus: ");
                    int idHapus = input.nextInt();
                    boolean ditemukan = false;
                    int i = 0;

                    while (i < stok.size()) {
                        if (stok.get(i).getId() == idHapus) {
                            stok.remove(i);
                            System.out.println("Barang berhasil dihapus!");
                            ditemukan = true;
                        }
                        i++;
                    }
                    if (!ditemukan) {
                        System.out.println("Barang dengan ID " + idHapus + " tidak ditemukan.");
                    }
                }
                case 0 -> {
                    System.out.println("Have a nice day :D");
                    input.close();
                    return;
                }
                default -> System.out.println("Pilihan tidak valid!");
            }
        } while (pilihan != 0);
    }
}
