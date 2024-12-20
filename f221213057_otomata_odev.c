#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int alfabede_var_mi(char ch, char *alfabe) 
{
    for(int i=0; alfabe[i] != '\0'; i++) 
    {
        if(ch == alfabe[i]) 
        {
            return 1;
        }
    }
    return 0;
}

int sadece_alfabedeki_harflerden_mi_olusuyor(char *duzenli_ifade, char *alfabe) 
{
    for(int i=0; duzenli_ifade[i] != '\0'; i++) 
    {
        if(!alfabede_var_mi(duzenli_ifade[i], alfabe) && 
            duzenli_ifade[i] != '*' && 
            duzenli_ifade[i] != '+' && 
            duzenli_ifade[i] != '(' && 
            duzenli_ifade[i] != ')') 
        {
            return 0;
        }
    }
    return 1;
}

char rastgele_karakter_uret(char *alfabe) 
{
    int uzunluk = strlen(alfabe);
    return alfabe[rand() % uzunluk];
}

int kelime_tekrarli_mi(char kelimeler[][100], char *kelime, int kelime_sayisi) 
{
    for(int i=0; i<kelime_sayisi; i++) 
    {
        if(strcmp(kelimeler[i], kelime) == 0) 
        {
            return 1;
        }
    }
    return 0;
}

void dil_uret(char *duzenli_ifade, char *alfabe, int kelime_sayisi) 
{
    char kelimeler[100][100]; 
    int uretilen_kelime_sayisi = 0;
    int max_deneme = 1000; 

    printf("Duzenli ifade S alfabesinden uretilebilir. Kelimeleriniz listeleniyor...\n");

    while(uretilen_kelime_sayisi < kelime_sayisi && max_deneme > 0) 
    {
        char kelime[100]; 
        int index = 0;

        for(int j=0; duzenli_ifade[j] != '\0'; j++) 
        {
            char ch = duzenli_ifade[j];

            if(ch == '(') 
            {
                char alternatifler[10];
                int alternatif_index = 0;
                j++; 
                while(duzenli_ifade[j] != ')') 
                {
                    if(alfabede_var_mi(duzenli_ifade[j], alfabe)) 
                    {
                        alternatifler[alternatif_index++] = duzenli_ifade[j];
                    }
                    j++;
                }
                alternatifler[alternatif_index] = '\0'; 
                kelime[index++] = rastgele_karakter_uret(alternatifler);
            }
            else if(ch == '*'){
                if(index > 0) 
                { 
                    int tekrar_sayisi = rand() % 5; 
                    char onceki_karakter = kelime[index - 1];

                    for(int k=0; k<tekrar_sayisi; k++) 
                    {
                        kelime[index++] = onceki_karakter;
                    }
                }
            }
            else if(ch == '+'){
                if(index > 0) 
                { 
                    char onceki_karakter = kelime[index - 1];
                    kelime[index++] = onceki_karakter;
                }
            }
            else if(alfabede_var_mi(ch, alfabe)){
                kelime[index++] = ch;
            }
        }
        kelime[index] = '\0'; 

        if(!kelime_tekrarli_mi(kelimeler, kelime, uretilen_kelime_sayisi)) 
        {
            strcpy(kelimeler[uretilen_kelime_sayisi++], kelime); 
        }
        max_deneme--; 
    }
    if(uretilen_kelime_sayisi < kelime_sayisi) 
    {
        printf("\nIstediginiz kadar sonuc uretilemedi. Mevcut kelimeler listeleniyor...\n");
    }
    printf("L = { ");
    for(int i=0; i<uretilen_kelime_sayisi; i++) 
    {
        printf("%s", kelimeler[i]);
        if(i != uretilen_kelime_sayisi - 1) 
        {
            printf(", ");
        }
    }
    printf(" }\n");
}

int kelime_dilde_mi(char *kelime, char *duzenli_ifade) 
{
    int kelime_uzunlugu = strlen(kelime);
    int ifade_uzunlugu = strlen(duzenli_ifade);
    int k=0; 
    for(int i=0; i<ifade_uzunlugu; i++) 
    {
        if(duzenli_ifade[i] == '(') 
        {
            char alternatifler[10];
            int alternatif_index = 0;
            i++;
            while(duzenli_ifade[i] != ')') 
            {
                alternatifler[alternatif_index++] = duzenli_ifade[i];
                i++;
            }
            alternatifler[alternatif_index] = '\0';
            if(k < kelime_uzunlugu && strchr(alternatifler, kelime[k]) != NULL) 
            {
                k++;
            }
            else{
                return 0; 
            }
        } 
        else if(duzenli_ifade[i] == '*'){
            if(k < kelime_uzunlugu) 
            {
                while(k < kelime_uzunlugu && kelime[k] == kelime[k - 1]) 
                {
                    k++;
                }
            }
        } 
        else if(duzenli_ifade[i] == '+'){
            if(k < kelime_uzunlugu && kelime[k] == kelime[k - 1]) 
            {
                k++;
            }
            else{
                return 0; 
            }
        } 
        else{
            if(k < kelime_uzunlugu && duzenli_ifade[i] == kelime[k]) 
            {
                k++;
            } 
            else{
                return 0;
            }
        }
    }
    return k == kelime_uzunlugu; 
}

int main() 
{
    srand(time(0)); 
    char alfabe[100],duzenli_ifade[100],kelime[100];
    int kelime_sayisi;

    printf("Alfabeyi giriniz S={ ");
    scanf("%s", alfabe);
    printf("}\n");
  
    printf("Duzenli ifadeyi giriniz: ");
    scanf("%s", duzenli_ifade);

    if(!sadece_alfabedeki_harflerden_mi_olusuyor(duzenli_ifade, alfabe)) 
    {
        printf("Duzenli ifade S alfabesinden uretilemez!\n");
        return 0;
    }
    printf("L dilinin kac kelimesini gormek istiyorsunuz? : ");
    scanf("%d", &kelime_sayisi);

    dil_uret(duzenli_ifade, alfabe, kelime_sayisi);

    printf("Kontrol etmek istediginiz kelimeyi giriniz: ");
    scanf("%s", kelime);

    if(kelime_dilde_mi(kelime, duzenli_ifade))
    {
        printf("Bu kelime L diline aittir.\n");
    } 
    else{
        printf("Bu kelime L diline ait degildir.\n");
    }
    return 0;
}
