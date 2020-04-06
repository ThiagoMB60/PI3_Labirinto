#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

using namespace std;

struct matrizGame
{
    char caractere;
    int indice;
};
const int tm1 = 21, tm2 = 26, tm3 = 31, tm4 = 36, tm5 = 41, tmax = tm5;
const int cEspaco = 32, cXis = 88, cBoneco = 206, cBandeira = 220, cSaida = 178;
const int iEspaco = 0, iXis = 1, iBoneco = 2, iBandeira = 3, iSaida = 4;

int pI = 0, pJ = 0;

bool next = false;

void cabecalho(int tamanho);
void rodape(int tamanho);
void bandeira(matrizGame marMax[][tmax],int tamanho);
void printMatriz(matrizGame mtx[][tmax], int tamanho);

void tela5(matrizGame mtx[][tmax], int pI, int pJ);
void tela4(matrizGame mtx[][tmax], int pI, int pJ);
void tela3(matrizGame mtx[][tmax], int pI, int pJ);
void tela2(matrizGame mtx[][tmax], int pI, int pJ);
void tela1(matrizGame mtx[][tmax], int pI, int pJ);
void tuto1(matrizGame mtx[][tmax], int pI, int pJ);

void alteraPosicao(bool subir,bool descer, bool direita, bool esquerda, matrizGame mtx[][tmax]);
void selectMatriz(matrizGame mtx[tmax][tmax], int matriz, int pI, int pJ);
void selectMovimento(matrizGame mtx[tmax][tmax], int matriz);
void movimento(matrizGame mtx[][tmax], int nMatriz);
void roteiro(matrizGame mtx[][tmax]);

int main()
{
    /*keybd_event(VK_MENU,0x36,0,0);
    keybd_event(VK_RETURN,0x1C,0,0);
    keybd_event(VK_RETURN,0x1C,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);*/
    matrizGame mtx[tmax][tmax];

    /*cout << "\n\n\n\t\tBem vindo ao Game do Labirinto.\n\n";
    system("pause");
    system("cls");
    cout << "\n\n\t\tVoce ira aprender como caminhar pelo nosso labirinto.\n\n";
    cout << "Voce deve usar as teclas W;A;S e D \npara se locomover respectivmente para cima,\nesquerda, baixo e direita.\n\n";
    cout << "Seu objetivo sera digitar uma sequencia de \nteclas que ajude o boneco a chegar ao centro do Labirinto.\n\n";
    cout << "Voce deve lembrar o boneco se locomove \nde ponto a ponto, so basta 1 comando \npara que ele chegue ate o proximo ponto.\nApos terminar de digitar a sequencia\nde movimentos desejada aperte enter para prosseguir.\n\n";
    system("pause");
    system("cls");*/

    roteiro(mtx);







}

void cabecalho(int tamanho)
{
    cout << "\n\n\n\t\t      ";
    for (int i = 0 ; i < tamanho; i++)
    {
        cout << i;
        if ( i< 10)
            cout  << " ";
    }
    cout << "\n";
}

void rodape(int tamanho)
{
    cout << "\n\n\t\t      ";
    for (int i = 0 ; i < tamanho; i++)
    {
        cout << i;
        if ( i< 10)
            cout  << " ";
    }
}

void bandeira(matrizGame mtx[][tmax], int tamanho)
{
    for(int linha = 0; linha < tamanho; linha++)
    {
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            if ((mtx[linha][coluna].indice == iEspaco) && ((mtx[linha][coluna+1].indice == iEspaco &&
                    (mtx[linha-1][coluna].indice == iEspaco || mtx[linha+1][coluna].indice == iEspaco)) ||
                    (mtx[linha][coluna-1].indice == iEspaco && (mtx[linha-1][coluna].indice == iEspaco ||
                            mtx[linha+1][coluna].indice == iEspaco))))
            {
                mtx[linha][coluna].caractere = cBandeira;
                mtx[linha][coluna].indice = iBandeira;
            }
        }
    }
}

void printMatriz(matrizGame mtx[][tmax], int tamanho)
{
    cabecalho(tamanho);
    for(int linha = 0; linha < tamanho; linha++)
    {

        cout << "\n\t\t  " << linha<< " _";
        if (linha < 10)
            cout << " ";
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            cout << mtx[linha][coluna].caractere;
            cout << " ";
        }
        cout << "_" << linha;
    }
    rodape(tamanho);
}

void alteraPosicao(bool subir,bool descer, bool direita, bool esquerda, matrizGame mtx[][tmax])
{
    if(subir == true)
    {
        while((mtx[pI][pJ].indice != iBandeira) && (mtx[pI][pJ].indice != iSaida)){
            if((mtx[pI-1][pJ].indice == iXis)){
                break;
            }
            pI--;
        }
    }
    else if(descer == true)
    {
        while((mtx[pI][pJ].indice != iBandeira) && (mtx[pI][pJ].indice != iSaida)){
            if((mtx[pI+1][pJ].indice == iXis)){
                break;
            }
            pI++;
        }
    }
    else if(direita == true)
    {
        while((mtx[pI][pJ].indice != iBandeira) && (mtx[pI][pJ].indice != iSaida)){
            if((mtx[pI][pJ+1].indice == iXis)){
                break;
            }
            pJ++;
        }
    }
    else if(esquerda == true)
    {
        while((mtx[pI][pJ].indice != iBandeira) && (mtx[pI][pJ].indice != iSaida)){
            if((mtx[pI][pJ-1].indice == iXis)){
                break;
            }
            pJ--;
        }
    }
}

void tela5(matrizGame mtx[][tmax], int pI, int pJ)
{

    for(int linha = 0; linha < tm5; linha++)
    {
        for(int coluna = 0; coluna < tm5; coluna++)
        {
            //rota principal
            if ((coluna == 21 && linha > 21)||(coluna == 10 && linha > 20 && linha < 30)||
                    (coluna == 16 && linha > 30 && linha < 35)||(coluna == 5 && linha < 34 && linha > 14)||
                    (coluna == 28 && linha > 15 && linha < 38)||(coluna == 36 && linha < 38 && linha > 9)||
                    (coluna == 11 && linha < 10 && linha > 4)||(coluna == 21 && linha < 5) ||
                    (linha == 21 && coluna > 10 && coluna <= 21)||(linha == 30 && coluna >= 10 && coluna <= 16)||
                    (linha == 34 && coluna < 16 && coluna > 4)||(linha == 15 && coluna > 5 && coluna <29)||
                    (linha == 37 && coluna > 28 && coluna < 36)||(linha == 10 && coluna < 36 && coluna > 10)||
                    (linha == 5 && coluna > 11 && coluna < 22))
            {

                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }

            //rotas alternativas
            else if((coluna == 3 && linha < 4) || (coluna == 32 && linha < 4) || (coluna > 2 && coluna < 33 && linha == 3) ||
                    (coluna == 6 && linha < 8) || (coluna == 27 && linha < 8 && linha > 0 ) || (coluna > 5 && coluna < 28 && linha == 7) ||
                    (coluna == 8 && linha < 14 && linha > 8) || (coluna == 32 && linha < 14 && linha > 4) || (coluna == 36 && linha < 6 && linha > 1) ||
                    (linha == 13 && coluna > 8 && coluna < 32) || (linha == 5 && coluna > 32 && coluna < 36) || (coluna == 34 && linha < 25 && linha > 11) ||
                    (linha == 24 && coluna < 40 && coluna > 34 ) || (coluna == 39 && linha < 25 && linha > 0) || (linha == 8 && coluna < 40 && coluna > 33) ||
                    (coluna == 36 && linha == 9) || (coluna == 31 && linha < 30 && linha > 14) || (linha == 29 && coluna > 31 && coluna < 39) ||
                    (linha > 29 && coluna == 38 && linha < 40) || (linha == 39 && coluna > 22&& coluna < 38) || (coluna == 23 && linha < 39 && linha > 31) ||
                    (linha == 32 && coluna < 32 && coluna > 23)|| (coluna == 32 && linha < 36 && linha > 29)|| (coluna == 1 && linha < 10 && linha > 0)||
                    (coluna > 1 && linha == 9 && coluna < 8) || (coluna == 3 && linha < 37 && linha > 23) || (coluna < 21 && linha == 36 && coluna > 3) ||
                    (coluna == 19 && linha < 36 && linha > 28) || (linha == 29 && coluna > 19 && coluna < 27) || (coluna == 26 && linha < 29 && linha > 16) ||
                    (linha == 17 && coluna > 6 && coluna < 26) || (coluna == 7 && linha < 33 && linha > 17) || (linha == 32 && coluna > 6 && coluna < 14) ||
                    (linha == 39 && coluna > 0 && coluna < 21) || (linha == 21 && coluna > 0 && coluna < 4) || (coluna == 1 && linha < 39 && linha > 21) ||
                    (coluna == 3 && linha < 21 && linha > 10) || (linha == 27 && coluna > 11 && coluna < 20) || (linha == 19 && coluna > 11 && coluna < 25) ||
                    (linha == 23 && coluna > 14 && coluna < 25) || (coluna == 12 && linha < 27 && linha > 19) || (coluna == 24 && linha < 23 && linha > 19) )
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else
            {
                mtx[linha][coluna].caractere = cXis;
                mtx[linha][coluna].indice = iXis;
            }
        }
    }

    mtx[pI][pJ].caractere = cBoneco;
    mtx[pI][pJ].indice = iBoneco;
    mtx[0][21].caractere = cSaida; //saida
    mtx[0][21].indice = iSaida;      //saida
    bandeira(mtx,tm5);
}

void tela4(matrizGame mtx[][tmax], int pI, int pJ)
{
    for(int linha = 0; linha < tm4; linha++)
    {
        for(int coluna = 0; coluna < tm4; coluna++)
        {
            if (1==0)
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else if (1==0)
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else
            {
                mtx[linha][coluna].caractere = cXis;
                mtx[linha][coluna].indice = iXis;
            }
        }
    }
    mtx[pI][pJ].caractere = cBoneco;
    mtx[pI][pJ].indice = iBoneco;
    bandeira(mtx,tm4);
}

void tela3(matrizGame mtx[][tmax], int pI, int pJ)
{
    for(int linha = 0; linha < tm3; linha++)
    {
        for(int coluna = 0; coluna < tm3; coluna++)
        {
            if (1==0)
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else if (1==0)
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else
            {
                mtx[linha][coluna].caractere = cXis;
                mtx[linha][coluna].indice = iXis;
            }
        }
    }
    mtx[pI][pJ].caractere = cBoneco;
    mtx[pI][pJ].indice = iBoneco;
    bandeira(mtx,tm3);
}

void tela2(matrizGame mtx[][tmax], int pI, int pJ)
{
    for(int linha = 0; linha < tm2; linha++)
    {
        for(int coluna = 0; coluna < tm2; coluna++)
        {
            if (1==0)
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else if (1==0)
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else
            {
                mtx[linha][coluna].caractere = cXis;
                mtx[linha][coluna].indice = iXis;
            }
        }
    }
    mtx[pI][pJ].caractere = cBoneco;
    mtx[pI][pJ].indice = iBoneco;
    bandeira(mtx,tm2);
}

void tela1(matrizGame mtx[][tmax], int pI, int pJ)
{
    for(int linha = 0; linha < tm1; linha++)
    {
        for(int coluna = 0; coluna < tm1; coluna++)
        {
            if (1==0)
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else if (1==0)
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else
            {
                mtx[linha][coluna].caractere = cXis;
                mtx[linha][coluna].indice = iXis;
            }
        }
    }
    mtx[pI][pJ].caractere = cBoneco;
    mtx[pI][pJ].indice = iBoneco;
    bandeira(mtx,tm1);
}

void tuto1(matrizGame mtx[][tmax], int pI, int pJ)
{
    for(int linha = 0; linha < tm1; linha++)
    {
        for(int coluna = 0; coluna < tm1; coluna++)
        {
            if ((linha > 17 && coluna == 10) || (linha == 18 && coluna > 0 && coluna < 10) || (coluna == 1 && linha > 0 && linha < 18) ||
                (linha == 1 && coluna > 0 && coluna < 20) || (coluna == 19 && linha > 0 && linha < 15) || (linha == 14 && coluna < 19 && coluna > 4) ||
                (coluna == 5 && linha > 4 && linha < 14) || (linha == 5 && coluna > 5 && coluna < 16) || (coluna == 15 && linha > 5 && linha < 11) ||
                ( linha == 10 && coluna > 9 && coluna < 15))
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else
            {
                mtx[linha][coluna].caractere = cXis;
                mtx[linha][coluna].indice = iXis;
            }
        }
    }
    mtx[pI][pJ].caractere = cBoneco;
    mtx[pI][pJ].indice = iBoneco;
    if (mtx[10][10].indice != 2){
        mtx[10][10].caractere = cSaida; //saida
        mtx[10][10].indice = iSaida;      //saida
    }
    bandeira(mtx,tm1);
}

void selectMatriz(matrizGame mtx[][tmax], int matriz, int pI, int pJ)
{

    switch(matriz)
    {
    case 1:
        tela1(mtx, pI, pJ);
        printMatriz(mtx,tm1);
        break;
    case 2:
        tela2(mtx, pI, pJ);
        printMatriz(mtx,tm2);
        break;
    case 3:
        tela3(mtx, pI, pJ);
        printMatriz(mtx,tm3);
        break;
    case 4:
        tela4(mtx, pI, pJ);
        printMatriz(mtx,tm4);
        break;
    case 5:
        tela5(mtx, pI, pJ);
        printMatriz(mtx,tm5);
        break;
    case 6:
        tuto1(mtx, pI, pJ);
        printMatriz(mtx,tm1);

    }
    Sleep(500);
    if (mtx[10][10].indice == iBoneco)
    {
        next = true;
    }
}

void selectMovimento(matrizGame mtx[][tmax], int matriz)
{
    do
    {
        switch(matriz){
        case 1:
            movimento(mtx,1);
            break;
        case 2:
            movimento(mtx,2);
            break;
        case 3:
            movimento(mtx,3);
            break;
        case 4:
            movimento(mtx,4);
            break;
        case 5:
            movimento(mtx,5);
            break;
        case 6:
            movimento(mtx,6);
            break;
        }
        if (next){
            next = false;
            return;
        }
    }
    while(matriz != -1);
}

void movimento(matrizGame mtx[][tmax], int nMatriz)
{

    char direcao[40];

    cout << "\n\nPara qual direcao deseja ir? ";
    fflush(stdin);
    gets(direcao);

    for(int i = 0; i < strlen(direcao); i++)
    {
        if (direcao[i] == 119)      //para cima
        {
            system("CLS");
            alteraPosicao(1,0,0,0, mtx);
            selectMatriz(mtx, nMatriz,pI, pJ);
        }
        else if (direcao[i] == 100)  //para direita
        {
            system("CLS");
            alteraPosicao(0,0,1,0, mtx);
            selectMatriz(mtx, nMatriz,pI, pJ);
        }
        else if (direcao[i] == 115) //para baixo
        {
            system("CLS");
            alteraPosicao(0,1,0,0, mtx);
            selectMatriz(mtx, nMatriz,pI, pJ);
        }
        else if (direcao[i] == 97)   //para esqueda
        {
            system("CLS");
            alteraPosicao(0,0,0,1, mtx);
            selectMatriz(mtx, nMatriz,pI, pJ);
        }
        else
        {
            system("CLS");
            alteraPosicao(0,0,0,0, mtx);
            selectMatriz(mtx, nMatriz,pI, pJ);
        }
    }
}

void roteiro(matrizGame mtx[][tmax]){
    int matriz = 6;
    pI = 20;
    pJ = 10;
    selectMatriz(mtx, matriz, pI, pJ);
    selectMovimento(mtx, matriz);
    cout << "\n\n";
    system("pause");
    matriz = 1;
    pI = 20;
    pJ = 10;
    selectMatriz(mtx, matriz, pI, pJ);
    selectMovimento(mtx, matriz);
    cout << "\n\n";
    system("pause");
    matriz = 2;
    pI = 25;
    pJ = 15;
    selectMatriz(mtx, matriz, pI, pJ);
    selectMovimento(mtx, matriz);
    cout << "\n\n";
    system("pause");
    matriz = 3;
    pI = 30;
    pJ = 20;
    selectMatriz(mtx, matriz, pI, pJ);
    selectMovimento(mtx, matriz);
    cout << "\n\n";
    system("pause");
    matriz = 4;
    pI = 35;
    pJ = 25;
    selectMatriz(mtx, matriz, pI, pJ);
    selectMovimento(mtx, matriz);
    cout << "\n\n";
    system("pause");
    matriz = 5;
    pI = 40;
    pJ = 20;
    selectMatriz(mtx, matriz, pI, pJ);
    selectMovimento(mtx, matriz);
    cout << "\n\n";
    system("pause");
}
