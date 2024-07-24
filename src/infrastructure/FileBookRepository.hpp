#ifndef FILE_BOOK_REPOSITORY_HPP
#define FILE_BOOK_REPOSITORY_HPP

#include "../interfaces/IBookRepository.hpp"
#include <vector>
#include <fstream>

namespace infrastructure {

    class FileBookRepository : public interfaces::IBookRepository {
    public:
        void addBook(const entities::Book& book) override {
            // Пример реализации записи в файл
            std::ofstream file("books.txt", std::ios::app);
            if (file.is_open()) {
                file << book.getTitle() << "," << book.getAuthor() << "\n";
                file.close();
            }
        }

        std::vector<entities::Book> listBooks() const override {
            // Пример реализации чтения из файла
            std::vector<entities::Book> books;
            std::ifstream file("books.txt");
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    auto commaPos = line.find(',');
                    if (commaPos != std::string::npos) {
                        std::string title = line.substr(0, commaPos);
                        std::string author = line.substr(commaPos + 1);
                        books.emplace_back(title, author);
                    }
                }
                file.close();
            }
            return books;
        }
    };

} // namespace infrastructure

#endif // FILE_BOOK_REPOSITORY_HPP
