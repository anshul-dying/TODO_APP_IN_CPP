#include <ctime>
#include <iomanip>

class Todo
{
    static int id;
    int my_id;
    std::string task;
    std::tm start;
    std::tm end;

public:
    // Constructor
    Todo()
    {
        my_id = id++;
        time_t now = time(0);
        start = *std::localtime(&now);
        end = *std::localtime(&now);
    }

public:
    void set_task(std::string task)
    {
        this->task = task;
    }

    std::string get_task()
    {
        return this->task;
    }

    int get_id()
    {
        return this->my_id;
    }

public:
    void set_start_time(int day, int month, int year, int h, int m, int s)
    {
        this->start.tm_mday = day;
        this->start.tm_mon = month - 1;
        this->start.tm_year = year - 1900;

        this->start.tm_hour = h;
        this->start.tm_min = m;
        this->start.tm_sec = s;
    }

    tm *get_start_time()
    {
        return &this->start;
    }

    void set_end_time(int day, int month, int year, int h, int m, int s)
    {
        this->end.tm_mday = day;
        this->end.tm_mon = month - 1;
        this->end.tm_year = year - 1900;

        this->end.tm_hour = h;
        this->end.tm_min = m;
        this->end.tm_sec = s;
    }

    tm *get_end_time()
    {
        return &this->end;
    }

public:
    ~Todo() = default;
};