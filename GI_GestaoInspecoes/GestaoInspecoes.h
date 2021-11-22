#ifndef GESTAOINSPECOES_H_
#define GESTAOINSPECOES_H_
	
	
	// Structs
	typedef struct inspection
	{
		Team team;
		Home home;
		char date[20];
		char ativo;
	} Inspection;
	
	
	// Signatures
	void InspectionsManagement(int *op, Inspection *inspections, int *nI, Home *homes, int nH, Team team);
	void InspectionMenu(int *op);
	void ShowInspectionList(Inspection *inspections, int n, int id);
	void CreateInspection(Inspection *inspections, int *nI, Home *homes, int nH, Team team);
	void RescheduleInspection(Inspection *inspections, int *n, int id, Team team);
	Team SelectTeamMembers(Team originalTeam);

#endif

