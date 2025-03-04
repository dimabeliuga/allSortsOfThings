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

struct Receipt{
    std::string clientName;
    int32_t numberOfApples;
    int32_t numberOfOranges;
    int32_t numberOfBannanas;

    void printReceipt(){
        std::cout << "Client: " << clientName << "\n";
        std::cout << "Apples: " << numberOfApples << "\n";
        std::cout << "Oranges: " << numberOfOranges << "\n";
        std::cout << "Bannanas: " << numberOfBannanas << "\n";
    }
};

int main(int argc, char* argv[]){
    Receipt firstClient;

    // description of all options
    po::options_description desc("All options");
    
    //*adding options to the description
    desc.add_options()
        ("apples", po::value<std::int32_t>(&firstClient.numberOfApples), "how many apples do you have")
        ("oranges", po::value<std::int32_t>(&firstClient.numberOfOranges), "how many oranges do you have")
        ("bannanas", po::value<std::int32_t>(&firstClient.numberOfBannanas), "How many apples do you have")
        ("user name", po::value<std::string>(&firstClient.clientName)->required(), "Your name")
        ("help", "help message")
    ;

    // valuable map to store the values of the options
    po::variables_map vm;
    // parsing the command line
    po::store(po::parse_command_line(argc, argv, desc), vm);
    // notifying the map that the parsing is done
    po::notify(vm);
    
    if(vm.empty()){
        std::cout << "No options provided\n";
        return EXIT_FAILURE;
    }

    if(vm.count("help")){
        std::cout << desc << "\n";
        return EXIT_FAILURE;
    }
   
    //* you can do like that only if all the options have the samy type
/*     for(auto& it : vm){
        std::cout << it.first << " ";
        if(it.second.empty()){
            std::cout << "empty\n";
        } else {
            std::cout << it.second.as<std::string>() << "\n";
        }
    }
 */
    return 0;
}