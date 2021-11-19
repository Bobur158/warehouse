#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    char nomi[100];
    int narxi;
    int sotildi;
    int mavjud;
} Product;


Product mahsulotlar[100];   
int mahsulot_index = 0;
int mavjud_mahsulotlar = 0;
int sotilgan_mahsulot = 0;
int sotilgan_summa = 0;


int menyuni_chiqarish() {

    printf("\n1.Mahsulotlar\n");
    printf("2.Mahsulot qushish\n");
    printf("3.Kirim\n");
    printf("4.sotish\n");
    printf("5.statistika\n");
    printf("6.chiqish\n");
    printf("\n");
    printf("\nTanlang :\n");

    int n;
    scanf("%d",&n);
    return n;
}

void saqlash() {

    FILE *f = fopen("xarajatlar.txt", "w");
        fprintf(f, "%d\n", mavjud_mahsulotlar);
    for(int i = 0; i < mavjud_mahsulotlar; i++) {
        fprintf(f, "%s %d\n", mahsulotlar[i].nomi,
            mahsulotlar[i].narxi);
    }
         
        fclose(f);
}

void mahsulot_ruyxati(Product mahsulotlar[]) {
         
    FILE *f = fopen("xarajatlar.txt", "r");
        fscanf(f, "%d", &mavjud_mahsulotlar);

    for(int i = 0; i < mavjud_mahsulotlar; i++){
        fscanf(f, "%s %d\n",mahsulotlar[i].nomi,
            &mahsulotlar[i].narxi);

        printf("%d.%s %d so`m \n",i + 1, 
            mahsulotlar[i].nomi, 
            mahsulotlar[i].narxi);

    }
           
}

void mahsulot_qushish(Product mahsulotlar[]) {

    printf("Mahsulot qushish :\n\n");
    
    printf("Nomi: ");
    scanf("%s", mahsulotlar[mavjud_mahsulotlar].nomi);
    
    printf("Narxi:");
    scanf("%d", &mahsulotlar[mavjud_mahsulotlar].narxi);    
    mahsulotlar[mavjud_mahsulotlar].mavjud = 0;

        //    mahsulotlar[3].raqami=mahsulotlar[mavjud_mahsulotlar].raqami;
        //    strcpy(mahsulotlar[3].nomi,mahsulotlar[mavjud_mahsulotlar].nomi);
        //    mahsulotlar[3].narxi=mahsulotlar[mavjud_mahsulotlar].narxi;
        //    mahsulotlar[3].mavjud=mahsulotlar[mavjud_mahsulotlar].mavjud;

    mahsulotlar[mavjud_mahsulotlar].sotildi = 0;
        mavjud_mahsulotlar++;

        saqlash();
        printf("\nMuvaffaqiyatli bajarildi\n");
}

void kirim(Product mahsulotlar[]) {  

    printf("mahsulot raqamini tanlang:\n");
        mahsulot_ruyxati(mahsulotlar);

    int k;
    scanf("%d", &k);

    for(int i = 0; i < mavjud_mahsulotlar; i++) {
        if(k == i + 1) {
            printf("%s ga qancha qo`shish kerak\n", mahsulotlar[i].nomi);
            int f = mahsulotlar[i].mavjud;
            scanf("%d", &mahsulotlar[i].mavjud);
            mahsulotlar[i].mavjud + f;
            saqlash();  
        }
    }
              
    printf("muvaffaqqiyatli qo`shildi!!!\n");
}

void mahsulot_sotish(Product mahsulotlar[]) {
    printf("Hurmatli xaridor mahsulot raqamini tanlang:\n");

    int d;
    scanf("%d", &d);

    for (int i = 0; i < mavjud_mahsulotlar; i++) {
        if(d == i + 1){
            printf ("%s\n", mahsulotlar[i].nomi);
            printf("nechchi kilo:\n");       

    int e;
    scanf("%d",&e);

        if(mahsulotlar[i].mavjud > e){
            printf("%d so`m\n", e * mahsulotlar[i].narxi);
            sotilgan_summa += e * mahsulotlar[i].narxi;
            mahsulotlar[i].mavjud = mahsulotlar[i].mavjud - e;
            sotilgan_mahsulot++;
    
            saqlash();

        } else {
            printf("kechirasiz bu mahsulotdan %d-kg qolibdi!\n", mahsulotlar[i].mavjud);
        }
            break;    
        }

    }
}
     
void arzon_qimmat() {     

    int mn = mahsulotlar[0].narxi;
    int mx = mahsulotlar[0].narxi;
         
    int mn_index = 0; 
    int mx_index = 0;

    for(int i = 0; i < mavjud_mahsulotlar; i++) {
        if(mahsulotlar[i].narxi > mx){
           mx = mahsulotlar[i].narxi;
            mx_index = i;
        }

        if(mahsulotlar[i].narxi < mn ) {
           mn = mahsulotlar[i].narxi;
            mn_index = i;

        }
    }
        printf("Eng qimmmat mahsulot : %d %s \n", mx, mahsulotlar[mx_index].nomi);
        printf("Eng arzon mahsulot : %d %s\n", mn, mahsulotlar[mn_index].nomi);

}

void statistika(Product mahsulotlar[]) { 

   
    printf("Jami sotilgan mahsulot %d-ta\n", sotilgan_mahsulot);
    printf("jami sotilgan summa %d so'm\n", sotilgan_summa);
    printf("omborda mavjud mahsulotlar %d-ta\n", mavjud_mahsulotlar );
    arzon_qimmat();
} 


     
int main() { 

    while(1){
        int n = menyuni_chiqarish();
        if(n == 6) {
            break;
        } else  if(n == 1) {
            mahsulot_ruyxati(mahsulotlar);
        } else if(n == 2){
            mahsulot_qushish(mahsulotlar);

        } else if(n == 3){
            kirim(mahsulotlar);

        } else if(n == 4){
            mahsulot_sotish(mahsulotlar);

        } else if(n == 5){
            statistika(mahsulotlar);
        } else {
            printf("------------------------------\n");
            printf("Iltimos 1 dan 6 gacha tanlang\n");
            printf("------------------------------\n");
        }
        
    }   
    return 0;
}