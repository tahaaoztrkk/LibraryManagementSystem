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
		cout << "ID:" << id << "Title:" << title << "Author:" << author << "[" << (isBorrowed ? "Borrowed" : "Available") << "]"<<endl;
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
			else {
				cout << "Book not found.";
			}
		}
	}
	void returnBook(int bookID) {
		for (int i = 0; i < bookcount; i++) {
			if (bookCatalog[i].getID() == bookID) {
				if (!bookCatalog[i].isAvailable()) {
					bookCatalog[i].borrowBook();
					cout << "Book returned succesfully.";
				}
				else {
					cout << "Book is already borrowed.";
				}
			}
			else {
				cout << "Book not found.";
			}
		}
	}
	
};

int main() {
	Library myLibrary("books.txt");
	int selection,id;
	do
	{
		cout << "--------Library Menu--------"<<endl;
		cout << "1.List All Books"<<endl;
		cout << "2. Borrow a Book" << endl;
		cout << "3.Return a Book" << endl;
		cout << "4.Save and Exit" << endl;
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
			myLibrary.saveBooksToFile();
			cout << "Saving changes... Goodbye!";
			break;
		}
	} while (selection!=4);

}