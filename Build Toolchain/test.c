#include <stdio.h>
//This is a comment
int main(){
    char name[30];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Good morning %s.  Have a nice day!", name);
    return 0;
}