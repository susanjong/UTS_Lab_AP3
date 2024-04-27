// Header 
#include <iostream> // header file library dalam c++
#include <string> // header untuk manipulasi string
using namespace std; // dipaaki untuk nama dari object dan variabel dari standar library

int main() // function 
{ // blok program dimulai 

   // Mendeklarasikan variabel yang diperlukan
   long long nomorkartu; // Menampung nomor kartu yang panjangnya mencapai 16 digit
   char digit; // Variabel untuk menyimpan digit nomor kartu saat dilakukan operasi per digit
   int total = 0; // Menyimpan total nilai setelah dilakukan operasi checksum
   bool checksum = false; // Menentukan apakah sedang melakukan operasi checksum pada digit kartu

   // Input nomor kartu
   cout << "Masukkan nomor kartu: "; // untuk output yang dimana harus memasukkan inputan nomor kartu 
   cin >> nomorkartu; // membaca/ memproses inputan
   cout << "Nomor Kartu Anda: " << nomorkartu << endl; //unutk output tampilan nomor kartu yang telah di input 

   string nomorStr = to_string(nomorkartu); // Konversi nomor kartu ke string

   // Loop untuk melakukan operasi checksum pada setiap digit nomor kartu
   for (int i = nomorStr.length() - 1; i >= 0; i--) { // Memakai perintah looping dimulai dari digit paling terkahir di sebalah kanan nomor kartu dan berjalan ke belakang sampai digit pertama bagian paling kiri
      // Lopping for dipakai untuk melakukan operasi checksum pada setiap digit nomor kartu
      digit = nomorStr[i]; // Mengambil digit dari belakang nomor kartu dengan memakai fitur tambahan yaitu array

      // Melakukan perintah if 
      if (checksum) { // untuk mperiksa bagian checksum
         digit = ((digit - '0') * 2) + '0'; // Melakukan operasi double digit jika sedang dalam status checksum
         if (digit > '9') { // melakukan pemisalan jika digit lebih besar dari 9
            digit = (digit - '0' - 9) + '0'; // Jika if yang udah kita lakuin pemisalan dinyatakan sesuai maka dijalankan perintah ini
            // sambungannya -->  maka akan dicocokan digitnya
         }
      }

      total += (digit - '0'); // Menambahkan hasil digit ke total setelah dikonversi ke angka
      checksum = !checksum; // Memakai perintah bool membalikkan nilai kebenaran dari suatu ekspresi boolean  sehingga status checksum akan terganti untuk operasi pada digit berikutnya
   }

   // Memeriksa hasil checksum untuk menentukan tipe kartu. Ini termasuk bagian algorithm Luhn untuk memvalidasi nomor kartu/ debit diketahui atau tidak
   if (total % 10 == 0) { // untuk validasi kartu tipe, akan memeriksa nilai total setelah operasi checksum habis dibagi 10
      cout << "Tipe Kartu Anda: "; // output untuk tampillin tipe kartu anda

      if (nomorStr.length() == 16 && nomorStr[0] == '5') { // mengecek nomor kartu yang dimasukkan memiliki panjang 16 karakter dan dimulai dengan digit 5 atau bukan. 
         //sambungannya bagian if --> dengan menggunakan ekspresi perbandingan
         cout << "MASTERCARD" << endl; // untuk tmapilin output apabila memenuhi perintah if nya

      } else if ((nomorStr.length() == 13 || nomorStr.length() == 16) && nomorStr[0] == '4') {
         // sambungan-->  Mengecek apakah nomor kartu memiliki panjang 13 atau 16 karakter
         // sambungan ke 2 --> dan dimulai dengan digit 4, yang merupakan kriteria untuk kartu VISA
         cout << "VISA" << endl; //jika else if nya terpenuhi makan tampilin output ini

    } 
    
    else { // jika perintah if  dan else if nya tidak terpenuhi
         cout << "TIDAK DIKETAHUI" << endl; // maka tampillin output ini 
      }

   } else { // jika perintah if dalam if nyanya tidak terpenuhi
      cout << "Tipe Kartu Anda: TIDAK VALID" << endl; // tampilin output ini
   }

   cout << "Hasil Checksum adalah : " << total << endl; // Tampilin hasil angka checksumnya apabila semua inputan sudah dimasukkin

   return 0; // akhir dari main function.
}  // akhir blok pemrograman secara keseluruhan
