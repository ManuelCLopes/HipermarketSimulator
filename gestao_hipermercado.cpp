#include "gestao_hipermercado.h"

void simulacao(int h, FUNCIONARIO*F, CAIXA_PAGAMENTO*c, DADOS_CLIENTE *cliente, GESTAO_HIPERMERCADO *H, STOCK_PRODUTOS* stock) {

	time_t abertura;
	int horas_decorridas;
	h++; int h1 = h - 1;
	horas_decorridas = 0;
	abertura = time(&abertura);

	while (horas_decorridas < 12 - h1) //cada hora equivale a 1 segundo, logo 12 h = 12
	{
		if (difftime(time(NULL), abertura) == h && horas_decorridas < 12 - h1)
		{			
			printf("\n|%d:00|", (9 + h));
			printf("\nClientes no Hipermercado: %d\n", H->n_clientes_hipermercado);
			gerar_clientes(cliente, H);
			horas_decorridas++;
			h++;

			
			manutencao_caixas(c, H);
			manutencao_clientes(cliente, H, c);
			if (horas_decorridas == 6)
				troca_de_turnos(F, c);
		}
	}
}
void menu_simulacao()
{
	printf("\n     Opcoes ao longo da simulacao:   \n");
	printf("\nContinuar                           (1)");
	printf("\nMenu Estatisticas                   (2)");
	printf("\nAbrir caixa                         (3)");
	printf("\nFechar caixa                        (4)");
	printf("\nSimular resto do dia                (0)");
}
void simulacao_com_paragens(int i, CAIXA_PAGAMENTO*c, GESTAO_HIPERMERCADO*h, STOCK_PRODUTOS* stock, DADOS_CLIENTE*Cliente, FUNCIONARIO*F) {

//	time_t abertura;
	int horas_decorridas;
	int op;
	horas_decorridas = 0;

	//abertura = time(&abertura);

	menu_simulacao();
	printf("\n\nDia %d \n\n|09:00|\t", i);
	printf("\tClientes no Hipermercado: %d", h->n_clientes_hipermercado);


	while (horas_decorridas<12)
	{
		do {
			printf("\n");
			scanf("%d", &op);
		} while (op < 0 || op>4);

		switch (op) {
		case 1: gerar_clientes(Cliente, h); 

			horas_decorridas++; 
			printf("\n|%d:00|\t", (9 + horas_decorridas)); 
			printf("\tClientes no Hipermercado: %d",h->n_clientes_hipermercado);

			if (horas_decorridas == 6)
				troca_de_turnos(F, c);
			
			manutencao_caixas(c, h);
			manutencao_clientes(Cliente, h, c);
			break;
		case 2: menu_estatisticas(c, h, stock, Cliente, F);
			printf("\nDe volta ao dia no hipermercado..."); menu_simulacao(); break;
		case 3:abrir_caixa(c, h);break;
		case 4:fechar_caixa_forcadamente(c);break;
		case 0:simulacao(horas_decorridas, F, c, Cliente, h, stock); 
			horas_decorridas = 12; 
			break;
		}
	}
}

void submenu_produtos(GESTAO_HIPERMERCADO * H, STOCK_PRODUTOS* p) {
	int op1;
	printf("|---------------------------Produtos---------------------------|\n");
	printf("|   Valor total obtido em vendas                           (1) |\n");
	printf("|   Numero total de produtos vendidos                      (2) |\n");
	printf("|   Stock de produtos                                      (3) |\n");
	printf("|                                                              |\n");
	printf("|   Voltar ao menu anterior                                (0) |\n");
	printf("|--------------------------------------------------------------|\n");

	scanf("%d", &op1);
	while (op1 < 0 || op1>8) {
		printf("Opcao invalida!\n Selecione de novo a opcao: ");
		scanf("%d", &op1);
	}
	switch (op1)
	{
	case 1:valor_total_vendas_dia(H);break;
	case 3:mostrar_produtos(p);break;
	case 2:printf("Numero de produtos vendidos: %d\n\n", H->n_produtos_vendidos);break;
	case 0:break;
	}
}
void submenu_clientes(DADOS_CLIENTE*c, GESTAO_HIPERMERCADO *H, CAIXA_PAGAMENTO*cp) {
	int op2;
	printf("|---------------------------Clientes---------------------------|\n");
	printf("|   Mostrar clientes                                       (1) |\n");
	printf("|   Numero instantaneo de clientes no hipermercado         (2) |\n");
	printf("|   Numero medio de clientes numa determinada fila/caixa   (3) |\n");
	printf("|                                                              |\n");
	printf("|   Voltar ao menu anterior                                (0) |\n");
	printf("|--------------------------------------------------------------|\n");
	scanf("%d", &op2);
	while (op2 < 0 || op2>4) {
		printf("Opcao invalida!\n Selecione de novo a opcao: ");
		scanf("%d", &op2);
	}
	switch (op2)
	{
	case 1:mostrar_clientes_hipermercado(c);break;
	case 2:printf("Numero de clientes : %d",H->n_clientes_hipermercado);break;
	case 3:n_clientes_numa_caixa(cp);break;
	case 4: pesquisar_pessoa(c, cp, H);
	case 0:break;
	}

}
void submenu_caixas(CAIXA_PAGAMENTO * caixa, FUNCIONARIO*f, GESTAO_HIPERMERCADO* H) {
	int op3;
	printf("|---------------------Caixas de pagamento-----------------------|\n");
	printf("|                                                               |\n");
	printf("|   Numero de caixas abertas neste instante                 (1) |\n");
	printf("|   Abrir caixa                                             (2) |\n");
	printf("|   Mostrar caixas                                          (3) |\n");
	printf("|   Mostrar funcionarios                                    (4) |\n");
	printf("|                                                               |\n");
	printf("|   Voltar ao menu anterior                                 (0) |\n");
	printf("|---------------------------------------------------------------|\n");
	scanf("%d", &op3);
	while (op3 < 0 || op3>4) {
		printf("Opcao invalida!\n Selecione de novo a opcao: ");
		scanf("%d", &op3);
	}
	switch (op3)
	{
	case 1:printf("Estao abertas %d caixas de pagamento.", H->caixas_abertas);break;
	case 2:abrir_caixa(caixa, H);break;
	case 3:mostrar_caixas(caixa);break;
	case 4:mostrar_funcionarios(f); break;
	case 0:break;
	}
}
void menu_estatisticas(CAIXA_PAGAMENTO *caixa, GESTAO_HIPERMERCADO*H, STOCK_PRODUTOS *p, DADOS_CLIENTE*c, FUNCIONARIO*f) {
	int op;
	printf("|---------------ESTATISTICAS----------------|\n");
	printf("|   Produtos............................(1) |\n");
	printf("|   Clientes............................(2) |\n");
	printf("|   Caixas de pagamento.................(3) |\n");
	printf("|                                           |\n");
	printf("|   Voltar ao menu anterior.............(0) |\n");
	printf("|------------------------------------------ |\n");
	scanf("%d", &op);
	while (op < 0 || op>3) {
		printf("Opcao invalida!\n Selecione de novo a opcao: ");
		scanf("%d", &op);
	}
	switch (op) {
	case 1:submenu_produtos(H,p);break;
	case 2:submenu_clientes(c, H, caixa);break;
	case 3:submenu_caixas(caixa, f, H);break;
	case 0:break;
	}

}
int menu()
{
	int opm;

	printf("\n|---------------Menu Principal-------------|\n");
	printf("|   Estatisticas                        (1)|\n");
	printf("|   Proximo dia                         (2)|\n");
	printf("|                                          |\n");
	printf("|   Terminar simulacao                  (0)|\n");
	printf("|------------------------------------------|\n");
	scanf("%d", &opm);
	while (opm < 0 || opm>2) {
		printf("Opcao invalida!\n Selecione de novo a opcao: ");
		scanf("%d", &opm);
	}
	return opm;
}

int num_medio_clientes_por_caixa(GESTAO_HIPERMERCADO *H, CAIXA_PAGAMENTO* caixa) {
	int pessoas = 0;
	CAIXA_PAGAMENTO *caixa_aux;
	for (int i = 0; i < MAX_CAIXAS; i++)
	{
		caixa_aux = caixa + i;
		pessoas += caixa_aux->f->n_pessoas;
	}
	return pessoas / H->caixas_abertas;
}
int pedir_codigo_cliente( )
{
	int codigo;
	printf("\nQual o codigo da pessoa a pesquisar?\n");
	scanf("%d",&codigo);
	while (codigo>999999 || codigo <0) {
		printf("\nCodigo Invalido! Volte a inserir o codigo\n");
		scanf("%s", &codigo);
	}
	return codigo;
}
void pesquisar_pessoa(DADOS_CLIENTE* C, CAIXA_PAGAMENTO *p, GESTAO_HIPERMERCADO*H)
{
	NO *aux = (NO *)malloc(sizeof(NO));
	aux = p->f->inicio;
	int i;
	int sucesso = 0;

	if (H->n_clientes_hipermercado == 0){
		printf("\nO Hipermercado encontra-se neste momento vazio.\n");
	return;
	}

	int codigo=pedir_codigo_cliente();
	for (i = 0; i < NUM_CLIENTES; i++)
	{
		if ((C + i)->codigo_cliente == codigo)
			if ((C + i)->estado = 0)
			{
				printf("\nO cliente nao se encontra no hipermercado.\n");
				return;
			}
			else
				if ((C + i)->estado = 1)
				{
					printf("\nO cliente ja se encontra na fase de pagamento.");
					return;
				}
				else {
					printf("\nO cliente esta a escolher as suas compras dentro do hipermercado.\n");
					return;
				}
	}
	printf("\nLamentamos, mas o codigo de cliente inserido nao corresponde a nenhum cliente da nossa base de dados.\n");
}
void mostrar_caixas(CAIXA_PAGAMENTO *p)
{
	for (int i = 0; i < MAX_CAIXAS; i++)
		if ((p + i)->aberta)
			printf("Caixa %d - Aberta\n", (p + i)->numero_da_caixa);
		else
			printf("Caixa %d - Fechada\n", (p + i)->numero_da_caixa);
}
DADOS_CLIENTE *pesquisar_cliente(DADOS_CLIENTE* c, int codigo)
{
	int i;
	for (i = 0; i < NUM_CLIENTES; i++)
		if ((c + i)->codigo_cliente == codigo)
			break;
	return (c + i);
}
void gerar_clientes(DADOS_CLIENTE*C, GESTAO_HIPERMERCADO *H)
{
	int n_clientes = rand() % (CAPACIDADE_HIPERMERCADO - H->n_clientes_hipermercado);
	int cod, n_prod;
	for (int i = 0; i < n_clientes; i++)
	{
		do { cod = rand() % 10000; } while ((C + cod)->estado);
		
		n_prod = rand() % 30; //50 maximos de produtos a comprar
		(C + cod)->preco = rand() % 300;//gasto maximo de 300 euros
		(C + cod)->tempo = rand() % 4;
		(C + cod)->estado = 1;

		H->total_vendas += (C + cod)->preco;
		H->n_produtos_vendidos += n_prod;
	}
	H->n_clientes_hipermercado += n_clientes;
}
void inserir_fila(DADOS_CLIENTE*c, CAIXA_PAGAMENTO* cp)
{
	NO* cliente = (NO*)malloc(sizeof(NO));
	cliente->dados = (DADOS_CLIENTE*)malloc(sizeof(DADOS_CLIENTE));
	cliente->dados = c;
	cliente->proximo = NULL;

	NO *aux = (NO*)malloc(sizeof(NO));
	aux->dados = (DADOS_CLIENTE*)malloc(sizeof(DADOS_CLIENTE));
	aux = cp->f->inicio;

	int i = 0;

	while ((cp + i)->aberta && (cp + i)->f->n_pessoas < LIMITE_PESSOAS_CAIXA)
		i++;
	if (aux==NULL)
		(cp + i)->f->inicio = cliente;
	else
	{
		while (aux->proximo != NULL)
			aux = aux->proximo;
		aux->proximo = cliente;
	}
	(cp + i)->f->n_pessoas++;
	c->n_caixa = i + 1;
}
void manutencao_clientes(DADOS_CLIENTE*C, GESTAO_HIPERMERCADO*H, CAIXA_PAGAMENTO*cp)
{
	FILA* fila;
	int n_caixa;
	for (int i = 0; i < NUM_CLIENTES; i++)
		if ((C + i)->estado)
		{
			if ((C + i)->tempo > 1)
				(C + i)->tempo -= 1;
			if ((C + i)->tempo == 1)
				inserir_fila((C + i), cp);
			if ((C + i)->tempo < 1) {
				fila = cp->f;
				n_caixa = (C + i)->n_caixa;
				fila->inicio = remover_da_fila(C, fila);
				(C + i)->estado = 0;
				H->n_clientes_hipermercado--;
			}
		}
}
NO* remover_da_fila(DADOS_CLIENTE*C, FILA*lista)
{
	NO*aux = lista->inicio;
	NO*ant = NULL;
	
	if (aux == NULL)
		return NULL;

	while (aux->proximo)
	{
		ant = aux;
		aux = aux->proximo;
	}
	if (ant)
		ant->proximo = NULL;
	free(aux);
	lista->n_pessoas--;
	return lista->inicio;
}

void fechar_caixa_com_menos_pessoas(CAIXA_PAGAMENTO *c, GESTAO_HIPERMERCADO *H)
{
	int n_caixa;

	for (int i = 0; i < MAX_CAIXAS; i++)
		if ((c + i)->aberta)
			if ((c + i)->f->n_pessoas > (c + i + 1)->f->n_pessoas) // se a caixa seguinte tiver menos pessoas
				n_caixa = (c + i + 1)->numero_da_caixa;
	(c+n_caixa-1)->aberta = 0; // Já não pode ir mais nenhum cliente para esta caixa, a não ser os que ja estavam na fila
	H->caixas_abertas--;
}
void fechar_caixa_forcadamente(CAIXA_PAGAMENTO* C)
{
	int op;
	printf("\nQual caixa deseja fechar? ");
	scanf("%d", &op);
	printf("\nMais nenhum cliente podera fazer compras nesta caixa enquanto esta permanecer fechada.\n");
	(C + op)->aberta = 0;
	(C+op)->f->n_pessoas = 0;
	free((C+op)->f->inicio);
}
void manutencao_caixas(CAIXA_PAGAMENTO*c, GESTAO_HIPERMERCADO*H)
{
	int n_caixas_abertas = H->caixas_abertas;
	int x=0;
	int caixas_necessarias = H->n_clientes_hipermercado / LIMITE_PESSOAS_CAIXA;
	if (H->n_clientes_hipermercado % LIMITE_PESSOAS_CAIXA != 0)
		x++;
	 x+= caixas_necessarias - n_caixas_abertas;
	int i = 0;
	while (i < MAX_CAIXAS - 1 && x>0)
	{
		if (!(c + i)->aberta) {
			(c + i)->aberta = 1;
			(c + i)->f->inicio = NULL;
			(c + i)->f->n_pessoas = 0;
				H->caixas_abertas++; x--;
		}
		if ((c + i)->aberta)
			i++;
	}
}
void abrir_caixa(CAIXA_PAGAMENTO* caix, GESTAO_HIPERMERCADO* H)
{
	int i = 0;
	int sucesso = 0;
	int op, numero;
	printf("\nAbrir caixa:\n");
	printf("\nAleatoriamente       (1)");
	printf("\nCaixa especifica     (2)");
	do {
		scanf("%d", &op);
	} while (op < 0 || op >2);
	switch (op)
	{
	case 1:
		if (H->caixas_abertas == MAX_CAIXAS)
		{
			printf("\nAs caixas já se encontram todas abertas.");
			return;
		}
		while (i < MAX_CAIXAS && !sucesso)
			if (!(caix + i)->aberta)
			{
				(caix + i)->aberta = 1;
				(caix + i)->f->inicio = NULL;
				(caix + i)->f->n_pessoas = 0;
				sucesso = 1;
				printf("\nCaixa %d esta agora aberta!", i + 1);
			}H->caixas_abertas++;
		break;
	case 2: mostrar_caixas(caix);
		printf("Insira o numero da caixa que deseja abrir: ");
		scanf("%d", &numero);
		while (numero < 0 || numero>45)
		{
			printf("\n Numero de caixa invalido! Insira novamente: ");
			scanf("%d", &numero);
		}
		if ((caix + numero - 1)->aberta)
			printf("\nA caixa escolhida ja se encontra aberta.");
		else 
		{
			(caix + numero - 1)->aberta = 1;
			(caix + i)->f->inicio = NULL;
			(caix + i)->f->n_pessoas = 0;
			H->caixas_abertas++;
			printf("\nCaixa %d esta agora aberta!", numero);

		}break;
	}
}

void verificar_caixas(GESTAO_HIPERMERCADO*H, CAIXA_PAGAMENTO *caix)
{
	int n = 0;
	for (int i = 0; i < MAX_CAIXAS; i++)
		if (caix->aberta && caix->f->n_pessoas==0)
			n++;
	if (n >= 2)
		fechar_caixa_com_menos_pessoas(caix, H);
}
void mostrar_clientes_hipermercado(DADOS_CLIENTE* p) {
	int vazio = 1;
	for (int i = 0; i < NUM_CLIENTES; i++)
	{
		if ((p + i)->estado) {
			vazio = 0;
			printf("\nCodigo de cliente: %d\nNome: %s \n", (p + i)->codigo_cliente, (p + i)->nome_cliente);
			printf("tempo na loja: %d horas\n", (p + i)->tempo);
			printf("Valor em produtos: %d euros\n", (p + i)->preco);
		}
	}
	if (vazio)
		printf("Hipermercado sem clientes.\n\n");
}
int numero_clientes_hipermercado(GESTAO_HIPERMERCADO*H, DADOS_CLIENTE*C)
{
	H->n_clientes_hipermercado = 0;
	for (int i = 0; i < NUM_CLIENTES; i++)
		if ((C + i)->estado)
			H->n_clientes_hipermercado++;
	return H->n_clientes_hipermercado;
}
void n_clientes_numa_caixa(CAIXA_PAGAMENTO*c) {
	int n;
	printf("\nEscolher caixa para fazer contagem de clientes: ");
	scanf("%d", &n);

	printf("\nA caixa %d tem neste momento %d pessoas.\n",n, ( c+n-1)->f->n_pessoas);
}
