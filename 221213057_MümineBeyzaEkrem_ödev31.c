#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KELIME 1000
#define MAX_KURAL 100

typedef struct {
    char sol[10];
    char sag[10][10];
    int sag_sayisi;
} Kural;

void cfg_dil_olustur(Kural kurallar[],int kural_sayisi,char *baslangic_sembol,char kelimeler[][MAX_KELIME],int *kelime_sayisi) 
{
    char kuyruk[MAX_KELIME][MAX_KELIME];
    int bas=0, son = 0;
    
    strcpy(kuyruk[son++],baslangic_sembol);
    while(bas<son) 
    {
        char kelime[MAX_KELIME];
        strcpy(kelime, kuyruk[bas++]);
        int terminal = 1; 
        for(int i=0; kelime[i] != '\0'; i++) 
        {
            if(kelime[i] >= 'A' && kelime[i] <= 'Z') 
            { 
                terminal=0;
                for(int j=0; j<kural_sayisi; j++) 
                {
                    if(kelime[i] == kurallar[j].sol[0]) 
                    {
                        for(int k=0; k<kurallar[j].sag_sayisi; k++) 
                        {
                            char yeni_kelime[MAX_KELIME] = "";
                            strncat(yeni_kelime,kelime,i); 
                            strcat(yeni_kelime,kurallar[j].sag[k]);
                            strcat(yeni_kelime,kelime+i+1);
                            strcpy(kuyruk[son++],yeni_kelime);
                        }
                    }
                }
                break;
            }
        }

        if(terminal) 
        { 
            int tekrar_var=0;
            for(int t=0; t < *kelime_sayisi; t++) 
            {
                if(strcmp(kelimeler[t],kelime)==0) 
                { 
                    tekrar_var=1;
                    break;
                }
            }
            if(!tekrar_var) 
            { 
                strcpy(kelimeler[(*kelime_sayisi)++],kelime);
            }
        }
    }
}

int main() 
{
    Kural kurallar[MAX_KURAL];
    char baslangic_sembol[10];
    char kelimeler[MAX_KELIME][MAX_KELIME];
    int kelime_sayisi = 0;
    int kural_sayisi;

    printf("Kuralların sayısını giriniz: ");
    scanf("%d",&kural_sayisi);

    for(int i=0; i<kural_sayisi; i++) 
    {
        printf("%d. kuralın sol tarafı: ",i + 1);
        scanf("%s",kurallar[i].sol);
        
        printf("%d. kuralın sağ tarafındaki üretim sayısı: ",i + 1);
        scanf("%d",&kurallar[i].sag_sayisi);
        
        for(int j=0; j<kurallar[i].sag_sayisi; j++) 
        {
            printf("Sağ taraf %d: ",j + 1);
            scanf("%s",kurallar[i].sag[j]);
        }
    }

    printf("Başlangıç sembolünü giriniz: ");
    scanf("%s",baslangic_sembol);

    cfg_dil_olustur(kurallar,kural_sayisi,baslangic_sembol,kelimeler,&kelime_sayisi);

    printf("\nCFG Tarafından Üretilen Kelimeler:\n");
    for(int i=0; i<kelime_sayisi; i++) 
    {
        printf("%s\n", kelimeler[i]);
    }
    return 0;
}