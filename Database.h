#ifndef DATABASE_H
#define DATABASE_H
#include<string>
#include<vector>
struct Item
{
    std::string category;
    std::string description;

    Item()
    {

    }

    Item(std::string in_title, int in_year)
    {
        title = in_title;
        year = in_year;
    }

};

class Database
{
    public:
        Database(int);
        ~Database();

        //inserts an item into the database
        void insertItem(std::string category, std::string description);

        //prints the information of all the items in the database
        void printDatabase();

    protected:
    private:
        //calculates a hashSum using x, which is the string to hash, as well as s, which is the array size of the table
        int hashSum(std::string x, int s);

        //number of slots in the hash table
        int tableSize = 0;

        //keeps track of the number of items in the hash table
        int numOfItems = 0;

        //table vector
        std::vector<std::vector<Item> > tableVector;
};

#endif // DATABASE_H
