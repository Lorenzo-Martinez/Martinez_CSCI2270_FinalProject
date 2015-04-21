#include <iostream>
#include "Database.h"
using namespace std;

int main()
{
	bool quit;
	string inputName;
	string inputDescription;
	string inputCategory;
	string inputOldCategory;
	string inputNewCategory;
	string inputOldName;
	string inputNewName;
	int inputYearInt;
    string input;
    Database newDatabase(20);

	//displays the menu and takes user input until the user decides to quit
	while(quit!= true)
	{
		cout<<"======Main Menu======"<<endl;
		cout<<"1. Insert category"<<endl;
        cout<<"2. Insert item"<<endl;

        cout<<"3. Delete category"<<endl;
        cout<<"4. Delete item"<<endl;

        cout<<"5. Change item category"<<endl;
        cout<<"6. Change item name"<<endl;
        cout<<"7. Change item description"<<endl;

        cout<<"8. Print category"<<endl;
		cout<<"9. Print categories"<<endl;
		cout<<"10. Print item"<<endl;
		cout<<"11. Print database"<<endl;

		cout<<"12. Quit"<<endl;

		getline(cin,input);

        if(input == "1")
		{

            cout<<"Enter name:"<<endl;
            getline(cin,inputName);
            cout<<"Enter description:"<<endl;
            getline(cin,inputDescription);
            newDatabase.insertCategory(inputName, inputDescription);
		}

        else if(input == "2")
        {
            cout<<"Enter category:"<<endl;
            getline(cin, inputCategory);
            cout<<"Enter name:"<<endl;
            getline(cin,inputName);
            cout<<"Enter description:"<<endl;
            getline(cin,inputDescription);
            newDatabase.insertItem(inputCategory, inputName, inputDescription);
        }
        else if(input == "3")
        {
            cout<<"Enter category:"<<endl;
            getline(cin, inputCategory);
            newDatabase.deleteCategory(inputCategory);
        }
        else if(input == "4")
        {
            cout<<"Enter category:"<<endl;
            getline(cin, inputCategory);
            cout<<"Enter name:"<<endl;
            getline(cin,inputName);
            newDatabase.deleteItem(inputCategory, inputName);
        }
        else if(input == "5")
        {
            cout<<"Enter old category:"<<endl;
            getline(cin, inputOldCategory);
            cout<<"Enter new category:"<<endl;
            getline(cin, inputNewCategory);
            cout<<"Enter name:"<<endl;
            getline(cin,inputName);
            newDatabase.changeItemCategory(inputOldCategory, inputNewCategory, inputName);
        }
        else if(input == "6")
        {
            cout<<"Enter category:"<<endl;
            getline(cin, inputCategory);
            cout<<"Enter old name:"<<endl;
            getline(cin,inputOldName);
            cout<<"Enter new name:"<<endl;
            getline(cin, inputNewName);
            newDatabase.changeItemName(inputCategory, inputOldName, inputNewName);
        }
        else if(input == "7")
        {
            cout<<"Enter category:"<<endl;
            getline(cin, inputCategory);
            cout<<"Enter name:"<<endl;
            getline(cin,inputName);
            cout<<"Enter new description:"<<endl;
            getline(cin, inputDescription);
            newDatabase.changeItemDescription(inputCategory, inputName, inputDescription);
        }
        else if(input == "8")
        {
            cout<<"Enter name:"<<endl;
            getline(cin,inputName);
            newDatabase.printCategory(inputName);
        }
		else if(input == "9")
        {
            newDatabase.printAllCategories();
        }
        else if(input == "10")
        {
            cout<<"Enter category:"<<endl;
            getline(cin, inputCategory);
            cout<<"Enter name:"<<endl;
            getline(cin,inputName);
            newDatabase.printItem(inputCategory, inputName);
        }
        else if(input == "11")
        {
            newDatabase.printDatabase();
        }
		/*
		else if(input == "2")
		{
            cout<<"Enter title:"<<endl;
            getline(cin,inputTitle);
            //delete the movie
            movieTable.deleteMovie(inputTitle);
		}
		else if(input == "3")
        {
            cout<<"Enter title:"<<endl;
            getline(cin,inputTitle);
            movieTable.findMovie(inputTitle);
        }
		else if(input == "4")
        {
            movieTable.printInventory();
        }
        */
        else if(input == "12")
        {
            quit = true;
			cout<<"Goodbye!"<<endl;
        }
        else
        {
            cout<<"Invalid Input"<<endl;
            //skipOne = true;
        }


	}
}
