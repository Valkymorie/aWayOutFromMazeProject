#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct matris{
    int deger;
    struct matris *sol;
    struct matris *sag;
    struct matris *alt;
    struct matris *ust;
};

typedef struct matris node;

void bastir(int *labirent,int boyut){
    int i,kontrol;
    for(i=0;i<boyut*boyut;i++){

        kontrol = i%boyut;
        if(kontrol==0 && i!=0){
            printf("\n");
        }
        printf("%2d ",*(labirent+i));
    }

}

int yol_bulma(int *labirent,int giris,int cikis,int boyut,node *yol){
    int kontrol,a,b,c,d;
    if(*(labirent+giris) == 0 && *(labirent+cikis) == 0){
        printf("cikis yok\n");
        return 0;
    }
    if(giris == cikis && *(labirent+giris)==1){
        printf("cikisa ulasti\n");
        *(labirent+giris) = 2;
        bastir(labirent,boyut);
        exit(1);
    }
    if(yol==NULL && giris!=cikis){
        yol = (node*)malloc(sizeof(node));
        yol->alt = NULL;
        yol->sol = NULL;
        yol->sag = NULL;
        yol->ust = NULL;
        yol->deger = *(labirent+giris);
       // printf("baktigi yer %d\n",*(labirent+giris));
        if(yol->deger == 2){
        //    printf("deger 2 \n");
            return yol->deger;
        }
        else if(yol->deger != 1){
          //  printf("deger 1 degil\n");
            return yol->deger;
        }
        *(labirent+giris) = 2;
       // printf("yeni yol olustu\n");
    }
    //ilk sira
    if(giris<boyut && giris!=cikis){
       if(giris!=(boyut-1)){
         // printf("ilk sira saga dondu\n");
          a = giris+1;
       //   printf("ilk sira yeni giris (sag) %d\n",a);
          kontrol = yol_bulma(labirent,a,cikis,boyut,yol->sag);
       }
       if(kontrol==0 || giris!=cikis){
        b = (giris+boyut);
       // printf("ilk sira assagi \nilk sira yeni giris (assagi) %d\n",b);
        kontrol = yol_bulma(labirent,b,cikis,boyut,yol->alt);
        if(kontrol == 0 || giris!=cikis){
            if(giris != 0){
                c = giris-1;
           //     printf("ilk sira sol \nilk sira yeni giris (sol) %d\n",c);
                *(labirent+giris)=0;
                kontrol = yol_bulma(labirent,c,cikis,boyut,yol->sol);
            }
         }
        }
    }
    //ortalarda gezerken
    else if(giris != cikis && giris<((boyut-1)*boyut)){
        if(((giris+1)%boyut)!= 0){
            a = giris+1;
           // printf("alt siralar sag\nyeni giris (sag) %d\n",a);
            kontrol = yol_bulma(labirent,a,cikis,boyut,yol->sag);
        }
        if(kontrol == 0 || giris != cikis){
            b = giris+boyut;
          //  printf("alt siralar assagi\nyeni giris (assagi) %d\n",b);
            kontrol = yol_bulma(labirent,b,cikis,boyut,yol->alt);
            }
        if(kontrol == 0 || giris != cikis){
            if(((giris+1)%boyut)!=1){
                c = giris-1;
             //   printf("alt siralar sol\nyeni giris (sol) %d\n",c);
                kontrol = yol_bulma(labirent,c,cikis,boyut,yol->sol);
            }
        }
        if(kontrol == 0 || giris != cikis){
            d = giris-boyut;
           // printf("alt siralar ust\nyeni giris (ust) %d\n",d);
            kontrol = yol_bulma(labirent,d,cikis,boyut,yol->ust);
            *(labirent+giris)=0;
        }
    }
    //en alt sira
    else if(giris>((boyut-1)*boyut) && giris != cikis){
        if((giris+1)%boyut!= 0){
           // printf("en alt siralar sag\nyeni giris (sag) %d\n",(giris+1));
            a = giris+1;
            kontrol = yol_bulma(labirent,a,cikis,boyut,yol->sag);
        }
        if(kontrol == 0 || giris != cikis){
            if(((giris+1)%boyut)!=1){
           //     printf("en alt siralar sol\nyeni giris (sol) %d\n",(giris-1));
                c = giris-1;
                kontrol = yol_bulma(labirent,c,cikis,boyut,yol->sol);
            }
        }
        if(kontrol == 0 || giris != cikis){
           // printf("en alt siralar ust\nyeni giris (ust) %d\n",(giris-boyut));
            d = giris-boyut;
            kontrol = yol_bulma(labirent,d,cikis,boyut,yol->ust);
            *(labirent+giris)=0;
        }
    }



}



int main(){
    int boyut;
    printf("labirentin boyutunu giriniz: ");
    scanf("%d", &boyut);
    node *yol=NULL;
    int i,j,giris,cikis;
    int labirent[boyut][boyut];
        srand(time(NULL));
        for(i=0;i<boyut;i++){
            for(j=0;j<boyut;j++){
            labirent[i][j]=rand()%2;
            }
        }
    bastir(&labirent,boyut);
    printf("\ngirisi seciniz (1,4,12 gibi): ");
    scanf("%d",&giris);
    printf("cikisi seciniz: ");
    scanf("%d",&cikis);
    int kontrol = yol_bulma(&labirent,(giris-1),(cikis-1),boyut,yol);





    return 0;
}
