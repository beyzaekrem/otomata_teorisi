#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_DURUMLAR 10
#define MAX_GIRDILER 10

int gecisTablosu[MAX_DURUMLAR][MAX_GIRDILER];
char cikis[MAX_DURUMLAR][10];

int durumlar;
int girdiler;

void tabloOlustur() 
{
    printf("\ndurum gecis tablosunu girin.(q1,q2 gibi degerler)\n");
    for(int i=0; i<durumlar; i++) 
    {
        for(int j=0; j<girdiler; j++) 
        {
            char durum[10];
            printf("durum q%d için girdi %d: ",i,j);
            scanf("%s",durum);
            if(durum[0] == '-') 
            {
                gecisTablosu[i][j]= -1; 
            } 
            else 
            {
                gecisTablosu[i][j]=atoi(&durum[1]); 
            }
        }
    }
    printf("\ncikislari girin:\n");
    for(int i=0; i<durumlar; i++)
    {
        printf("durum q%d için cikis: ",i);
        scanf("%s",cikis[i]);
    }
}

int yeniDurumBul(int mevcutDurum, int girdi) 
{
    if(girdi >= 0 && girdi<girdiler) 
    {
        return gecisTablosu[mevcutDurum][girdi];
    }
    return -1;
}

char* cikisiDondur(int durum) 
{
    if (durum >= 0 && durum<durumlar) 
    {
        return cikis[durum];
    }
    return NULL;
}

void mooreMakinesi(char* girdiDizisi) 
{
    int mevcutDurum = 0;  
    printf("\nbaslangic durumu: q%d, cikis: %s\n",mevcutDurum,cikisiDondur(mevcutDurum));
    for (int i=0; i<strlen(girdiDizisi); i++) 
    {
        int girdi=girdiDizisi[i]-'0';  
        int yeniDurum = yeniDurumBul(mevcutDurum, girdi);
        if (yeniDurum == -1) 
        {
            printf("\ngecersiz durum gecisi!\n");
            return;
        }
        mevcutDurum=yeniDurum;
        printf("girdi: %d, yeni durum: q%d, cikis: %s\n",girdi,mevcutDurum,cikisiDondur(mevcutDurum));
    }
}
int main() 
{
    printf("\nMoore Makinesi \n");
    printf("\ndurum sayisini girin:");
    scanf("%d",&durumlar);
    printf("\ngirdi sayisini girin:");
    scanf("%d", &girdiler);

    tabloOlustur();

    char girdiDizisi[50];
    printf("\nsimulasyon icin girdi dizisini girin:");
    scanf("%s",girdiDizisi);

    mooreMakinesi(girdiDizisi);

    return 0;
}