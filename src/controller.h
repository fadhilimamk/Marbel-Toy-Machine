/*
Marble Toy Automata Machine
Author  : Fadhil Imam Kurnia - 13515146
Date    : 18 September 2016
File    : controller.h v1.00
Desc    : File to support main app, processing state
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "boolean.h"
#include <stdio.h>
#include "model.h"

char * transisi(DFA *dfa, char * init, char sigmax);

char * getInitialState(DFA *dfa);

boolean isFinal(DFA dfa, char * state);

boolean isAlphabetValid(DFA dfa, char x);

void proses(DFA *dfa, char * kalimat);

char * prosesFinal(DFA *dfa, char * kalimat);

boolean isAccepted(char * state);


#endif
