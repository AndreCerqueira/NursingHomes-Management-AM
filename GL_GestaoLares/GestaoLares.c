#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestaoLares.h"


/*
	This procedure contains all the procedures for each option in the nursing home management menu.
	@op = Option selected in the menu
	@district = district of the selected team
	@homes = Nursing home list
	@homeCounter = Total amount of Nursing homes
*/
void NursingHomesManagement(int *op, int district, Home *homes, int *homeCounter)
{	
	// The program only ends when the user chooses the option to exit in the Home Menu
	while (*op != 0)
	{
		// Choose the option for the Home Menu
		NursingHomeMenu(op);
	
		// Run the selected option
		switch (*op)
		{
			// Create a home
			case 1:
				CreateHome(district, homes, homeCounter);
			break;
			// Select and view a home
			case 2:
				SortHomesRating(homes, *homeCounter);
				ShowHome(homes, *homeCounter, district);
			break;
		}
	}
	*op = -1;
}


/*
	This procedure displays the Nursing Home Menu and returns via pointer an option selected in the menu
	@op = Option selected in the menu
*/
void NursingHomeMenu(int *op)
{
	// Reset Option
	*op = -1;
	
	// Menu
	system("cls");
	printf("+---------------------------------------+\n");
	printf("| %25s\t\t|\n", "Menu de Lares");
	printf("+---------------------------------------+\n");
	printf("|\t\t\t\t\t|\n");
	printf("| 1- Criar Lar \t\t\t\t|\n");
	printf("|\t\t\t\t\t|\n");
	printf("| 2- Consultar Lares\t\t\t|\n");
	printf("|\t\t\t\t\t|\n");
	printf("| 0- Sair\t\t\t\t|\n");
	printf("|\t\t\t\t\t|\n");
	printf("+---------------------------------------+\n\n");
	
	// Select an option
	printf("Selecione uma opção: ");
	scanf("%d", op);
}


/*
	This procedure shows a table with all nursing homes
	@homes = Nursing home list
	@n = Total amount of Nursing homes
	@district = district id of the team
*/
void ShowHomeList(Home *homes, int n, int district)
{
	// Variables
	int i;
	
	// Show nursing homes
	system("cls");
	puts("+------------------------------------------------------------------------------------------------------------------+");
	puts("|                                                   Lista de Lares                                                 |");
	puts("+------------------------------------------------------------------------------------------------------------------+");
	puts("| ID  |             Nome              | Quantidade |  Quantidade   |  Quantidade  |       Morada       | Avaliação |");
	puts("|     |                               |  Utentes   | Utentes Risco | Funcionarios |                    |           |");
	puts("+------------------------------------------------------------------------------------------------------------------+");
	for(i = 0; i < n; i++)
	{
		// show only the homes in the same district as the team
		if (homes[i].district == district)
		{
			printf("| %*d | %-29s | %*d | %*d | %*d | %-18s |"
			, -3, i, homes[i].name, -10, homes[i].patientQuantity,  -13, homes[i].riskPatientQuantity, -12, homes[i].employeeQuantity, homes[i].address, homes[i].evaluation);
			
			// Only show the evaluation if the home already have
			if (homes[i].evaluation == -1)
				printf("    Na     |\n");
			else
				printf("   %02d/10   |\n", homes[i].evaluation);
		}
	}
	puts("+------------------------------------------------------------------------------------------------------------------+");
}


/*
	This procedure shows a table with all nursing homes
	@homes = Nursing home list
	@n = Total amount of Nursing homes
	@district = district id of the team
*/
void ShowHome(Home *homes, int n, int district)
{
	// Variables
	int id, i;
	char question[50];
	
	// Show a table with all nursing homes
	ShowHomeList(homes, n, district);
	
	puts("+------------------------------+");
	puts("| Consultar Informações do Lar |");
	puts("+------------------------------+");
	
	// Select a home ID
	id = SelectById(n);
	
	// Exit condition
	if (id < 0)
		return;
		
	// Show all informations of the Home
	system("cls");
    puts("+-------------------------------------------------------+");
    printf("| Informações do Lar %-35s|\n", homes[id].name);
    puts("+-------------------------------------------------------+");
    puts("|                                                       |");
    if (homes[id].evaluation == -1)
    	printf("|                Avaliação Geral: Na                    |\n");
    else
    	printf("|                Avaliação Geral: [%02d/10]               |\n", homes[id].evaluation);
    puts("|                                                       |");
    puts("| Condições:                                            |");
    puts("|                                                       |");
    
    // evaluation loop of the home
    for (i = 0; i < MAX_QUESTION; i++)
    {
    	GetHomeQuestion(i, question);
    	printf("| %d) ", i+1);
		printf("%-43s", question);
    	printf("[%02d/10] |\n", homes[id].questionsHome[i]);	
	}
	
    puts("|                                                       |");
 	puts("| Staff:                                                |");
 	
	// Employee loop of the home
	for (i = 0; i < homes[id].employeeQuantity; i++)
	{
		printf("|   >      Nome: %-29s          |\n", homes[id].employees[i].name);	
		printf("|   > Telémovel: %-29s          |\n", homes[id].employees[i].telephoneNumber);	
		puts("|                                                       |");
	}
	
 	puts("|                                                       |");	
 	puts("+-------------------------------------------------------+");
 	
 	// Pause
 	getch();
}


/*
	Procedure to add a Employee to the home
*/
Employee AddEmployee()
{
	// Variables
	int job = 0, ccrp = 0;
	Employee employee;
	
	system("cls");
	puts("+-------------------------------+");
	puts("|        Adicionar Staff        |");
	puts("+-------------------------------+");
	
	// Insert name
	printf("Nome: ");
	GetText(employee.name);
	
	// Inserir telephone number
	printf("Número Telémovel: ");
	GetText(employee.telephoneNumber);
	
	return employee;
}


/*
	This procedure is responsible for creating a nursing home.
	@district = district id of the team
	@homes = Nursing home list
	@n = Total amount of Nursing homes
*/
void CreateHome(int district, Home *homes, int *n)
{
	// Variables
	int i;
	
	// Insert home Data
	system("cls");
	puts("+-------------------------------+");
	puts("|\tCriação de Lares\t|");
	puts("+-------------------------------+");
	printf("Insira o nome do lar: ");
	GetText(homes[*n].name);
	printf("Insira a quantidade de funcionarios: ");
	scanf("%d", &homes[*n].employeeQuantity);
	printf("Insira a quantidade de utentes: ");
	scanf("%d", &homes[*n].patientQuantity);
	printf("Insira a quantidade de utentes de risco: ");
	scanf("%d", &homes[*n].riskPatientQuantity);
	printf("Insira a morada: ");
	GetText(homes[*n].address);
	
	// Insert employees
	for (i = 0; i < homes[*n].employeeQuantity; i++)
		homes[*n].employees[i] = AddEmployee();
	
	// Auto data
	homes[*n].district = district;
	homes[*n].evaluation = -1;
	*n += 1;
}


/*
	This procedure is responsible for sort homes by rating (wortes rates in top)
	@homes = Nursing home list
	@n = Total amount of Nursing homes
*/
void SortHomesRating(Home *homes, int n)
{
	// Variables
	int i, j;
	Home temp;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n - 1; j++)
		{
			if(homes[j].evaluation > homes[j + 1].evaluation)
			{
				temp = homes[j];
				homes[j] = homes[j + 1];
				homes[j + 1] = temp;
			}
		}
	}
}


/*
	This procedure is responsible for sort homes by patient quantity
	@homes = Nursing home list
	@n = Total amount of Nursing homes
*/
void SortHomesPatientQuantity(Home *homes, int n)
{
	// Variables
	int i, j;
	Home temp;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n - 1; j++)
		{
			if(homes[j].patientQuantity + homes[j].riskPatientQuantity < homes[j + 1].patientQuantity + homes[j + 1].riskPatientQuantity)
			{
				temp = homes[j];
				homes[j] = homes[j + 1];
				homes[j + 1] = temp;
			}
		}
	}
}







