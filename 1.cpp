#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nim;
    string nama;
    int nilai;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    // dynamic array manual untuk menyimpan nilai
    int capacity = 2;
    int size = 0;
    int* nilaiArray = new int[capacity];

    //  input data mahasiswa ke linked list 
    cout << "Masukkan data mahasiswa (NIM Nama Nilai):" << endl;
    for (int i = 0; i < n; i++) {
        string nim, nama;
        int nilai;
        cout << "Mahasiswa ke-" << i + 1 << ": ";
        cin >> nim >> nama >> nilai;

        // alokasi node baru
        Node* nodeBaru = new Node();
        nodeBaru->nim = nim;
        nodeBaru->nama = nama;
        nodeBaru->nilai = nilai;
        nodeBaru->next = nullptr;

        // tambah node baru ke linked list
        if (head == nullptr) {
            head = nodeBaru;
            tail = nodeBaru;
        } else {
            tail->next = nodeBaru;
            tail = nodeBaru;
        }

        // simpan nilai ke dynamic array
        if (size == capacity) {
            capacity *= 2;
            int* tempArr = new int[capacity];
            for (int j = 0; j < size; j++) {
                tempArr[j] = nilaiArray[j];
            }
            delete[] nilaiArray;
            nilaiArray = tempArr;
        }
        nilaiArray[size] = nilai;
        size++;
    }

    // showing data awal
    cout << endl;
    cout << "Data awal:" << endl;
    cout << "NIM     Nama     Nilai" << endl;
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->nim << "     " << temp->nama << "     " << temp->nilai << endl;
        temp = temp->next;
    }

    // pake insertion sort untuk mengurutkan nilai data kecil ke besar
    for (int i = 1; i < size; i++) {
        int key = nilaiArray[i];
        int j = i - 1;
        while (j >= 0 && nilaiArray[j] > key) {
            nilaiArray[j + 1] = nilaiArray[j];
            j--;
        }
        nilaiArray[j + 1] = key;
    }

    cout << endl;
    cout << "Nilai setelah diurutkan (Insertion Sort): ";
    for (int i = 0; i < size; i++) {
        cout << nilaiArray[i] << " ";
    }
    cout << endl;

    //  linear search nim pada linked list 
    string nimCari;
    cout << endl;
    cout << "Masukkan NIM yang dicari (Linear Search): ";
    cin >> nimCari;

    temp = head;
    int indexLinear = 0;
    bool ketemuNIM = false;
    while (temp != nullptr) {
        if (temp->nim == nimCari) {
            cout << "NIM ditemukan pada urutan ke-" << indexLinear + 1 << endl;
            ketemuNIM = true;
            break;
        }
        temp = temp->next;
        indexLinear++;
    }
    if (!ketemuNIM) {
        cout << "NIM tidak ditemukan" << endl;
    }

    //  binary search nilai pada dynamic array
    int nilaiCari;
    cout << "Masukkan nilai yang dicari (Binary Search): ";
    cin >> nilaiCari;

    int low = 0;
    int high = size - 1;
    int hasilBinary = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nilaiArray[mid] == nilaiCari) {
            hasilBinary = mid;
            break;
        } else if (nilaiCari < nilaiArray[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (hasilBinary != -1) {
        cout << "Nilai ditemukan pada indeks : " << hasilBinary << endl;
    } else {
        cout << "Nilai tidak ditemukan" << endl;
    }

    // bersihin dynamic array
    delete[] nilaiArray;

    return 0;
}