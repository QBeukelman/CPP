# Module 00

## Ex00

The megaphone program takes the first argument from the standard input. It writes the same string to the standard output with all alphabetical characters capitalised.

### Usage

Compile the program
```
make
```

Run the program
```
./megaphone
```
<br><br/>


## Ex01

The phone_book program is a command line phone book. One can enter up to 8 contacts containing the fields `first_name`, `last_name` and `phone_number`. If 8 contacts have already been entered, new contacts are added in the order from oldest to newest. Contacts do not persist.

Use the phone book with the following commands:

- `add` Create new contact. Users are prompted to enter fields individually.
- `search` Search a contact by its index. Results are displayed in a pipe separated table format, with strings truncated to 10 characters.
- `exit` Exit the phone book and erase all contacts.


### Usage

Compile the program
```
make
```

Run the program
```
./phone_book
```
<br><br/>