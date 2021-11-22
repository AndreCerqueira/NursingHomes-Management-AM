#include <stdio.h>
#include <stdlib.h>
#include "Estatisticas.h"


/*
	This procedure displays all statistics
	@teams = list of teams
	@nT = teams quantity
	@reports = list of reports
	@nR = report quantity
	@homes = list of homes
	@nH = homes quantity
*/
void ShowStatistics(Team *teams, int nT, Report *reports, int nR, Home *homes, int nH)
{
	// Variables
	int i, op;
	char district[50];
	
	// Initial Verifications
	if (nR == 0)
	{
		printf("Ainda não existe nenhum relatório no sistema!");
		return;
	}
	
	// show all statistics
	system("cls");
	printf("+-------------------------------------------+\n");
	printf("|            Estatísticas Gerais            |\n");
	printf("+-------------------------------------------+\n");
	printf("|                                           |\n");
	printf("| Distritos sem avaliação: %6.2f%%          |\n", PercentageHomesNotRated(homes, nH));
	printf("|                                           |\n");
	printf("| Média de staff por lar: %-18.0f|\n", AverageStaffPerHome(homes, nH));
	printf("|                                           |\n");

	// Calculate and Show all statistics
	CalculateAllStatistics(reports, nR);
	
	// Choose to leave or to see the teams informations
	printf("+-------------------------------------------+\n");
	puts("Número [Positivo] para consultar tudo.");
	puts("Número [Negativo] para voltar.");
	printf("Insira um número: ");
	scanf("%d", &op);
	puts("");
	
	// Exit condition
	if (op < 0)
		return;
	
	// Team only statistics
	for (i = 0; i < nT; i++)
	{
		// Convert district ID to text 
		GetDistrict(teams[i].district, district);
	
		// District Header
		printf("+-------------------------------------------+\n");
    	printf("| ---> %-37s|\n", district);
    	printf("+-------------------------------------------+\n");
    	
    	// Calculate and Show the team Statistics
    	CalculateTeamStatistics(teams[i], reports, nR, homes, nH);
	}
	
	printf("+-------------------------------------------+\n");
	getch();
}


/*
	This procedure calculate all statistics
	@team = selected team
	@reports = list of reports
	@nR = report quantity
	@homes = list of homes
	@nH = homes quantity
*/
void CalculateTeamStatistics(Team team, Report *reports, int nR, Home *homes, int nH)
{
	// Variables
	int i, j, testsPerformed  = 0, afectedAge = 0;
	int homeCounter = 0, positiveCounter = 0;
	float evaluationSum = 0;
	
	// Cycle of all reports made by a specific team 
	for (i = 0; i < nR; i++)
	{
		if (team.id == reports[i].inspection.team.id)
		{
			testsPerformed += reports[i].testQnt;
			evaluationSum += reports[i].homeEvaluation;
			homeCounter++;
			
			for (j = 0; j < reports[i].positiveCasesQnt; j++)
				positiveCounter++;
		}
	}
	
	// Verify if have positive cases to calculate the ages
	afectedAge = (positiveCounter == 0) ? -1 : AgeRange(team, reports, nR);
	
	// Show the data
    printf("|                                           |\n");
    printf("| Testes Efetuados: %-24d|\n", testsPerformed);
    printf("|                                           |\n");
    printf("| Casos Positivos: %-25d|\n", positiveCounter);
    printf("|                                           |\n");
    printf("| Lares Testados: %-26d|\n", homeCounter);
    printf("|                                           |\n");
    if (afectedAge == -1)
    	printf("| Faixa Etária mais afetada: Na             |\n");
    else
    	printf("| Faixa Etária mais afetada: [%-2d - %2d]      |\n", afectedAge - 10, afectedAge);
    printf("|                                           |\n");
    printf("| Avaliação Média: [%.2f / 10]              |\n", (homeCounter == 0) ? 0 : evaluationSum / homeCounter);
	printf("|                                           |\n");		
	
}


/*
	This procedure calculate all statistics
	@reports = list of reports
	@n = report quantity
*/
void CalculateAllStatistics(Report *reports, int n)
{
	// Variables
	int i, j, k, testsPerformed = 0, afectedAge = 0;
	int positiveCounter = 0;
	float evaluationSum = 0;
	
	// Cycle of all reports made by all teams 
	for (j = 0; j < n; j++)
	{
		testsPerformed += reports[j].testQnt;
		evaluationSum += reports[j].homeEvaluation;
		
		for (k = 0; k < reports[j].positiveCasesQnt; k++)
			positiveCounter ++;
	}
	
	// Verify if have positive cases to calculate the ages
	afectedAge = (positiveCounter == 0) ? -1 : AllAgeRange(reports, n);
	
	// Show the data
    printf("|                                           |\n");
    printf("| Testes Efetuados: %-24d|\n", testsPerformed);
    printf("|                                           |\n");
    printf("| Casos Positivos: %-25d|\n", positiveCounter);
    printf("|                                           |\n");
    printf("| Lares Testados: %-26d|\n", n);
    printf("|                                           |\n");
    if (afectedAge == -1) 
    	printf("| Faxa Etária mais afetada: Na              |\n");
    else
    	printf("| Faxa Etária mais afetada: [%-2d - %2d]       |\n", afectedAge - 10, afectedAge);
    printf("|                                           |\n");
    printf("| Avaliação Média: [%.2f / 10]              |\n", (n == 0) ? 0 : evaluationSum / n);
	printf("|                                           |\n");		
	
}


/*
	This procedure calculate the most affected age range, assuming that the interval of the age range is (afectedAge - 10 to afectedAge)
	@team = selected team
	@reports = list of reports
	@n = report quantity
*/
int AgeRange(Team team, Report *reports, int n)
{
	// Variables
	int ageRanges[10];
	int i, j, age, bigger = 0, afectedAge = 0;
	
	// Clear array 
	for (i = 0; i < 10; i++)
		ageRanges[i] = 0;
	
	// check quantity of people in each age group 
	for (age = 0; age < 100; age += 10)
	{
	
		// Report cycle 
		for (i = 0; i < n; i++)
		{
			
			// Check if the report is from the selected team 
			if (reports[i].inspection.team.id == team.id)
			{
				// Positive case cycle for each report 
				for (j = 0; j < reports[i].positiveCasesQnt; j++)
				{
			    	if (reports[i].posCases[j].age > age && reports[i].posCases[j].age <= age + 10)  
			        	ageRanges[age / 10]++; 
			        else if (reports[i].posCases[j].age > 100)
						ageRanges[9] ++;
				}
			}
			
		}
	
	}
	
	// Check who has the most infected people in the age group 
	for (i = 0; i < 10; i += 1)
	{
	    if (ageRanges[i] > bigger)
	    {
	        bigger = ageRanges[i];
	        afectedAge = (i+1) * 10;
	    }
	}
	
	return afectedAge;
}


/*
	This procedure calculate the most affected age range, assuming that the interval of the age range is (afectedAge - 10 to afectedAge)
	@reports = list of reports
	@n = report quantity
*/
int AllAgeRange(Report *reports, int n)
{
	// Variables
	int ageRanges[10];
	int i, j, age, bigger = 0, afectedAge = 0;
	
	// Clear array 
	for (i = 0; i < 10; i++)
		ageRanges[i] = 0;
	
	// Check quantity of people in each age group 
	for (age = 0; age < 100; age += 10)
	{
	
		// Report cycle 
		for (i = 0; i < n; i++)
		{
			
			// Positive case cycle for each report 
			for (j = 0; j < reports[i].positiveCasesQnt; j++)
			{
		    	if (reports[i].posCases[j].age > age && reports[i].posCases[j].age <= age + 10)  
		        	ageRanges[age / 10] ++; 
		        else if (reports[i].posCases[j].age > 100)
					ageRanges[9] ++;
			}
			
		}
	
	}
	
	// Check who has the most infected people in the age group 
	for (i = 0; i < 10; i += 1)
	{
	    if (ageRanges[i] > bigger)
	    {
	        bigger = ageRanges[i];
	        afectedAge = (i+1) * 10;
	    }
	}
	
	return afectedAge;
}


/*
	This procedure calculates and returns the average of staff per home
	@homes = list of homes
	@n = homes quantity
*/
float AverageStaffPerHome(Home *homes, int n)
{
	// Variables
	int i, sum = 0;
	
	// Initial verifications
	if (n == 0)
		return 0;
	
	// Cycle of homes 
	for (i = 0; i < n; i++)
		sum += homes[i].employeeQuantity;
		
	return sum / (float)n;
}


/*
	This procedure calculates and returns the percentage of homes in the program that are not rated
	@homes = list of homes
	@n = homes quantity
*/
float PercentageHomesNotRated(Home *homes, int n)
{
	// Variables
	int i, homeRatedCounter = 0;
	
	// Cycle of homes and increment the homeCounter
	for (i = 0; i < n; i++)
	{
		if (homes[i].evaluation > 0)
			homeRatedCounter++;
	}
	
	// Do not let it be possible to divide by 0 and return the percentage
	return (n == 0) ? 100 : (100 - (homeRatedCounter * 100) / (float)n);
}
















