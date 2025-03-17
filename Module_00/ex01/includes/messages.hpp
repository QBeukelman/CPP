/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   messages.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 23:21:42 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2025/03/17 23:21:45 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_HPP
#define MESSAGES_HPP

#define MAX_FIELD_WIDTH		7

// Introduction
#define INTRO_MESSAGE		"\nPhone book started.\nStore up to 8 contacts, thereafter the first contact is overwritten.\nThe table schema is as follows:"
#define TABLE_SCHEMA 		"[i] | first    | last     | phone    "

#define MANUAL_TITLE		"Commands:"
#define ADD_MANUAL		 	"\tAdd a new contact to the phone book."
#define SEARCH_MANUAL	 	"\tSearch for an existing contact by index"
#define EXIT_MANUAL		 	"\tTerminate program."

// Commands
#define ENTER_CMD			"[Phone Book]: "
#define INVALID_CMD			"Command not found, try: add, search, exit:"
#define ADDED_CONTACT		"Contact added successfully."
#define EMPTY_BOOK			"The phone book contains no contacts. Please use 'add' to enter contacts."
#define SEARCH_PROMPT		"Contact index 1 to 8:"
#define INVALID_INDEX		"Index out of range or contact does not exist. Try a number between 1 and 8."

// Write contact
#define TABLE_SEPERATOR		" | "

// Exit
#define EXIT_PROGRAM		"\tPhone book closed."

#endif
