
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


#include "contacts.h"
#include "contactHelpers.h"



// getName:
void getName(struct Name* name)
{
	int userChoice;

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]s", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	userChoice = yes();
	if (userChoice == 1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]s", name->middleInitial);
		clearKeyboard();
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]s", name->lastName);
	clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address)
{
	int userChoice;

	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();

	while (address->streetNumber <= 0)
	{
		printf("Please enter the contact's street number: ");
		address->streetNumber = getInt();
	}

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]s", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	userChoice = yes();

	if (userChoice == 1)
	{
		printf("Please enter the contact's apartment number: ");
		(*address).apartmentNumber = getInt();

		while (address->apartmentNumber <= 0)
		{
			printf("Please enter the contact's apartment number: ");
			(*address).apartmentNumber = getInt();
		}
	}
	else
		address->apartmentNumber = -1;

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]s", address->city);
	clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
	int userChoice;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	userChoice = yes();

	if (userChoice == 1)
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	else
		strcpy(numbers->home, "");

	printf("Do you want to enter a business phone number? (y or n): ");
	userChoice = yes();

	if (userChoice == 1)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	else
		strcpy(numbers->business, "");
}

// getContact:
void getContact(struct Contact* contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
