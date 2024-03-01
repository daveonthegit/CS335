#include "Book.hpp"

    // write and document all methods in this file.
    Book::Book() :title_(""),author_(""),ISBN_(0),icon_(nullptr),price_(0.00),blurb_("")
    {
    }

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


    Book& Book::operator=(const Book& rhs)
    {
        Book copy(rhs);
        std::swap(*this,copy);
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
    const std::string& Book::getTitle() const
    {
        return title_;
    }

    void Book::setTitle(const std::string& title)
    {
        this->title_=title;
    }

    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    void Book::setAuthor(const std::string& author)
    {
        this->author_=author;
    }

    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    void Book::setISBN(long long int ISBN)
    {
        this->ISBN_=ISBN;
    }

    const int* Book::getIcon() const
    {
        return icon_;
    }

    void Book::setIcon(int* icon)
    {
        delete[] icon_;
        icon_ = new int[80];
        std::copy(icon, icon + 80, icon_);
    }

    float Book::getPrice() const
    {
        return price_;
    }

    void Book::setPrice(float price)
    {
        this->price_=price;
    }

    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        this->keywords_=keywords;
    }

    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    void Book::setBlurb(const std::string& blurb)
    {
        this->blurb_=blurb;
    }

    void Book::print() const
    {
        std::cout<<"Title: "<<this->title_<<std::endl;
        std::cout<<"Author: "<<this->author_<<std::endl;
        std::cout<<"ISBN: "<<this->ISBN_<<std::endl;
        std::cout<<"Icon: ";
    // Print Icon if not null
        if (icon_ != nullptr) {
            std::cout << "Icon: ";
            for (int i = 0; i < 80; i++) {
                std::cout << icon_[i] << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Icon: (null)" << std::endl;
        }
        std::cout<<std::endl;
        std::cout<<"Price: $"<<std::fixed<<std::setprecision(2)<<this->price_<<std::endl;
        std::cout<<"Keywords: ";
        for(int i = 0 ;i<keywords_.size();i++)
        {
            std::cout<<keywords_[i];
            if(i!=keywords_.size()-1){
                std::cout<<", ";
            }
        }
        std::cout<<std::endl;
        std::cout<<"Blurb: "<<this->blurb_<<std::endl;
    }