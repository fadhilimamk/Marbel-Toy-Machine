/*
Marble Toy Automata Machine
Author  : Fadhil Imam Kurnia - 13515146
Date    : 13 September 2016
File    : main.c v1.00
Desc    : Machine to accept string and show whether that string accepted or not
          base on state that saved on external file
*/

#include <stdio.h>
#include "view.h"
#include "model.h"
#include <conio.h>
#include "boolean.h"
#include "controller.h"

int main(){
  DFA dfa;
  char kalimat[256];

  ShowStartPage();
  clearScreen();
  ShowHeader();
  printf(" # Kondisi Awal Marble Toy : \n");
  ShowToy(true,true,true);
  ReadFile(&dfa);
  printf(" # Masukkan kalimat: ");
  scanf("%s", &kalimat);
  printf("\n # Proses: ");
  proses(&dfa, kalimat);
  printf(" # Hasil akhir: >>> %s ", prosesFinal(&dfa, kalimat));

  if (isAccepted(prosesFinal(&dfa, kalimat))) {
    printf("(DITERIMA)");
  }else{
    printf("(DITOLAK)");
  }

  printf("\n # Kondisi Akhir Marble Toy : \n");
  ShowToy(prosesFinal(&dfa, kalimat)[0],prosesFinal(&dfa, kalimat)[1],prosesFinal(&dfa, kalimat)[2]);


  getch();

  return 0;
}
