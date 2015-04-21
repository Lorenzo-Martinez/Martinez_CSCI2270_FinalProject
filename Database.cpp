#include "Database.h"
#include<vector>
#include<iostream>
#include <algorithm>
Database::Database(int size)
{
    for(int i = 0; i < size; i++)
    {
        std::vector<Category> categoryVector;
        tableVector.push_back(categoryVector);
    }
}

Database::~Database()
{

}

//inserts an item into the database
void Database::insertItem(std::string category, std::string name, std::string description)
{

}

//prints the information of all the items in the database
void Database::printDatabase()
{

}

//prints the information of all the items within a category
void Database::printCategory(std::string category)
{

}

//finds an item and prints all of the information related to it
void Database::printItem(std::string category, std::string name)
{

}

//prints all of the categories within the database
void Database::printAllCategories()
{

}

//changes the category of an item
void Database::changeItemCategory(std::string oldCategory, std::string newCategory, std::string name)
{

}

//changes the name of an item
void Database::changeItemName(std::string category, std::string oldName, std::string newName)
{

}

//changes the description of an item
void Database::changeItemDescription(std::string category, std::string name, std::string newDescription)
{

}

//deletes a category
void Database::deleteCategory(std::string category)
{

}

//deletes an item
void Database::deleteItem(std::string category, std::string name)
{

}

//calculates a hashSum
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
