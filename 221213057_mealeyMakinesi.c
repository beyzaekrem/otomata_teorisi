#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DURUMLAR 10
#define MAX_GIRDILER 10
#define MAX_CIKISLAR 10

char durumlar[MAX_DURUMLAR][10];
char girdiler[MAX_GIRDILER][10];
char cikislar[MAX_CIKISLAR][10];
char gecisTablosu[MAX_DURUMLAR][MAX_GIRDILER][2][10]; // [durum][girdi][0->yeni durum, 1->cikis]

void durumlariGuvenliAlmaKontrolu(char* istem, char* tampon, int boyut);
void gecisleriAl(int durumSayisi, int girdiSayisi);
void durumGecisTablosunuYazdir(int durumSayisi, int girdiSayisi);

void sayilariAl() 
{
    int durumSayisi, girdiSayisi, cikisSayisi;
    
    printf("durum sayisini girin: ");
    scanf("%d",&durumSayisi);
    getchar();
    
    char durumGirdisi[100];
    durumlariGuvenliAlmaKontrolu("\ndurumlari girin (S0,S1 seklinde ve aralara virgul koyarak!): ", durumGirdisi, 100);
    
    char* token=strtok(durumGirdisi, ","); //virgul ile kullanim icin
    int i=0;
    while(token != NULL && i<durumSayisi) 
    {
        strcpy(durumlar[i++],token);
        token=strtok(NULL, ",");
    }

    char girdiKumesi[100];
    durumlariGuvenliAlmaKontrolu("\ngiris kumesini girin (0,1 gibi) (aralara virgul koyarak!): ",girdiKumesi,100);
    
    token = strtok(girdiKumesi, ",");
    girdiSayisi=0;
    while(token != NULL) 
    {
        strcpy(girdiler[girdiSayisi++],token);
        token=strtok(NULL, ",");
    }
    
    char cikisKumesi[100];
    durumlariGuvenliAlmaKontrolu("\ncikis kumesini girin (A,B gibi) (aralara virgul koyarak!): ",cikisKumesi,100);

    token=strtok(cikisKumesi, ",");
    cikisSayisi=0;
    while(token != NULL) 
    {
        strcpy(cikislar[cikisSayisi++],token);
        token=strtok(NULL, ",");
    }
    gecisleriAl(durumSayisi, girdiSayisi);
    durumGecisTablosunuYazdir(durumSayisi, girdiSayisi);
}

void gecisleriAl(int durumSayisi,int girdiSayisi) 
{
    char yeniDurum[10];
    char cikis[10];
    
    for(int i=0; i<durumSayisi; i++) 
    {
        for(int j=0; j<girdiSayisi; j++) 
        {
            printf("\n%s durumunda %s girisi ile yeni durumu ve ciktiyi girin. ",durumlar[i],girdiler[j]);
            printf("\nyeni durum: ");
            scanf("%s",yeniDurum);
            getchar();  // satir sonunu temizler
            printf("cikis: ");
            scanf("%s",cikis);
            getchar(); 
            
            // durum gecisini kaydeder
            strcpy(gecisTablosu[i][j][0], yeniDurum);
            strcpy(gecisTablosu[i][j][1], cikis);
        }
    }
}

void durumGecisTablosunuYazdir(int durumSayisi,int girdiSayisi) 
{
    printf("\ndurum tablosu:\n");
    printf("    ");
    
    for(int i=0; i<girdiSayisi; i++) 
    {
        printf("girdi %s  ", girdiler[i]);
    }
    printf("\n");
    
    for(int i=0; i<durumSayisi; i++) 
    {
        printf("%s  ", durumlar[i]);
        for(int j=0; j<girdiSayisi; j++) 
        {
            printf("(%s, %s)  ",gecisTablosu[i][j][0],gecisTablosu[i][j][1]);
        }
        printf("\n");
    }
}

void durumlariGuvenliAlmaKontrolu(char* istem, char* tampon, int boyut) 
{
    printf("%s",istem);
    fgets(tampon,boyut,stdin);//durumlari guvenli almak icin fgets kullanilir.
    tampon[strcspn(tampon, "\n")] = '\0';  //yeni satir karakterini temizler.
}

int main() 
{
    printf("\nMealey Makinesi \n\n");
    sayilariAl();
    return 0;
}