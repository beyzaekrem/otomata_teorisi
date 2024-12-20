#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int ogeler[MAX_SIZE];
    int top;
} Yigin;

void yigin_baslat(Yigin* yigin) 
{
    yigin->top = -1;
}

int yigin_bos_mu(Yigin* yigin) {
    return yigin->top == -1;
}

void yigina_eleman_ekle(Yigin* yigin, int deger) 
{
    if(yigin->top < MAX_SIZE - 1) 
    {
        yigin->ogeler[++yigin->top] = deger;
    }
}

int yigindan_eleman_cikar(Yigin* yigin) 
{
    if(!yigin_bos_mu(yigin)) 
    {
        return yigin->ogeler[yigin->top--];
    }
    return -1; 
}

int aritmetik_islem(int a, int b, char islem) 
{
    switch (islem) 
    {
        case '+': 
            return a + b;
        case '-': 
            return a - b;
        case '*': 
            return a * b;
        case '/': 
            return a / b;
        default: 
            return 0;
    }
}

int rakam_mi(char c) 
{
    return c >= '0' && c <= '9';
}

int polish_notasyonu(char* ifade) 
{
    Yigin yigin;
    yigin_baslat(&yigin);

    char* token = strtok(ifade, " ");
    
    char* tokens[100];
    int tokenSayisi = 0;

    while(token != NULL) 
    {
        tokens[tokenSayisi++] = token;
        token = strtok(NULL, " ");
    }

    int i;
    for(i = tokenSayisi-1; i >= 0; i--) 
    {
        token=tokens[i];
        
        if(rakam_mi(token[0]) || (token[0] == '-' && rakam_mi(token[1]))) 
        {
            yigina_eleman_ekle(&yigin,atoi(token));
        } 
        else 
        {
            int a = yigindan_eleman_cikar(&yigin);
            int b = yigindan_eleman_cikar(&yigin);
            int sonuc = aritmetik_islem(a,b,token[0]);
            yigina_eleman_ekle(&yigin,sonuc);
        }
    }
    return yigindan_eleman_cikar(&yigin);
}

int main() 
{
    char ifade[MAX_SIZE];

    printf("Polish Notasyonu ifadesini girin: ");
    fgets(ifade,MAX_SIZE,stdin);

    ifade[strcspn(ifade, "\n")]=0;

    int sonuc = polish_notasyonu(ifade);
    printf("Sonuc: %d\n",sonuc);

    return 0;
}
