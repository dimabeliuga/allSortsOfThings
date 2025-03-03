/**
 * @file BoostCommandParser.cpp
 * @author DB
 * @brief programm to learn how to use <boost/program_options.hpp>
 * https://www.boost.org/doc/libs/1_79_0/doc/html/program_options.html#id-1.3.30.3 - documentation
 * @copyright Copyright (c) 2025
 */

#include <iostream>
#include <boost/program_options.hpp>
#include <iterator>


namespace po = boost::program_options;

int main(int argc, char** argv){
    po::options_description desc("All options");
    desc.add_options()
        ("apples", po::value<int>(), "how many apples do you have")
        ("oranges", po::value<int>(), "how many oranges do you have")
        ("help", "help message")
    ;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    if(vm.count("help")){
        std::cout << desc << "\n";
        return EXIT_FAILURE;
    }
    std::cout << "Fruit count: " << vm["apples"].as<int>() + vm["oranges"].as<int>() << "\n";

    return 0;
}