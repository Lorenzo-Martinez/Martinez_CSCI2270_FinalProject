#include "Database.h"
#include<vector>
#include<iostream>
#include <algorithm>
Database::Database(int size)
{
    tableSize = size;
    for(int i = 0; i < size; i++)
    {
        std::vector<Category> categoryVector;
        tableVector.push_back(categoryVector);
    }
}

Database::~Database()
{

}

//inserts a category into the database
void Database::insertCategory(std::string name, std::string description)
{
    Category newCategory(name, description);
    int sum = hashSum(name);
    tableVector[sum].push_back(newCategory);
    numOfCategories++;
}

//inserts an item into the database
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

//prints the information of all the items and categories in the database
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
            std::cout<<tableVector[z][i].name<<" : "<<tableVector[z][i].description<<std::endl;
            for(int y = 0; y < tableVector[z][i].itemVector.size(); y++)
            {
                std::cout<<"--"<<tableVector[z][i].itemVector[y].name<<" : "<<tableVector[z][i].itemVector[y].description<<std::endl;
            }
        }
    }
}

//prints the information of all the items within a category
void Database::printCategory(std::string category)
{
    int sum = hashSum(category);
    for(int i = 0; i < tableVector[sum].size(); i++)
    {
        if(tableVector[sum][i].name == category)
        {
            std::cout<<tableVector[sum][i].name<<" : "<<tableVector[sum][i].description<<std::endl;
            for(int y = 0; y < tableVector[sum][i].itemVector.size(); y++)
            {
                std::cout<<"--"<<tableVector[sum][i].itemVector[y].name<<" : "<<tableVector[sum][i].itemVector[y].description<<std::endl;
            }
        }
    }
}

//finds an item and prints all of the information related to it
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
                    std::cout<<tableVector[sum][i].itemVector[y].name<<" : "<<tableVector[sum][i].itemVector[y].description<<std::endl;
                }
            }
        }
    }
}

//prints all of the categories within the database
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
            std::cout<<tableVector[z][i].name<<" : "<<tableVector[z][i].description<<std::endl;
        }
    }
}

//changes the category of an item
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

//changes the name of an item
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

//changes the description of an item
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

//deletes a category
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

//deletes an item
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

    Calculates a hashsum based on the string passed in as well as the table size that the Database was created with.
    All of the decimal ascii values of each character of the string are added together, then modded by the table size.
    The resulting number is the hashsum.

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
