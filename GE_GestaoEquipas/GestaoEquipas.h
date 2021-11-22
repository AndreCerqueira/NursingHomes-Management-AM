#ifndef GESTAOEQUIPAS_H_
#define GESTAOEQUIPAS_H_
	
	// Structs
	typedef struct member 
	{
		int id;
		char name[50];
		char job[35];
		char address[20];
		char cc[10];
		char ccrp[4];
		char expirationDate[15];
		char telephoneNumber[10];
		int active;
	} Member;
	
	typedef struct vehicle
    {
    	Member driver;
        int capacity;
        char licensePlate[9];
    } Vehicle;
	
	typedef struct team 
	{
		int id;
		int district;
	    Member members[MAX_STRUCTS];
	    int memberCount;
	    Member leader;
	    int objective; 
	    int progress;
	    Vehicle vehicles[MAX_STRUCTS];
	    int vehicleCount;
	}Team;
		
	
	// Signatures
	void TeamsManagement(int *op, Team *teams, int *teamCounter);
	void TeamMenu(int *op);
	void EditTeam(int *op, Team *teams, int teamCounter, int user);
	void EditTeamMenu(int *op, Team *teams, int id);
	void DeleteMember(Team *team);
	void ShowTeamList(Team  *teams, int n);
	void ShowMembersList(Team team);
	void ShowInspectionMembersList(Team originalTeam, Team newTeam);
	Member AddMember(int id);
	void CreateTeam(Team *teams, int *n);
	void ShowVehiclesList(Team team);
	Vehicle AddVehicle();
	Member SelectDriver(Team team);
	void ShowAvailableDistricts(Team *teams, int *n);
	int ValidateTeam(Team team);

#endif

