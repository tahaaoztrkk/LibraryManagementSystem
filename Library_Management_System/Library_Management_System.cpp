#include <iostream>
#include <fstream>
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
		return id + "," + title + "," + author + "," + (isBorrowed ? "1" : "0");
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
		if (file.is_open()) {

		}
	}

};

int main() {


}