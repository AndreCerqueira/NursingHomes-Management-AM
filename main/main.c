#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "..\Utilis\Utilis.c"
#include "..\GL_GestaoLares\GestaoLares.c"
#include "..\GE_GestaoEquipas\GestaoEquipas.c"
#include "..\GI_GestaoInspecoes\GestaoInspecoes.c"
#include "..\GR_GestaoRelatorios\GestaoRelatorios.c"
#include "..\Estatisticas\Estatisticas.c"
#include "..\Hardcode\Hardcode.c"


// Signatures
void HomeMenu(int *op);
void MultiTeamMenu(int *op, int district);
void MaiMenu(int *op);


int main(int argc, char *argv[]) 
{
	// Variables
	Home homes[70];
	Inspection inspections[MAX_STRUCTS];
	Report reports[MAX_STRUCTS];
	Team teams[23];
	int op = -1, id, homeCounter = 0, inspectionCounter = 0, reportCounter = 0, teamCounter = 0;
	
	// Initial Settings
   	setlocale(LC_ALL, "Portuguese");
   	LoadHomeData(homes, &homeCounter);
   	LoadTeamData(teams, &teamCounter);
   	LoadInspectionData(inspections, &inspectionCounter, teams, homes);
   	LoadReportData(reports, &reportCounter, inspections, teams, homes);
   	
   	// The program ends only when the user chooses the option to exit the Home Menu
	while(op != 0)
	{
		// Choose the option from the home menu
		HomeMenu(&op);
		
		// Exit condition
		if (op == 0)
			continue;
			
		// Enter the Multidisciplinary Teams Menu
		if (op == 1)
		{
			// Select the team id
			ShowTeamList(teams, teamCounter);
			id = SelectById(teamCounter);
			
			// Exit condition
			if (id < 0)
				continue;
				
			// The user only exits that menu after selecting 0- Back
			while (op != 0)
			{	
				// Choose Option within the Multidisciplinary Teams Menu
				MultiTeamMenu(&op, teams[id].district);
				
				// Run the selected option
				switch (op)
				{
					// Edit the team as a Team user
					case 1:
						EditTeam(&op, teams, teamCounter, id);
						break;
						
					// Nursing Homes Management Option
					case 2:
						NursingHomesManagement(&op, teams[id].district, homes, &homeCounter);
						break;
						
					// Inspections Management Option
					case 3:
						InspectionsManagement(&op, inspections, &inspectionCounter, homes, homeCounter, teams[id]);
						break;
						
					// Create Report Option
					case 4:
						CreateReport(reports, &reportCounter, inspections, &inspectionCounter, &teams[id], homes);
						break;
				}
			}
			op = -1;
		}
		// Enter the MAI Menu
		else if (op == 2)
		{
			// The user only exits this menu after selecting 0- Back
			while (op != 0)
			{
				// Choose Option within the MAI Menu
				MaiMenu(&op);
			
				// Run the selected Option
				switch (op)
				{
					// Teams Option
					case 1:
						TeamsManagement(&op, teams, &teamCounter);
						break;
						
					// Show all the reports
					case 2:
						ShowReport(reports, reportCounter);
						break;
				}
			}
			op = -1;
		}
		// Show the statistics
		else if (op == 3)
		{
			ShowStatistics(teams, teamCounter, reports, reportCounter, homes, homeCounter);
		}
	}
}


/*
	This procedure displays the Home Menu and returns via pointer an option selected in the menu
	@op = Option selected in the menu
*/
void HomeMenu(int *op)
{
	// Reset Option
	*op = -1;
	
	// Menu
	system("cls");
	puts("+---------------------------------------+");
	puts("|              Menu Inicial             |");
	puts("+---------------------------------------+");
	puts("|                                       |");
	puts("| 1- Equipas Multidisciplinares         |");
	puts("|                                       |");
	puts("| 2- Ministério da Administração Interna|");
	puts("|                                       |");
	puts("| 3- Consultar Estatísticas             |");
	puts("|                                       |");
	puts("| 0- Sair                               |");
	puts("|                                       |");
	puts("+---------------------------------------+");
	
	// Select an option
	printf("Selecione um número: ");
	scanf("%d", op);
}


/*
	This procedure displays the Multidisciplinary Teams Menu and returns via pointer an option selected in the menu
	@op = Option selected in the menu
*/
void MultiTeamMenu(int *op, int district)
{	
	// Variables
	char districtText[50];
	
	// Reset Option
	*op = -1;
	
	// Convert district ID to text 
	GetDistrict(district, districtText);
	
	// Menu
	system("cls");
	puts("+---------------------------------------+");
	printf("| Equipa %-31s|\n", districtText);
	puts("+---------------------------------------+");
	puts("|                                       |");
	puts("| 1- Editar Equipa                      |");
	puts("|                                       |");
	puts("| 2- Lares                              |");
	puts("|                                       |");
	puts("| 3- Inspeções                          |");
	puts("|                                       |");
	puts("| 4- Criar Relatório                    |");
	puts("|                                       |");
	puts("| 0- Voltar                             |");
	puts("|                                       |");
	puts("+---------------------------------------+");
	
	// Select an option
	printf("Selecione um número: ");
	scanf("%d", op);
}


/*
	This procedure displays the MAI Menu and returns via pointer an option selected in the menu
	@op = Option selected in the menu
*/
void MaiMenu(int *op)
{
	// Reset Option
	*op = -1;
	
	// Menu
	system("cls");
	puts("+---------------------------------------+");
	puts("|  Ministério da Administração Interna  |");
	puts("+---------------------------------------+");
	puts("|                                       |");
	puts("| 1- Gerir Equipas                      |");
	puts("|                                       |");
	puts("| 2- Consultar Relatórios               |");
	puts("|                                       |");
	puts("| 0- Voltar                             |");
	puts("|                                       |");
	puts("+---------------------------------------+");
	
	// Select an option
	printf("Selecione um número: ");
	scanf("%d", op);
}



