#include <stdio.h>  // biblioteca para entrada e saida padrao de fun��es.
#include <stdlib.h> // biblioteca para fun��es de aloca��o de mem�ria.
#include <locale.h> // biblioteca para configura��o de localidade (IDIOMA)
#include <string.h> // bilbioteca para manipula��o de strings
#include <sys/stat.h> // biblioteca para todo tipo de manipula��o de arquivos.

// Fun��o para verificar se o diret�rio existe, se n�o, cri�-lo
void cDiret(const char *nmDiret) {
    struct stat st = {0};
    if (stat(nmDiret, &st) == -1) {
        if (mkdir(nmDiret) == -1) {
            printf("Erro ao criar o diret�rio %s\n", nmDiret);
            exit(1);
        }
    }
}

// Fun��o Conferir se h� exist�ncia de CPF cadastrado para aluno
int cpfcad_a(const char *cpf){
    char arquivo[50];
    sprintf(arquivo, "ALUNOS/%s.txt", cpf);
    struct stat buffer;
    return (stat(arquivo, &buffer) == 0);
}

// Fun��o Conferir se h� exist�ncia de CPF cadastrado para professor
int cpfcad_p(const char *cpf){
    char arquivo[50];
    sprintf(arquivo, "PROFESSORES/%s.txt", cpf);
    struct stat buffer;
    return (stat(arquivo, &buffer) == 0);
}

// Fun��o de registro de aluno
void reg_aluno() {
    char nm[80], sbnm[80], cpf[40], curso[100];
    char resp;
    
    cDiret("ALUNOS");
    
    do {
    	setlocale(LC_ALL, "Portuguese");
    	
        // Captura das informa��es do aluno
        printf("###-- Cadastro de Aluno --###\n\n");
        
        printf("Agora, me diga o primeiro nome: ");
        scanf(" %79[^\n]", nm);
        getchar();
        
        printf("Agora me diga o sobrenome: ");
        fgets(sbnm, sizeof(sbnm), stdin);
        sbnm[strcspn(sbnm, "\n")] = '\0';
        
        printf("Agora, digite o CPF: ");
        scanf("%39s", cpf);
        
        
        // confer�ncia de CPF antes do cadastro, para n�o sobreescrever um cadastro antigo.
        if (cpfcad_a(cpf)) {
        	system("cls");
            printf("\n\nCPF j� cadastrado para aluno. Por favor, informe um CPF v�lido ou entre em contato com a Administra��o.\n\n\n");
            system("pause");
            system("cls");
            return;
        }
        
        while(getchar() != '\n');
        
        // Captando informa��es
        printf("Agora, me diga qual curso: ");
        fgets(curso, sizeof(curso), stdin);
        curso[strcspn(curso, "\n")] = '\0';
        system("cls");
        
        // sistema conferindo se foram preenchidos todos os campos
        if (strlen(nm) == 0 || strlen(sbnm) == 0 || strlen(cpf) == 0 || strlen(curso) == 0) {
        	printf("Por favor, preencha todos os campos. \n");
        	continue;
		}
		
		// confirma��o de dados fornecidos
		printf("\n Confirme os dados fonecidos: \n");
		printf("Nome: %s %s \n", nm, sbnm);
		printf("CPF: %s \n", cpf);
		printf("Curso: %s \n", curso);
		printf("\n Os dados est�o corretos? (S/N): ");
		scanf(" %c", &resp);
		system("cls");
		
		if (resp != 'S' && resp != 's') {
			printf("Cadastro cancelado. Voltando ao Menu Principal. \n");
			return;
		}
        
        // Salva os dados do aluno em um arquivo
        char arquivo[50];
        sprintf(arquivo, "ALUNOS/%s.txt", cpf);
        FILE *file = fopen(arquivo, "w");
        if (file == NULL){
            printf("Erro ao abrir o arquivo. Entre em contato com o suporte!\n"); // caso o arquivo n�o existir
            return;
        }
        // gravando os informa��es no arquivo
        fprintf(file, " Nome: %s %s \n CPF: %s \n Curso: %s \n\n\n", nm, sbnm, cpf, curso);
        fclose(file);
        
        // confirma��o de cadastro
        printf("Cadastro realizado com sucesso!\n\n");
        
        // perguntando se quer realizar outro cadastro, caso n�o ele volta ao menu principal
        printf("Deseja realizar outro cadastro de aluno? (S/N): ");
        getchar();
        resp = getchar();
        system("cls");
    
    } while (resp == 'S' || resp == 's');
}

// Fun��o de registro de professor
void reg_professor() {
    char nm[80], sbnm[80], cpf[40], curso[100];
    char resp;
    
    cDiret("PROFESSORES");
    
    do {
    	setlocale(LC_ALL, "Portuguese");
    	
        // Captura das informa��es do aluno
        printf("###-- Cadastro de Professores --###\n\n");
        
        printf("Agora, me diga o primeiro nome: ");
        scanf(" %79[^\n]", nm);
        getchar();
        
        printf("Agora me diga o sobrenome: ");
        fgets(sbnm, sizeof(sbnm), stdin);
        sbnm[strcspn(sbnm, "\n")] = '\0';
        
        printf("Agora, digite o CPF: ");
        scanf("%39s", cpf);
        
        // conferencia de CPF antes do cadastro, para n�o sobreescrever um cadastro antigo.
        if (cpfcad_p(cpf)) {
        	system("cls");
            printf("\n\n\nCPF j� cadastrado para professor. Por favor, informe um CPF v�lido ou entre em contato com a Administra��o.\n\n\n\n");
            system("pause");
            system("cls");
            return;
        }
        
        while(getchar() != '\n');
        
        // captando informa��es
        printf("Agora, me diga qual curso: ");
        fgets(curso, sizeof(curso), stdin);
        curso[strcspn(curso, "\n")] = '\0';
        system("cls");
        
        // sistema conferindo se foram preenchidos todos os campos
        if (strlen(nm) == 0 || strlen(sbnm) == 0 || strlen(cpf) == 0 || strlen(curso) == 0) {
        	printf("Por favor, preencha todos os campos. \n");
        	continue;
		}
		
		// confirma��o de dados fornecidos
		printf("\n Confirme os dados fonecidos: \n");
		printf("Nome: %s %s \n", nm, sbnm);
		printf("CPF: %s \n", cpf);
		printf("Curso: %s \n", curso);
		printf("\n Os dados est�o corretos? (S/N): ");
		scanf(" %c", &resp);
		system("cls");
		
		if (resp != 'S' && resp != 's') {
			printf("Cadastro cancelado. Voltando ao Menu Principal. \n");
			return;
		}
        
        // Salva os dados do aluno em um arquivo
        char arquivo[50];
        sprintf(arquivo, "PROFESSORES/%s.txt", cpf);
        FILE *file = fopen(arquivo, "w");
        if (file == NULL){
            printf("Erro ao abrir o arquivo. Entre em contato com o suporte!\n"); // caso o arquivo n�o existir
            return;
        }
        // gravando os informa��es no arquivo
        fprintf(file, " Nome: %s %s \n CPF: %s \n Curso: %s \n\n\n", nm, sbnm, cpf, curso);
        fclose(file);
        
        // confirma��o de cadastro
        printf("Cadastro realizado com sucesso!\n\n");
        
        // perguntando se quer realizar outro cadastro, caso n�o ele volta ao menu principal
        printf("Deseja realizar outro cadastro de professor? (S/N): ");
        getchar();
        resp = getchar();
        system("cls");
    
    } while (resp == 'S' || resp == 's');
}

// Fun��o de consulta de aluno
void con_aluno() {
	char cpf[40], cont[500], resp;
	
	do {
		printf("###-- Consulta de Alunos --###\n\n");
		printf("Para consultar um Aluno, digite o CPF cadastrado: ");
		scanf("%s", cpf);
		char arquivo[50];
		sprintf(arquivo, "ALUNOS/%s.txt", cpf);
	
		FILE *arq = fopen(arquivo, "r");
	
	// se n�o houver arquivo de aluno salvo/cadastrado
		if (arq == NULL) {
			system("cls");
			printf("\n\nAluno n�o encontrado. \n\n");
			system("pause");
			return;
			system("cls");
		}
		system("cls");
		printf("Essas s�o as informa��es do Aluno: \n\n");
	
		// mostrar dados consultados
		while (fgets(cont, sizeof(cont), arq) != NULL){
			printf("%s", cont);
		}
	
		fclose(arq);
		system("pause");
		system("cls");
		printf("\n\n Deseja realizar outra consulta ? (S/N): ");
		scanf(" %c", &resp);
		system("cls");
		
	} while (resp == 'S' || resp == 's');
}

// Fun��o de consulta de professor
void con_professor() {
	char cpf[40], cont[500], resp;
	
	do {
		printf("###-- Consulta de Professores --###\n\n");
		printf("Para consultar um Professor, digite o CPF cadastrado: ");
		scanf("%s", cpf);
		char arquivo[50];
		sprintf(arquivo, "PROFESSORES/%s.txt", cpf);
	
		FILE *arq = fopen(arquivo, "r");
	
	// se n�o houver arquivo de professor salvo/cadastrado
		if (arq == NULL) {
			system("cls");
			printf("\n\nProfessor n�o encontrado. \n\n");
			system("pause");
			return;
		}
		system("cls");
		printf("Essas s�o as informa��es do Professor: \n\n");
	
	// mostrar dados consultados
		while (fgets(cont, sizeof(cont), arq) != NULL){
			printf("%s", cont);
		}
	
		fclose(arq);
		system("pause");
		system("cls");
		printf("\n\n Deseja realizar outra consulta ? (S/N): ");
		scanf(" %c", &resp);
		system("cls");
		
	} while (resp == 'S' || resp == 's');
}

// Fun��o de exclus�o de cadastro de aluno
void del_aluno() {
    // Fun��o de Deletar Aluno da Lista de cadastro.
    char cpf[40];
    char resp;
    
    do {
    	printf("###-- Exclus�o de Cadastro de Aluno --###\n\n");
    	printf("Digite o CPF do aluno que deseja excluir: ");
    	scanf("%s", cpf);
    	system("cls");
    	
    	// Verificar se o aluno com o CPF fornecido existe
    	if (!cpfcad_a(cpf)) {
    		printf("Aluno com CPF %s n�o encontrado. \n", cpf);
    		return;
		}
		
		// Mostrar os dados do ALuno antes de confirmar a exclus�o
		printf("Confirme se este Aluno � o que deseja excluir: \n");
		char cont[500];
		char arquivo[50];
		sprintf(arquivo, "ALUNOS/%s.txt", cpf);
		FILE *arq = fopen(arquivo, "r");
		while (fgets(cont, sizeof(cont), arq) != NULL){
			printf("%s", cont);
		}
		fclose(arq);
		
		// Confirmar a exclus�o
		printf("\n Tem certeza que deseja excluir o Aluno com o CPF %s? (S/N): ", cpf);
		scanf(" %c", &resp);
		
		if (resp == 'S' || resp == 's') {
			 
			 
			 system("cls");
			 
			 // Remover o arquivo correspondente ao cadastro do Aluno.
			 if (remove(arquivo) == 0) {
			 	printf("Cadastro do Aluno com CPF %s excluido com sucesso! \n\n");
			 	system("pause");
				system("cls");
			
			 } else {
			 	printf("Erro ao excluir o cadastro, favor contatar Administra��o! \n\n ");
			 	system("pause");
				system("cls");
			
			 } 
		} else {
			printf("Exclus�o cancelada. \n\n");
		}
		
		printf("Deseja excluir outro cadastro de Aluno ? (S/N): ");
		scanf(" %c", &resp);
		
	} while (resp == 'S' || resp== 's');
}

// Fun��o de exclus�o de cadastro de professor
void del_professor() {
    // Fun��o de Deletar Professor da Lista de cadastro.
    char cpf[40];
    char resp;
    
    do {
    	printf("###-- Exclus�o de Cadastro de Professor --###\n\n");
    	printf("Digite o CPF do Professor que deseja excluir: ");
    	scanf("%s", cpf);
    	system("cls");
    	
    	// Verificar se o professor com o CPF fornecido existe
    	if (!cpfcad_p(cpf)) {
    		printf("Professor com CPF %s n�o encontrado. \n", cpf);
    		continue;
		}
		
		// Mostrar os dados do Professor antes de confirmar a exclus�o
		printf("Confirme se este Professor � o que deseja excluir: \n");
		char cont[500];
		char arquivo[50];
		sprintf(arquivo, "PROFESSORES/%s.txt", cpf);
		FILE *arq = fopen(arquivo, "r");
		while (fgets(cont, sizeof(cont), arq) != NULL){
			printf("%s", cont);
		}
		fclose(arq);
		
		// Confirmar a exclus�o
		printf("\n Tem certeza que deseja excluir o Professor com o CPF %s? (S/N): ", cpf);
		scanf(" %c", &resp);
		
		if (resp == 'S' || resp == 's') {
			 
			 
			 system("cls");
			 
			 // Remover o arquivo correspondente ao cadastro do Professor.
			 if (remove(arquivo) == 0) {
			 	printf("Cadastro do Professor com CPF %s excluido com sucesso! \n\n");
			 	system("pause");
				system("cls");
			
			 } else {
			 	printf("Erro ao excluir o cadastro, favor contatar Administra��o! \n\n ");
			 	system("pause");
				system("cls");
			
			 } 
		} else {
			printf("Exclus�o cancelada. \n\n");
		}
		
		printf("Deseja excluir outro cadastro de Professor ? (S/N): ");
		scanf(" %c", &resp);
		
	} while (resp == 'S' || resp== 's');
}

// Fun��o principal
int main(){
    int opcao, cont = 1;
    char nome[100];
    setlocale(LC_ALL, "Portuguese");
    char senhad[10];
    int comp;
    
    //Solicitando senha de Administrador
    printf("Seja bem-vindo ao Cart�rio de Alunos e Professores da EBAC!\n\n");
    printf("Login de Administrador! \n\nDigite a sua senha: ");
    scanf("%s", senhad);
    system("cls");
    
    // limpar o buffer de entrada
    while (getchar() != '\n');
    
    //Verificar se a senha fornecida � correta
    comp = strcmp(senhad, "admin");
    
    // Boas vindas e solicitar nome de usu�rio para melhor intera��o
    printf("Para come�ar, por favor, diga o seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    system("cls");
    
    //veerificar se a senha esta correta
    if(comp == 0)
	{
   		 // Boas vindas
    	printf("Ol� %s, espero que esteja tendo um �timo dia!\n\n", nome);
    	system("pause");
    	
    	// Menu principal
    	while (cont) {
    		system("cls");
        	printf("###-- Cart�rio EBAC --###\n\n");
        	printf("%s, escolha uma das op��es do menu abaixo:\n\n", nome);
        	printf("\t1 - Realizar Cadastro\n");
        	printf("\t2 - Realizar Consulta\n");
        	printf("\t3 - Excluir do Cart�rio\n");
        	printf("\t0 - Sair\n\n");
        	printf("Digite a op��o desejada: ");
        	scanf("%d", &opcao);
        	system("cls");
        
        	switch (opcao) {
            	case 1:
                	// Submenu de cadastro
                	printf("###-- Menu de Cadastro --###\n\n");
                	printf("%s, escolha o tipo de cadastro:\n\n", nome);
                	printf("\t1 - Cadastrar Aluno\n");
                	printf("\t2 - Cadastrar Professor\n");
                	printf("\t0 - Voltar ao Menu Principal\n\n");
                	printf("Digite a op��o desejada: ");
                	scanf("%d", &opcao);
                	system("cls");
                
                	switch (opcao) {
                    	case 1:
                       		reg_aluno();
                        	break;
                    	case 2:
                        	reg_professor();
                        	break;
                    	case 0:
                        	break;
                    	default:
                        	printf("Op��o inv�lida! Por favor, digite uma op��o v�lida.\n");
                        	system("pause");
                        	system("cls");
                        	break;
                	}
                	break;
            
            	case 2:
                	// Submenu de consulta
                	printf("###-- Menu de Consulta --###\n\n");
                	printf("%s , escolha o tipo de consulta:\n\n", nome);
                	printf("\t1 - Consultar Aluno\n");
                	printf("\t2 - Consultar Professor\n");
                	printf("\t0 - Voltar ao Menu Principal\n\n");
                	printf("Digite a op��o desejada: ");
                	scanf("%d", &opcao);
                	system("cls");
                
                	switch (opcao) {
                    	case 1:
                        	con_aluno();
                        	break;
                    	case 2:
                        	con_professor();
                        	break;
                    	case 0:
                        	break;
                    	default:
                        	printf("Op��o inv�lida! Por favor, digite uma op��o v�lida.\n");
                        	system("pause");
                        	system("cls");
                        	break;
                	}
                	break;
            
            	case 3:
                	// Submenu de exclus�o
                	printf("###-- Menu de Exclus�o --###\n\n");
                	printf("%s , escolha o tipo de cadastro a ser exclu�do:\n\n", nome);
                	printf("\t1 - Excluir Cadastro de Aluno\n");
                	printf("\t2 - Excluir Cadastro de Professor\n");
                	printf("\t0 - Voltar ao Menu Principal\n\n");
                	printf("Digite a op��o desejada: ");
                	scanf("%d", &opcao);
                	system("cls");

					// chamada de fun��es
                	switch (opcao) {
                    	case 1:
                        	del_aluno();
                        	break;
                    	case 2:
                        	del_professor();
                        	break;
                    	case 0:
                        	break;
                    	default:
                        	//printf("Op��o inv�lida! Por favor, digite uma op��o v�lida.\n");
                        	system("pause");
                        	system("cls");
                        	break;
                	}
                	break;
            
            	// ao finalizar o programa, uma mensagem de adeus
            	case 0:
                	cont = 0;
                	printf("%s , obrigado por utilizar nosso sistema! At� mais!\n", nome);
                	break;
            
            	// caso digitar op��es inv�lidas.
            	default:
                	printf("Op��o inv�lida! Por favor, digite uma op��o v�lida.\n");
                	system("pause");
                	system("cls");
                	break;
        	}
    	}
	}else{
		printf("Senha incorreta!");
	}
    // encerramento de programa
    return 0;
}

