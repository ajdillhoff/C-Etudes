#include <stdio.h>
#include <string.h>
#include <time.h>

#if defined(_WIN32)
#include <direct.h>
#define getcwd _getcwd
#elif defined(__linux__)
#include <sys/stat.h>
#endif


#define BUFSIZE 256
#define INFO 1
#define WARNING 2
#define ALL 3

typedef struct {
    char log_path[BUFSIZE];
    int log_level;
    int log_to_file;
} config_t;

static config_t log_config_default = { 0 };

void init_logging_config() {
    // Load config from file
    FILE *fp = fopen("config.cfg", "r");

    // Get current date and time as the file name
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char filename[BUFSIZE];
    strftime(filename, sizeof(filename) - 1, "%Y-%m-%d_%H-%M-%S", t);
    strcat(filename, ".log");
    strcat(log_config_default.log_path, "logs/");
    strcat(log_config_default.log_path, filename);

    // Create the logs directory if it doesn't exist
    FILE *dir = fopen("logs", "r");
    if (dir == NULL) {
        mkdir("logs", 0700);
    } else {
        fclose(dir);
    }

    if (fp == NULL) {
        printf("Logging configuration not found, using default settings.\n");
        log_config_default.log_level = ALL;
        log_config_default.log_to_file = 1;
        return;
    }
}

/*
 * Logs a message to the console.
 */
void log_msg(int level, char message[], const char func_name[]) {
    // TODO: Log the message to a file
    FILE *fp = fopen(log_config_default.log_path, "a");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    if (level == WARNING && log_config_default.log_level >= WARNING) {
        fprintf(fp, "[WARNING] %s: %s", func_name, message);
    } else if (level == INFO && (log_config_default.log_level == INFO || log_config_default.log_level == ALL)) {
        fprintf(fp, "[INFO] %s: %s", func_name, message);
    }

    fclose(fp);
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
        log_msg(WARNING, "Password must be at least 8 characters.\n", __func__);
        return 1;
    }

    printf("Enter an email address: ");
    fgets(email, BUFSIZE, stdin);
    trim(email);

    // Validate the email
    if (strchr(email, '@') == NULL) {
        log_msg(WARNING, "Email must contain an @ symbol.\n", __func__);
        return 1;
    }

    log_msg(INFO, "User signed up successfully.\n", __func__);
    return 0;
}

int main() {
    char username[BUFSIZE];
    char password[BUFSIZE];
    char email[BUFSIZE];

    init_logging_config();

    signup(username, password, email);

    return 0;
}