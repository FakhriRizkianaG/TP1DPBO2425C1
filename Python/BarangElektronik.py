class BarangElektronik:
    def __init__(self, id=-1, nama="", manufaktur="", harga=0):
        self.__id = id
        self.__nama = nama
        self.__manufaktur = manufaktur
        self.__harga = harga

    # Getter & Setter
    def get_id(self):
        return self.__id

    def set_id(self, id):
        self.__id = id

    def get_nama(self):
        return self.__nama

    def set_nama(self, nama):
        self.__nama = nama

    def get_manufaktur(self):
        return self.__manufaktur

    def set_manufaktur(self, manufaktur):
        self.__manufaktur = manufaktur

    def get_harga(self):
        return self.__harga

    def set_harga(self, harga):
        self.__harga = harga

    def tampilkan_info(self):
        print(f"ID: {self.__id}")
        print(f"Nama: {self.__nama}")
        print(f"Manufaktur: {self.__manufaktur}")
        print(f"Harga: Rp{self.__harga}")