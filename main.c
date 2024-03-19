#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void cevap_anahtari_uret(char cevap_anahtari[], int S){

    srand(time(0));

    for(int i=0;i<S;i++){
    int x=(rand()%5)+1;
    switch(x){
    case 1:
        cevap_anahtari[i]='A';
            break;
    case 2:
        cevap_anahtari[i]='B';
            break;
    case 3:
        cevap_anahtari[i]='C';
            break;
    case 4:
        cevap_anahtari[i]='D';
            break;
    default:
        cevap_anahtari[i]='E';
            break;
    }
    }
}

void cevap_anahtari_yazdir(char cevap_anahtari[], int S){
    printf("Cevap Anahtari:\n");
    for(int i=1;i<=S;i++){
    printf("%03d:%c | ",i,cevap_anahtari[i-1]);
}
printf("\n");
}

void sinavi_uygula(char ogrenci_cevaplari[][100], char cevap_anahtari[], int N, int S, double B,
double D){

    srand(time(0));
    for(int i=0;i<N;i++){
        for(int j=0;j<S;j++){
            int x=(rand()%100)+1;
                if(x<=(D*100)){
                    ogrenci_cevaplari[i][j]=cevap_anahtari[j];
                }
                else if(x>(D*100)&&x<=((D+B)*100)){
                    ogrenci_cevaplari[i][j]='X';
                }
                else{
                    int y=(rand()%5)+1;
                    switch(y){
                        case 1:
                            ogrenci_cevaplari[i][j]='A';

                            if(ogrenci_cevaplari[i][j]!=cevap_anahtari[j]){
                            break;}

                            else{
                                int z=(rand()%4)+1;
                                switch(z){
                                case 1:
                                    ogrenci_cevaplari[i][j]='B';
                                        break;
                                case 2:
                                    ogrenci_cevaplari[i][j]='C';
                                        break;
                                case 3:
                                    ogrenci_cevaplari[i][j]='D';
                                        break;
                                default:
                                    ogrenci_cevaplari[i][j]='E';
                                        break;
                                }}
                                break;
                        case 2:
                            ogrenci_cevaplari[i][j]='B';

                            if(ogrenci_cevaplari[i][j]!=cevap_anahtari[j]){
                            break;}

                            else{
                                int z=(rand()%4)+1;
                                switch(z){
                                case 1:
                                    ogrenci_cevaplari[i][j]='A';
                                        break;
                                case 2:
                                    ogrenci_cevaplari[i][j]='C';
                                        break;
                                case 3:
                                    ogrenci_cevaplari[i][j]='D';
                                        break;
                                default:
                                    ogrenci_cevaplari[i][j]='E';
                                        break;
                                }}
                                break;
                        case 3:
                            ogrenci_cevaplari[i][j]='C';

                            if(ogrenci_cevaplari[i][j]!=cevap_anahtari[j]){
                            break;}

                            else{
                                int z=(rand()%4)+1;
                                switch(z){
                                case 1:
                                    ogrenci_cevaplari[i][j]='A';
                                        break;
                                case 2:
                                    ogrenci_cevaplari[i][j]='B';
                                        break;
                                case 3:
                                    ogrenci_cevaplari[i][j]='D';
                                        break;
                                default:
                                    ogrenci_cevaplari[i][j]='E';
                                        break;
                                }}
                        case 4:
                            ogrenci_cevaplari[i][j]='D';

                            if(ogrenci_cevaplari[i][j]!=cevap_anahtari[j]){
                            break;}

                            else{
                                int z=(rand()%4)+1;
                                switch(z){
                                case 1:
                                    ogrenci_cevaplari[i][j]='A';
                                        break;
                                case 2:
                                    ogrenci_cevaplari[i][j]='B';
                                        break;
                                case 3:
                                    ogrenci_cevaplari[i][j]='C';
                                        break;
                                default:
                                    ogrenci_cevaplari[i][j]='E';
                                        break;
                                }}
                                break;
                        default:
                            ogrenci_cevaplari[i][j]='E';

                            if(ogrenci_cevaplari[i][j]!=cevap_anahtari[j]){
                            break;}

                            else{
                                int z=(rand()%4)+1;
                                switch(z){
                                case 1:
                                    ogrenci_cevaplari[i][j]='A';
                                        break;
                                case 2:
                                    ogrenci_cevaplari[i][j]='B';
                                        break;
                                case 3:
                                    ogrenci_cevaplari[i][j]='C';
                                        break;
                                default:
                                    ogrenci_cevaplari[i][j]='D';
                                        break;
                                }}
                                break;
                        }
                }
        }
        }
    }

void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100],int ogrenci_ID, int S){

        printf("%03d.Ogrencinin Cevaplari:\n",ogrenci_ID+1);
        for(int i=1;i<=S;i++){
            printf("%03d:%c | ",i,ogrenci_cevaplari[ogrenci_ID][i-1]);
        }
        printf("\n");

}

void ogrencileri_puanla(char ogrenci_cevaplari[][100], char cevap_anahtari[], double HBN[],
int N, int S){

    for(int i=0;i<N;i++){
        double sayac1=0.0;
        double sayac2=0.0;
        for(int j=0;j<S;j++){
            if(ogrenci_cevaplari[i][j]!=cevap_anahtari[j]&&ogrenci_cevaplari[i][j]!='X'){
                sayac1++;
            }
            if(ogrenci_cevaplari[i][j]==cevap_anahtari[j]){
                sayac2++;
            }
        }

        double puan=(sayac2-((sayac1/4)))*(100.0/S);

        if(puan<0.0){
           HBN[i]=0.0;
        }
        else
            HBN[i]=puan;
    }

    /*for(int i=0;i<N;i++){
        printf("%d.Ogrencinin puani: %.2lf\n",i+1,HBN[i]);
    }*/
}

double sinif_ortalamasi_hesapla(double HBN[], int N){

    double toplam=0.00;
    double ortalama=0.00;

    for(int i=0;i<N;i++){
        toplam+=HBN[i];
    }
    ortalama= toplam/N;
    return(ortalama);
}

double standart_sapma_hesapla(double ortalama, double HBN[], int N){

    double toplam=0.0;
    ortalama=sinif_ortalamasi_hesapla(HBN,N);
    for(int i=0;i<N;i++){
        toplam+=pow((HBN[i]-ortalama),2.0);
    }
    double standart_sapma=(sqrt(toplam/N));

    if(standart_sapma>0&&standart_sapma<100){
        return(standart_sapma);
    }
    else{
        double standart_sapma=0.0;
        return 0.0;
    }
}

void T_skoru_hesapla(double ortalama, double HBN[], int N, double std, double T_skoru[]){


    ortalama=sinif_ortalamasi_hesapla(HBN,N);
    std=standart_sapma_hesapla(ortalama,HBN,N);
    for(int i=0;i<N;i++){
        T_skoru[i]=60.0+(10.0*((HBN[i]-ortalama)/std));

        if(ortalama<=100&&ortalama>80){
                if(T_skoru[i]<32)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FF\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=32&&T_skoru[i]<37)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=37&&T_skoru[i]<42)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=42&&T_skoru[i]<47)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=47&&T_skoru[i]<52)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=52&&T_skoru[i]<57)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=57&&T_skoru[i]<62)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=62&&T_skoru[i]<67)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BA\n",i+1,HBN[i],T_skoru[i]);
                else if(ortalama==100){
                    double a=70.0;
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:AA\n",i+1,HBN[i],a);
        }
                else
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:AA\n",i+1,HBN[i],T_skoru[i]);
        }
        else if(ortalama<=80&&ortalama>70){
                if(T_skoru[i]<34)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FF\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=34&&T_skoru[i]<39)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=39&&T_skoru[i]<44)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=44&&T_skoru[i]<49)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=49&&T_skoru[i]<54)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=54&&T_skoru[i]<59)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=59&&T_skoru[i]<64)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=64&&T_skoru[i]<69)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BA\n",i+1,HBN[i],T_skoru[i]);
                else
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:AA\n",i+1,HBN[i],T_skoru[i]);

        }
        else if(ortalama<=70&&ortalama>62.5){
                if(T_skoru[i]<36)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FF\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=36&&T_skoru[i]<41)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=41&&T_skoru[i]<46)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=46&&T_skoru[i]<51)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=51&&T_skoru[i]<56)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=56&&T_skoru[i]<61)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=61&&T_skoru[i]<66)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=66&&T_skoru[i]<71)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BA\n",i+1,HBN[i],T_skoru[i]);
                else
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:AA\n",i+1,HBN[i],T_skoru[i]);

        }
        else if(ortalama<=62.5&&ortalama>57.5){
                if(T_skoru[i]<38)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FF\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=38&&T_skoru[i]<43)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=43&&T_skoru[i]<48)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=48&&T_skoru[i]<53)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=53&&T_skoru[i]<58)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=58&&T_skoru[i]<63)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=63&&T_skoru[i]<68)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=68&&T_skoru[i]<73)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BA\n",i+1,HBN[i],T_skoru[i]);
                else
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:AA\n",i+1,HBN[i],T_skoru[i]);

        }
        else if(ortalama<=62.5&&ortalama>57.5){
                if(T_skoru[i]<38)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FF\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=38&&T_skoru[i]<43)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=43&&T_skoru[i]<48)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=48&&T_skoru[i]<53)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=53&&T_skoru[i]<58)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=58&&T_skoru[i]<63)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=63&&T_skoru[i]<68)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=68&&T_skoru[i]<73)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BA\n",i+1,HBN[i],T_skoru[i]);
                else
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:AA\n",i+1,HBN[i],T_skoru[i]);
        }
        else if(ortalama<=57.5&&ortalama>52.5){
                if(T_skoru[i]<40)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FF\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=40&&T_skoru[i]<45)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=45&&T_skoru[i]<50)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=50&&T_skoru[i]<55)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=55&&T_skoru[i]<60)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=60&&T_skoru[i]<65)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=65&&T_skoru[i]<70)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=70&&T_skoru[i]<75)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BA\n",i+1,HBN[i],T_skoru[i]);
                else
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:AA\n",i+1,HBN[i],T_skoru[i]);

        }
        else if(ortalama<=52.5&&ortalama>47.5){
                if(T_skoru[i]<42)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FF\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=42&&T_skoru[i]<47)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=47&&T_skoru[i]<52)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=52&&T_skoru[i]<57)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=57&&T_skoru[i]<62)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=62&&T_skoru[i]<67)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=67&&T_skoru[i]<72)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=72&&T_skoru[i]<77)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BA\n",i+1,HBN[i],T_skoru[i]);
                else
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:AA\n",i+1,HBN[i],T_skoru[i]);

        }
        else if(ortalama<=47.5&&ortalama>42.5){
                if(T_skoru[i]<44)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FF\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=44&&T_skoru[i]<49)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=49&&T_skoru[i]<54)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=54&&T_skoru[i]<59)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=59&&T_skoru[i]<64)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=64&&T_skoru[i]<69)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=69&&T_skoru[i]<74)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=74&&T_skoru[i]<79)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BA\n",i+1,HBN[i],T_skoru[i]);
                else
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:AA\n",i+1,HBN[i],T_skoru[i]);

        }
        else if(ortalama<=42.5&&ortalama>=0){
                if(T_skoru[i]<46)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FF\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=46&&T_skoru[i]<51)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=51&&T_skoru[i]<56)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DD\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=56&&T_skoru[i]<61)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:DC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=61&&T_skoru[i]<66)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CC\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=66&&T_skoru[i]<71)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:CB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=71&&T_skoru[i]<76)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BB\n",i+1,HBN[i],T_skoru[i]);
                else if(T_skoru[i]>=76&&T_skoru[i]<81)
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:BA\n",i+1,HBN[i],T_skoru[i]);
                else if(ortalama==0){
                    double b=40.0;
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:FF\n",i+1,HBN[i],b);
        }
                else
                    printf("%03d. Ogrencinin Puani: %.2lf, T_Skoru:%.2lf, Harf Notu:AA\n",i+1,HBN[i],T_skoru[i]);
        }
    }
}

void sinif_duzeyi(double ortalama,double HBN[], int N){
    ortalama=sinif_ortalamasi_hesapla(HBN,N);

    if(ortalama<=100&&ortalama>80){
        printf("Sinif Duzeyi:Ustun Basari\n");}
    else if(ortalama<=80&&ortalama>70){
        printf("Sinif Duzeyi:Mukemmel\n");}
    else if(ortalama<=70&&ortalama>62.5){
        printf("Sinif Duzeyi:Cok Iyi\n");}
    else if(ortalama<=62.5&&ortalama>57.5){
        printf("Sinif Duzeyi:Iyi\n");}
    else if(ortalama<=57.5&&ortalama>52.5){
        printf("Sinif Duzeyi: Ortanin Ustu\n");}
    else if(ortalama<=52.5&&ortalama>47.5){
        printf("Sinif Duzeyi:Orta\n");}
    else if(ortalama<=47.5&&ortalama>42.5){
        printf("Sinif Duzeyi:Zayif\n");}
    else if(ortalama<=42.5&&ortalama>=0){
        printf("Sinif Duzeyi:Kotu\n");}
}

int main()
{

    int N,S;
    double B,D;
    int Ogrenci_ID=0;

    while(1){
    printf("Ogrenci sayisini giriniz(MAKS 100): ");
    scanf("%d",&N);

        if(N>=0&&N<=100){
            break;
        }
        else
            printf("Gecersiz Ogrenci Sayisi!\n");
    }

    while(1){
    printf("Soru sayisini giriniz(MAKS 100): ");
    scanf("%d",&S);

        if(S>=0&&S<=100)
            break;

        else
            printf("Gecersiz Soru Sayisi!\n");
    }

    while(1){
    printf("Bos birakma ihtimalini giriniz (0.0-1.0): ");
    scanf("%lf",&B);

        if(B>=0&&B<=1)
            break;
        else
            printf("Gecersiz deger araligi!\n");
            }

    while(1){
    printf("Dogru cevap verme ihtimalini giriniz (0.0-1.0): ");
    scanf("%lf",&D);

        if(D>=0&&D+B<=1)
            break;
        else
            printf("Gecersiz deger araligi!\n");

    }

    char Cevap_anahtari[100];
    char Ogrenci_cevaplari[N][100];
    double T_skoru[N];
    double HBN[N];
    double Ortalama=0.0;
    double Std=0.0;
    cevap_anahtari_uret(Cevap_anahtari,S);
    cevap_anahtari_yazdir(Cevap_anahtari,S);
    sinavi_uygula(Ogrenci_cevaplari,Cevap_anahtari,N,S,B,D);

    for(Ogrenci_ID=0;Ogrenci_ID<N;Ogrenci_ID++){
    ogrenci_cevabini_yazdir(Ogrenci_cevaplari,Ogrenci_ID,S);
    }

    ogrencileri_puanla(Ogrenci_cevaplari,Cevap_anahtari,HBN,N,S);
    printf("Sinif Ortalamasi:%.2lf || Standart Sapma:%.2lf\n",sinif_ortalamasi_hesapla(HBN,N),standart_sapma_hesapla(Ortalama,HBN,N));
    sinif_duzeyi(Ortalama,HBN,N);
    T_skoru_hesapla(Ortalama,HBN,N,Std,T_skoru);

    return 0;
}
