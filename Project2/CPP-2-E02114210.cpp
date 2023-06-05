#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Book {
private:
	string title;
	string author;
	int page;
	float price;
	int count;
public:
	Book(){}
	Book(string _title, string _author, int _page, float _price, int _count) 
		:title(_title),author(_author),page(_page),price(_price),count(_count){}
	void show() {
		cout << "Title: " << title << ", Author: " << author << ", Pages: " << page << ", Price: RMB " << price << ", Count: " << count << endl;
	}
	string getTitle() {
		return title;
	}
	string getAuthor() {
		return author;
	}
	int getPage() {
		return page;
	}
	float getPrice() {
		return price;
	}
	int getCount() {
		return count;
	}
	void modifyPrice(float price) {
		this->price = price;
	}
	void restoreBook(int num) {
		this->count += num;
	}
	int soldBook(int num) {
		if (num > this->count) {
			return -1;
		}
		this->count -= num;
		return num;
	}
};

class BookShop {
private:
	vector<Book> books;
public:
	void addBook(Book book) {
		books.push_back(book);
	}
	void showBooks() {
		cout << "All Books:" << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
		float priceSum = 0;
		for (int i = 0; i < books.size(); i++) {
			showOneBook(i);
			priceSum += books[i].getPrice() * books[i].getCount();
		}
		int countSum = getCount();
		cout << "Total Count = " << countSum << ", Total Price = " << priceSum << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
	}
	void showOneBook(int num) {
		cout << num << " : ";
		books[num].show();
	}
	int getCount() {
		vector<Book>::iterator it;
		int countSum = 0;
		for (it = books.begin(); it != books.end(); it++)
		{
			countSum += it->getCount();
		}
		return countSum;
	}
	float soldBooks(int num,int soldNum) {
		float soldPrice = soldNum * books[num].getPrice();
		books[num].soldBook(soldNum);
		cout << "Sold " << soldNum << " \"" << books[num].getTitle() << "\", Sum = " << soldPrice << endl;
		return soldPrice;
	}
	void restoreBooks(int num, int countNum) {
		books[num].restoreBook(countNum);
		cout << "Restock " << countNum << " \"" << books[num].getTitle() << "\"" << endl;
	}
};

int main() {
	BookShop bookShop;
	string title1 = "C++ Programming";
	string author1 = "Stroustrup";
	int page1 = 760;
	float price1 = 79.9f;
	int count1 = 10;
 	string title2 = "Java Programming";
	string author2 = "James Gosling";
	int page2 = 420;
	float price2 = 59.9f;
	int count2 = 31;
	string title3 = "Compiler";
	string author3 = "Steven";
	int page3 = 340;
	float price3 = 49.9f;
	int count3 = 37;
	string title4 = "Physics";
	string author4 = "Chen-Ning Yang";
	int page4 = 300;
	float price4 = 37.9f;
	int count4 = 20;
	Book book1(title1, author1, page1, price1, count1);
	Book book2(title2, author2, page2, price2, count2);
	Book book3(title3, author3, page3, price3, count3);
	Book book4(title4, author4, page4, price4, count4);
	bookShop.addBook(book1);
	bookShop.addBook(book2);
	bookShop.addBook(book3);
	bookShop.addBook(book4);
	cout << "½­ÜçÄÝ E02114210" << endl;
	bookShop.showBooks();
	bookShop.soldBooks(0, 10);
	bookShop.soldBooks(1, 13);
	bookShop.soldBooks(3, 17);
	bookShop.restoreBooks(0, 10);
	bookShop.restoreBooks(1, 5);
	bookShop.soldBooks(2, 5);
	bookShop.showBooks();
	return 0;
}