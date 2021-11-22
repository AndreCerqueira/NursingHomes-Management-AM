#ifndef ESTATISTICAS_H_
#define ESTATISTICAS_H_


	// Signatures
	void ShowStatistics(Team *teams, int nT, Report *reports, int nR, Home *homes, int nH);
	void CalculateTeamStatistics(Team team, Report *reports, int nR, Home *homes, int nH);
	void CalculateAllStatistics(Report *reports, int nR);
	int AgeRange(Team team, Report *reports, int n);
	int AllAgeRange(Report *reports, int n);
	float AverageStaffPerHome(Home *homes, int n);
	float PercentageHomesNotRated(Home *homes, int n);

#endif
