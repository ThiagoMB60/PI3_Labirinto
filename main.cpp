#include <iostream>
#include <windows.h>

using namespace std;

struct matrizGame
{
    char caractere;
};

const int tm1 = 21, tm2 = 26, tm3 = 31, tm4 = 36, tm5 = 41;

matrizGame matriz5[tm5][tm5];
matrizGame matriz4[tm4][tm4];
matrizGame matriz3[tm3][tm3];
matrizGame matriz2[tm2][tm2];
matrizGame matriz1[tm1][tm1];

int posLinha;
int posColuna;

void printMatriz5(int tamanho)
{

    cout << "\n\n\n\t\t      ";
    for (int i = 0 ; i < tm5; i++)
    {
        cout << i;
        if ( i< 10)
            cout  << " ";
    }
    cout << "\n";

    for(int linha = 0; linha < tamanho; linha++)
    {

        cout << "\n\t\t  " << linha<< " _";
        if (linha < 10)
            cout << " ";
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            cout << matriz5[linha][coluna].caractere;
            cout << " ";
        }
    }
}

void printMatriz4(int tamanho)
{

    cout << "\n\n\n\t\t      ";
    for (int i = 0 ; i < tm4; i++)
    {
        cout << i;
        if ( i< 10)
            cout  << " ";
    }
    cout << "\n";

    for(int linha = 0; linha < tamanho; linha++)
    {

        cout << "\n\t\t  " << linha<< " _";
        if (linha < 10)
            cout << " ";
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            cout << matriz4[linha][coluna].caractere;
            cout << " ";
        }
    }
}

void printMatriz3(int tamanho)
{

    cout << "\n\n\n\t\t      ";
    for (int i = 0 ; i < tm3; i++)
    {
        cout << i;
        if ( i< 10)
            cout  << " ";
    }
    cout << "\n";

    for(int linha = 0; linha < tamanho; linha++)
    {

        cout << "\n\t\t  " << linha<< " _";
        if (linha < 10)
            cout << " ";
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            cout << matriz3[linha][coluna].caractere;
            cout << " ";
        }
    }
}

void printMatriz2(int tamanho)
{

    cout << "\n\n\n\t\t      ";
    for (int i = 0 ; i < tm2; i++)
    {
        cout << i;
        if ( i< 10)
            cout  << " ";
    }
    cout << "\n";

    for(int linha = 0; linha < tamanho; linha++)
    {

        cout << "\n\t\t  " << linha<< " _";
        if (linha < 10)
            cout << " ";
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            cout << matriz2[linha][coluna].caractere;
            cout << " ";
        }
    }
}

void printMatriz1(int tamanho)
{

    cout << "\n\n\n\t\t      ";
    for (int i = 0 ; i < tm1; i++)
    {
        cout << i;
        if ( i< 10)
            cout  << " ";
    }
    cout << "\n";

    for(int linha = 0; linha < tamanho; linha++)
    {

        cout << "\n\t\t  " << linha<< " _";
        if (linha < 10)
            cout << " ";
        for(int coluna = 0; coluna < tamanho; coluna++)
        {
            cout << matriz1[linha][coluna].caractere;
            cout << " ";
        }
    }
}

void tela5(matrizGame matriz5[][tm5], int tamanho)
{

    for(int linha = 0; linha < tm5; linha++)
    {
        for(int coluna = 0; coluna < tm5; coluna++)
        {
            if ((coluna == tm1 && linha > tm1)||(coluna == 10 && linha > 20 && linha < 30)||
                    (coluna == 16 && linha > 30 && linha < 35)||(coluna == 5 && linha < 34 && linha > 14)||
                    (coluna == 28 && linha > 15 && linha < 38)||(coluna == tm4 && linha < 38 && linha > 9)||
                    (coluna == 11 && linha < 10 && linha > 4)||(coluna == tm1 && linha < 5))  // condições para colunas
            {

                matriz5[linha][coluna].caractere = ' ';
            }
            else if((linha == tm1 && coluna > 10 && coluna <= tm1)||(linha == 30 && coluna >= 10 && coluna <= 16)||
                    (linha == 34 && coluna < 16 && coluna > 4)||(linha == 15 && coluna > 5 && coluna <29)||
                    (linha == 37 && coluna > 28 && coluna < tm4)||(linha == 10 && coluna < tm4 && coluna > 10)||
                    (linha == 5 && coluna > 11 && coluna < 22))  //condições para linha
            {
                matriz5[linha][coluna].caractere = ' ';
            }
            else
            {
                matriz5[linha][coluna].caractere = 'X';
            }
        }
    }

    printMatriz5(tamanho);
}

void tela4(matrizGame matriz4[][tm4], int tamanho)
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
    printMatriz4(tamanho);
}
void tela3(matrizGame matriz3[][tm3], int tamanho)
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
    printMatriz3(tamanho);
}
void tela2(matrizGame matriz2[][tm2], int tamanho)
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
    printMatriz2(tamanho);
}
void tela1(matrizGame matriz1[][tm1], int tamanho)
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
    printMatriz1(tamanho);
}

void selectMatriz(int matriz, int tamanho)
{

    switch(matriz)
    {
    case 1:
        tamanho = tm1;
        tela1(matriz1, tamanho);
        break;
    case 2:
        tamanho = tm2;
        tela2(matriz2, tamanho);
        break;
    case 3:
        tamanho = tm3;
        tela3(matriz3, tamanho);
        break;
    case 4:
        tamanho = tm4;
        tela4(matriz4, tamanho);
        break;
    case 5:
        tamanho = tm5;
        tela5(matriz5, tamanho);
    }
}

int main()
{

    keybd_event(VK_MENU,0x36,0,0);
    keybd_event(VK_RETURN,0x1C,0,0);
    keybd_event(VK_RETURN,0x1C,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);

    int resposta = 0;
    int tamanho = 0;

    do
    {
        cout << "\n\n\tQual matriz deseja imprimir? (0 para sair).\n\n\t";
        cin >> resposta;
        selectMatriz(resposta, tamanho);
        cout << "\n\n\n";
        system ("pause");
        system ("cls");

    }
    while(resposta !=0 );
}
