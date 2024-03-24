#include <stdio.h>  // biblioteca para entrada e saida padrao de funções.
#include <stdlib.h> // biblioteca para funções de alocação de memória.
#include <locale.h> // biblioteca para configuração de localidade (IDIOMA)
#include <string.h> // bilbioteca para manipulação de strings
#include <sys/stat.h> // biblioteca para todo tipo de manipulação de arquivos.

// Função para verificar se o diretório existe, se não, criá-lo
void cDiret(const char *nmDiret) {
    struct stat st = {0};
    if (stat(nmDiret, &st) == -1) {
        if (mkdir(nmDiret) == -1) {
            printf("Erro ao criar o diretório %s\n", nmDiret);
            exit(1);
        }
    }
}

// Função Conferir se há existência de CPF cadastrado para aluno
int cpfcad_a(const char *cpf){
    char arquivo[50];
    sprintf(arquivo, "ALUNOS/%s.txt", cpf);
    struct stat buffer;
    return (stat(arquivo, &buffer) == 0);
}

// Função Conferir se há existência de CPF cadastrado para professor
int cpfcad_p(const char *cpf){
    char arquivo[50];
    sprintf(arquivo, "PROFESSORES/%s.txt", cpf);
    struct stat buffer;
    return (stat(arquivo, &buffer) == 0);
}

// Função de registro de aluno
void reg_aluno() {
    char nm[80], sbnm[80], cpf[40], curso[100];
    char resp;
    
    cDiret("ALUNOS");
    
    do {
    	setlocale(LC_ALL, "Portuguese");
    	
        // Captura das informações do aluno
        printf("###-- Cadastro de Aluno --###\n\n");
        
        printf("Agora, me diga o primeiro nome: ");
        scanf(" %79[^\n]", nm);
        getchar();
        
        printf("Agora me diga o sobrenome: ");
        fgets(sbnm, sizeof(sbnm), stdin);
        sbnm[strcspn(sbnm, "\n")] = '\0';
        
        printf("Agora, digite o CPF: ");
        scanf("%39s", cpf);
        
        
        // conferÊncia de CPF antes do cadastro, para não sobreescrever um cadastro antigo.
        if (cpfcad_a(cpf)) {
        	system("cls");
            printf("\n\nCPF já cadastrado para aluno. Por favor, informe um CPF válido ou entre em contato com a Administração.\n\n\n");
            system("pause");
            system("cls");
            return;
        }
        
        while(getchar() != '\n');
        
        // Captando informações
        printf("Agora, me diga qual curso: ");
        fgets(curso, sizeof(curso), stdin);
        curso[strcspn(curso, "\n")] = '\0';
        system("cls");
        
        // sistema conferindo se foram preenchidos todos os campos
        if (strlen(nm) == 0 || strlen(sbnm) == 0 || strlen(cpf) == 0 || strlen(curso) == 0) {
        	printf("Por favor, preencha todos os campos. \n");
        	continue;
		}
		
		// confirmação de dados fornecidos
		printf("\n Confirme os dados fonecidos: \n");
		printf("Nome: %s %s \n", nm, sbnm);
		printf("CPF: %s \n", cpf);
		printf("Curso: %s \n", curso);
		printf("\n Os dados estão corretos? (S/N): ");
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
            printf("Erro ao abrir o arquivo. Entre em contato com o suporte!\n"); // caso o arquivo não existir
            return;
        }
        // gravando os informações no arquivo
        fprintf(file, " Nome: %s %s \n CPF: %s \n Curso: %s \n\n\n", nm, sbnm, cpf, curso);
        fclose(file);
        
        // confirmação de cadastro
        printf("Cadastro realizado com sucesso!\n\n");
        
        // perguntando se quer realizar outro cadastro, caso não ele volta ao menu principal
        printf("Deseja realizar outro cadastro de aluno? (S/N): ");
        getchar();
        resp = getchar();
        system("cls");
    
    } while (resp == 'S' || resp == 's');
}

// Função de registro de professor
void reg_professor() {
    char nm[80], sbnm[80], cpf[40], curso[100];
    char resp;
    
    cDiret("PROFESSORES");
    
    do {
    	setlocale(LC_ALL, "Portuguese");
    	
        // Captura das informações do aluno
        printf("###-- Cadastro de Professores --###\n\n");
        
        printf("Agora, me diga o primeiro nome: ");
        scanf(" %79[^\n]", nm);
        getchar();
        
        printf("Agora me diga o sobrenome: ");
        fgets(sbnm, sizeof(sbnm), stdin);
        sbnm[strcspn(sbnm, "\n")] = '\0';
        
        printf("Agora, digite o CPF: ");
        scanf("%39s", cpf);
        
        // conferencia de CPF antes do cadastro, para não sobreescrever um cadastro antigo.
        if (cpfcad_p(cpf)) {
        	system("cls");
            printf("\n\n\nCPF já cadastrado para professor. Por favor, informe um CPF válido ou entre em contato com a Administração.\n\n\n\n");
            system("pause");
            system("cls");
            return;
        }
        
        while(getchar() != '\n');
        
        // captando informações
        printf("Agora, me diga qual curso: ");
        fgets(curso, sizeof(curso), stdin);
        curso[strcspn(curso, "\n")] = '\0';
        system("cls");
        
        // sistema conferindo se foram preenchidos todos os campos
        if (strlen(nm) == 0 || strlen(sbnm) == 0 || strlen(cpf) == 0 || strlen(curso) == 0) {
        	printf("Por favor, preencha todos os campos. \n");
        	continue;
		}
		
		// confirmação de dados fornecidos
		printf("\n Confirme os dados fonecidos: \n");
		printf("Nome: %s %s \n", nm, sbnm);
		printf("CPF: %s \n", cpf);
		printf("Curso: %s \n", curso);
		printf("\n Os dados estão corretos? (S/N): ");
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
            printf("Erro ao abrir o arquivo. Entre em contato com o suporte!\n"); // caso o arquivo não existir
            return;
        }
        // gravando os informações no arquivo
        fprintf(file, " Nome: %s %s \n CPF: %s \n Curso: %s \n\n\n", nm, sbnm, cpf, curso);
        fclose(file);
        
        // confirmação de cadastro
        printf("Cadastro realizado com sucesso!\n\n");
        
        // perguntando se quer realizar outro cadastro, caso não ele volta ao menu principal
        printf("Deseja realizar outro cadastro de professor? (S/N): ");
        getchar();
        resp = getchar();
        system("cls");
    
    } while (resp == 'S' || resp == 's');
}

// Função de consulta de aluno
void con_aluno() {
	char cpf[40], cont[500], resp;
	
	do {
		printf("###-- Consulta de Alunos --###\n\n");
		printf("Para consultar um Aluno, digite o CPF cadastrado: ");
		scanf("%s", cpf);
		char arquivo[50];
		sprintf(arquivo, "ALUNOS/%s.txt", cpf);
	
		FILE *arq = fopen(arquivo, "r");
	
	// se não houver arquivo de aluno salvo/cadastrado
		if (arq == NULL) {
			system("cls");
			printf("\n\nAluno não encontrado. \n\n");
			system("pause");
			return;
			system("cls");
		}
		system("cls");
		printf("Essas são as informações do Aluno: \n\n");
	
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

// Função de consulta de professor
void con_professor() {
	char cpf[40], cont[500], resp;
	
	do {
		printf("###-- Consulta de Professores --###\n\n");
		printf("Para consultar um Professor, digite o CPF cadastrado: ");
		scanf("%s", cpf);
		char arquivo[50];
		sprintf(arquivo, "PROFESSORES/%s.txt", cpf);
	
		FILE *arq = fopen(arquivo, "r");
	
	// se não houver arquivo de professor salvo/cadastrado
		if (arq == NULL) {
			system("cls");
			printf("\n\nProfessor não encontrado. \n\n");
			system("pause");
			return;
		}
		system("cls");
		printf("Essas são as informações do Professor: \n\n");
	
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

// Função de exclusão de cadastro de aluno
void del_aluno() {
    // Função de Deletar Aluno da Lista de cadastro.
    char cpf[40];
    char resp;
    
    do {
    	printf("###-- Exclusão de Cadastro de Aluno --###\n\n");
    	printf("Digite o CPF do aluno que deseja excluir: ");
    	scanf("%s", cpf);
    	system("cls");
    	
    	// Verificar se o aluno com o CPF fornecido existe
    	if (!cpfcad_a(cpf)) {
    		printf("Aluno com CPF %s não encontrado. \n", cpf);
    		return;
		}
		
		// Mostrar os dados do ALuno antes de confirmar a exclusão
		printf("Confirme se este Aluno é o que deseja excluir: \n");
		char cont[500];
		char arquivo[50];
		sprintf(arquivo, "ALUNOS/%s.txt", cpf);
		FILE *arq = fopen(arquivo, "r");
		while (fgets(cont, sizeof(cont), arq) != NULL){
			printf("%s", cont);
		}
		fclose(arq);
		
		// Confirmar a exclusão
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
			 	printf("Erro ao excluir o cadastro, favor contatar Administração! \n\n ");
			 	system("pause");
				system("cls");
			
			 } 
		} else {
			printf("Exclusão cancelada. \n\n");
		}
		
		printf("Deseja excluir outro cadastro de Aluno ? (S/N): ");
		scanf(" %c", &resp);
		
	} while (resp == 'S' || resp== 's');
}

// Função de exclusão de cadastro de professor
void del_professor() {
    // Função de Deletar Professor da Lista de cadastro.
    char cpf[40];
    char resp;
    
    do {
    	printf("###-- Exclusão de Cadastro de Professor --###\n\n");
    	printf("Digite o CPF do Professor que deseja excluir: ");
    	scanf("%s", cpf);
    	system("cls");
    	
    	// Verificar se o professor com o CPF fornecido existe
    	if (!cpfcad_p(cpf)) {
    		printf("Professor com CPF %s não encontrado. \n", cpf);
    		continue;
		}
		
		// Mostrar os dados do Professor antes de confirmar a exclusão
		printf("Confirme se este Professor é o que deseja excluir: \n");
		char cont[500];
		char arquivo[50];
		sprintf(arquivo, "PROFESSORES/%s.txt", cpf);
		FILE *arq = fopen(arquivo, "r");
		while (fgets(cont, sizeof(cont), arq) != NULL){
			printf("%s", cont);
		}
		fclose(arq);
		
		// Confirmar a exclusão
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
			 	printf("Erro ao excluir o cadastro, favor contatar Administração! \n\n ");
			 	system("pause");
				system("cls");
			
			 } 
		} else {
			printf("Exclusão cancelada. \n\n");
		}
		
		printf("Deseja excluir outro cadastro de Professor ? (S/N): ");
		scanf(" %c", &resp);
		
	} while (resp == 'S' || resp== 's');
}

// Função principal
int main(){
    int opcao, cont = 1;
    char nome[100];
    setlocale(LC_ALL, "Portuguese");
    char senhad[10];
    int comp;
    
    //Solicitando senha de Administrador
    printf("Seja bem-vindo ao Cartório de Alunos e Professores da EBAC!\n\n");
    printf("Login de Administrador! \n\nDigite a sua senha: ");
    scanf("%s", senhad);
    system("cls");
    
    // limpar o buffer de entrada
    while (getchar() != '\n');
    
    //Verificar se a senha fornecida é correta
    comp = strcmp(senhad, "admin");
    
    // Boas vindas e solicitar nome de usuário para melhor interação
    printf("Para começar, por favor, diga o seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    system("cls");
    
    //veerificar se a senha esta correta
    if(comp == 0)
	{
   		 // Boas vindas
    	printf("Olá %s, espero que esteja tendo um ótimo dia!\n\n", nome);
    	system("pause");
    	
    	// Menu principal
    	while (cont) {
    		system("cls");
        	printf("###-- Cartório EBAC --###\n\n");
        	printf("%s, escolha uma das opções do menu abaixo:\n\n", nome);
        	printf("\t1 - Realizar Cadastro\n");
        	printf("\t2 - Realizar Consulta\n");
        	printf("\t3 - Excluir do Cartório\n");
        	printf("\t0 - Sair\n\n");
        	printf("Digite a opção desejada: ");
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
                	printf("Digite a opção desejada: ");
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
                        	printf("Opção inválida! Por favor, digite uma opção válida.\n");
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
                	printf("Digite a opção desejada: ");
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
                        	printf("Opção inválida! Por favor, digite uma opção válida.\n");
                        	system("pause");
                        	system("cls");
                        	break;
                	}
                	break;
            
            	case 3:
                	// Submenu de exclusão
                	printf("###-- Menu de Exclusão --###\n\n");
                	printf("%s , escolha o tipo de cadastro a ser excluído:\n\n", nome);
                	printf("\t1 - Excluir Cadastro de Aluno\n");
                	printf("\t2 - Excluir Cadastro de Professor\n");
                	printf("\t0 - Voltar ao Menu Principal\n\n");
                	printf("Digite a opção desejada: ");
                	scanf("%d", &opcao);
                	system("cls");

					// chamada de funções
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
                        	//printf("Opção inválida! Por favor, digite uma opção válida.\n");
                        	system("pause");
                        	system("cls");
                        	break;
                	}
                	break;
            
            	// ao finalizar o programa, uma mensagem de adeus
            	case 0:
                	cont = 0;
                	printf("%s , obrigado por utilizar nosso sistema! Até mais!\n", nome);
                	break;
            
            	// caso digitar opções inválidas.
            	default:
                	printf("Opção inválida! Por favor, digite uma opção válida.\n");
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

