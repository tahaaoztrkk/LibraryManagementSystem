#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Book {
private:
	int id;
	string title;
	string author;
	bool isBorrowed;
	
public:
	void setBookDetails(int id,string title,string author,bool isBorrowed) {
		this->id = id;
		this->title = title;
		this->author = author;
		this->isBorrowed = isBorrowed;

	}
	void display() {
		cout << "ID: " << id << " | Title: " << title << "| Author: " << author << "[" << (isBorrowed ? "Borrowed" : "Available") << "]"<<endl;
	}
	void borrowBook() {
		isBorrowed = true;
	}
	void returnBook() {
		isBorrowed = false;
	}
	bool isAvailable() {
		return !isBorrowed;
	}
	int getID() {
		return id;
	}
	string getSaveFormat() {
		return to_string(id) + "," + title + "," + author + "," + (isBorrowed ? "1" : "0");
	}
};

class Library {
private:
	Book bookCatalog[50];
	int bookcount;
	string bookFileName;
public:
	Library(string filename) {
		bookFileName = filename;
		bookcount = 0;
		loadBooksFromFile();
	}
	void loadBooksFromFile() {
		ifstream file(bookFileName);
		string line;

		if (file.is_open()) {
			
			
			
			while (getline(file,line)) {
				stringstream ss(line);
				string idStr, title, author, statusStr;
				char del = ',';

				getline(ss, idStr, del);
				getline(ss, title, del);
				getline(ss, author, del);
				getline(ss, statusStr, del);

				int id = stoi(idStr);
				bool status = (statusStr == "1");

				bookCatalog[bookcount].setBookDetails(id, title, author, status);
				bookcount++;

			}
		}
		else
		{
			cout << "File can not open.";
		}
		file.close();
		cout << "Total book is: " << bookcount << endl;
	}
	void saveBooksToFile() {
		ofstream file(bookFileName);

		while (file.is_open())
		{
			for (int i = 0; i < bookcount; i++) {
				file << bookCatalog[i].getSaveFormat()<<endl;
			}
			file.close();
			cout << "Book saved succesfully.";
		}
	}
	void listAllBooks() {
		for (int i = 0; i < bookcount; i++) {
			bookCatalog[i].display();
		}
	}
	void borrowBook(int bookID) {
		for (int i = 0; i < bookcount; i++) {
			if (bookCatalog[i].getID() == bookID) {
				if (bookCatalog[i].isAvailable()) {
					bookCatalog[i].borrowBook();
					cout << "Book borrowed succesfully."<<endl;
				}
				else {
					cout << "Book is already borrowed.";
				}
				
			}
			
		}
		
	}
	void returnBook(int bookID) {
		for (int i = 0; i < bookcount; i++) {
			if (bookCatalog[i].getID() == bookID) {
				if (!bookCatalog[i].isAvailable()) {
					bookCatalog[i].returnBook();
					cout << "Book returned succesfully.";
				}
				else {
					cout << "Book is already borrowed.";
				}
			}
			
		}
		
	}

	void checkStudentBooks(int stdid) {
		bool found = false;

		cout << "Borrowed books: ";

		for (int i = 0; i < bookcount; i++) {
			if (!bookCatalog[i].isAvailable() && bookCatalog[i].getID() == stdid) {
				bookCatalog[i].display();
				found= true;
			}
		}
		if (!found) {
			cout << "You have not any books. "<<endl;
		}
	}

	void addBook() {
		int newID;
		string newTitle, newAuthor;


		for (int i = 0; i < bookcount; i++) {
			cout << "Enter book ID: ";
			cin >> newID;
			if (bookCatalog[i].getID() == newID) {
				cout << "ID already exist. Enter another ID!"<<endl;
			}
		}
		cin.ignore();

		cout << "Enter book title: ";
		getline(cin, newTitle);

		cout << "Enter book author: ";
		getline(cin, newAuthor);

		bookCatalog[bookcount].setBookDetails(newID, newTitle, newAuthor, false);
		bookcount++;
		cout << "Book added successfully!" << endl;

		saveBooksToFile();
	}
	
};

int main() {
	int selection, id, stdid;
	cout << "Please enter your student id: ";
	cin >> stdid;

	Library myLibrary("books.txt");
	myLibrary.checkStudentBooks(stdid);
	do
	{   
		
		cout << "--------Library Menu--------"<<endl;
		cout << "1.List All Books"<<endl;
		cout << "2.Borrow a Book" << endl;
		cout << "3.Return a Book" << endl;
		cout << "4.Add New Book" << endl;
		cout << "5.Save and Exit" << endl;
		
		cout << "Enter your selection between 1-5: ";
		cin >> selection;

		switch (selection)
		{
		case 1:
			myLibrary.listAllBooks();
			break;

		case 2:
			cout << "Please enter book ID: ";
			cin >> id;
			myLibrary.borrowBook(id);
			break;

		case 3:
			cout << "Please enter book ID: ";
			cin >> id;
			myLibrary.returnBook(id);
			break;

		case 4:
			myLibrary.addBook();
			break;

		case 5:
			myLibrary.saveBooksToFile();
			cout << "Saving changes... Goodbye!";
			break;
		}
	} while (selection!=5);
	return 0;
}