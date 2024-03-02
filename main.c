#include "VT_Erisim.h"

int main()
{
    int islem;
    int i;
    printf("+++++++++++++++++++++++++++++++++++++++\n");
    printf("* Ogrenci Kayit Sistemine Hosgeldiniz *\n");

    do
    {
        printf("\nOgrenci eklemek icin : 1\nBir ogrenci sorgulamak icin : 2\nOgrenci kayitlari icin : 3\nCikis yapmak icin : 0\n");
        printf("+-- Yapmak istediginiz islem nedir: ");
        while (scanf("%d", &islem) != 1) //İslem bir sayı olana kadır alır
        {
            printf("!!! Gecersiz islem (Bir sayi girmelisiniz)!!!\nYapmak istediginiz islem nedir: ");
            scanf("%*s"); // Girişi geçersiz kıl
        }
        switch (islem)
        {
        case 1:
            //          İsim alma
            printf("+- Ogrencinin ismini ve soyismini aralarinda bosluk birakarak giriniz -+\n");
            printf("Ogrenci : ");
            getchar();
            fgets(new_ogrenci.isim, sizeof(new_ogrenci.isim), stdin); // Boslukları da almak amacımız
            // Sonda ki new line silmeliyiz
            i = 0;
            while (new_ogrenci.isim[i])
            {
                if ((i == 0 || new_ogrenci.isim[i - 1] == ' ') && (new_ogrenci.isim[i] > 96 && new_ogrenci.isim[i] < 123)) // Kelimelerin ilk harfini büyüt
                    new_ogrenci.isim[i] -= 32;
                
                if (!(i == 0 || new_ogrenci.isim[i - 1] == ' ') && (new_ogrenci.isim[i] > 40 && new_ogrenci.isim[i] < 91)) // Kelimelerin ortasında ki harfleri küçült
                    new_ogrenci.isim[i] += 32;

                if ((new_ogrenci.isim[i] == '\n') || (new_ogrenci.isim[i] == ' ' && (new_ogrenci.isim[i + 1] == '\n'))) // Sonda ki \n NULL yapıyoruz veya sonda ki fazla bosluk varsa siliyoruz
                    new_ogrenci.isim[i] = '\0';
                i++;
            }
            //          Not Ortalmasi
            printf("Ogrencinin not ortalmasi : ");
            new_ogrenci.ort = 0; // Eger program birkaç defa çalıştırılırsa yanlıs girilen bir değer olsa eski degeri alıp onu database atar, bu yüzden degeri sıfırla
            scanf("%d", &new_ogrenci.ort);  // Eger kullanıcı bir sayı değilde harf girerese 0 degeri atanıyor bu yüzden sıfır sayısını almıyoruz
            while (new_ogrenci.ort < 1 || new_ogrenci.ort > 100)
            {
                printf("Gecerli bir not giriniz (1 - 100) : ");
                getchar( );
                scanf("%d", &new_ogrenci.ort);
            }
            // Struct hazır yolla
            VT_ekle(new_ogrenci);
            break;
        case 2:
            char sorguismi[256];
            printf("Sorgulamak istediiniz ogrencinin ismi : ");
            getchar();
            fgets(sorguismi, 256, stdin);
            if (!(sorguismi[0]) || sorguismi[0] == '\n')
            {
                printf("Isimsiz kayit bulunamadi :) \n");
                break ;
            }
            VT_sorgu(sorguismi);
            break;
        case 3:
            VT_yaz();
            break;
        case 0:
            break;
        default:
            printf("\n!!! Gecersiz islem !!! \n");
            break;
        }
    } while (islem != 0);

    printf("\n* Programdan Basarili sekilde cikis saglandi *\n");
    printf("----------------------------------------------\n");
    return 0;
}