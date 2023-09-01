# Log Files

Logging events that happen in your program is important not only for your own analysis, but for helping others debug their issues when using your program.

This etude will have you create a simple logging system that can be used in your programs. Since the focus is file I/O. The program should start by loading the `logging.cfg` file and parsing the information. This file contains the following configuration options:
- log_dir: logs/
- log_level: INFO
- log_function: True
- print_log: False

The `log_dir` is the directory where the log files will be stored. The `log_level` option determines what sort of information should be logged. It can either be set to `WARNING`, `INFO`, or `ALL`. If it is set to `WARNING`, then The `log_function` is a boolean value that determines if the name of the current function should be included inthe log. The `print_log` is a boolean value that determines if the log should also be printed to the console.

The program should then create a log file in the `log_dir` directory. The name of the log file should be the current date and time in the format `YYYY-MM-DD-HH-MM-SS.log`. Your program should include any relevant log information based on if the log function was called in the original program. The log file should be closed when the program exits.

This etude already comes with a program that prompts the user to enter form information. It goes through several functions, each one calling the log function. Your task is to implement the required functionality so that the program compiles and logs the information correctly.