#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int hastaNo;
    char hastaAd[50];
    int hastaYas;
    char hastalik[50];
} Hasta;

void dosyaOlustur(const char* dosyaAdi) {
    FILE* dosya = fopen(dosyaAdi, "w+");
    if (dosya == NULL) {
        printf("Dosya olusturma hatasi!\n");
        return;
    }
    fclose(dosya);
    printf("Dosya olusturuldu: %s\n", dosyaAdi);
}

void kayitEkle(const char* dosyaAdi) {
    Hasta hasta;

    printf("Hasta No: ");
    scanf("%d", &hasta.hastaNo);
    printf("Hasta Ad: ");
    scanf("%s", hasta.hastaAd);
    printf("Hasta Yas: ");
    scanf("%d", &hasta.hastaYas);
    printf("Hastalik: ");
    scanf("%s", hasta.hastalik);

    FILE* dosya = fopen(dosyaAdi, "a+");
    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n");
        return;
    }
    fwrite(&hasta, sizeof(Hasta), 1, dosya);
    fclose(dosya);

    printf("Kayit eklendi.\n");
}

void hastaAra(const char* dosyaAdi) {
    int hedefNo;

    printf("Aranacak hasta No: ");
    scanf("%d", &hedefNo);

    FILE* dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n");
        return;
    }

    Hasta hasta;
    int bulundu = 0;
    while (fread(&hasta, sizeof(Hasta), 1, dosya)) {
        if (hasta.hastaNo == hedefNo) {
            printf("Hasta Bulundu:\n");
            printf("Hasta No: %d\n", hasta.hastaNo);
            printf("Hasta Ad: %s\n", hasta.hastaAd);
            printf("Hasta Yas: %d\n", hasta.hastaYas);
            printf("Hastalik: %s\n", hasta.hastalik);
            bulundu = 1;
            break;
        }
    }

    if (!bulundu) {
        printf("Hasta bulunamadi.\n");
    }

    fclose(dosya);
}

void tumHastalariListele(const char* dosyaAdi) {
    FILE* dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n");
        return;
    }

    Hasta hasta;
    printf("Tum Hastalar:\n");
    while (fread(&hasta, sizeof(Hasta), 1, dosya)) {
        printf("Hasta No: %d\n", hasta.hastaNo);
        printf("Hasta Ad: %s\n", hasta.hastaAd);
        printf("Hasta Yas: %d\n", hasta.hastaYas);
        printf("Hastalik: %s\n", hasta.hastalik);
        printf("-------------------------\n");
    }

    fclose(dosya);
}

void hastaKaydiSil(const char* dosyaAdi) {
    int hedefNo;

    printf("Silinecek hasta No: ");
    scanf("%d", &hedefNo);

    FILE* dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n");
        return;
    }

    FILE* geciciDosya = fopen("gecici.dat", "w");
    if (geciciDosya == NULL) {
        printf("Gecici dosya olusturma hatasi!\n");
        fclose(dosya);
        return;
    }

    Hasta hasta;
    int bulundu = 0;
    while (fread(&hasta, sizeof(Hasta), 1, dosya)) {
        if (hasta.hastaNo != hedefNo) {
            fwrite(&hasta, sizeof(Hasta), 1, geciciDosya);
        } else {
            bulundu = 1;
        }
    }

    fclose(dosya);
    fclose(geciciDosya);

    if (bulundu) {
        remove(dosyaAdi);
        rename("gecici.dat", dosyaAdi);
        printf("Hasta kaydi silindi.\n");
    } else {
        remove("gecici.dat");
        printf("Hasta bulunamadi.\n");
    }
}

void hastaKaydiDuzenle(const char* dosyaAdi) {
    int hedefNo;

    printf("Duzenlenecek hasta No: ");
    scanf("%d", &hedefNo);

    FILE* dosya = fopen(dosyaAdi, "r+");
    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n");
        return;
    }

    Hasta hasta;
    int bulundu = 0;
    while (fread(&hasta, sizeof(Hasta), 1, dosya)) {
        if (hasta.hastaNo == hedefNo) {
            printf("Hasta Bulundu:\n");
            printf("Hasta No: %d\n", hasta.hastaNo);
            printf("Hasta Ad: %s\n", hasta.hastaAd);
            printf("Hasta Yas: %d\n", hasta.hastaYas);
            printf("Hastalik: %s\n", hasta.hastalik);

            printf("Yeni Hasta Ad: ");
            scanf("%s", hasta.hastaAd);
            printf("Yeni Hasta Yas: ");
            scanf("%d", &hasta.hastaYas);
            printf("Yeni Hastalik: ");
            scanf("%s", hasta.hastalik);

            fseek(dosya, -sizeof(Hasta), SEEK_CUR);
            fwrite(&hasta, sizeof(Hasta), 1, dosya);
            bulundu = 1;

            printf("Hasta kaydi duzenlendi.\n");
            break;
        }
    }

    if (!bulundu) {
        printf("Hasta bulunamadi.\n");
    }

    fclose(dosya);
}

int main() {
    char dosyaAdi[] = "hastalar.txt";
    int secim;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Dosya Olustur\n");
        printf("2. Kayit Ekle\n");
        printf("3. Hasta Ara\n");
        printf("4. Tum Hastalari Listele\n");
        printf("5. Hasta Kaydi Sil\n");
        printf("6. Hasta Kaydi Duzenle\n");
        printf("7. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                dosyaOlustur(dosyaAdi);
                break;
            case 2:
                kayitEkle(dosyaAdi);
                break;
            case 3:
                hastaAra(dosyaAdi);
                break;
            case 4:
                tumHastalariListele(dosyaAdi);
                break;
            case 5:
                hastaKaydiSil(dosyaAdi);
                break;
            case 6:
                hastaKaydiDuzenle(dosyaAdi);
                break;
            case 7:
                printf("Programdan cikiliyor...\n");
                exit(0);
            default:
                printf("Gecersiz secim!\n");
                break;
        }
    }

    return 0;
}


