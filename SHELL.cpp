/* TODO:
    -change directory (cd)
    -make a file (touch)
    -remove something (rm)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <filesystem>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

using namespace std;
using namespace boost::filesystem;


class Shell 
{
    public:
        void input(); //wip
        void divide();
        void multiplicate();
        void his();   //done
        void add(); //done
        void subtract(); //done
        void exit(); //done
        void clear(); //done
        void help(); //wip
        void showFiles(); //done
        void bintodec(); //done
        void dectobin(); //done

        bool getRunning();
        void getCommand();
    private:
        string command;
        bool running = true;
        vector<string> history;
};

int main()
{
    Shell shell;

    shell.clear();

    while(shell.getRunning())
    {
        cout << get_current_dir_name() << "$ ";
        shell.input();
        cout << endl;
        shell.getCommand();
    }
}

void Shell::add()
{
    int sum = 0, num;
    string line, number;

    getline(cin, line);

    stringstream s_str(line);

    while(s_str >> number)
    {
        num = stoi(number);
        sum += num;
    }
    s_str.str(string());
    cout << sum;

}
void Shell::exit()
{
    clear();
    running = false;
}
void Shell::subtract()
{
    int difference = 0, num; 
    string line, number;

    getline(cin, line);

    stringstream s_str(line);

    s_str >> number;
    difference = stoi(number);

    while(s_str >> number)
    {
        num = stoi(number);
        difference -= num;
    }

    cout << difference;
}
void Shell::clear()
{
    system("clear");
    cout << flush;
}
void Shell::his()
{
    string func;

    cin >> func;

    if(func == "-c")
    {
        history.clear();
        command.append(" -c");
    }
    else if("-s")
    {
        int size = history.size();
        for(int i = 0; i<size; i++)
        {
            cout << i+1 << ": " << history[i] << endl;
        }
        command.append(" -s");
    }
}
void Shell::help()
{
    cout << "List of all commands: \n \n";
    cout << "add 'number... number...'       = adds all the numbers behind 'add' \n";
    cout << "subtract 'number... number...'  = subtracts all the numbers behind 'subtract' \n";
    cout << "multiplicate 'number... number' = multiplicates all the number behind the keyword \n";
    cout << "divide 'number... number'       = divide all the numbers behind the keyword  \n";
    cout << "clear                           = clears console \n";
    cout << "exit                            = closes console \n";
    cout << "history '-c / -s'               = -c clears history / -s shows history \n";
    cout << "ls                              = shows all files in current directory \n";

}
void Shell::divide()
{
    float sum = 0, num;
    string line, number;

    getline(cin, line);

    stringstream s_str(line);

    s_str >> number;
    sum += stof(number);

    while(s_str >> number)
    {
        num = stof(number);
        sum /= num;
    } 
    s_str.str(string());
    cout << sum;
}
void Shell::multiplicate()
{
    float sum = 0, num;
    string line, number;

    getline(cin, line);

    stringstream s_str(line);

    s_str >> number;
    sum = stof(number);

    while(s_str >> number)
    {
        num = stof(number);
        sum *= num;
    }
    s_str.str(string());
    cout << sum;

    
}
void Shell::showFiles()
{
    string p = get_current_dir_name();

    for(auto& entry : boost::make_iterator_range(directory_iterator(p), {}))
            std::cout << entry << "\n";
    
}
void Shell::dectobin()
{
    int num;
    cin >> num;
    string sum;
    cout << endl;			
    while(num != 0)
    {
        sum.insert(0,(to_string(num % 2)));
        num /= 2;
        
    }
    cout << sum << endl;
}
void Shell::bintodec()
{
    int sum = 0;
    string num;
    cout << endl; 
    cin >> num;

    for(int i = 0, j = num.length()-1; i < num.length(); i++, j--)
    {
        if(num[i] == '1')
        {
            sum += pow(2, j);
        }
    }
    cout << sum << endl;
}

//functions just working in the backgroung
bool Shell::getRunning()
{
    if(running)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Shell::input()
{
    cin >> command;
        
    if(command == "add")
    {
        add();
    }
    else if(command == "binary")
    {
        dectobin();
    }
    else if(command == "decimal")
    {
        bintodec();
    }
    else if(command == "subtract")
    {
        subtract();
    }
    else if(command == "ls")
    {
        showFiles();
    }
    else if(command == "clear")
    {
        clear();
    }
    else if(command == "exit")
    {
        exit();
    }
    else if(command == "history")
    {
        his();  //history -c clears history.
    }
    else if(command == "divide")
    {
        divide();
    }
    else if(command == "multiplicate")
    {
        multiplicate();
    }
    else if(command == "help")
    {
        help();
    }
    else
    {
        cout << "command '" << command << "' not found";
    }
}
void Shell::getCommand()
{
    history.push_back(command);
}
