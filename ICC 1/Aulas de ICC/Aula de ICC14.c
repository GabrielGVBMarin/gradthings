#include <stdio.h>
#include <stdlib.h>

typedef struct{//estrutura pra guardar os dados do usuario
    int id;
    char nome[100];
    int idade;
    float salario;
}dados;

int id=0;//gambiarra pra salvar a qtd ja cadastrada(que no meu caso foi 3)
void cadastro_dados(char *);
void retorna_dados(char *);
void remove_dados(char *);
int menu();

int main()
{
    int op;
    //cadastro_dados("cadastro.txt");
    op=menu();
    while(op){
        switch(op){
            case 0: printf("Tchau!!!");
                break;
            case 1: cadastro_dados("cadastro.bin");
                break;
            case 2: retorna_dados("cadastro.bin");
                break;
            // case 3: remove_dados("cadastro.bin");
            //     break;
            /*case 4: altera_dados();
                break;*/
            default: printf ("Opção inválida");
        }
        op=menu();
    }
    return 0;
}
int menu(){//função pra mostrar o menu
    int op;
    printf("\n0-Sair\n1-Insere dados\n2-Retorna dados");
    printf("\n3-Remove dados\n4-Altera dados\nOpção:");
    scanf("%d", &op);
    return op;
}

void cadastro_dados(char *str){//função p cadastrar ou inserir dados
    FILE *arq;
    int sair=1;
    dados usr;
    arq=fopen(str, "ab+");//o a+ verifica se ja existe, se existir add no final, se não ele cria
    if(arq==NULL){
        printf("\nErro cadastro dados");
        exit(0);
    }
    do{
       printf("Nome:"); scanf(" %[^\n]s", usr.nome);
       printf("Idade:"); scanf(" %d", &usr.idade);
       printf("Salario:"); scanf(" %f", &usr.salario);
       usr.id = ++id;
       fwrite(&usr, sizeof(usr), 1, arq);
       printf("Digite 0 para sair:");
       scanf("%d", &sair);
    }while(sair);

    fclose(arq);

}

void retorna_dados(char *str){//função p retornar dados(mostrar o nome e salario do usuario buscado pelo id)
    FILE *arq;
    dados usr;
    int id;
    arq=fopen(str, "r");
    printf("Digite ID:"); scanf("%d", &id);
    while(fscanf(arq,"%d %[^\n]s", &usr.id, usr.nome)!=EOF){
        fscanf(arq,"%d %f", &usr.idade, &usr.salario);
        if (usr.id==id){
            printf("\n%s R$%.2f", usr.nome, usr.salario);
            break;
        }
    }
}
void remove_dados(char *str){//função p remover um dado ja cadastrado

    FILE *arq;
    dados usr;
    int id;
    int tam;
    arq=fopen(str, "rb+");
    printf("Digite ID a ser removido:"); scanf("%d", &id);
    while(fread(&usr, sizeof(usr), 1, arq)) {
        if (usr.id==id){
            tam+=sizeof(usr.id)+sizeof(usr.nome);
            fseek(arq, tam, SEEK_CUR);
            fprintf(arq, "%d %s", -1, usr.nome);
            break;
        }
        fscanf(arq,"%d %f", &usr.idade, &usr.salario);
        tam+= sizeof(usr);
    }
}
