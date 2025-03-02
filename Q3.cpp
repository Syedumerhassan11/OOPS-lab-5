#include <iostream>
#include <vector>
#include <memory>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return isbn; }
};

class Catalog {
private:
    std::vector<std::shared_ptr<Book>> books;

public:
    void addBook(std::shared_ptr<Book> book) {
        books.push_back(book);
    }
    std::shared_ptr<Book> findBook(const std::string& isbn) {
        for (const auto& book : books) {
            if (book->getISBN() == isbn) {
                return book;
            }
        }
        return nullptr;
    }
};

class Library {
private:
    std::string name;
    std::string address;
    Catalog catalog;
    std::vector<std::shared_ptr<Book>> books;

public:
    Library(std::string n, std::string addr) : name(n), address(addr) {}
    void addBook(std::shared_ptr<Book> book) {
        books.push_back(book);
        catalog.addBook(book);
    }
    std::shared_ptr<Book> findBookInCatalog(const std::string& isbn) {
        return catalog.findBook(isbn);
    }
    void listBooks() {
        for (const auto& book : books) {
            std::cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << ", ISBN: " << book->getISBN() << std::endl;
        }
    }
};

int main() {
    Library myLibrary("Central Library", "123 Main St");
    
    auto book1 = std::make_shared<Book>("C++ Primer", "Stanley B. Lippman", "9780321714114");
    auto book2 = std::make_shared<Book>("The Art of Computer Programming", "Donald Knuth", "9780201896831");
    auto book3 = std::make_shared<Book>("Clean Code", "Robert C. Martin", "9780132350884");
    
    myLibrary.addBook(book1);
    myLibrary.addBook(book2);
    myLibrary.addBook(book3);
    
    std::cout << "Library Books:\n";
    myLibrary.listBooks();
    
    std::string searchISBN = "9780132350884";
    auto foundBook = myLibrary.findBookInCatalog(searchISBN);
    if (foundBook) {
        std::cout << "\nBook found: " << foundBook->getTitle() << " by " << foundBook->getAuthor() << std::endl;
    } else {
        std::cout << "\nBook not found in catalog." << std::endl;
    }
    
    return 0;
}

