/**
 * @file book.cxx
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 *
 * @brief This file contains the definitions of the BookType class.
 *
 * @date 2020-05-10
 */

#include "../include/book.hh"
#include <fstream>
#include <iostream>
#include <string>

book::BookType::BookType() {}

// --- Destructors ---
book::BookType::~BookType() {}

// --- Setters ---
void book::BookType::setBookInfo(std::string, std::string, std::string, int,
                                 std::string *, double, int, int) {}
void book::BookType::updateQuantity(int) {}

// --- Getters ---
bool book::BookType::isISBN(std::string) const { return true; }
bool book::BookType::isTitle(std::string) const { return true; }

// --- Printers ---
void book::BookType::printbookTitle() const {}
void book::BookType::printbookTitleAndISBN() const {}
void book::BookType::printInfo() const {}
