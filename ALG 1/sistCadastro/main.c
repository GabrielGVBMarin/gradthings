#include <stdio.h>
#include <stdlib.h>
#include <biblio.h>

// Gabriel Guimarães Vilas Boas Marin NUSP: 11218521

int main(void)  {

  // DECLARA A LISTA
  MENU List;
  unsigned char sair = 0;
  List.counter = 0;
  List.first = NULL;
  List.last = NULL;

 // ENQUANTO A FLAG DE SAIR N FOR MARCADA
 // O WHILE PERMANECE PEDINDO NOVOS COMANDOS DO USUARIO
  while(!sair)  {
    // VERIFICA APENAS A 1 LETRA DO COMANDO, E JÁ DEFINE QUAL É POR ELA
    switch (leOperation()) {
      case 'c':
        makeCadastro(&List);
      break;
      case 'b':
        buscaCPF(&List);
      break;
      case 'd':
        makeDump(&List);
      break;
      case 's':
        sair = exitProgram(&List);
      break;
      case 'r':
        makeRemove(&List);
      break;
    }
  }

  return 0;

}
