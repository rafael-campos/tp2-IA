#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam_mapa 4
int mapa[tam_mapa][tam_mapa];
void Zerarmapa(){
    int i,j;
    for (i=0;i<4;i++){
        for(j=0;j<4;j++){
            mapa[i][j] = -1;
        }
    }
}
void Zerarmapa_jogador(int mapa_jogador[tam_mapa][tam_mapa]){
    int i,j;
    for (i=0;i<4;i++){
        for(j=0;j<4;j++){
            mapa_jogador[i][j] = -1;
        }
    }
}
void ImprimirMapa(){
    int i,j;
     for (i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d \t",mapa[i][j]);
        }
        printf("\n");
    }
}
void ImprimirMapa_jogador(int mapa_jogador[tam_mapa][tam_mapa]){
    int i,j;
     for (i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d \t",mapa_jogador[i][j]);
        }
        printf("\n");
    }
}
void Gerarmapa(){
    int posicaox = 3 , posicaoy = 0;
    mapa[3][0] = 0;
    //ImprimirMapa();
    // criando a posição do wumpus
    while(mapa[posicaox][posicaoy] != -1){
        posicaox = rand() % 4;
        posicaoy = rand() % 4;
    }
    mapa[posicaox][posicaoy] = 1;
    printf("\n");
    //ImprimirMapa();
    //criando o ouro
    posicaox = 3;
    posicaoy = 0;
    while(posicaox == 3 && posicaoy == 0){
        posicaox = rand() % 4;
        posicaoy = rand() % 4;
    }
    mapa[posicaox][posicaoy] = 7;
    printf("\n");
    //ImprimirMapa();
    // criando os poços
    int quantpocos,i,j;
    quantpocos = 1 + rand() % 3;
    printf("%d \n",quantpocos);
    for(i = 0 ;i < quantpocos ; i++){
        while(mapa[posicaox][posicaoy] != -1){
            posicaox = rand() % 4;
            posicaoy = rand() % 4;
        }
        mapa[posicaox][posicaoy] = 2;
    }
    printf("\n");
    //ImprimirMapa();
    //gerando brisa e fedo
    for(i=0;i<tam_mapa;i++){
        for(j=0;j<tam_mapa;j++){
            if(mapa[i][j] == 1){
                if(i + 1 < 4){
                    // nao tem nada
                    if(mapa[i+1][j] == -1){
                        mapa[i+1][j] = 3;
                    // tem brisa
                    }else if(mapa[i+1][j] == 4){
                        mapa[i+1][j] = 5;
                    //tem jogador
                    }else if(mapa[i+1][j] == 0){
                        mapa[i+1][j] = 3;
                    //tem jogador e brisa
                    }else if(mapa[i+1][j] == 9){
                        mapa[i+1][j] = 5;
                    //tem ouro
                    }else if(mapa[i+1][j] == 7){
                        mapa[i+1][j] = 13;
                    //tem ouro e brisa
                    }else if(mapa[i+1][j] == 12){
                        mapa[i+1][j] = 14;
                    }
                }
                if(i - 1 >= 0){
                    if(mapa[i-1][j] == -1){
                        mapa[i-1][j] = 3;
                    }else if(mapa[i-1][j] == 4){
                        mapa[i-1][j] = 5;
                    }else if(mapa[i-1][j] == 0){
                        mapa[i-1][j] = 3;
                    }else if(mapa[i-1][j] == 9){
                        mapa[i-1][j] = 5;
                    }else if(mapa[i-1][j] == 7){
                        mapa[i-1][j] = 13;
                    }else if(mapa[i-1][j] == 12){
                        mapa[i-1][j] = 14;
                    }
                }
                if(j + 1 < 4){
                    if(mapa[i][j+1] == -1){
                        mapa[i][j+1] = 3;
                    }else if(mapa[i][j+1] == 4){
                        mapa[i][j+1] = 5;
                    }else if(mapa[i][j+1] == 0){
                        mapa[i][j+1] = 3;
                    }else if(mapa[i][j+1] == 9){
                        mapa[i][j+1] = 5;
                    }else if(mapa[i][j+1] == 7){
                        mapa[i][j+1] = 13;
                    }else if(mapa[i][j+1] == 12){
                        mapa[i][j+1] = 14;
                    }
                }
                if(j - 1 >= 0){
                    if(mapa[i][j-1] == -1){
                        mapa[i][j-1] = 3;
                    }else if(mapa[i][j-1] == 4){
                        mapa[i][j-1] = 5;
                    }else if(mapa[i][j-1] == 0){
                        mapa[i][j-1] = 3;
                    }else if(mapa[i][j-1] == 9){
                        mapa[i][j-1] = 5;
                    }else if(mapa[i][j-1] == 7){
                        mapa[i][j-1] = 13;
                    }else if(mapa[i][j-1] == 12){
                        mapa[i][j-1] = 14;
                    }
                }
            }
            else if(mapa[i][j] == 2){
                if(i + 1 < 4){
                    if(mapa[i+1][j] == -1){
                        mapa[i+1][j] = 4;
                    }else if(mapa[i+1][j] == 3){
                        mapa[i+1][j] = 5;
                    }else if(mapa[i+1][j] == 0){
                        mapa[i+1][j] = 4;
                    }else if(mapa[i+1][j] == 10){
                        mapa[i+1][j] = 5;
                    }else if(mapa[i+1][j] == 7){
                        mapa[i+1][j] = 12;
                    }else if(mapa[i+1][j] == 13){
                        mapa[i+1][j] = 14;
                    }
                }
                if(i - 1 >= 0){
                    if(mapa[i-1][j] == -1){
                        mapa[i-1][j] = 4;
                    }else if(mapa[i-1][j] == 3){
                        mapa[i-1][j] = 5;
                    }else if(mapa[i-1][j] == 0){
                        mapa[i-1][j] = 4;
                    }else if(mapa[i-1][j] == 10){
                        mapa[i-1][j] = 5;
                    }else if(mapa[i-1][j] == 7){
                        mapa[i-1][j] = 12;
                    }else if(mapa[i-1][j] == 13){
                        mapa[i-1][j] = 14;
                    }
                }
                if(j + 1 < 4){
                    if(mapa[i][j+1] == -1){
                        mapa[i][j+1] = 4;
                    }else if(mapa[i][j+1] == 3){
                        mapa[i][j+1] = 5;
                    }else if(mapa[i][j+1] == 0){
                        mapa[i][j+1] = 4;
                    }else if(mapa[i][j+1] == 10){
                        mapa[i][j+1] = 5;
                    }else if(mapa[i][j+1] == 7){
                        mapa[i][j+1] = 12;
                    }else if(mapa[i][j+1] == 13){
                        mapa[i][j+1] = 14;
                    }
                }
                if(j - 1 >= 0){
                    if(mapa[i][j-1] == -1){
                        mapa[i][j-1] = 4;
                    }else if(mapa[i][j-1] == 3){
                        mapa[i][j-1] = 5;
                    }else if(mapa[i][j-1] == 0){
                        mapa[i][j-1] = 4;
                    }else if(mapa[i][j-1] == 10){
                        mapa[i][j-1] = 5;
                    }else if(mapa[i][j-1] == 7){
                        mapa[i][j-1] = 12;
                    }else if(mapa[i][j-1] == 13){
                        mapa[i][j-1] = 14;
                    }
                }
            }
        }
    }
    printf("\n");
    ImprimirMapa();

}

void finalizar(){

}
void finalizou(int posicaoxJogador , int posicaoyJogador, int mapa_jogador[tam_mapa][tam_mapa]){
    printf("\n");
    if(mapa_jogador[posicaoxJogador][posicaoyJogador] == 1){
        ImprimirMapa_jogador(mapa_jogador);
        printf("\n \n");
        ImprimirMapa();
        printf("você foi morto pelo Wumpus \n");
        exit(0);
    }else if(mapa_jogador[posicaoxJogador][posicaoyJogador] == 2){
        ImprimirMapa_jogador(mapa_jogador);
        printf("\n \n");
        ImprimirMapa();
        printf("você caiu no poço \n");
        exit(0);
    }else if(mapa_jogador[posicaoxJogador][posicaoyJogador] == 7 || mapa_jogador[posicaoxJogador][posicaoyJogador] == 12 || mapa_jogador[posicaoxJogador][posicaoyJogador] == 13){
        ImprimirMapa_jogador(mapa_jogador);
        printf("\n \n");
        ImprimirMapa();
        printf("você achou o ouro \n");
        exit(0);
    }
}
void IA(int mapa_jogador[tam_mapa][tam_mapa],int posicaoxJogador,int posicaoyJogador){
    int i,j;
    printf("%i  %i \n",posicaoxJogador,posicaoyJogador);
    if(mapa_jogador[posicaoxJogador][posicaoyJogador] == 4){
        if(posicaoxJogador + 1 < 4){
            printf("entrou aki \n");   
            if(mapa_jogador[posicaoxJogador +1][posicaoyJogador] == -1){
                printf("entrou aki \n");    
                mapa_jogador[posicaoxJogador + 1][posicaoyJogador] = 16;
            }else if(mapa_jogador[posicaoxJogador +1][posicaoyJogador] == 16){
                mapa_jogador[posicaoxJogador + 1][posicaoyJogador] = 2;
            }else if(mapa_jogador[posicaoxJogador +1][posicaoyJogador] == 17){
                mapa_jogador[posicaoxJogador + 1][posicaoyJogador] = 16;
            }
        }
        if(posicaoxJogador - 1 >= 0){
            printf("entrou aki \n");   
            if(mapa_jogador[posicaoxJogador  - 1][posicaoyJogador] == -1){
                mapa_jogador[posicaoxJogador - 1][posicaoyJogador] = 16;
            }else if(mapa_jogador[posicaoxJogador - 1][posicaoyJogador] == 16){
                mapa_jogador[posicaoxJogador - 1][posicaoyJogador] = 2;
            }else if(mapa_jogador[posicaoxJogador - 1][posicaoyJogador] == 17){
                mapa_jogador[posicaoxJogador - 1][posicaoyJogador] = 16;
            }
        }
        if(posicaoyJogador + 1 < 4 ){
            printf("entrou aki \n");   
            if(mapa_jogador[posicaoxJogador ][posicaoyJogador + 1] == -1){
                mapa_jogador[posicaoxJogador][posicaoyJogador + 1] = 16;
            }else if(mapa_jogador[posicaoxJogador][posicaoyJogador + 1] == 16){
                mapa_jogador[posicaoxJogador][posicaoyJogador + 1] = 2;
            }else if(mapa_jogador[posicaoxJogador][posicaoyJogador + 1] == 17){
                mapa_jogador[posicaoxJogador ][posicaoyJogador + 1] = 16;
            }
        }
        if(posicaoyJogador -1 >= 0){
            printf("entrou aki \n");   
            if(mapa_jogador[posicaoxJogador ][posicaoyJogador - 1] == -1){
                mapa_jogador[posicaoxJogador ][posicaoyJogador -1] = 16;
            }else if(mapa_jogador[posicaoxJogador][posicaoyJogador - 1] == 16){
                mapa_jogador[posicaoxJogador ][posicaoyJogador -1 ] = 2;
            }else if(mapa_jogador[posicaoxJogador][posicaoyJogador - 1] == 17){
                mapa_jogador[posicaoxJogador ][posicaoyJogador - 1] = 16;
            }
        }
    
    }else if(mapa_jogador[posicaoxJogador][posicaoyJogador] == 3){
        if(posicaoxJogador + 1 < 4){
            printf("entrou aki x + 1\n"); 
            if(mapa_jogador[posicaoxJogador +1][posicaoyJogador] == -1){
                printf("entrou aki -1 \n"); 
                mapa_jogador[posicaoxJogador + 1][posicaoyJogador] = 15;
            }else if(mapa_jogador[posicaoxJogador +1][posicaoyJogador] == 15){
                printf("entrou aki 15 \n");
                mapa_jogador[posicaoxJogador + 1][posicaoyJogador] = 1;
                int i,j;
                for(i = 0;i<tam_mapa;i++){
                    for(j=0;j<tam_mapa;j++){
                        if(mapa_jogador[i][j] == 15){
                            printf("entrou aki tirar 15");
                            mapa_jogador[i][j] = -1;
                        }
                    }
                }
            }else if(mapa_jogador[posicaoxJogador +1][posicaoyJogador] == 17){
                printf("entrou aki 17 \n");
                mapa_jogador[posicaoxJogador + 1][posicaoyJogador] = 15;
            }
        }
        if(posicaoxJogador - 1 >= 0){
            printf("entrou aki x-1\n"); 
            if(mapa_jogador[posicaoxJogador  - 1][posicaoyJogador] == -1){
                printf("entrou aki -1 \n");
                mapa_jogador[posicaoxJogador - 1][posicaoyJogador] = 15;
            }else if(mapa_jogador[posicaoxJogador - 1][posicaoyJogador] == 15){
                printf("entrou aki 15 \n");
                mapa_jogador[posicaoxJogador - 1][posicaoyJogador] = 1;
            }else if(mapa_jogador[posicaoxJogador - 1][posicaoyJogador] == 17){
                printf("entrou aki 17 \n");
                mapa_jogador[posicaoxJogador - 1][posicaoyJogador] = 15;
            }
        }
        if(posicaoyJogador + 1 < 4 ){
            printf("entrou aki y+1 \n"); 
            if(mapa_jogador[posicaoxJogador ][posicaoyJogador + 1] == -1){
                printf("entrou aki -1 \n");
                mapa_jogador[posicaoxJogador][posicaoyJogador + 1] = 15;
            }else if(mapa_jogador[posicaoxJogador][posicaoyJogador + 1] == 15){
                printf("entrou aki 15 \n");
                mapa_jogador[posicaoxJogador ][posicaoyJogador + 1] = 1;
            }else if(mapa_jogador[posicaoxJogador][posicaoyJogador + 1] == 17){
                printf("entrou aki 17 \n");
                mapa_jogador[posicaoxJogador][posicaoyJogador + 1] = 15;
            }
        }
        if(posicaoyJogador -1 >= 0){
            printf("entrou aki y-1\n"); 
            if(mapa_jogador[posicaoxJogador ][posicaoyJogador - 1] == -1){
                printf("entrou aki -1 \n");
                mapa_jogador[posicaoxJogador ][posicaoyJogador -1] = 15;
            }else if(mapa_jogador[posicaoxJogador][posicaoyJogador - 1] == 15){
                printf("entrou aki 15 \n");
                mapa_jogador[posicaoxJogador ][posicaoyJogador -1 ] = 1;
            }else if(mapa_jogador[posicaoxJogador][posicaoyJogador - 1] == 17){
                printf("entrou aki 17 \n");
                mapa_jogador[posicaoxJogador ][posicaoyJogador - 1] = 15;
            }
        }
    }else if(mapa_jogador[posicaoxJogador][posicaoyJogador] == 5){
        if(posicaoxJogador + 1 < 4){
            printf("entrou aki x + 1\n"); 
            if(mapa_jogador[posicaoxJogador +1][posicaoyJogador] == -1){
                printf("entrou aki -1 \n"); 
                mapa_jogador[posicaoxJogador + 1][posicaoyJogador] = 17;
            }
        }
        if(posicaoxJogador - 1 >= 0){
            printf("entrou aki x-1\n"); 
            if(mapa_jogador[posicaoxJogador  - 1][posicaoyJogador] == -1){
                printf("entrou aki -1 \n");
                mapa_jogador[posicaoxJogador - 1][posicaoyJogador] = 17;
            }
        }
        if(posicaoyJogador + 1 < 4 ){
            printf("entrou aki y+1 \n"); 
            if(mapa_jogador[posicaoxJogador ][posicaoyJogador + 1] == -1){
                printf("entrou aki -1 \n");
                mapa_jogador[posicaoxJogador][posicaoyJogador + 1] = 17;
            }
        }
        if(posicaoyJogador -1 >= 0){
            printf("entrou aki y-1\n"); 
            if(mapa_jogador[posicaoxJogador ][posicaoyJogador - 1] == -1){
                printf("entrou aki -1 \n");
                mapa_jogador[posicaoxJogador ][posicaoyJogador -1] = 17;
            }
        }
    }
    
}
void jogar(){
    int mapa_jogador[tam_mapa][tam_mapa];
    int posicaoxJogadoranterior[100];
    int posicaoyJogadoranterior[100];
    int posicaoxJogador = 3,posicaoyJogador = 0,acabar = 1;
    posicaoxJogadoranterior[0] = 3;
    posicaoyJogadoranterior[0] = 0;
    Zerarmapa_jogador(mapa_jogador);
    mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
    int aux = 0;
    while(acabar != 0){
        finalizou(posicaoxJogador,posicaoyJogador,mapa_jogador);
        IA(mapa_jogador,posicaoxJogador,posicaoyJogador);
       if(posicaoxJogador + 1 < 4 && mapa_jogador[posicaoxJogador + 1][posicaoyJogador] == -1){
            posicaoxJogadoranterior[aux] = posicaoxJogador;
            posicaoxJogador = posicaoxJogador + 1;
            if(mapa_jogador[posicaoxJogadoranterior[aux]][posicaoyJogador] == -1){
            mapa_jogador[posicaoxJogadoranterior[aux]][posicaoyJogador] = 8;
            }
            mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
            aux++;
        }else if(posicaoxJogador - 1 >= 0  && mapa_jogador[posicaoxJogador - 1][posicaoyJogador] == -1){
            posicaoxJogadoranterior[aux] = posicaoxJogador;
            posicaoxJogador = posicaoxJogador - 1;
            if(mapa_jogador[posicaoxJogadoranterior[aux]][posicaoyJogador] == -1){
            mapa_jogador[posicaoxJogadoranterior[aux]][posicaoyJogador] = 8;
            }
            aux++;
            mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
        }else if(posicaoyJogador + 1 < 4  && mapa_jogador[posicaoxJogador][posicaoyJogador + 1] == -1){
            posicaoyJogadoranterior[aux] = posicaoyJogador;
            posicaoyJogador = posicaoyJogador + 1;
            if(mapa_jogador[posicaoxJogador][posicaoyJogadoranterior[aux]] == -1){
            mapa_jogador[posicaoxJogador][posicaoyJogadoranterior[aux]] = 8;
            }
            aux++;
            mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
        }else if(posicaoyJogador -1 >= 0  && mapa_jogador[posicaoxJogador + 1][posicaoyJogador - 1] == -1   ){
            posicaoyJogadoranterior[aux] = posicaoyJogador;
            posicaoyJogador = posicaoyJogador - 1;
            if(mapa_jogador[posicaoxJogador][posicaoyJogadoranterior[aux]] == -1){
            mapa_jogador[posicaoxJogador][posicaoyJogadoranterior[aux]] = 8;
            }
            aux++;
            mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
        }else if(posicaoxJogador = posicaoxJogadoranterior[aux -1 ] && posicaoyJogador == posicaoyJogadoranterior[aux - 1]){
            posicaoxJogador = posicaoxJogadoranterior[aux - 1];
            posicaoyJogador = posicaoyJogadoranterior[aux - 1];
            if(posicaoxJogador + 1 < 4 && mapa_jogador[posicaoxJogador + 1][posicaoyJogador] == -1){
                posicaoxJogadoranterior[aux] = posicaoxJogador;
                posicaoxJogador = posicaoxJogador + 1;
                if(mapa_jogador[posicaoxJogadoranterior[aux]][posicaoyJogador] == -1){
                    mapa_jogador[posicaoxJogadoranterior[aux]][posicaoyJogador] = 8;
                }
                mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
            }else if(posicaoxJogador - 1 >= 0  && mapa_jogador[posicaoxJogador - 1][posicaoyJogador] == -1){
                posicaoxJogadoranterior[aux] = posicaoxJogador;
                posicaoxJogador = posicaoxJogador - 1;
                if(mapa_jogador[posicaoxJogadoranterior[aux]][posicaoyJogador] == -1){
                    mapa_jogador[posicaoxJogadoranterior[aux]][posicaoyJogador] = 8;
                }
                mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
            }else if(posicaoyJogador + 1 < 4  && mapa_jogador[posicaoxJogador][posicaoyJogador + 1] == -1){
                posicaoyJogadoranterior[aux] = posicaoyJogador;
                posicaoyJogador = posicaoyJogador + 1;
                if(mapa_jogador[posicaoxJogador][posicaoyJogadoranterior[aux]] == -1){
                    mapa_jogador[posicaoxJogador][posicaoyJogadoranterior[aux]] = 8;
                }
            mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
            }else if(posicaoyJogador -1 >= 0  && mapa_jogador[posicaoxJogador + 1][posicaoyJogador - 1] == -1   ){
                posicaoyJogadoranterior[aux] = posicaoyJogador;
                posicaoyJogador = posicaoyJogador - 1;
                if(mapa_jogador[posicaoxJogador][posicaoyJogadoranterior[aux]] == -1){
                    mapa_jogador[posicaoxJogador][posicaoyJogadoranterior[aux]] = 8;
                }
                mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
            }
        }
        printf("\n");
        printf ("%i %i \n",posicaoxJogador,posicaoyJogador);
        finalizou(posicaoxJogador,posicaoyJogador,mapa_jogador);
        IA(mapa_jogador,posicaoxJogador,posicaoyJogador);
        ImprimirMapa_jogador(mapa_jogador);
    
    }
}
/*valores :
jogador = 0 
wumpus = 1
poço = 2
fedo = 3
brisa = 4
fedo e brisa = 5
ouro = 7
visitado = 8
jogador e brisa = 9
jogador e fedor = 10
jogador ,brisa e fedor = 11
ouro e brisa = 12
ouro e fedor = 13
ouro ,brisa e fedor = 14
possivel wumpus = 15
possivel poço = 16
possivel poço e wumpus = 17
*/
int main(int argc,char **argv){
    srand( (unsigned)time(NULL) );
    int mapa[tam_mapa][tam_mapa];
    Zerarmapa();
    ImprimirMapa();
    Gerarmapa();
    jogar();
}