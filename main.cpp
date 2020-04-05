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
    char caractere;  //0 = ' '; 1 = 'X'; 2  = 206; 3 = 220;
    int indice = 0;
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
<<<<<<< HEAD
void tela5(matrizGame matriz5[][tmax]);
void tela4(matrizGame matriz4[][tmax]);
void tela3(matrizGame matriz3[][tmax]);
void tela2(matrizGame matriz2[][tmax]);
void tela1(matrizGame matriz1[][tmax]);
void alteraPosicao(bool subir,bool descer, bool direita, bool esquerda);
void selectMatriz(int matriz);
void movimento();

int main()
{
    /*keybd_event(VK_MENU,0x36,0,0);
    keybd_event(VK_RETURN,0x1C,0,0);
    keybd_event(VK_RETURN,0x1C,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);*/

    int resposta = 5;
    selectMatriz(resposta);

    do
    {
        movimento();
    }
    while(resposta !=0);
}

=======
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

>>>>>>> 55267baa0141b964bc928e81f2648c1f3f1a3651
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
<<<<<<< HEAD
                matMax[linha][coluna].indice = 3;
=======
>>>>>>> 55267baa0141b964bc928e81f2648c1f3f1a3651
            }
        }
    }
}

void printMatriz(matrizGame matMax[][tmax], int tamanho)
{
<<<<<<< HEAD
=======

>>>>>>> 55267baa0141b964bc928e81f2648c1f3f1a3651
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

<<<<<<< HEAD
void alteraPosicao(bool subir,bool descer, bool direita, bool esquerda)
{
    if(subir == true)
    {
        while((matriz5[posicaoI][posicaoJ].indice != 3)){
            if((matriz5[posicaoI-1][posicaoJ].indice == 1)){
                break;
            }
            posicaoI--;
        }
    }
    else if(descer == true)
    {
        while((matriz5[posicaoI][posicaoJ].indice != 3)){
            if((matriz5[posicaoI+1][posicaoJ].indice == 1)){
                break;
            }
            posicaoI++;
        }
    }
    else if(direita == true)
    {
        while((matriz5[posicaoI][posicaoJ].indice != 3)){
            if((matriz5[posicaoI][posicaoJ+1].indice == 1)){
                break;
            }
            posicaoJ++;
        }
    }
    else if(esquerda == true)
    {
        while((matriz5[posicaoI][posicaoJ].indice != 3)){
            if((matriz5[posicaoI][posicaoJ-1].indice == 1)){
                break;
            }
            posicaoJ--;
        }
    }
}

void tela5(matrizGame matriz5[][tmax])
{

    for(int linha = 0; linha < tm5; linha++)
=======
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
>>>>>>> 55267baa0141b964bc928e81f2648c1f3f1a3651
    {
        posicaoJ--;
    }

    do
    {
        for(int linha = 0; linha < tm5; linha++)
        {
<<<<<<< HEAD
            //rota principal
            if ((coluna == tm1 && linha > tm1)||(coluna == 10 && linha > 20 && linha < 30)||
                    (coluna == 16 && linha > 30 && linha < 35)||(coluna == 5 && linha < 34 && linha > 14)||
                    (coluna == 28 && linha > 15 && linha < 38)||(coluna == tm4 && linha < 38 && linha > 9)||
                    (coluna == 11 && linha < 10 && linha > 4)||(coluna == tm1 && linha < 5) ||
                    (linha == tm1 && coluna > 10 && coluna <= tm1)||(linha == 30 && coluna >= 10 && coluna <= 16)||
                    (linha == 34 && coluna < 16 && coluna > 4)||(linha == 15 && coluna > 5 && coluna <29)||
                    (linha == 37 && coluna > 28 && coluna < tm4)||(linha == 10 && coluna < tm4 && coluna > 10)||
                    (linha == 5 && coluna > 11 && coluna < 22))
=======
            for(int coluna = 0; coluna < tm5; coluna++)
>>>>>>> 55267baa0141b964bc928e81f2648c1f3f1a3651
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

<<<<<<< HEAD
                matriz5[linha][coluna].caractere = ' ';
                matriz5[linha][coluna].indice = 0;
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
                matriz5[linha][coluna].indice = 0;
            }
            else
            {
                matriz5[linha][coluna].caractere = 'X';
                matriz5[linha][coluna].indice = 1;
=======
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
>>>>>>> 55267baa0141b964bc928e81f2648c1f3f1a3651
            }
        }

        matriz5[posicaoI][posicaoJ].caractere = 206;
        bandeira(matriz5,tm5);
        printMatriz(matriz5,tm5);
    }
<<<<<<< HEAD

    matriz5[posicaoI][posicaoJ].caractere = 206;
    matriz5[posicaoI][posicaoJ].indice = 2;
    bandeira(matriz5,tm5);
    printMatriz(matriz5,tm5);
    Sleep(1000);
=======
    while(1);
>>>>>>> 55267baa0141b964bc928e81f2648c1f3f1a3651
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
<<<<<<< HEAD
    char direcao[40];

    cout << "\n\nPara qual direcao deseja ir? ";
    fflush(stdin);
    gets(direcao);

    for(int i = 0; i < strlen(direcao); i++)
    {
        if (direcao[i] == 119)      //para cima
        {
            system("CLS");
            alteraPosicao(1,0,0,0);
            tela5(matriz5);
        }
        else if (direcao[i] == 100)  //para direita
        {
            system("CLS");
            alteraPosicao(0,0,1,0);
            tela5(matriz5);
        }
        else if (direcao[i] == 115) //para baixo
        {
            system("CLS");
            alteraPosicao(0,1,0,0);
            tela5(matriz5);
        }
        else if (direcao[i] == 97)   //para esqueda
        {
            system("CLS");
            alteraPosicao(0,0,0,1);
            tela5(matriz5);
        }
        else
        {
            system("CLS");
            alteraPosicao(0,0,0,0);
            tela5(matriz5);
        }
=======
    char direcao[100];

    cout << "\nPara qual direcao deseja ir? ";
    fflush(stdin);
    gets(direcao);


    for(int i = 0; i < strlen(direcao); i++)
    {
        char letra = direcao[i];

        switch(direcao[i])
        {
        case 'w':
            system("CLS");
            tela5(matriz5, 1,0,0,0);
            break;
        case 's':
            system("CLS");
            tela5(matriz5, 0,1,0,0);
            break;
        case 'a':
            system("CLS");
            tela5(matriz5, 0,0,0,1);
            break;
        case 'd':
            system("CLS");
            tela5(matriz5, 0,0,1,0);
            break;
        default:
            system("CLS");
            tela5(matriz5,0,0,0,0);
            break;
        }

>>>>>>> 55267baa0141b964bc928e81f2648c1f3f1a3651
    }
}

           /*if (letra == 119)      //para cima
            {
            system("CLS");
            tela5(matriz5, 1,0,0,0);
            }
            else if (letra == 100)  //para direita
            {
            system("CLS");
            tela5(matriz5, 0,0,1,0);
            }
            else if (letra == 115) //para baixo
            {
                system("CLS");
                tela5(matriz5, 0,1,0,0);
            }
            else if (letra == 97)   //para esqueda
            {
                system("CLS");
                tela5(matriz5, 0,0,0,1);
            }
            else
            {
                system("CLS");
                tela5(matriz5,0,0,0,0);
            }*/
