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
#include <filesystem>

namespace po = boost::program_options;

struct Receipt{
    std::string clientName;
    int32_t numberOfApples;
    int32_t numberOfOranges;
    int32_t numberOfBannanas;
    bool isClientSatisfied;
    std::string configPath;

    void printReceipt(){
        std::cout << "Client: " << clientName << "\n"
                  << "Apples: " << numberOfApples << "\n"
                  << "Oranges: " << numberOfOranges << "\n"
                  << "Bannanas: " << numberOfBannanas << "\n"
                  << "Service: " << (isClientSatisfied ? "Good" : "Bad") << "\n"
                  << "Config: " << configPath << "\n";
    }
};

po::options_description createOptionsDescription(Receipt& receipt){
    //description of all options
    po::options_description desc("All options");
    
    //adding options to the description
    desc.add_options()
        ("apples,a,apple", po::value<std::int32_t>(&receipt.numberOfApples)->default_value(0), "how many apples do you have")
        ("oranges,o,orange", po::value<std::int32_t>(&receipt.numberOfOranges)->default_value(0), "how many oranges do you have")
        ("bannanas,b,bannana", po::value<std::int32_t>(&receipt.numberOfBannanas)->default_value(0), "How many apples do you have")
        ("user-name,user,name,username", po::value<std::string>(&receipt.clientName)->required()->default_value("Unknown"), "Your name")
        ("service,s", po::value<bool>(&receipt.isClientSatisfied)->default_value(true), "Are you satisfied with the service?")
        ("config,c", po::value<std::string>(&receipt.configPath), "Path to the config file")
        ("help,h","help message")
    ;

    return desc;
}

void handleCommandLineArguments(int argc, char** argv, po::variables_map& vm, po::options_description& desc){
    try{
        // parsing the command line
        po::store(po::parse_command_line(argc, argv, desc), vm);
        // notifying the map that the parsing is done
        po::notify(vm);
    } catch(po::error& ex){
        std::cout << "Error: " << ex.what() << '\n';
        exit(EXIT_FAILURE);
    }
}

void handleConfigFile(std::string& configFilePath, po::options_description& desc, po::variables_map& vm){
    try{
        if(!std::filesystem::exists(configFilePath)){
            std::cerr << "Config file does not exist\n";
            throw po::error("Config file does not exist\n");
        }
        //* parsing the config file
        po::store(po::parse_config_file<char>(configFilePath.c_str(), desc), vm);
        
        //*check if all required valualbes are provided
        po::notify(vm);

    } catch(const po::error& e){
        std::cerr << "Error: " << e.what() << "\n";
        exit(EXIT_FAILURE);
    }
}
int main(int argc, char* argv[]){
    Receipt firstClient;
    // valuable map to store the values of the options
    po::options_description desc = createOptionsDescription(firstClient);
    
    // valuable map to store the values of the options
    po::variables_map vm;
    handleCommandLineArguments(argc, argv, vm, desc);

    if(vm.empty()){
        std::cout << "No options provided\n";
        return EXIT_FAILURE;
    }

    if(vm.count("help")){
        std::cout << desc << "\n";
        return EXIT_FAILURE;
    }
    
    if(vm.count("config")){
        handleConfigFile(firstClient.configPath, desc, vm);
    }
    
    firstClient.printReceipt();

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