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
const int tm1 = 21, tm2 = 26, tm3 = 31, tm4 = 36, tm5 = 41, tmax = tm5; //tamanho da matriz
const int cEspaco = 32, cParede = 157, cBoneco = 206, cBandeira = 220, cSaida = 178, cPeca = 88	; //numero referente a tabela ascii referente ao struct
const int iEspaco = 0, iXis = 1, iBoneco = 2, iBandeira = 3, iSaida = 4, iPeca = 5; //indici do struct

int contLibera = 0;//contador responsabel por liberar o lab 5
int contLocal2 = 0;//contador responsavel pelo lab 2

int matriz;
int pI = 0, pJ = 0; //PI=linha e PJ=coluna

bool nextMatriz = false; // Passa para proxima fase
bool iniciarJogo();

void cabecalho(int tamanho); // responsavel por dar espaço e escrever os numero  do lado da matriz
void rodape(int tamanho); //escrever os numero  do lado da matriz
void bandeira(matrizGame marMax[][tmax],int tamanho);  //print bandeira
void printMatriz(matrizGame mtx[][tmax], int tamanho);  //printa matriz

// manipulacao de dados das matrizes
void tela5(matrizGame mtx[][tmax], int pI, int pJ);
void tela4(matrizGame mtx[][tmax], int pI, int pJ);
void tela3(matrizGame mtx[][tmax], int pI, int pJ);
void tela2(matrizGame mtx[][tmax], int pI, int pJ);
void tela1(matrizGame mtx[][tmax], int pI, int pJ);
void tuto1(matrizGame mtx[][tmax], int pI, int pJ);

void alteraPosicao(bool subir,bool descer, bool direita, bool esquerda, matrizGame mtx[][tmax]);//testar posiçoes e fazer movimento
void selectMatriz(matrizGame mtx[tmax][tmax], int matriz, int pI, int pJ); //seleciona a matriz
void selectMovimento(matrizGame mtx[tmax][tmax], int matriz); //chamada dentro do roteiro
void movimento(matrizGame mtx[][tmax], int nMatriz);
void roteiro(matrizGame mtx[][tmax]);
bool testeSaida(matrizGame mtx [][tmax], int matriz);
void ajudaTutorial();
void roteiroTuto(matrizGame mtx[][tmax]);
void ajuda(matrizGame mtx[][tmax], int pI, int pJ);
void ajudafixa();

void reiniciaMatriz(matrizGame mtx[][tmax], int nMatriz, int pI, int pJ);

int main()
{
    /*keybd_event(VK_MENU,0x36,0,0);
    keybd_event(VK_RETURN,0x1C,0,0);
    keybd_event(VK_RETURN,0x1C,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);*/
    iniciarJogo();
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
            //testa as posiicoes se tem caminhos alternativos
            if ((mtx[linha][coluna].indice == iEspaco) && ((mtx[linha][coluna+1].indice == iEspaco &&
                    (mtx[linha-1][coluna].indice == iEspaco || mtx[linha+1][coluna].indice == iEspaco)) ||
                    (mtx[linha][coluna-1].indice == iEspaco && (mtx[linha-1][coluna].indice == iEspaco ||
                            mtx[linha+1][coluna].indice == iEspaco))))
            {
                mtx[linha][coluna].caractere = cBandeira;//caracter recebe o numero relacionado ao bandeira declarado
                mtx[linha][coluna].indice = iBandeira;//indice recebe o iBandeira  declarados no cabecalho para testes internos
            }

        }
    }
}

void printMatriz(matrizGame mtx[][tmax], int tamanho) //printa a matriz
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
        while((mtx[pI][pJ].indice != iBandeira) && (mtx[pI][pJ].indice != iSaida))
        {
            if((mtx[pI-1][pJ].indice == iXis))
            {
                break;
            }
            pI--;
        }
    }
    else if(descer == true)
    {
        while((mtx[pI][pJ].indice != iBandeira) && (mtx[pI][pJ].indice != iSaida))
        {
            if((mtx[pI+1][pJ].indice == iXis))
            {
                break;
            }
            pI++;
        }
    }
    else if(direita == true)
    {
        while((mtx[pI][pJ].indice != iBandeira) && (mtx[pI][pJ].indice != iSaida))
        {

            if((mtx[pI][pJ+1].indice == iXis))
            {
                break;
            }
            pJ++;
        }
    }
    else if(esquerda == true)
    {
        while((mtx[pI][pJ].indice != iBandeira) && (mtx[pI][pJ].indice != iSaida))
        {
            if((mtx[pI][pJ-1].indice == iXis))
            {
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
                mtx[linha][coluna].caractere = cParede;
                mtx[linha][coluna].indice = iXis;
            }
        }
    }

    mtx[pI][pJ].caractere = cBoneco;
    mtx[pI][pJ].indice = iBoneco;
    if (mtx[0][21].indice != iBoneco)  //coloca o boneco no centro da matriz
    {
        mtx[0][21].caractere = cSaida; //caracter recebe o numero relacionado ao saido do labirinto declarado
        mtx[0][21].indice = iSaida;  //indice recebe o iSaida declarados no cabecalho para testes internos
    }
    bandeira(mtx,tm5);
}

void tela4(matrizGame mtx[][tmax], int pI, int pJ)
{
    cout << "\n\tCHAVES:"<<contLibera<<"\n";
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
                mtx[linha][coluna].caractere = cParede;
                mtx[linha][coluna].indice = iXis;
            }
        }
    }
    mtx[pI][pJ].caractere = cBoneco;
    mtx[pI][pJ].indice = iBoneco;
    if (mtx[0][0].indice != iBoneco)  //coloca o boneco no centro da matriz
    {
        mtx[0][0].caractere = cSaida; //caracter recebe o numero relacionado ao saido do labirinto declarado
        mtx[0][0].indice = iSaida;  //indice recebe o iSaida declarados no cabecalho para testes internos
    }
    bandeira(mtx,tm4);
}

void tela3(matrizGame mtx[][tmax], int pI, int pJ)
{
    cout << "\n\tCHAVES:"<<contLibera<<"\n";
    for(int linha = 0; linha < tm3; linha++)
    {
        for(int coluna = 0; coluna < tm3; coluna++)
        {
            if (      (coluna >= 0 && coluna <= 7 && linha == 3   )||(coluna == 7 && linha >= 3 && linha <= 8     )||(coluna <= 7 && coluna >= 2 && linha == 8   )
                    ||(coluna == 2 && linha >= 6 && linha <= 8    )||(coluna == 7 && linha >= 8 && linha <= 15    )||(coluna >= 2 && coluna <= 7 && linha == 15  )
                    ||(coluna == 2 && linha >= 15 && linha <= 28  )||(linha == 28 && coluna >= 2 && coluna <= 13  )||(coluna == 13 && linha >= 18 && linha <= 28 )
                    ||(linha == 18 && coluna >= 4 && coluna <= 12 )||(coluna == 4 && linha >= 18 && linha <= 25   )||(linha == 25 && coluna >= 4 && coluna <= 10 )
                    ||(coluna == 10 && linha >= 21 && linha <= 25 )||(linha == 21 && coluna >= 10 && coluna <= 26 )||(coluna == 7 && linha >= 21 && linha <= 23  )
                    ||(linha == 23 && coluna >= 7 && coluna <= 8  )||(linha == 21 && coluna >= 7 && coluna <= 10  )||(linha == 3 && coluna >= 7 && coluna <= 28  )
                    ||(coluna == 28 && linha >= 3 && linha <= 5   )||(linha == 5 && coluna >= 11 && coluna <= 28  )||(coluna == 11 && linha >= 5 && linha <= 9   )
                    ||(linha == 9 && coluna >= 11 && coluna <= 30 )||(linha == 12 && coluna >= 11 && coluna <= 27 )||(coluna == 11 && linha >= 9 && linha <= 12  )
                    ||(coluna == 27 && linha >= 12 && linha <= 15 )||(linha == 15 && coluna >= 15 && coluna <= 27 )||(coluna == 15 && linha >= 15 && linha <= 20 )
                    ||(coluna == 26 && linha >= 21 && linha <= 24 )||(linha == 24 && coluna >= 17 && coluna <= 26 )||(coluna == 11 && linha >= 10 && linha <= 15 )
                    ||(linha == 15 && coluna >= 9 && coluna <= 11 )||(coluna == 9 && linha >= 13 && linha <=15    )||(coluna == 20 && linha >= 16 && linha <=18  )
                    ||(linha == 18 && coluna >= 20 && coluna <= 26)||(coluna == 17 && linha >=25 && linha <= 30   )

                  )
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
                mtx[linha][coluna].caractere = cParede;
                mtx[linha][coluna].indice = iXis;
            }
        }
    }
    mtx[pI][pJ].caractere = cBoneco;
    mtx[pI][pJ].indice = iBoneco;
    if (mtx[9][30].indice != iBoneco)  //coloca o boneco no centro da matriz
    {
        mtx[9][30].caractere = cSaida; //caracter recebe o numero relacionado ao saido do labirinto declarado
        mtx[9][30].indice = iSaida;  //indice recebe o iSaida declarados no cabecalho para testes internos
    }
    if (mtx[30][17].indice != iBoneco)  //coloca o boneco no centro da matriz
    {
        mtx[30][17].caractere = cSaida; //caracter recebe o numero relacionado ao saido do labirinto declarado
        mtx[30][17].indice = iSaida;  //indice recebe o iSaida declarados no cabecalho para testes internos
    }
    bandeira(mtx,tm3);
}

void tela2(matrizGame mtx[][tmax], int pI, int pJ)
{   cout << "\n\t\t\t\tCHAVES:"<<contLibera<<"\n";
    cout << "\n\n\t\t\t\tConceito da tabela verdade: NEGACAO";
    cout << "\n\t\t\t\tA negacao consistem em inverter oque esta se querendo";
    cout << "\n\t\t\t\tOque e verdadeiro fica falso e vice-versa. ";
    cout << "\n\n\n\t\t\t\t ----------------------";
    cout << "\n\t\t\t\t|nao pegue dois objetos|";
    cout << "\n\t\t\t\t ----------------------\n\n";

    for(int linha = 0; linha < tm2; linha++)
    {
        for(int coluna = 0; coluna < tm2; coluna++)
        {


            if ((coluna > 4 && coluna < 16 && linha == 20)||(coluna == 15 && linha > 20)||
                (coluna > 4 && coluna < 20  && linha == 16)||(coluna > 13  && coluna < 19  && linha == 11)||
                (coluna == 5 && linha < 20 && linha > 16)||(coluna == 19 && linha < 16  && linha > 10)||
                (coluna > 11 && coluna < 14  && linha == 14)||(coluna == 13 && linha < 14  && linha > 10)||
                (coluna < 14 && coluna > 1  && linha == 14)||(coluna < 5 && coluna > 1  && linha == 4)||
                (coluna < 20 && coluna > 9  && linha == 6)||(coluna == 4 && linha < 10 && linha > 3 )||
                (coluna < 20 && coluna > 9  && linha == 2)||(coluna == 2 && linha < 14 && linha > 4)||
                (coluna == 2 && linha > 3 && linha < 10)||(coluna == 10 && linha > 10 && linha < 6)||
                (coluna > 3 && coluna < 20 && linha == 9)||(coluna == 19 && linha < 10 && linha > 5)||
                (coluna == 10 && linha < 6 && linha > 2)||(coluna == 19 && linha < 2)||
                (coluna > 19 && coluna < 23 && linha == 14)||(coluna == 23 && linha > 13 && linha < 23)||
                (coluna < 24 && coluna > 19 && linha == 22)||(coluna == 20 && linha > 17 && linha < 23)||
                (coluna < 21 && coluna > 6 && linha == 18)||(coluna > 0 && coluna < 15 && linha == 23)||
                (coluna == 1 && linha > 16 && linha < 24)||(coluna > 2 && coluna < 12 && linha == 14)||
                (coluna < 7 && coluna > 1 && linha == 2)||(coluna == 7 && linha > 1 && linha < 9)||
                (coluna > 2 && coluna < 12 && linha == 12)||(coluna == 23 && linha < 14 && linha >3)||
                (coluna > 12 && coluna < 23 && linha == 4))
            {

                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }

            else
            {
                mtx[linha][coluna].caractere = cParede;
                mtx[linha][coluna].indice = iXis;
            }

            if ((linha == 2 && coluna == 2)||(linha == 18 && coluna == 20)||
                (linha == 4 && coluna == 13)||(linha == 17 && coluna == 1)){
                mtx[linha][coluna].caractere = cPeca;
                mtx[linha][coluna].indice = iPeca;
            }
        }
    }
    mtx[pI][pJ].caractere = cBoneco;
    mtx[pI][pJ].indice = iBoneco;
    if (mtx[0][19].indice != iBoneco)  //coloca o boneco no centro da matriz
    {
        mtx[0][19].caractere = cSaida; //caracter recebe o numero relacionado ao saido do labirinto declarado
        mtx[0][19].indice = iSaida;  //indice recebe o iSaida declarados no cabecalho para testes internos
    }
    bandeira(mtx,tm2);
}

void tela1(matrizGame mtx[][tmax], int pI, int pJ)
{
    cout << "\n\tCHAVES:"<<contLibera<<"\n";
    for(int linha = 0; linha < tm1; linha++)
    {
        for(int coluna = 0; coluna < tm1; coluna++)
        {
            if ((coluna == 10 && linha > 16)||(coluna >= 10 && coluna <=15 && linha == 16)||
                    (coluna == 15 && linha > 9 && linha < 16)||(coluna > 4 && coluna < 15 && linha == 10)||
                    (coluna == 5 && linha < 10 && linha > 3)||(coluna >= 5 && coluna < 17 && linha == 4)||
                    (coluna == 16 && linha < 4))
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else if ((coluna <= 10 && coluna >= 2 && linha == 16)||(coluna == 2 && linha > 16 && linha <=10)||
                     (coluna == 8 && linha > 4 && linha < 8)||(coluna >= 8 && coluna <= 18 && linha == 7)||
                     (coluna == 2 && linha < 16 && linha > 4)||(coluna > 7 && coluna < 13 && linha == 13)||
                     (coluna == 8 && linha > 10 && linha < 13)||(coluna == 13 && linha > 0 && linha < 4)||
                     (coluna > 2 && coluna < 13 && linha == 1)||(coluna == 18 && linha > 7 &&linha < 19)||
                     (coluna < 18 && coluna > 13 && linha == 18))
            {
                mtx[linha][coluna].caractere = cEspaco;
                mtx[linha][coluna].indice = iEspaco;
            }
            else
            {
                mtx[linha][coluna].caractere = cParede;
                mtx[linha][coluna].indice = iXis;
            }
        }
    }
    mtx[pI][pJ].caractere = cBoneco;
    mtx[pI][pJ].indice = iBoneco;
    if (mtx[0][16].indice != iBoneco)  //coloca o boneco no centro da matriz
    {
        mtx[0][16].caractere = cSaida; //caracter recebe o numero relacionado ao saido do labirinto declarado
        mtx[0][16].indice = iSaida;  //indice recebe o iSaida declarados no cabecalho para testes internos
    }
    bandeira(mtx,tm1);
}

void tuto1(matrizGame mtx[][tmax], int pI, int pJ)
{
    //desenho da trilha
    for(int linha = 0; linha < tm1; linha++)
    {
        for(int coluna = 0; coluna < tm1; coluna++)
        {
            if ((linha > 17 && coluna == 10) || (linha == 18 && coluna > 0 && coluna < 10) || (coluna == 1 && linha > 0 && linha < 18) ||
                    (linha == 1 && coluna > 0 && coluna < 20) || (coluna == 19 && linha > 0 && linha < 15) || (linha == 14 && coluna < 19 && coluna > 4) ||
                    (coluna == 5 && linha > 4 && linha < 14) || (linha == 5 && coluna > 5 && coluna < 16) || (coluna == 15 && linha > 5 && linha < 11) ||
                    ( linha == 10 && coluna > 9 && coluna < 15))
            {
                mtx[linha][coluna].caractere = cEspaco; //caracter recebe o numero relacionado ao espaço declarado
                mtx[linha][coluna].indice = iEspaco; //indice recebe o iEsoaco  declarados no cabecalho para testes internos
            }
            else
            {
                mtx[linha][coluna].caractere = cParede; //caracter recebe o numero relacionado ao 'X' declarado
                mtx[linha][coluna].indice = iXis; //indice recebe o iXis  declarados no cabecalho para testes internos
            }
        }
    }
    mtx[pI][pJ].caractere = cBoneco; //caracter recebe o numero relacionado ao boneco declarado
    mtx[pI][pJ].indice = iBoneco; //indice recebe o iBoneco declarados no cabecalho para testes internos
    if (mtx[10][10].indice != iBoneco)  //coloca o boneco no centro da matriz
    {
        mtx[10][10].caractere = cSaida; //caracter recebe o numero relacionado ao saido do labirinto declarado
        mtx[10][10].indice = iSaida;  //indice recebe o iSaida declarados no cabecalho para testes internos
    }
    bandeira(mtx,tm1);
}

void selectMatriz(matrizGame mtx[][tmax], int matriz, int pI, int pJ)
{
    //escolha da matriz
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
        ajudafixa();
        tuto1(mtx, pI, pJ);
        printMatriz(mtx,tm1);

    }
    //Sleep(500);
    nextMatriz = testeSaida(mtx,matriz);
}

bool testeSaida(matrizGame mtx [][tmax], int matriz)
{

    switch(matriz)
    {

    case 1:
        if (mtx[0][16].indice == iBoneco)
        {
            return true;
        }
        break;
    case 2:
        if (mtx[0][19].indice == iBoneco) // POSIÇAO DE SAIDA
        {
            if (contLocal2 == 2){
                contLibera ++;
            }
            return true;
        }
        break;
    case 3:
        if (mtx[9][30].indice == iBoneco || mtx[30][17].indice == iBoneco) // POSIÇAO DE SAIDA
        {
            return true;
        }
        break;
    case 4:
        if (mtx[0][0].indice == iBoneco) // POSIÇAO DE SAIDA
        {
            return true;
        }
        break;
    case 5:
        if (mtx[0][21].indice == iBoneco) // POSIÇAO DE SAIDA
        {
            return true;
        }
        break;
    case 6:
        if (mtx[10][10].indice == iBoneco) // POSIÇAO DE SAIDA
        {
            return true;
        }
        break;
    }
    return false;
}

void selectMovimento(matrizGame mtx[][tmax], int matriz)
{

    do
    {
        switch(matriz)
        {
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
        if (nextMatriz)
        {
            nextMatriz = false;
            return;
        }
    }
    while(matriz != -1);
}

void movimento(matrizGame mtx[][tmax], int nMatriz)
{

    char direcao[40];

    cout << "\n\n\t\t  Para qual direcao deseja ir? ";
    fflush(stdin);
    gets(direcao);

    for(int i = 0; i < strlen(direcao); i++)
    {
        if (direcao[i] == 119)      //para cima 'W'
        {
            system("CLS");
            alteraPosicao(1,0,0,0, mtx);
            selectMatriz(mtx, nMatriz,pI, pJ);
        }
        else if (direcao[i] == 100)  //para direita 'D'
        {
            system("CLS");
            alteraPosicao(0,0,1,0, mtx);
            selectMatriz(mtx, nMatriz,pI, pJ);
        }
        else if (direcao[i] == 115) //para baixo 'S'
        {
            system("CLS");
            alteraPosicao(0,1,0,0, mtx);
            selectMatriz(mtx, nMatriz,pI, pJ);
        }
        else if (direcao[i] == 97)   //para esqueda 'A'
        {
            system("CLS");
            alteraPosicao(0,0,0,1, mtx);
            selectMatriz(mtx, nMatriz,pI, pJ);
        }
    }
    reiniciaMatriz(mtx, matriz, pI, pJ);
}

void reiniciaMatriz(matrizGame mtx[][tmax], int nMatriz, int pI, int pJ){
    if (!nextMatriz && matriz == 6 ){
        ajuda(mtx, pI, pJ);
        system("CLS");
        roteiroTuto(mtx);
    }
    else if (!nextMatriz && matriz == 1){
        system("pause");
        system("CLS");
        roteiro(mtx);
    }
    else if (!nextMatriz && matriz == 2){
        //teste peca para negaçao
        if (mtx[2][2].indice == iBoneco || mtx[18][20].indice == iBoneco||
            mtx[4][13].indice == iBoneco || mtx[17][1].indice == iBoneco)
        {
        contLocal2 ++;
        }
        else {
            //se o boneco parar fora de uma peça o lab e reiniciado
            contLocal2 = 0;
            system("pause");
            system("CLS");
            roteiro(mtx);
        }
    }
    else if (!nextMatriz && matriz == 4){
        system("pause");
        system("CLS");
        roteiro(mtx);
    }



}


void roteiro(matrizGame mtx[][tmax])
{
    //if (matriz == 0){
        matriz;
        //trata-se de uma matriz
        //inicio
        matriz = 1;
        pI = 20;
        pJ = 10;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
        //fim
        matriz = 2;
        pI = 25;
        pJ = 15;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
        matriz = 4;
        pI = 35;
        pJ = 25;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
        matriz = 3;
        pI = 3;
        pJ = 0;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
        matriz = 5;
        pI = 40;
        pJ = 21;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
    /*}
    else if(matriz == 1){
        matriz = 0;
        roteiro(mtx);
    }
    else if(matriz == 2){
        pI = 25;
        pJ = 15;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
        matriz = 4;
        pI = 35;
        pJ = 25;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
        matriz = 3;
        pI = 3;
        pJ = 0;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
        matriz = 5;
        pI = 40;
        pJ = 21;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
    }
    else if (matriz == 4){
        pI = 35;
        pJ = 25;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
        matriz = 3;
        pI = 3;
        pJ = 0;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
        matriz = 5;
        pI = 40;
        pJ = 21;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
    }
    else if(matriz == 3){
        pI = 3;
        pJ = 0;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
        matriz = 5;
        pI = 40;
        pJ = 21;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
    }
    else {
        pI = 40;
        pJ = 21;
        selectMatriz(mtx, matriz, pI, pJ);
        selectMovimento(mtx, matriz);
        cout << "\n\n";
        system("pause");
        system("CLS");
    }*/


}


void ajudafixa(){
        cout << "\n\n\t\tVoce ira aprender como caminhar pelo nosso labirinto.\n";
        cout << "\n\tVoce deve usar as teclas W;A;S e D para se locomover respectivamente para cima,\n\tesquerda, baixo e direita.";
        cout << "\n\tSeu objetivo sera digitar uma sequencia de teclas que ajude o boneco a chegar ao centro do Labirinto.";
        cout << "\n\tVoce deve lembrar o boneco se locomove de ponto a ponto, so basta 1 comando \n\tpara que ele chegue ate o proximo ponto.\n\tApos terminar de digitar a sequencia\n\tde movimentos desejada aperte enter para prosseguir.\n";

}

void roteiroTuto(matrizGame mtx[][tmax])
{
    matriz = 6;
    pI = 20;
    pJ = 10;
    selectMatriz(mtx, matriz, pI, pJ);
    selectMovimento(mtx, matriz);
    cout << "\n\n";
    nextMatriz = testeSaida(mtx,matriz);
    system("pause");
}


void ajuda(matrizGame mtx[][tmax], int pI, int pJ)
{
        while (1){
        if(mtx[10][15].indice == iBoneco){
            cout << "\n\n\n\t\t --------------------------------";
            cout << "\n\t\t |  voce chegou muito perto!!!  |";
            cout << "\n\t\t | Digite a sequencia completa: |";
            cout << "\n\t\t -------------------------------- \n\n";
            system("pause");
            break;
        }
        else if(mtx[14][19].indice == iBoneco){
            cout << "\n\n\n\t\t --------------------------------";
            cout << "\n\t\t |     voce esta na metade!!!   |";
            cout << "\n\t\t | Digite a sequencia completa: |";
            cout << "\n\t\t --------------------------------\n\n";
            system("pause");
            break;
        }
        else{
            cout << "\n\n\n\t\t ------------------------------------------";
            cout << "\n\t\t |O boneco nao conceguiu chegar ao centro:|";
            cout << "\n\t\t |      Digite a sequencia completa:      |";
            cout << "\n\t\t ------------------------------------------\n\n";
            system("pause");
            break;
        }
    }
}
bool iniciarJogo()
{
    int op;
    matrizGame mtx[tmax][tmax];

    while (1)
    {
        cout << "\n\n\t 1-Iniciar jogo\n";
        cout << "\t 2-Tutorial\n";
        cout << "\t 3-Sair\n\t ";
        cin >> op;


        if (op > 0 && op < 5)
        {
            if (op == 1)
            {
                system("CLS");
                roteiro(mtx);
                break;
            }
            if (op == 2)
            {
                system("CLS");
                roteiroTuto(mtx);
                system("CLS");
                iniciarJogo();
                break;
            }
            if (op == 3)
            {
                return 0;
            }
        }
        else
        {
            cout << "Escolha uma opcao valida";
            system("pause");
            system("CLS");
            iniciarJogo();
        }
    }
    return 0;
}

