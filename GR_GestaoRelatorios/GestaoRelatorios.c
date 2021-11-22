#include <stdio.h>
#include <stdlib.h>
#include "GestaoRelatorios.h"


/*
	Procedure to show a list of created reports
	@reports = reports list
	@n = Total amount of reports
*/
void ShowReportList(Report *reports, int n)
{
	// Variables
	int i;
	char districtText[30];
	
	// Show reports
	system("cls");
	puts("+--------------------------------------------------------------------+");
	puts("|                        Lista de Relatórios                         |");
	puts("+--------------------------------------------------------------------+");
	puts("|  ID  |    Data    |     Equipa     |              Lar              |");
	puts("+--------------------------------------------------------------------+");
	for(i = 0; i < n; i++)
	{
		// Convert district ID to text 
		GetDistrict(reports[i].inspection.team.district, districtText);
	
		printf("| %*d  | %-10s | %-14s | %-29s |\n"
		, -3, i, reports[i].inspection.date, districtText, reports[i].inspection.home.name);
	}
	
	puts("+--------------------------------------------------------------------+");
}


/*
	Procedure to show a specific report
	@reports = reports list
	@n = Total amount of reports
*/
void ShowReport(Report *reports, int n)
{
	// Variables
	int i, id;
	char districtText[30], question[50];
	
	// Show report list
	ShowReportList(reports, n);
	
	// Ask for report id
	id = SelectById(n);
	
	// Exit condition
	if (id < 0)
		return;
		
	// Convert district ID to text 
	GetDistrict(reports[id].inspection.team.district, districtText);
	
	// Show selected report
	system("cls");
	printf("+--------------------------------------------------------+\n");
	printf("|            Relatório %-4d                              |\n", id);
	printf("+--------------------------------------------------------+\n");
	printf("|                                                        |\n");
	printf("| Inspeção realizada pela Equipa de %-21s|\n", districtText);
	printf("| ao Lar %-48s|\n", reports[id].inspection.home.name);
	printf("| no Dia %-48s|\n", reports[id].inspection.date);
	printf("|                                                        |\n");
	printf("| Membros presentes:                                     |\n");
	for (i = 0; i < reports[id].inspection.team.memberCount; i++)
	{
		printf("|   > Nome: %-45s|\n", reports[id].inspection.team.members[i].name);
	}
	printf("|                                                        |\n");
	printf("| Testes Efetuados -> %-6d                             |\n", reports[id].testQnt);
	printf("|                                                        |\n");
	printf("| Casos Positivos  -> %-6d                             |\n", reports[id].positiveCasesQnt);
	printf("|                                                        |\n");
	for (i = 0; i < reports[id].positiveCasesQnt; i++)
	{
		printf("| Caso Nº%-4d                                            |\n", i+1);
		printf("|   > Idade: %-3d                                         |\n", reports[id].posCases[i].age);
		printf("|   > SNS: %-12s                                  |\n", reports[id].posCases[i].sns);	
		printf("|                                                        |\n");
	}
	
	printf("| Condições:                                             |\n");
    printf("|                                                        |\n");
    for (i = 0; i < MAX_QUESTION; i++)
    {
    	GetHomeQuestion(i, question);
    	printf("| %d) ", i+1);
		printf("%-30s", question);
    	printf("[%02d/10]  |\n", reports[id].questionsHome[i]);	
	}
	
	printf("|                                                        |\n");
	printf("|    Casos Positivos: %8.1f%%                          |\n", reports[id].positivePercentage);
	printf("|    Avaliação do Lar: [%.2f/10]                         |\n", reports[id].homeEvaluation);
	printf("|    Avaliação do Funcionario: [%.2f/10]                 |\n", reports[id].employeeEvaluation);
	printf("|    Avaliação Final: [%.2f/10]                          |\n", reports[id].finalEvaluation);
	printf("|                                                        |\n");
	printf("+--------------------------------------------------------+\n");

	// Pause
	getch();
}


/*
	This procedure is responsible for creating a report.
	@reports = reports list
	@nR = Total amount of reports
	@inspections = inspections list
	@nI = Tota amount of inspections
*/
void CreateReport(Report *reports, int *nR, Inspection *inspections, int *nI, Team *team, Home *homes)
{
	// Variables
	int i, id, testQnt, positiveCases;
	char question[50];
	
	// Show list of inspections and select one
	ShowInspectionList(inspections, *nI, team->id);
	
	id = SelectById(*nI);
	
	system("cls");
	puts("+-------------------------------+");
	puts("|\tCriação do Relatório\t|");
	puts("+-------------------------------+");
	puts("");
	
	// Exit condition
	if (id < 0)
		return;
		
	// Insert the quatity of the positive cases
	printf("Insira a quantidade de testes positivos:");
	scanf("%d", &reports[*nR].positiveCasesQnt);
	puts("");
		
	// Insert the positive cases
	puts("====== Dados dos Infetados ======");
	for (i = 0; i < reports[*nR].positiveCasesQnt; i++)
	{
		printf("Numero SNS:");
		scanf("%s", reports[*nR].posCases[i].sns);
		printf("Idade:");
		scanf("%d", &reports[*nR].posCases[i].age);
		puts("");
	}
	
	// Home conditions questions
	puts("");
	puts("+--------------------------------------+");
	puts("|         Quiz Condições do Lar        |");
	puts("+--------------------------------------+");
	puts("Para toda as perguntas insira uma nota de 0 a 10.");
	// Request home questions for evaluation
	for (i = 0; i < MAX_QUESTION; i++)
	{
		GetHomeQuestion(i, question);
		printf("%s", question);
		scanf("%d", &reports[*nR].questionsHome[i]);
	}

	
	// Employees questions
	puts("");
	puts("+--------------------------------------+");
	puts("|           Quiz Funcionario           |");
	puts("+--------------------------------------+");
	puts("Perguntas a ser feitas a um funcionario do lar.");
	puts("Para toda as perguntas insira uma nota de 0 a 10.");
	// Request employee questions for evaluation
	for (i = 0; i < MAX_QUESTION; i++)
	{
		GetEmployeeQuestion(i, question);
		printf("%s", question);
		scanf("%d", &reports[*nR].questionsEmployee[i]);
	}
	
	// Assign the inspection data in the report
	reports[*nR].inspection = inspections[id];
	
	// Assign test quantity based on the home residents
	reports[*nR].testQnt = (inspections[id].home.patientQuantity + inspections[id].home.employeeQuantity);
	
	// Calculate the questions average
	reports[*nR].homeEvaluation = Average(reports[*nR].questionsHome, MAX_QUESTION);
	reports[*nR].employeeEvaluation = Average(reports[*nR].questionsEmployee, MAX_QUESTION);
	reports[*nR].finalEvaluation = (reports[*nR].homeEvaluation + reports[*nR].employeeEvaluation) / 2;
	
	// Calculate the percentage of the positive cases if there is at least one
	if(reports[*nR].positiveCasesQnt > 0 )
		reports[*nR].positivePercentage = Percentage(reports[*nR].positiveCasesQnt, reports[*nR].testQnt);
	
	// Reschedule the inspection if the evaluation is negative
	if(reports[*nR].homeEvaluation < 5 ) 
		RescheduleInspection(inspections, nI, id, *team);
	
	// Show on screen an warning
	Notification(reports[*nR]);
	getch();
	

	// Assign data
	inspections[id].ativo = 0;
	homes[inspections[id].home.id].evaluation = reports[*nR].finalEvaluation;
	for (i = 0; i < MAX_QUESTION; i++)
		homes[inspections[id].home.id].questionsHome[i] = reports[*nR].questionsHome[i];
	team->progress += 1;
	*nR += 1;
}


/*
	This procedure show a notification on screen
	to know if DGS or GNR ar alerted 
	@report = selected report
*/
void Notification(Report report)
{
	
	//to know if have positive cases
	if ((report.positiveCasesQnt > 0 && report.homeEvaluation >= 5))
		printf("\nA DGS foi notificada dos casos positivos."); 
	else if (report.positiveCasesQnt > 0)
	{
		printf("\nA DGS foi notificada dos casos positivos."); 
		printf("\nA GNR foi notificada dos casos positivos que vão realizar o isolamento em casa."); 
	}
	
}












