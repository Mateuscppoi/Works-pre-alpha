#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

	char tipoServico1[25] = "Serviço completo: R$";
	char tipoServico2[9] = "Hora: R$";
	int usuariosCadastrados = 0;
	char emailCadastro[10] [30];
	char senhaCadastro [10] [30];
	char emailLogin	[30];
	char senhaLogin [30];
	int usuarioLogado = 0;
	int usuarioOn;
	char nickUsuario [10][30];
	int itensPorUsuario [10][1] = {0};
	char tituloItemUsuario [10][6][150];
	char descricaoItemUsuario [10][6][150];
	float precoItemUsuario [10][6];
	int tipoPrecoUsuario [10][6];

void logo () {
	printf("        ####   ####   ####    ############    #########      ####     ####  ##    ############\n");
	printf("        ####   ####   ####    ############    ##########     ####    ####   ##    ############\n");
	printf("        ####   ####   ####    ##        ##    ##       ##    ####   ####          ##\n");
	printf("        ####   ####   ####    ##        ##    ##       ##    ####  ####           ##\n");
	printf("        ####   ####   ####    ##        ##    ##      ##     #### ####            ############\n");
	printf("        ####   ####   ####    ##        ##    ########       ####  ####           ############\n");
	printf("        ####   ####   ####    ##        ##    ##      ##     ####   ####                    ##\n");
	printf("        ####   ####   ####    ##        ##    ##       ##    ####    ####                   ##\n");
	printf("        ##################    ############    ##        ##   ####     ####        ############\n");
	printf("        ##################    ############    ##         ##  ####      ####       ############\n");
	printf("                                                                                    by TI TEAM\n");
	for (int x = 0; x<4; x++){
		printf("\n");
	}
}

void Cadastro () {
	logo();
	fflush(stdin);
	printf("                               Digite seu email: ");
	gets(emailCadastro[usuariosCadastrados]);
	printf("                               Digite sua senha: ");
	gets(senhaCadastro[usuariosCadastrados]);
	printf("                               Digite um nome de usuario: ");
	gets(nickUsuario[usuariosCadastrados]);
	usuariosCadastrados++;
}

void Login () {
	int tmp = 0;
	while (tmp == 0){
		fflush(stdin);
		logo();
		printf("                               Login: ");
		gets(emailLogin);
		printf("                               Password: ");
		gets(senhaLogin);
		int validaLogin = 0;
		for (int x = 0; x<=usuariosCadastrados; x++) {
			if (strcmp(emailLogin,emailCadastro[x]) == 0 && strcmp(senhaLogin,senhaCadastro[x]) == 0){
				validaLogin = 1;
				usuarioOn = 1;
				usuarioLogado = x;
				tmp = 1;
			}		
		}
		if (validaLogin == 0) {
			int tmp2 = 0;
			system("cls");
			logo();
			printf("             Login ou senha incorreta\n");
			printf("              1 - tentar novamente\n");
			printf("              2 - voltar");
			scanf("%d", &tmp2);
			system("cls");
			if (tmp2 == 2) {
				tmp = 1;
				break;
			}
		}
	}
}

void InserirAnuncio () {
	int tmp1 = 0,tmp2 = 0,tmp3 = 0,tipo;
	system("cls");
	while (tmp1 == 0){
		printf("Digite o título do anúncio: ");
		fflush(stdin);
		gets(tituloItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]]);
		if (strlen(tituloItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]]) >= 2 || strlen(tituloItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]]) <= 150) {
			tmp1 = 1;
		} else {
			if (strlen(tituloItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]]) < 2) {
				printf("\n\n");
				printf("O título do anúncio deve possuir no mínimo 2 caracteres.\n");
			} else {
				printf("\n\n");
				printf("O título do anúncio deve possuir no máximo 150 caracteres.\n");
			}
		}
	}
	system("cls");
	while (tmp2 == 0){
		printf("\n%s\n", tituloItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]]);
		printf("Digite a descrição do anúncio: ");
		fflush(stdin);
		gets(descricaoItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]]);
		if (strlen(descricaoItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]]) >= 2 || strlen(descricaoItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]]) <= 150) {
			tmp2 = 1;
		} else {
			if (strlen(descricaoItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]]) < 2) {
				printf("\n\n");
				printf("A descrição do anúncio deve possuir no mínimo 2 caracteres.\n");
			} else {
				printf("\n\n");
				printf("A descrição do anúncio deve possuir no máximo 150 caracteres.\n");
			}
		}
	}
	system("cls");
	printf("\n%s\n", descricaoItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]]);
	printf("Escolha se o valor será do serviço completo ou por hora.\n");
	printf("1 - Serviço completo\n");
	printf("2 - Por hora\n\n");
	printf("Opção: ");
	scanf("%d", &tipo);
	if (tipo == 1) {
		tipoPrecoUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]] = 1;
	} else {
		tipoPrecoUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]] = 2;
	}
	system("cls");
	printf("\n");
	printf("Digite o preço do serviço (xx,xx): ");
	scanf("%f", &precoItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]]);
	if (tipoPrecoUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]] == 1) {
		printf("%s %.2f", tipoServico1, precoItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]] );
	} else {
		printf("%s %.2f", tipoServico2, precoItemUsuario[usuarioLogado][itensPorUsuario[usuarioLogado][0]] );
	}
	itensPorUsuario[usuarioLogado][0]++;
	system("pause");
}

void MeusAnuncios() {
	system("cls");
	logo();
	int opcao;
	printf("1 - Ver meus anúncios\n");
	printf("2 - Inserir anúncio\n");
	scanf("%d", &opcao);
	if (opcao == 1) {
		if (itensPorUsuario[usuarioLogado][0] > 0){
			for (int x = usuarioLogado; x<=usuarioLogado; x++) {
				for (int y = 0; y < itensPorUsuario[usuarioLogado][0]; y++) {
					printf("Título: %s\n", tituloItemUsuario[x][y] );
					printf("Descrição: %s\n", descricaoItemUsuario[x][y] );
					if (tipoPrecoUsuario[x][y] == 1) {
						printf("%s %.2f\n", tipoServico1, precoItemUsuario[x][y] );
					} else {
						printf("%s %.2f\n", tipoServico2, precoItemUsuario[x][y] );
					}
					system("pause");
				}
			} 
		}
	}
	if (opcao == 2) {
		InserirAnuncio();
	}
}

void itensDisponiveis() {
	system("cls");
	logo();
	int tmp = 1;
	for (int x = 0; x<= usuariosCadastrados; x++) {
		for (int y = 0; y < itensPorUsuario[x][0]; y++) {
			printf("%d - Título: %s\n", tmp, tituloItemUsuario[x][y] );
			printf("	 Descrição: %s\n", descricaoItemUsuario[x][y] );
				if (tipoPrecoUsuario[x][y] == 1) {
					printf("	 %s %.2f\n", tipoServico1, precoItemUsuario[x][y] );
				} else {
					printf("	 %s %.2f\n", tipoServico2, precoItemUsuario[x][y] );
				}
			printf("	 Criado por: %s\n", nickUsuario[x]);
			tmp++;
		}
	}
}

void removeAnuncio() {
	int opcao;
	itensDisponiveis();
	scanf("%d", &opcao);
	
}

void menu () {
	system("cls");
	logo();
	int op1;
	printf("Olá %s \n",nickUsuario[usuarioLogado]);
	printf("1 - Ver itens disponíveis\n");
	printf("2 - Meus anúncios\n");
	printf("3 - Deslogar\n");
	scanf("%d", &op1);
	if (op1 == 1) {
		itensDisponiveis();
		system("pause");
	}
	if (op1 == 2) {
		MeusAnuncios();
	}
	if (op1 == 3) {
		usuarioOn = 0;
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	int sair = 0;
	while(sair != 1){
		system("cls");
		logo();
		int opcaoInicial = 0;
		printf(" 1- Login \n");
		printf(" 2- Cadastro\n");
		printf(" 3- Sair \n");
		scanf("%d", &opcaoInicial);
		if (opcaoInicial == 1) {
			system("cls");
			Login();
		} 
		if (opcaoInicial == 2) {
			system("cls");
			Cadastro();			
		}
		if (opcaoInicial == 3) {
			break;
		}
		if (usuarioOn == 1) {
			while (usuarioOn == 1) {
				menu();
			}
	}
	
}
	return 0;
}

