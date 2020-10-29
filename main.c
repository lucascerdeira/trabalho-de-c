#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

// Retorna a senha somente com números
char* PassNumeric(int Size) {
    char *ramdom_number;
    time_t seconds = time(NULL);
    ramdom_number = NULL;
    ramdom_number = (char *)realloc(ramdom_number, sizeof(char) * Size);
    srand(seconds * rand());
    for (int i = 0; i < Size; i++) {
        ramdom_number[i] = 48 + (rand() % 9);
    }
    return ramdom_number;
}

char* JuntaRaSenha(char *RA, char *Senha, int Size) {
    char *RaSenha;
    RaSenha = NULL;
    RaSenha = (char *)realloc(RaSenha, sizeof(char) * (Size + 8));
    strcat(RaSenha, RA);
    strcat(RaSenha, ";");
    strcat(RaSenha, Senha);
    strcat(RaSenha, ";");
    return RaSenha;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	printf("GRUPO 3.\nNOMES: \n");
	printf("========================\n");
	printf("André Corradi\n");
	printf("André de Lima\n"); 
	printf("Lucas Almeida Cerdeira \n");
	printf("Matheus Stankevicius \n");
	printf("========================\n\n");
    
	// Var 
	int Escolha_Usuario, i, Tamanho_Senha;
    char aux[7];

    // Ponteiro que recebe a resposta das funções
    char *Senha;

    // Pronteiro que recebe os RAs do arquivo
    char RA[7];

    // Ponteiro que recebe o RA e a Senha já unidos
    char *Ra_Senha;

    // Ponteiro para o arquivo de matriculas
    FILE *MATR_FILE;
    
	// Ponteiro para arquivo de senhas.txt
	FILE *SENHA_FILE;

    // Inicializando as variáveis
	Escolha_Usuario = 0;
    i = 0;
    Tamanho_Senha = 0; 
	Senha = NULL;
    Ra_Senha = NULL;
    MATR_FILE = NULL;
    SENHA_FILE = NULL;
	// Abre os arquivos
    MATR_FILE = fopen("MATR.txt", "r");
	SENHA_FILE = fopen("SENHAS.txt", "w");

    // Verifica se existe o arquivo
    if (MATR_FILE == NULL) {
        fclose(MATR_FILE);
        printf("Arquivo não encontrado ou inválido");
        return 1;
    }
	printf("Indique o número de caracteres (mínimo de 6 caracteres): ");
    while (i == 0) {
	    scanf("%d", &Tamanho_Senha);
        if (Tamanho_Senha >= 6) {
            i = 1;
        } else {
            printf("\nNúmero de caracteres inválido!\n");
            printf("Digite a quantidade de caracteres: ");
        }
    }

	printf("Escolha o tipo de senha que deseja gerar: \n");
	printf("1. Numérica – conterá apenas algarismos.\n");
	printf("2. Alfabética – conterá apenas letras maiúsculas e minúsculas.\n");
	printf("3. Alfanumérica 1 – conterá letras maiúsculas e algarismos.\n");
	printf("4. Alfanumérica 2 – conterá letras maiúsculas, minúsculas e algarismos.\n");
	printf("5. Geral – conterá letras maiúsculas, minúsculas, algarismos e os caracteres: +, -, _ , @, *, &, =, $, %%, &\n\n");
	
	printf("OPÇÃO: ");
	
    i = 0;
    while (i == 0) {
	    scanf("%d", &Escolha_Usuario);
        if (Escolha_Usuario <=0 || Escolha_Usuario >= 6) {
            printf("Opção incorreta!\n");
	        printf("OPÇÃO: ");
        } else {
            i = 1;
        }
    }
	i = 0;
	if( Escolha_Usuario == 1) {
        while (fscanf(MATR_FILE, "%s\n", aux) != EOF) {
            i++;
            strcpy(RA, aux);
            Senha = NULL;
            Senha = PassNumeric(Tamanho_Senha);
            Ra_Senha = NULL;
            Ra_Senha = (char *)realloc(Ra_Senha, sizeof(char) * (Tamanho_Senha + 8));
            Ra_Senha = JuntaRaSenha(RA, Senha, Tamanho_Senha);
		    fprintf(SENHA_FILE,"%s\n", Ra_Senha);
            free(Ra_Senha);
            free(Senha);
        }
	} else if (Escolha_Usuario == 2){
		printf("2\n");
		
	} else if (Escolha_Usuario == 3) {
		printf("3\n");
		
	} else if (Escolha_Usuario == 4) {
		printf("mangeur marié\n");

	} else if (Escolha_Usuario == 5) {
		printf("SUPER XANDÃO\n");
	}
	
	// TODO dar free() em todos os ponteiros!!!
    fclose(MATR_FILE);
    fclose(SENHA_FILE);
	return 0;
	
	
}