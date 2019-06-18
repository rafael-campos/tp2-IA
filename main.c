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
    ImprimirMapa();
    // criando a posição do wumpus
    while(mapa[posicaox][posicaoy] != -1){
        posicaox = rand() % 4;
        posicaoy = rand() % 4;
    }
    mapa[posicaox][posicaoy] = 1;
    printf("\n");
    ImprimirMapa();
    //criando o ouro
    posicaox = 3;
    posicaoy = 0;
    while(posicaox == 3 && posicaoy == 0){
        posicaox = rand() % 4;
        posicaoy = rand() % 4;
    }
    mapa[posicaox][posicaoy] = 7;
    printf("\n");
    ImprimirMapa();
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
    ImprimirMapa();
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
                        mapa[i+1][j] = 10;
                    //tem jogador e brisa
                    }else if(mapa[i+1][j] == 9){
                        mapa[i+1][j] = 11;
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
                        mapa[i-1][j] = 10;
                    }else if(mapa[i-1][j] == 9){
                        mapa[i-1][j] = 11;
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
                        mapa[i][j+1] = 10;
                    }else if(mapa[i][j+1] == 9){
                        mapa[i][j+1] = 11;
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
                        mapa[i][j-1] = 10;
                    }else if(mapa[i][j-1] == 9){
                        mapa[i][j-1] = 11;
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
                        mapa[i+1][j] = 9;
                    }else if(mapa[i+1][j] == 10){
                        mapa[i+1][j] = 11;
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
                        mapa[i-1][j] = 9;
                    }else if(mapa[i-1][j] == 10){
                        mapa[i-1][j] = 11;
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
                        mapa[i][j+1] = 9;
                    }else if(mapa[i][j+1] == 10){
                        mapa[i][j+1] = 11;
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
                        mapa[i][j-1] = 9;
                    }else if(mapa[i][j-1] == 10){
                        mapa[i][j-1] = 11;
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
void andar(int posicaoxJogador,int posicaoyJogador){
    if(posicaoxJogador + 1 < 4){
        posicaoxJogador = posicaoxJogador + 1;
    }
    else if(posicaoxJogador - 1 >= 0){
        posicaoxJogador = posicaoxJogador - 1;
    }
    if(posicaoyJogador + 1 < 4 ){
        posicaoyJogador = posicaoyJogador + 1;
    }
    if(posicaoyJogador -1 >= 0){
        posicaoyJogador = posicaoyJogador - 1;
    }
}
void finalizar(){

}
void finalizou(int posicaoxJogador , int posicaoyJogador, int mapa_jogador[tam_mapa][tam_mapa]){
    printf("\n");
    if(mapa_jogador[posicaoxJogador][posicaoyJogador] == 1){
        printf("você foi morto pelo Wumpus \n");
        exit(0);
    }else if(mapa_jogador[posicaoxJogador][posicaoyJogador] == 2){
        printf("você caiu no poço \n");
        exit(0);
    }else if(mapa_jogador[posicaoxJogador][posicaoyJogador] == 7 || mapa_jogador[posicaoxJogador][posicaoyJogador] == 12 || mapa_jogador[posicaoxJogador][posicaoyJogador] == 13){
        printf("você achou o ouro \n");
        exit(0);
    }
}
void IA(int mapa_jogador[tam_mapa][tam_mapa]){
    int i,j;
    
}
void jogar(){
    int mapa_jogador[tam_mapa][tam_mapa];
    int posicaoxJogador = 3,posicaoyJogador = 0,acabar = 1;
    int posicaoxJogadoranterior,posicaoyJogadoranterior;
    Zerarmapa_jogador(mapa_jogador);
    mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
    while(acabar != 0){
        finalizou(posicaoxJogador,posicaoyJogador,mapa_jogador);
        ImprimirMapa_jogador(mapa_jogador);
        if(posicaoxJogador + 1 < 4){
            posicaoxJogadoranterior = posicaoxJogador;
            posicaoxJogador = posicaoxJogador + 1;
            mapa_jogador[posicaoxJogadoranterior][posicaoyJogador] = 8;
            mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
        }else if(posicaoxJogador - 1 >= 0){
            posicaoxJogadoranterior = posicaoxJogador;
            posicaoxJogador = posicaoxJogador - 1;
            mapa_jogador[posicaoxJogadoranterior][posicaoyJogador] = 8;
            mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
        }else if(posicaoyJogador + 1 < 4 ){
            posicaoyJogadoranterior = posicaoyJogador;
            posicaoyJogador = posicaoyJogador + 1;
            mapa_jogador[posicaoxJogador][posicaoyJogadoranterior] = 8;
            mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
        }else if(posicaoyJogador -1 >= 0){
            posicaoyJogadoranterior = posicaoyJogador;
            posicaoyJogador = posicaoyJogador - 1;
            mapa_jogador[posicaoxJogador][posicaoyJogadoranterior] = 8;
            mapa_jogador[posicaoxJogador][posicaoyJogador] = mapa[posicaoxJogador][posicaoyJogador];
        }
        printf("\n");
        printf ("%i %i \n",posicaoxJogador,posicaoyJogador);
        finalizou(posicaoxJogador,posicaoyJogador,mapa_jogador);
        ImprimirMapa_jogador(mapa_jogador);
        exit(0);
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