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
#include <fstream>
#include <string>

namespace book {
/**
 * @class BookType "include/book.hh"
 *
 * @brief ADT for BookType as requested by the Module 5 Chapter 10 programming
 * assignment.
 */
class BookType {
public:
  // --- Constructors ---
  BookType();
  BookType(BookType &&) = default;
  BookType(const BookType &) = default;
  BookType &operator=(BookType &&) = default;
  BookType &operator=(const BookType &) = default;
  // --- Destructors ---
  ~BookType();

  // --- Setters ---
  void setBookInfo(std::string, std::string, std::string, int, std::string *,
                   double, int, int);
  void updateQuantity(int);

  // --- Getters ---
  bool isISBN(std::string) const;
  bool isTitle(std::string) const;

  // --- Printers ---
  void printbookTitle() const;
  void printbookTitleAndISBN() const;
  void printInfo() const;

protected:
  std::string title;
  std::string ISBN;
  std::string Publisher;
  int PublishYear;
  int authorCount;
  std::string auth[4];
  double cost;
  int copies;
};
} // namespace book
#endif // !BOOK_HH_INCLUDED