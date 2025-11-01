// Filename: Passenger_Manager.c
// Author: Ugochukwu Odinjor
// Date created: June 23rd 2025
//In this program I have created a prototype Manager for passengers and airports to handle registration and handling// 
//of information and passengers that come into said airport.//

#include <stdio.h>
#include <string.h>

#define NAME_LEN 50

void main(void) {

	char first_name[NAME_LEN] = "";//Initializing Buffers//
	char last_name[NAME_LEN] = "";
	char airline_name[NAME_LEN] = "";
	char flight_number[NAME_LEN] = "";
	char seat_row_number[NAME_LEN] = "";
	char seat_letter[NAME_LEN] = "";
	
	memset(first_name, 0, NAME_LEN);
	memset(last_name, 0, NAME_LEN);
	memset(airline_name, 0, NAME_LEN);
	memset(flight_number, 0, NAME_LEN);
	memset(seat_row_number, 0, NAME_LEN);
	memset(seat_letter, 0, NAME_LEN);
//********Passenger Prompts******************//
//------------------------------------------------------//
	printf("Enter your first name: ");//These prompts ask and take the passenger's information
	scanf("%49s", first_name);
	
	printf("Enter your last name: ");
	scanf("%49s", last_name);
	
	printf("Enter the name of your airline: ");
	scanf("%49s", airline_name);

	printf("Enter your flight number: ");
	scanf("%49s", flight_number);
	
	printf("Enter the number of your seat row: ");
	scanf("%49s", seat_row_number);

	printf("Enter the letter of your seat: ");
	scanf("%49s", seat_letter);
	
//**********String functions to simplify passenger information**********//
//------------------------------------------------------------------------//
	// ---- Passenger Info -----
	char passenger_fullname[NAME_LEN] = "";
	strncpy(passenger_fullname, first_name, NAME_LEN - 1); //copies first name to dst
	passenger_fullname[NAME_LEN - 1] = '\0';//Ensures null-terminator
	// Adds space after first name 
	size_t len = strlen(passenger_fullname);//We use len because of how indexes work, start from 0
	if (len < NAME_LEN - 1) {
		passenger_fullname[len] = ' ';
		len++;
	}
	// Adds last name
	strncat(passenger_fullname, last_name,NAME_LEN - len - 1);//Makes sure its placed correctly
	
	// ---- Flight Info ----
	char passenger_flight[NAME_LEN] = "";
	strncpy(passenger_flight, airline_name, NAME_LEN - 1);
	passenger_flight[NAME_LEN - 1] = '\0';
	
	// Adds space
	len = strlen(passenger_flight);
	if (len < NAME_LEN - 1) {
		passenger_flight[len] = ' ';
		len++;
	}

	strncat(passenger_flight, flight_number, NAME_LEN - len - 1);
       
	// ---- Seat Info ----
	char passenger_seat[NAME_LEN] = "";
	strncpy(passenger_seat, seat_row_number, NAME_LEN - 1);
	passenger_seat[NAME_LEN - 1] = '\0';

	// Adds space
	len = strlen(passenger_seat);
	if (len < NAME_LEN - 1) {
		passenger_seat[len] = ' ';
		len++;
	}
	// Adds seat letter
	strncat(passenger_seat, seat_letter, NAME_LEN - len - 1);
//*******Print Statement that prints welcome message to passengern********//
//---------------------------------------------------------------------------------//
	printf("Welcome %s! Your flight is %s. Your seat is %s. Have a great trip!\n", passenger_fullname,
	passenger_flight, passenger_seat);
	 
}

