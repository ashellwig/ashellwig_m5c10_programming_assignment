// main() provided in 00_CatchMain.cxx

#include "../include/book.hh" // TBD
#include "../include/catch2/catch.hh"
#include "../include/options.hh" // Argument parsing
#include <fstream>               // std::fstream
#include <iostream>              // std::cout
#include <string>                // std::string

class DBConnection {
public:
  static DBConnection createConnection(std::string const & /*dbName*/) {
    return DBConnection();
  }

  bool executeSQL(std::string const & /*query*/, int const /*id*/,
                  std::string const &arg) {
    if (arg.length() == 0) {
      throw std::logic_error("empty SQL query argument");
    }
    return true; // ok
  }
};

class UniqueTestsFixture {
protected:
  UniqueTestsFixture() : conn(DBConnection::createConnection("myDB")) {}

  int getID() { return ++uniqueID; }

protected:
  DBConnection conn;

private:
  static int uniqueID;
};

int UniqueTestsFixture::uniqueID = 0;

TEST_CASE_METHOD(UniqueTestsFixture, "Create Employee/No Name", "[create]") {
  REQUIRE_THROWS(conn.executeSQL(
      "INSERT INTO employee (id, name) VALUES (?, ?)", getID(), ""));
}

TEST_CASE_METHOD(UniqueTestsFixture, "Create Employee/Normal", "[create]") {
  REQUIRE(conn.executeSQL("INSERT INTO employee (id, name) VALUES (?, ?)",
                          getID(), "Joe Bloggs"));
}

// Compile & run:
// - g++ -std=c++2a -Wall -Iinclude -isystem include/catch2 -isystem
// include/cxxopts -o out/bin/test.bin test/01_TestStudentClass.cxx
// 000-CatchMain.o && 110-Fix-ClassFixture
// --success
// - cl -EHsc -I%CATCH_SINGLE_INCLUDE% -Iinclude 110-Fix-ClassFixture.cpp
// 000-CatchMain.obj && 110-Fix-ClassFixture --success
