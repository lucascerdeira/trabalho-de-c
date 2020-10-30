#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Retorna a senha somente com números
char* PassNumeric(int Size) {
    char *random_pass;
    time_t Time = time(NULL);
    random_pass = NULL;
    random_pass = (char *)realloc(random_pass, sizeof(char) * Size);
    srand(Time * rand());
    for (int i = 0; i < Size; i++) {
        random_pass[i] = 48 + (rand() % 10);
    }
    return random_pass;
}

char* PassAlfa(int Size) {
    int tipo = 0;
	char *random_pass;
    time_t seconds = time(NULL);
    random_pass  = NULL;
    random_pass = (char *)realloc(random_pass, sizeof(char) * Size);
    srand(seconds * rand());
    for (int i = 0; i < Size; i++){
    	tipo = rand() % 2;
    	if (tipo == 0) {
    		random_pass[i] = 65 + (rand() % 26);
		}
		else if (tipo == 1) {
			random_pass[i] = 97 + (rand() % 26);
		}
	}
	return random_pass;
}

char* PassAlfa1(int Size) {
    int tipo = 0;
	char *random_pass;
    time_t seconds = time(NULL);
    random_pass  = NULL;
    random_pass = (char *)realloc(random_pass, sizeof(char) * Size);
    srand(seconds * rand());
    for (int i = 0; i < Size; i++){
    	tipo = rand() % 2;
    	if (tipo == 0) {
    		random_pass[i] = 65 + (rand() % 26);
		}
		else if (tipo == 1) {
			random_pass[i] = 48 + (rand() % 10);
		}
	}
	return random_pass;
}

char* PassAlfa2(int Size) {
    int tipo = 0;
	char *random_pass;
    time_t seconds = time(NULL);
    random_pass  = NULL;
    random_pass = (char *)realloc(random_pass, sizeof(char) * Size);
    srand(seconds * rand());
    for (int i = 0; i < Size; i++){
    	tipo = rand() % 3;
    	if (tipo == 0) {
    		random_pass[i] = 65 + (rand() % 26);
		}
		else if (tipo == 1) {
			random_pass[i] = 97 + (rand() % 26);
		}
		else if (tipo == 2) {
			random_pass[i] = 48 + (rand() % 10);
		}
	}
	return random_pass;
}

char* PassGeral(int Size) {
    char especiais[10] = {43, 45, 95, 64, 42, 38, 61, 36, 37};
    char *random_pass;
    int caracter_especial = 0;
    int tipo = 0;
    time_t Time = time(NULL);
    random_pass = NULL;
    random_pass = (char *)realloc(random_pass, sizeof(char) * Size);
    srand(Time * rand());
    for (int i = 0; i < Size; i++) {
        tipo = rand() % 4;
        if (tipo == 0) {
            random_pass[i] = 65 + (rand() % 26);
        } else if (tipo == 1) {
            random_pass[i] = 97 + (rand() % 26);
        } else if (tipo == 2) {
            random_pass[i] = 48 + (rand() % 10);
        } else {
            caracter_especial = rand() % 9;
            random_pass[i] = especiais[caracter_especial];
        }
    }
    return random_pass;
}

int main() {
	printf("GRUPO 3.\nNOMES: \n");
	printf("========================\n");
	printf("André Corradi\n");
	printf("André de Lima\n"); 
	printf("Lucas Almeida Cerdeira \n");
	printf("Matheus Stankevicius \n");
	printf("========================\n\n");
    
	// Var 
	int Escolha_Usuario, i, Tamanho_Senha;

    // Ponteiro que recebe a resposta das funções
    char *Senha;

    // Pronteiro que recebe os RAs do arquivo
    char RA[7];

    // Ponteiro para o arquivo de matriculas
    FILE *MATR_FILE;
    
	// Ponteiro para arquivo de senhas.txt
	FILE *SENHA_FILE;

    // Inicializando as variáveis
	Escolha_Usuario = 0;
    i = 0;
    Tamanho_Senha = 0; 
	Senha = NULL;
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
	if( Escolha_Usuario == 1) {
        while (fscanf(MATR_FILE, "%s\n", RA) != EOF) {
            Senha = NULL;
            Senha = PassNumeric(Tamanho_Senha);
		    fprintf(SENHA_FILE,"%s;%s;\n", RA, Senha);
            free(Senha);
        }
	} else if (Escolha_Usuario == 2){
		while (fscanf(MATR_FILE, "%s\n", RA) != EOF) {
            Senha = NULL;
            Senha = PassAlfa(Tamanho_Senha);
		    fprintf(SENHA_FILE,"%s;%s;\n", RA, Senha);
            free(Senha);
        }
	} else if (Escolha_Usuario == 3) {
		while (fscanf(MATR_FILE, "%s\n", RA) != EOF) {
            Senha = NULL;
            Senha = PassAlfa1(Tamanho_Senha);
		    fprintf(SENHA_FILE,"%s;%s;\n", RA, Senha);
            free(Senha);
        }
	} else if (Escolha_Usuario == 4) {
		while (fscanf(MATR_FILE, "%s\n", RA) != EOF) {
            Senha = NULL;
            Senha = PassAlfa2(Tamanho_Senha);
		    fprintf(SENHA_FILE,"%s;%s;\n", RA, Senha);
            free(Senha);
        }
	} else if (Escolha_Usuario == 5) {
		while (fscanf(MATR_FILE, "%s\n", RA) != EOF) {
            Senha = NULL;
            Senha = PassGeral(Tamanho_Senha);
		    fprintf(SENHA_FILE,"%s;%s;\n", RA, Senha);
            free(Senha);
        }
	}
    fclose(MATR_FILE);
    fclose(SENHA_FILE);
	return 0;
}