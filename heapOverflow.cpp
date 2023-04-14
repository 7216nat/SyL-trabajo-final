#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
#define MAX_PASSWORD_LENGTH 7   // 8 bytes

void example(){
    std::unique_ptr<char[]> enteredPassword(new char[MAX_PASSWORD_LENGTH]);
    std::unique_ptr<char[]> loggedInStatus(new char[MAX_PASSWORD_LENGTH]);

    strcpy(loggedInStatus.get(), "notLoggedIn");
    printf("Enter your password to access the system: ");
    std::cin >> enteredPassword.get();

    printf("enteredPassword value: %s\n", enteredPassword.get());
    printf("loggedInStatus value: %s\n", loggedInStatus.get());
    if(strcmp(enteredPassword.get(), "SecretPassword")==0){
        printf("Your password is correct\n");
        strcpy(loggedInStatus.get(), "LoggedIn");
    }else{
        printf("You have entered the incorrect password\n");
    }

    if((strcmp(loggedInStatus.get(), "notLoggedIn")!=0)){
        printf("You now have user privileges\n");
    }

    printf("enteredPassword value: %s\n", enteredPassword.get());
    printf("loggedInStatus value: %s\n", loggedInStatus.get());
}
int main(void){
    example();
}
