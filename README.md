# Token-Splitter

This program is a token analyzer written in C. It reads input from the user and analyzes each token, categorizing them into different types such as keywords, operators, identifiers, and numbers. It also maintains a symbol table to store the symbols along with their corresponding addresses and types.
Getting Started

To compile and run the code, make sure you have a C compiler installed on your system. This program uses the standard C library functions, so no additional dependencies are required.

    Copy the code provided into a file with a .c extension (e.g., token_analyzer.c).

    Open a terminal or command prompt and navigate to the directory where the file is saved.

    Compile the code using the following command:

        gcc token_analyzer.c -o token_analyzer

    Run the program:

        ./token_analyzer

Usage

    Upon running the program, it will prompt you to enter input. Enter the text you want to analyze, and press Enter.
    The program will tokenize the input, categorize each token, and store it in the symbol table.
    Repeat the process to analyze more input.
    To stop the program, enter ~ as the input.

Symbol Table

The program maintains a symbol table to store the analyzed symbols along with their addresses and types. The symbol table is displayed after analyzing each input. The columns of the symbol table are as follows:

    Symbol: The name of the analyzed symbol.
    Address: The address of the symbol.
    Type: The type of the symbol (kw for keywords, op for operators, id for identifiers, and num for numbers).

Code Explanation

The code is organized into functions to perform specific tasks. Here's a brief explanation of each function:

    addsym: This function adds a symbol to the symbol table. It takes the symbol's name and type as arguments and stores them in the symbol table along with an assigned address.
    pnt: This function prints the contents of the symbol table, displaying the symbol names, addresses, and types.
    iskey: This function checks if a given word is a keyword by comparing it with a list of predefined keywords.
    isop: This function checks if a given symbol is an operator by comparing it with a list of predefined operators.
    isid: This function checks if a given symbol is a valid identifier by verifying that it contains only alphanumeric characters.
    isnum: This function checks if a given symbol is a valid number by verifying that it contains only digits.
    main: The main function is the entry point of the program. It reads input from the user, tokenizes it using strtok, and analyzes each token by calling the appropriate functions. The program stops reading input if the user enters ~.

Contributing
This program is a simple token analyzer and can be expanded or modified to suit specific requirements. If you would like to contribute to the project, feel free to fork the repository and submit your pull requests.

If you encounter any issues or have suggestions for improvements, please open an issue in the repository.

License
This code is released under the MIT License. Feel free to use, modify, and distribute it as per the terms of the license.
