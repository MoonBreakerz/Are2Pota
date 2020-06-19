#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char nome[50];
	float salario;
	int matricula, altura, idade;
	
}funcionario;

//Lista ja preenchida para facilitar uso do programa.
funcionario func[5] = {{"Gabriel", 9500, 111, 175, 24}, {"Elis", 300.5, 222, 155, 19}, {"Dani", 700, 333, 156, 24}, {"Rebecca", 1000,444,160,25}, {"Aria", 5000,555,165,18}};

int i =0;
void imprimir();



int compareid (const void * a, const void * b)
{

  funcionario *funcionarioA = (funcionario *)a;
  funcionario *funcionarioB = (funcionario *)b;

  if ( funcionarioA->idade < funcionarioB->idade )
         return 1;
     else if ( funcionarioA->idade > funcionarioB->idade )
         return -1;
     else return 0;
}

int comparesal (const void * a, const void * b)
{

  funcionario *funcionarioA = (funcionario *)a;
  funcionario *funcionarioB = (funcionario *)b;

  if ( funcionarioA->salario < funcionarioB->salario )
         return 1;
     else if ( funcionarioA->salario > funcionarioB->salario )
         return -1;
     else return 0;
}

void imprimir()
{
	for(i= 0; i<5;i++)
	{
		printf("\nNome: %s", func[i].nome);
		printf("\nIdade: %d", func[i].idade);
		printf("\nMatricula: %d", func[i].matricula);
		printf("\nAltura: %d", func[i].altura);
		printf("\nSalario: %.2f", func[i].salario);
	}
	system("pause");
}

void ordenarid()
{
	qsort (func, 5, sizeof(funcionario), compareid);	
	imprimir();
}

void ordenarsal()
{
	qsort (func, 5, sizeof(funcionario), comparesal);	
	imprimir();
}

main()
{
	int op;
	do
	{
		printf("\t\tMENU\n1 - Imprimir Lista\n2 - Ordenar salarios e mostrar em tela\n3 - Ordenar idades e mostrar em tela\n4 - Sair\n\nEscolha: ");
		scanf("%d",&op);
		system("cls");
		switch(op)
		{
			case 1: imprimir(); break;
			case 2: ordenarsal();break;
			case 3: ordenarid();break;
			case 4: exit(1);
		}
		system("cls");
	}while(1);
}
