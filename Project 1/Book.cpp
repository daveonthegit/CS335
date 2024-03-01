#include "Book.hpp"

    // write and document all methods in this file.
    Book::Book() :title_(""),author_(""),ISBN_(0),icon_(new int[80]),price_(0.00),blurb_("")
    {
    }

    Book::~Book()
    {
        delete icon_;
    }

    Book::Book(const Book& rhs)
    {
        title_=rhs.title_;
        author_=rhs.author_;
        ISBN_=rhs.ISBN_;
        icon_=new int{*rhs.icon_};
        price_=rhs.price_;
        keywords_=rhs.keywords_;
        blurb_=rhs.blurb_;
    }

    Book& Book::operator=(const Book& rhs)
    {
        Book copy =rhs;
        std::swap(*this,copy);
        return *this;
    }

    Book::Book(Book&& rhs):title_{rhs.title_},author_{rhs.author_},ISBN_{rhs.ISBN_},
    icon_{rhs.icon_},price_{rhs.price_},keywords_{std::move(rhs.keywords_)},blurb_{rhs.blurb_}
    {
        rhs.icon_=nullptr;
    }

    Book& Book::operator=(Book&& rhs)
    {
        std::swap(title_,rhs.title_);
        std::swap(author_,rhs.author_);
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
        this->icon_=icon;
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
        for(int i =0;i<80;i++)
        {
            std::cout<<icon_[i]<<" ";
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