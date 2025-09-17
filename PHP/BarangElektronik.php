<?php
class BarangElektronik {
    private $id;
    private $nama;
    private $manufaktur;
    private $harga;
    private $image;

    public function __construct($id, $nama, $manufaktur, $harga, $image) {
        $this->id = $id;
        $this->nama = $nama;
        $this->manufaktur = $manufaktur;
        $this->harga = $harga;
        $this->image = $image;
    }

    public function getId() {
        return $this->id;
    }

    public function setId($id) {
        $this->id = $id;
    }

    public function getNama() {
        return $this->nama;
    }

    public function setNama($nama) {
        $this->nama = $nama;
    }

    public function getManufaktur() {
        return $this->manufaktur;
    }

    public function setManufaktur($manufaktur) {
        $this->manufaktur = $manufaktur;
    }

    public function getHarga() {
        return $this->harga;
    }

    public function setHarga($harga) {
        $this->harga = $harga;
    }

    public function getImage() {
        return $this->image;
    }

    public function setImage($image) {
        $this->image = $image;
    }
}
