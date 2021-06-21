#include <stdio.h>
#include <string.h>

struct node
{
	int matricula;
	char nome[20];
	double nota;
	struct node *next;
};

typedef struct node node;

void ordenar(node *head)
{
	int aux_matricula, tamanho, tamanho_aux, i;
	double aux_nota;
	char aux_nome[20];
	node* hi;
	node* hj;
	node* hfim = NULL;

	for(hi = head; hi -> next != NULL; hi = hi -> next)
	{
		for(hj = head; hj -> next != hfim; hj = hj -> next)
		{
			if(hj -> nota > hj -> next -> nota)
			{
				strcpy(aux_nome, hj -> nome);
				aux_nota = hj -> nota;
				aux_matricula = hj -> matricula;

				strcpy(hj -> nome, hj -> next -> nome);
				hj -> nota = hj -> next -> nota;
				hj -> matricula = hj -> next -> matricula;

				strcpy(hj -> next -> nome, aux_nome);
				hj -> next -> nota = aux_nota;
				hj -> next -> matricula = aux_matricula;
			}
			else if(hj -> nota == hj -> next -> nota)
			{
			    if(hj -> matricula > hj -> next -> matricula)
			    {
				    strcpy(aux_nome, hj -> nome);
				    aux_nota = hj -> nota;
				    aux_matricula = hj -> matricula;

				    strcpy(hj -> nome, hj -> next -> nome);
				    hj -> nota = hj -> next -> nota;
				    hj -> matricula = hj -> next -> matricula;
				    
				    strcpy(hj -> next -> nome, aux_nome);
				    hj -> next -> nota = aux_nota;
				    hj -> next -> matricula = aux_matricula;
			    }
		    }
		}

		hfim = hj;
	}
}

void verifica(node *lista, double valor)
{
	while(lista != NULL)
	{
		if(lista -> nota >= valor)
		{
			printf("Matricula: %d Nome: %s Nota: %.1lf\n", lista -> matricula, lista -> nome, lista -> nota);
		}
		lista = lista -> next;
	}
}

node* add(node *lista, int matri, char name[], int tamanho, double not)
{
    int i = 0;
	node *new_node = (node*) malloc(sizeof(node));
	while(i < tamanho)
	{
	    new_node -> nome[i] = name[i];
	    i++;
	}
	new_node -> nota = not;
	new_node -> matricula = matri;
	new_node -> next = lista;
	return new_node;
}

node* criar_lista()
{
	return NULL;
}

int main()
{
	node* lista = criar_lista();
	node* lista2 = criar_lista();

	int quantidade, i = 0, matri, tamanho;
	char nome[20];
	double nota, valor = 0;

	scanf("%d\n", &quantidade);

	while(i < quantidade)
	{
		scanf("%d\n", &matri);
		scanf("%[^\n]", nome);
		getchar();
		tamanho = strlen(nome);
		scanf("%lf\n", &nota);
		lista = add(lista, matri, nome, tamanho, nota);
		i++;
	}

	ordenar(lista);

	i = 0, lista2 = lista;

	while(lista2 != NULL)
	{
		valor += lista2 -> nota;
		lista2 = lista2 -> next;
	}

	verifica(lista, valor/quantidade);
	
	printf("Media = %.2lf", valor/quantidade);

	return 0;
}