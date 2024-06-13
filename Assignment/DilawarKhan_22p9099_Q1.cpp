#include <iostream>
using namespace std;
class Date
{
    int year;
    int month;
    int day;

public:
    Date(int day = 0, int month = 0, int year = 0)
    {
        setDate(day, month, year);
    }
    void setDate(int day, int month, int year)
    {
        if (day > 0 && day <= 31)
        {
            this->day = day;
        }
        else
        {
            return;
        }
        if (month > 0 && month <= 12)
        {
            this->month = month;
        }
        else
        {

            return;
        }
        if (year > 0)
        {
            this->year = year;
        }
        else
        {

            return;
        }
    }
    int getYear()
    {
        return year;
    }
    int getMonth()
    {
        return month;
    }
    int getDay()
    {
        return day;
    }
    void Display()
    {
        // display in form day/month/year
        if (day < 10)
        {
            cout << "0";
        }
        cout << day << "/";
        if (month < 10)
        {
            cout << "0";
        }
        cout << month << "/";
        cout << year << endl;
    }
};
class Book
{
    string ISBN;
    string author;
    string title;
    string genre;
    Date publication_date;

public:
    Book(string ISBN = "", string author = "", string title = "", string genre = "", int day = 0, int month = 0, int year = 0)
    {
        setISBN(ISBN);
        setAuthor(author);
        setTitle(title);
        setGenre(genre);
        setDate(day, month, year);
    }
    void setISBN(string ISBN)
    {
        this->ISBN = ISBN;
    }
    string getISBN()
    {
        return ISBN;
    }

    void setAuthor(string author)
    {
        this->author = author;
    }
    string getAuthor()
    {
        return author;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    string getTitle()
    {
        return title;
    }
    void setGenre(string genre)
    {
        this->genre = genre;
    }
    string getGenre()
    {
        return genre;
    }
    void setDate(int day, int month, int year)
    {
        publication_date.setDate(day, month, year);
    }
    int getYear()
    {
        publication_date.getYear();
    }
    int getMonth()
    {
        publication_date.getMonth();
    }
    int getDay()
    {
        publication_date.getDay();
    }
    void Display()
    {
        cout << "ISBN: " << ISBN << endl;
        cout << "Athor: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Publication Date: ";
        publication_date.Display();
    }
};
class Node
{
public:
    Node *next;
    Node *prev;
    Book data;

    Node(string ISBN, string author, string title, string genre, int day, int month, int year)
    {
        data.setISBN(ISBN);
        data.setAuthor(author);
        data.setTitle(title);
        data.setGenre(genre);
        data.setDate(day, month, year);
        next = NULL;
        prev = NULL;
    }
};
class DoublyList
{

    Node *head;

public:
    DoublyList()
    {

        head = NULL;
    }
    // All These insert functions will be used in AddBook function
    // code from this line till line 265 is for a proper sorted insertion
    void Insert_At_Head(Node *n)
    {
        n->next = head;
        if (head != NULL)
        {
            head->prev = n;
        }
        head = n;
    }
    void Insert_At_End(Node *n)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
    void Insert_Before(Node *n, Node *curr)
    {
        n->next = curr;
        n->prev = curr->prev;
        if (curr->prev != NULL)
        {
            curr->prev->next = n;
        }
        curr->prev = n;
    }
    void AddBook(string ISBN, string author, string title, string genre, int day, int month, int year)
    {
        Node *n = new Node(ISBN, author, title, genre, day, month, year);

        Helper_AddBook(n, head);
    }
    void Helper_AddBook(Node *n, Node *curr)
    {
        if (head == NULL)
        {
            Insert_At_Head(n);
        }
        else if (curr == NULL)
        {
            Insert_At_End(n);
        }
        else if (n->data.getYear() < curr->data.getYear() && curr == head)
        {
            Insert_At_Head(n);
        }
        else if (n->data.getYear() < curr->data.getYear())
        {
            Insert_Before(n, curr);
        }
        else if (n->data.getYear() == curr->data.getYear())
        {
            if (n->data.getMonth() < curr->data.getMonth() && curr == head)
            {
                Insert_At_Head(n);
            }
            else if (n->data.getMonth() < curr->data.getMonth())
            {
                Insert_Before(n, curr);
            }
            else if (n->data.getMonth() == curr->data.getMonth())
            {
                if (n->data.getDay() < curr->data.getDay() && curr == head)
                {
                    Insert_At_Head(n);
                }
                else if (n->data.getDay() < curr->data.getDay())
                {
                    Insert_Before(n, curr);
                }
                else
                {
                    return Helper_AddBook(n, curr->next);
                }
            }
            else
            {
                return Helper_AddBook(n, curr->next);
            }
        }
        else
        {
            return Helper_AddBook(n, curr->next);
        }
    }
    // search By ISBN
    void Search_by_ISBN(string ISBN)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->data.getISBN() == ISBN)
            {
                cout << "Book Found  :) " << endl;
                cout << "Book Details:- " << endl;
                curr->data.Display();
            }
            curr = curr->next;
        }
        cout << "Book with ISBN " << ISBN << " was not found :(" << endl;
    }
    // search by name
    void Search_by_Name(string name)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->data.getTitle() == name)
            {
                cout << "Book Found  :) " << endl;
                cout << "Book Details:- " << endl;
                curr->data.Display();
                return;
            }
            curr = curr->next;
        }
        cout << "Book with Title " << name << " was not found :(" << endl;
    }
    void Display()
    {
        Node *curr = head;
        int i = 1;
        while (curr != NULL)
        {
            cout << "----------------------------" << endl;
            cout << "BOOK " << i << ":-" << endl;
            curr->data.Display();
            i++;
            curr = curr->next;
        }
    }
    void Filter_by_author(string author)
    {
        Node *curr = head;
        int i = 1;
        while (curr != NULL)
        {
            if (curr->data.getAuthor() == author)
            {
                cout << "----------------------------" << endl;
                cout << "Book " << i << ":-" << endl;
                curr->data.Display();
                i++;
            }

            curr = curr->next;
        }
        if (i == 1)
        {
            cout << "No other books of this author is available in Library " << endl;
            return;
        }
    }
    void Recommend(string name)
    {
        Node *curr = head;
        bool flag = false;
        while (curr != NULL)
        {
            if (curr->data.getTitle() == name)
            {
                flag = true;
                break;
            }
            curr = curr->next;
        }
        if (flag == false)
        {
            cout << "No recommended books available in library " << endl;
            return;
        }
        else
        {
            string temp = curr->data.getGenre();

            curr = head;
            int i = 1;
            while (curr != NULL)
            {
                if (curr->data.getGenre() == temp)
                {
                    if (curr->data.getTitle() != name)
                    {
                        if (i > 3)
                        {
                            break;
                        }
                        cout << "----------------------------" << endl;
                        cout << "BOOK " << i << ":- " << endl;
                        curr->data.Display();
                        i++;
                    }
                }
                curr = curr->next;
            }
        }
    }
    void Delete(string ISBN)
    {
        Node *curr = head;
        if(curr->data.getISBN()==ISBN)
        {
            head=head->next;
            head->prev=NULL;
            delete curr;
        }
        while (curr != NULL)
        {
            if (curr->data.getISBN() == ISBN)
            {
                if (curr->prev != NULL)
                {
                    curr->prev->next = curr->next;
                }
                if (curr->next != NULL)
                {
                    curr->next->prev = curr->prev;
                }
                delete curr;
                break;
            }
            curr = curr->next;
        }
    }
};
int main()
{
    DoublyList l1;
    int choice;
    int x;
    string ISBN;
    string author;
    string title;
    string genre;
    int day;
    int month;
    int year;

    while (1)
    {
        cout << "Please select an option " << endl;
        cout << "1- Add a new Book" << endl;
        cout << "2- Search for a Book" << endl;
        cout << "3- Display Books " << endl;
        cout << "4- Filter Books by Author " << endl;
        cout << "5- Recommend related Books" << endl;
        cout << "6- Delete a Book " << endl;
        cout << "7- Exit " << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Please Enter the details of new book " << endl;
            cout << "Enter the ISBN number " << endl;
            cin >> ISBN;
            cout << "Enter the name of author of the book " << endl;
            getline(cin >> ws, author);
            cout << "Enter the Title of the book " << endl;
            getline(cin >> ws, title);
            cout << "Enter the Genre of book " << endl;
            getline(cin >> ws, genre);
            cout << "Enter the year of publication " << endl;
            cin >> year;
            cout << "Enter the month of publication " << endl;
            cin >> month;
            cout << "Enter the day of publication " << endl;
            cin >> day;
            l1.AddBook(ISBN, author, title, genre, day, month, year);
        }
        else if (choice == 2)
        {
            cout << "Please select searching method " << endl;
            cout << "1- Search by ISBN" << endl;
            cout << "2- Search by Name" << endl;
            cin >> x;
            if (x == 1)
            {
                cout << "Enter the ISBN to search" << endl;
                cin >> ISBN;
                l1.Search_by_ISBN(ISBN);
            }
            else if (x == 2)
            {
                cout << "Enter the name to search " << endl;
                getline(cin >> ws, title);
                l1.Search_by_Name(title);
            }
        }
        else if (choice == 3)
        {
            l1.Display();
        }
        else if (choice == 4)
        {
            cout << "Enter the author name to show his books " << endl;
            getline(cin >> ws, author);
            l1.Filter_by_author(author);
        }
        else if (choice == 5)
        {
            cout << "Enter the book name to recommend related books  " << endl;
            getline(cin >> ws, title);
            l1.Recommend(title);
        }
        else if (choice == 6)
        {
            cout << "Enter the books ISBN to delete " << endl;
            cin >> ISBN;
            l1.Delete(ISBN);
        }
        else if (choice == 7)
        {
            cout << "Program Exited Successfully " << endl;
            return 0;
        }
        else
        {
            cout << "Invalid Input " << endl;
        }
    }
}
