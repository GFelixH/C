/*
11.11 (Write Statements to Accomplish a Task)
struct person {
 char lastName[15];
 char firstName[15];
 char age[4];
};
has been defined and that the file is already open for writing.
a) Initialize the file "nameage.dat" so that there are 100 records with lastName = "unassigned", firstname = "" and age = "0".
b) Input 10 last names, first names and ages, and write them to the file.
c) Update a record; if there’s no information in the record, tell the user "No info".
d) Delete a record that has information by reinitializing that particular record.

a)struct person fillPerson = { "unassigned","","0"};
 for(int i=0; i<10; i++){
    fwrite(&fillPerson, sizeof(struct person), 1, fPtr);
 }

 b) fgets(fillperson.lastname, 15, stdin);
    fgets(fillperson.firstname, 15, stdin);
    fgets(fillperson.age, 4, stdin);

 c) fseek(fPtr, x * sizeof(struct person), SEEK_SET);
    if(person.lastname == null) no info

 d) fseek(fPtr, x * sizeof(struct person), SEEK_SET);
    struct person fillPerson = { "unassigned","","0"};
fwrite(&fillPerson, sizeof(struct person), 1, fPtr);
 */