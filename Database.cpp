#include "Database.h"
#include<vector>
#include<iostream>
#include <algorithm>
#include <fstream>
#include <iostream>
#include<sstream>

Database::Database(int size)
{
    tableSize = size;

    for(int i = 0; i < size; i++)
    {
        std::vector<Category> categoryVector;
        tableVector.push_back(categoryVector);
    }

    std::string currentLine;
    std::fstream databaseStream;
    databaseStream.open("Database.txt");
    int one_two_counter = 0;
    std::string category;
    std::string name;
    std::string description;
    std::string inText;
    while(!databaseStream.eof())
    {

        getline(databaseStream, currentLine);
        std::istringstream lineStream(currentLine);

        if(currentLine[0] != '-' && currentLine != "")
        {
            while(getline(lineStream, inText, ':' ))
            {
                if(one_two_counter == 0)
                {
                    one_two_counter++;
                    category = inText;
                }
                else if(one_two_counter == 1)
                {
                    one_two_counter++;
                    description = inText;
                    one_two_counter = 0;
                }
            }
            insertCategory(category, description);
        }
        else if(currentLine != "")
        {
            while(getline(lineStream, inText, ':' ))
            {
                if(one_two_counter == 0)
                {
                    one_two_counter++;
                    name = inText.substr(2);
                }
                else if(one_two_counter == 1)
                {
                    one_two_counter++;
                    description = inText;
                    one_two_counter = 0;
                }
            }
            insertItem(category, name, description);
        }
    }
    databaseStream.close();
}

Database::~Database()
{
    std::fstream databaseStream;
    databaseStream.open("Database.txt");
    if(databaseStream.fail())
    {
        std::cout<<"failed to open file"<<std::endl;
    }
    if(numOfCategories == 0)
    {
        std::cout<<"empty"<<std::endl;
    }
    for(int z = 0; z< tableVector.size(); z++)
    {
        for(int i = 0; i < tableVector[z].size(); i++)
        {
            databaseStream<<tableVector[z][i].name<<":"<<tableVector[z][i].description<<std::endl;
            std::cout<<tableVector[z][i].name<<":"<<tableVector[z][i].description<<std::endl;
            for(int y = 0; y < tableVector[z][i].itemVector.size(); y++)
            {
                databaseStream<<"--"<<tableVector[z][i].itemVector[y].name<<":"<<tableVector[z][i].itemVector[y].description<<std::endl;
            }
        }
    }
    databaseStream.close();
}

/*
    void insertCategory(string, string)

    Inserts a category into the database. First, a new category with the name and description passed in is created.
    Second, the place for the new category is determined via a the hash sum of the new category's name.
    The new category is then inserted at that place in the database.

    insertCategory("Food", "Things that are meant to be eaten") will insert a category with the name "Food" and the description "Things that are meant to be eaten".

    pre-conditions: the category name and description cannot have semicolons in them

    post-conditions: a category with the name and description passed in will now exist within the database
*/
void Database::insertCategory(std::string name, std::string description)
{
    Category newCategory(name, description);
    int sum = hashSum(name);
    tableVector[sum].push_back(newCategory);
    numOfCategories++;
}

/*
    void insertItem(string, string, string)

    Inserts an item into the database. First, a new item with the name and description passed in is created.
    Second, the category that the item is going to be inserted into is found via the hash sum of the category name. Then the item is added to that category.

    insertItem("Food", "Apple", "Sweet red fruit") will insert an item with the name "Apple" and the description "Sweet red fruit" into the category "Food"

    pre-conditions: the category has to already be in the database and the name and description of the item cannot have semicolons in them

    post-conditions: an item with the name and description passed in will now exist within the specified category
*/
void Database::insertItem(std::string category, std::string name, std::string description)
{
    Item newItem(category, name, description);
    int sum = hashSum(category);
    for(int z = 0; z<tableVector[sum].size(); z++)
    {
        if(tableVector[sum][z].name == category)
        {
            tableVector[sum][z].itemVector.push_back(newItem);
        }
    }
    numOfItems ++;
}

/*
    void printDatabase()

    Parses all of the category vectors in each spot of the hash table and prints their names and descriptions as well as the names and descriptions of the items within each category.
    If there are no categories in the database, "empty" will be printed

    if the hash table has the category "Food" with the description "Things that are meant to be eaten"  and within that category is the item "Apple" with the description "Sweet red fruit"
    and the hash table also has the category "Decoration" with the description "Things that are meant to be displayed" and within that category is the item "Sun Painting" with the description
    "Painting of the sun rising over the horizon"
    then printDatabase() will display: "Food:Things that are meant to be eaten"
                                       "--Apple:Sweet red fruit"
                                       "Decoration:Things that are meant to be displayed"
                                       "--Sun Painting:Painting of the sun rising over the horizon"

    pre-conditions: none

    post-conditions: none
*/
void Database::printDatabase()
{
    if(numOfCategories == 0)
    {
        std::cout<<"empty"<<std::endl;
    }
    for(int z = 0; z< tableVector.size(); z++)
    {
        for(int i = 0; i < tableVector[z].size(); i++)
        {
            std::cout<<tableVector[z][i].name<<":"<<tableVector[z][i].description<<std::endl;
            for(int y = 0; y < tableVector[z][i].itemVector.size(); y++)
            {
                std::cout<<"--"<<tableVector[z][i].itemVector[y].name<<":"<<tableVector[z][i].itemVector[y].description<<std::endl;
            }
        }
    }
}

/*
    void printCategory(string)

    Prints the name and description of a category and of all the items in that category.
    First, the category that the item belongs in is found via the hash sum of the category name,
    then the category. The name and description of that category is printed.
    Then, the category is parsed and all of the names and descriptions of the items within that category are printed

    if the category "Food" with the description "Things that are meant to be eaten" has an item called
    "Apple" with the description "Sweet red fruit" then printCategory("Food") will print: "Food:Things that are meant to be eaten"
                                                                                          "--Apple:Sweet red fruit"

    pre-conditions: the category has to exist

    post-conditions: none
*/
void Database::printCategory(std::string category)
{
    int sum = hashSum(category);
    for(int i = 0; i < tableVector[sum].size(); i++)
    {
        if(tableVector[sum][i].name == category)
        {
            std::cout<<tableVector[sum][i].name<<":"<<tableVector[sum][i].description<<std::endl;
            for(int y = 0; y < tableVector[sum][i].itemVector.size(); y++)
            {
                std::cout<<"--"<<tableVector[sum][i].itemVector[y].name<<":"<<tableVector[sum][i].itemVector[y].description<<std::endl;
            }
        }
    }
}

/*
    void printItem(string, string)

    Prints the name and description of an item. First, the category that the item belongs in is found via the hash sum of the category name,
    then the category is searched for the item. The item's name and description is then printed.

    if the category "Food" has an item called "Apple" with the description "Sweet red fruit" then printItem("Food", "Apple") will print: "Apple:Sweet red fruit"

    pre-conditions: the item and category have to exist

    post-conditions: none
*/
void Database::printItem(std::string category, std::string name)
{
    int sum = hashSum(category);
    for(int i = 0; i < tableVector[sum].size(); i++)
    {
        if(tableVector[sum][i].name == category)
        {
            for(int y = 0; y < tableVector[sum][i].itemVector.size(); y++)
            {
                if(tableVector[sum][i].itemVector[y].name == name)
                {
                    std::cout<<tableVector[sum][i].itemVector[y].name<<":"<<tableVector[sum][i].itemVector[y].description<<std::endl;
                }
            }
        }
    }
}

/*
    void printAllCategories()

    Parses all of the category vectors in each spot of the hash table and prints their names and descriptions. If there are no categories in the database, "empty" will be printed

    if the hash table has the category "Food" with the description "Things that are meant to be eaten" and the category "Decoration" with the description "Things that are meant to be displayed"
    then printAllCategories() will display: "Food:Things that are meant to be eaten"
                                            "Decoration:Things that are meant to be displayed"

    pre-conditions: none

    post-conditions: none
*/
void Database::printAllCategories()
{
    if(numOfCategories == 0)
    {
        std::cout<<"empty"<<std::endl;
    }
    for(int z = 0; z< tableVector.size(); z++)
    {
        for(int i = 0; i < tableVector[z].size(); i++)
        {
            std::cout<<tableVector[z][i].name<<":"<<tableVector[z][i].description<<std::endl;
        }
    }
}

/*
    void changeItemCategory(string, string, string)

    Changes the category of an item. First, the category that the item belongs in is found via the hash sum of the category name,
    then the category is searched for the item. The description and name of that item are then saved in temp variables.
    The item is then deleted from its old category. The new category is found via the hash sum of the category name, and a new
    item with the same name and description as the item that was deleted is added to that category.

    changeItemCategory("Food", "Decoration", "Plastic Apple") will change the category of "Plastic Apple" from "Food" to "Decoration"

    pre-conditions: the old and new category and item have to already be in the database

    post-conditions: the item will be permanently removed from the old category and added to the new one
*/
void Database::changeItemCategory(std::string oldCategory, std::string newCategory, std::string name)
{
    std::string description;
    int sum = hashSum(oldCategory);
    for(int i = 0; i < tableVector[sum].size(); i++)
    {
        if(tableVector[sum][i].name == oldCategory)
        {
            for(int y = 0; y < tableVector[sum][i].itemVector.size(); y++)
            {
                if(tableVector[sum][i].itemVector[y].name == name)
                {
                    description = tableVector[sum][i].itemVector[y].description;
                    tableVector[sum][i].itemVector.erase(tableVector[sum][i].itemVector.begin()+y);
                }
            }
        }
    }
    Item itemToMove(newCategory, name, description);
    sum = hashSum(newCategory);
    for(int i = 0; i < tableVector[sum].size(); i++)
    {
        if(tableVector[sum][i].name == newCategory)
        {
            tableVector[sum][i].itemVector.push_back(itemToMove);
        }
    }

}

/*
    void changeItemName(string, string, string)

    Changes the name of an item. First, the category that the item belongs in is found via the hash sum of the category name,
    then the category is searched for the item. The old item's name is then replaced by the new one.

    changeItemName("Food", "Apple", "Orange") will change the name of "Apple" in the category "Food" to "Orange"

    pre-conditions: the category and item have to already be in the database and the new name cannot have a semicolon in it

    post-conditions: the name of the item will be permanently changed to the new name
*/
void Database::changeItemName(std::string category, std::string oldName, std::string newName)
{
    int sum = hashSum(category);
    for(int i = 0; i < tableVector[sum].size(); i++)
    {
        if(tableVector[sum][i].name == category)
        {
            for(int y = 0; y < tableVector[sum][i].itemVector.size(); y++)
            {
                if(tableVector[sum][i].itemVector[y].name == oldName)
                {
                    tableVector[sum][i].itemVector[y].name = newName;
                }
            }
        }
    }

}

/*
    void changeItemDescription(string, string, string)

    Changes the description of an item. First, the category that the item belongs in is found via the hash sum of the category name,
    then the category is searched for the item. The old item's description is then replaced by the new one.

    changeItemDescription("Food", "Apple", "Sweet red fruit") will change the description of "Apple" in the category "Food" to "Sweet red fruit"

    pre-conditions: the category and item have to already be in the database and the new description cannot have a semicolon in it

    post-conditions: the description of the item will be permanently changed to the new description
*/
void Database::changeItemDescription(std::string category, std::string name, std::string newDescription)
{
    int sum = hashSum(category);
    for(int i = 0; i < tableVector[sum].size(); i++)
    {
        if(tableVector[sum][i].name == category)
        {
            for(int y = 0; y < tableVector[sum][i].itemVector.size(); y++)
            {
                if(tableVector[sum][i].itemVector[y].name == name)
                {
                    tableVector[sum][i].itemVector[y].description = newDescription;
                }
            }
        }
    }
}

/*
    void deleteCategory(string)

    Deletes a category from the database. First, the vector that the category should be found in is located by using the hash sum of the category name.
    Then, The vector of categories at that location is searched for the specific category. Once it is found, it is erased from the vector.
    All of the items that were in that category are deleted as well.

    deleteCategory(Food) will delete the category "Food" and all of the items within it

    pre-conditions: the category has to already be in the database

    post-conditions: the category and all of its associated items will no longer be in the database and will be permanently deleted
*/
void Database::deleteCategory(std::string category)
{
    int sum = hashSum(category);
    for(int i = 0; i < tableVector[sum].size(); i++)
    {
        if(tableVector[sum][i].name == category)
        {
            tableVector[sum].erase(tableVector[sum].begin()+i);
        }
    }
    numOfCategories--;
}

/*
    void deleteItem(string, string)

    Deletes an item from the database. First, the category that the item belongs in is found via the hash sum of the category name,
    then the category is searched for the item. THe item is then erased from the category's vector.

    deleteItem(Food, Apple) will delete the item "Apple" within the category "Food" providing that they both exist

    pre-conditions: the item and category have to already be in the database

    post-conditions: the item will no longer be in the database and will be permanently deleted
*/
void Database::deleteItem(std::string category, std::string name)
{
    int sum = hashSum(category);
    for(int i = 0; i < tableVector[sum].size(); i++)
    {
        if(tableVector[sum][i].name == category)
        {
            for(int y = 0; y < tableVector[sum][i].itemVector.size(); y++)
            {
                if(tableVector[sum][i].itemVector[y].name == name)
                {
                    tableVector[sum][i].itemVector.erase(tableVector[sum][i].itemVector.begin()+y);
                }
            }
        }
    }
    numOfItems--;
}
/*
    int hashSum(string)

    Calculates a hash sum based on the string passed in as well as the table size that the Database was created with.
    All of the decimal ascii values of each character of the string are added together, then modded by the table size.
    The resulting number is the hash sum.

    hashSum(Dog) with a table size of 10 will return 2

    pre-conditions: none

    post-conditions: none
*/
int Database::hashSum(std::string stringToHash)
{
    int sum = 0;
    for(int i = 0; i< stringToHash.length(); i++)
    {
        sum =sum + stringToHash[i];
    }
    sum = sum % tableSize;
    return sum;
}
