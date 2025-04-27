#include <iostream>
#include <vector>

//Используя std::vector<int>, реализуйте консольное приложение, которое позволяет
//управлять оценками ученика со следующим интерфейсом :
//  -показать все оценки;
//  -добавить оценку;
//  -изменить оценку;
//  -удалить оценку;
//  -получить средний балл.
//Постарайтесь сделать как можно лучше.Так, например, можно контролировать ввод
//оценки и проверять, что оценка находится в диапазоне от 1 до 5.
//Ответ представить в виде файла с расширением.cpp

void printMenu()
{
    std::cout << "\nГлавное меню дневника\n\n" <<
        "1. Показать оценки\n" <<
        "2. Добавить оценку\n" <<
        "3. Удалить оценку\n" <<
        "4. Изменить оценку\n" <<
        "5. Средний балл\n" <<
        "0. Закрыть программу" << std::endl;
}

void printAllMarks(std::vector<int> &marks)
{
    std::cout << "\nНомер оценки";

    for (int i = 1; i < marks.size() + 1; i++)
    {
        std::cout << " " << i;
    }

    std::cout << "\n      Оценка";

    for (int m : marks)
    {
        std::cout << " " << m;
    }

    std::cout << "\n";
}

bool markCheck(int mark)
{
    bool check = true;

    if (mark < 1 || mark > 5)
    {
        std::cout << "\nНеправильный ввод оценки! Повторите ввод\n";
        check = false;
    }

    return check;
}

int markInput()
{
    int mark = 0;

    do
    {
        std::cout << "\nВведите оценку от 1 до 5: ";
        std::cin >> mark;
    } while (!markCheck(mark));

    return mark;
}

bool checkMarkPos(int pos, std::vector<int>& marks)
{
    bool check = true;

    if (pos < 0 || pos > marks.size())
    {
        std::cout << "\nТакого номера оценки не существует! Повторите ввод\n";
        check = false;
    }

    return check;
}

int posInput()
{
    int pos = 0;

    do
    {
        std::cout << "\nВведите номер оценки: ";
        std::cin >> pos;
    } while (!markCheck(pos));

    return --pos;
}

void replaceMark(std::vector<int>& marks)
{
    int pos = posInput();
    int mark = markInput();
    
    marks[pos] = mark;
}

void averageMark(std::vector<int>& marks)
{
    int averageMark = 0;

    for (int mark: marks)
    {
        averageMark += mark;
    }

    std::cout << "\nСредний балл: " << (double) averageMark / marks.size() << std::endl;
}

void runProg(std::vector<int>& marks)
{
    int pointMenu = -1;

    while (pointMenu != 0)
    {
        printMenu();
        
        std::cout << "\nВведите пункт меню: ";
        std::cin >> pointMenu;

        switch (pointMenu)
        {
        case 1:
            printAllMarks(marks);
            break;
        case 2:
            marks.push_back(markInput());
            break;
        case 3:
            marks.erase(marks.cbegin() + posInput());
            break;
        case 4:
            replaceMark(marks);
            break;
        case 5:
            averageMark(marks);
            break;
        case 0:
            std::cout << "\nЗавершение работы программы" << std::endl;
            break;
        default:
            std::cout << "\nВы ввели неправильный номер пункта меню! Повторите ввод.\n" << std::endl;
            break;
        }
    }
}

int main()
{
    std::vector<int> marks{ 1, 2, 3, 4, 5 };
    
    setlocale(LC_ALL, "Russian");
    runProg(marks);
}
