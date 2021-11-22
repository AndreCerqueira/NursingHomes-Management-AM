#ifndef GESTAOLARES_H_
#define GESTAOLARES_H_
	
	
	// Structs
	typedef struct employee
	{
		char name[50];
		char telephoneNumber[10];
	} Employee;
	
	typedef struct home
	{
		int id;
		char name[100];
		int patientQuantity;
		Employee employees[50];
		int employeeQuantity;
		int riskPatientQuantity;
		int district;
		char address[30];
		int evaluation;
		int questionsHome[MAX_QUESTION];
	} Home;
	
	
	// Signatures
	void NursingHomesManagement(int *op, int district, Home *homes, int *homeCounter);
	void NursingHomeMenu(int *op);
	void ShowHomeList(Home *homes, int n, int district);
	void ShowHome(Home *homes, int n, int district);
	Employee AddEmployee();
	void CreateHome(int district, Home *homes, int *n);
	void SortHomesRating(Home *homes, int n);
	void SortHomesPatientQuantity(Home *homes, int n);

#endif

