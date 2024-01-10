#include<stdio.h>
#include<stdlib.h>
int main(){
    char pil;
    char pilihan;
    info_diri();
    do
    {
        menu();
        //scanf("%c",&pil);
        pil=getch();
        switch(pil)
        {
        case '1':info_diri();
                break;
        case '2':string();
                getch();
                break;
        case '3':format_rupiah();
                getch();
                break;
        case '4':printf("\nprogram selesai\n");
                break;
        }
    }while(pil!='4');
   return 0;
}
void info_diri(){
    system("cls");
    puts("=====================");
    puts("Soal UAS Algo");
    puts("Oleh  : Daffa Maulana Ramadhan");
    puts("Nim   : C030323001");
    puts("=====================");
    printf("Tekan enter untuk melanjutkan");
    getch();
}
void menu(){
    system("cls");
    puts("=====================");
    puts("==== MENU UTAMA ====");
    puts("1. Info Diri");
    puts("2. String");
    puts("3. Format Rupiah");
    puts("4. Keluar");
    puts("=====================");
    printf("Pilihan Anda Nomor");
}
void hitung_umur(){
    system("cls");
    int thnLahir, umur;
    puts("Program Hitung Umur");
    printf("Masukkan Tahun Lahir = ");
    scanf("%d",&thnLahir);
    umur = 2023 - thnLahir;

    if(thnLahir > 2023)
    {
    printf("\nTahun Lahir Tidak Boleh Lebih 2023");
    }
    /*else if(thnLahir<0)
    {
    printf("\nTahun Lahir Anda Tidak Boleh Negative");
    }*/
    else
    {
    printf("\nUmur Anda Adalah = %i ",umur);
    }
    printf("\nTekan enter untuk kembali ke menu");
}

void string() {
    system("cls");
    char kalimat[1000];
    int hurufHidup = 0;

    printf("Masukkan kalimat: ");
    gets(kalimat);

    for (int i = 0; kalimat[i] != '\0'; i++) {
        if (i == 0 || kalimat[i - 1] == ' ') {
            kalimat[i] = toupper(kalimat[i]);
        } else {
            kalimat[i] = tolower(kalimat[i]);
        }
        if (kalimat[i] == 'a' || kalimat[i] == 'i' || kalimat[i] == 'u' || kalimat[i] == 'e' || kalimat[i] == 'o') {
            hurufHidup++;
        }
    }
    printf("\nKalimat: %s\n", kalimat);
    printf("Jumlah huruf hidup: %d\n", hurufHidup);

    FILE *file = fopen("uas.txt", "w");
    if (file != NULL) {
        fprintf(file, "Data Kalimat: %s\n", kalimat);
        fprintf(file, "Data Huruf Hidup: %d\n", hurufHidup);
        fclose(file);
        printf("Data telah disimpan dalam file uas.txt\n");
    } else {
        printf("Gagal membuka file uas.txt untuk ditulis.\n");
    }

}

void format_rupiah() {
    system("cls");
    char pilihan;
    do {
        long long int angka;

        puts("Konversi Angka ke Format Rupiah");
        puts("------------------------------------");
        printf("Masukkan angka max 9jt = ");
        scanf("%lld", &angka);

        printf("Rp 1.000.000,-\n");
        printf("Rp ");

        char angkaStr[20];
        sprintf(angkaStr, "%lld", angka);

        int length = strlen(angkaStr);

        for (int i = 0; i < length; i++) {
            printf("%c", angkaStr[i]);
            if ((length - i - 1) % 3 == 0 && i != length - 1) {
                printf(".");
            }
        }

        printf(",-\n");

        printf("Apakah ingin mengulang? (y/n): ");
        scanf(" %c", &pilihan);

    } while (pilihan == 'y' || pilihan == 'Y');


}

