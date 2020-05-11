/**
 * @file options.cxx
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 *
 * @brief This file contains the arg/opt parser for the program.
 *
 * @date 2020-05-10
 */

#include "../include/options.hh"
#include "../include/cxxopts/cxxopts.hh"
#include <fstream>  // std::fstream
#include <iomanip>  // std::setw & std::setfill
#include <iostream> // std::cout
#include <string>   // std::string

extern bool verbose = false;
extern std::string INPUT_FILE = "";
extern std::string OUTPUT_FILE = "";

void ashwig_parse(int argc, char *argv[]) {
  try {
    // Command-line-options
    cxxopts::Options options(
        "ashellwig_m5c10_programming_assignment",
        "Ashton Hellwig's solution to Module 5 Chapter 10's "
        "programming assignment for SP2020.");

    bool verbose;

    options.allow_unrecognised_options().add_options()(
        "v,verbose", "Enable debugging",
        cxxopts::value<bool>(verbose)->default_value(0))(
        "f,input", "File used for obtaining the student's data.",
        cxxopts::value<std::string>(INPUT_FILE)
            ->default_value("/home/ahellwig/Documents/School/CSC160/Module-5/"
                            "Programming-Assignments/"
                            "ashellwig_m5c9_programming_assignment/data/"
                            "Ch9Ex2/Ch9Ex2Data.txt"))(
        "o,output", "File used for outputting the student's data.",
        cxxopts::value<std::string>(OUTPUT_FILE)
            ->default_value("/home/ahellwig/Documents/School/CSC160/Module-5/"
                            "Programming-Assignments/"
                            "ashellwig_m5c9_programming_assignment/data/"
                            "OUT_Ch9Ex2Data.txt"))("h,help", "Print help.");

    // Parse options
    auto result = options.parse(argc, argv);

    // Show help
    if (result.count("help")) {
      std::cout << options.help({""}) << std::endl;
      exit(0);
    }

    // Enable verbosity/Print some info
    if (result.count("verbose") >= 1) {
      verbose = true;
      std::cout << "-------------------------------------------------\n";
      std::cout << "Here are the files we are using:" << std::endl;
      std::cout << "input: " << result["input"].as<std::string>() << std::endl;
      std::cout << "output: " << result["output"].as<std::string>()
                << std::endl;
      std::cout << "-------------------------------------------------"
                << std::endl;
    } else {
      verbose = false;
    }

    if (result.count("input")) {
      INPUT_FILE = result["input"].as<std::string>();
    } else {
      INPUT_FILE = std::string(
          "/home/ahellwig/Documents/School/CSC160/Module-5/"
          "Programming-Assignments/"
          "ashellwig_m5c9_programming_assignment/data/bookData.txt");
    }

    if (result.count("output")) {
      OUTPUT_FILE = result["output"].as<std::string>();
    } else {
      OUTPUT_FILE = std::string(
          "/home/ahellwig/Documents/School/CSC160/Module-5/"
          "Programming-Assignments/"
          "ashellwig_m5c10_programming_assignment/out/bin/output_data.txt");
    }

  } catch (const cxxopts::OptionException &e) {
    std::cout << "Error parsing options/arguments: " << e.what() << std::endl;
    exit(1);
  }
}
