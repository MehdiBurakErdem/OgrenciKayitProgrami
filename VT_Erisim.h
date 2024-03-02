#ifndef VT_ERIS_H
#define VT_ERIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ogrenci
{
    char isim[256];
    int ort;
} new_ogrenci;

// Case 1
void VT_ekle(struct Ogrenci a)
{
    FILE *pdosya = fopen("C:\\Users\\mehdi\\OneDrive\\Desktop\\C\\OgrenciKayit\\VT\\Ogrenciler.text", "a");
    if (pdosya == NULL)
    {
        printf("Dosya acilamadi!!");
    }
    else
    {
        fprintf(pdosya,"%s | %d", a.isim, a.ort);
        fputc('\n',pdosya);
        fclose(pdosya);
        printf("\\_ Islem Basarili Sekilde Gerceklesti _/\n");
    }
}

// Case 2

int ft_strcmp(char *file, char *ara)
{
    int i = 0;
    while (file[i + 1] != '|')
    {
        if ((ara[i] != file[i]) && (file[i] + 32 != ara[i]) && (file[i] != ara[i] + 32)) // Buyuk harf kücük harf içinde kontrol sağlanıyor
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void VT_sorgu(char *p)
{
    FILE *pdosya = fopen("C:\\Users\\mehdi\\OneDrive\\Desktop\\C\\OgrenciKayit\\VT\\Ogrenciler.text", "r");
    if (pdosya == NULL)
    {
        printf("Dosya acilamadi!!");
        return ;
    }
    char isim[256];
    while (fgets(isim, 256, pdosya) != NULL)
    {
        if (ft_strcmp(isim,p) == 1)
        {
            printf("---> Kisinin kaydi : %s", isim);
            fclose(pdosya);
            return ;
        }
    }
    printf("\\_ Sorgulama yapildi *ogrenci kaydi yoktur* \n");
    fclose(pdosya);
}

// Case 3
void VT_yaz()
{
    FILE *pdosya = fopen("C:\\Users\\mehdi\\OneDrive\\Desktop\\C\\OgrenciKayit\\VT\\Ogrenciler.text", "r");
    if (pdosya == NULL)
    {
        printf("Dosya acilamadi!!");
        return ;
    }
    int i = 1;
    char kayit[256];
    while (fgets(kayit,256,pdosya))
    {
        printf("%d. %s",i ,kayit);
        i++;
    }
}

#endif