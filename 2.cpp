#include <iostream>
#include <string>
using namespace std;

struct NodeQueue {
    string nim;
    string nama;
    NodeQueue* next;
};

NodeQueue* front = nullptr;
NodeQueue* rear = nullptr;

void enqueue(string nim, string nama) {
    NodeQueue* baru = new NodeQueue{nim, nama, nullptr};
    if (!rear) {
        front = rear = baru;
        return;
    }
    rear->next = baru;
    rear = baru;
}

void dequeue() {
    if (!front) {
        cout << "Antrian kosong!" << endl;
        return;
    }
    NodeQueue* temp = front;
    cout << "Meminjam buku untuk: " << temp->nim << " " << temp->nama << endl;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

void tampilkanAntrian() {
    cout << "Isi Antrian (peminjaman): ";
    NodeQueue* temp = front;
    if (!temp) {
        cout << "kosong" << endl;
        return;
    }
    while (temp) {
        cout << temp->nim << " ";
        temp = temp->next;
    }
    cout << endl;
}

struct NodeStack {
    string idBuku;
    NodeStack* next;
};

NodeStack* top = nullptr;

void push(string idBuku) {
    NodeStack* baru = new NodeStack{idBuku, nullptr};
    baru->next = top;
    top = baru;
}

void pop() {
    if (!top) {
        cout << "Riwayat kosong!" << endl;
        return;
    }
    NodeStack* temp = top;
    cout << "Mengembalikan buku: " << temp->idBuku << endl;
    top = top->next;
    delete temp;
}

void tampilkanRiwayat() {
    cout << "Riwayat Pengembalian (LIFO): ";
    NodeStack* temp = top;
    if (!temp) {
        cout << "kosong" << endl;
        return;
    }
    while (temp) {
        cout << temp->idBuku << " ";
        temp = temp->next;
    }
    cout << endl;
}

struct NodeTree {
    string id;
    NodeTree* kiri;
    NodeTree* kanan;
};

void tambahBST(NodeTree*& root, string id) {
    if (root == NULL) {
        root = new NodeTree;
        root->id = id;
        root->kiri = NULL;
        root->kanan = NULL;
    } else if (id < root->id) {
        tambahBST(root->kiri, id);
    } else if (id > root->id) {
        tambahBST(root->kanan, id);
    }
}

bool cariBST(NodeTree* root, string target) {
    if (root == NULL) return false;
    if (root->id == target) return true;
    if (target < root->id) return cariBST(root->kiri, target);
    return cariBST(root->kanan, target);
}

void preOrder(NodeTree* root) {
    if (root != NULL) {
        cout << root->id << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(NodeTree* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->id << " ";
        inOrder(root->kanan);
    }
}

void postOrder(NodeTree* root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->id << " ";
    }
}

int main() {
    NodeTree* root = NULL;
    int pilihan;

    enqueue("2201001", "Andi");
    enqueue("2201002", "Budi");
    enqueue("2201003", "Citra");

    push("B001");
    push("B002");

    tambahBST(root, "B003");
    tambahBST(root, "B001");
    tambahBST(root, "B005");
    tambahBST(root, "B002");
    tambahBST(root, "B004");

    do {
        cout << endl;
        cout << " Sistem Antrian & Buku Perpustakaan " << endl;
        cout << "1. Tambah antrian peminjaman" << endl;
        cout << "2. Proses peminjaman (dequeue)" << endl;
        cout << "3. Tambah pengembalian buku (push)" << endl;
        cout << "4. Proses pengembalian (pop)" << endl;
        cout << "5. Tambah buku ke BST" << endl;
        cout << "6. Cari ID Buku di BST" << endl;
        cout << "7. Tampilkan traversal BST" << endl;
        cout << "8. Tampilkan semua data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nim, nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Nama: ";
            cin >> nama;
            enqueue(nim, nama);
        } else if (pilihan == 2) {
            dequeue();
        } else if (pilihan == 3) {
            string id;
            cout << "Masukkan ID Buku: ";
            cin >> id;
            push(id);
        } else if (pilihan == 4) {
            pop();
        } else if (pilihan == 5) {
            string id;
            cout << "Masukkan ID Buku: ";
            cin >> id;
            tambahBST(root, id);
        } else if (pilihan == 6) {
            string idCari;
            cout << "Masukkan ID Buku yang dicari: ";
            cin >> idCari;
            if (cariBST(root, idCari)) {
                cout << "ID Buku " << idCari << " Ditemukan di dalam BST!" << endl;
            } else {
                cout << "ID Buku " << idCari << " Tidak Ditemukan!" << endl;
            }
        } else if (pilihan == 7) {
            cout << "Pre-Order  : ";
            preOrder(root);
            cout << endl;
            cout << "In-Order   : ";
            inOrder(root);
            cout << endl;
            cout << "Post-Order : ";
            postOrder(root);
            cout << endl;
        } else if (pilihan == 8) {
            tampilkanAntrian();
            tampilkanRiwayat();
            cout << "Isi BST (In-Order): ";
            inOrder(root);
            cout << endl;
        }
    } while (pilihan != 0);

    return 0;
}