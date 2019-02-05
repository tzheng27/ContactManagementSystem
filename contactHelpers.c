
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


#include <string.h>
#include <ctype.h>


#include "contactHelpers.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               



#define MAXCONTACTS 5
#define PHONELENGTH 11



struct Contact theWalkingDead[MAXCONTACTS] =
{ { { "Rick",{ '\0' }, "Grimes" },
{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
{ "4161112222", "4162223333", "4163334444" } },
	  {
		  { "Maggie", "R.", "Greene" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9051112222", "9052223333", "9053334444" } },
	  {
		  { "Morgan", "A.", "Jones" },
{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
{ "7051112222", "7052223333", "7053334444" } },
	  {
		  { "Sasha",{ '\0' }, "Williams" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9052223333", "9052223333", "9054445555" } },
};

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
	int validInt;
	char ifNewline = 'x';

	scanf("%d%c", &validInt, &ifNewline);

	while (ifNewline != '\n')
	{
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &validInt, &ifNewline);
	}

	return validInt;
}

// getIntInRange:
int getIntInRange(int lowerBound, int upperBound)
{
	int intInRange;

	intInRange = getInt();

	while (intInRange < lowerBound || intInRange > upperBound)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lowerBound, upperBound);
		intInRange = getInt();
	}
	return intInRange;
}

// yes:
int yes(void)
{
	char flag;
	char ifNewline = 'x';

	scanf(" %c%c", &flag, &ifNewline);

	while (ifNewline != '\n')
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &flag, &ifNewline);
	}

	while (toupper(flag) != 'Y' && toupper(flag) != 'N')
	{
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &flag, &ifNewline);
		while (ifNewline != '\n')
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			scanf(" %c%c", &flag, &ifNewline);
		}
	}

	if (toupper(flag) == 'Y')
		return 1;
	else
		return 0;
}

// menu:
int menu(void)
{
	int menuOption;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	menuOption = getIntInRange(0, 6);

	return menuOption;
}

// ContactManagerSystem:
void ContactManagerSystem(void)
{
	int option, userChoice = 0;

		do
		{
			option = menu();
			switch (option)
			{
			case 1:
				printf("\n");
				displayContacts(theWalkingDead, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 2:
				printf("\n");
				addContact(theWalkingDead, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 3:
				printf("\n");
				updateContact(theWalkingDead, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 4:
				printf("\n");
				deleteContact(theWalkingDead, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 5:
				printf("\n");
				searchContacts(theWalkingDead, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 6:
				printf("\n");
				sortContacts(theWalkingDead, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 0:
				printf("\n");
				printf("Exit the program? (Y)es/(N)o: ");
				userChoice = yes();
				printf("\n");
				if (userChoice == 1)
					printf("Contact Management System: terminated\n");
			}

		} while (userChoice == 0);
}


// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int i, stop = 0, nonDigit = 0;

	scanf("%s", telNum);
	clearKeyboard();

	while (strlen(telNum) != 10)
	{
		printf("Enter a 10-digit phone number: ");
		scanf("%s", telNum);
		clearKeyboard();
	}

	while (stop == 0)
	{
		while (strlen(telNum) != 10)
		{
			printf("Enter a 10-digit phone number: ");
			scanf("%s", telNum);
			clearKeyboard();
		}

		for (i = 0; i < PHONELENGTH - 1; i++)
		{
			if (isdigit(telNum[i]) == 0)
				nonDigit++;
		}

		if (nonDigit > 0)
		{
			printf("Enter a 10-digit phone number: ");
			scanf("%s", telNum);
			clearKeyboard();
			nonDigit = 0;
		}
		else
			stop = 1;

	}
}


// findContactIndex:
int findContactIndex(const struct Contact findCon[], int size, const char cellNum[])
{
	int i, stop = 0;
	for (i = 0; i < size && stop == 0; i++)
	{
		if (strcmp(findCon[i].numbers.cell, cellNum) == 0)
		{¡¢
			stop = 1;
		}
	}
	if (stop != 0)
		return i-1;
	else
		return -1;
}

// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int footer)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", footer);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact * displayCon)
{
	if (strlen(displayCon->name.middleInitial) > 0)
		printf(" %s %s %s\n", displayCon->name.firstName, displayCon->name.middleInitial, displayCon->name.lastName);
	else
		printf(" %s %s\n", displayCon->name.firstName, displayCon->name.lastName);

	printf("    C: %-10s   H: %-10s   B: %-10s\n", displayCon->numbers.cell, displayCon->numbers.home, displayCon->numbers.business);


	if (displayCon->address.apartmentNumber > 0)
		printf("       %d %s, Apt# %d, %s, %s\n", displayCon->address.streetNumber, displayCon->address.street, displayCon->address.apartmentNumber, displayCon->address.city, displayCon->address.postalCode);
	else
		printf("       %d %s, %s, %s\n", displayCon->address.streetNumber, displayCon->address.street, displayCon->address.city, displayCon->address.postalCode);

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact displayCon[], int display)
{
	int i, valid = 0;
	displayContactHeader();

	for (i = 0; i < display; i++)
	{
		if (strlen(displayCon[i].numbers.cell) > 0)
		{
			displayContact(&displayCon[i]);
			valid++;
		}
	}

	displayContactFooter(valid);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact searchCon[], int search)
{
	int whoisTarget;
	char searchTarget[PHONELENGTH];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(searchTarget);

	whoisTarget = findContactIndex(searchCon, search, searchTarget);

	if (whoisTarget != -1)
	{
		printf("\n");
		displayContact(&searchCon[whoisTarget]);
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n");
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact addCon[], int add)
{
	int i, stop = 0;

	for (i = 0; i < add && stop == 0; i++)
	{
		if (strlen(addCon[i].numbers.cell) == 0)
		{
			stop = 1;
		}
	}

	if (stop == 0)
		printf("*** ERROR: The contact list is full! ***\n");
	else
	{
		getContact(&addCon[i-1]);
		

		printf("--- New contact added! ---\n");
	}
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact updateCon[], int update)
{
	int whoisTarget, yesOrno, updateTimes = 0;
	char updateTarget[PHONELENGTH];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(updateTarget);

	whoisTarget = findContactIndex(updateCon, update, updateTarget);

	if (whoisTarget == -1)
		printf("*** Contact NOT FOUND ***\n");
	else
	{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&updateCon[whoisTarget]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		yesOrno = yes();
		if (yesOrno == 1)
		{
			getName(&updateCon[whoisTarget].name);
			updateTimes++;
		}

		printf("Do you want to update the address? (y or n): ");
		yesOrno = yes();
		if (yesOrno == 1)
		{
			getAddress(&updateCon[whoisTarget].address);
			updateTimes++;
		}


		printf("Do you want to update the numbers? (y or n): ");
		yesOrno = yes(); ==
		if (yesOrno == 1)
		{
			getNumbers(&updateCon[whoisTarget].numbers);
			updateTimes++;
		}

		if (updateTimes > 0)
			printf("--- Contact Updated! ---\n");
	}

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact delCon[], int delete)
{
	int whoisTarget, yesOrno;
	char deleteTarget[PHONELENGTH];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(deleteTarget);

	whoisTarget = findContactIndex(delCon, delete, deleteTarget);

	if (whoisTarget == -1)
		printf("*** Contact NOT FOUND ***\n");
	else
	{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&delCon[whoisTarget]);
		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");
		yesOrno = yes();
		if (yesOrno == 1)
		{
			strcpy(delCon[whoisTarget].numbers.cell, "");
			printf("--- Contact deleted! ---\n");
		}

	}
}



// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact sortCon[], int sort)
{
	int i, j;
	struct Contact temp = { { { '\0' } },{ 0,{ '\0' }, 0,{ '\0' },{ '\0' } },{ { '\0' } }
	};

	for (i = sort - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if ( strcmp (sortCon[j].numbers.cell, sortCon[j + 1].numbers.cell) > 0)
				{
					temp = sortCon[j];
					sortCon[j] = sortCon[j + 1];
					sortCon[j + 1] = temp;
				}
		}
	}

	printf("--- Contacts sorted! ---\n");
}
