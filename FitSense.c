#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_ALUNOS 100
#define MAX_PLANOS 10
#define MAX_FREQUENCIA 500
#define MAX_AULAS 50
#define MAX_INSTRUTORES 50


// ------------------------ ESTRUTURAS ------------------------ 

typedef struct {
    int id;
    char nome[50];
    char data_nascimento[11];
    char email[50];
    char telefone[15];
} Aluno;

typedef struct {
    int id;
    char nome[50];
    char descricao[400];
    float preco;
} Plano;

typedef struct {
    int id;
    int id_aluno;
    char data[11];
    char presenca;
} Frequencia;

typedef struct {
    int id;
    char nome[50];
    char instrutor[50];
    char horario[10];
} Aula;

typedef struct {
	char nome[50];
} Instrutor;



// ------------------------ VARIÁVEIS GLOBAIS -------------------------

Aluno alunos[MAX_ALUNOS];
int total_alunos = 0;

Plano planos[MAX_PLANOS];
int total_planos = 0;

Frequencia frequencia[MAX_FREQUENCIA];
int total_frequencia = 0;

Aula aulas[MAX_AULAS];
int total_aulas = 0;

Instrutor instrutores[MAX_INSTRUTORES];
int total_instrutores = 0;



// ------------------------ FUNÇÕES DE CADASTRO ------------------------ 

void cadastrarAluno() {
	
	setlocale(LC_ALL, "");
	system("cls");
	
    Aluno aluno;
    int i;

	
    printf("------------------- CADASTRO DE ALUNO -----------------\n\n");
    
    printf("ID do aluno: ");
    scanf("%d", &aluno.id);
    
    // Verifica se o ID já está cadastrado no sistema
    for (i = 0; i < total_alunos; i++) {
        if (alunos[i].id == aluno.id) {
        	system("cls");
        	
            printf("\nATENÇÃO: ID DE ALUNO JÁ CADASTRADO NO SISTEMA!\a\n");
            printf("                       ( >_< )                          ");
            printf("\nPor favor, realize um novo cadastro com outro ID de Aluno.\n\n");
            
            system("pause");
            system("cls");
            return;
        }
    }
    
    printf("Nome completo: ");
    scanf(" %[^\n]", aluno.nome);
    
    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf(" %[^\n]", aluno.data_nascimento);
    
    printf("Endereço de email: ");
    scanf(" %[^\n]", aluno.email);
    
    printf("Número de telefone: ");
    scanf(" %[^\n]", aluno.telefone);
    
    alunos[total_alunos] = aluno;
    total_alunos++;
    
    printf("\n-------------------------------------------------------\n\n");
    printf("ALUNO CADASTRADO COM SUCESSO!\n\n");
    
    system("pause");
    system("cls");
}

void cadastrarPlano() {
	
	setlocale(LC_ALL, "");
    system("cls");
    
    Plano plano;
    int i;
    
    
    printf("------------------ CADASTRO DE PLANOS -----------------\n\n");
    
    printf("ID do plano: ");
    scanf("%d", &plano.id);
    
    // Verifica se o ID já está cadastrado no sistema
    for (i = 0; i < total_planos; i++) {
        if (planos[i].id == plano.id) {
        	system("cls");
        	
            printf("\nATENÇÃO: ID DE PLANO JÁ CADASTRADO NO SISTEMA!\a\n");
            printf("\nPor favor, realize um novo cadastro com outro ID de Plano.\n\n");
            
            system("pause");
            system("cls");
            return;
        }
    }
    
    printf("Nome do plano: ");
    scanf(" %[^\n]", plano.nome);
    
    printf("Descrição do plano: ");
    scanf(" %[^\n]", plano.descricao);
    
    printf("Mensalidade: R$");
    scanf("%f", &plano.preco);
    
    planos[total_planos] = plano;
    total_planos++;
    
    printf("\n-------------------------------------------------------\n\n");
    printf("PLANO CASDASTRADO COM SUCESSO!\n\n");
    
    system("pause");
    system("cls");
}

void registrarFrequencia() {
	
	setlocale(LC_ALL, "");
	system("cls");
	
	// Verifica se já há alunos cadastrados
    if (total_alunos == 0) {
    	system("cls");
    	
        printf("\nATENÇÃO: NENHUM ALUNO CADASTRADO NO SISTEMA.\a\n");
        printf("\nPor favor, cadastre um aluno primeiro.\n\n");
        
        system("pause");
        system("cls");
        return;
    }
	
    Frequencia reg;
    int i;
    int alunoEncontrado = 0;
    
    
    printf("----------------- REGISTRAR FREQUÊNCIA ----------------\n\n");
    
    printf("ID do registro de frequencia: ");
    scanf("%d", &reg.id);
    
    // Verifica se o ID já está cadastrado no sistema
    for (i = 0; i < total_frequencia; i++) {
        if (frequencia[i].id == reg.id) {
        	system("cls");
        	
            printf("\nATENÇÃO: ID DE FREQUÊNCIA JÁ CADASTRADO NO SISTEMA.\a\n");
            printf("\nPor favor, realize um novo cadastro com outro ID para o registro.\n\n");
            
            system("pause");
            system("cls");
            return;
        }
    }
    
    printf("ID do aluno: ");
    scanf("%d", &reg.id_aluno);
    
    // Verifica se o aluno está sistema
    for (i = 0; i < total_alunos; i++) {
        if (alunos[i].id == reg.id_aluno) {
            alunoEncontrado = 1;
            break;
        }
    }

    if (!alunoEncontrado) {
    	system("cls");
    	
        printf("\nATENÇÃO: ALUNO NÃO ENCONTRADO NO SISTEMA.\a\n");
        printf("\nPor favor, realize um novo registro com um ID de Aluno válido.\n\n");
        
        system("pause");
        system("cls");
        return;
    }
    
    printf("Data do registro de frequencia (dd/mm/aaaa): ");
    scanf(" %[^\n]", reg.data);
    
    // Verifica se já existe registro de frequência
    for (i = 0; i < total_frequencia; i++) {
        if (frequencia[i].id_aluno == reg.id_aluno && strcmp(frequencia[i].data, reg.data) == 0) {
        	system("cls");
        	
            printf("ATENÇÃO: JÁ FOI ENCONTRADO UM REGISTRO DE FREQUÊNCIA PARA O ALUNO NA DATA INFORMADA.\a\n");
            printf("\nNão é possível alterar a frequência do aluno.\n");
            
            system("pause");
            system("cls");
            return;
        }
    }

    
    printf("Presença do aluno (S/N): ");
    scanf(" %c", &reg.presenca);
    
    frequencia[total_frequencia] = reg;
    total_frequencia++;
    
    printf("\n-------------------------------------------------------\n\n");
    printf("FREQUÊNCIA REGISTRADA COM SUCESSO!\n\n");
    
    system("pause");
    system("cls");
}

void cadastraInstrutror() {
	
	setlocale(LC_ALL, "");
	system("cls");
	
	Instrutor instrutor;
	int i;
	
	printf("----------------- CADASTRAR INSTRUTOR -----------------\n\n");
    
    printf("Nome do instrutor: ");
    scanf(" %[^\n]", instrutor.nome);
    
    // Verifica se o instrutor já está no sistema
    for (i = 0; i < total_instrutores; i++) {
        if (strcmp(instrutores[i].nome, instrutor.nome) == 0) {
        	system("cls");
        	
            printf("\nATENÇÃO: INSTRUTOR JÁ CADASTRADO NO SISTEMA.\a\n\n");
            
            system("pause");
            system("cls");
            return;
        }
    }
	
	
    instrutores[total_instrutores] = instrutor;
    total_instrutores++;
    
    printf("\n-------------------------------------------------------\n\n");
    printf("INSTRUTOR CADASTRADO COM SUCESSO!\n\n");
    
    system("pause");
    system("cls");
	
}

void cadastrarAula() {
	
	setlocale(LC_ALL, "");
	system("cls");
	
    Aula aula;
    int i;
    int instrutorOK = 0;
    
    // Verifica se já há instrutores cadastrados
    if (total_instrutores == 0) {
    	system("cls");
    	
        printf("\nATENÇÃO: NENHUM INSTRUROR CADASTRADO NO SISTEMA.\a\n");
        printf("\nPor favor, cadastre um instrutor primeiro.\n\n");
        
        system("pause");
        system("cls");
        return;
    }
    
    
    printf("------------------ CADASTRO DE AULAS ------------------\n\n");
    
    printf("ID da aula: ");
    scanf("%d", &aula.id);
    
    // Verifica se o ID já existe no sistema
    for (i = 0; i < total_aulas; i++) {
        if (aulas[i].id == aula.id) {
        	system("cls");
        	
            printf("\nATENÇÃO: ID DE AULA JÁ CADASTRADO NO SISTEMA.\a\n");
            printf("\nPor favor, realize um novo cadastro com outro ID de Aula..\n\n");
            
            system("pause");
            system("cls");
            return;
        }
    }

    printf("Nome da aula: ");
    scanf(" %[^\n]", aula.nome);
    
    printf("Nome do instrutor responsável: ");
    scanf(" %[^\n]", aula.instrutor);
    
    // Verifica se o instrutor está no sistema
    for (i = 0; i < total_instrutores; i++) {
        if (strcmp(instrutores[i].nome, aula.instrutor) == 0) {
            instrutorOK = 1;
            break;
        }
    }

    if (!instrutorOK) {
    	system("cls");
    	
        printf("ATENÇÃO: O INSTRUTOR INFORMADO NÃO ESTÁ CADASTRADO NO SISTEMA.\a\n");
        printf("\nPor favor, insira um instrutor que esteja cadastrado.\n");
        
        system("pause");
        system("cls");
        return;
    }
    
    printf("Horário em que a aula é realizada: ");
    scanf(" %[^\n]", aula.horario);
    
    aulas[total_aulas] = aula;
    total_aulas++;
    
    printf("\n-------------------------------------------------------\n\n");
    printf("AULA CADASTRADA COM SUCESSO!\n\n");
    
    system("pause");
    system("cls");
}


// ------------------------ FUNÇÕES DE RECUPERAÇÃO ------------------------ 

void mostrarAlunos() {
	
	setlocale(LC_ALL, "");
	system("cls");
	
	// Verifica se já há alunos cadastrados
    if (total_alunos == 0) {
    	system("cls");
    	
        printf("\nATENÇÃO: ATENÇÃO: NENHUM ALUNO CADASTRADO NO SISTEMA.\a\n");
        printf("\nPor favor, cadastre um aluno primeiro.\n\n");
        
        system("pause");
        system("cls");
        return;
    }
	
	int i;
	
	printf("------------------------- ALUNOS ----------------------\n\n");
	
    for (i = 0; i < total_alunos; i++) {
    	
    	
        printf("ID: %d\n", alunos[i].id);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Data de Nascimento: %s\n", alunos[i].data_nascimento);
        printf("Email: %s\n", alunos[i].email);
        printf("Telefone: %s\n", alunos[i].telefone);
        
        printf("\n-------------------------------------------------------\n\n");
    }
    
    system("pause");
    system("cls");
}

void mostrarPlanos() {
	
	setlocale(LC_ALL, "");
	system("cls");
	
	// Verifica se já há planos cadastrados
    if (total_planos == 0) {
    	system("cls");
    	
        printf("\nATENÇÃO: NENHUM PLANO CADASTRADO NO SISTEMA.\a\n");
        printf("\nPor favor, cadastre um plano primeiro.\n\n");
        
        system("pause");
        system("cls");
        return;
    }
	
	int i;
	
	printf("------------------------- PLANOS ----------------------\n\n");
	
    for (i = 0; i < total_planos; i++) {
    	
        printf("ID: %d\n", planos[i].id);
        printf("Nome: %s\n", planos[i].nome);
        printf("Descrição: %s\n", planos[i].descricao);
        printf("Mensalidade: R$%.2f\n", planos[i].preco);
        
        printf("\n-------------------------------------------------------\n\n");
    }
    
    system("pause");
    system("cls");
}

void mostrarFrequencia() {
	
	setlocale(LC_ALL, "");
	system("cls");
	
	// Verifica se já há alunos cadastrados
    if (total_alunos == 0) {
    	system("cls");
    	
        printf("\nATENÇÃO: NENHUM ALUNO CADASTRADO NO SISTEMA.\a\n");
        printf("\nPor favor, cadastre um aluno primeiro.\n\n");
        
        system("pause");
        system("cls");
        return;
    }
	
    int id_aluno;
    char data[11];
    int i;
    int frequenciaOK= 0, alunoOK = 0;

    
    printf("----------------------- FREQUÊNCIA --------------------\n\n");
    
    printf("ID do aluno que deseja consultar: ");
    scanf("%d", &id_aluno);
    
    
    // Verifica se o aluno já está no sistema
    for (i = 0; i < total_alunos; i++) {
        if (alunos[i].id == id_aluno) {
            alunoOK = 1;
            break;
        }
    }

    if (!alunoOK) {
        printf("\nATENÇÃO: O ID DE ALUNO INFORMADO NÃO ESTÁ CADASTRADO NO SISTEMA.\a\n");
        printf("\nPor favor, realize uma nova busca com um ID de Aluno válido..\n\n");
            
        system("pause");
        system("cls");
        return;
    }
    
    printf("Data (dd/mm/aaaa): ");
    scanf(" %[^\n]", data);
    
    // Verifica se há registro de frequência para o aluno
    
    for (i = 0; i < total_frequencia; i++) {
        if (frequencia[i].id_aluno == id_aluno && strcmp(frequencia[i].data, data) == 0) {
            frequenciaOK = 1;
            
            printf("\nREGISTRO DE FREQUÊNCIA ENCONTRADO\n");
            printf("Data: %s\n", frequencia[i].data);
            printf("Presenca do aluno: %c\n", frequencia[i].presenca);
            
            printf("\n-------------------------------------------------------\n\n");
        }
	}

    if (!frequenciaOK) {
    	system("cls");
    	
        printf("ATENÇÃO: NÃO HÁ REGISTRO DE FREQUÊNCIA PARA O ALUNO INFORMADO NA DATA ESPECIFICADA.\a\n");
    }
    
    
    system("pause");
    system("cls");
    
}

void mostrarAulasInstrutor() {
	
	setlocale(LC_ALL, "");
	system("cls");
	
	 // Verifica se já há instrutores cadastrados
    if (total_instrutores == 0) {
    	system("cls");
    	
        printf("\nATENÇÃO: NENHUM INSTRUROR CADASTRADO NO SISTEMA.\a\n");
        printf("\nPor favor, cadastre um instrutor primeiro.\n\n");
        
        system("pause");
        system("cls");
        return;
    }
	
    Instrutor instrutor;
    int i;
    int ministraAulas = 0, instrutorOK = 0;
    
    printf("Recuperar aulas ministradas por instrutor\n");
    
    printf("------------------ AULAS POR INSTRUTOR ----------------\n\n");
    
    printf("Nome do instrutor: ");
    scanf(" %[^\n]", instrutor.nome);
    
    // Verifica se o instrutor está cadastrado
    for (i = 0; i < total_instrutores; i++) {
        if (strcmp(instrutores[i].nome, instrutor.nome) == 0) {
            instrutorOK = 1;
            break;
        }
    }

    if (!instrutorOK) {
    	system("cls");
    	
        printf("\nATENÇÃO: INSTRUTOR NÃO CADASTRADO NO SISTEMA\a\n");
        printf("\nPor favor, insira um instrutor válido.\n");
        
        system("pause");
        system("cls");
        return;
    }
    
    
    printf("Aulas ministradas por %s:\n\n", instrutor.nome);
    
    // Verifica se o instrutor ministra alguma aula
    for (i = 0; i < total_aulas; i++) {
        if (strcmp(aulas[i].instrutor, instrutor.nome) == 0) {
            ministraAulas = 1;
            
            printf("ID: %d\n", aulas[i].id);
            printf("Nome: %s\n", aulas[i].nome);
            printf("Horario: %s\n", aulas[i].horario);
            
            printf("\n-------------------------------------------------------\n\n");
        }
    }

    if (!ministraAulas) {
    	system("pause");
    	
        printf("ATENÇÃO: O INSTRUTOR INFORMADO AINDA NÃO MINISTRA NENHUMA AULA.\a\n");
    }
    
    system("pause");
    system("cls");
}

void mostrarAlunosAusentes() {
	
	setlocale(LC_ALL, "");
	system("cls");
	
	// Verifica se já há alunos cadastrados
    if (total_alunos == 0) {
    	system("cls");
    	
        printf("\nATENÇÃO: ATENÇÃO: NENHUM ALUNO CADASTRADO NO SISTEMA.\a\n");
        printf("\nPor favor, cadastre um aluno primeiro.\n\n");
        
        system("pause");
        system("cls");
        return;
    }
	
    char data[11];
    int i;
	int frequenciaOK = 0;
    
    printf("Recuperar alunos ausentes em uma data\n\n");
    
    printf("Data (dd/mm/aaaa): ");
    scanf(" %[^\n]", data);
    
    printf("\n-------------------------------------------------------\n\n");
    printf("\nAlunos ausentes no dia %s:\n", data);
    
    // Verifica se há registros na data
    for (i = 0; i < total_frequencia; i++) {
        if (strcmp(frequencia[i].data, data) == 0 && frequencia[i].presenca == 'N') {
            frequenciaOK = 1;
            int id_aluno = frequencia[i].id_aluno;
            
            printf("Aluno com ID: %d\n", id_aluno);
            printf("\n");
        }
    }

    if (!frequenciaOK) {
        printf("ATENÇÃO: NÃO HÁ REGISTROS DE AUSÊNCIAS PARA A DATA INFORMADA.\a\n");
    }
    
    
    system("pause");
    system("cls");
}


// ------------------------ FUNÇÃO PRINCIPAL ------------------------ 
int main() {
	
	setlocale(LC_ALL, "");
	
    int opcao, escolha;
    
    do {
        printf("---------------- Bem-vindo ao FitSense ----------------\n\n");
        printf("                         \\|^_^|/                          \n\n");
        printf("------------------------- MENU ------------------------\n\n");
        
        printf("1 - Cadastrar aluno\n");
        printf("2 - Cadastrar plano\n");
        printf("3 - Registrar frequencia\n");
        printf("4 - Cadastrar instrutor\n");
        printf("5 - Cadastrar aula\n");
        printf("6 - Recuperar dados\n");
        printf("7 - Sair\n\n");
        
        printf("-------------------------------------------------------\n");
        printf("\nDIGITE A OPÇÃO DESEJADA: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                cadastrarPlano();
                break;
            case 3:
                registrarFrequencia();
                break;
            case 4:
                cadastraInstrutror();
                break;
            case 5:
                cadastrarAula();
                break;
            case 6:
            	
            	// ------------------------ PERGUNTAS DO TRABALHO ------------------------ 
            	
            	system("cls");
            	
            	printf("------------------------ SUBMENU ----------------------\n\n");
   	
            	printf("Escolha quais dados deseja exibir.\n");
            	printf("1 - Alunos matriculados no sitema\n");
                printf("2 - Planos de treinamento da academia\n");
                printf("3 - Frequência de um aluno\n");
                printf("4 - Aulas ministradas por um instrutor\n");
                printf("5 - Alunos ausentes em uma data\n\n");
                
                printf("-------------------------------------------------------\n");
                
                printf("\nDIGITE A OPÇÃO DESEJADA: ");
                scanf("%d", &escolha);
                printf("\n");
                
                switch (escolha) {
					case 1:
                        mostrarAlunos();
                        break;
                    case 2:
                        mostrarPlanos();
                        break;
                    case 3:
                        mostrarFrequencia();
                        break;
                    case 4:
                        mostrarAulasInstrutor();
                        break;
                    case 5:
                        mostrarAlunosAusentes();
                        break;
				}
                break;
            case 7:
                printf("FECHANDO PROGRAMA...\n");
                opcao = 0;
                break;
            default:
                printf("\nA OPÇÃO DIGITADA É INVÁLIDA!\a\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}