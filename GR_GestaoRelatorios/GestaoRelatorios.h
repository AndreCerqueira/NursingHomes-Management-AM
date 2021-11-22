#ifndef GESTAORELATORIOS_H_
#define GESTAORELATORIOS_H_

	// Structs
	typedef struct positiveCase
	 {
	 	int age;
	 	char sns[9];
	 } PositiveCase;
	 
	typedef struct report
	{
		Inspection inspection;
		int testQnt;
		int positiveCasesQnt;
		PositiveCase posCases[MAX_STRUCTS];
		double positivePercentage;
		int questionsHome[MAX_QUESTION];
		int questionsEmployee[MAX_QUESTION];
		float homeEvaluation;
		float employeeEvaluation;
		float finalEvaluation;

	} Report;
	
	
	// Signatures
	void ShowReportList(Report *reports, int n);
	void ShowReport(Report *reports, int n);
	void CreateReport(Report *reports, int *nR, Inspection *inspections, int *nI, Team *team, Home *homes);
	void Notification(Report report);
	

#endif
