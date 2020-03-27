#pragma once
#include "stdconfig.h"
#include "ficheiros.h"
#include "Estruturas.h"

void simulacao(int, FUNCIONARIO*, CAIXA_PAGAMENTO *, DADOS_CLIENTE *, GESTAO_HIPERMERCADO *, STOCK_PRODUTOS*);
void simulacao_com_paragens(int, CAIXA_PAGAMENTO * , GESTAO_HIPERMERCADO*, STOCK_PRODUTOS*, DADOS_CLIENTE*, FUNCIONARIO*);
void menu_simulacao();
void menu_estatisticas(CAIXA_PAGAMENTO*, GESTAO_HIPERMERCADO*, STOCK_PRODUTOS*, DADOS_CLIENTE*, FUNCIONARIO*);
void submenu_produtos(GESTAO_HIPERMERCADO *,STOCK_PRODUTOS*);
void submenu_clientes(DADOS_CLIENTE*, GESTAO_HIPERMERCADO*, CAIXA_PAGAMENTO*);
void submenu_caixas(CAIXA_PAGAMENTO *, FUNCIONARIO*);
int menu();

void gerar_clientes(DADOS_CLIENTE*, GESTAO_HIPERMERCADO *);
void saida_cliente(GESTAO_HIPERMERCADO*);
void manutencao_clientes(DADOS_CLIENTE*, GESTAO_HIPERMERCADO*, CAIXA_PAGAMENTO*);
void inserir_fila(DADOS_CLIENTE*, CAIXA_PAGAMENTO*);
NO* remover_da_fila(DADOS_CLIENTE*C, FILA*);


int num_medio_clientes_por_caixa(GESTAO_HIPERMERCADO *, CAIXA_PAGAMENTO*);
int pedir_codigo_cliente();
void n_clientes_numa_caixa(CAIXA_PAGAMENTO*);

DADOS_CLIENTE *pesquisar_cliente(DADOS_CLIENTE*, int);
void pesquisar_pessoa(DADOS_CLIENTE*, CAIXA_PAGAMENTO *, GESTAO_HIPERMERCADO*);     //ver se cliente se encontra no hipermercado
void mostrar_caixas(CAIXA_PAGAMENTO *);

void abrir_caixa(CAIXA_PAGAMENTO*, GESTAO_HIPERMERCADO*);
void manutencao_caixas(CAIXA_PAGAMENTO*, GESTAO_HIPERMERCADO*);

void fechar_caixa_com_menos_pessoas(CAIXA_PAGAMENTO *, GESTAO_HIPERMERCADO *);
void fechar_caixa_forcadamente(CAIXA_PAGAMENTO*);
void mudar_fila(CAIXA_PAGAMENTO *);
void mudar_caixa(CAIXA_PAGAMENTO*, CAIXA_PAGAMENTO*);

void mostrar_clientes_hipermercado(DADOS_CLIENTE*);
