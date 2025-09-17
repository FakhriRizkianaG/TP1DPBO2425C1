<?php
require_once "BarangElektronik.php";
session_start();

if (!isset($_SESSION['stok'])) {
    $_SESSION['stok'] = [];
}

// Fungsi untuk menangani upload gambar
function uploadImage($fileInputName) {
    if (isset($_FILES[$fileInputName]) && $_FILES[$fileInputName]['error'] == UPLOAD_ERR_OK) {
        $targetDir = "Images/";
        if (!is_dir($targetDir)) {
            mkdir($targetDir, 0777, true);
        }

        $fileName = basename($_FILES[$fileInputName]['name']);
        $targetFile = $targetDir . time() . "_" . $fileName;

        // Validasi file (hanya gambar)
        $imageFileType = strtolower(pathinfo($targetFile, PATHINFO_EXTENSION));
        $allowed = ["jpg", "jpeg", "png", "gif"];
        if (!in_array($imageFileType, $allowed)) {
            echo "<p style='color:red;'>Format gambar tidak valid. Gunakan JPG, JPEG, PNG, atau GIF.</p>";
            return "";
        }

        if (move_uploaded_file($_FILES[$fileInputName]['tmp_name'], $targetFile)) {
            return $targetFile;
        } else {
            echo "<p style='color:red;'>Gagal mengupload gambar.</p>";
            return "";
        }
    }
    return "";
}

// Tambah barang
if (isset($_POST['tambah'])) {
    $id = $_POST['id'];
    $nama = $_POST['nama'];
    $manufaktur = $_POST['manufaktur'];
    $harga = $_POST['harga'];

    $imagePath = uploadImage('image');

    $idDuplikat = false;
    foreach ($_SESSION['stok'] as $barang) {
        if ($barang->getId() == $id) {
            $idDuplikat = true;
        }
    }

    if (!$idDuplikat) {
        $_SESSION['stok'][] = new BarangElektronik($id, $nama, $manufaktur, $harga, $imagePath);
    } else {
        echo "<p style='color:red;'>Gagal menambahkan! ID $id sudah ada.</p>";
    }
}

// Edit barang
if (isset($_POST['edit'])) {
    $idLama = $_POST['id_lama'];
    foreach ($_SESSION['stok'] as $barang) {
        if ($barang->getId() == $idLama) {
            $barang->setId($_POST['id']);
            $barang->setNama($_POST['nama']);
            $barang->setManufaktur($_POST['manufaktur']);
            $barang->setHarga($_POST['harga']);

            $imagePath = uploadImage('image_edit');
            if ($imagePath != "") {
                $barang->setImage($imagePath);
            }
        }
    }
}

// Hapus barang
if (isset($_POST['hapus'])) {
    $idHapus = $_POST['id_hapus'];
    foreach ($_SESSION['stok'] as $key => $barang) {
        if ($barang->getId() == $idHapus) {
            // hapus file gambar dari folder
            if ($barang->getImage() && file_exists($barang->getImage())) {
                unlink($barang->getImage());
            }
            unset($_SESSION['stok'][$key]);
        }
    }
}

// Pencarian
$cari = isset($_GET['cari']) ? $_GET['cari'] : "";
$stokFiltered = [];
if ($cari != "") {
    foreach ($_SESSION['stok'] as $barang) {
        if (stripos($barang->getNama(), $cari) !== false || stripos($barang->getManufaktur(), $cari) !== false) {
            $stokFiltered[] = $barang;
        }
    }
} else {
    $stokFiltered = $_SESSION['stok'];
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Frizkian Elec</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

<h1>Frizkian Elec Catalogue</h1>

<!-- Form Pencarian -->
<form method="get" class="search-box">
    <input type="text" name="cari" placeholder="Cari barang..." value="<?= htmlspecialchars($cari) ?>">
    <button type="submit">Cari</button>
</form>

<!-- Tabel Stok -->
<table>
    <tr>
        <th>ID</th>
        <th>Nama</th>
        <th>Manufaktur</th>
        <th>Harga</th>
        <th>Gambar</th>
        <th>Aksi</th>
    </tr>
    <?php if (count($stokFiltered) > 0): ?>
        <?php foreach ($stokFiltered as $barang): ?>
            <tr>
                <td><?= $barang->getId() ?></td>
                <td><?= htmlspecialchars($barang->getNama()) ?></td>
                <td><?= htmlspecialchars($barang->getManufaktur()) ?></td>
                <td>Rp<?= number_format($barang->getHarga(), 0, ',', '.') ?></td>
                <td>
                    <?php if ($barang->getImage()): ?>
                        <img src="<?= htmlspecialchars($barang->getImage()) ?>" alt="Gambar">
                    <?php else: ?>
                        <span>-</span>
                    <?php endif; ?>
                </td>
                <td>
                    <form method="post" style="display:inline;">
                        <input type="hidden" name="id_hapus" value="<?= $barang->getId() ?>">
                        <button type="submit" name="hapus" class="btn-hapus" onclick="return confirm('Hapus barang ini?')">
                            Hapus
                        </button>
                    </form>
                </td>
            </tr>
        <?php endforeach; ?>
    <?php else: ?>
        <tr><td colspan="6">Tidak ada barang yang ditemukan.</td></tr>
    <?php endif; ?>
</table>

<hr class="divider">

<!-- Form Tambah Barang -->
<h3>Tambah Barang</h3>
<form method="post" enctype="multipart/form-data">
    <input type="number" name="id" placeholder="ID" required>
    <input type="text" name="nama" placeholder="Nama" required>
    <input type="text" name="manufaktur" placeholder="Manufaktur" required>
    <input type="number" name="harga" placeholder="Harga" required>
    <input type="file" name="image" accept="image/*">
    <button type="submit" name="tambah">Tambah</button>
</form>

<hr class="divider">

<!-- Form Edit Barang -->
<h3>Edit Barang</h3>
<form method="post" enctype="multipart/form-data">
    <input type="number" name="id_lama" placeholder="ID Lama" required>
    <input type="number" name="id" placeholder="ID Baru" required>
    <input type="text" name="nama" placeholder="Nama Baru" required>
    <input type="text" name="manufaktur" placeholder="Manufaktur Baru" required>
    <input type="number" name="harga" placeholder="Harga Baru" required>
    <input type="file" name="image_edit" accept="image/*">
    <button type="submit" name="edit">Edit</button>
</form>

</body>
</html>

