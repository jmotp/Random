#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
int ano;

int bis();
int main()
{
    scanf("%d",&ano);
    //printf("%d",dia_semana(dia,mes,ano));
    int x;
    for(x=1;x<=12;x++){
        calendario(x);
    }

    return 0;
}
int bis(int ano){
    if(ano%4==0&&(ano%100!=0||ano%400==0)){return 1;}{return 0;}
}
int n_dias(int mes,int ano){
    int ndias;
    switch (mes){
    case 1:ndias=31;break;
    case 2:if(bis(ano)==1){ndias=29;}else{ndias=28;};break;
    case 3:ndias=31;break;
    case 4:ndias=30;break;
    case 5:ndias=31;break;
    case 6:ndias=30;break;
    case 7:ndias=31;break;
    case 8:ndias=31;break;
    case 9:ndias=30;break;
    case 10:ndias=31;break;
    case 11:ndias=30;break;
    case 12:ndias=31;break;

    }
    return ndias;
}
int dia_semana(int dia, int mes, int ano){
    int c[2][12]={{0,3,3,6,1,4,6,2,5,0,3,5},{6,2,3,6,1,4,6,2,5,0,3,5}};
    int ds=((5*(ano%100)/4)+c[bis(ano)][mes-1]+dia-(2*((ano/100)%4)+7))%7;
    if(ds==0){ds=6;}else{ds=ds-1;}
    return ds;
}
void calendario(int mes){
    switch (mes){
    case 1:printf("Janeiro");break;
    case 2:printf("Fevereiro");break;
    case 3:printf("Marco");break;
    case 4:printf("Abril");break;
    case 5:printf("Maio");break;
    case 6:printf("Junho");break;
    case 7:printf("Julho");break;
    case 8:printf("Agosto");break;
    case 9:printf("Setembro");break;
    case 10:printf("Outubro");break;
    case 11:printf("Novembro");break;
    case 12:printf("Dezembro");break;
    }
    printf("/%d\n",ano);
    printf("Dom Seg Ter Qua Qui Sex Sab\n");
    int i,j;
    for(i=1; i<= n_dias(mes,ano)+dia_semana(1, mes, ano); i++){
        if(i==1&&dia_semana(1,mes,ano)!=0){
            for (j=1;j<=dia_semana(1,mes,ano);j++){
                printf("    ");
            }

        }
        if(i-dia_semana(1,mes,ano)>0){
            if(i-dia_semana(1,mes,ano)<10){
                printf("  %d ",i-dia_semana(1,mes,ano));
            }else{
            printf(" %d ",i-dia_semana(1,mes,ano));
            }
        }
        if(i%7==0){printf("\n");}

    }
    printf("\n");
}
