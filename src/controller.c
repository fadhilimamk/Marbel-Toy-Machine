/*
Marble Toy Automata Machine
Author  : Fadhil Imam Kurnia - 13515146
Date    : 18 September 2016
File    : controller.c v1.00
Desc    : File to support main app, processing state
*/

#include "boolean.h"
#include <stdio.h>
#include "model.h"
#include <string.h>

char * transisi(DFA *dfa, char * init, char sigmax){
  int idx = 0 ;
  boolean found = false;

  while (idx < (*dfa).countDelta && !found) {
    if (strcmp((*dfa).delta[idx].istate,init) == 0 && (*dfa).delta[idx].sigma == sigmax) {
      found = true;
    }else{
      idx++;
    }
  }

  return (*dfa).delta[idx].fstate;

}

char * getInitialState(DFA *dfa){
  return (*dfa).Start;
}

boolean isFinal(DFA dfa, char * state){
    boolean found = false;
    int idx = 0;
    while (idx < dfa.countFinal) {
      if ((dfa.Final[idx], state) == 0 ) {
        found = true;
      }else{
        idx++;
      }
    }

    return found;
}

boolean isAlphabetValid(DFA dfa, char x){
  boolean found = false;
  int idx = 0;
  while (idx < dfa.countAlphabet) {
    if (dfa.Alphabet[idx] == x ) {
      found = true;
    }else{
      idx++;
    }
  }

  return found;
}

void proses(DFA *dfa, char * kalimat){
  char CState[4];
  char * X = getInitialState(&(*dfa));
  int i =0;
  int j;
  for (i = 0; i < 4; i++) {
    CState[i] = X[i];
  }
  printf("\n    %s\n", CState);
  for (i = 0; i < strlen(kalimat); i++) {
    X = transisi(&(*dfa), CState, kalimat[i]);
    for (j = 0; j < 4; j++) {
      CState[j] = X[j];
    }
    printf("    %s\n", CState);
  }

  strcpy(X, CState);

}

char * prosesFinal(DFA *dfa, char * kalimat){
  char CState[4];
  char * X = getInitialState(&(*dfa));
  int i =0;
  int j;
  for (i = 0; i < 4; i++) {
    CState[i] = X[i];
  }
  for (i = 0; i < strlen(kalimat); i++) {
    X = transisi(&(*dfa), CState, kalimat[i]);
    for (j = 0; j < 4; j++) {
      CState[j] = X[j];
    }
  }

  strcpy(X, CState);

  return X;
}


boolean isAccepted(char * state){
  return (state[3] == 'a');
}
