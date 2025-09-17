public class BarangElektronik {
    private int id;
    private String nama;
    private String manufaktur;
    private int harga;

    // Constructor default
    public BarangElektronik() {
        this.id = -1;
        this.nama = "";
        this.manufaktur = "";
        this.harga = 0;
    }

    // Constructor dengan parameter
    public BarangElektronik(int id, String nama, String manufaktur, int harga) {
        this.id = id;
        this.nama = nama;
        this.manufaktur = manufaktur;
        this.harga = harga;
    }

    // Getter dan Setter
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public String getManufaktur() {
        return manufaktur;
    }

    public void setManufaktur(String manufaktur) {
        this.manufaktur = manufaktur;
    }

    public int getHarga() {
        return harga;
    }

    public void setHarga(int harga) {
        this.harga = harga;
    }

    public void tampilkanInfo() {
        System.out.println("ID: " + id);
        System.out.println("Nama: " + nama);
        System.out.println("Manufaktur: " + manufaktur);
        System.out.println("Harga: Rp" + harga);
    }
}
