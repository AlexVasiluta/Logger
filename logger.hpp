#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

#define COLOR_INFO  "\033[1;37m"	
#define COLOR_WARN  "\033[1;33m"
#define COLOR_ERR   "\033[1;31m"
#define COLOR_RESET "\033[0m"

class Logger
{
private:
    clock_t timelog = clock();
    std::ostream *stream();
    bool writeToFile = false;
    std::ofstream fout;
public:
    Logger() { std::cout << std::fixed << std::setprecision(3); }
    
    ~Logger() { fout.close(); }
    
    void setFile(const char *path)
    {
        fout.open(path);
        writeToFile = true;
        fout << std::fixed << std::setprecision(3);
    }
    
    void logInfo(const char *msg)
    {
        std::cout << COLOR_INFO 
                  << float(clock() - timelog) / CLOCKS_PER_SEC
                  << " " << msg << COLOR_RESET << "\n";
        if(writeToFile)
            fout << float(clock() - timelog) / CLOCKS_PER_SEC << " " << msg << "\n";
    }
    
    void logWarning(const char *msg)
    {
        std::cout << COLOR_WARN 
                  << float(clock() - timelog) / CLOCKS_PER_SEC
                  << " " << msg << COLOR_RESET << "\n";
        if(writeToFile)
            fout << float(clock() - timelog) / CLOCKS_PER_SEC << " " << msg << "\n";
    }
    void logError(const char *msg)
    {
        std::cout << COLOR_ERR 
                  << float(clock() - timelog) / CLOCKS_PER_SEC
                  << " " << msg << COLOR_RESET << "\n";
        if(writeToFile)
            fout << float(clock() - timelog) / CLOCKS_PER_SEC << " " << msg << "\n";
    }
};