#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

namespace entities {

    class Book {
    public:
        Book(const std::string& title, const std::string& author)
            : title(title), author(author) {}

        std::string getTitle() const { return title; }
        std::string getAuthor() const { return author; }

    private:
        std::string title;
        std::string author;
    };

} // namespace entities

#endif // BOOK_HPP
