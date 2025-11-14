#ifndef INTERACTIVE_DLL_H
#define INTERACTIVE_DLL_H

#include <iostream>
#include <string>
#include "doubLinkList.h"

class InterActiveDLL{

    const int _MAX_ = 100000;
    public:
    doubLinkList MyList;
    char optionSelected = 0;
    std::string IntroSentence = R"(Welcome to Doubly linked List Interactive usage....
     Lets Start)";
    std::string _Options = R"(What do you want to do: 
    Type the number besides the action you want to take in this doubly linked list:
    
    Add an Element (a)
    Remove an Element (b)
    Search an Element (c)
    Display the full list (d)
    Exit Program (x)
    
    Enter your number below: )";
    std::string ErrorMessageForOptions1 = R"(the option selected does not match the available options: 
    please read and select from the given options)";
    //------------------------------------------------------------------


    

    void InterActiveMain(){
        std::cout << IntroSentence << std::endl;
        while (true)
        {
            optionSelected='n';
            std::cout << _Options;
            std::cin>>optionSelected;
            switch (tolower(optionSelected))
            {
            case 'a':
                AddInteraction();
                break;
            case 'b':
                RemoveInteraction();
                break;
            case 'c':
                SearchInteraction();
                break;
            case 'd':
                MyList.Display();
                break;
            case 'x':
                return;
            default:
                _ErrorMessageforOptions();
                break;
            }
        }
    }

     
    private:

    
    bool _ErrorLimits(int numberOptions,int highLimit,int lowLimit){
        return numberOptions > highLimit || numberOptions < 1;
    }

    void _ErrorMessageforOptions(){
        std::cerr << ErrorMessageForOptions1 << std::endl;
    }

    bool CinCheckerForInt(int &input){
        if (!std::cin>>input) {
        std::cin.clear();
        std::cin.ignore(_MAX_, '\n');
        std::cout << "please enter a valid input i.e : integer without decimal or a character" << std::endl;
        return false;
        }
        return true;
    }

    int stringToInt(std::string &data){
        int result = 0;
        for (size_t i = 0; i < data.size(); i++)
        {
            if(int(data[i]) < 48 || int(data[i]) > 57){
                std::cout << "enter valid data without decimals" << std::endl;
                return -1;
            }
        }   
        return stoi(data);
    }

    void AddInteraction(){
        int data;
        std::string numeral;
        
        std::string AddOption = R"(where do you want to add
        add at front (a)
        add at back (b)
        exit (x)
        
        enter your number: )";
        loop1:
        std::cout << "what data you want to add?" << std::endl;
        std::cin >> numeral;
        data = stringToInt(numeral);
        if (data < 0){goto loop1;}
        data = stringToInt(numeral);
        while (true)
        {
            std::cout << AddOption;
            std::cin >> optionSelected;
            switch (tolower(optionSelected))
            {
            case 'a':
                MyList.addDataFront(data);
                std::cout << "data added at front." << std::endl;
                return;
            case 'b':
                MyList.addDataBack(data);
                std::cout << "data added at back." << std::endl;
                return;
            case 'x':
                return;
            default:
                _ErrorMessageforOptions();
                break;
            }
        }   
        
    }

    void SearchInteraction(){
        int data;
        std::string numeral;
        std::string AddOption = R"(do you want to?)
        Search at position (a)
        Search data (b)
        exit (x)
        
        enter your number: )";
        while (true)
        {
            std::cout << AddOption;
            std::cin >> optionSelected;
            
            switch (tolower(optionSelected))
            {
            case 'a':
                std::cout << "add position you want to Search Data of: ";
                std::cin >> numeral;
                data = stringToInt(numeral);
                if(data < 1){ break; }
                std::cout << "data on position: " << MyList.SearchPosition(data) << std::endl;
                if (MyList.isEmpty()){break;}
                std::cout << "Done!" << std::endl;
                return;
            case 'b':
                std::cout << "add data you want to Search position of: ";
                std::cin >> numeral;
                data = stringToInt(numeral);
                if(data < 0){ break; } 
                if(!(MyList.SearchData(data) == -1)) {std::cout << "position of data is: " << MyList.SearchData(data)<< std::endl;}
                if (MyList.isEmpty()){break;}
                return;
            case 'x':
                return;
            default:
                _ErrorMessageforOptions();
                break;
            }
        }   
    }
    void RemoveInteraction(){
        int data;
        std::string numeral;
        std::string AddOption = R"(do you want to?)
        Remove at position (a)
        Remove data (b)
        Clear All List (c)
        exit (x)
        
        enter your number: )";
        while (true)
        {
            std::cout << AddOption;
            std::cin >> optionSelected;
            
            switch (tolower(optionSelected))
            {
            case 'a':
                std::cout << "add position you want to remove: ";
                std::cin >> numeral;
                data = stringToInt(numeral);
                if(data < 1){ break; }
                MyList.RemovalForPos(data);
                if (MyList.isEmpty() || data > MyList.getSize()){break;}
                std::cout << "Done!" << std::endl;
                return;
            case 'b':
                std::cout << "add data you want to remove: ";
                std::cin >> numeral;
                data = stringToInt(numeral);
                if(data < 0){ break; } 
                if(MyList.SearchData(data) == -1){ break;}
                MyList.RemovalForData(data);
                if (MyList.isEmpty()){break;}
                std::cout << "data: " << data << "is removed." << std::endl;
                return;
            case 'c':
                std::cout << "clearing the list..." << std::endl;
                MyList.ClearAll();
                std::cout << "List is Cleared! currently the list is empty." << std::endl;
                return;
            case 'x':
                return;
            default:
                _ErrorMessageforOptions();
                break;
            }
        }   
        
    }
};

#endif
