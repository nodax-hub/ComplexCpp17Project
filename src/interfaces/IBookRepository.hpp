#ifndef IBOOK_REPOSITORY_HPP
#define IBOOK_REPOSITORY_HPP

#include <vector>

#include "../entities/Book.hpp"

namespace interfaces {

    class IBookRepository {
    public:
        virtual ~IBookRepository() = default;
        virtual void addBook(const entities::Book& book) = 0;
        virtual std::vector<entities::Book> listBooks() const = 0;
    };

} // namespace interfaces

#endif // IBOOK_REPOSITORY_HPP
