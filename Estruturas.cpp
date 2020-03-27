#pragma once
#include "stdconfig.h"
#include "Estruturas.h"

GESTAO_HIPERMERCADO* HIPERMERCADO_NOVO_DIA(int i)
{
	GESTAO_HIPERMERCADO*H = (GESTAO_HIPERMERCADO*)malloc(sizeof(GESTAO_HIPERMERCADO));
	H->dia = i;
	H->n_clientes_hipermercado = 0;
	H->n_produtos_oferecidos = 0;
	H->n_produtos_vendidos = 0;
	H->total_vendas = 0;
	H->caixas_abertas = 0;
	return H;
}
NO *criar_no()
{
	NO* no;
	no = (NO *)malloc(sizeof(NO));
	no->proximo = NULL;
	return no;
}
/*PRODUTO_CONFIANCA* criar_p_vazio() {
	PRODUTO_CONFIANCA *prod;
	prod = (PRODUTO_CONFIANCA*)malloc(sizeof(PRODUTO_CONFIANCA));
	prod->produt = (STOCK_PRODUTOS*)malloc(sizeof(STOCK_PRODUTOS));
	prod->n_produtos_oferecidos++;
	return prod;
}*/

void abrir_caixa_fechada(CAIXA_PAGAMENTO *caixa)
{
	caixa->aberta = 1;
}

TEMPO_MEDIO_ESPERA *zerar_tempo_espera()
{
	TEMPO_MEDIO_ESPERA *tempo;
	tempo = (TEMPO_MEDIO_ESPERA*)malloc(sizeof(TEMPO_MEDIO_ESPERA));
	tempo->n_clientes = 0;
	tempo->tempo_medio_espera = 0;
	return tempo;
}

int num_medio_clientes_hipermercado(GESTAO_HIPERMERCADO* H, int horas)
{
	int pessoas = 0;
	pessoas += H->n_clientes_hipermercado;
	/*DE HORA EM GORA GUARDAR O NUMERO DE CLIENTES QUE ESTAO NO HIPERMERCADO E
	POSTERIORMENTE DIVIDIR PELO NUMERO DE HORAS DE FUNCIONAMENTO DO HIPERMERCADO PARA SABER O NUM MEDIO DE PESSOAS NO HIPERMERCADO*/
	return pessoas / horas;
}
int num_instantaneo_clientes_hipermercado(GESTAO_HIPERMERCADO *H)
{
	return H->n_clientes_hipermercado;
}

int num_vendas_por_caixa(CAIXA_PAGAMENTO *caixa)
{
	return caixa->n_produtos_vendidos;
}

int num_vendas_por_dia(GESTAO_HIPERMERCADO* H)
{
	return H->n_produtos_vendidos;
}

float valor_das_vendas_por_caixa(CAIXA_PAGAMENTO* caixa)
{
	return caixa->valor_vendas;
}

void valor_total_vendas_dia(GESTAO_HIPERMERCADO* H)
{
	printf("Numero total de vendas do hipermercado no dia corrente: %0.2f euros\n\n", H->total_vendas);
}

STOCK_PRODUTOS* aloca_memoria_produtos(int n)
{
	STOCK_PRODUTOS* p;
	p = (STOCK_PRODUTOS*)malloc(n * sizeof(STOCK_PRODUTOS));

	if (p == NULL)
	{
		printf("Memoria Insuficiente!");
		return NULL;
	}
	else
		return p;
}
DADOS_CLIENTE* aloca_memoria_clientes(int n)
{
	DADOS_CLIENTE* p;
	p = (DADOS_CLIENTE*)malloc(n * sizeof(DADOS_CLIENTE));

	if (p == NULL)
	{
		printf("Memoria Insuficiente!");
		return NULL;
	}
	else
		return p;
}
FUNCIONARIO* aloca_memoria_funcionarios(int n)
{
	FUNCIONARIO* p;
	p = (FUNCIONARIO*)malloc(n * sizeof(FUNCIONARIO));

	if (p == NULL)
	{
		printf("Memoria Insuficiente!");
		return NULL;
	}
	else
		return p;
}
CAIXA_PAGAMENTO* aloca_memoria_CAIXAS(int n)
{
	CAIXA_PAGAMENTO* cp;
	cp = (CAIXA_PAGAMENTO*)malloc(n * sizeof(CAIXA_PAGAMENTO));

	if (cp == NULL)
	{
		printf("Memoria Insuficiente!");
		return NULL;
	}
	else
		for (int i = 0; i < MAX_CAIXAS; i++)
		{
			(cp + i)->f = (FILA*)malloc(sizeof(FILA));
			if ((cp + i)->f == NULL)
			{
				printf("Memoria Insuficiente!");
				return NULL;
			}
			else {
				(cp+i)->f->inicio = NULL;
				(cp+i)->f->n_pessoas = 0;
			}
		}return cp;
}
void inicializar_caixas(CAIXA_PAGAMENTO *cp)
{
	for (int i = 0; i < MAX_CAIXAS; i++)
	{
		(cp + i)->numero_da_caixa = i + 1;
		(cp + i)->aberta = 0;
	}
}
FILA* criar_fila(CAIXA_PAGAMENTO*c)
{
		c->f = (FILA*)malloc(sizeof(FILA));
		if (c->f == NULL)
		{
			printf("Memoria Insuficiente!");
			return NULL;
		}
		else {
			c->f->inicio = NULL;
			c->f->n_pessoas = 0;
		}
	
		return c->f;
}

void mostrar_produtos(STOCK_PRODUTOS* p) {
	for (int i = 0; i < MAX_PRODUTOS; i++)
		printf("\nNome do produto: %s\nPreco: %s euros ", (p + i)->nome, (p + i)->preco);
}

void associar_turnos(FUNCIONARIO*F, CAIXA_PAGAMENTO*C)  //TESTAR FUNCAO
{
	for (int i = 0; i < MAX_CAIXAS; i++)
		(C + i)->func = (F + i); // turno 1
}
void troca_de_turnos(FUNCIONARIO *F, CAIXA_PAGAMENTO*C)
{
	for (int i = MAX_CAIXAS / 2; i < MAX_CAIXAS; i++)
		(C + i)->func = (F + i);//turno 2
}
void mostrar_funcionarios(FUNCIONARIO* p) {
	for (int i = 0; i < NUM_FUNCIONARIOS; i++)
		printf("\nCodigo de funcionario: %s\nNome: %s\n", (p + i)->codigo, (p + i)->nome_funcionario);
}