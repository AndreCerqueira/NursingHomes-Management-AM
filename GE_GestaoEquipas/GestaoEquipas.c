#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestaoEquipas.h"


/*
	This procedure contains all the procedures for each option in the Team management menu for the MAI user.
	@op = Option selected in the menu
	@teams = teams list
	@teamCounter = Total amount of teams
*/
void TeamsManagement(int *op, Team *teams, int *teamCounter)
{		
	// The program ends only when the user chooses the option to exit the Team Menu
	while (*op != 0)
	{
		// Choose Team Menu option
		TeamMenu(op);
	
		// Run the selected option
		switch (*op)
		{
			// Create a Team
			case 1:
				CreateTeam(teams, teamCounter);
			break;
			// Show a list of teams
			case 2:
				ShowTeamList(teams, *teamCounter);
				getch();
			break;
			// Edit a team as a MAI user
			case 3:
				EditTeam(op, teams, *teamCounter, -1);
			break;
		}
	}
	*op = -1;
}


/*
	This procedure displays the Team Menu and returns via pointer an option selected in the menu
	@op = Option selected in the menu
*/
void TeamMenu(int *op)
{
	// Reset option
	*op = -1;
	
	// Menu
	system("cls");
	puts("+---------------------------------------+");
	puts("|            Menu de Equipas            |");
	puts("+---------------------------------------+");
	puts("|                                       |");
	puts("| 1- Criar Equipa                       |");
	puts("|                                       |");
	puts("| 2- Lista de Equipas                   |");
	puts("|                                       |");
	puts("| 3- Editar Equipa                      |");
	puts("|                                       |");
	puts("| 0- Voltar                             |");
	puts("|                                       |");
	puts("+---------------------------------------+");
	
	// Select option
	printf("Selecione um numero: ");
	scanf("%d", op);
}


/*
	This procedure contains all the procedures for each option in the Team management menu for the team leader user.
	@op = Option selected in the menu
	@teams = teams list
	@teamCounter = Total amount of teams
	@user = -1 means the user is MAI if user is MAI he needs to select a team, other number is the id of the team
*/
void EditTeam(int *op, Team *teams, int teamCounter, int user)
{		
	// Variables
	int id;

	// Verify the user that want to edit the team. -1 means MAI
	if (user == -1)
	{
		// Select the team id
		ShowTeamList(teams, teamCounter);
		id = SelectById(teamCounter);
		
		// Exit condition
		if (id < 0)
			return;
	}
	else
		id = user;

	// The program ends only when the user chooses the option to exit the Team Menu
	while (*op != 0)
	{
		// Choose Team Menu option
		EditTeamMenu(op, teams, id);
	
		// Run the selected option
		switch (*op)
		{
			// Add a member to the team
			case 1:
				teams[id].members[teams[id].memberCount] = AddMember(teams[id].memberCount);
				teams[id].memberCount++;
				break;
				
			// Remove a member of the team
			case 2:
				DeleteMember(&teams[id]);
				break;
				
			// Show the members of the team
			case 3:
				ShowMembersList(teams[id]);
				getch();
				break;
				
			// Request the vehicles of the team
			case 4:
				teams[id].vehicles[teams[id].vehicleCount] = AddVehicle(teams[id].vehicleCount);
				teams[id].vehicles[teams[id].vehicleCount].driver = SelectDriver(teams[id]);
				teams[id].vehicleCount++;
				break;
				
			// Show the vehicles of the team
			case 5:
				ShowVehiclesList(teams[id]);
				getch();
				break;
		}
	}
	*op = -1;
}


/*
	This procedure displays the Team Menu and returns via pointer an option selected in the menu
	@op = Option selected in the menu
*/
void EditTeamMenu(int *op, Team *teams, int id)
{
	// Variables
	char districtText[50];
	
	// Reset option
	*op = -1;
	
	// Convert district ID to text 
	GetDistrict(teams[id].district, districtText);
	
	// Menu
	system("cls");
	puts("+---------------------------------------+");
	printf("| Editar Equipa %-24s|\n", districtText);
	puts("+---------------------------------------+");
	puts("|                                       |");
	puts("| 1- Adicionar Membro                   |");
	puts("|                                       |");
	puts("| 2- Remover Membro                     |");
	puts("|                                       |");
	puts("| 3- Lista de Membros                   |");
	puts("|                                       |");
	puts("| 4- Requisitar Veículo                 |");
	puts("|                                       |");
	puts("| 5- Lista de Veículos                  |");
	puts("|                                       |");
	puts("| 0- Voltar                             |");
	puts("|                                       |");
	puts("+---------------------------------------+");
	
	// Select option
	printf("Selecione um numero: ");
	scanf("%d", op);
}


/*
	Procedure to show a list of created Teams
	@teams = teams list
	@n = Total amount of teams
*/
void ShowTeamList(Team *teams, int n)
{
	// Variables
	int i, j, countMember = 0;
	char district[50];
	
	// Show teams
	system("cls");
	puts("+------------------------------------------------+");
	puts("|                Lista de Equipas                |");
	puts("+------------------------------------------------+");
	puts("| ID  |     Distrito      |  Objetivo  | Membros |");
	puts("+------------------------------------------------+");
	for (i = 0; i < n; i++)
	{
		// Convert district ID to text 
		GetDistrict(teams[i].district, district);
		
		// pre-requesits to count active members
		for (j= 0; j < teams[i].memberCount; j++)
		{
			if (teams[i].members[j].active == 1) 
				countMember++;	
		}
		
		// Show line
		printf("| %*d | %-17s |   %02d/%02d    | %*d |\n"
		, -3, i, district, teams[i].progress, teams[i].objective, -7, countMember);
		
		countMember = 0;	
	}
	puts("+------------------------------------------------+");
	
}


/*
	Procedure to show a list of members of a Team
	@team = team selected
*/
void ShowMembersList(Team team)
{
	// Variables
	int i;
	Member *members = team.members;
	char district[50];
	
	// Convert district ID to text 
	GetDistrict(team.district, district);
	
	// Show members
	system("cls");
	puts("+-------------------------------------------------------------------------------------------------------+");
	printf("|                                 Lista de Membros da Equipa %-37s      |\n", district);
	puts("+-------------------------------------------------------------------------------------------------------+");
	puts("| ID  |          Nome          |      Profissão       |  Telemóvel  |     CC     | CCRP | Data Validade |");
	puts("+-------------------------------------------------------------------------------------------------------+");
	for (i = 0; i < team.memberCount; i++)
	{
		// Show only the active members
		if (members[i].active == 1) 
		{
			printf("| %*d | %-22s | %-20s | %-11s | %-10s | %-4s |  %-12s |"
			, -3, i, members[i].name, members[i].job, members[i].telephoneNumber, members[i].cc, members[i].ccrp, members[i].expirationDate);
		
			if (team.leader.id == i)
				printf("-> LIDER");
				
			printf("\n");	
		}
	}
	puts("+-------------------------------------------------------------------------------------------------------+");
}


/*
	Procedure to show a list of members of a Team selected in an inspection
	@originalTeam = team selected
	@newTeam = team with the selected members
*/
void ShowInspectionMembersList(Team originalTeam, Team newTeam)
{
	// Variables
	int i, j;
	Member *members = originalTeam.members;
	char district[50];
	
	// Convert district ID to text 
	GetDistrict(originalTeam.district, district);
	
	// Show members
	system("cls");
	puts("+-----------------------------------------------------------------------------------------------------------------+");
	printf("|                                        Lista de Membros da Equipa %-44s  |\n", district);
	puts("+-----------------------------------------------------------------------------------------------------------------+");
	puts("| ID  |          Nome          |      Profissão       |  Telemóvel  |     CC     | CCRP | Data Validade | Seleção |");
	puts("+-----------------------------------------------------------------------------------------------------------------+");
	for (i = 0; i < originalTeam.memberCount; i++)
	{
		// Show only the active members
		if (members[i].active == 1) 
		{
			printf("| %*d | %-22s | %-20s | %-11s | %-10s | %-4s |  %-12s |"
			, -3, i, members[i].name, members[i].job, members[i].telephoneNumber, members[i].cc, members[i].ccrp, members[i].expirationDate);
			
			// See if the member is already selected to the inspection
			for (j = 0; j < newTeam.memberCount; j++)
			{
				if (members[i].id == newTeam.members[j].id)
					members[i].id = -1;	
			}
			
			// Show the members selected to the inspection with an [X]
			printf("%s", (members[i].id == -1) ? "   [X]   |" : "   [ ]   |" );
				
			printf("\n");
		}
	}
	puts("+-----------------------------------------------------------------------------------------------------------------+");
}


/*
	Function to create a member
	@id = intended member id
*/
Member AddMember(int id)
{
	// Variables
	int job = 0, ccrp = 0;
	Member member;
	
	system("cls");
	puts("+-------------------------------+");
	printf("|\tAdicionar Membro %-2d\t|\n", id);
	puts("+-------------------------------+");

	// Input Name
	printf("Nome: ");
	GetText(member.name);

	// Insert a cityzen card 
	printf("Cartão de Cidadão: ");
	GetText(member.cc);
	
	// Insert a phone number 
	printf("Número de Telemóvel: ");
	GetText(member.telephoneNumber);
	
	// Insert adress 
	printf("Morada: ");
	GetText(member.address);

	// Inserir Profissão
	puts("[1] > Médico | [2] > Enfermeiro | [3] > Assistente Social | [4] > Técnico de Saúde Ambiental Social");
	printf("Insira a Profissão: ");
	do
		scanf("%d", &job);
	while (job != 1 && job != 2 && job != 3 && job != 4);

	// Insert ccrp
	printf("\n[1] > Sim | [2] > Não");
	printf("\nCarta de Condução: ");
	do
		scanf("%d", &ccrp);
 	while (ccrp != 1 && ccrp != 2);
		
	// Insert a experation date 
	if (ccrp == 1)
	{
		printf("Data de validade da carta: \n");
		GetDate(member.expirationDate);
	}
	else
		strcpy(member.expirationDate, "--/--/----");
	
	
	// Assign a Job depending on the number 
	switch(job)
	{
		case 1: 
			strcpy(member.job, "Médico");
			break;
		case 2: 
			strcpy(member.job, "Enfermeiro");
			break;
		case 3: 
			strcpy(member.job, "Assistente Social");
			break;
		case 4: 
			strcpy(member.job, "Tec. Saúde Ambiental");
			break;
	}
	
	// Assign CCRP (yes or no)
	switch (ccrp)
	{
		case 1: 
			strcpy(member.ccrp, "Sim");
			break;
		case 2: 
			strcpy(member.ccrp, "Não");
			break;
	}

	// Auto data
	member.id = id;
	member.active = 1;
	
	return member;
}


/*
	Procedure to create a Team
	@teams = teams list
	@n = Total amount of teams
*/
void CreateTeam(Team *teams, int *n)
{
	// Variables
	int vehicleCount, i, id, memberCount = 0;
	
	// Initial Settings
	teams[*n].leader.id = -1;
	teams[*n].memberCount = 0;
	
	// Collect data for the Team
	system("cls");
	puts("+-------------------------------+");
	puts("|\tCriação da Equipa\t|");
	puts("+-------------------------------+");

	// show available districts for the team and select the district
	ShowAvailableDistricts(teams, n);
	printf("Para Voltar insira um ID negativo.\n");
	printf("Escolha o id do distrito: ");
	scanf("%d", &id);
	
	// Exit Condition
	if (id <= 0)
		return;
	else
		teams[*n].district = id;

	// Insert Objective
	printf("\nObjetivo da Equipa: ");
	scanf("%d", &teams[*n].objective);
	
	// Insert Team quantity
	printf("\nQuantidade da Membros: ");
	scanf("%d", &memberCount);
	
	// this verify if have one member per professional category if not creat one 
	while (teams[*n].memberCount < memberCount || ValidateTeam(teams[*n]) == 0)
	{
		teams[*n].members[teams[*n].memberCount] = AddMember(teams[*n].memberCount);
		teams[*n].memberCount++;	
	}
	
	// Choose a member to become the team leader
	ShowMembersList(teams[*n]);
	puts("+------------------------------+");
	puts("|   Designar Lider da Equipa   |");
	puts("+------------------------------+");
	printf("Insira um ID: ");
	do 
		scanf("%d", &id);
	while (id < 0 || id >= teams[*n].memberCount);

	// Insert the vehicles quantity
	printf("\n[Minimo: 1]\n");
	printf("Quantidade de Veículos: ");
	do
		scanf("%d", &vehicleCount);
	while (vehicleCount < 1 || vehicleCount > MAX_STRUCTS);
	
	// Insert vehicles and select drivers for them	
	for (i = 0; i < vehicleCount; i++)
	{
		teams[*n].vehicles[i] = AddVehicle();
		teams[*n].vehicles[i].driver = SelectDriver(teams[*n]);
	}	
	
	// Auto data
	teams[*n].id = *n;
	teams[*n].progress = 0;
	teams[*n].vehicleCount = vehicleCount;
	teams[*n].leader = teams[*n].members[id];
	*n += 1;
}


/*
	Procedure to show all veicles and drivers of a team
	@team = selected team
*/
void ShowVehiclesList(Team team)
{
	// Variables
	int i;
	Vehicle *vehicles = team.vehicles;
	char district[50];
	
	// Convert district ID to text 
	GetDistrict(team.district, district);
	
	// Show all vehicles and drivers of a team
	system("cls");
	puts("+---------------------------------------------------+");
	printf("|       Lista de Veículos da Equipa %-16s|\n", district);
	puts("+---------------------------------------------------+");
	puts("| ID  | Capacidade |  Matricula  |     Condutor     |");
	puts("+---------------------------------------------------+");
	for (i = 0; i < team.vehicleCount; i++)
		printf("| %*d | %*d | %-11s | %-16s |\n"
		, -3, i, -10, vehicles[i].capacity, vehicles[i].licensePlate, vehicles[i].driver.name);
	puts("+---------------------------------------------------+");
	
}


/*
	Funtion to create a vehicle for a team
*/
Vehicle AddVehicle()
{
	// Variables
	Vehicle vehicle;
	
	system("cls");
	puts("+-------------------------------+");
	printf("|\tCriar Veículo\t\t|\n");
	puts("+-------------------------------+");
	
	// Insert maximum vehicle capacity
	printf("Insira a capacidade máxima do veículo: ");
	scanf("%d", &vehicle.capacity);
	
	// Insert vehicle license plate
	printf("Insira a matrícula do veículo: ");
	GetLicensePlate(vehicle.licensePlate);
	
	return vehicle;
}


/*
	Function to select a driver for a vehicle and return the driver
	@team = selected team
*/
Member SelectDriver(Team team)
{
	// Variables
	int i, id;
	Member *members = team.members;
	char district[50];
	
	// Convert district ID to text 
	GetDistrict(team.district, district);
	
	// Show all members with CCRP
	system("cls");
	puts("+-------------------------------------------------------------------------------------------------------+");
	printf("|                            Lista de Membros da Equipa com carta %-34s  |\n", district);
	puts("+-------------------------------------------------------------------------------------------------------+");
	puts("| ID  |          Nome          |      Profissão       |  Telemóvel  |     CC     | CCRP | Data Validade |");
	puts("+-------------------------------------------------------------------------------------------------------+");
	for (i = 0; i < team.memberCount; i++)
	{
		if (stricmp(members[i].ccrp, "Sim") == 0 && members[i].active == 1)
				printf("| %*d | %-22s | %-20s | %-11s | %-10s | %-4s |  %-12s |\n"
			, -3, i, members[i].name, members[i].job, members[i].telephoneNumber, members[i].cc, members[i].ccrp, members[i].expirationDate);	
	}
	puts("+-------------------------------------------------------------------------------------------------------+");
	
	// Select a driver
	puts("+-------------------------------+");
	printf("|\tDesignar Condutor\t|\n");
	puts("+-------------------------------+");
	id = SelectById(team.memberCount);
	
	// Exit condition
	if (id < 0)
		return;
	
	return members[id];
}


/*
	This procedure is responsible for showing available districts.
	@teams = all teams
	@n = number of teams 
*/
void ShowAvailableDistricts(Team *teams, int *n)
{
	char s[20];
	int i, j, encontrou = 0;
	
	// Show all districts available
	printf("+--------------------------------+\n");	
	for (i = 1; i < MAX_DISTRICTS; i++)
	{
		encontrou = 0;
		
		// see if the district is already used
		for (j = 0; j < *n && encontrou == 0; j++)
		{
			if (teams[j].district == i)
				encontrou = 1;
		}
		
		// if the district is available
		if (encontrou == 0)
		{
			GetDistrict(i, s);
			printf("| %2d - %-25s |\n", i, s);
		}
	}
	printf("+--------------------------------+\n");
}


/*
	This verify if have one member per professional category
	@team = selected team
*/
int ValidateTeam(Team team)
{
	// variables
	int medCount = 0, nurCount = 0, assCount = 0, tecCount = 0, ccrpCount = 0, i;

	// in this loop we count how many members a profession have 
	for (i = 0; i < team.memberCount; i++)
	{
		if (team.members[i].active == 1) 
		{
			if (stricmp(team.members[i].ccrp, "Sim") == 0)
			{
				ccrpCount++;
			}
			
			if (stricmp(team.members[i].job, "Médico") == 0)
			{
				medCount++;
			}
			else if (stricmp(team.members[i].job, "Enfermeiro") == 0)
			{
				nurCount++;
			} 
			else if (stricmp(team.members[i].job, "Assistente Social") == 0) 
			{
				assCount++;
			}
			else if (stricmp(team.members[i].job, "Tec. Saúde Ambiental") == 0)
			{
				tecCount++;
			}
		}
	}
	
	// verify if have more than one member per job
	if (medCount > 0 && nurCount > 0 && assCount > 0 && tecCount > 0 && ccrpCount > 0) 
		return 1;
	else
	{
		// show what is missing in the team
		puts("");
		puts("Tem de inserir pelo menos um membro de cada categoria profissional e um elemento com carta!");
		puts("");
		puts("A equipa:");
		printf("-> Médicos: %d\n", medCount);
		printf("-> Enfermeiros: %d\n", nurCount);
		printf("-> Assistentes Socias: %d\n", assCount);
		printf("-> Tec. Sáude Ambiental: %d\n", tecCount);
		printf("-> Membros com carta de condução: %d\n", ccrpCount);
			
		getch();
	}
		
	return 0;
}


/*
	This procedure is responsible for deleting a member in a team
	@team = selected team
*/
void DeleteMember(Team *team)
{
	// Variables
	int id;
	Team temp = *team;
	
	// Show active members on team
	ShowMembersList(*team);
	
	puts("+------------------------------+");
	puts("|        Remover Membro        |");
	puts("+------------------------------+");
	
	// Select a member ID
	id = SelectById(team->memberCount);
	
	// Exit condition
	if (id < 0)
		return;
	
	// Remove temporary a member to verify if its possible	
	temp.members[id].active = 0;
	
	// validate team to see if there is enough members of each job
	if (ValidateTeam(temp) == 1)
	{
		if (team->members[id].id == team->leader.id)
			printf("Não pode remover o Lider da Equipa!");
		else
		{
			team->members[id].active = 0;
			puts("");
			printf("Membro removido com sucesso!");
		}
		getch();
	}
	
}













