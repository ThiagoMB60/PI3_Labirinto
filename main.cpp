#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

struct matrizGame
{
    char caractere;
};
const int tm1 = 21, tm2 = 26, tm3 = 31, tm4 = 36, tm5 = 41, tmax = tm5;

int posLinha;
int posColuna;
int posicaoI = 40, posicaoJ = 21;
matrizGame matriz5[tmax][tmax];
matrizGame matriz4[tmax][tmax];
matrizGame matriz3[tmax][tmax];
matrizGame matriz2[tmax][tmax];
matrizGame matriz1[tmax][tmax];

void cabecalho(int tamanho);
void rodape(int tamanho);
void bandeira(matrizGame marMax[][tmax],int tamanho);
void printMatriz(matrizGame matMax[][tmax], int tamanho);
void tela5(matrizGame matriz5[][tmax],bool subir,bool descer, bool direita, bool esquerda);
void tela4(matrizGame matriz4[][tmax],bool subir,bool descer, bool direita, bool esquerda);
void tela3(matrizGame matriz3[][tmax],bool subir,bool descer, bool direita, bool esquerda);
void tela2(matrizGame matriz2[][tmax],bool subir,bool descer, bool direita, bool esquerda);
void tela1(matrizGame matriz1[][tmax],bool subir,bool descer, bool direita, bool esquerda);
void selectMatriz(int matriz);
void movimento();

int main()
{
    /*keybd_event(VK_MENU,0x36,0,0);
    keybd_event(VK_RETURN,0x1C,0,0);
    keybd_event(VK_RETURN,0x1C,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);*/

    int resposta;

    do
    {
        cout << "\n\n\tQual matriz deseja imprimir? (0 para sair) .\n\n\t";
        cin >> resposta;
        selectMatriz(resposta);
        cout << "\n\n\n";
        system ("pause");
        system ("cls");

    }
    while(resposta !=0);
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

void bandeira(matrizGame matMax[][tmax], int tamanho)
{
    for(int linha = 0; linha < tamanho; linha++)
    {
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            if ((matMax[linha][coluna].caractere == ' ') && ((matMax[linha][coluna+1].caractere == ' ' &&
                    (matMax[linha-1][coluna].caractere == ' ' || matMax[linha+1][coluna].caractere == ' ')) ||
                    (matMax[linha][coluna-1].caractere == ' ' && (matMax[linha-1][coluna].caractere == ' ' ||
                            matMax[linha+1][coluna].caractere == ' '))))
            {
                matMax[linha][coluna].caractere = 220;
            }
        }
    }
}

void printMatriz(matrizGame matMax[][tmax], int tamanho)
{

    cabecalho(tamanho);
    for(int linha = 0; linha < tamanho; linha++)
    {

        cout << "\n\t\t  " << linha<< " _";
        if (linha < 10)
            cout << " ";
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            cout << matMax[linha][coluna].caractere;
            cout << " ";
        }
        cout << "_" << linha;
    }
    rodape(tamanho);
    movimento();
}

void tela5(matrizGame matriz5[][tmax],bool subir,bool descer, bool direita, bool esquerda)
{
    if(subir == true)
    {
        posicaoI--;
    }
    else if(descer == true)
    {
        posicaoI++;
    }
    else if(direita == true)
    {
        posicaoJ++;
    }
    else if(esquerda == true)
    {
        posicaoJ--;
    }

    do
    {
        for(int linha = 0; linha < tm5; linha++)
        {
            for(int coluna = 0; coluna < tm5; coluna++)
            {
                //rota principal
                if ((coluna == tm1 && linha > tm1)||(coluna == 10 && linha > 20 && linha < 30)||
                        (coluna == 16 && linha > 30 && linha < 35)||(coluna == 5 && linha < 34 && linha > 14)||
                        (coluna == 28 && linha > 15 && linha < 38)||(coluna == tm4 && linha < 38 && linha > 9)||
                        (coluna == 11 && linha < 10 && linha > 4)||(coluna == tm1 && linha < 5) ||
                        (linha == tm1 && coluna > 10 && coluna <= tm1)||(linha == 30 && coluna >= 10 && coluna <= 16)||
                        (linha == 34 && coluna < 16 && coluna > 4)||(linha == 15 && coluna > 5 && coluna <29)||
                        (linha == 37 && coluna > 28 && coluna < tm4)||(linha == 10 && coluna < tm4 && coluna > 10)||
                        (linha == 5 && coluna > 11 && coluna < 22))
                {

                    matriz5[linha][coluna].caractere = ' ';
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
                    matriz5[linha][coluna].caractere = ' ';
                }
                else
                {
                    matriz5[linha][coluna].caractere = 'X';
                }
            }
        }

        matriz5[posicaoI][posicaoJ].caractere = 206;
        bandeira(matriz5,tm5);
        printMatriz(matriz5,tm5);
    }
    while(1);
}

void tela4(matrizGame matriz4[][tmax])
{
    for(int linha = 0; linha < tm4; linha++)
    {
        for(int coluna = 0; coluna < tm4; coluna++)
        {
            if (1==0)
            {
                matriz4[linha][coluna].caractere = ' ';
            }
            else if (1==0)
            {
                matriz4[linha][coluna].caractere = ' ';
            }
            else
            {
                matriz4[linha][coluna].caractere = 'X';
            }
        }
    }
    bandeira(matriz4,tm4);
    printMatriz(matriz4,tm4);
}

void tela3(matrizGame matriz3[][tmax])
{
    for(int linha = 0; linha < tm3; linha++)
    {
        for(int coluna = 0; coluna < tm3; coluna++)
        {
            if (1==0)
            {
                matriz3[linha][coluna].caractere = ' ';
            }
            else if (1==0)
            {
                matriz3[linha][coluna].caractere = ' ';
            }
            else
            {
                matriz3[linha][coluna].caractere = 'X';
            }
        }
    }
    bandeira(matriz4,tm4);
    printMatriz(matriz3,tm3);
}

void tela2(matrizGame matriz2[][tmax])
{
    for(int linha = 0; linha < tm2; linha++)
    {
        for(int coluna = 0; coluna < tm2; coluna++)
        {
            if (1==0)
            {
                matriz2[linha][coluna].caractere = ' ';
            }
            else if (1==0)
            {
                matriz2[linha][coluna].caractere = ' ';
            }
            else
            {
                matriz2[linha][coluna].caractere = 'X';
            }
        }
    }
    bandeira(matriz4,tm4);
    printMatriz(matriz2,tm2);
}

void tela1(matrizGame matriz1[][tmax])
{
    for(int linha = 0; linha < tm1; linha++)
    {
        for(int coluna = 0; coluna < tm1; coluna++)
        {
            if (1==0)
            {
                matriz1[linha][coluna].caractere = ' ';
            }
            else if (1==0)
            {
                matriz1[linha][coluna].caractere = ' ';
            }
            else
            {
                matriz1[linha][coluna].caractere = 'X';
            }
        }
    }
    bandeira(matriz4,tm4);
    printMatriz(matriz1,tm1);
}

void selectMatriz(int matriz)
{

    switch(matriz)
    {
    case 1:
        tela1(matriz1);
        break;
    case 2:
        tela2(matriz2);
        break;
    case 3:
        tela3(matriz3);
        break;
    case 4:
        tela4(matriz4);
        break;
    case 5:
        tela5(matriz5,0,0,0,0);
    }
}

void movimento()
{
    int fase;

    cout << "\nPara qual direcao deseja ir? ";

    fase = getch();
    if (fase == 72)      //para cima
    {
        system("CLS");
        tela5(matriz5, 1,0,0,0);
    }
    else if (fase == 77)  //para direita
    {
        system("CLS");
        tela5(matriz5, 0,0,1,0);
    }
    else if (fase == 80) //para baixo
    {
        system("CLS");
        tela5(matriz5, 0,1,0,0);
    }
    else if (fase == 75)   //para esqueda
    {
        system("CLS");
        tela5(matriz5, 0,0,0,1);
    }
}
