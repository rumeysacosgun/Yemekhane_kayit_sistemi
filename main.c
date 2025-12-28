#include <stdio.h>
#include <stdlib.h>

#define ogrenciSayisi 5
#define aySayisi 12

void dosyayaKaydet(int matris[ogrenciSayisi][aySayisi])
{
    int i, j;
    FILE *dosya = fopen("kayitlar.txt", "w");
    if (dosya == NULL)
	{
        printf("Dosya acilamadi!\n");
        return;
    }
    for (i = 0; i < ogrenciSayisi; i++) 
	{
        for (j = 0; j < aySayisi; j++) 
		{
            fprintf(dosya, "%d ", matris[i][j]);
        }
        fprintf(dosya, "\n");
    }
    fclose(dosya);
}
void dosyadanOku(int matris[ogrenciSayisi][aySayisi]) 
{
    int i, j;
    FILE *dosya = fopen("kayitlar.txt", "r");
    if (dosya == NULL) return;
    for (i = 0; i < ogrenciSayisi; i++) 
	{
        for (j = 0; j < aySayisi; j++) 
		{
            if (fscanf(dosya, "%d", &matris[i][j]) != 1) break;
        }
    }
    fclose(dosya);
}

int main()
{
    int secim, ogrNo, aySecim, i, j;
    char *aylar[] = {"Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran","Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"};
    int kayitMatrisi[ogrenciSayisi][aySayisi] = {0};
    dosyadanOku(kayitMatrisi);
    while (1) {
        printf("\n YEMEKHANE SISTEMI \n");
        printf("1. Kayit Yap\n2. Iptal Et\n3. Listele\n4. Cikis\n");
        printf("Seciminiz: ");
        
        if (scanf("%d", &secim) != 1) 
		{
            while(getchar() != '\n');
            continue;
        }
        if (secim == 4) break;
        if (secim == 1) 
		{
            printf("Ogrenci No (0-%d): ", ogrenciSayisi - 1);
            scanf("%d", &ogrNo);
            printf("Ay Secimi (1-12): ");
            scanf("%d", &aySecim);
            if (ogrNo >= 0 && ogrNo < ogrenciSayisi && aySecim >= 1 && aySecim <= 12) 
			{
                kayitMatrisi[ogrNo][aySecim - 1] = 1;
                dosyayaKaydet(kayitMatrisi);
                printf("Kayit %s ayi icin tamamlandi.\n", aylar[aySecim - 1]);
            } 
			else 
			{
                printf("Hatali giris! Lutfen araliklara dikkat edin.\n");
            }
        } 
        else if (secim == 2) 
		{
            printf("Ogrenci No: ");
            scanf("%d", &ogrNo);
            printf("Iptal Ayi (1-12): ");
            scanf("%d", &aySecim);    
            if (ogrNo >= 0 && ogrNo < ogrenciSayisi && aySecim >= 1 && aySecim <= 12) 
			{
                if (kayitMatrisi[ogrNo][aySecim - 1] == 1)
				{	
                    kayitMatrisi[ogrNo][aySecim - 1] = 0;
                    dosyayaKaydet(kayitMatrisi);
                    printf("Iptal islemi tamamlandi.\n");
                }
				else
				{
                    printf("Bu ay icin zaten kayit bulunmuyor.\n");
                }
            }
        }
        else if (secim == 3) 
		{
            printf("\n MEVCUT KAYIT DURUMU \n");
            for (i = 0; i < ogrenciSayisi; i++) 
			{
                printf("Ogr %d: ", i);
                for (j = 0; j < aySayisi; j++) 
				{
                    printf("%s ", kayitMatrisi[i][j] ? "[Dolu]" : "[Bos]");
                }
                printf("\n");
            }
        }
    }
    printf("Program kapatiliyor...\n");
    sleep(1);
    printf("Program kapatildi...\n");
    return 0;
}
