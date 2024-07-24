#ifndef ADD_BOOK_HPP
#define ADD_BOOK_HPP

#include "../interfaces/IBookRepository.hpp"
#include "../entities/Book.hpp"

namespace use_cases {

    class AddBook {
    public:
        AddBook(interfaces::IBookRepository& repository)
            : repository(repository) {}

        void execute(const entities::Book& book) {
            repository.addBook(book);
        }

    private:
        interfaces::IBookRepository& repository;
    };

} // namespace use_cases

#endif // ADD_BOOK_HPP
