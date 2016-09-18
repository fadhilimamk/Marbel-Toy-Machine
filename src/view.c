/*
Marble Toy Automata Machine
Author  : Fadhil Imam Kurnia - 13515146
Date    : 13 September 2016
File    : view.c v1.00
Desc    : File to support main app frontend
*/

#include "view.h"
#include "boolean.h"
#include <stdio.h>
#include <unistd.h>
#include <conio.h>

void clearScreen(){
  system("@cls||clear");
}

void ShowStartPage(){
  clearScreen();
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("                                        o   o         o    o     o-O-o                                                 \n");
  printf("                                        |\\ /|         |    |       |                                                   \n");
  printf("                                        | O |  oo o-o O-o  | o-o   |   o-o o  o                                        \n");
  printf("                                        |   | | | |   |  | | |-'   |   | | |  |                                        \n");
  printf("                                        o   o o-o-o   o-o  o o-o   o   o-o o--O                                        \n");
  printf("                                                                              |                                        \n");
  printf("                                                                           o--o                                        \n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("                                                        Welcome                \n");
  printf("                                          This is Marble Toy Automata Machine  \n");
  printf("                                           by: Fadhil Imam Kurnia - 13515146   \n");
  printf("                                               Press enter to continue !       \n");
  printf("                                                           ");
  getch();
}

void ShowHeader(){
  printf("                                        o   o         o    o     o-O-o                                                 \n");
  printf("                                        |\\ /|         |    |       |                                                   \n");
  printf("                                        | O |  oo o-o O-o  | o-o   |   o-o o  o                                        \n");
  printf("                                        |   | | | |   |  | | |-'   |   | | |  |                                        \n");
  printf("                                        o   o o-o-o   o-o  o o-o   o   o-o o--O                                        \n");
  printf("------------------------------------------------------------------------------|----------------------------------------\n");
  printf("                                                                           o--o                                        \n");
}

void ShowToy(boolean a, boolean b, boolean c){
  printf("                                                    A             B     \n");
  printf("        \n");
  if(!a){
    if(!c){
      printf("                                                |   /  |      |   /  |   \n");
      printf("                                               /   /    \\    /   /    \\  \n");
    }else{
      printf("                                                |   /  |      |   \\  |    \n");
      printf("                                               /   /    \\    /     \\  \\  \n");
    }
  }else{
    if(!c){
      printf("                                                |   \\  |      |   /  |     \n");
      printf("                                               /     \\  \\    /   /    \\   \n");
    }else{
      printf("                                                |   \\  |      |   \\  |      \n");
      printf("                                               /     \\  \\    /     \\  \\    \n");
    }
  }
  printf("                                              /    /\\    \\  /    /\\    \\      \n");
  printf("                                             /    /  \\    \\/    /  \\    \\     \n");
  if(!b){
    printf("                                            /    /    \\    /   /    \\    \\ \n");
    printf("                                            \\    \\    /   /    \\    /    /\n");
  }else{
    printf("                                            /    /    \\   \\    /    \\    \\ \n");
    printf("                                            \\    \\    /    \\   \\    /    /\n");
  }
  printf("                                             \\    \\  /    /\\    \\  /    /\n");
  printf("                                              \\    \\/    /  \\    \\/    /\n");
  printf("                                               \\        /    \\        /\n");
  printf("                                                |      |      |      |                                                 \n");
  printf("        \n");
  printf("                                                    C             D                                                 \n");
}
