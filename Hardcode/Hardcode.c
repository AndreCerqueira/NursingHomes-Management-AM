#include <stdio.h>
#include <stdlib.h>

// Signatures
void LoadHomeData(Home *homes, int *n);
void LoadTeamData(Team *teams, int *n);
void LoadInspectionData(Inspection *inspections, int *nI, Team *teams, Home *homes);
void LoadReportData(Report *reports, int *nR, Inspection *inspections, Team *teams, Home *homes);


/*
	Extra procedure for loading home data by Hardcode to simulate data and test the program
	@homes = homes list
	@n = homes quantity
*/
void LoadHomeData(Home *homes, int *n)
{
	// Variables
	int id = 0;
	
	//---------------------- Lares da Equipa do distrito 1 -------------------------------
	strcpy(homes[*n].name, "Centro Social de Belazaima");
	strcpy(homes[*n].address, "Águeda");
	homes[*n].district = 1;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 75;
	homes[*n].riskPatientQuantity = 24;
	homes[*n].employeeQuantity = 6;
	strcpy(homes[*n].employees[0].name, "Olívia Nunes");
	strcpy(homes[*n].employees[0].telephoneNumber, "912345623");
	strcpy(homes[*n].employees[1].name, "Eduardo Filgueiras");
	strcpy(homes[*n].employees[1].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[2].name, "Linda Nascimento");
	strcpy(homes[*n].employees[2].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[3].name, "António Araujo");
	strcpy(homes[*n].employees[3].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[4].name, "Martim Pereira");
	strcpy(homes[*n].employees[4].telephoneNumber, "966467324");
	strcpy(homes[*n].employees[5].name, "Vítor Martins");
	strcpy(homes[*n].employees[5].telephoneNumber, "933546573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Centro Social da Anadia");
	strcpy(homes[*n].address, "Anadia");
	homes[*n].district = 1;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 58;
	homes[*n].riskPatientQuantity = 5;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Mariana Cunha");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[1].name, "Carla Azevedo");
	strcpy(homes[*n].employees[1].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[2].name, "Ágatha Pereira");
	strcpy(homes[*n].employees[2].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[3].name, "Alex Cunha");
	strcpy(homes[*n].employees[3].telephoneNumber, "966467324");
	strcpy(homes[*n].employees[4].name, "Tiago Santos");
	strcpy(homes[*n].employees[4].telephoneNumber, "913546573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Jardim de São José");
	strcpy(homes[*n].address, "Arouca");
	homes[*n].district = 1;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 68;
	homes[*n].riskPatientQuantity = 13;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Eduarda Fernandes");
	strcpy(homes[*n].employees[0].telephoneNumber, "912345623");
	strcpy(homes[*n].employees[1].name, "Fábio Souza");
	strcpy(homes[*n].employees[1].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[2].name, "Nicolas Pinto");
	strcpy(homes[*n].employees[2].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[3].name, "Eduardo Castro");
	strcpy(homes[*n].employees[3].telephoneNumber, "962464657");
	strcpy(homes[*n].employees[4].name, "Diogo Ribeiro");
	strcpy(homes[*n].employees[4].telephoneNumber, "936467324");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 2 -------------------------------
	strcpy(homes[*n].name, "Associação Escola Aberta");
	strcpy(homes[*n].address, "Beja");
	homes[*n].district = 2;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 80;
	homes[*n].riskPatientQuantity = 47;
	homes[*n].employeeQuantity = 6;
	strcpy(homes[*n].employees[0].name, "Alex Cunha");
	strcpy(homes[*n].employees[0].telephoneNumber, "931243355");
	strcpy(homes[*n].employees[1].name, "Sofia Azevedo");
	strcpy(homes[*n].employees[1].telephoneNumber, "964568912");
	strcpy(homes[*n].employees[2].name, "Murilo Oliveira");
	strcpy(homes[*n].employees[2].telephoneNumber, "923498578");
	strcpy(homes[*n].employees[3].name, "Eduardo Ribeiro");
	strcpy(homes[*n].employees[3].telephoneNumber, "918345732");
	strcpy(homes[*n].employees[4].name, "Caio Barros");
	strcpy(homes[*n].employees[4].telephoneNumber, "934345789");
	strcpy(homes[*n].employees[5].name, "Raissa Correia");
	strcpy(homes[*n].employees[5].telephoneNumber, "910920348");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Fundação S. Barnabé");
	strcpy(homes[*n].address, "Almodôvar");
	homes[*n].district = 2;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 44;
	homes[*n].riskPatientQuantity = 15;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Aline Alves");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[1].name, "João Costa");
	strcpy(homes[*n].employees[1].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[2].name, "Danilo Souza");
	strcpy(homes[*n].employees[2].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[3].name, "Miguel Santos");
	strcpy(homes[*n].employees[3].telephoneNumber, "966467324");
	strcpy(homes[*n].employees[4].name, "Luis Silva");
	strcpy(homes[*n].employees[4].telephoneNumber, "913546573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Jacinto Faleiro");
	strcpy(homes[*n].address, "Castro Verde");
	homes[*n].district = 2;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 61;
	homes[*n].riskPatientQuantity = 20;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Isabela Lima");
	strcpy(homes[*n].employees[0].telephoneNumber, "912345623");
	strcpy(homes[*n].employees[1].name, "Leonardo Castro");
	strcpy(homes[*n].employees[1].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[2].name, "Sofia Melo");
	strcpy(homes[*n].employees[2].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[3].name, "Clara Pinto");
	strcpy(homes[*n].employees[3].telephoneNumber, "962464657");
	strcpy(homes[*n].employees[4].name, "Vitoria Dias");
	strcpy(homes[*n].employees[4].telephoneNumber, "936467324");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 3 -------------------------------
	strcpy(homes[*n].name, "Casa do Cruzeiro");
	strcpy(homes[*n].address, "Barcelos");
	homes[*n].district = 3;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 53;
	homes[*n].riskPatientQuantity = 24;
	homes[*n].employeeQuantity = 6;
	strcpy(homes[*n].employees[0].name, "Matheus Ferreira");
	strcpy(homes[*n].employees[0].telephoneNumber, "918794054");
	strcpy(homes[*n].employees[1].name, "Rodrigo Azevedo");
	strcpy(homes[*n].employees[1].telephoneNumber, "964568912");
	strcpy(homes[*n].employees[2].name, "Vinícius Gomes");
	strcpy(homes[*n].employees[2].telephoneNumber, "923498577");
	strcpy(homes[*n].employees[3].name, "Vinicius Santos");
	strcpy(homes[*n].employees[3].telephoneNumber, "918345328");
	strcpy(homes[*n].employees[4].name, "Beatrice Castro");
	strcpy(homes[*n].employees[4].telephoneNumber, "934345897");
	strcpy(homes[*n].employees[5].name, "Raissa Fernandes");
	strcpy(homes[*n].employees[5].telephoneNumber, "910920380");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Centro Social João Paulo II");
	strcpy(homes[*n].address, "Esposende");
	homes[*n].district = 3;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 39;
	homes[*n].riskPatientQuantity = 7;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Julia Santos");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[1].name, "Kauan Lima");
	strcpy(homes[*n].employees[1].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[2].name, "Nicolas Correia");
	strcpy(homes[*n].employees[2].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[3].name, "Lucas Lima");
	strcpy(homes[*n].employees[3].telephoneNumber, "966467324");
	strcpy(homes[*n].employees[4].name, "Kauã Correia");
	strcpy(homes[*n].employees[4].telephoneNumber, "913546573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Centro Infantil de Golães");
	strcpy(homes[*n].address, "Fafe");
	homes[*n].district = 3;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 65;
	homes[*n].riskPatientQuantity = 42;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Eduarda Fernandes");
	strcpy(homes[*n].employees[0].telephoneNumber, "912345623");
	strcpy(homes[*n].employees[1].name, "Tânia Cardoso");
	strcpy(homes[*n].employees[1].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[2].name, "Tomás Barros");
	strcpy(homes[*n].employees[2].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[3].name, "Felipe Souza");
	strcpy(homes[*n].employees[3].telephoneNumber, "962464657");
	strcpy(homes[*n].employees[4].name, "Nicolas Souza");
	strcpy(homes[*n].employees[4].telephoneNumber, "936467324");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 4 -------------------------------
	strcpy(homes[*n].name, "Centro de Dia de Deilão");
	strcpy(homes[*n].address, "Bragança");
	homes[*n].district = 4;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 58;
	homes[*n].riskPatientQuantity = 12;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Lara Carvalho");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576285");
	strcpy(homes[*n].employees[1].name, "Vitória Ferreira");
	strcpy(homes[*n].employees[1].telephoneNumber, "910247865");
	strcpy(homes[*n].employees[2].name, "Bruno Alves");
	strcpy(homes[*n].employees[2].telephoneNumber, "925874565");
	strcpy(homes[*n].employees[3].name, "Eduarda Martins");
	strcpy(homes[*n].employees[3].telephoneNumber, "965741369");
	strcpy(homes[*n].employees[4].name, "Victor Correia");
	strcpy(homes[*n].employees[4].telephoneNumber, "932014589");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Casa do Povo de Alferce");
	strcpy(homes[*n].address, "Monchique");
	homes[*n].district = 4;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 42;
	homes[*n].riskPatientQuantity = 4;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "José Rodrigues");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[1].name, "Marisa Silva");
	strcpy(homes[*n].employees[1].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[2].name, "Erick Gomes");
	strcpy(homes[*n].employees[2].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[3].name, "Bruna Barbosa");
	strcpy(homes[*n].employees[3].telephoneNumber, "966463324");
	strcpy(homes[*n].employees[4].name, "Isabela Barbosa");
	strcpy(homes[*n].employees[4].telephoneNumber, "913542573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Associação Tempus");
	strcpy(homes[*n].address, "Olhão");
	homes[*n].district = 4;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 84;
	homes[*n].riskPatientQuantity = 14;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Guilherme Ferreira");
	strcpy(homes[*n].employees[0].telephoneNumber, "935741258");
	strcpy(homes[*n].employees[1].name, "Vitor Goncalves");
	strcpy(homes[*n].employees[1].telephoneNumber, "914756325");
	strcpy(homes[*n].employees[2].name, "Beatriz Pereira");
	strcpy(homes[*n].employees[2].telephoneNumber, "925684426");
	strcpy(homes[*n].employees[3].name, "Amanda Melo");
	strcpy(homes[*n].employees[3].telephoneNumber, "910357950");
	strcpy(homes[*n].employees[4].name, "Bruno Barbosa");
	strcpy(homes[*n].employees[4].telephoneNumber, "965324101");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 5 -------------------------------
	strcpy(homes[*n].name, "Lar Major Rato");
	strcpy(homes[*n].address, "Castelo Branco");
	homes[*n].district = 5;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 75;
	homes[*n].riskPatientQuantity = 32;
	homes[*n].employeeQuantity = 6;
	strcpy(homes[*n].employees[0].name, "Matheus Cardoso");
	strcpy(homes[*n].employees[0].telephoneNumber, "965471235");
	strcpy(homes[*n].employees[1].name, "Martim Pinto");
	strcpy(homes[*n].employees[1].telephoneNumber, "912753951");
	strcpy(homes[*n].employees[2].name, "Marisa Silva");
	strcpy(homes[*n].employees[2].telephoneNumber, "932546285");
	strcpy(homes[*n].employees[3].name, "Matilde Cavalcanti");
	strcpy(homes[*n].employees[3].telephoneNumber, "967349875");
	strcpy(homes[*n].employees[4].name, "Lavinia Sousa");
	strcpy(homes[*n].employees[4].telephoneNumber, "937015384");
	strcpy(homes[*n].employees[5].name, "Fábio Ribeiro");
	strcpy(homes[*n].employees[5].telephoneNumber, "916520047");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Centro de Dia de Orjais");
	strcpy(homes[*n].address, "Covilhã");
	homes[*n].district = 5;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 42;
	homes[*n].riskPatientQuantity = 4;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Clara Carvalho");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[1].name, "Amanda Araujo");
	strcpy(homes[*n].employees[1].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[2].name, "Artur Cunha");
	strcpy(homes[*n].employees[2].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[3].name, "Nicolas Almeida");
	strcpy(homes[*n].employees[3].telephoneNumber, "966463324");
	strcpy(homes[*n].employees[4].name, "Fábio Almeida");
	strcpy(homes[*n].employees[4].telephoneNumber, "913542573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Centro Social da Torre");
	strcpy(homes[*n].address, "Fundão");
	homes[*n].district = 5;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 84;
	homes[*n].riskPatientQuantity = 14;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Nicole Lima");
	strcpy(homes[*n].employees[0].telephoneNumber, "936369639");
	strcpy(homes[*n].employees[1].name, "Miguel Ferreira");
	strcpy(homes[*n].employees[1].telephoneNumber, "920054782");
	strcpy(homes[*n].employees[2].name, "Camila Cardoso");
	strcpy(homes[*n].employees[2].telephoneNumber, "919258200");
	strcpy(homes[*n].employees[3].name, "Alice Alves");
	strcpy(homes[*n].employees[3].telephoneNumber, "910245369");
	strcpy(homes[*n].employees[4].name, "Luiz Ribeiro");
	strcpy(homes[*n].employees[4].telephoneNumber, "968745632");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 6 -------------------------------
	strcpy(homes[*n].name, "Assistência Folquense");
	strcpy(homes[*n].address, "Arganil");
	homes[*n].district = 6;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 42;
	homes[*n].riskPatientQuantity = 12;
	homes[*n].employeeQuantity = 6;
	strcpy(homes[*n].employees[0].name, "Pedro Barros");
	strcpy(homes[*n].employees[0].telephoneNumber, "935874258");
	strcpy(homes[*n].employees[1].name, "Alex Castro");
	strcpy(homes[*n].employees[1].telephoneNumber, "936951753");
	strcpy(homes[*n].employees[2].name, "João Barbosa");
	strcpy(homes[*n].employees[2].telephoneNumber, "925025900");
	strcpy(homes[*n].employees[3].name, "Samuel Sousa");
	strcpy(homes[*n].employees[3].telephoneNumber, "967349875");
	strcpy(homes[*n].employees[4].name, "Lara Santos");
	strcpy(homes[*n].employees[4].telephoneNumber, "937015384");
	strcpy(homes[*n].employees[5].name, "Ana Oliveira");
	strcpy(homes[*n].employees[5].telephoneNumber, "916520047");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Fundação Ferreira Freire");
	strcpy(homes[*n].address, "Cantanhede");
	homes[*n].district = 6;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 42;
	homes[*n].riskPatientQuantity = 4;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Clara Carvalho");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[1].name, "Amanda Araujo");
	strcpy(homes[*n].employees[1].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[2].name, "Artur Cunha");
	strcpy(homes[*n].employees[2].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[3].name, "Araújo Almeida");
	strcpy(homes[*n].employees[3].telephoneNumber, "966463324");
	strcpy(homes[*n].employees[4].name, "Inês Almeida");
	strcpy(homes[*n].employees[4].telephoneNumber, "913542573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Associação Novo Olhar");
	strcpy(homes[*n].address, "Figueira da Foz");
	homes[*n].district = 6;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 75;
	homes[*n].riskPatientQuantity = 23;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Ágatha Lima");
	strcpy(homes[*n].employees[0].telephoneNumber, "936369639");
	strcpy(homes[*n].employees[1].name, "Miguel Martins");
	strcpy(homes[*n].employees[1].telephoneNumber, "920054782");
	strcpy(homes[*n].employees[2].name, "Fernanda Cardoso");
	strcpy(homes[*n].employees[2].telephoneNumber, "919258200");
	strcpy(homes[*n].employees[3].name, "Gonçalo Alves");
	strcpy(homes[*n].employees[3].telephoneNumber, "910245369");
	strcpy(homes[*n].employees[4].name, "Henrique Ribeiro");
	strcpy(homes[*n].employees[4].telephoneNumber, "968745632");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 7 -------------------------------
	strcpy(homes[*n].name, "Betânia");
	strcpy(homes[*n].address, "Vendas Novas");
	homes[*n].district = 7;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 57;
	homes[*n].riskPatientQuantity = 24;
	homes[*n].employeeQuantity = 6;
	strcpy(homes[*n].employees[0].name, "Emanuel Costa");
	strcpy(homes[*n].employees[0].telephoneNumber, "935874258");
	strcpy(homes[*n].employees[1].name, "Beatriz Santos");
	strcpy(homes[*n].employees[1].telephoneNumber, "936951753");
	strcpy(homes[*n].employees[2].name, "Paulo Sousa");
	strcpy(homes[*n].employees[2].telephoneNumber, "925025900");
	strcpy(homes[*n].employees[3].name, "Francisco Pereira");
	strcpy(homes[*n].employees[3].telephoneNumber, "967349875");
	strcpy(homes[*n].employees[4].name, "Ângela Vedeira");
	strcpy(homes[*n].employees[4].telephoneNumber, "937015384");
	strcpy(homes[*n].employees[5].name, "Paula Oliveira");
	strcpy(homes[*n].employees[5].telephoneNumber, "916520047");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Fundação Romão de Sousa");
	strcpy(homes[*n].address, "Estremoz");
	homes[*n].district = 7;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 89;
	homes[*n].riskPatientQuantity = 18;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Júlio Azevedo");
	strcpy(homes[*n].employees[0].telephoneNumber, "912585454");
	strcpy(homes[*n].employees[1].name, "José Tavares");
	strcpy(homes[*n].employees[1].telephoneNumber, "925687458");
	strcpy(homes[*n].employees[2].name, "António Silva");
	strcpy(homes[*n].employees[2].telephoneNumber, "930005845");
	strcpy(homes[*n].employees[3].name, "Maria Gomes");
	strcpy(homes[*n].employees[3].telephoneNumber, "931236458");
	strcpy(homes[*n].employees[4].name, "Eva Viana");
	strcpy(homes[*n].employees[4].telephoneNumber, "920101475");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Fundação do Patrocínio");
	strcpy(homes[*n].address, "Évora");
	homes[*n].district = 7;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 98;
	homes[*n].riskPatientQuantity = 42;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Rafaela Torrado");
	strcpy(homes[*n].employees[0].telephoneNumber, "936456391");
	strcpy(homes[*n].employees[1].name, "Eliana Martins");
	strcpy(homes[*n].employees[1].telephoneNumber, "920365823");
	strcpy(homes[*n].employees[2].name, "Claúdia Cardoso");
	strcpy(homes[*n].employees[2].telephoneNumber, "912588200");
	strcpy(homes[*n].employees[3].name, "Henry Mortágua");
	strcpy(homes[*n].employees[3].telephoneNumber, "912413693");
	strcpy(homes[*n].employees[4].name, "Lucía Fiães");
	strcpy(homes[*n].employees[4].telephoneNumber, "969510632");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 8 -------------------------------
	strcpy(homes[*n].name, "Casa da Primeira Infância");
	strcpy(homes[*n].address, "Loulé");
	homes[*n].district = 8;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 47;
	homes[*n].riskPatientQuantity = 30;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Lara Carvalho");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576285");
	strcpy(homes[*n].employees[1].name, "Vitória Ferreira");
	strcpy(homes[*n].employees[1].telephoneNumber, "910247865");
	strcpy(homes[*n].employees[2].name, "Bruno Alves");
	strcpy(homes[*n].employees[2].telephoneNumber, "925874565");
	strcpy(homes[*n].employees[3].name, "Eduarda Martins");
	strcpy(homes[*n].employees[3].telephoneNumber, "965741369");
	strcpy(homes[*n].employees[4].name, "Victor Correia");
	strcpy(homes[*n].employees[4].telephoneNumber, "932014589");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Casa do Povo de Alferce");
	strcpy(homes[*n].address, "Monchique");
	homes[*n].district = 8;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 42;
	homes[*n].riskPatientQuantity = 4;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "José Rodrigues");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[1].name, "Marisa Silva");
	strcpy(homes[*n].employees[1].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[2].name, "Erick Gomes");
	strcpy(homes[*n].employees[2].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[3].name, "Bruna Barbosa");
	strcpy(homes[*n].employees[3].telephoneNumber, "966463324");
	strcpy(homes[*n].employees[4].name, "Isabela Barbosa");
	strcpy(homes[*n].employees[4].telephoneNumber, "913542573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Associação Tempus");
	strcpy(homes[*n].address, "Olhão");
	homes[*n].district = 8;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 84;
	homes[*n].riskPatientQuantity = 14;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Guilherme Ferreira");
	strcpy(homes[*n].employees[0].telephoneNumber, "935741258");
	strcpy(homes[*n].employees[1].name, "Vitor Goncalves");
	strcpy(homes[*n].employees[1].telephoneNumber, "914756325");
	strcpy(homes[*n].employees[2].name, "Beatriz Pereira");
	strcpy(homes[*n].employees[2].telephoneNumber, "925684426");
	strcpy(homes[*n].employees[3].name, "Amanda Melo");
	strcpy(homes[*n].employees[3].telephoneNumber, "910357950");
	strcpy(homes[*n].employees[4].name, "Bruno Barbosa");
	strcpy(homes[*n].employees[4].telephoneNumber, "965324101");
	homes[*n].id = *n;
	*n += 1;
	
	//---------------------- Lares da Equipa do distrito 9 -------------------------------
	strcpy(homes[*n].name, "Casa da Primeira Infância");
	strcpy(homes[*n].address, "Loulé");
	homes[*n].district = 9;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 74;
	homes[*n].riskPatientQuantity = 54;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Fatima Sardo");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576285");
	strcpy(homes[*n].employees[1].name, "Rogério Olaio");
	strcpy(homes[*n].employees[1].telephoneNumber, "910247865");
	strcpy(homes[*n].employees[2].name, "Manuela Cedro");
	strcpy(homes[*n].employees[2].telephoneNumber, "925874565");
	strcpy(homes[*n].employees[3].name, "Samir Castro");
	strcpy(homes[*n].employees[3].telephoneNumber, "965741369");
	strcpy(homes[*n].employees[4].name, "Benjamin Correia");
	strcpy(homes[*n].employees[4].telephoneNumber, "932014589");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Fundação Dias Carvalho");
	strcpy(homes[*n].address, "Portel");
	homes[*n].district = 9;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 72;
	homes[*n].riskPatientQuantity = 47;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Luis Dias");
	strcpy(homes[*n].employees[0].telephoneNumber, "914258630");
	strcpy(homes[*n].employees[1].name, "Gabriel Pereira");
	strcpy(homes[*n].employees[1].telephoneNumber, "925836900");
	strcpy(homes[*n].employees[2].name, "Renan Dias");
	strcpy(homes[*n].employees[2].telephoneNumber, "936541201");
	strcpy(homes[*n].employees[3].name, "Victor Souza");
	strcpy(homes[*n].employees[3].telephoneNumber, "920548074");
	strcpy(homes[*n].employees[4].name, "André Dias");
	strcpy(homes[*n].employees[4].telephoneNumber, "920555874");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Lar da Betânia");
	strcpy(homes[*n].address, "Vendas Novas");
	homes[*n].district = 9;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 76;
	homes[*n].riskPatientQuantity = 20;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Pedro Rocha");
	strcpy(homes[*n].employees[0].telephoneNumber, "910321654");
	strcpy(homes[*n].employees[1].name, "Alex Lima");
	strcpy(homes[*n].employees[1].telephoneNumber, "928654987");
	strcpy(homes[*n].employees[2].name, "Paulo Goncalves");
	strcpy(homes[*n].employees[2].telephoneNumber, "936852471");
	strcpy(homes[*n].employees[3].name, "Amanda Azevedo");
	strcpy(homes[*n].employees[3].telephoneNumber, "920508060");
	strcpy(homes[*n].employees[4].name, "Sofia Ferreira");
	strcpy(homes[*n].employees[4].telephoneNumber, "931014051");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 10 -------------------------------
	strcpy(homes[*n].name, "Associação Crescer e Crer");
	strcpy(homes[*n].address, "Marinha Grande");
	homes[*n].district = 10;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 86;
	homes[*n].riskPatientQuantity = 42;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Marcos Goncalves");
	strcpy(homes[*n].employees[0].telephoneNumber, "965800241");
	strcpy(homes[*n].employees[1].name, "Guilherme Martins");
	strcpy(homes[*n].employees[1].telephoneNumber, "930025441");
	strcpy(homes[*n].employees[2].name, "Tânia Goncalves");
	strcpy(homes[*n].employees[2].telephoneNumber, "920014478");
	strcpy(homes[*n].employees[3].name, "Raquel Azevedo");
	strcpy(homes[*n].employees[3].telephoneNumber, "933966922");
	strcpy(homes[*n].employees[4].name, "Maria Santos");
	strcpy(homes[*n].employees[4].telephoneNumber, "911922955");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Centro Social da Bufarda");
	strcpy(homes[*n].address, "Peniche");
	homes[*n].district = 10;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 53;
	homes[*n].riskPatientQuantity = 16;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Luis Dias");
	strcpy(homes[*n].employees[0].telephoneNumber, "914258630");
	strcpy(homes[*n].employees[1].name, "Bruno Ribeiro");
	strcpy(homes[*n].employees[1].telephoneNumber, "925836900");
	strcpy(homes[*n].employees[2].name, "Hugo Dias");
	strcpy(homes[*n].employees[2].telephoneNumber, "936541201");
	strcpy(homes[*n].employees[3].name, "Matias Souza");
	strcpy(homes[*n].employees[3].telephoneNumber, "920548074");
	strcpy(homes[*n].employees[4].name, "Joana Dias");
	strcpy(homes[*n].employees[4].telephoneNumber, "920555874");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Centro Social Júlio Antunes");
	strcpy(homes[*n].address, "Pombal");
	homes[*n].district = 10;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 96;
	homes[*n].riskPatientQuantity = 64;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Lara Rocha");
	strcpy(homes[*n].employees[0].telephoneNumber, "910321654");
	strcpy(homes[*n].employees[1].name, "Clara Lima");
	strcpy(homes[*n].employees[1].telephoneNumber, "928654987");
	strcpy(homes[*n].employees[2].name, "Ana Goncalves");
	strcpy(homes[*n].employees[2].telephoneNumber, "936852471");
	strcpy(homes[*n].employees[3].name, "Joana Azevedo");
	strcpy(homes[*n].employees[3].telephoneNumber, "920508060");
	strcpy(homes[*n].employees[4].name, "Vania Ferreira");
	strcpy(homes[*n].employees[4].telephoneNumber, "931014051");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 11 -------------------------------
	strcpy(homes[*n].name, "Fundação Mariápolis");
	strcpy(homes[*n].address, "Alenquer");
	homes[*n].district = 11;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 85;
	homes[*n].riskPatientQuantity = 52;
	homes[*n].employeeQuantity = 6;
	strcpy(homes[*n].employees[0].name, "Carlos Nunes");
	strcpy(homes[*n].employees[0].telephoneNumber, "912345623");
	strcpy(homes[*n].employees[1].name, "Felipe Filgueiras");
	strcpy(homes[*n].employees[1].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[2].name, "Felipa Nascimento");
	strcpy(homes[*n].employees[2].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[3].name, "Adelina Araujo");
	strcpy(homes[*n].employees[3].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[4].name, "Alcina Pereira");
	strcpy(homes[*n].employees[4].telephoneNumber, "966467324");
	strcpy(homes[*n].employees[5].name, "Isidoro Martins");
	strcpy(homes[*n].employees[5].telephoneNumber, "933546573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Casa de Repouso Britânica");
	strcpy(homes[*n].address, "Cascais");
	homes[*n].district = 11;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 76;
	homes[*n].riskPatientQuantity = 29;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Mariza Cunha");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[1].name, "Miguel Azevedo");
	strcpy(homes[*n].employees[1].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[2].name, "Afonso Pereira");
	strcpy(homes[*n].employees[2].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[3].name, "Barbara Cunha");
	strcpy(homes[*n].employees[3].telephoneNumber, "966467324");
	strcpy(homes[*n].employees[4].name, "Jorge Santos");
	strcpy(homes[*n].employees[4].telephoneNumber, "913546573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Associação Juvenil Renascer");
	strcpy(homes[*n].address, "Lisboa");
	homes[*n].district = 11;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 76;
	homes[*n].riskPatientQuantity = 24;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Luiz Almeida");
	strcpy(homes[*n].employees[0].telephoneNumber, "912345623");
	strcpy(homes[*n].employees[1].name, "Cláudia Souza");
	strcpy(homes[*n].employees[1].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[2].name, "Rita Pinto");
	strcpy(homes[*n].employees[2].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[3].name, "Judite Castro");
	strcpy(homes[*n].employees[3].telephoneNumber, "962464657");
	strcpy(homes[*n].employees[4].name, "Joaquim Ribeiro");
	strcpy(homes[*n].employees[4].telephoneNumber, "936467324");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 12 -------------------------------
	strcpy(homes[*n].name, "Centro Social de Mosteiros");
	strcpy(homes[*n].address, "Arronches");
	homes[*n].district = 12;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 72;
	homes[*n].riskPatientQuantity = 22;
	homes[*n].employeeQuantity = 6;
	strcpy(homes[*n].employees[0].name, "Alexandre Cunha");
	strcpy(homes[*n].employees[0].telephoneNumber, "9312433552");
	strcpy(homes[*n].employees[1].name, "Sara Azevedo");
	strcpy(homes[*n].employees[1].telephoneNumber, "964568912");
	strcpy(homes[*n].employees[2].name, "Inês Oliveira");
	strcpy(homes[*n].employees[2].telephoneNumber, "923498578");
	strcpy(homes[*n].employees[3].name, "João Ribeiro");
	strcpy(homes[*n].employees[3].telephoneNumber, "918345732");
	strcpy(homes[*n].employees[4].name, "Rui Barros");
	strcpy(homes[*n].employees[4].telephoneNumber, "934345789");
	strcpy(homes[*n].employees[5].name, "Rafaela Correia");
	strcpy(homes[*n].employees[5].telephoneNumber, "910920348");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Fundação Abreu Callado");
	strcpy(homes[*n].address, "Avis");
	homes[*n].district = 12;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 75;
	homes[*n].riskPatientQuantity = 23;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Pedro Alves");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[1].name, "Luciana Costa");
	strcpy(homes[*n].employees[1].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[2].name, "Lucy Souza");
	strcpy(homes[*n].employees[2].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[3].name, "José Santos");
	strcpy(homes[*n].employees[3].telephoneNumber, "966467324");
	strcpy(homes[*n].employees[4].name, "Annie Silva");
	strcpy(homes[*n].employees[4].telephoneNumber, "913546573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Centro Social de Margem");
	strcpy(homes[*n].address, "Gavião");
	homes[*n].district = 12;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 84;
	homes[*n].riskPatientQuantity = 34;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Maria Lima");
	strcpy(homes[*n].employees[0].telephoneNumber, "912345623");
	strcpy(homes[*n].employees[1].name, "Marta Castro");
	strcpy(homes[*n].employees[1].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[2].name, "Paulo Melo");
	strcpy(homes[*n].employees[2].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[3].name, "João Pinto");
	strcpy(homes[*n].employees[3].telephoneNumber, "962464657");
	strcpy(homes[*n].employees[4].name, "Nuno Dias");
	strcpy(homes[*n].employees[4].telephoneNumber, "936467324");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 13 -------------------------------
	strcpy(homes[*n].name, "Infantário Creche O Miúdo");
	strcpy(homes[*n].address, "Amarante");
	homes[*n].district = 13;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 45;
	homes[*n].riskPatientQuantity = 12;
	homes[*n].employeeQuantity = 6;
	strcpy(homes[*n].employees[0].name, "André Ferreira");
	strcpy(homes[*n].employees[0].telephoneNumber, "918794054");
	strcpy(homes[*n].employees[1].name, "Diogo Azevedo");
	strcpy(homes[*n].employees[1].telephoneNumber, "964568912");
	strcpy(homes[*n].employees[2].name, "Diana Gomes");
	strcpy(homes[*n].employees[2].telephoneNumber, "923498577");
	strcpy(homes[*n].employees[3].name, "Helena Santos");
	strcpy(homes[*n].employees[3].telephoneNumber, "918345328");
	strcpy(homes[*n].employees[4].name, "Beatriz Castro");
	strcpy(homes[*n].employees[4].telephoneNumber, "9343458977");
	strcpy(homes[*n].employees[5].name, "Gabriela Fernandes");
	strcpy(homes[*n].employees[5].telephoneNumber, "9109203808");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "O Amanhã da Criança");
	strcpy(homes[*n].address, "Maia");
	homes[*n].district = 13;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 98;
	homes[*n].riskPatientQuantity = 16;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Juliana Santos");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[1].name, "Rafael Lima");
	strcpy(homes[*n].employees[1].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[2].name, "Fernando Correia");
	strcpy(homes[*n].employees[2].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[3].name, "Lucas Lima");
	strcpy(homes[*n].employees[3].telephoneNumber, "966467324");
	strcpy(homes[*n].employees[4].name, "Francisca Correia");
	strcpy(homes[*n].employees[4].telephoneNumber, "913546573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Fundação Vítor Baía 99");
	strcpy(homes[*n].address, "Matosinhos");
	homes[*n].district = 13;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 65;
	homes[*n].riskPatientQuantity = 42;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Eduarda Fernandes");
	strcpy(homes[*n].employees[0].telephoneNumber, "912345623");
	strcpy(homes[*n].employees[1].name, "Tânia Cardoso");
	strcpy(homes[*n].employees[1].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[2].name, "Tomás Barros");
	strcpy(homes[*n].employees[2].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[3].name, "Felipe Souza");
	strcpy(homes[*n].employees[3].telephoneNumber, "962464657");
	strcpy(homes[*n].employees[4].name, "Nicolas Souza");
	strcpy(homes[*n].employees[4].telephoneNumber, "936467324");
	homes[*n].id = *n;
	*n += 1;
	
	
	//---------------------- Lares da Equipa do distrito 14 -------------------------------
	strcpy(homes[*n].name, "Centro Social do Pego");
	strcpy(homes[*n].address, "Abrantes");
	homes[*n].district = 14;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 74;
	homes[*n].riskPatientQuantity = 12;
	homes[*n].employeeQuantity = 6;
	strcpy(homes[*n].employees[0].name, "Carla Dias");
	strcpy(homes[*n].employees[0].telephoneNumber, "918794054");
	strcpy(homes[*n].employees[1].name, "Fernanda Melo");
	strcpy(homes[*n].employees[1].telephoneNumber, "964568912");
	strcpy(homes[*n].employees[2].name, "Bruno Ribeiro");
	strcpy(homes[*n].employees[2].telephoneNumber, "923498577");
	strcpy(homes[*n].employees[3].name, "Henrique Silva");
	strcpy(homes[*n].employees[3].telephoneNumber, "918345328");
	strcpy(homes[*n].employees[4].name, "Lara Oliveira");
	strcpy(homes[*n].employees[4].telephoneNumber, "934345897");
	strcpy(homes[*n].employees[5].name, "Gabriel Fernandes");
	strcpy(homes[*n].employees[5].telephoneNumber, "910920380");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Associação ENCOPROF");
	strcpy(homes[*n].address, "Entroncamento");
	homes[*n].district = 14;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 89;
	homes[*n].riskPatientQuantity = 15;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Juliano Borjes");
	strcpy(homes[*n].employees[0].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[1].name, "Rafaela Sampaio");
	strcpy(homes[*n].employees[1].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[2].name, "André Correia");
	strcpy(homes[*n].employees[2].telephoneNumber, "922464657");
	strcpy(homes[*n].employees[3].name, "Filipa Costa");
	strcpy(homes[*n].employees[3].telephoneNumber, "966467324");
	strcpy(homes[*n].employees[4].name, "Andreia Correia");
	strcpy(homes[*n].employees[4].telephoneNumber, "913546573");
	homes[*n].id = *n;
	*n += 1;
	
	strcpy(homes[*n].name, "Cáritas de Tomar");
	strcpy(homes[*n].address, "Tomar");
	homes[*n].district = 14;
	homes[*n].evaluation = -1;
	homes[*n].patientQuantity = 76;
	homes[*n].riskPatientQuantity = 54;
	homes[*n].employeeQuantity = 5;
	strcpy(homes[*n].employees[0].name, "Eduardo Santos");
	strcpy(homes[*n].employees[0].telephoneNumber, "912345623");
	strcpy(homes[*n].employees[1].name, "Tomás Pereira");
	strcpy(homes[*n].employees[1].telephoneNumber, "934576234");
	strcpy(homes[*n].employees[2].name, "Tomás Barros");
	strcpy(homes[*n].employees[2].telephoneNumber, "912346345");
	strcpy(homes[*n].employees[3].name, "Felipe Mota");
	strcpy(homes[*n].employees[3].telephoneNumber, "962464657");
	strcpy(homes[*n].employees[4].name, "Susaza Souza");
	strcpy(homes[*n].employees[4].telephoneNumber, "936467324");
	homes[*n].id = *n;
	*n += 1;
}


/*
	Extra procedure for loading team data by Hardcode to simulate data and test the program
	@teams = teams list
	@n = teams quantity
*/
void LoadTeamData(Team *teams, int *n)
{
	// Variables
	int id = 0;
	
	// ---------------------- Equipa 1 Distrito 1-------------------------------
	teams[*n].id = 0;
	
	teams[*n].district = 1;
	
	teams[*n].members[0].id = 0;
	strcpy(teams[*n].members[0].name, "André Cerqueira");
	strcpy(teams[*n].members[0].job, "Médico");
	strcpy(teams[*n].members[0].telephoneNumber, "910258741");
	strcpy(teams[*n].members[0].cc, "13070639");
	strcpy(teams[*n].members[0].ccrp, "Não");
	strcpy(teams[*n].members[0].expirationDate, "--/--/----");
	teams[*n].members[0].active = 1;
	
	teams[*n].members[1].id = 1;
	strcpy(teams[*n].members[1].name, "Diogo Costa");
	strcpy(teams[*n].members[1].job, "Enfermeiro");
	strcpy(teams[*n].members[1].telephoneNumber, "930741852");
	strcpy(teams[*n].members[1].cc, "17276517");
	strcpy(teams[*n].members[1].ccrp, "Sim");
	strcpy(teams[*n].members[1].expirationDate, "17/09/2023");
	teams[*n].members[1].active = 1;
	
	teams[*n].members[2].id = 2;
	strcpy(teams[*n].members[2].name, "Diogo Sampaio");
	strcpy(teams[*n].members[2].job, "Assistente Social");
	strcpy(teams[*n].members[2].telephoneNumber, "936852147");
	strcpy(teams[*n].members[2].cc, "17482743");
	strcpy(teams[*n].members[2].ccrp, "Não");
	strcpy(teams[*n].members[2].expirationDate, "--/--/----");
	teams[*n].members[2].active = 1;
	
	teams[*n].members[3].id = 3;
	strcpy(teams[*n].members[3].name, "João Braga");
	strcpy(teams[*n].members[3].job, "Tec. Saúde Ambiental");
	strcpy(teams[*n].members[3].telephoneNumber, "920586025");
	strcpy(teams[*n].members[3].cc, "17575755");
	strcpy(teams[*n].members[3].ccrp, "Sim");
	strcpy(teams[*n].members[3].expirationDate, "05/04/2027");
	teams[*n].members[3].active = 1;
	
	teams[*n].members[4].id = 4;
	strcpy(teams[*n].members[4].name, "Nuno Fernandes");
	strcpy(teams[*n].members[4].job, "Médico");
	strcpy(teams[*n].members[4].telephoneNumber, "935161982");
	strcpy(teams[*n].members[4].cc, "19476879");
	strcpy(teams[*n].members[4].ccrp, "Sim");
	strcpy(teams[*n].members[4].expirationDate, "16/05/2033");
	teams[*n].members[4].active = 1;
		
	teams[*n].members[5].id = 5;
	strcpy(teams[*n].members[5].name, "Vitor Silva");
	strcpy(teams[*n].members[5].job, "Enfermeiro");
	strcpy(teams[*n].members[5].telephoneNumber, "963852741");
	strcpy(teams[*n].members[5].cc, "14634977");
	strcpy(teams[*n].members[5].ccrp, "Não");
	strcpy(teams[*n].members[5].expirationDate, "--/--/----");
	teams[*n].members[5].active = 1;
	
	teams[*n].memberCount = 6;
	
	
	//------------------- Veiculos da equipa 1 -------------------------------
	teams[*n].vehicles[id].capacity = 9;
	strcpy(teams[*n].vehicles[id].licensePlate, "12-XX-56");
	teams[*n].vehicles[id].driver = teams[*n].members[1];
	id++;
	
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "22-45-GB");
	teams[*n].vehicles[id].driver = teams[*n].members[3];
	id++;
	
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "ZA-62-53");
	teams[*n].vehicles[id].driver = teams[*n].members[4];
	id++;
	
	teams[*n].vehicleCount = 3;
	
	teams[*n].leader = teams[*n].members[0]; 
	
	teams[*n].objective = 10;
	
	teams[*n].progress = 0;
	
	*n += 1;
	
	//---------------------- Equipa 2 Distrito 2-------------------------------
	teams[*n].id = 1;
	
	teams[*n].district = 2;
	
	teams[*n].members[0].id = 0;
	teams[*n].members[0].active = 1;
	strcpy(teams[*n].members[0].name, "Manuel Fernandes");
	strcpy(teams[*n].members[0].job, "Médico");
	strcpy(teams[*n].members[0].telephoneNumber, "987654321");
	strcpy(teams[*n].members[0].cc, "12345678");
	strcpy(teams[*n].members[0].ccrp, "Sim");
	strcpy(teams[*n].members[0].expirationDate, "01/01/2025");
	
	teams[*n].members[1].id = 1;
	teams[*n].members[1].active = 1;
	strcpy(teams[*n].members[1].name, "Diogo Pereira");
	strcpy(teams[*n].members[1].job, "Enfermeiro");
	strcpy(teams[*n].members[1].telephoneNumber, "987654321");
	strcpy(teams[*n].members[1].cc, "12345678");
	strcpy(teams[*n].members[1].ccrp, "Sim");
	strcpy(teams[*n].members[1].expirationDate, "01/01/2025");
	
	teams[*n].members[2].id = 2;
	teams[*n].members[2].active = 1;
	strcpy(teams[*n].members[2].name, "José Mota");
	strcpy(teams[*n].members[2].job, "Assistente Social");
	strcpy(teams[*n].members[2].telephoneNumber, "987654321");
	strcpy(teams[*n].members[2].cc, "12345678");
	strcpy(teams[*n].members[2].ccrp, "Sim");
	strcpy(teams[*n].members[2].expirationDate, "01/01/2025");
	
	teams[*n].members[3].id = 3;
	teams[*n].members[3].active = 1;
	strcpy(teams[*n].members[3].name, "Tiago Ribeiro");
	strcpy(teams[*n].members[3].job, "Tec. Saúde Ambiental");
	strcpy(teams[*n].members[3].telephoneNumber, "987654321");
	strcpy(teams[*n].members[3].cc, "12345678");
	strcpy(teams[*n].members[3].ccrp, "Sim");
	strcpy(teams[*n].members[3].expirationDate, "01/01/2025");
	
	teams[*n].members[4].id = 4;
	teams[*n].members[4].active = 1;
	strcpy(teams[*n].members[4].name, "Joaquim Matos");
	strcpy(teams[*n].members[4].job, "Enfermeiro");
	strcpy(teams[*n].members[4].telephoneNumber, "987654321");
	strcpy(teams[*n].members[4].cc, "12345678");
	strcpy(teams[*n].members[4].ccrp, "Sim");
	strcpy(teams[*n].members[4].expirationDate, "01/01/2025");

	teams[*n].memberCount = 5;
	
	id = 0;
	//------------------- Veiculos da equipa 2 -------------------------------
	teams[*n].vehicles[id].capacity = 9;
	strcpy(teams[*n].vehicles[id].licensePlate, "12-ER-56");
	teams[*n].vehicles[id].driver = teams[*n].members[0];
	id++;
	
	teams[*n].vehicles[id].capacity = 9;
	strcpy(teams[*n].vehicles[id].licensePlate, "22-45-YU");
	teams[*n].vehicles[id].driver = teams[*n].members[2];
	id++;
	
	teams[*n].vehicleCount = 2;
	
	teams[*n].leader = teams[*n].members[3]; 
	
	teams[*n].objective = 20;
	
	teams[*n].progress = 0;
	
	*n += 1;
	
	//---------------------- Equipa 3 Distrito 3-------------------------------
	teams[*n].id = 2;
	
	teams[*n].district = 3;
	
	teams[*n].members[0].id = 0;
	strcpy(teams[*n].members[0].name, "André Sousa");
	strcpy(teams[*n].members[0].job, "Enfermeiro");
	strcpy(teams[*n].members[0].telephoneNumber, "936521148");
	strcpy(teams[*n].members[0].cc, "13070639");
	strcpy(teams[*n].members[0].ccrp, "Não");
	strcpy(teams[*n].members[0].expirationDate, "--/--/----");
	teams[*n].members[0].active = 1;
	
	teams[*n].members[1].id = 1;
	strcpy(teams[*n].members[1].name, "Rafaela Pinto");
	strcpy(teams[*n].members[1].job, "Assistente Social");
	strcpy(teams[*n].members[1].telephoneNumber, "914753698");
	strcpy(teams[*n].members[1].cc, "17276517");
	strcpy(teams[*n].members[1].ccrp, "Sim");
	strcpy(teams[*n].members[1].expirationDate, "17/09/2023");
	teams[*n].members[1].active = 1;
	
	teams[*n].members[2].id = 2;
	strcpy(teams[*n].members[2].name, "Julia Cardoso");
	strcpy(teams[*n].members[2].job, "Tec. Saúde Ambiental");
	strcpy(teams[*n].members[2].telephoneNumber, "920456987");
	strcpy(teams[*n].members[2].cc, "17482743");
	strcpy(teams[*n].members[2].ccrp, "Não");
	strcpy(teams[*n].members[2].expirationDate, "--/--/----");
	teams[*n].members[2].active = 1;
	
	teams[*n].members[3].id = 3;
	strcpy(teams[*n].members[3].name, "Leila Dias");
	strcpy(teams[*n].members[3].job, "Médico");
	strcpy(teams[*n].members[3].telephoneNumber, "930753015");
	strcpy(teams[*n].members[3].cc, "17575755");
	strcpy(teams[*n].members[3].ccrp, "Sim");
	strcpy(teams[*n].members[3].expirationDate, "05/04/2027");
	teams[*n].members[3].active = 1;
	
	teams[*n].members[4].id = 4;
	strcpy(teams[*n].members[4].name, "Luana Gomes");
	strcpy(teams[*n].members[4].job, "Enfermeiro");
	strcpy(teams[*n].members[4].telephoneNumber, "920753684");
	strcpy(teams[*n].members[4].cc, "19476879");
	strcpy(teams[*n].members[4].ccrp, "Sim");
	strcpy(teams[*n].members[4].expirationDate, "16/05/2033");
	teams[*n].members[4].active = 1;
		
	teams[*n].members[5].id = 5;
	strcpy(teams[*n].members[5].name, "Vitor Alves");
	strcpy(teams[*n].members[5].job, "Assistente Social");
	strcpy(teams[*n].members[5].telephoneNumber, "968756324");
	strcpy(teams[*n].members[5].cc, "14634977");
	strcpy(teams[*n].members[5].ccrp, "Não");
	strcpy(teams[*n].members[5].expirationDate, "--/--/----");
	teams[*n].members[5].active = 1;
	
	teams[*n].memberCount = 6;
	
	
	//------------------- Veiculos da equipa 3 -------------------------------
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "00-ZZ-01");
	teams[*n].vehicles[id].driver = teams[*n].members[1];
	id++;
	
	teams[*n].vehicles[id].capacity = 9;
	strcpy(teams[*n].vehicles[id].licensePlate, "14-GH-68");
	teams[*n].vehicles[id].driver = teams[*n].members[3];
	id++;
	
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "52-KL-30");
	teams[*n].vehicles[id].driver = teams[*n].members[4];
	id++;
	
	teams[*n].vehicleCount = 3;
	
	teams[*n].leader = teams[*n].members[3]; 
	
	teams[*n].objective = 15;
	
	teams[*n].progress = 0;
	
	*n += 1;
	
	//---------------------- Equipa 4 Distrito 5 -------------------------------
	teams[*n].id = 3;
	
	teams[*n].district = 5;
	
	teams[*n].members[0].id = 0;
	strcpy(teams[*n].members[0].name, "Gabriel Goncalves");
	strcpy(teams[*n].members[0].job, "Assistente Social");
	strcpy(teams[*n].members[0].telephoneNumber, "936521148");
	strcpy(teams[*n].members[0].cc, "13070639");
	strcpy(teams[*n].members[0].ccrp, "Não");
	strcpy(teams[*n].members[0].expirationDate, "--/--/----");
	teams[*n].members[0].active = 1;
	
	teams[*n].members[1].id = 1;
	strcpy(teams[*n].members[1].name, "Rafaela Pinto");
	strcpy(teams[*n].members[1].job, "Tec. Saúde Ambiental");
	strcpy(teams[*n].members[1].telephoneNumber, "914753698");
	strcpy(teams[*n].members[1].cc, "17276517");
	strcpy(teams[*n].members[1].ccrp, "Sim");
	strcpy(teams[*n].members[1].expirationDate, "17/09/2023");
	teams[*n].members[1].active = 1;
	
	teams[*n].members[2].id = 2;
	strcpy(teams[*n].members[2].name, "Julia Cardoso");
	strcpy(teams[*n].members[2].job, "Médico");
	strcpy(teams[*n].members[2].telephoneNumber, "920456987");
	strcpy(teams[*n].members[2].cc, "17482743");
	strcpy(teams[*n].members[2].ccrp, "Não");
	strcpy(teams[*n].members[2].expirationDate, "--/--/----");
	teams[*n].members[2].active = 1;
	
	teams[*n].members[3].id = 3;
	strcpy(teams[*n].members[3].name, "Leila Dias");
	strcpy(teams[*n].members[3].job, "Enfermeiro");
	strcpy(teams[*n].members[3].telephoneNumber, "930753015");
	strcpy(teams[*n].members[3].cc, "17575755");
	strcpy(teams[*n].members[3].ccrp, "Sim");
	strcpy(teams[*n].members[3].expirationDate, "05/04/2027");
	teams[*n].members[3].active = 1;
	
	teams[*n].members[4].id = 4;
	strcpy(teams[*n].members[4].name, "Luana Gomes");
	strcpy(teams[*n].members[4].job, "Assistente Social");
	strcpy(teams[*n].members[4].telephoneNumber, "920753684");
	strcpy(teams[*n].members[4].cc, "19476879");
	strcpy(teams[*n].members[4].ccrp, "Sim");
	strcpy(teams[*n].members[4].expirationDate, "16/05/2033");
	teams[*n].members[4].active = 1;
		
	teams[*n].members[5].id = 5;
	strcpy(teams[*n].members[5].name, "Vitor Alves");
	strcpy(teams[*n].members[5].job, "Tec. Saúde Ambiental");
	strcpy(teams[*n].members[5].telephoneNumber, "968756324");
	strcpy(teams[*n].members[5].cc, "14634977");
	strcpy(teams[*n].members[5].ccrp, "Não");
	strcpy(teams[*n].members[5].expirationDate, "--/--/----");
	teams[*n].members[5].active = 1;
	
	teams[*n].memberCount = 6;
	
	
	//------------------- Veiculos da equipa 4 -------------------------------
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "00-ZZ-01");
	teams[*n].vehicles[id].driver = teams[*n].members[1];
	id++;
	
	teams[*n].vehicles[id].capacity = 9;
	strcpy(teams[*n].vehicles[id].licensePlate, "14-GH-68");
	teams[*n].vehicles[id].driver = teams[*n].members[3];
	id++;
	
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "52-KL-30");
	teams[*n].vehicles[id].driver = teams[*n].members[4];
	id++;
	
	teams[*n].vehicleCount = 3;
	
	teams[*n].leader = teams[*n].members[3]; 
	
	teams[*n].objective = 15;
	
	teams[*n].progress = 0;
	
	*n += 1;
	
	//---------------------- Equipa 5 distrito 7 -------------------------------
	teams[*n].id = 4;
	
	teams[*n].district = 7;
	
	teams[*n].members[0].id = 0;
	strcpy(teams[*n].members[0].name, "Domingos Pedroso");
	strcpy(teams[*n].members[0].job, "Médico");
	strcpy(teams[*n].members[0].telephoneNumber, "910258741");
	strcpy(teams[*n].members[0].cc, "13070639");
	strcpy(teams[*n].members[0].ccrp, "Não");
	strcpy(teams[*n].members[0].expirationDate, "--/--/----");
	teams[*n].members[0].active = 1;
	
	teams[*n].members[1].id = 1;
	strcpy(teams[*n].members[1].name, "Teresa Fontes");
	strcpy(teams[*n].members[1].job, "Enfermeiro");
	strcpy(teams[*n].members[1].telephoneNumber, "910258741");
	strcpy(teams[*n].members[1].cc, "17276517");
	strcpy(teams[*n].members[1].ccrp, "Sim");
	strcpy(teams[*n].members[1].expirationDate, "17/09/2025");
	teams[*n].members[1].active = 1;
	
	teams[*n].members[2].id = 2;
	strcpy(teams[*n].members[2].name, "Maria Cabral");
	strcpy(teams[*n].members[2].job, "Assistente Social");
	strcpy(teams[*n].members[2].telephoneNumber, "930258745");
	strcpy(teams[*n].members[2].cc, "17482743");
	strcpy(teams[*n].members[2].ccrp, "Não");
	strcpy(teams[*n].members[2].expirationDate, "--/--/----");
	teams[*n].members[2].active = 1;
	
	teams[*n].members[3].id = 3;
	strcpy(teams[*n].members[3].name, "Luisa Teixeira");
	strcpy(teams[*n].members[3].job, "Tec. Saúde Ambiental");
	strcpy(teams[*n].members[3].telephoneNumber, "920369852");
	strcpy(teams[*n].members[3].cc, "17575755");
	strcpy(teams[*n].members[3].ccrp, "Sim");
	strcpy(teams[*n].members[3].expirationDate, "05/07/2028");
	teams[*n].members[3].active = 1;
	
	teams[*n].members[4].id = 4;
	strcpy(teams[*n].members[4].name, "Ana Conde");
	strcpy(teams[*n].members[4].job, "Médico");
	strcpy(teams[*n].members[4].telephoneNumber, "910147147");
	strcpy(teams[*n].members[4].cc, "19476879");
	strcpy(teams[*n].members[4].ccrp, "Sim");
	strcpy(teams[*n].members[4].expirationDate, "23/08/2023");
	teams[*n].members[4].active = 1;
		
	teams[*n].members[5].id = 5;
	strcpy(teams[*n].members[5].name, "Leonor Ribeiro");
	strcpy(teams[*n].members[5].job, "Enfermeiro");
	strcpy(teams[*n].members[5].telephoneNumber, "920123654");
	strcpy(teams[*n].members[5].cc, "14634977");
	strcpy(teams[*n].members[5].ccrp, "Não");
	strcpy(teams[*n].members[5].expirationDate, "--/--/----");
	teams[*n].members[5].active = 1;
	
	teams[*n].memberCount = 6;
	
	
	//------------------- Veiculos da equipa 5 -------------------------------
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "AQ-34-56");
	teams[*n].vehicles[id].driver = teams[*n].members[1];
	id++;
	
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "PL-45-43");
	teams[*n].vehicles[id].driver = teams[*n].members[3];
	id++;
	
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "MN-62-53");
	teams[*n].vehicles[id].driver = teams[*n].members[4];
	id++;
	
	teams[*n].vehicleCount = 3;
	
	teams[*n].leader = teams[*n].members[0]; 
	
	teams[*n].objective = 15;
	
	teams[*n].progress = 0;
	
	*n += 1;
	
	
	//---------------------- Equipa 6 distrito 8 -------------------------------
	teams[*n].id = 5;
	
	teams[*n].district = 8;
	
	teams[*n].members[0].id = 0;
	strcpy(teams[*n].members[0].name, "Maria Pedroso");
	strcpy(teams[*n].members[0].job, "Médico");
	strcpy(teams[*n].members[0].telephoneNumber, "910258741");
	strcpy(teams[*n].members[0].cc, "13070639");
	strcpy(teams[*n].members[0].ccrp, "Não");
	strcpy(teams[*n].members[0].expirationDate, "--/--/----");
	teams[*n].members[0].active = 1;
	
	teams[*n].members[1].id = 1;
	strcpy(teams[*n].members[1].name, "João Fontes");
	strcpy(teams[*n].members[1].job, "Enfermeiro");
	strcpy(teams[*n].members[1].telephoneNumber, "910258741");
	strcpy(teams[*n].members[1].cc, "17276517");
	strcpy(teams[*n].members[1].ccrp, "Sim");
	strcpy(teams[*n].members[1].expirationDate, "17/09/2025");
	teams[*n].members[1].active = 1;
	
	teams[*n].members[2].id = 2;
	strcpy(teams[*n].members[2].name, "Ana Cabral");
	strcpy(teams[*n].members[2].job, "Assistente Social");
	strcpy(teams[*n].members[2].telephoneNumber, "930258745");
	strcpy(teams[*n].members[2].cc, "17482743");
	strcpy(teams[*n].members[2].ccrp, "Não");
	strcpy(teams[*n].members[2].expirationDate, "--/--/----");
	teams[*n].members[2].active = 1;
	
	teams[*n].members[3].id = 3;
	strcpy(teams[*n].members[3].name, "Tiago Teixeira");
	strcpy(teams[*n].members[3].job, "Tec. Saúde Ambiental");
	strcpy(teams[*n].members[3].telephoneNumber, "920369852");
	strcpy(teams[*n].members[3].cc, "17575755");
	strcpy(teams[*n].members[3].ccrp, "Sim");
	strcpy(teams[*n].members[3].expirationDate, "05/07/2028");
	teams[*n].members[3].active = 1;
	
	teams[*n].members[4].id = 4;
	strcpy(teams[*n].members[4].name, "Beatriz Conde");
	strcpy(teams[*n].members[4].job, "Médico");
	strcpy(teams[*n].members[4].telephoneNumber, "910147147");
	strcpy(teams[*n].members[4].cc, "19476879");
	strcpy(teams[*n].members[4].ccrp, "Sim");
	strcpy(teams[*n].members[4].expirationDate, "23/08/2023");
	teams[*n].members[4].active = 1;
		
	teams[*n].members[5].id = 5;
	strcpy(teams[*n].members[5].name, "Diogo Ribeiro");
	strcpy(teams[*n].members[5].job, "Enfermeiro");
	strcpy(teams[*n].members[5].telephoneNumber, "920123654");
	strcpy(teams[*n].members[5].cc, "14634977");
	strcpy(teams[*n].members[5].ccrp, "Não");
	strcpy(teams[*n].members[5].expirationDate, "--/--/----");
	teams[*n].members[5].active = 1;
	
	teams[*n].memberCount = 6;
	
	
	//------------------- Veiculos da equipa 6 -------------------------------
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "23-TR-09");
	teams[*n].vehicles[id].driver = teams[*n].members[1];
	id++;
	
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "ER-44-23");
	teams[*n].vehicles[id].driver = teams[*n].members[3];
	id++;
	
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "09-34-TT");
	teams[*n].vehicles[id].driver = teams[*n].members[4];
	id++;
	
	teams[*n].vehicleCount = 3;
	
	teams[*n].leader = teams[*n].members[0]; 
	
	teams[*n].objective = 15;
	
	teams[*n].progress = 0;
	
	*n += 1;
	
	
	//---------------------- Equipa 7 distrito 10 -------------------------------
	teams[*n].id = 6;
	
	teams[*n].district = 10;
	
	teams[*n].members[0].id = 0;
	strcpy(teams[*n].members[0].name, "Maria Pedroso");
	strcpy(teams[*n].members[0].job, "Médico");
	strcpy(teams[*n].members[0].telephoneNumber, "910258741");
	strcpy(teams[*n].members[0].cc, "13070639");
	strcpy(teams[*n].members[0].ccrp, "Não");
	strcpy(teams[*n].members[0].expirationDate, "--/--/----");
	teams[*n].members[0].active = 1;
	
	teams[*n].members[1].id = 1;
	strcpy(teams[*n].members[1].name, "João Fontes");
	strcpy(teams[*n].members[1].job, "Enfermeiro");
	strcpy(teams[*n].members[1].telephoneNumber, "910258741");
	strcpy(teams[*n].members[1].cc, "17276517");
	strcpy(teams[*n].members[1].ccrp, "Sim");
	strcpy(teams[*n].members[1].expirationDate, "17/09/2025");
	teams[*n].members[1].active = 1;
	
	teams[*n].members[2].id = 2;
	strcpy(teams[*n].members[2].name, "Ana Cabral");
	strcpy(teams[*n].members[2].job, "Assistente Social");
	strcpy(teams[*n].members[2].telephoneNumber, "930258745");
	strcpy(teams[*n].members[2].cc, "17482743");
	strcpy(teams[*n].members[2].ccrp, "Não");
	strcpy(teams[*n].members[2].expirationDate, "--/--/----");
	teams[*n].members[2].active = 1;
	
	teams[*n].members[3].id = 3;
	strcpy(teams[*n].members[3].name, "Tiago Teixeira");
	strcpy(teams[*n].members[3].job, "Tec. Saúde Ambiental");
	strcpy(teams[*n].members[3].telephoneNumber, "920369852");
	strcpy(teams[*n].members[3].cc, "17575755");
	strcpy(teams[*n].members[3].ccrp, "Sim");
	strcpy(teams[*n].members[3].expirationDate, "05/07/2028");
	teams[*n].members[3].active = 1;
	
	teams[*n].members[4].id = 4;
	strcpy(teams[*n].members[4].name, "Beatriz Conde");
	strcpy(teams[*n].members[4].job, "Médico");
	strcpy(teams[*n].members[4].telephoneNumber, "910147147");
	strcpy(teams[*n].members[4].cc, "19476879");
	strcpy(teams[*n].members[4].ccrp, "Sim");
	strcpy(teams[*n].members[4].expirationDate, "23/08/2023");
	teams[*n].members[4].active = 1;
		
	teams[*n].members[5].id = 5;
	strcpy(teams[*n].members[5].name, "Diogo Ribeiro");
	strcpy(teams[*n].members[5].job, "Enfermeiro");
	strcpy(teams[*n].members[5].telephoneNumber, "920123654");
	strcpy(teams[*n].members[5].cc, "14634977");
	strcpy(teams[*n].members[5].ccrp, "Não");
	strcpy(teams[*n].members[5].expirationDate, "--/--/----");
	teams[*n].members[5].active = 1;
	
	teams[*n].memberCount = 6;
	
	
	//------------------- Veiculos da equipa 7 -------------------------------
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "23-TR-09");
	teams[*n].vehicles[id].driver = teams[*n].members[1];
	id++;
	
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "ER-44-23");
	teams[*n].vehicles[id].driver = teams[*n].members[3];
	id++;
	
	teams[*n].vehicles[id].capacity = 5;
	strcpy(teams[*n].vehicles[id].licensePlate, "09-34-TT");
	teams[*n].vehicles[id].driver = teams[*n].members[4];
	id++;
	
	teams[*n].vehicleCount = 3;
	
	teams[*n].leader = teams[*n].members[0]; 
	
	teams[*n].objective = 15;
	
	teams[*n].progress = 0;
	
	*n += 1;
}


/*
	Extra procedure for loading inspection data by Hardcode to simulate data and test the program
	@inspections = inspections list
	@n = inspections quantity
*/
void LoadInspectionData(Inspection *inspections, int *nI, Team *teams, Home *homes)
{	
	//-------------------------------------- Equipa 1 --------------------------------------------
	
	//---------------------- Inspeção 1 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "12/03/2021");
	inspections[*nI].team = teams[0];
	inspections[*nI].home = homes[0];
	*nI += 1;
	
	//---------------------- Inspeção 2 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "01/02/2021");
	inspections[*nI].team = teams[0];
	inspections[*nI].home = homes[1];
	*nI += 1;
	
	//---------------------- Inspeção 3 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "24/02/2025");
	inspections[*nI].team = teams[0];
	inspections[*nI].home = homes[2];
	*nI += 1;
	
	//-------------------------------------- Equipa 2 --------------------------------------------
	
	//---------------------- Inspeção 1 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "22/05/2021");
	inspections[*nI].team = teams[1];
	inspections[*nI].home = homes[3];
	*nI += 1;
	
	//---------------------- Inspeção 2 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "11/06/2021");
	inspections[*nI].team = teams[1];
	inspections[*nI].home = homes[4];
	*nI += 1;
	
	//---------------------- Inspeção 3 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "24/02/2025");
	inspections[*nI].team = teams[1];
	inspections[*nI].home = homes[5];
	*nI += 1;
	
	//-------------------------------------- Equipa 3 --------------------------------------------
	
	//---------------------- Inspeção 1 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "24/02/2025");
	inspections[*nI].team = teams[2];
	inspections[*nI].home = homes[6];
	*nI += 1;
	
	//---------------------- Inspeção 2 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "11/02/2025");
	inspections[*nI].team = teams[2];
	inspections[*nI].home = homes[7];
	*nI += 1;
	
	//---------------------- Inspeção 3 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "11/02/2025");
	inspections[*nI].team = teams[2];
	inspections[*nI].home = homes[8];
	*nI += 1;
	
	//------------------------------------ Equipa 4 --------------------------------------
	
	//---------------------- Inspeção 1 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "24/02/2025");
	inspections[*nI].team = teams[3];
	inspections[*nI].home = homes[9];
	*nI += 1;
	
	//---------------------- Inspeção 2 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "11/02/2025");
	inspections[*nI].team = teams[3];
	inspections[*nI].home = homes[10];
	*nI += 1;
	
	//---------------------- Inspeção 3 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "11/02/2025");
	inspections[*nI].team = teams[3];
	inspections[*nI].home = homes[11];
	*nI += 1;
	
	//-------------------------------------- Equipa 5 --------------------------------------------
	
	//---------------------- Inspeção 1 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "24/02/2025");
	inspections[*nI].team = teams[4];
	inspections[*nI].home = homes[12];
	*nI += 1;
	
	//---------------------- Inspeção 2 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "11/02/2025");
	inspections[*nI].team = teams[4];
	inspections[*nI].home = homes[13];
	*nI += 1;
	
	//---------------------- Inspeção 3 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "11/02/2025");
	inspections[*nI].team = teams[4];
	inspections[*nI].home = homes[14];
	*nI += 1;
	
	//-------------------------------------- Equipa 6 --------------------------------------------
	
	//---------------------- Inspeção 1 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "24/02/2025");
	inspections[*nI].team = teams[5];
	inspections[*nI].home = homes[15];
	*nI += 1;
	
	//---------------------- Inspeção 2 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "11/02/2025");
	inspections[*nI].team = teams[5];
	inspections[*nI].home = homes[16];
	*nI += 1;
	
	//---------------------- Inspeção 3 ----------------------------
	inspections[*nI].ativo = 1;
	strcpy(inspections[*nI].date, "11/02/2025");
	inspections[*nI].team = teams[5];
	inspections[*nI].home = homes[17];
	*nI += 1;
	
}


/*
	Extra procedure for loading report data by Hardcode to simulate data and test the program
	@reports = reports list
	@n = reports quantity
	@inspections = inspections list
	@homes = homes list
*/
void LoadReportData(Report *reports, int *nR, Inspection *inspections, Team *teams, Home *homes)
{	
	// Variables
	int i;
	//---------------------- Relatorio 1 ----------------------------
	reports[*nR].inspection = inspections[0];
	reports[*nR].inspection.ativo = 0;
	reports[*nR].testQnt = reports[*nR].inspection.home.patientQuantity + reports[*nR].inspection.home.employeeQuantity;
	reports[*nR].positiveCasesQnt = 3;
	strcpy(reports[*nR].posCases[0].sns, "160996472");
	reports[*nR].posCases[0].age = 69;
	strcpy(reports[*nR].posCases[1].sns, "15396912");
	reports[*nR].posCases[1].age = 85;
	strcpy(reports[*nR].posCases[2].sns, "20112789");
	reports[*nR].posCases[2].age = 81;
	reports[*nR].positivePercentage = 3.7f;
	reports[*nR].questionsHome[0] = 7;
	reports[*nR].questionsHome[1] = 8;
	reports[*nR].questionsHome[2] = 6;
	reports[*nR].questionsHome[3] = 5;
	reports[*nR].questionsHome[4] = 7;
	reports[*nR].homeEvaluation = 6.6f;
	reports[*nR].questionsEmployee[0] = 8;
	reports[*nR].questionsEmployee[1] = 7;
	reports[*nR].questionsEmployee[2] = 6;
	reports[*nR].questionsEmployee[3] = 6;
	reports[*nR].questionsEmployee[4] = 6;
	reports[*nR].employeeEvaluation = 6.6f;
	reports[*nR].finalEvaluation = 6.6f;
	homes[reports[*nR].inspection.home.id].evaluation = reports[*nR].finalEvaluation;
	for (i = 0; i < MAX_QUESTION; i++)
		homes[reports[*nR].inspection.home.id].questionsHome[i] = reports[*nR].questionsHome[i];
	teams[reports[*nR].inspection.team.id].progress++;
	*nR += 1;
	
	//---------------------- Relatorio 2 ----------------------------
	reports[*nR].inspection = inspections[1];
	reports[*nR].inspection.ativo = 0;
	reports[*nR].testQnt = inspections[1].home.patientQuantity + inspections[1].home.employeeQuantity;
	reports[*nR].positiveCasesQnt = 3;
	strcpy(reports[*nR].posCases[0].sns, "283956782");
	reports[*nR].posCases[0].age = 56;
	strcpy(reports[*nR].posCases[1].sns, "173950322");
	reports[*nR].posCases[1].age = 87;
	strcpy(reports[*nR].posCases[2].sns, "143256003");
	reports[*nR].posCases[2].age = 63;
	reports[*nR].positivePercentage = 6.1f;
	reports[*nR].questionsHome[0] = 9;
	reports[*nR].questionsHome[1] = 8;
	reports[*nR].questionsHome[2] = 8;
	reports[*nR].questionsHome[3] = 5;
	reports[*nR].questionsHome[4] = 6;
	reports[*nR].homeEvaluation = 7.2f;
	reports[*nR].questionsEmployee[0] = 7;
	reports[*nR].questionsEmployee[1] = 5;
	reports[*nR].questionsEmployee[2] = 9;
	reports[*nR].questionsEmployee[3] = 8;
	reports[*nR].questionsEmployee[4] = 7;
	reports[*nR].employeeEvaluation = 7.2f;
	reports[*nR].finalEvaluation = 7.2f;
	homes[reports[*nR].inspection.home.id].evaluation = reports[*nR].finalEvaluation;
	for (i = 0; i < MAX_QUESTION; i++)
		homes[reports[*nR].inspection.home.id].questionsHome[i] = reports[*nR].questionsHome[i];
	teams[reports[*nR].inspection.team.id].progress++;
	*nR += 1;
	
	//---------------------- Relatorio 3 ----------------------------
	reports[*nR].inspection = inspections[2];
	reports[*nR].inspection.ativo = 0;
	reports[*nR].testQnt = inspections[2].home.patientQuantity + inspections[2].home.employeeQuantity;
	reports[*nR].positiveCasesQnt = 5;
	strcpy(reports[*nR].posCases[0].sns, "176345123");
	reports[*nR].posCases[0].age = 61;
	strcpy(reports[*nR].posCases[1].sns, "187493212");
	reports[*nR].posCases[1].age = 84;
	strcpy(reports[*nR].posCases[2].sns, "278394732");
	reports[*nR].posCases[2].age = 61;
	strcpy(reports[*nR].posCases[3].sns, "200456386");
	reports[*nR].posCases[3].age = 59;
	strcpy(reports[*nR].posCases[4].sns, "190756309");
	reports[*nR].posCases[4].age = 57;
	reports[*nR].positivePercentage = 6.8f;
	reports[*nR].questionsHome[0] = 6;
	reports[*nR].questionsHome[1] = 7;
	reports[*nR].questionsHome[2] = 8;
	reports[*nR].questionsHome[3] = 8;
	reports[*nR].questionsHome[4] = 9;
	reports[*nR].homeEvaluation = 7.6f;
	reports[*nR].questionsEmployee[0] = 7;
	reports[*nR].questionsEmployee[1] = 7;
	reports[*nR].questionsEmployee[2] = 5;
	reports[*nR].questionsEmployee[3] = 6;
	reports[*nR].questionsEmployee[4] = 7;
	reports[*nR].employeeEvaluation = 6.4f;
	reports[*nR].finalEvaluation = 7;
	homes[reports[*nR].inspection.home.id].evaluation = reports[*nR].finalEvaluation;
	for (i = 0; i < MAX_QUESTION; i++)
		homes[reports[*nR].inspection.home.id].questionsHome[i] = reports[*nR].questionsHome[i];
	teams[reports[*nR].inspection.team.id].progress++;
	*nR += 1;
	
	//---------------------- Relatorio 4 ----------------------------
	reports[*nR].inspection = inspections[4];
	reports[*nR].inspection.ativo = 0;
	reports[*nR].testQnt = inspections[4].home.patientQuantity + inspections[4].home.employeeQuantity;
	reports[*nR].positiveCasesQnt = 5;
	strcpy(reports[*nR].posCases[0].sns, "176345123");
	reports[*nR].posCases[0].age = 71;
	strcpy(reports[*nR].posCases[1].sns, "187493212");
	reports[*nR].posCases[1].age = 84;
	strcpy(reports[*nR].posCases[2].sns, "278394732");
	reports[*nR].posCases[2].age = 81;
	strcpy(reports[*nR].posCases[3].sns, "200456386");
	reports[*nR].posCases[3].age = 69;
	strcpy(reports[*nR].posCases[4].sns, "190756309");
	reports[*nR].posCases[4].age = 37;
	reports[*nR].positivePercentage = Percentage(reports[*nR].positiveCasesQnt, reports[*nR].testQnt);
	reports[*nR].questionsHome[0] = 6;
	reports[*nR].questionsHome[1] = 3;
	reports[*nR].questionsHome[2] = 5;
	reports[*nR].questionsHome[3] = 5;
	reports[*nR].questionsHome[4] = 6;
	reports[*nR].homeEvaluation = Average(reports[*nR].questionsHome, MAX_QUESTION);
	reports[*nR].questionsEmployee[0] = 2;
	reports[*nR].questionsEmployee[1] = 3;
	reports[*nR].questionsEmployee[2] = 5;
	reports[*nR].questionsEmployee[3] = 2;
	reports[*nR].questionsEmployee[4] = 4;
	reports[*nR].employeeEvaluation = Average(reports[*nR].questionsEmployee, MAX_QUESTION);
	reports[*nR].finalEvaluation = (reports[*nR].homeEvaluation + reports[*nR].employeeEvaluation) / 2;
	homes[reports[*nR].inspection.home.id].evaluation = reports[*nR].finalEvaluation;
	for (i = 0; i < MAX_QUESTION; i++)
		homes[reports[*nR].inspection.home.id].questionsHome[i] = reports[*nR].questionsHome[i];
	teams[reports[*nR].inspection.team.id].progress++;
	*nR += 1;
	
	//---------------------- Relatorio 5 ----------------------------
	reports[*nR].inspection = inspections[8];
	reports[*nR].inspection.ativo = 0;
	reports[*nR].testQnt = inspections[8].home.patientQuantity + inspections[8].home.employeeQuantity;
	reports[*nR].positiveCasesQnt = 5;
	strcpy(reports[*nR].posCases[0].sns, "176345123");
	reports[*nR].posCases[0].age = 71;
	strcpy(reports[*nR].posCases[1].sns, "187493212");
	reports[*nR].posCases[1].age = 74;
	strcpy(reports[*nR].posCases[2].sns, "278394732");
	reports[*nR].posCases[2].age = 81;
	strcpy(reports[*nR].posCases[3].sns, "200456386");
	reports[*nR].posCases[3].age = 93;
	strcpy(reports[*nR].posCases[4].sns, "190756309");
	reports[*nR].posCases[4].age = 37;
	reports[*nR].positivePercentage = Percentage(reports[*nR].positiveCasesQnt, reports[*nR].testQnt);
	reports[*nR].questionsHome[0] = 6;
	reports[*nR].questionsHome[1] = 1;
	reports[*nR].questionsHome[2] = 5;
	reports[*nR].questionsHome[3] = 3;
	reports[*nR].questionsHome[4] = 4;
	reports[*nR].homeEvaluation = Average(reports[*nR].questionsHome, MAX_QUESTION);
	reports[*nR].questionsEmployee[0] = 7;
	reports[*nR].questionsEmployee[1] = 4;
	reports[*nR].questionsEmployee[2] = 4;
	reports[*nR].questionsEmployee[3] = 3;
	reports[*nR].questionsEmployee[4] = 5;
	reports[*nR].employeeEvaluation = Average(reports[*nR].questionsEmployee, MAX_QUESTION);
	reports[*nR].finalEvaluation = (reports[*nR].homeEvaluation + reports[*nR].employeeEvaluation) / 2;
	homes[reports[*nR].inspection.home.id].evaluation = reports[*nR].finalEvaluation;
	for (i = 0; i < MAX_QUESTION; i++)
		homes[reports[*nR].inspection.home.id].questionsHome[i] = reports[*nR].questionsHome[i];
	teams[reports[*nR].inspection.team.id].progress++;
	*nR += 1;
	
}











