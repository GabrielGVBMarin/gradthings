#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sobrenome(char *);
void trocasnomes(char *Nome1, char *Nome2);

int main(void){
  /// ** Leitura
    char **nome = NULL,c;
    int tamVetor = 1, numNomes = 1,i,j;
    nome = (char**)realloc(nome,numNomes*sizeof(char*));
    nome[numNomes-1] = (char*)calloc(tamVetor,sizeof(char));

    c = getchar();
    while(c != '$'){
        if((int)c != 10){
            nome[numNomes-1][tamVetor-1] = c;
        }
        else{
            nome[numNomes-1][tamVetor-1] = '\0';
            numNomes += 1;
            nome = (char**)realloc(nome,numNomes*sizeof(char*));
            tamVetor = 0;
        }
        tamVetor += 1;
        nome[numNomes-1] = (char*)realloc(nome[numNomes-1],tamVetor*sizeof(char));
        c = getchar();
    }
    // fim da Leitura

  //  Processamento
    nome[numNomes-1] = (char*)realloc(nome[numNomes-1],(tamVetor+1)*sizeof(char));
    nome[numNomes-1][tamVetor+1] = '\0';
    for(i=0,j=numNomes-1; i<numNomes/2; i++, j--){
        trocasnomes(nome[i], nome[j]);
    }
    ///////


// printando os nomes :
    for(i=0;i<numNomes; i++)
    printf("%s\n", nome[i]);

// liberando o vetor :
  free(nome);
    return 0;
}

char * sobrenome(char * nome){
    char *sobrenome = NULL;
    int i, tam;
    tam = strlen(nome);
    /// ENCONTRANDO O SOBRENOME
    for(i=tam-1;i>=0;i--){
        if(nome[i] == ' '){
            sobrenome = &nome[i+1];
            break;
        }
    }
    return sobrenome;
}

void trocasnomes(char *Nome1, char *Nome2){
    char *Sobrenome1 = sobrenome(Nome1);
    char *Sobrenome2 = sobrenome(Nome2);
    /// realocando o tamanho dos ponteiros
    int TamNome1 = strlen(Nome1),TamNome2 = strlen(Nome2);
    int TamSobre1 = strlen(Sobrenome1), TamSobre2 = strlen(Sobrenome2);
    int TamFinal1 = TamNome1-TamSobre1+TamSobre2,TamFinal2 = TamNome2-TamSobre2+TamSobre1;
    Nome1 = (char*)realloc(Nome1, TamFinal1*sizeof(char));
    Nome2 = (char*)realloc(Nome2, TamFinal2*sizeof(char));
    ///
    int i, j;
    /// colocando o primeiro sobrenome
    for(i=TamNome1-TamSobre1, j=0; i<TamFinal1; i++,j++){
        Nome1[i] = Sobrenome2[j];
    }
    Nome1[i] = '\0';
    /// colocando o segundo sobrenome
    for(i=TamNome2-TamSobre2, j=0; i<TamFinal2; i++,j++){
         Nome2[i] = Sobrenome1[j];
    }
    Nome2[i] = '\0';
}
