/*
Marble Toy Automata Machine
Author  : Fadhil Imam Kurnia - 13515146
Date    : 18 September 2016
File    : model.c v1.00
Desc    : File to support main app, connecting with data
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "model.h"

void ReadFile(DFA * dfa){
  FILE *file;
  char buff[255];
  char temp[255];
  char alphabet[255];
  int i,j=0,count = 0;


  file = fopen("..//src//data//language.dfa", "r");
  // baca alfabet
  fgets(buff, 255, (FILE*)file);
  strncpy(temp, buff, 12  );temp[12]='\0';
  if (strcmp(temp,"alphabet : {")==0) {
    i = 12;
    while(buff[i]!='}'){
      if (buff[i]!=',') {
        (*dfa).Alphabet[count]=buff[i];
        count++;
      }
      i++;
    }
    (*dfa).countAlphabet = count;
  }else{
    printf("terjadi kesalahan saat pembacaan file\n");
    exit(0);
  }

  // baca state
  fgets(buff, 255, (FILE*)file);count=0;
  strncpy(temp, buff, 9  );temp[9]='\0';
  if (strcmp(temp,"state : {")==0) {
    memset(temp, 0, sizeof(temp));  //reset memori temp karena akan dipakai ulang
    i=9;
    while (buff[i]!='}') {
      if(buff[i]!=','){
        temp[j] = buff[i];
        j++;
      }else{
        j=0;
        (*dfa).State[count] = (char*)malloc(sizeof(temp));
        strcpy((*dfa).State[count], temp);
        count++;
      }
      i++;
    }
    (*dfa).countState = count +1;
  }else{
    printf("terjadi kesalahan saat pembacaan file\n");
    exit(0);
  }

  //baca Start
  fgets(buff, 255, (FILE*)file);count=0;
  strncpy(temp, buff, 8  );temp[8]='\0';
  if (strcmp(temp,"start : ")==0) {
    memset(temp, 0, sizeof(temp));
    memcpy( (*dfa).Start, &buff[8], strlen(buff) );
  }else{
    printf("terjadi kesalahan saat pembacaan file\n");
    exit(0);
  }

  // baca final
  fgets(buff, 255, (FILE*)file);count=0;
  strncpy(temp, buff, 9  );temp[9]='\0';
  if (strcmp(temp,"final : {")==0) {
    memset(temp, 0, sizeof(temp));  //reset memori temp karena akan dipakai ulang
    i=9;j=0;
    while (buff[i]!='}') {
      if(buff[i]!=','){
        temp[j] = buff[i];
        j++;
      }else{
        j=0;
        (*dfa).Final[count] = (char*)malloc(sizeof(temp));
        strcpy((*dfa).Final[count], temp);
        count++;
      }
      i++;
    }
    (*dfa).countDelta = count;
  }else{
    printf("terjadi kesalahan saat pembacaan file\n");
    exit(0);
  }

  // baca delta
  fgets(buff, 255, (FILE*)file);count=0;
  strncpy(temp, buff, 7  );temp[7]='\0';
  if (strcmp(temp,"delta :")==0) {
    boolean a = false, b= false,c = false;
    fgets(buff, 255, (FILE*)file);
    count=0;
    while(!feof((FILE*)file)){
      memset(temp, 0, sizeof(temp));
      i=1;j=0;
      while(buff[i]!=')'){
        if(buff[i]=='|'){
          strcpy((*dfa).delta[count].istate, temp);
          j=0;
        }
        if(buff[i]=='='){
          (*dfa).delta[count].sigma = temp[j-1];
          j=0;
          i++;
        }
        temp[j] = buff[i];
        i++;j++;
      }
      strcpy((*dfa).delta[count].fstate, temp);
      count++;
      fgets(buff, 255, (FILE*)file);
    }
    (*dfa).countDelta = count;

  }else{
    printf("terjadi kesalahan saat pembacaan file\n");
    exit(0);
  }


  fclose(file);

}
