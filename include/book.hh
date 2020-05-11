/**
 * @file book.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 *
 * @brief This file contains the declarations of the BookType class.
 *
 * @date 2020-05-10
 */

#ifndef BOOK_HH_INCLUDED
#define BOOK_HH_INCLUDED
namespace book {
class BookType {
public:
  BookType();
  BookType(BookType &&) = default;
  BookType(const BookType &) = default;
  BookType &operator=(BookType &&) = default;
  BookType &operator=(const BookType &) = default;
  ~BookType();

private:
};
} // namespace book
#endif // !BOOK_HH_INCLUDED