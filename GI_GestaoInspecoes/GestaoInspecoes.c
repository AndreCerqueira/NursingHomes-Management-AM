#include <stdio.h>
#include <stdlib.h>
#include "GestaoInspecoes.h"


/*
	This procedure contains all the procedures for each option in the inspection management menu.
	@op = Option selected in the menu
	@inspections = inspections list
	@nI = Total amount of inspections
	@homes = homes list
	@nH = Total amount of homes
	@team = selected Team
*/
void InspectionsManagement(int *op, Inspection *inspections, int *nI, Home *homes, int nH, Team team)
{
	// The program only ends when the user chooses the option to exit in the Inspection Menu
	while (*op != 0)
	{
		// Choose the option for the Inspection Menu
		InspectionMenu(op);
	
		// Run the selected option
		switch (*op)
		{
			// Create an Inspection
			case 1:
				CreateInspection(inspections, nI, homes, nH, team);
			break;
			// Show Inspections
			case 2:
				ShowInspectionList(inspections, *nI, team.id);
				getch();
			break;
		}
	}
	*op = -1;
}


/*
	This procedure displays the Inspection Menu and returns via pointer an option selected in the menu
	@op = Option selected in the menu
*/
void InspectionMenu(int *op)
{
	// Reset Option
	*op = -1;
	
	// Menu
	system("cls");
	printf("+---------------------------------------+\n");
	printf("| %25s\t\t|\n", "Menu de Inspeções");
	printf("+---------------------------------------+\n");
	printf("|\t\t\t\t\t|\n");
	printf("| 1- Criar Inspeção \t\t\t|\n");
	printf("|\t\t\t\t\t|\n");
	printf("| 2- Lista de Inspeções\t\t\t|\n");
	printf("|\t\t\t\t\t|\n");
	printf("| 0- Voltar\t\t\t\t|\n");
	printf("|\t\t\t\t\t|\n");
	printf("+---------------------------------------+\n\n");
	
	// Select an option
	printf("Selecione uma opção: ");
	scanf("%d", op);
}


/*
	This procedure shows a table with all inspections
	@inspections = inspections list
	@n = Total amount of inspections
	@id = id of the selected team
*/
void ShowInspectionList(Inspection *inspections, int n, int id)
{
	// Variables
	int i;
	char district[50];
	
	// Menu
	system("cls");
	puts("+----------------------------------------------------------------------+");
	puts("|                         Lista de Inspeções                           |");
	puts("+----------------------------------------------------------------------+");
	puts("|  ID  |    Data    |       Equipa       |             Lar             |");
	puts("+----------------------------------------------------------------------+");
	for (i = 0; i < n; i++)
	{
		if (inspections[i].ativo == 1 && inspections[i].team.id == id)
		{
			// Convert district ID to text 
			GetDistrict(inspections[i].team.district, district);
		
			// Show data
			printf("| %*d  | %-10s | %-18s | %-27s |\n",
			-3, i, inspections[i].date, district, inspections[i].home.name);		
		}
	}
	puts("+----------------------------------------------------------------------+");
	
}


/*
	This procedure is responsible for creating a inspection.
	@inspections = inspections list
	@nI = Total amount of inspections
	@homes = homes list
	@nH = Total amount of homes
	@team = selected Team
*/
void CreateInspection(Inspection *inspections, int *nI, Home *homes, int nH, Team team)
{
	// Variables
	int id, i;
			
	// Show a table with all homes, the homes with most patients in the top
	SortHomesPatientQuantity(homes, nH);
	ShowHomeList(homes, nH, team.district);
	
	puts("+------------------------------+");
	puts("|     Criação de Inspeções     |");
	puts("+------------------------------+");
	puts("|   Selecione o ID de um Lar   |");
	puts("+------------------------------+");
		
	// Select a home ID
	id = SelectById(nH);
	
	// Exit condition
	if (id < 0)
		return;
	
	// Insert team
	inspections[*nI].team = SelectTeamMembers(team);
	
	// Insert a date
	GetDate(inspections[*nI].date);
	
	// Assign auto data
	inspections[*nI].team.district = team.district;
	inspections[*nI].team.id = team.id;
	inspections[*nI].ativo = 1;
	inspections[*nI].home = homes[id];
	*nI += 1;
}


/*
	This procedure is responsible for Reschedule an inspection.
	@inspections = inspections list
	@n = Total amount of inspections
	@id = id of the previous inspection
	@team = original team, used to select the team members again
*/
void RescheduleInspection(Inspection *inspections, int *n, int id, Team team)
{
	
	system("cls");
	puts("+-----------------------------+");
	puts("|      Remarcar Inspeção      |");
	puts("+-----------------------------+");
	puts("A avaliação final do lar foi insuficiente!");
	puts("Por favor remarque uma nova inspeção");
	getch();
		
	// Insert a new team
	inspections[*n].team = SelectTeamMembers(team);	
		
	// Insert a new date
	GetDate(inspections[*n].date);
		
	// Assign data
	inspections[*n].team = inspections[id].team;
	inspections[*n].home = inspections[id].home;
	inspections[*n].ativo = 1;
	*n += 1;	
		
}


/*
	This procedure is responsible for select members of one team for one inspection
	@originalTeam = original Team with all members
*/
Team SelectTeamMembers(Team originalTeam)
{
	// Variables
	int id = 0, countInspectionMembers = 0;
	Team newTeam;
	newTeam.memberCount = 0;
	
	// Add as many members as user want
	while (id >= 0)
	{
		// Call the procedure that show the members list of selected team
		ShowInspectionMembersList(originalTeam, newTeam);
			
		puts("-------------------------------------");
		puts("|  Escolher membros para inspeção   |");
		puts("-------------------------------------");
		
		// select member id
		printf("Para concluir insira um ID negativo.\n");
		printf("Insira um ID: ");
		do 
			scanf("%d", &id);
		while (id >= originalTeam.memberCount);
		
		// Exit condition
		if (id < 0)
		{
			// Verify if there is at least one member per job in the team
			if (ValidateTeam(newTeam) == 0)
				id = 0;
				
			continue;
		}
		
		// Add the member to the inspection list and increment the member counter
		newTeam.members[newTeam.memberCount] = originalTeam.members[id];
		newTeam.memberCount++;
	} 
	
	// Return selected members in a new team
	return newTeam;
}











