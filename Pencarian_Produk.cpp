#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> // Untuk transform()

using namespace std;

// Fungsi untuk mencocokkan string dengan algoritma brute force (case insensitive)
vector<int> bruteForceStringMatch(const string& text, const string& pattern) {
    vector<int> matches;
    string lower_text = text;
    string lower_pattern = pattern;

    // Mengonversi kedua string menjadi huruf kecil
    transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);
    transform(lower_pattern.begin(), lower_pattern.end(), lower_pattern.begin(), ::tolower);

    int n = lower_text.length();
    int m = lower_pattern.length();

    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (lower_text[i + j] != lower_pattern[j])
                break;
        }
        if (j == m)
            matches.push_back(i); // Cocok
    }
    return matches;
}

int main() {
    std::cout << "===== PROGRAM MENCOCOKAN USERNAME =====\n";
    std::cout << "Nama : Rianawati\n";
    std::cout << "Nim  : 20533390\n";
    std::cout << "========================================\n";
    std::cout << "Kategori Produk= Minuman: KopiTeh,Susu,Jus, Makanan : Roti,Kue,Donat,Pasta, Snack : Keripik,Coklat,Kacang,Permen";

    // Menggunakan unordered_map untuk menyimpan produk berdasarkan kategori mereka
    unordered_map<string, vector<string>> categories = {
        {"Minuman", {"Kopi", "Teh", "Susu", "Jus"}},
        {"Makanan", {"Roti", "Kue", "Donat", "Pasta"}},
        {"Snack", {"Keripik", "Coklat", "Kacang", "Permen"}},
        // Tambahkan kategori lainnya di sini
    };

    // Input pencarian
    string search_query;
    cout << "\n\nMasukkan nama produk yang ingin Anda cari: ";
    getline(cin, search_query);

    // Mencocokkan produk dengan pencarian menggunakan algoritma brute force (case insensitive)
    vector<int> matches;
    for (auto& category : categories) {
        for (int i = 0; i < category.second.size(); ++i) {
            vector<int> match_indices = bruteForceStringMatch(category.second[i], search_query);
            for (int index : match_indices) {
                matches.push_back(i); // Menyimpan indeks produk yang cocok dalam kategori
            }
        }
    }

    // Menampilkan hasil pencarian
    if (matches.empty()) {
        cout << "Produk tidak ditemukan." << endl;
    } else {
        cout << "Produk ditemukan pada kategori dan indeks: ";
        for (int index : matches) {
            // Mendapatkan kategori berdasarkan indeks
            for (auto& category : categories) {
                if (index < category.second.size()) {
                    cout << category.first << " - " << category.second[index] << endl;
                    break;
                }
                index -= category.second.size();
            }
        }
    }

    return 0;
}
