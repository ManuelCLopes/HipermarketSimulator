#pragma once
#include "stdconfig.h"

typedef struct {
	char codigo[CODIGO_PRODUTO];
	char nome[NOME_PRODUTO];
	char preco[5];
	char tempo_de_compra[5];
	char tempo_caixa[5];
}STOCK_PRODUTOS;

typedef struct {
	int codigo_cliente;
	char nome_cliente[NOME_PESSOA];
	int n_caixa;
	int tempo, preco; //tempo : caso seja 0, o cliente nao vai comprar nada. caso seja 1 o cliente ja esta na caixa. superior quer dizer que o client
	int estado; // 0 - nao esta no hipermercado   1 - esta no hipermercado
}DADOS_CLIENTE;

typedef struct no {
	struct no *proximo;
	DADOS_CLIENTE *dados;
}NO;

typedef struct fila {
	NO *inicio;
	int n_pessoas;
}FILA;

typedef struct funcionario {
	char nome_funcionario[NOME_PESSOA];
	char codigo[CODIGO_FUNCIONARIO];
}FUNCIONARIO;

typedef struct caixa {
	int numero_da_caixa;
	FILA *f;
	FUNCIONARIO *func;
	int aberta; // 0 fechada -- 1 aberta
	int n_pessoas_atendidas;
	int n_produtos_vendidos;
	float valor_vendas;
}CAIXA_PAGAMENTO;

typedef struct {
	int dia;
	int n_clientes_hipermercado; //valor instantaneo
	int n_produtos_vendidos;
	int n_produtos_oferecidos;
	int caixas_abertas;
	float total_vendas; // ir adicionando o valor dos produtos que vao sendo vendidos
}GESTAO_HIPERMERCADO;

typedef struct {
	float tempo_medio_espera; // cada cliente que seja atendido, o seu tempo de espera será incrementado neste parametro da estrutura
	int n_clientes;
}TEMPO_MEDIO_ESPERA;

GESTAO_HIPERMERCADO* HIPERMERCADO_NOVO_DIA(int);

NO *criar_no();

void abrir_caixa_fechada(CAIXA_PAGAMENTO*);
TEMPO_MEDIO_ESPERA *zerar_tempo_espera();

int num_medio_clientes_hipermercado(GESTAO_HIPERMERCADO*, int);
int num_instantaneo_clientes_hipermercado(GESTAO_HIPERMERCADO *);

int num_vendas_por_caixa(CAIXA_PAGAMENTO *);

int num_vendas_por_dia(GESTAO_HIPERMERCADO*);

float valor_das_vendas_por_caixa(CAIXA_PAGAMENTO*);

void valor_total_vendas_dia(GESTAO_HIPERMERCADO*);
STOCK_PRODUTOS* aloca_memoria_produtos(int);
DADOS_CLIENTE* aloca_memoria_clientes(int);
FUNCIONARIO* aloca_memoria_funcionarios(int);
CAIXA_PAGAMENTO* aloca_memoria_CAIXAS(int);
FILA* criar_fila(CAIXA_PAGAMENTO*);
void inicializar_caixas(CAIXA_PAGAMENTO *);

void mostrar_produtos(STOCK_PRODUTOS*);
void mostrar_funcionarios(FUNCIONARIO*);

void associar_turnos(FUNCIONARIO*, CAIXA_PAGAMENTO*);
void troca_de_turnos(FUNCIONARIO *, CAIXA_PAGAMENTO*);
