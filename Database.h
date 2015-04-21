#ifndef DATABASE_H
#define DATABASE_H
#include<string>
#include<vector>
struct Item
{
    std::string category;
    std::string name;
    std::string description;

    Item()
    {

    }

    Item(std::string inCategory, std::string inName, std::string inDescription)
    {
        category = inCategory;
        name = inName;
        description = inDescription;
    }

};

struct Category
{
    std::string name;
    std::string description;
    std::vector<Item> itemVector;

    Category()
    {

    }

    Category(std::string inName, std::string inDescription)
    {
        name = inName;
        description = inDescription;
    }
};
class Database
{
    public:
        Database(int size);
        ~Database();

        //inserts a category into the database
        void insertCategory(std::string name, std::string description);

        //inserts an item into the database
        void insertItem(std::string category, std::string name, std::string description);

        //prints the information of all the items in the database
        void printDatabase();

        //prints the information of all the items within a category
        void printCategory(std::string category);

        //finds an item and prints all of the information related to it
        void printItem(std::string category, std::string name);

        //prints all of the categories within the database
        void printAllCategories();

        //changes the category of an item
        void changeItemCategory(std::string oldCategory, std::string newCategory, std::string name);

        //changes the name of an item
        void changeItemName(std::string category, std::string oldName, std::string newName);

        //changes the description of an item
        void changeItemDescription(std::string category, std::string name, std::string newDescription);

        //deletes a category
        void deleteCategory(std::string category);

        //deletes an item
        void deleteItem(std::string category, std::string name);


    protected:
    private:
        //calculates a hashSum
        int hashSum(std::string stringToHash);

        //number of slots in the hash table
        int tableSize = 0;

        //keeps track of the number of items in the hash table
        int numOfItems = 0;

        //keeps track of the number of categories in the hash table
        int numOfCategories = 0;

        //table vector
        std::vector<std::vector<Category> > tableVector;
};

#endif // DATABASE_H
