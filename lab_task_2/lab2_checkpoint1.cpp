#include <bits/stdc++.h>
using namespace std;

// Apply a Caesar shift: positive 'k' shifts forward (encode), negative shifts backward (decode)
string caesarShift(const string &text, int k) {
    string out = text;
    k = (k % 26 + 26) % 26; // normalize k into 0..25
    for (size_t i = 0; i < out.size(); ++i) {
        char ch = out[i];
        if (ch >= 'a' && ch <= 'z') {
            out[i] = char('a' + (ch - 'a' + k) % 26);
        } else if (ch >= 'A' && ch <= 'Z') {
            out[i] = char('A' + (ch - 'A' + k) % 26);
        } else {
            // non-alphabetic characters remain unchanged
            out[i] = ch;
        }
    }
    return out;
}

// Convenience wrappers
string decodeWithKey(const string &cipher, int key) {
    // decoding is shifting backwards by key -> same as shifting forward by (26-key)
    return caesarShift(cipher, -key);
}
string encodeWithKey(const string &plain, int key) {
    return caesarShift(plain, key);
}

int main() {
    const string cipher = "odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo";

    cout << "Trying all possible keys (1..25):\n";
    for (int key = 1; key < 26; ++key) {
        string candidate = decodeWithKey(cipher, key);
        cout << "Key = " << setw(2) << key << " -> " << candidate << '\n';
    }

    // show explicit decode/encode using key 10
    const int chosenKey = 10;
    string decoded = decodeWithKey(cipher, chosenKey);
    cout << "\nDecoded using key " << chosenKey << ":\n" << decoded << "\n";

    string reEncoded = encodeWithKey(decoded, chosenKey);
    cout << "Re-encoded using key " << chosenKey << " (should match original cipher):\n" 
         << reEncoded << "\n";

    // quick check
    if (reEncoded == cipher) {
        cout << "\nRound-trip check: OK (re-encoded == original cipher)\n";
    } else {
        cout << "\nRound-trip check: MISMATCH\n";
    }

    return 0;
}
