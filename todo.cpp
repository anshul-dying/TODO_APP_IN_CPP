#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <fstream>

#include "todo.h"

int Todo::id = 0;

void save_task_to_file(Todo *t)
{
    std::ofstream file("tasks.txt", std::ios::app);
    file << t->get_id() << "|"
         << t->get_task() << "|"
         << std::put_time(t->get_start_time(), "%d %m %Y %H %M %S") << "|"
         << std::put_time(t->get_end_time(), "%d %m %Y %H %M %S") << "\n";

    file.close();
}

void load_tasks(std::vector<Todo *> &tasks)
{
    std::ifstream file("tasks.txt");
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> parts;
        while (std::getline(iss, token, '|'))
            parts.push_back(token);

        if (parts.size() != 4)
            continue;

        Todo *t = new Todo();
        t->set_task(parts[1]);

        int d, m, y, h, mi, s;
        std::istringstream(parts[2]) >> d >> m >> y >> h >> mi >> s;
        t->set_start_time(d, m, y, h, mi, s);

        std::istringstream(parts[3]) >> d >> m >> y >> h >> mi >> s;
        t->set_end_time(d, m, y, h, mi, s);

        tasks.push_back(t);
    }
    file.close();
}

void update_file(std::vector<Todo *> &tasks)
{
    std::ofstream file("tasks.txt", std::ios::trunc);
    for (const auto &t : tasks)
    {
        file << t->get_id() << "|"
             << t->get_task() << "|"
             << std::put_time(t->get_start_time(), "%d %m %Y %H %M %S") << "|"
             << std::put_time(t->get_end_time(), "%d %m %Y %H %M %S") << "\n";
    }
    file.close();
}

void add_task(std::vector<Todo *> &tasks)
{
    Todo *t = new Todo();
    std::string task;
    int day, month, year;
    int h, m, s;

    std::cin.ignore();
    std::cout << "Enter task title: ";
    std::getline(std::cin, task);

    std::cout << "Enter start date and time (dd mm yyyy hh mm ss): ";
    std::cin >> day >> month >> year >> h >> m >> s;
    t->set_start_time(day, month, year, h, m, s);

    std::cout << "Enter end date and time (dd mm yyyy hh mm ss): ";
    std::cin >> day >> month >> year >> h >> m >> s;
    t->set_end_time(day, month, year, h, m, s);

    t->set_task(task);

    tasks.push_back(t);

    save_task_to_file(t);

    std::cout << "Task added successfully";
}

void delete_task(std::vector<Todo *> &tasks)
{
    if (tasks.empty())
    {
        std::cout << "No tasks to delete\n";
        return;
    }

    int t;
    std::cout << "Enter task ID: ";
    std::cin >> t;
    if (t >= tasks.size())
    {
        std::cout << "Enter valid task id\n";
        return;
    }
    for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i]->get_id() == t)
        {
            tasks.erase(tasks.begin() + i);
            update_file(tasks);
        }
    }

    std::cout << "Task Deleted successfully\n";
}

void display_task(std::vector<Todo *> &tasks)
{
    if (tasks.empty())
    {
        std::cout << "No tasks to display.\n";
        return;
    }

    std::cout << "\n+----+----------------------+---------------------+---------------------+\n";
    std::cout << "| ID | Task Title           | Start Time          | End Time           |\n";
    std::cout << "+----+----------------------+---------------------+---------------------+\n";

    for (const auto &task : tasks)
    {
        std::cout << "| "
                  << std::setw(2) << task->get_id() << " | "
                  << std::setw(20) << std::left << task->get_task().substr(0, 20) << " | "
                  << std::put_time(task->get_start_time(), "%d-%m-%Y %H:%M:%S") << " | "
                  << std::put_time(task->get_end_time(), "%d-%m-%Y %H:%M:%S") << " |\n";
    }

    std::cout << "+----+----------------------+---------------------+---------------------+\n";
}

int main()
{
    std::vector<Todo *> tasks;
    load_tasks(tasks);
    int option;
    do
    {
        std::cout << "\n"
                  << "+------------------------------+\n"
                  << "|          TODO MENU           |\n"
                  << "+------------------------------+\n"
                  << "| [1] Add Task                 |\n"
                  << "| [2] Delete Task              |\n"
                  << "| [3] Display Tasks            |\n"
                  << "| [0] Exit                     |\n"
                  << "+------------------------------+\n"
                  << "Enter your option (0-3): ";

        std::cin >> option;

        if (option < 0 || option > 3)
        {
            std::cout << "\nInvalid Option! Please choose 0-3.\n";
        }
        else
        {
            switch (option)
            {
            case 0:
                std::cout << "\nExiting... Goodbye!\n";
                break;
            case 1:
                add_task(tasks);
                break;
            case 2:
                delete_task(tasks);
                break;
            case 3:
                display_task(tasks);
                break;
            }
        }

    } while (option != 0);

    return 0;
}
