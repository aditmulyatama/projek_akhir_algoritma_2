#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// deklarasi record utama
struct buku {
    int id, tahun, halaman;
    string judul, pengarang, penerbit;
};

void input(string namaFile), output(string namaFile), sort(string namaFile), cari(string namaFile), ubah(string namaFile), hapus(string namaFile), reset(string namaFile);

main() {
    int pilih;
    char konfirmasi;
    string namaFile;

    while(pilih != 8) {
        cout<<setfill('=')<<setw(40)<<'='<<"\n";
        cout<<"\tMenu Utama\n";
        cout<<setfill('=')<<setw(40)<<'='<<"\n";
        cout<<"1. Tambah Data\n2. Tampilan Data\n3. Pengurutan Data\n4. Pencarian Data\n5. Pengubahan Data\n6. Penghapusan Data\n7. Pengosongan Data\n8. Keluar Program\n";
        cout<<setfill('=')<<setw(40)<<'='<<"\n";

        // input pilihan menu
        cout<<"\nPilih\t: ";
        cin>>pilih;
        cin.ignore();

        if(pilih < 8 && pilih > 0){
            // input nama file
            cout<<"\nNama file\t= ";
            getline(cin, namaFile);

            system("cls");

            switch(pilih) {
            case 1:
                input(namaFile);
                break;
            case 2:
                cout<<setfill('=')<<setw(40)<<'='<<"\n";
                cout<<"\tOUTPUT DATA\n";
                cout<<setfill('=')<<setw(40)<<'='<<"\n";
                output(namaFile);
                break;
            case 3:
                sort(namaFile);
                break;
            case 4:
                cout<<setfill('=')<<setw(40)<<'='<<"\n";
                cout<<"\tPENCARIAN DATA\n";
                cout<<setfill('=')<<setw(40)<<'='<<"\n";
                cari(namaFile);
                break;
            case 5:
                cout<<setfill('=')<<setw(40)<<'='<<"\n";
                cout<<"\tPENGUBAHAN DATA\n";
                cout<<setfill('=')<<setw(40)<<'='<<"\n";

                ubah(namaFile);
                break;
            case 6:
                cout<<setfill('=')<<setw(40)<<'='<<"\n";
                cout<<"\tPENGHAPUSAN DATA\n";
                cout<<setfill('=')<<setw(40)<<'='<<"\n";

                hapus(namaFile);
                break;
            case 7:
                cout<<setfill('=')<<setw(40)<<'='<<"\n";
                cout<<"\tPENGOSONGAN FILE\n";
                cout<<setfill('=')<<setw(40)<<'='<<"\n";

                reset(namaFile);
                break;
            }
            cout<<setfill('=')<<setw(40)<<'='<<"\n";
            cout<<setfill('=')<<setw(40)<<'='<<"\n\n";
            system("pause");
        } else if (pilih ==8 ) {
            cout<<"Apakah anda yakin ingin keluar dari program? (ketik y jika iya)\n";
            cin>>konfirmasi;

            if(konfirmasi == 'y')
                exit(0);
            else pilih = 0;
        } else {
            cout<<"\nMasukan anda salah. Silakan ulangi lagi!\n";
            system("pause");
        }
        system("cls");
    }
}

void input(string namaFile){
    // deklarasi variabel record sementara untuk dimasukkan ke dalam file
    buku dataBuku;
    int banyak;

    cout<<setfill('=')<<setw(40)<<'='<<"\n";
    cout<<"\t\tINPUT DATA\n";
    cout<<setfill('=')<<setw(40)<<'='<<"\n";

    // input banyak data
    cout<<"Banyak data\t\t= ";
    cin>>banyak;
    cin.ignore();

    cout<<endl<<setfill('=')<<setw(40)<<'='<<"\n";

    // deklarasi variabel ofstream 
    ofstream inputFile(namaFile, ios::app);
    // kondisi apakah file terbuka atau tidak
    if(inputFile.is_open()) {
        // perulangan sejumlah banyak untuk input file
        for (int i = 0; i < banyak; i++) {
            cout<<"\nInput ke-"<<i + 1<<"\nJudul\t\t\t= ";
            getline(cin, dataBuku.judul);
            cout<<"Pengarang\t\t= ";
            getline(cin, dataBuku.pengarang);
            cout<<"Penerbit\t\t= ";
            getline(cin, dataBuku.penerbit);
            cout<<"Id\t\t\t= ";
            cin>>dataBuku.id;
            cout<<"Halaman\t\t\t= ";
            cin>>dataBuku.halaman;
            cout<<"Tahun terbit\t\t= ";
            cin>>dataBuku.tahun;
            cin.ignore();

            // memasukkan data dari variabel record ke dalam file
            inputFile<<dataBuku.judul<<'\t'<<dataBuku.pengarang<<'\t'<<dataBuku.penerbit<<'\t'<<dataBuku.id<<'\t'<<dataBuku.halaman<<'\t'<<dataBuku.tahun<<"\n";
        }
    } else
        cout <<"File tidak ditemukan.";
    // nutup file
    inputFile.close();
}

void output(string namaFile){
    // deklarasi variabel record sementara untuk dimasukkan ke dalam file
    buku dataBuku;
    int i = 1;

   

    // deklarasi variabel ifstream
    ifstream outputFile(namaFile);
    // kondisi apakah file terbuka atau tidak
    if(outputFile.is_open()) {
        // perulangan sampai akhir baris dari stream file
        while(outputFile.eof()==0) {
            //input data dari file ke variabel record lokal
            getline(outputFile, dataBuku.judul, '\t');
            getline(outputFile, dataBuku.pengarang, '\t');
            getline(outputFile, dataBuku.penerbit, '\t');
            outputFile>>dataBuku.id>>dataBuku.halaman>>dataBuku.tahun;
            outputFile.ignore();

            // output data dari variabel record lokal apabila baris tidak kosong
            if(dataBuku.judul!="") {
                cout<<"\nData ke-"<<i;
                cout<<"\nID buku\t\t\t: "<<dataBuku.id;
                cout<<"\nJudul Buku\t\t: "<<dataBuku.judul;
                cout<<"\nPengarang\t\t: "<<dataBuku.pengarang;
                cout<<"\nPenerbit\t\t: "<<dataBuku.penerbit;
                cout<<"\nJumlah Halaman\t\t: "<<dataBuku.halaman;
                cout<<"\nTahun Terbit\t\t: "<<dataBuku.tahun<<endl<<endl;

                i++;
            }
        }
        if(i==1)
            cout<<"Tidak ada data yang ditemukan dalam file ini.\n";
    } else
        cout <<"File tidak ditemukan.\n";
    // nutup file
    outputFile.close();
}

void sort(string namaFile){
    
    int pilihan, i = 0, j, k, kolom;
	buku temp, dataBuku[100];
    
    cout<<setfill('=')<<setw(40)<<'='<<"\n";
    cout<<"\tPENGURUTAN DATA\n";
    cout<<setfill('=')<<setw(40)<<'='<<"\n";
    cout<<"\nDaftar Kolom:\n\t1. Judul Buku\n\t2. Jumlah Halaman\n\t3. Tahun Terbit\n\t4. Penerbit\n\t5.Pengarang\n\t6. Kembali\n";

    // input pilihan menu
    cout<<"\nKolom yang ingin diurutkan\t= ";
    cin>>pilihan;


    // deklarasi variabel ifstream asal data
    ifstream asalData(namaFile);
    // kondisi apakah file terbuka atau tidak
    if(asalData.is_open()) {
        // perulangan sampai akhir baris dari stream file
        while(asalData.eof()==0) {
            //input data dari file ke variabel record lokal
            getline(asalData, dataBuku[i].judul, '\t');
            getline(asalData, dataBuku[i].pengarang, '\t');
            getline(asalData, dataBuku[i].penerbit, '\t');
            asalData>>dataBuku[i].id>>dataBuku[i].halaman>>dataBuku[i].tahun;
            asalData.ignore();
            i++;
        }

        // perulangan untuk sorting
        if(pilihan>0&&pilihan<7){

            
            for(j=0; j<i; j++){
                // mengisi variabel record temp dengan record dari file dengan indeks j
                temp = dataBuku[j];
                k = j - 1;
                // perulangan untuk menukar data yang memiliki nilai lebih besar dengan yang bernilai lebih kecil
                if(pilihan==1){
                        while((temp.judul < dataBuku[k].judul) & (k >= 0)){
                        dataBuku[k+1] = dataBuku[k];
                        k--;
                    }
                } else if(pilihan==2){
                        while((temp.halaman < dataBuku[k].halaman) & (k >= 0)){
                        dataBuku[k+1] = dataBuku[k];
                        k--;
                    }
                } else if(pilihan==3){
                        while((temp.tahun < dataBuku[k].tahun) & (k >= 0)){
                        dataBuku[k+1] = dataBuku[k];
                        k--;
                    }
                } else if(pilihan==4){
                        while((temp.penerbit < dataBuku[k].penerbit) & (k >= 0)){
                        dataBuku[k+1] = dataBuku[k];
                        k--;
                    }
                } else if(pilihan==5){
                        while((temp.pengarang < dataBuku[k].pengarang) & (k >= 0)){
                        dataBuku[k+1] = dataBuku[k];
                        k--;
                    }
                }
                dataBuku[k+1] = temp;
            }
        }

        // deklarasi variabel ofstream memasukkan data hasil sorting ke file
        ofstream inputFile("hasil_sorting.txt");
        // perulangan input data
        for(k = 0; k <= i-1; k++) {
            if(dataBuku[k].judul != "") {
                // input data hasil sorting ke dalam file
                inputFile<<dataBuku[k].judul<<'\t'<<dataBuku[k].pengarang<<'\t'<<dataBuku[k].penerbit<<'\t'<<dataBuku[k].id<<'\t'<<dataBuku[k].halaman<<'\t'<<dataBuku[k].tahun;
                // kondisi penambahan baris baru di dalam file agar baris terakhir bukan baris kosong
                if(k != i-1)
                    inputFile<<"\n";
            }
        }
        // nutup file
        inputFile.close();

        // output file hasil sorting
        output("hasil_sorting.txt");
    } else
        cout <<"File tidak ditemukan.\n";
    // nutup file asal data
    asalData.close();
}

void cari(string namaFile) {
    int i = 0, j = 0, pilih, pencarianId,pencarianHalaman,pencarianTahun;
    bool ketemu = false;
    string pencarianNama, tempNama,pencarianPenerbit,pencarianPengarang,tempPenerbit,tempPengarang;
	buku temp, dataBuku[100];

 

    // deklarasi variabel ifstream asal data
    ifstream asalData(namaFile);
    // kondisi apakah file terbuka atau tidak
    if(asalData.is_open()) {
        cout<<"\nDaftar Kolom:\n\t1. Judul Buku\n\t2. Id Buku\n\t3. Jumlah Halaman\n\t4. Tahun Terbit\n\t5. Penerbit\n\t6.Pengarang\n\t7. Kembali\n";

        // input pilihan menu
        cout<<"\nKolom yang ingin dicari\t= ";
        cin>>pilih;

        if(pilih<8 && pilih>0){
            cout<<"\nData yang dicari\t= ";
            // input data buku yang dicari sesuai dengan kolom yang dipilih
            switch (pilih) {
                case 1:
                    cin.ignore();
                    getline(cin, pencarianNama);
                    // membuat data yang dicari menjadi huruf kecil
                    for(int x = 0; x < pencarianNama.length(); x++) {
                        pencarianNama[x] = tolower(pencarianNama[x]);
                    }
                    cout<<endl<<pencarianNama<<endl;
                    break;
                case 2:
                    cin>>pencarianId;
                    break;
                case 3:
                    cin>>pencarianHalaman;
                    break;
                case 4:
                    cin>>pencarianTahun;
                    break;    
                case 5:
                    cin.ignore();
                    getline(cin, pencarianPenerbit);
                    // membuat data yang dicari menjadi huruf kecil
                    for(int x = 0; x < pencarianPenerbit.length(); x++) {
                        pencarianPenerbit[x] = tolower(pencarianPenerbit[x]);
                    }
                    cout<<endl<<pencarianPenerbit<<endl;
                    break;
                case 6:
                    cin.ignore();
                    getline(cin, pencarianPengarang);
                    // membuat data yang dicari menjadi huruf kecil
                    for(int x = 0; x < pencarianPengarang.length(); x++) {
                        pencarianPengarang[x] = tolower(pencarianPengarang[x]);
                    }
                    cout<<endl<<pencarianPengarang<<endl;
                    break;
            }

            // perulangan sampai akhir baris dari stream file
            while(asalData.eof()==0) {
                //input data dari file ke variabel record lokal
                getline(asalData, dataBuku[i].judul, '\t');
                getline(asalData, dataBuku[i].pengarang, '\t');
                getline(asalData, dataBuku[i].penerbit, '\t');
                asalData>>dataBuku[i].id>>dataBuku[i].halaman>>dataBuku[i].tahun;
                asalData.ignore();
                i++;
            }

            // deklarasi variabel ofstream memasukkan data hasil search ke file
            ofstream inputFile("hasil_search.txt");
            while(j < i) {
                tempNama = dataBuku[j].judul;
                tempPenerbit = dataBuku[j].penerbit;
                tempPengarang = dataBuku[j].pengarang;

                // membuat data nama buku menjadi huruf kecil
                for(int x = 0; x < tempNama.length(); x++) {
                    tempNama[x] = tolower(tempNama[x]);
                    tempPenerbit[x] = tolower(tempPenerbit[x]);
                    tempPengarang[x] = tolower(tempPengarang[x]);

                }
                // kondisi jika data yang dicari cocok dengan data record yang ada
                if((pilih == 1 ? (tempNama.find(pencarianNama) != string::npos) : (pilih == 2 ? (dataBuku[j].id == pencarianId) : (pilih == 3 ? (dataBuku[j].halaman==pencarianHalaman) : (pilih==4 ? (dataBuku[j].tahun==pencarianTahun) : (pilih==5 ? (tempPenerbit.find(pencarianPenerbit) != string::npos) : (tempPengarang.find(pencarianPengarang) != string::npos) )))))) {
                    ketemu = 1;
                    // memasukkan baris data yang cocok dengan data yang dicari ke dalam file
                    inputFile<<dataBuku[j].judul<<'\t'<<dataBuku[j].pengarang<<'\t'<<dataBuku[j].penerbit<<'\t'<<dataBuku[j].id<<'\t'<<dataBuku[j].halaman<<'\t'<<dataBuku[j].tahun;
                    if(j!=i-1)
                        inputFile<<"\n";
                }
                j++;
            }
            // nutup file
            inputFile.close();
            
            // output file hasil pencarian
            output("hasil_search.txt");
            // tampilan jika data tidak ditemukan
            if(!ketemu)
                cout <<"\nData tidak ada ditemukan dalam file "<<namaFile<<"\n";
        } else
            cout<<"\nMaaf input anda salah. Silakan coba lagi!\n";
    } else
        cout <<"\nFile tidak ditemukan.\n";
    // nutup file
    asalData.close();
}

void ubah(string namaFile) {
    int i = 0, j = 0, pencarianId,pencarianHalaman;
    bool ketemu = false;
    string pencarianNama, tempNama;
	buku temp, dataBuku[100];



    // deklarasi variabel ifstream asal data
    ifstream asalData(namaFile);
    // kondisi apakah file terbuka atau tidak
    if(asalData.is_open()) {
        // input data buku yang diubah
        cout<<"\nData yang ingin diubah :\nJudul Buku\t= ";
        getline(cin, pencarianNama);
        cout<<"ID Buku\t\t= ";
        cin>>pencarianId;
        cout<<"Jumlah Halaman\t= ";
        cin>>pencarianHalaman;
        // lowercase inputan variabel pencarianNama
        for(int x = 0; x < pencarianNama.length(); x++) {
            pencarianNama[x] = tolower(pencarianNama[x]);
        }

        // perulangan sampai akhir baris dari stream file
        while(asalData.eof()==0) {
            //input data dari file ke variabel record lokal
            getline(asalData, dataBuku[i].judul, '\t');
            getline(asalData, dataBuku[i].pengarang, '\t');
            getline(asalData, dataBuku[i].penerbit, '\t');
            asalData>>dataBuku[i].id>>dataBuku[i].halaman>>dataBuku[i].tahun;
            asalData.ignore();
            i++;
        }

        // deklarasi variabel ofstream memasukkan data hasil search ke file
        ofstream inputFile(namaFile);
        while(j < i) {
            tempNama = dataBuku[j].judul;
            // membuat data nama buku menjadi huruf kecil
            for(int x = 0; x < tempNama.length(); x++) {
                tempNama[x] = tolower(tempNama[x]);
            }
            // kondisi jika data yang dicari cocok dengan data record yang ada
            if(tempNama.find(pencarianNama) != string::npos && pencarianId == dataBuku[j].id && pencarianHalaman == dataBuku[j].halaman) {
                ketemu = 1;
                // input data yang diubah
                cin.ignore();
                cout<<"\nUbah Data :\nNama\t\t\t= ";
                getline(cin, dataBuku[j].judul);
                cout<<"Pengarang\t\t= ";
                getline(cin, dataBuku[j].pengarang);
                cout<<"Penerbit\t\t= ";
                getline(cin, dataBuku[j].penerbit);
                cout<<"Id\t\t\t= ";
                cin>>dataBuku[j].id;
                cout<<"Halaman\t\t\t= ";
                cin>>dataBuku[j].halaman;
                cout<<"Tahun terbit\t\t= ";
                cin>>dataBuku[j].tahun;
                cin.ignore();
            }
            // memasukkan data lokal ke file
            if(dataBuku[j].judul!="")
            inputFile<<dataBuku[j].judul<<'\t'<<dataBuku[j].pengarang<<'\t'<<dataBuku[j].penerbit<<'\t'<<dataBuku[j].id<<'\t'<<dataBuku[j].halaman<<'\t'<<dataBuku[j].tahun<<"\n";

            j++;
        }
        // nutup file
        inputFile.close();
        
        // tampilan jika data berhasil diubah dan jika data gagal ditemukan;
        if(!ketemu)
            cout<<"\nData tidak ada ditemukan dalam file "<<namaFile<<endl;
        else
            cout<<"\nData berhasil diubah"<<endl;
    } else
        cout <<"\nFile tidak ditemukan.";
    asalData.close();
}

void hapus(string namaFile) {
    int i = 0, j = 0, pencarianId,pencarianHalaman;
    bool ketemu = false;
    string pencarianNama, tempNama;
	buku temp, dataBuku[100];



    // deklarasi variabel ifstream asal data
    ifstream asalData(namaFile);
    // kondisi apakah file terbuka atau tidak
    if(asalData.is_open()) {
        // input data buku yang dihapus
        cout<<"\nData yang ingin dihapus :\nJudul Buku\t= ";
        getline(cin, pencarianNama);
        cout<<"ID Buku\t\t= ";
        cin>>pencarianId;
        cout<<"Jumlah Halaman\t= ";
        cin>>pencarianHalaman;
        // lowercase inputan variabel pencarianNama
        for(int x = 0; x < pencarianNama.length(); x++) {
            pencarianNama[x] = tolower(pencarianNama[x]);
        }

        // perulangan sampai akhir baris dari stream file
        while(asalData.eof()==0) {
            //input data dari file ke variabel record lokal
            getline(asalData, dataBuku[i].judul, '\t');
            getline(asalData, dataBuku[i].pengarang, '\t');
            getline(asalData, dataBuku[i].penerbit, '\t');
            asalData>>dataBuku[i].id>>dataBuku[i].halaman>>dataBuku[i].tahun;
            asalData.ignore();
            i++;
        }

        // deklarasi variabel ofstream memasukkan data hasil search ke file
        ofstream inputFile(namaFile);
        while(j < i) {
            tempNama = dataBuku[j].judul;
            // membuat data nama buku menjadi huruf kecil
            for(int x = 0; x < tempNama.length(); x++) {
                tempNama[x] = tolower(tempNama[x]);
            }
            // kondisi jika data yang dicari cocok dengan data record yang ada kemudian menandakan bahwa data ditemukan
            if(tempNama.find(pencarianNama) != string::npos && pencarianId == dataBuku[j].id && pencarianHalaman == dataBuku[j].halaman) {
                ketemu = 1;
            } else {
                // memasukkan data yang tidak dicari ke dalam file
                if(dataBuku[j].judul!="")
                inputFile<<dataBuku[j].judul<<'\t'<<dataBuku[j].pengarang<<'\t'<<dataBuku[j].penerbit<<'\t'<<dataBuku[j].id<<'\t'<<dataBuku[j].halaman<<'\t'<<dataBuku[j].tahun;

                if(j!=i-1)
                    inputFile<<"\n";
            }
            j++;
        }
        // nutup file
        inputFile.close();

        cout<<endl<<setfill('=')<<setw(40)<<"=\n";
        
        // tampilan jika data ditemukan atau tidak
        if(!ketemu)
            cout<<"\nData tidak ada ditemukan dalam file "<<namaFile<<endl;
        else
            cout<<"\nData berhasil dihapus"<<endl;
    } else
        cout <<"File tidak ditemukan.\n";
    // nutup file
    asalData.close();
}

void reset(string namaFile) {




    // deklarasi variabel ifstream asal data
    ifstream asalData(namaFile);
    // kondisi apakah file terbuka atau tidak
    if(asalData.is_open()) {
            // deklarasi variabel ofstream tanpa memasukkan data apapun
            ofstream inputFile(namaFile);
            // nutup file
            inputFile.close();
            cout<<"\nFile berhasil dikosongkan"<<endl;
    } else
        cout <<"\nFile tidak ditemukan.\n";
    // nutup file
    asalData.close();
}