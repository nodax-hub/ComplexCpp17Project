#include "../use_cases/AddBook.hpp"
#include "../infrastructure/FileBookRepository.hpp"
#include "../entities/Book.hpp"
#include <iostream>

int main() {
    infrastructure::FileBookRepository bookRepository;
    use_cases::AddBook addBookUseCase(bookRepository);

    std::string title, author;
    std::cout << "Enter book title: ";
    std::getline(std::cin, title);
    std::cout << "Enter book author: ";
    std::getline(std::cin, author);

    entities::Book book(title, author);
    addBookUseCase.execute(book);

    std::cout << "Book added successfully!" << std::endl;

    return 0;
}
