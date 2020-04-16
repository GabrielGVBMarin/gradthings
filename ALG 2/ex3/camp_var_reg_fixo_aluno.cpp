#include<stdio.h>
#include<string.h>

#define MAX 10

struct endereco {
    char nome[15];
    char sobrenome[15];
    char rua[25];
    int numero;
} e[MAX] = {{"Joao", "Souza", "XV Novembro", 151},
            {"Eduardo", "Martins", "Sao Sebastiao", 201},
            {"Maria", "Caldas", "Aquidabam", 45},
            {"Janaina", "Souto", "Narciso Romano", 5567},
            {"Elisa", "Milare", "Coronal Spinola", 420},
            {"Claudia", "Ferraz", "25 de marco", 311},
            {"Diogo", "Oliveira", "Santiago Sanches", 1000},
            {"Rafael", "Soares", "Sgt. Menezes", 501},
            {"Cristiano", "Facelli", "Larga", 40},
            {"Paulo", "Kuhl", "13 de maio", 1004}};

void camp_var_reg_fixo(endereco e, char *buffer) {    
    sprintf(buffer, "%s|%s|%s|%d|", e.nome, e.sobrenome, e.rua, e.numero); 
}

char *parser(char *buffer, int *pos) {
    int posi = *pos; 
    
    while(buffer[*pos]!='|')
        (*pos)++;
    buffer[*pos] = '\0'; 
    (*pos)++;   
    return &buffer[posi];
}

int main() {
    FILE *fd;
    
    struct endereco e2;
    char buffer[1000];
    int i, pos;
    
    fd = fopen("campo_var_reg_fixo.dad", "w+b");
  
     
  
    fclose(fd);

    getchar();
}
