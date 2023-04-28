<a target="_top" href="https://flamingtext.com/" ><img src="https://blog.flamingtext.com/blog/2023/04/28/flamingtext_com_1682719092_44598376.jpg" border="0" alt="Logo Design by FlamingText.com" title="Logo Design by FlamingText.com"></a>
<br/> <a href="" ></a>

# Shell

This code implements a very basic shell that allows command execution on Unix-based operating systems. 
The functionality of this shell includes the ability to display the prompt, read and parse user input, and execute commands entered by the user.


### Flowchar

![flowchar de shell(simpleshell) drawio](https://user-images.githubusercontent.com/124283901/235261395-c00c5d58-ea75-4337-a7f3-a4b1c5c2fe94.png)

#### How it worksl

* main()

This main function contains the main shell loop. It reads the user input, parses it and executes the entered commands. If the user enters the command "exit", the program terminates.

* isatty()

This function determines whether a file descriptor refers to an interactive terminal. In this case, it is used to check whether it is running on a terminal, which determines whether the prompt should be displayed.

* getline()

This function reads an input line from standard input and stores it in the command string.

* tokenize()

This function takes an input string and splits it into tokens using spaces as delimiters. The resulting tokens are stored in an array of strings (tokenargv) that is used to execute the command.

* print_env()

This function displays the system environment variables.

* _strcmp()

This function compares two strings and returns 0 if they are the same. It is used to compare the first token entered by the user with the available commands (in this case, only "env" and "exit").

* execute()

This function uses the execvp() function to execute the command entered by the user. If the command cannot be executed, an error message is displayed in the console.

* free_token()

This function frees the memory allocated to the token array (tokenargv) after the command is executed.