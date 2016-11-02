/*
 Autori: Arta, Leart, Edis
 Data 30/10/2016
 Revidimi i fundit : 31/10/2016
 */

#include <iostream>
#include <algorithm>
#include <string>
#ifndef BOOK_H
#define BOOK_H

using namespace std;



struct Book
{
    string ID;
    string ISBN;
    string ISSN;
    string Title;
    string Author;
    
    
    
    
    void PrintInfo()
    {
        cout << "\n ID : " << ID
        << "\n ISBN : " << ISBN
        << "\n  ISSN : " << ISSN
        << "\n Title : " <<Title
        << "\n Author: " << Author;
       
        
    }
};

struct  BookManager
{
    Book *books;
    int book_nr;
    
    bool Contains(string base_string, string search_criteria)
    {
        transform(base_string.begin(), base_string.end(), base_string.begin(), ::tolower);
        transform(search_criteria.begin(), search_criteria.end(), search_criteria.begin(), ::tolower);
        
        if (base_string.find(search_criteria) != string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void Search(string search_criteria)
    {
        
        for (int i = 0; i < book_nr; i++)
        {
            if (Contains(books[i].ID,search_criteria) ||
                Contains(books[i].ISBN, search_criteria) ||
                Contains(books[i].Title, search_criteria) ||
                Contains(books[i].Author, search_criteria) ||
                Contains(books[i].ISSN, search_criteria))
            {
                books[i].PrintInfo();
            }
            
        }
    }
};

int main()
{
    BookManager bm;
    Book stud[] = {
        {"1"," 0735611319","978-0735611313", "The Hidden Language of Computer Hardware and Software ", "Charles Petzold"},
        {"2"," 1518662587","978-1518662584", "Computer Programming for Beginners - Learn the Basics of Java, SQL & C++", "Joseph Connor"},
        {"3"," 1442113987","978-1442113985", "How Computers Work: Processor And Main Memory (Second Edition)", "Roger Young"},
        {"4"," 1511654945"," 978-1511654944", "Introduction to Networking: How the Internet Works ", "Dr. Charles R Severance "},
        

        
    };
    
    bm.books = stud;
    bm.book_nr = 4;
    
    string search;
    cout << "If you want to search enter the ID,ISSN,ISBN the Title or the Auther of the book : ";
    
    
    
    
    while (true)
    {
        cin >> search;
        bm.Search(search);
    }
    
    
    
}
