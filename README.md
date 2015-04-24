# Martinez_CSCI2270_FinalProject
Final project for CSCI 2270

Project Summary
  
  This program creates a database using strings. When the program is started up, it takes the info from a text document and converts it into a hash table. Information can then be added, deleted, or looked up by the user. When the program is terminated, the information on the hash table is once again converted into a text document. This allows information to be stored while the program is not running. Each place in the hash table has a category. Each category has a description. Within each category, there is items related to that category. Each item has a description. For example, if one of the categories was cars, one of the items in that category might be a Volvo. This flexible system allows the user to make a database of whatever they want, provided that each item only has a category, a name, and a description.

How to Run

1.Download the files located in the repo.
2.Open up a new project in an IDE or something that runs C++ files.
3.Add a blank text file named "Database.txt" into the project folder.
4.Add DriverFile.cpp, Database.cpp, and Database.h to the project and remove main.cpp from the project if there is one.
5.Run DriverFile.cpp.
6.A menu should be brought up in the console.
7.Add as many categories or items as you want. 
8.Quit the progrm by inputting 12. This will save all of the categories and items you added into the Database.txt file.
9.The next time you run the program, the categories and items you added last time will be in the database when you start the program.

Dependencies

This program does not require any third-party libraries, only the standard C++ ones. A Database.txt file within the project folder is required for the program to run properly.

System Requirements

My program runs in an ubuntu operating sytem just fine, but you may encounter issues if you try running it with other operating systems.

Group Members

Lorenzo Martinez

Contributors

Lorenzo Martinez

Open issues/bugs

Currently, the user cannot add descriptions or names with semicolons. This is because the program uses semicolons to split lines of text from the text document into names and descriptions. If there are semicolons in the names or descriptions, then the input from Database.txt is messed up. As a result, the program currently checks for semicolons and does not accept descriptions or names that contain them.
