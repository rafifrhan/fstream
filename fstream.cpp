#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

//deklarasi struct bernama input

struct Input
{
    float data;
}objek1, objek2; //objek dari struct input

//Deklarasi struct untuk hasil

struct Hasil
{
    float jumlah, kurang, kali, bagi;
}result;    //objek dari struct hasil

//fungsi untuk melakukan input dan menyimpannya ke dalam file

void input (Input objek1, Input objek2)
{
    // datainput1 dan datainput2 merupakan objek dari ofstream
    // data yang diinput disimpan dalam "input1.txt" dan "input2.txt"

    ofstream dataInput3 ("input3.txt", ios::app);
    ofstream dataInput4 ("input4.txt", ios::app);
    cout << "Masukkan bilangan pertama : "; cin >> objek1.data;
    cout << "Masukkan bilangan kedua : "; cin >> objek2.data;

    //menyimpan ke dalam file

    dataInput3.write((char*)& objek1, sizeof(objek1));
    dataInput4.write((char*)& objek2, sizeof(objek2));

    //menutup file

    dataInput3.close();
    dataInput4.close();
}

//fungsi untuk melakukan operasi aritmatika
void hitung(Input objek1, Input objek2)
{
    float bil1,bil2;
    hasil result;
    ofstream datahasil("hasil.txt", ios::in);

    //ifstream untuk membaca file (input1.txt)
    ifstream bukainput3("input3.txt", ios::in);
    bukainput3.read((char*)&objek1, sizeof(objek1));

    //operasi bil = nilai "data" pada objek1
    bil1 = objek1.data;
    
    //ifstream untuk membaca file (input2.txt)
    ifstream bukainput4("input4.txt", ios::in);
    bukainput4.read((char*)&objek2, sizeof(objek2));

    bil2 = objek2.data;    //operasi bill = nilai "data" pada objek2

    result.jumlah = bil1 + bil2;
    result.kurang = bil1 - bil2;
    result.kali = bil1 * bil2;
    result.bagi = bil1 / bil2;

    datahasil.write((char*)&result, sizeof(result));       //menulis hasil berupa objek ke dalam file

    bukainput3.close();
    bukainput4.close();
    datahasil.close();
}

void hasil(Hasil result)
{
    ifstream bukahasil("hasil.txt");       //membaca data objek yang ada di dalam file "hasil1.txt"

    bukahasil.read((char*)&result, sizeof(result));

    cout << "----Hasil----" << endl;
    cout << "-------------" << endl;
    cout << "Hasil Penjumlahan = " << result.jumlah << endl;
    cout << "Hasil Pengurangan = " << result.kurang << endl;
    cout << "Hasil Perkalian = " << result.kali << endl;
    cout << "Hasil Pembagian = " << result.bagi << endl;

    bukahasil.close();
}

int main()
{
    cout << "Operasi Aritmaika Pemrograman Deklaratif E" << endl;
    cout << "==========================================" << endl;   

    //memanggil fungsi
    input(objek1, objek2);
    hitung(objek1, objek2);
    hasil(result);

    _getch();

}

