//============================================================================
// Name        : laby.cpp
// Author      : Mateo A Zabala G
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

char labyrinth[35][35];
int m1[] = {-1,1,0,0};
int m2[] = {0,0,-1,1};
int contador = 0;

void llenadoLaby(int r,int c, int tam){
  if(r < 0 || r >= tam || c < 0 || c >= tam) return; 
  if(labyrinth[r][c] != '.') return;
  labyrinth[r][c] = 'g';
  for(int i = 0; i<4; i++){
     llenadoLaby(r + m1[i], c + m2[i],tam);
  }
  return;
}

void contador1(int tam){
  for(int i = 0; i<tam; i++){
    for(int j = 0; j<tam; j++){
      if(labyrinth[i][j] == 'g'){
	    if(labyrinth[i-1][j] != 'g'){
	     contador++;
	    }
	    if(labyrinth[i+1][j]!='g'){
	     contador++;
	    }
	    if(labyrinth[i][j-1]!='g'){
	     contador++;
	    }
	    if(labyrinth[i][j+1]!='g'){
	     contador++;
	    }
      }
    }
  }
  cout << (contador-4)*9;
}

int main(){
  
  int tam, contador = 0;
  string input;
  
  cin >> tam;
  getline(cin,input);
  
  for(int i = 0; i<tam; i++ ){
    getline(cin,input);
    
    for(int i = 0; i < input.size();i++){
      labyrinth[contador][i] = input[i];
    }
    contador++;
  }

 llenadoLaby(0,0,tam);
  if(labyrinth[tam-1][tam-1] != 'g'){
    llenadoLaby(tam-1,tam-1,tam);
  }
  
  contador1(tam);
  
  return 0;
}
