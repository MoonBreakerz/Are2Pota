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
funcionario aux[5];

int i =0;



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


void imprimirdesc()
{
	for(i= 4; i>=0;i--)
	{
		printf("\nNome: %s", func[i].nome);
		printf("\nIdade: %d", func[i].idade);
		printf("\nMatricula: %d", func[i].matricula);
		printf("\nAltura: %d", func[i].altura);
		printf("\nSalario: %.2f\n", func[i].salario);
	}
	system("pause");
}



void mergeid(funcionario func[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    

    while(com1 <= meio && com2 <= fim){
        if(func[com1].idade < func[com2].idade) {
            aux[comAux] = func[com1];
            com1++;
        } else {
            aux[comAux] = func[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){ 
        aux[comAux] = func[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   
        aux[comAux] = func[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){   
        func[comAux] = aux[comAux-comeco];
    }
    
}

void mergeSortid(funcionario func[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSortid(func, comeco, meio);
        mergeSortid(func, meio+1, fim);
        mergeid(func, comeco, meio, fim);
    }
}


void mergesal(funcionario func[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    

    while(com1 <= meio && com2 <= fim){
        if(func[com1].salario < func[com2].salario) {
            aux[comAux] = func[com1];
            com1++;
        } else {
            aux[comAux] = func[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  
        aux[comAux] = func[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   
        aux[comAux] = func[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){   
        func[comAux] = aux[comAux-comeco];
    }
    
}

void mergeSortsal(funcionario func[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSortsal(func, comeco, meio);
        mergeSortsal(func, meio+1, fim);
        mergesal(func, comeco, meio, fim);
    }
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
			case 2: mergeSortsal(func,0,4);imprimirdesc();break;
			case 3: mergeSortid(func,0,4);;imprimirdesc();break;
			case 4: exit(1);
		}
		system("cls");
	}while(1);
}
