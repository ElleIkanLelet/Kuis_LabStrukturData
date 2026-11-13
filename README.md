# Kuis_LabStrukturData

Nama: Gabrielle Christin Gilberyn Ginting

Nim: 251401047

KOM: B

Link Youtube: https://youtu.be/92ySxBzD0oY

Deskripsi Program

1. Sistem Pengelolaan Nilai Mahasiswa (1.cpp)
Program ini mengelola data nilai mahasiswa (NIM, nama, dan nilai) menggunakan dua struktur data utama:

* Single Linked List untuk menyimpan biodata mahasiswa.
* Dynamic Array untuk menampung seluruh daftar nilai.
* Algoritma Insertion Sort digunakan untuk mengurutkan nilai dari yang terkecil ke terbesar.
* Algoritma Linear Search digunakan untuk mencari data mahasiswa berdasarkan NIM.
* Algoritma Binary Search digunakan untuk pencarian nilai tertentu pada array yang sudah terurut.

2. Sistem Antrean dan Pengelolaan Buku Perpustakaan (2.cpp)
Program simulasi layanan perpustakaan untuk mencatat antrean peminjaman, histori pengembalian, dan daftar buku:

* Queue (FIFO) digunakan untuk mengelola antrean peminjaman buku mahasiswa.
* Stack (LIFO) digunakan untuk mencatat riwayat pengembalian buku teratas.
* Binary Search Tree (BST) digunakan untuk menyimpan data ID buku.
* Dilengkapi fungsi pencarian ID buku serta penelusuran pohon secara Pre-Order, In-Order, dan Post-Order.
* Menampilkan kondisi antrean terkini, riwayat transaksi pengembalian, dan isi pohon BST.

3. Sistem Pencarian Rute di Lingkungan Kampus (3.cpp)
Program navigasi antarlokasi di kampus menggunakan Graph berbobot dengan 6 titik (vertex A sampai F):

* Adjacency Matrix 6x6 digunakan untuk menyimpan relasi keterhubungan dan jarak antar-vertex.
* BFS dan DFS digunakan untuk melakukan penelusuran graf secara melebar dan mendalam.
* Algoritma Dijkstra digunakan untuk menemukan rute dengan total jarak terpendek dari lokasi awal ke tujuan.
* Menampilkan lintasan rute yang dilalui beserta total jarak tempuhnya.
* Pengguna dapat memilih sendiri titik awal keberangkatan dan lokasi tujuan.

4. Sistem Pengelolaan Data Mahasiswa Menggunakan Hash Table (4.cpp)
Program direktori data mahasiswa menggunakan Hash Table berukuran 20 slot dengan NIM sebagai key dan nama sebagai value:

* Menerapkan metode Double Hashing untuk menangani kondisi bentrokan data (collision).
* Rumus Hashing: Hash1(key) = key % 20 dan Hash2(key) = 19 - (key % 19).
* Memiliki fitur Insert, Search, Remove (lazy deletion), dan Display.
* Diuji menggunakan 15 data mahasiswa untuk membuktikan penanganan collision dan pembaruan status slot yang dihapus (DELETED).


Struktur Folder

Kuis_LabStrukturData/
├── 1.cpp
├── 2.cpp
├── 3.cpp
├── 4.cpp
└── README.md

