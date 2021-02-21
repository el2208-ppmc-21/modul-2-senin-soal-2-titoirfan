/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 2
*Percobaan        : -
*Hari dan Tanggal : Sabtu, 20 Februari 2021
*Nama (NIM)       : -
*Asisten (NIM)    : Adeline Kartika (13218081)
*Nama File        : main.c
*Deskripsi        : Melakukan pembacaan file eksternal data rumah sakit dan melakukan pencarian
*/

#include <stdio.h>
#include <string.h>

int main(){
    char file[20];
    char temp[50];
    char hospital[20];
    char pencarian[30];
    int cari;
    int hasil = 0;
    int jumlah = 0;

    char namapasien[30];
    char umurpasien[3];
    char penyakitpasien[30];

    FILE *fp = NULL;

    printf("Masukkan nama file: ");
    gets(file);
    fp = fopen(file, "r");

    while (fp == NULL){
        printf("File tidak ditemukan!\n\n");
        printf("Masukkan nama file: ");
        gets(file);
        fp = fopen(file, "r");
    }

    fgets(temp, sizeof(temp), fp);
    sscanf(temp, " %[^\n]s", &hospital);

    printf("\nNama Rumah Sakit: %s\n", hospital);
    printf("\nJenis pencarian pasien:\n");
    printf("1. Nama\n");
    printf("2. Umur\n");
    printf("3. Penyakit\n");
    printf("Pilihan pencarian: ");
    scanf("%d", &cari);
    printf("Masukkan pencarian: ");
    scanf(" %[^\n]s", &pencarian);
    printf("\n");

    while(fgets(temp, sizeof(temp), fp)){ // mengecek apakah inputan ada dalam file
        jumlah++;

        strcpy(namapasien, strtok(temp, ","));
        strcpy(umurpasien, strtok(NULL, ","));
        strcpy(penyakitpasien, strtok(NULL, "\n"));

        if(cari == 1){
            if(strstr(namapasien,pencarian) != 0){
                hasil++;
                printf("Data pasien ke-%d\n", jumlah);        
                printf("Nama pasien \t: %s\n", namapasien);
                printf("Umur pasien \t: %s\n", umurpasien);
                printf("Kondisi pasien \t: %s\n", penyakitpasien);
                printf("\n"); 
            }
        } else if(cari == 2){
            if(strstr(umurpasien,pencarian) != 0){
                hasil++;
                printf("Data pasien ke-%d\n", jumlah);        
                printf("Nama pasien \t: %s\n", namapasien);
                printf("Umur pasien \t: %s\n", umurpasien);
                printf("Kondisi pasien \t: %s\n", penyakitpasien);
                printf("\n");
            }
        } else if(cari == 3){
            if(strstr(penyakitpasien,pencarian) != 0){
                hasil++;
                printf("Data pasien ke-%d\n", jumlah);        
                printf("Nama pasien \t: %s\n", namapasien);
                printf("Umur pasien \t: %s\n", umurpasien);
                printf("Kondisi pasien \t: %s\n", penyakitpasien);
                printf("\n");
            }
        }
    }

    fclose(fp);

    if (hasil == 0){
        printf("Data pasien tidak ditemukan!");
    }

    return 0;
}
