/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int func0() {
    char str[] = "Hello, World!";
    memfrob(str, strlen(str));
    printf("Frobbed string: %s\n", str);
    return 0;
}

int func1() {
    char buf[100];
    confstr(_CS_PATH, buf, sizeof(buf));
    printf("GNU libc version: %s\n", buf);
    return 0;
}

int func2() {
    dprintf(STDOUT_FILENO, "Hello, %s!\n", "World");
    return 0;
}

int func3() {
    char buffer[100];
    getcwd(buffer, sizeof(buffer));
    printf("Current directory: %s\n", buffer);
    return 0;
}

int func4() {
    char buffer[100];
    getlogin_r(buffer, sizeof(buffer));
    printf("Login name: %s\n", buffer);
    return 0;
}

int func5()
{
    char str[50] = "hello";
    printf("The given string is = %s\n", str);
    char temp[50];
    int i = 0, j = strlen(str)-1;
    for(i, j; i<strlen(str); i++, j--) {
        temp[i] = str[j];
    }
    temp[strlen(str)] = '\0';
    
    printf("The reversed string is = %s\n", temp);
    
    return 0;
}

int func6() {
    char *name = "malayalam";
    bool isPalindrom = true;
    for(int i = 0, j = strlen(name)-1; i < (strlen(name)/2) + 1; i++, j--) {
        if (name[i] != name[j]) {
            isPalindrom = false;
            break;
        }
    }
    printf("\"%s\" is %s word\n", name, (isPalindrom)?"Palindrome" : "not Palindrome");
}

int main() {
    char str[] = "HelloWorld";
    strfry(str);
    printf("Fried string: %s\n", str);
    
    func0();
    func1();
    func2();
    func3();
    func4();
    func5();
    func6();
    
    return 0;
}
