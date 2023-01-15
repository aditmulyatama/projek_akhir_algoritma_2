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

void isiData(string namaFile, int* index, buku dataBuku[]),
 input(string namaFile, int* index, buku dataBuku[]), output(buku dataBuku[], int jumlah), 
 sort(buku dataBuku[], int jumlah), cari(buku dataBuku[], int jumlah), 
 ubah(string namaFile, int index, buku dataBuku[]), hapus(string namaFile, int jumlah, buku dataBuku[]), 
 reset(string namaFile), sortTemp(buku dataBuku[],buku temp[], int jml);

main() {
    int pilih, index = 0;
    char konfirmasi;
    string namaFile, tempFile = "";
    buku dataBuku[100],temp[100];

    while(pilih != 8) {
        cout<<setfill('=')<<setw(40)<<'='<<"\n";
        cout<<"\t\tMenu Utama\n";
        cout<<setfill('=')<<setw(40)<<'='<<"\n";
        cout<<"\n1. Tambah Data\n2. Tampilan Data\n3. Pengurutan Data\n4. Pencarian Data\n5. Pengubahan Data\n6. Penghapusan Data\n7. Pengosongan Data\n8. Keluar Program\n\n";
        cout<<setfill('=')<<setw(40)<<'='<<"\n";

        // input pilihan menu
        cout<<"\nPilih\t: ";
        cin>>pilih;
        cin.ignore();

        if(pilih < 8 && pilih > 0){
            // input nama file
            cout<<"\nNama file\t= ";
            getline(cin, namaFile);

            if(namaFile!=tempFile) {
                tempFile = namaFile;
                index = 0;
            }

            ifstream fileUtama(namaFile);

            if(fileUtama.is_open()) {
                if(index == 0) {
                    for(int i = 0; i < 100; i++) {
                        dataBuku[i].id=0;
                        dataBuku[i].judul="";
                        dataBuku[i].pengarang="";
                        dataBuku[i].penerbit="";
                        dataBuku[i].halaman=0;
                        dataBuku[i].tahun=0;
                    }
                    isiData(namaFile, &index, dataBuku);
                }
                if (index == 0 && pilih != 1) {
                    cout<<"\nFile yang anda pilih kosong\n\n";
                } else {    
                    system("cls");            
                    switch(pilih) {
                        case 1:
                            input(namaFile, &index, dataBuku);
                            break;
                        case 2:
                            cout<<setfill('=')<<setw(40)<<'='<<"\n";
                            cout<<"\tOUTPUT DATA\n";
                            cout<<setfill('=')<<setw(40)<<'='<<"\n";
                            output(dataBuku, index);
                            break;
                        case 3:
                            sortTemp(dataBuku,temp,index);
                            sort(temp, index);
                            break;
                        case 4:
                            cout<<setfill('=')<<setw(40)<<'='<<"\n";
                            cout<<"\tPENCARIAN DATA\n";
                            cout<<setfill('=')<<setw(40)<<'='<<"\n";
                            cari(dataBuku, index);
                            break;
                        case 5:
                            cout<<setfill('=')<<setw(40)<<'='<<"\n";
                            cout<<"\tPENGUBAHAN DATA\n";
                            cout<<setfill('=')<<setw(40)<<'='<<"\n";

                            ubah(namaFile, index, dataBuku);
                            break;
                        case 6:
                            cout<<setfill('=')<<setw(40)<<'='<<"\n";
                            cout<<"\tPENGHAPUSAN DATA\n";
                            cout<<setfill('=')<<setw(40)<<'='<<"\n";

                            hapus(namaFile, index, dataBuku);
                            index = 0;
                            break;
                        case 7:
                            cout<<setfill('=')<<setw(40)<<'='<<"\n";
                            cout<<"\tPENGOSONGAN FILE\n";
                            cout<<setfill('=')<<setw(40)<<'='<<"\n";

                            reset(namaFile);
                            index = 0;
                            break;
                    }
                    cout<<setfill('=')<<setw(40)<<'='<<"\n";
                    cout<<setfill('=')<<setw(40)<<'='<<"\n\n";
                }
            } else if(pilih == 1) {
                system("cls");
                input(namaFile, &index, dataBuku);
                cout<<setfill('=')<<setw(40)<<'='<<"\n";
                cout<<setfill('=')<<setw(40)<<'='<<"\n\n";
            } else
                cout <<"\nFile tidak ditemukan.\n";
            fileUtama.close();
            system("pause");
        } else if (pilih == 8) {
            cout<<"\nApakah anda yakin ingin keluar dari program? (ketik y jika iya)\n";
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

void isiData(string namaFile, int* index, buku dataBuku[]){
    ifstream fileAsal(namaFile);

    while(!fileAsal.eof()) {
        fileAsal>>dataBuku[*index].id;
        fileAsal.ignore();
        getline(fileAsal, dataBuku[*index].judul, '\t');
        getline(fileAsal, dataBuku[*index].pengarang, '\t');
        getline(fileAsal, dataBuku[*index].penerbit, '\t');
        fileAsal>>dataBuku[*index].halaman>>dataBuku[*index].tahun;
        fileAsal.ignore();
        // cout<<*index<<"\t"<<dataBuku[*index].id<<"\t"<<dataBuku[*index].judul<<"\t"<<dataBuku[*index].pengarang<<"\t"<<dataBuku[*index].penerbit<<"\t"<<dataBuku[*index].halaman<<"\t"<<dataBuku[*index].tahun<<endl;
        if(dataBuku[*index].judul != "") {
            *index += 1;
        }
    }

    fileAsal.close();
}

void sortTemp(buku dataBuku[], buku temp[], int jml){
    for(int i=0;i<jml;i++){
        temp[i]=dataBuku[i];
    }
}

void input(string namaFile, int* index, buku dataBuku[]){
    // deklarasi variabel record sementara untuk dimasukkan ke dalam file
    // buku dataBuku;
    int banyak, i = *index;
    string dummy;
    ofstream inputFile(namaFile, ios::app);

    cout<<setfill('=')<<setw(40)<<'='<<"\n";
    cout<<"\t\tINPUT DATA\n";
    cout<<setfill('=')<<setw(40)<<'='<<"\n";

    // input banyak data
    cout<<"\nBanyak data\t\t= ";
    cin>>banyak;
    cin.ignore();
    banyak += *index;

    cout<<endl<<setfill('=')<<setw(40)<<'='<<"\n";
    
    for (i; i < banyak; i++) {
        if(i != 0)
            dataBuku[i].id = dataBuku[i-1].id + 1;
        else
        dataBuku[i].id = i + 1;
        cout<<"\nId ke-"<<dataBuku[i].id<<"\nJudul\t\t\t= ";
        getline(cin, dataBuku[i].judul);
        cout<<"Pengarang\t\t= ";
        getline(cin, dataBuku[i].pengarang);
        cout<<"Penerbit\t\t= ";
        getline(cin, dataBuku[i].penerbit);
        cout<<"Halaman\t\t\t= ";
        cin>>dataBuku[i].halaman;
        cout<<"Tahun terbit\t\t= ";
        cin>>dataBuku[i].tahun;
        cin.ignore();

        // memasukkan data dari variabel record ke dalam file
        if(i>0)
            inputFile<<"\n";
        inputFile<<dataBuku[i].id<<'\t'<<dataBuku[i].judul<<'\t'<<dataBuku[i].pengarang<<'\t'<<dataBuku[i].penerbit<<'\t'<<dataBuku[i].halaman<<'\t'<<dataBuku[i].tahun;
    }
    *index = i;
    cout<<"\n"<<setfill('=')<<setw(40)<<'='<<"\n\n";
    cout<<"Data berhasil ditambahkan ke dalam file.\n\n";
    
    inputFile.close();
}

void output(buku dataBuku[], int jumlah){
    // output data dari variabel record lokal apabila baris tidak kosong
    for (int i = 0; i < jumlah; i++) {
        if(dataBuku[i].judul!="") {
            cout<<"\nData ke-"<<i+1;
            cout<<"\n  ID buku\t\t: "<<dataBuku[i].id;
            cout<<"\n  Judul Buku\t\t: "<<dataBuku[i].judul;
            cout<<"\n  Pengarang\t\t: "<<dataBuku[i].pengarang;
            cout<<"\n  Penerbit\t\t: "<<dataBuku[i].penerbit;
            cout<<"\n  Jumlah Halaman\t: "<<dataBuku[i].halaman;
            cout<<"\n  Tahun Terbit\t\t: "<<dataBuku[i].tahun<<endl;
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
}

void sort(buku dataBuku[], int jumlah){
    int pilihan, i = 0, j, k, kolom;
	buku temp;
    
    cout<<setfill('=')<<setw(40)<<'='<<"\n";
    cout<<"\tPENGURUTAN DATA\n";
    cout<<setfill('=')<<setw(40)<<'='<<"\n";
    cout<<"\nDaftar Kolom:\n\t1. Judul Buku\n\t2. Pengarang\n\t3. Penerbit\n\t4. Jumlah Halaman\n\t5. Tahun Terbit\n\t6. Kembali\n";

    // input pilihan menu
    cout<<"\nKolom yang ingin diurutkan\t= ";
    cin>>pilihan;

    // perulangan untuk sorting
    if(pilihan>0&&pilihan<6){
        for(j=0; j<jumlah; j++){
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
                while((temp.pengarang < dataBuku[k].pengarang) & (k >= 0)){
                    dataBuku[k+1] = dataBuku[k];
                    k--;
                }
            } else if (pilihan==3){
                while((temp.penerbit < dataBuku[k].penerbit) & (k >= 0)){
                    dataBuku[k+1] = dataBuku[k];
                    k--;
                }
            } else if(pilihan==4){
                while((temp.halaman < dataBuku[k].halaman) & (k >= 0)){
                    dataBuku[k+1] = dataBuku[k];
                    k--;
                }
            } else if(pilihan==5){
                while((temp.tahun < dataBuku[k].tahun) & (k >= 0)){
                    dataBuku[k+1] = dataBuku[k];
                    k--;
                }
            }
            dataBuku[k+1] = temp;
        }
    }

    // output file hasil sorting
    output(dataBuku,jumlah);
}

void cari(buku dataBuku[], int jumlah) {
    int i = 0, j = 0, pilih, pencarianId, pencarianHalaman, pencarianTahun;
    bool ketemu = false;
    string pencarianNama, tempNama, pencarianPenerbit, pencarianPengarang, tempPenerbit, tempPengarang;
    
    cout<<"\nDaftar Kolom:\n\t1. Id Buku\n\t2. Judul Buku\n\t3. Pengarang\n\t4. Penerbit\n\t5. Jumlah Halaman\n\t6. Tahun Terbit\n\t7. Kembali\n";

    // input pilihan menu
    cout<<"\nKolom yang ingin dicari\t= ";
    cin>>pilih;

    if(pilih<7 && pilih>0){
        cout<<"\nData yang dicari\t= ";
        // input data buku yang dicari sesuai dengan kolom yang dipilih
        switch (pilih) {
            case 1:
                cin>>pencarianId;
                break;
            case 2:
                cin.ignore();
                getline(cin, pencarianNama);
                // membuat data yang dicari menjadi huruf kecil
                for(int x = 0; x < pencarianNama.length(); x++) {
                    pencarianNama[x] = tolower(pencarianNama[x]);
                }
                // cout<<endl<<pencarianNama<<endl;
                break;
            case 3:
                cin.ignore();
                getline(cin, pencarianPengarang);
                // membuat data yang dicari menjadi huruf kecil
                for(int x = 0; x < pencarianPengarang.length(); x++) {
                    pencarianPengarang[x] = tolower(pencarianPengarang[x]);
                }
                // cout<<endl<<pencarianPengarang<<endl;
                break;
            case 4:
                cin.ignore();
                getline(cin, pencarianPenerbit);
                // membuat data yang dicari menjadi huruf kecil
                for(int x = 0; x < pencarianPenerbit.length(); x++) {
                    pencarianPenerbit[x] = tolower(pencarianPenerbit[x]);
                }
                // cout<<endl<<pencarianPenerbit<<endl;
                break;    
            case 5:
                cin>>pencarianHalaman;
                break;
            case 6:
                cin>>pencarianTahun;
                break;
        }

        // deklarasi variabel ofstream memasukkan data hasil search ke file
        ofstream inputFile("hasil_search.txt");
        while(j < jumlah) {
            tempNama = dataBuku[j].judul;
            tempPenerbit = dataBuku[j].penerbit;
            tempPengarang = dataBuku[j].pengarang;

            // membuat data nama buku menjadi huruf kecil
            for(int x = 0; x < tempNama.length(); x++) {
                tempNama[x] = tolower(tempNama[x]);
            }
            for(int x = 0; x < tempPenerbit.length(); x++) {
                tempPenerbit[x] = tolower(tempPenerbit[x]);
            }
            for(int x = 0; x < tempPengarang.length(); x++) {
                tempPengarang[x] = tolower(tempPengarang[x]);
            }

            
            // kondisi jika data yang dicari cocok dengan data record yang ada
            if((pilih == 1 ? (dataBuku[j].id == pencarianId) : 
                (pilih == 2 ? (tempNama.find(pencarianNama) != string::npos) :
                    (pilih == 3 ? (tempPengarang.find(pencarianPengarang) != string::npos) :
                        (pilih==4 ? (tempPenerbit.find(pencarianPenerbit) != string::npos) :
                            (pilih==5 ? (dataBuku[j].halaman==pencarianHalaman) :
                                (dataBuku[j].tahun==pencarianTahun) )))))) {
                ketemu = 1;
                cout<<"\nData ke-"<<i+1<<" yang ditemukan : ";
                cout<<"\n  ID buku\t\t: "<<dataBuku[j].id;
                cout<<"\n  Judul Buku\t\t: "<<dataBuku[j].judul;
                cout<<"\n  Pengarang\t\t: "<<dataBuku[j].pengarang;
                cout<<"\n  Penerbit\t\t: "<<dataBuku[j].penerbit;
                cout<<"\n  Jumlah Halaman\t: "<<dataBuku[j].halaman;
                cout<<"\n  Tahun Terbit\t\t: "<<dataBuku[j].tahun<<endl;
                i++;
            }
            j++;
        }
        cout<<endl;
        // nutup file
        inputFile.close();
        
        // tampilan jika data tidak ditemukan
        if(!ketemu)
            cout <<"\nData tidak ada ditemukan dalam file\n\n";
    } else
        cout<<"\nMaaf input anda salah. Silakan coba lagi!\n\n";
}

void ubah(string namaFile, int jumlah, buku dataBuku[]) {
    int j = 0, pencarianId;
    bool ketemu = false;

    cout<<"ID Buku\t\t= ";
    cin>>pencarianId;

    // deklarasi variabel ofstream memasukkan data hasil search ke file
    ofstream inputFile(namaFile);
    while(j < jumlah) {
        // kondisi jika data yang dicari cocok dengan data record yang ada
        if(pencarianId == dataBuku[j].id) {
            ketemu = 1;
            // input data yang diubah
            cin.ignore();
            cout<<"\nId ke-"<<dataBuku[j].id<<"\nJudul\t\t\t= ";
            getline(cin, dataBuku[j].judul);
            cout<<"Pengarang\t\t= ";
            getline(cin, dataBuku[j].pengarang);
            cout<<"Penerbit\t\t= ";
            getline(cin, dataBuku[j].penerbit);
            cout<<"Halaman\t\t\t= ";
            cin>>dataBuku[j].halaman;
            cout<<"Tahun terbit\t\t= ";
            cin>>dataBuku[j].tahun;
            cin.ignore();
        }
        // memasukkan data lokal ke file
        if(dataBuku[j].judul!=""){
            if(j>0)
                inputFile<<"\n";
            inputFile<<dataBuku[j].id<<'\t'<<dataBuku[j].judul<<'\t'<<dataBuku[j].pengarang<<'\t'<<dataBuku[j].penerbit<<'\t'<<dataBuku[j].halaman<<'\t'<<dataBuku[j].tahun;
        }
        
        j++;
    }
    // nutup file
    inputFile.close();
    
    // tampilan jika data berhasil diubah dan jika data gagal ditemukan;
    if(!ketemu)
        cout<<"\nData tidak ada ditemukan dalam file "<<namaFile<<"\n\n";
    else
        cout<<"\nData berhasil diubah\n\n";
}

void hapus(string namaFile, int jumlah, buku dataBuku[]) {
    int j = 0, pencarianId;
    bool ketemu = false;

    // input data buku yang dihapus
    cout<<"\nID dari buku yang ingin dihapus : ";
    cin>>pencarianId;

    // deklarasi variabel ofstream memasukkan data hasil search ke file
    ofstream inputFile(namaFile);
    while(j < jumlah) {
        // kondisi jika data yang dicari cocok dengan data record yang ada kemudian menandakan bahwa data ditemukan
        if(pencarianId == dataBuku[j].id) {
            ketemu = 1;
        } else {
            // memasukkan data yang tidak dicari ke dalam file
            if(dataBuku[j].judul!="") {
                if(j>0)
                    inputFile<<"\n";
                inputFile<<dataBuku[j].id<<'\t'<<dataBuku[j].judul<<'\t'<<dataBuku[j].pengarang<<'\t'<<dataBuku[j].penerbit<<'\t'<<dataBuku[j].halaman<<'\t'<<dataBuku[j].tahun;
            }
        }
        j++;
    }
    // nutup file
    inputFile.close();

    cout<<endl<<setfill('=')<<setw(40)<<"=\n";
    
    // tampilan jika data ditemukan atau tidak
    if(!ketemu)
        cout<<"\nData yang anda cari tidak ada ditemukan dalam file "<<namaFile<<"\n\n";
    else
        cout<<"\nData berhasil dihapus\n\n";
}

void reset(string namaFile) {
    // deklarasi variabel ofstream tanpa memasukkan data apapun
    ofstream inputFile(namaFile);
    // nutup file
    inputFile.close();
    cout<<"\nFile berhasil dikosongkan\n\n";
}