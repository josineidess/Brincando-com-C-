#include <iostream>

#include <stdlib.h>

#include <string.h>

using namespace std;

//variaveis globais
string palavra_sorteada = " ";
int tam_palavra = palavra_sorteada.size();
char forca[120];
int jogada = 1;
char palavra[20];
bool ganhou = false;
char letra = ' ';
//funcoes

char desenho_forca();
char advinha_palavra();

int main() {
  cout << "palavra: ";
  cin >> palavra_sorteada;
  system("color 0a");
  tam_palavra = palavra_sorteada.size();
  while (ganhou || jogada < 8) {
    if (jogada == 7) {
      desenho_forca();
      cout << "\n\nP E R D E U...\n\n";
      system("pause");
      break;
    } else {
      desenho_forca();
      cout << "\n\nLetra: ";
      cin >> letra;
      system("cls");
      jogada++;
    }
  }
  return 0;
}

char desenho_forca() {
  switch (jogada) {
  case 1:
    for (int e = 0; e < 120; e++) {
      if (e % 11 == 0) {
        forca[e] = '|';
      }
    }
    for (int r = 0; r < 11; r++) {
      forca[r] = '_';
    }
    advinha_palavra();
    break;
  case 2:
    forca[17] = '|';
    forca[21] = '|';
    forca[28] = '\\';
    forca[32] = '/';
    forca[40] = '-';
    forca[41] = '-';
    forca[42] = '-';
    advinha_palavra();
    break;
  case 3:
    for (int w = 52, s = 0; w < 87; w++) {
      if (s % 11 == 0) {
        forca[w] = '|';
      }
      s++;
    }
    advinha_palavra();
    break;
  case 4:
    forca[53] = '\\';
    forca[65] = '\\';
    advinha_palavra();
    break;
  case 5:
    forca[51] = '/';
    forca[61] = '/';
    advinha_palavra();
    break;
  case 6:
    forca[95] = '/';
    forca[105] = '/';
    advinha_palavra();
    break;
  case 7:
    forca[97] = '\\';
    forca[109] = '\\';
    break;
  }

  for (int i = 0; i < 120; i++) {
    if (i % 11 == 0) {
      cout << "\n" << forca[i];
    } else {
      cout << forca[i];
    }
  }
  cout << "\n\n";

}

char advinha_palavra() {
  for (int e = 0; e < tam_palavra; e++) {
    palavra[e] = '_';
  }
  for (int r = 0; r < tam_palavra; r++) {
    cout << palavra[r] << " ";
  }
}
