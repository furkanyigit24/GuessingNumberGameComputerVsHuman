//
//  main.c
//  NumberGuessingComputerVsHuman
//
//  Created by Furkan Y. on 19.02.2021.
//  Copyright © 2021 Furkan Yigit Akyildiz. All rights reserved.
//

#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void computerGuessing()
{
    int r=123,n,a[10],b[10],c[10],d[10],B[10],C[10],i=-1,j=0,t=0;
    srand(time(NULL));
    t=i;
    while(B[i]!=4) // + değerler 4 değilse döngüye girer
    {
        label2:
        if(r==70000) // Yeterli sayıda tahimn yapılıp hala sonuca ulasılamadıysa
        {
            printf("\nVerdiginiz yanitlarla ilgili bir sorun var.");
            break;
        }
        if (j==0 || (rand()%10)!=9) // 0.9 kez rastgele sayı seçilecektir
        {
            d[j]=rand()%10;
            c[j]=rand()%10;
            b[j]=rand()%10;
            a[j]=rand()%10;
        }
        // Verilen yanıtları karşılayan en küçük sayının 0.1 kez seçilecektir
        else
        {
            n=r;
            d[j]=n%10; n=n/10;
            c[j]=n%10; n=n/10;
            b[j]=n%10; n=n/10;
            a[j]=n%10; n=n/10;
            r=r+1;
        }
        if ((a[j]==b[j]||a[j]==c[j]||a[j]==d[j]) || (b[j]==c[j]||b[j]==d[j]) || (c[j]==d[j])) {goto label2;} // Birbirini tekrar eden sayı üretilmişse Label2: satırına gider
        
         /* İlgili basamak değerinin kullanıcıdan alınan "+" ve "-" geri bildirimine göre kıyaslar, basamak ve değer uyusuyorsa B arttırılır, sadece değer uyusuyorsa C arttırılır*/
        label3:
        if (a[j]==b[i]||a[j]==c[i]||a[j]==d[i]) {C[j]=C[j]+1;} if(a[j]==a[i]) {B[j]=B[j]+1;}
        if (b[j]==a[i]||b[j]==c[i]||b[j]==d[i]) {C[j]=C[j]+1;} if(b[j]==b[i]) {B[j]=B[j]+1;}
        if (c[j]==b[i]||c[j]==a[i]||c[j]==d[i]) {C[j]=C[j]+1;} if(c[j]==c[i]) {B[j]=B[j]+1;}
        if (d[j]==b[i]||d[j]==c[i]||d[j]==a[i]) {C[j]=C[j]+1;} if(d[j]==d[i]) {B[j]=B[j]+1;}
        while(i>=0)
        {
            if (B[j] != B[i] || C[j] != C[i])
            {
                B [j] = C[j] = 0;
                i=t;
                goto label2; // Rakamlar ilgili basamak değerleri ile uyuşmuyorsa label2 satırana gider
            }
            i = i-1;
            B[j] = C[j] = 0;
            goto label3; // sayaç bir düşürülüp label3 satırına gider ve tekrardan rakamların değerini ve basamak yerini kontrol eder
        }
        i=t+1; t=i; r=1000;
        printf("\nTahminim %d%d%d%d\n+ : ",a[j],b[j],c[j],d[j]);
        a[i]=a[j];
        b[i]=b[j];
        c[i]=c[j];
        d[i]=d[j];
        scanf("%d",&B[i]);
        if (B[i]!=4) // Pozitif sayı değeri 4 değil ise negatif değeri kullaıcıdan al
        {
            printf("- : ");
            scanf("%d",&C[i]);
        }
        j=j+1;
    }
    if (B[i]==4){ printf(" %d. tahminimde bildim",j); }
}
void humanGuessing()
{
    int n,a=0,b=0,c,d,a1,b1,c1,d1,P=0,N,counter=0;
    int x,y,z,t;
    srand(time(NULL)); // Programı her koşturduğumuzda farklı saylılar türetmeyi sağlar

    /* Eğer üretilen rakamlar birbiri ile aynı ise tekrardan üretilmelidir. 2268 üretildiğini varsayarsak 2 rakamlarından birinin değişmesi gerekir dolayısı ile while döngüsü kullanılarak bu kontrol sağlanır */
    while(a==b||a==c||a==d||b==c||b==d||c==d)
    {
        a=(rand() % 9) + 1; // 0 sayısı üretilmemesi için
        b=rand()%10; // 0 ile 9 arası değer atanır
        c=rand()%10; // 0 ile 9 arası değer atanır
        d=rand()%10; // 0 ile 9 arası değer atanır
    }
    while(P!=4)
    {
        n=0;
        while(a1==b1||a1==c1||a1==d1||b1==c1||b1==d1||c1==d1||n<123||n>9876)
        {
            printf("\nTahmin ettiginiz sayiyi giriniz: ");
            scanf("%d",&n);
            t=n%10;
            z=(n/10)%10;
            y=(n/100)%10;
            x=(n/1000)%10;
            if (n<1000 || n>9999)
            {
                printf("\n 4 basamakli giriniz\n");
            }
            else if (x==y||x==z||x==t||y==z||y==t||z==t)
            {
            printf("\n Birbirini tekrarlayan rakamlar girdiniz, lutfen birbirinden farklı olacak sekilde 4 basamakli sayi giriniz\n");
            }
            else
            {
            d1=n%10; // birler basamağı d1 e atanır
            c1=(n/10)%10; // onlar basamağı c1 e atanır
            b1=(n/100)%10; // yüzler basamağı b1 e atanır
            a1=(n/1000)%10; // binler basamağı a1 e atanır
            }
        }
        P=0; N=0;
        if(a1==b||a1==c||a1==d) { N=N+1; } else if(a1==a) { P=P+1; }
        if(b1==a||b1==c||b1==d) { N=N+1; } else if(b1==b) { P=P+1; }
        if(c1==b||c1==a||c1==d) { N=N+1; } else if(c1==c) { P=P+1; }
        if(d1==b||d1==c||d1==a) { N=N+1; } else if(d1==d) { P=P+1; }
        counter=counter+1;
        printf("+\t-\n%d \t%d\n",P,N);
        if(P==4)
            printf("\nTebrikler %d. tahmininde dogru sayiyi buldun\r",counter);
    }
}
int main() {
    int decision;
    
    printf("Bilgisayarin sizin aklinizdaki sayiyi tahmin etmesini istiyorsaniz 1, eger siz bilgisayarın tuttugu sayiyi bilmek istiyorsaniz 2 yazin\n");
    scanf("%d",&decision);
    if (decision == 1)
    {
        computerGuessing();
    }
    else if (decision == 2)
    {
        humanGuessing();
    }
    else
        printf("1 veya 2 rakamlarindan birini girmelisiniz");
    return 0;
}
