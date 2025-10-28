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
		string line;

		if (file.is_open()) {
			
			stringstream ss(line);
			
			while (getline(file,line)) {
				
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
	

};

int main() {


}