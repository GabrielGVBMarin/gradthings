#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
  char nome_atk[20];
  int poder_base;
  float accurace;
  char classe;
} ataque;

typedef struct  {
  int HP;
  int ataque;
  int defesa;
  int ataque_especial;
  int defesa_especial;
  int velocidade;
} atributos;

typedef struct  {
  char nome[50];
  char tipo_primario[20];
  char tipo_secundario[20];
  atributos attr;
  ataque atk[4];
} pokemon;

void adiciona_pokemon(pokemon*);
void add_ataque(pokemon*);
void imprimir_dados(pokemon*);
void imprimir_atk(pokemon*);

int main()  {
  int opt, contador = 0;
  pokemon *animal = NULL;
  // o numero 1 adiciona pokemons
  // 2 adiciona um ataque a um pokemon especifico
  // 3 imprime os dados de 1 pokemons
  // 4 imprimir os dados de um dado ataque especifico de pokemon
  do {
    scanf("%d", &opt);
    switch (opt) {
      case 1:
        contador++;
        animal = (pokemon*) realloc(animal, contador*sizeof(pokemon));
        adiciona_pokemon(&animal[contador-1]);

      break;
      case 2:
        add_ataque(animal);
      break;
      case 3:
        imprimir_dados(animal);
      break;
      case 4:
        imprimir_atk(animal);
      break;
      default:
      break;
    }
  } while(opt);

  free(animal);
  return 0;
}

void adiciona_pokemon(pokemon *ser) {

  scanf("%s", ser->nome);
  scanf("%s", ser->tipo_primario);
  scanf("%s", ser->tipo_secundario);
  scanf("%d %d %d %d %d %d", &ser->attr.HP, &ser->attr.ataque, &ser->attr.defesa, &ser->attr.ataque_especial, &ser->attr.defesa_especial, &ser->attr.velocidade);

}

void add_ataque(pokemon *ser) {

  int indice, indice_atk;
  scanf("%d %d", &indice, &indice_atk);
  scanf("%s %d %f %c", ser[indice].atk[indice_atk].nome_atk, &ser[indice].atk[indice_atk].poder_base, &ser[indice].atk[indice_atk].accurace, &ser[indice].atk[indice_atk].classe);

}

void imprimir_dados(pokemon *ser) {

  int indice;
  scanf("%d", &indice);

  printf("Nome do Pokemon: %s\n", ser[indice].nome);
  printf("Tipo primario: %s\n", ser[indice].tipo_primario);
  printf("Tipo secundario: %s\n", ser[indice].tipo_secundario);
  printf("Status:\n");
  printf("\tHP: %d\n", ser[indice].attr.HP);
  printf("\tAtaque: %d\n", ser[indice].attr.ataque);
  printf("\tDefesa: %d\n", ser[indice].attr.defesa);
  printf("\tAtaque Especial: %d\n", ser[indice].attr.ataque_especial);
  printf("\tDefesa Especial: %d\n", ser[indice].attr.defesa_especial);
  printf("\tVelocidade: %d\n\n", ser[indice].attr.velocidade);

}

void imprimir_atk(pokemon *ser) {
  int indice, indice_atk;
  scanf("%d %d", &indice, &indice_atk);
  printf("Nome do Ataque: %s\n", ser[indice].atk[indice_atk].nome_atk);
  printf("Poder base: %d\n", ser[indice].atk[indice_atk].poder_base);
  printf("Acuracia: %f\n", ser[indice].atk[indice_atk].accurace);
  printf("Classe: %c\n\n", ser[indice].atk[indice_atk].classe);
}
