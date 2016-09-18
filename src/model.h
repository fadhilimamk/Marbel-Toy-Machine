/*
Marble Toy Automata Machine
Author  : Fadhil Imam Kurnia - 13515146
Date    : 18 September 2016
File    : model.h v1.00
Desc    : File to support main app, connecting with data
*/

#ifndef MODEL_H
#define MODEL_H

#include "boolean.h"
#include <stdio.h>

typedef struct{
  char istate[20];
  char sigma;
  char fstate[20];
} DELTA;

typedef struct {
  char Alphabet[5];
  int countAlphabet;
  char *State[20];
  int countState;
  char Start[10];
  char *Final[20];
  int countFinal;
  DELTA delta[100];
  int countDelta;
} DFA;


void ReadFile(DFA *dfa);


#endif
