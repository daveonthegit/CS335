#include "Book.hpp"

// Default Constructor
Book::Book() : title_(""), author_(""), ISBN_(0), icon_(nullptr), price_(0.00), blurb_("")
{
}

// Destructor
Book::~Book()
{
    delete[] icon_;
}

// Copy Constructor
Book::Book(const Book& rhs)
    : title_(rhs.title_), author_(rhs.author_), ISBN_(rhs.ISBN_),
      icon_(new int[80]), price_(rhs.price_), keywords_(rhs.keywords_),
      blurb_(rhs.blurb_)
{
    // Copy the contents of the icon array
    std::copy(rhs.icon_, rhs.icon_ + 80, icon_);
}

// Copy Assignment Operator
Book& Book::operator=(const Book& rhs)
{
    // Create a temporary copy
    Book copy(rhs);
    // Swap with the temporary copy
    std::swap(*this, copy);
    return *this;
}

// Move Constructor
Book::Book(Book&& rhs)
    : title_(std::move(rhs.title_)), author_(std::move(rhs.author_)),
      ISBN_(std::move(rhs.ISBN_)), icon_(rhs.icon_), price_(std::move(rhs.price_)),
      keywords_(std::move(rhs.keywords_)), blurb_(std::move(rhs.blurb_))
{
    // Reset the source object
    rhs.icon_ = nullptr;
}

// Move Assignment Operator
Book& Book::operator=(Book&& rhs)
{
    // Check for self-assignment
    if (this != &rhs) {
        // Swap with the source object
        std::swap(title_, rhs.title_);
        std::swap(author_, rhs.author_);
        std::swap(ISBN_, rhs.ISBN_);
        std::swap(icon_, rhs.icon_);
        std::swap(price_, rhs.price_);
        std::swap(keywords_, rhs.keywords_);
        std::swap(blurb_, rhs.blurb_);
    }
    return *this;
}

// Getter for Title
const std::string& Book::getTitle() const
{
    return title_;
}

// Setter for Title
void Book::setTitle(const std::string& title)
{
    this->title_ = title;
}

// Getter for Author
const std::string& Book::getAuthor() const
{
    return author_;
}

// Setter for Author
void Book::setAuthor(const std::string& author)
{
    this->author_ = author;
}

// Getter for ISBN
long long int Book::getISBN() const
{
    return ISBN_;
}

// Setter for ISBN
void Book::setISBN(long long int ISBN)
{
    this->ISBN_ = ISBN;
}

// Getter for Icon
const int* Book::getIcon() const
{
    return icon_;
}

// Setter for Icon
void Book::setIcon(int* icon)
{
    // Delete existing icon array
    delete[] icon_;
    // Allocate new memory and copy icon array
    icon_ = new int[80];
    std::copy(icon, icon + 80, icon_);
}

// Getter for Price
float Book::getPrice() const
{
    return price_;
}

// Setter for Price
void Book::setPrice(float price)
{
    this->price_ = price;
}

// Getter for Keywords
const std::vector<std::string>& Book::getKeywords() const
{
    return keywords_;
}

// Setter for Keywords
void Book::setKeywords(const std::vector<std::string>& keywords)
{
    this->keywords_ = keywords;
}

// Getter for Blurb
const std::string& Book::getBlurb() const
{
    return blurb_;
}

// Setter for Blurb
void Book::setBlurb(const std::string& blurb)
{
    this->blurb_ = blurb;
}

// Print Book Details
void Book::print() const
{
    std::cout << "Title: " << this->title_ << std::endl;
    std::cout << "Author: " << this->author_ << std::endl;
    std::cout << "ISBN: " << this->ISBN_ << std::endl;
    // Print Icon if not null
    if (icon_ != nullptr) {
        std::cout << "Icon: ";
        for (int i = 0; i < 80; i++) {
            std::cout << icon_[i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Price: $" << std::fixed << std::setprecision(2) << this->price_ << std::endl;
    std::cout << "Keywords: ";
    for (int i = 0; i < keywords_.size(); i++) {
        std::cout << keywords_[i];
        if (i != keywords_.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "Blurb: " << this->blurb_ << std::endl;
}
