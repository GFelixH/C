#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
    int c, x, y, z;
    double d, e, f;
    char *ptr;
    char s1[100] = {};
    char s2[100] = {};

    c = toupper(c);
    int r1 = isdigit(c);
    int r2 = iscntrl(c);
    size_t x = 199;
    fgets(s1, x, stdin);
    puts(s1);
    ptr = strrchr(s1, 'c');
    putchar(c);
    x = isalpha(c);
    c = getchar();
    ptr = strstr(s1, s2);
    x = isprint(c);
    sscanf("1.27 10.3 9.432", "%lf %lf%lf", &d, &e, &f);
    strcpy(s1, s2);
    ptr = strpbrk(s1, s2);
    int a2 = strcmp(s1, s2);
    ptr = strchr(s1, c);
    sprintf(s1, "%7d %7d %7d", &x, &y, &z);
    strcat(s1, s2);
    size_t n = strlen(s1);
    ptr = strtok(s1, ",");
    // Show two different ways to initialize character array vowel with the string of vowels "AEIOU"
    char vowel[] = {"AEIOU"};
    char vowel2[] = {'A', 'E', 'I', 'O', 'U', '\0'};
    /*
    char s1[50] = "jack", s2[50] = "jill", s3[50];
*a) printf("%c%s", toupper(s1[0]), &s1[1]);
*b) printf("%s", strcpy(s3, s2));
*c) printf("%s", strcat(strcat(strcpy(s3, s1), " and "), s2));
*d) printf("%u", strlen(s1) + strlen(s2));
*e) printf("%u", strlen(s3)); // using s3 after part (c) executes
*
*a) Error value &s1[1] returns type %p
*b)ok
*c)s3 can hold it
*d)ok
*e)returns 50
*printf("%u", strlen(s3)); // using s3 after part (c) executes
8.4 Find the error in each of the following program segments and explain how to correct it:
a) char s[10];
strncpy(s, "hello", 5);
printf("%s\n", s);
b) printf("%s", 'a');
c) char s[12];
strcpy(s, "Welcome Home");
d) if (strcmp(string1, string2)) {
puts("The strings are equal");
}*/
}