#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *		"Utilis" é uma biblioteca composta por varias funções 
 *		e procedimentos, usados várias vezes no decorrer do programa.
 */
 
// consts
#define MAX_STRUCTS 30
#define MAX_DISTRICTS 24
#define MAX_QUESTION 5


// Signatures
int SelectById(int n);
void GetText(char *text);
void GetDate(char *date);
void GetLicensePlate(char *licensePlate);
void GetDistrict(int id, char *district);
float Percentage(int nums, int totalNum);
float Average(int *nums, int n);
void GetHomeQuestion(int id, char *text);
void GetEmployeeQuestion(int id, char *text);


/*
	This function is responsible for returning an index from a given array, or a negative number if user wants to Cancel.
	@n = array quantity
*/
int SelectById(int n)
{
	// Variables
	int id;

	// Insert ID, and ensure that is valid
	printf("Para Voltar insira um ID negativo.\n");
	printf("Insira um ID: ");
	do 
		scanf("%d", &id);
	while (id >= n);
	
	return id;
}


/*
	This procedure is responsible for returning a string by pointer. This solves the problem of not being able to use text with spaces
	@text = text to be returned
*/
void GetText(char *text)
{
	// Clean Buffer
	fflush(stdin);
	
	// Read the text
	scanf("%[^\n]%*c", text); 
}


/*
    This procedure is responsible for returning a date by pointer. Having to insert the Day, Month and Year.
    @date = date text to be returned
*/
void GetDate(char *date)
{
    // Variables
    int day, month, year;

    // Insert Date
    printf("Insira a data:");
    printf("\n   > Dia: ");
    scanf("%d", &day);
    printf("\n   > Mês: ");
    scanf("%d", &month);
    printf("\n   > Ano: ");
    scanf("%d", &year);

    // Assign date
    sprintf(date, "%02d/%02d/%04d", day, month, year);
}


/*
    This procedure is responsible for returning a licensePlate by pointer. Having to insert the Number1, Number2 and Number3.
    @licensePlate = licensePlate text to be returned
*/
void GetLicensePlate(char *licensePlate)
{
    // Variables
    char num1[3], num2[3], num3[3];

    // Insert the numbers
    printf("Insira a Matricula: [Insira 2 valores por vez]");
    printf("\n   > Parte 1: ");
    scanf("%s", &num1);
    printf("\n   > Parte 2: ");
    scanf("%s", &num2);
    printf("\n   > Parte 3: ");
    scanf("%s", &num3);

    // Assign licensePlate
    sprintf(licensePlate, "%02s-%02s-%02s", num1, num2, num3);
}


/*
	This function is responsible for returning a district by pointer. 
	Having to insert the id, to know what district will return.
	@id = id of the district
	@district = district that is returned
*/
void GetDistrict(int id, char *district)
{
	switch (id)
	{
		case 1:
			strcpy(district, "Aveiro");
	    	break;
	    case 2:
			strcpy(district, "Beja");
			break;
		case 3:
			strcpy(district, "Braga");
			break;
		case 4:
			strcpy(district, "Bragança");
			break;
		case 5:
			strcpy(district, "Castelo Branco");
			break;
		case 6:
			strcpy(district, "Coimbra");
			break;
		case 7:
			strcpy(district, "Évora");
			break;
		case 8:
			strcpy(district, "Faro");
			break;
		case 9:
			strcpy(district, "Guarda");
			break;
		case 10:
			strcpy(district, "Leiria");
			break;
		case 11:
			strcpy(district, "Lisboa");
			break;
		case 12:
			strcpy(district, "Portalegre");
			break;
		case 13:
			strcpy(district, "Porto");
			break;
		case 14:
			strcpy(district, "Santarem");
			break;
		case 15:
			strcpy(district, "Setúbal");
			break;
		case 16:
			strcpy(district, "Viana do Castelo");
			break;
		case 17:
			strcpy(district, "Vila Real");
			break;
		case 18:
			strcpy(district, "Viseu");
			break;
		case 19:
			strcpy(district, "Angra do Heroísmo");
			break;
		case 20:
			strcpy(district, "Funchal");
			break;
		case 21:
			strcpy(district, "Horta");
			break;
		case 22:
			strcpy(district, "Lamego");
			break;
		case 23:
			strcpy(district, "Ponta Delgada");
			break;	
	}
}


/*
	Function to calculate the positive cases average returning the percentage
	@nums = number of elements counted 
	@totalNum = total number of elements
*/
float Percentage(int nums, int totalNum)
{
	// Variables
	float result;
	
	// Calculate percentage
	result = (nums * 100) / (float) totalNum;
	
	// Return result
	return result;
}


/*
	Function to calculate a average based on the result of questions returing the average
	@nums = list with integer numbers
	@totalNum = quantity of numbers
*/
float Average(int *nums, int n)
{
	// Variables
	int i, sum = 0;
	float result;
	
	for ( i = 0; i < n; i++)
	{
		sum += nums[i];
	}
	
	// Calculate the average
	result = sum / (float) n;
	
	// Return the average
	return result;
}


/*
	This procedure loads the home questions utilised on the report
	@id = question id
	@text = question in text
*/
void GetHomeQuestion(int id, char *text)
{
	
	// Load Questions
	switch (id)
	{
		case 0:
			strcpy(text, "Cump. de distanciamento social           : ");
			break;
		case 1:
			strcpy(text, "Cump. de regras de higienização          : ");
			break;
		case 2:
			strcpy(text, "Cump. das normas nas visitas             : ");
			break;
		case 3:
			strcpy(text, "Cump. das normas na admissão de utentes  : ");
			break;
		case 4:
			strcpy(text, "Procedimento na descoberta de novos casos: ");
			break;
	}
	
}


/*
	This procedure loads the employee questions utilised on the report
	@id = question id
	@text = question in text
*/
void GetEmployeeQuestion(int id, char *text)
{
	
	// Load Questions
	switch (id)
	{
		case 0:
			strcpy(text, "Higienização das mãos              : ");
			break;
		case 1:
			strcpy(text, "Evitar Exposição                   : ");
			break;
		case 2:
			strcpy(text, "Aderir medidas de controle         : ");
			break;
		case 3:
			strcpy(text, "Apoiar medidas de prevenção        : ");
			break;
		case 4:
			strcpy(text, "Procedimento na descoberta de casos: ");
			break;
	}
	
}






