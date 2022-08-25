/*8.26 (Write Your Own Character-Handling Functions) Using the ASCII character chart in
Appendix B as a guide, write your own versions of the character-handling functions in Fig. 8.1.


int isalpha(int c); Returns a true value if c is a letter and 0 (false) otherwise.

int isalnum(int c); Returns a true value if c is a digit or a letter and 0 (false) otherwise.

int isxdigit(int c); Returns a true value if c is a hexadecimal digit character and 0 (false) otherwise. (See Appendix C for a detailed explanation of binary numbers,
octal numbers, decimal numbers and hexadecimal numbers.)

int islower(int c); Returns a true value if c is a lowercase letter and 0 (false) otherwise.

int isupper(int c); Returns a true value if c is an uppercase letter and 0 (false) otherwise.

int tolower(int c); If c is an uppercase letter, tolower returns c as a lowercase letter. Otherwise,
tolower returns the argument unchanged.

int toupper(int c); If c is a lowercase letter, toupper returns c as an uppercase letter. Otherwise,
toupper returns the argument unchanged.

int isspace(int c); Returns a true value if c is a whitespace character—newline ('\n'), space
(' '), form feed ('\f'), carriage return ('\r'), horizontal tab ('\t') or
vertical tab ('\v')—and 0 (false) otherwise.

int iscntrl(int c); Returns a true value if c is a control character—horizontal tab ('\t'), vertical tab ('\v'), form feed ('\f'), alert ('\a'), backspace ('\b'), carriage
return ('\r'), newline ('\n') and others—and 0 (false) otherwise.

int ispunct(int c); Returns a true value if c is a printing character other than a space, a digit,
or a letter—such as $, #, (, ), [, ], {, }, ;, : or %—and returns 0 otherwise.

int isprint(int c); Returns a true value if c is a printing character (i.e., a character that’s visible on the screen) including a space and returns 0 (false) otherwise.

int isgraph(int c); Returns a true value if c is a printing character other than a space and
returns 0 (false) otherwise
*/
#include <stdio.h>
int isblank(int c);
/*
int isdigit(int c); Returns a true value if c is a digit and 0 (false) otherwise.
*/
int isDigit(int c)
{
    return (c > 47 && c < 58);
}
/*
Returns a true value if c is a blank character that separates words in a line of text and 0(false)otherwise.
*/
int isBlank(int c)
{
    return c == 32;
}

int main(void)
{
    return 0;
}