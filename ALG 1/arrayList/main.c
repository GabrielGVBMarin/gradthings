// Gabriel Guimarães Vilas Boas Marin 11218521
#include <stdio.h>
#include <stdlib.h>
#include <biblio.h>

int main(void)  {
  ArrayList *mainList = NULL;
  char *opt = NULL;
  int *vars = NULL;

  mainList = new_arrayList();
  opt = leString();

  while(strcmp(opt, "sair"))  {
    // COMPARA A STRING COM O COMANDO PARA EXECUTAR O QUE FOI PEDIDO
    if (!strcmp(opt, "add")) {

      vars = (int*) realloc(vars, 2*sizeof(int));
      scanf("%d %d", &vars[0], &vars[1]);
      add_arrayList(mainList, &vars[1], &vars[0]);

    } else if (!strcmp(opt, "tamanho")) {

      printf("%d\n", size_arrayList(mainList));

    } else if (!strcmp(opt, "sub")) {

      vars = (int*) realloc(vars, 2*sizeof(int));
      ArrayList *sub = NULL;
      scanf("%d %d", &vars[0], &vars[1]);
      sub = subArray_arrayList(mainList, vars[0], vars[1]);
      print_arrayList(sub);
      free_arrayList(sub);

    } else if (!strcmp(opt, "set")) {

      vars = (int*) realloc(vars, 3*sizeof(int));
      scanf("%d %d %d", &vars[0], &vars[1], &vars[2]);
      sort_arrayList(mainList);
      set_arrayList(mainList, vars[0], &vars[2], &vars[1]);

    } else if (!strcmp(opt, "print")) {

      sort_arrayList(mainList);
      print_arrayList(mainList);

    } else if (!strcmp(opt, "contem")) {

      vars = (int*) realloc(vars, 1*sizeof(int));
      scanf("%d", &vars[0]);
      printf("%d\n", contains_arrayList(mainList, vars[0]));

    } else if (!strcmp(opt, "indice"))  {

      vars = (int*) realloc(vars, 2*sizeof(int));
      scanf("%d", &vars[0]);
      vars[1] = indexOf_arrayList(mainList, vars[0]);
      if (vars[1] != -3)  {
        printf("%d\n", vars[1]);
      }

    } else if (!strcmp(opt, "vazia")) {

      printf("%d\n", isEmpty_arrayList(mainList));

    } else if (!strcmp(opt, "remover")) {

      vars = (int*) realloc(vars, 1*sizeof(int));
      scanf("%d", &vars[0]);
      remove_arrayList(&mainList, vars[0]);

    } else if (!strcmp(opt, "get")) {

      vars = (int*) realloc(vars, 1*sizeof(int));
      scanf("%d", &vars[0]);
      get_arrayList(mainList, vars[0]);

    }
    opt = leString();
  }

  // FAZER FREE
  free_arrayList(mainList);
  if (!vars)  free(vars);
  free(opt);

  return 0;

}
