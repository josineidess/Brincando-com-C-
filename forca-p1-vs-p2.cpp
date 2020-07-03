#include <iostream>

#include <stdlib.h>

using namespace std;

char palavra[30], palavra_oculta[30], letra[1],tabuleiro[120] = {};
int tam = 0, chances = 6, acertos = 0;
bool achou = false;

int tamanho(char palavra[30]);
void esconder_palavra(char palavra[30]);
bool buscar_letra(char l[1]);
void tabu_ini(char tabuleiro[120]);
void atualizar_tabu(char tabuleiro[120],int chances);

int main() {
  cin >> palavra;
  system("color 0a");
  system("cls");
  tam = tamanho(palavra);
  tabu_ini(tabuleiro);
  esconder_palavra(palavra);

  while (chances > 0 && acertos < tam) {
    atualizar_tabu(tabuleiro,chances);
    for(int e = 0;e < 120;e++){
        if(e%11==0){
            cout << "\n" << tabuleiro[e];
        }else{
        cout << tabuleiro[e];
    }
    }
    cout << "\n";

    for (int e = 0; e < tam; e++) {
      cout << palavra_oculta[e] << " ";
    }
    cout << endl;
    cin >> letra;
    buscar_letra(letra);
    achou = false;

    for (int e = 0; e < tam; e++) {
      cout << palavra_oculta[e] << " ";
    }
    system("cls");
    }
  if (acertos == tam) {
    cout << "Parabens voce ganhou!" << endl;
  } else {
    cout << "Que pena, voce perdeu!" << endl;
  }
  return 0;
}

int tamanho(char palavra[30]) {
  int e = 0;
  while (palavra[e] != '\0') {
    e++;
  }
  return e;
}
void esconder_palavra(char palavra[30]) {
  for (int e = 0; e < tam; e++) {
    palavra_oculta[e] = '_';
  }
}
bool buscar_letra(char l[1]) {
  for (int e = 0; e < tam; e++) {
    if (palavra[e] == l[0]) {
      palavra_oculta[e] = l[0];
      acertos++;
      achou = true;
    }
  }
  if (!achou) {
    chances--;
    return false;
  } else {
    return true;
  }
}

void tabu_ini(char tabuleiro[120]){
    for(int e = 0;e < 120;e++){
        tabuleiro[e] = ' ';
    }
    for(int e = 0;e < 120;e++){
        if(e >= 0 && e < 11){
            tabuleiro[e] = '_';
        }
        if(e%11==0){
            tabuleiro[e] = '|';
        }
    }
}

void atualizar_tabu(char tabuleiro[120],int chances){
    switch(chances){
       case 5:
           tabuleiro[17] = '|';
           tabuleiro[21] = '|';
           tabuleiro[28] = '\\';
           tabuleiro[32] = '/';
           tabuleiro[40] = '-';
           tabuleiro[41] = '-';
           tabuleiro[42] = '-';
           break;
       case 4:
          for (int w = 52, s = 0; w < 87; w++) {
              if (s % 11 == 0) {
                 tabuleiro[w] = '|';
              }
               s++;
            }
            break;
       case 3:
         tabuleiro[53] = '\\';
         tabuleiro[65] = '\\';
         break;
       case 2:
         tabuleiro[51] = '/';
         tabuleiro[61] = '/';
         break;
       case 1:
          tabuleiro[95] = '/';
          tabuleiro[105] = '/';
          break;
       case 0:
          tabuleiro[97] = '\\';
          tabuleiro[109] = '\\';
          break;
}
}
