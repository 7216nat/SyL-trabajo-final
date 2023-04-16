#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_PASSWORD_LENGTH 8   // 8 bytes

int main(void){
    char *enteredPassword = (char *)malloc(8*sizeof(char));
    char *loggedInStatus = (char *)malloc(8*sizeof(char));

    strcpy(loggedInStatus, "notLoggedIn");
    printf("Enter your password to access the system: ");
    gets(enteredPassword);

    if(strcmp(enteredPassword, "SecretPassword")==0){
        printf("Your password is correct\n");
        loggedInStatus = "LoggedIn";
    }else{
        printf("You have entered the incorrect password\n");
    }

    if((strcmp(loggedInStatus, "notLoggedIn")!=0)){
        printf("You now have user privileges\n");
    }

    printf("enteredPassword value: %s\n", enteredPassword);
    printf("loggedInStatus value: %s\n", loggedInStatus);
    
    free(enteredPassword);
    free(loggedInStatus);
}
