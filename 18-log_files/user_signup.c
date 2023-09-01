#include <stdio.h>
#include <string.h>

#define BUFSIZE 256
#define WARNING 1
#define INFO 2

/*
 * Logs a message to the console.
 */
void log(int level, char message[], char func_name[]) {
    // TODO: Log the message to a file
}

/*
 * Removes the trailing newline character from a string, if it exists.
 */
void trim(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

/*
 * Signs up a new user.
 * Returns 0 if successful, 1 if unsuccessful.
 */
int signup(char username[], char password[], char email[]) {
    printf("Enter a username: ");
    fgets(username, BUFSIZE, stdin);
    trim(username);

    printf("Enter a password (must be at least 8 chars): ");
    fgets(password, BUFSIZE, stdin);
    trim(password);

    // Validate the password
    if (strlen(password) < 8) {
        log(WARNING, "Password must be at least 8 characters.\n", __func__);
        return 1;
    }

    printf("Enter an email address: ");
    fgets(email, BUFSIZE, stdin);
    trim(email);

    // Validate the email
    if (strchr(email, '@') == NULL) {
        log(WARNING, "Email must contain an @ symbol.\n", __func__);
        return 1;
    }

    log(INFO, "User signed up successfully.\n", __func__);
    return 0;
}

int main() {
    char username[BUFSIZE];
    char password[BUFSIZE];
    char email[BUFSIZE];

    signup(username, password, email);

    return 0;
}