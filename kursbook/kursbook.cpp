
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <cstring>
#include <chrono>
#include <string>
#include <random>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;
using namespace chrono;

struct students {
    char fio[100];
    char sex[100];
    int groupNumber;
    int groupListNumber;
    int gradesForTheLastSession[8];
    char formOfEducation[100];
    time_t dataChanges;
};

struct List {
    int data;
    List* next;
    List* prev;
    int list[10];
};

int Size;

// Создание новой записи о студенте
void createStudents() {

    students stu;
    string path = "test_2.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open()) {
        cout << "Eror!";
    }
    else {

        cout << "\nEnter the FIO: ";
        cin >> stu.fio;

        cout << "\nEnter the sex: ";
        cin >> stu.sex;

        cout << "\nEnter the Number group: ";
        cin >> stu.groupNumber;

        cout << "\nEnter the Group List Number: ";
        cin >> stu.groupListNumber;

        cout << "\nEnter the Grades For The Last Session: ";

        for (int i = 0; i < 8; i++) {
            cin >> stu.gradesForTheLastSession[i];
        }

        cout << "\nEnter the Form Of Education: ";
        cin >> stu.formOfEducation;

        stu.dataChanges = time(NULL);
        cout << "\n";

        cout << "FIO: " << stu.fio << "\n";
        cout << "SEX: " << stu.sex << "\n";
        cout << "Group Number: " << stu.groupNumber << "\n";
        cout << "Group List Number: " << stu.groupListNumber << "\n";
        cout << "Grades For The Last Session: " << stu.gradesForTheLastSession << "\n";
        cout << "The Form Of Education: " << stu.formOfEducation << "\n";
        cout << "The Data Changes: " << stu.dataChanges << "\n";

        fs << stu.fio << '\n';
        fs << stu.sex << '\n';
        fs << stu.groupNumber << '\n';
        fs << stu.groupListNumber << '\n';

        for (int i = 0; i < 8; i++) {
            fs << stu.gradesForTheLastSession[i] << " ";
        }
        fs << "\n";

        fs << stu.formOfEducation << '\n';
        fs << stu.dataChanges << '\n';
    }

    fs.close();
}


// edit makingChangesToAnexiStingRecord
void makingChangesToAnexiStingRecord() {

    students stu;
    string path = "test_2.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open()) {
        cout << "Eror!";
    }
    else {
        cout << "\nEdit FIO: ";
        cin >> stu.fio;

        cout << "\nEdit the sex: ";
        cin >> stu.sex;

        cout << "\nEdit the Number group: ";
        cin >> stu.groupNumber;

        cout << "\nEdit the Group List Number: ";
        cin >> stu.groupListNumber;

        cout << "\nEdit the Grades For The Last Session: ";
        for (int i = 0; i < 8; i++) {
            cin >> stu.gradesForTheLastSession[i];
        }

        cout << "\nEdit the Form Of Education: ";
        cin >> stu.formOfEducation;

        cout << "FIO: " << stu.fio << "\n";
        cout << "SEX: " << stu.sex << "\n";
        cout << "Group Number: " << stu.groupNumber << "\n";
        cout << "Group List Number: " << stu.groupListNumber << "\n";
        cout << "Grades For The Last Session: " << stu.gradesForTheLastSession << "\n";
        cout << "The Form Of Education: " << stu.formOfEducation << "\n";
        cout << "The Data Changes: " << stu.dataChanges << "\n";

        fs << stu.fio << '\n';
        fs << stu.sex << '\n';
        fs << stu.groupNumber << '\n';
        fs << stu.groupListNumber << '\n';
        fs << stu.gradesForTheLastSession << '\n';
        fs << stu.formOfEducation << '\n';
        fs << stu.dataChanges << '\n';
    }

    fs.close();
}

// функция возврат заначения
students* getAllDataFromFile() {

    students* List = NULL; // 
    ifstream file;

    file.open("test_2.txt");
    while (!file.is_open()) {

        cout << "file error! \n";
        return NULL;
    }

    Size = 0;

    while (!file.eof()) {
        List = (students*)realloc(List, (Size + 1) * sizeof(students));
        students* newStudent = List + Size;
        file.getline(newStudent->fio, 100);
        file.getline(newStudent->sex, 100);
        file >> newStudent->groupNumber;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        file >> newStudent->groupListNumber;

        file.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < 8; i++) {
            file >> newStudent->gradesForTheLastSession[i];
        }

        file.ignore(numeric_limits<streamsize>::max(), '\n');
        file.getline(newStudent->formOfEducation, 100);
        file >> newStudent->dataChanges;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        Size++;
    }

    file.close();
    return List; // возращает указатель впамати
}

// маска для вывода полей
void printStudents(students* stu) {

    for (int i = 0; i < Size; i++) {
        students* Current = stu + i;
        cout << "FIO: " << Current->fio << "\n";
        cout << "SEX: " << Current->sex << "\n";
        cout << "Group Number: " << Current->groupNumber << "\n";
        cout << "Group List Number: " << Current->groupListNumber << "\n";
        cout << "Grades For The Last Session: " << " ";
        for (int i = 0; i < 8; i++) {
            cout << Current->gradesForTheLastSession[i] << " ";
        }
        cout << "\n";

        cout << "The Form Of Education: " << Current->formOfEducation << "\n";
        cout << "The Data Changes: " << ctime(&(Current->dataChanges)) << "\n";
    }
    stu = stu + 1;
}

// функция изменения записи
void editPrintStudents(students* stu) {

    ofstream file;
    string path = "test_2.txt";

    file.open(path, std::ios_base::trunc);

    if (!file.is_open()) {
        cout << "file error! \n";
    }
    else {

        for (int i = 0; i < Size; i++) {

            students* Current = stu + i;

            file << Current->fio << '\n';
            file << Current->sex << '\n';
            file << Current->groupNumber << '\n';
            file << Current->groupListNumber << '\n';

            for (int i = 0; i < 8; i++) {
                file << Current->gradesForTheLastSession[i] << " ";
            }
            file << "\n";

            file << Current->formOfEducation << '\n';
            file << Current->dataChanges;
            //file << ctime(&(Current->dataChanges));

            if (!(i == Size - 1)) {
                file << '\n';
            }
        }
        file.close();
    }

}

// функция записывает в память
void memoryEdit(students* stu) {

    students* Current;

    for (int i = 0; i < Size; i++) {
        Current = stu + i;
        cout << i + 1 << ". " << Current->fio << '\n';
    }

    cout << "Enter the students: ";

    int number;
    cin >> number;
    Current = stu + number - 1;

    cout << "FIO: ";
    cin >> Current->fio;
    cout << "SEX: ";
    cin >> Current->sex;
    cout << "Group Number: ";
    cin >> Current->groupNumber;
    cout << "Group List Number: ";
    cin >> Current->groupListNumber;
    cout << "Grades For The Last Session: ";

    for (int i = 0; i < 8; i++) {
        cin >> Current->gradesForTheLastSession[i];
    }

    cout << "The Form Of Education: ";
    cin >> Current->formOfEducation;
    cout << "The Data Changes: ";

    cin.getline(Current->sex, 100);

    editPrintStudents(stu);
}

//Вывод информации обо всех студентах группы N. N – инициализируется пользователем

void outputAllStudentsGroupN(students* List) {

    int n;
    cout << "Enter the group number:" << endl;
    cin >> n;

    for (int i = 0; i < Size; i++) {

        if (List[i].groupNumber == n) {

            cout << List[i].fio << endl;
            cout << List[i].sex << endl;
            cout << List[i].groupNumber << endl;
            cout << List[i].groupListNumber << endl;

            cout << "Term grades:";
            for (int j = 0; j < 8; j++) {
                cout << List[i].gradesForTheLastSession[j] << " ";

            }
            cout << endl;

            cout << List[i].formOfEducation << endl;
            cout << ctime(&(List[i].dataChanges)) << endl;
        }
    }
}

void listTop(students* List)
{
    cout << "Top students:" << std::endl << std::endl;
    // структура для хранения средних балов
    struct sortList
    {
        unsigned int number;
        double score;
    };

    sortList* SortList = (sortList*)malloc(sizeof(sortList) * Size);

    for (int i = 0; i < Size; i++) {

        int sum = 0;
        (SortList + i)->number = i;

        for (int j = 0; j < 8; j++) {
            sum = (sum + List[i].gradesForTheLastSession[j]);
            (SortList + i)->score = (double)sum / 8;
        }
    }

    int sorted = 0;
    int currentMaxUnsorted = Size - 1;
    while (!sorted)
    {
        sorted = 1;
        for (int i = 0; i < currentMaxUnsorted; i++)
        {
            if ((SortList + i)->score - (SortList + i + 1)->score > 0)
            {
                sortList Buffer;
                Buffer.number = (SortList + i)->number;
                Buffer.score = (SortList + i)->score;
                (SortList + i)->number = (SortList + i + 1)->number;
                (SortList + i)->score = (SortList + i + 1)->score;
                (SortList + i + 1)->number = Buffer.number;
                (SortList + i + 1)->score = Buffer.score;
                sorted = 0;
            }
        }
        currentMaxUnsorted--; // последний уже отсортирован и проверсять не надо 
    }

    for (unsigned int i = Size - 1, j = 0; i >= 0 && j < 3; i--, j++)
    {
        cout << List[(SortList + i)->number].fio << endl;
        cout << List[(SortList + i)->number].sex << endl;
        cout << List[(SortList + i)->number].groupNumber << endl;
        cout << List[(SortList + i)->number].groupListNumber << endl;
        cout << "Term grades:";
        for (int j = 0; j < 8; j++) {
            cout << List[(SortList + i)->number].gradesForTheLastSession[j] << " ";
        }
        cout << endl;
        cout << List[(SortList + i)->number].formOfEducation << endl;
        cout << ctime(&(List[(SortList + i)->number].dataChanges)) << endl;
    }
    std::cout << std::endl << std::endl;
    free(SortList); // осовобождения памяти функции малок
}

/*----------------------------------------------*/

void getItemArray() {

    int size;
    cout << "Enter the number: ";
    cin >> size;

    if (size <= 100) {

        int* arr = new int[size];

        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % 100;
        }

        for (int i = 0; i < size; ++i) {
            cout << arr[i] << "\t" << arr + i << "\n";
        }

        delete[] arr;
    }

    else {
        cout << "Error! ";
    }

}

List* getAllDataFromFile2() {

    List* listFile = NULL; // 
    ifstream file;

    file.open("list.txt");
    while (!file.is_open()) {

        cout << "file error! \n";
        return NULL;
    }

    Size = 0;

    while (!file.eof()) {

        listFile = (List*)realloc(listFile, (Size + 1) * sizeof(List));
        List* newList = listFile + Size;

        for (int i = 0; i < 10; i++) {
            file >> newList->list[i];
        }

        file.ignore(numeric_limits<int>::max(), '\n');
        Size++;
    }

    file.close();
    return listFile; // возращает указатель впамати
}

void getListFile(List* N) {

    for (int i = 0; i < Size; i++) {

        List* Current = N + i;

        cout << "the array is read from the file, N is defined as the number of array elements in the file" << endl;
        cout << "Array: " << " ";
        for (int i = 0; i < 10; i++) {
            cout << Current->list[i] << " ";
        }
        cout << "\n";
        cout << "count item array: ";
        cout << sizeof(Current->list) / sizeof(int);
    }

    N = N + 1;
}

void FillArray(int* const arr, const int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void ShowArray(const int* const arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void push_back(int*& arr, int& size, const int value) {

    int* newArray = new int[size + 1];

    for (int i = 0; i < size; i++) {
        newArray[i] = arr[i];
    }

    newArray[size] = value;

    size++;

    delete[] arr;

    arr = newArray;

}

void pop_back(int*& arr, int& size) {

    size--;
    int* newArray = new int[size];

    for (int i = 0; i < size; i++) {
        newArray[i] = arr[i];
    }

    delete[] arr;
    arr = newArray;
}

void editArray() {

    vector <double> array = { 11, 32, 21, 13, 184, 5, 18, 23, 71, 40, 10 };

    /*for (int i = 0; i < 11; ++i) {
        array[i] = rand() % 100;
    }*/

    cout << "The vector: > " << " ";
    for (int i = 0; i < array.size(); i++) {
        cout << "v: " << array[i] << " | ";
    }

    cout << endl;
    cout << "Add new item: > " << " ";
    int addItem;
    cin >> addItem;
    array.push_back(addItem);
    cout << "The vector: > " << " ";
    for (int i = 0; i < array.size(); i++) {
        cout << "v: " << array[i] << " | ";
    }

    cout << endl;

    cout << "delete by index: [0 to n]" << endl;
    cout << ">";
    int indexToRemove;
    cin >> indexToRemove;

    array.erase(array.begin() + indexToRemove);

    cout << "The vector: > " << " ";
    for (int i = 0; i < array.size(); i++) {
        cout << "v: " << array[i] << " | ";
    }

    cout << endl;
    cout << "select item mass: [0 to n] > " << " ";
    int select;
    cin >> select;
    if (select < 12) {
        cout << "v: " << array[select] << "\t";
    }
    else {
        cout << "error!";
    }
}

//inserts List at the front of the list
void insert_front(struct List** head, int new_data)
{
    //выделяю память для нового списка 
    struct List* newList = new List;

    //назначить данные в новый список
    newList->data = new_data;

    //новый список является заголовком, а предыдущий - нулевым, так как мы добавляем впереди
    newList->next = (*head);
    newList->prev = NULL;

    //previous of head is new List
    if ((*head) != NULL)
        (*head)->prev = newList;

    //заголовок указывает на новый список
    (*head) = newList;
}

/* вставка нового списка после нового */
void insert_After(struct List* prev_List, int new_data)
{
    if (prev_List == NULL) {
        cout << "Previous List is required , it cannot be NULL";
        return;
    }

    struct List* newList = new List;

    newList->data = new_data;

    //установить следующий из newList на следующий из предыдущего списка
    newList->next = prev_List->next;

    //установить следующий из предыдущего списка в новый список
    prev_List->next = newList;

    //теперь установите prev для newList на prev List
    newList->prev = prev_List;

    //установить предыдущий новый список рядом с новым списком
    if (newList->next != NULL) {
        newList->next->prev = newList;
    }
}

//вставить новый список в конец списка
void insert_end(struct List** head, int new_data)
{
    //выделяю памать для списка
    struct List* newList = new List;

    struct List* last = *head; //установить последнее значение списка в заголовок

    //установить данные для нового списка
    newList->data = new_data;

    //установка для следующего нового списка значение null
    newList->next = NULL;

    //если список пуст - создаем новый	
    if (*head == NULL) {
        newList->prev = NULL;
        *head = newList;
        return;
    }

    //в противном случае перейдите по списку, чтобы перейти к последнему списку
    while (last->next != NULL)
        last = last->next;

    //установить предпоследний в новый список
    last->next = newList;

    //установить последний на предыдущий в новом списке
    newList->prev = last;
    return;
}

// вывод 
void displayList(struct List* List) {

    struct List* last;

    while (List != NULL) {
        cout << List->data << "<==>";
        last = List;
        List = List->next;
    }
    if (List == NULL) {
        cout << "NULL";
    }
}

void dellList(struct List* list) {

    struct List* prev, * next;
    prev = list->prev;
    next = list->next;
    if (prev != NULL) {
        prev->next = list->next;
    }
    if (next != NULL) {
        next->prev = list->prev;
    }
    free(list);
}



int main()
{
    int choice;
    cout << " Laboratory works.\n";
    cout << " 1 - User-defined data types\n";
    cout << " 2 - linear data structures\n";
    cout << endl;
    cout << endl;
    
    cout << "enter the lab number (1 - 2)\n";

    cout << "> ";
    cin >> choice;


    if (choice == 1) {

        int select;

        cout << "1 - Creating a new student record\n";
        cout << "2 - Edit making changes to anexi sting recordn\n";
        cout << "3 - Record change function \n";
        cout << "4 - Out put all students group N \n";
        cout << endl;
        cout << endl;
        cout << "select the function (1 - 4)\n";
        cin >> select;

        if (select == 1) {
            createStudents();
        }

        if (select == 2) {
            makingChangesToAnexiStingRecord();
        }

        if (select == 3) {
            cout << "oppppsss :(";
        }

        if (select == 4) {
          students* stu_1 = getAllDataFromFile();
          printStudents(stu_1);
        }
    }

    if (choice == 2) {
        cout << "Choise: (1) (2) (3)" << endl;
        cout << "(1) Formation of an integer one-dimensional array" << endl;
        cout << "(2) Getting an array element" << endl;
        cout << "(3) Formation of a doubly linked list" << endl;
        cout << " -> ";
        int input;
        cin >> input;
        if (input == 1) {
            cout << "Formation of an integer one-dimensional array of dimension N, where: ";
            getItemArray();
            cout << endl;
            system_clock::time_point start = system_clock::now();
            List* newl = getAllDataFromFile2();
            getListFile(newl);
            cout << "\n";
            system_clock::time_point end = system_clock::now();

            duration<double> sec = end - start;
            cout << "seconds: " << sec.count() << endl << endl;
        }
        // определение скорости создания динамического массива

        if (input == 2) {
            int size;
            cout << "Enter the size: ";
            cin >> size;
            int* arr = new int[size];

            FillArray(arr, size);

            system_clock::time_point start_1 = system_clock::now();
            ShowArray(arr, size);
            system_clock::time_point end_1 = system_clock::now();
            duration<double> sec_ = end_1 - start_1;
            cout << "seconds: " << sec_.count() << endl << endl;
            int add;
            cout << "add new item last of list: ";
            cin >> add;
            system_clock::time_point start_2 = system_clock::now();
            push_back(arr, size, add);
            ShowArray(arr, size);
            system_clock::time_point end_2 = system_clock::now();
            duration<double> sec_2 = end_2 - start_2;
            cout << "seconds: " << sec_2.count() << endl;

            pop_back(arr, size);

            ShowArray(arr, size);

            editArray();
        }
        cout << endl;

        if (input == 3) {

            struct List* head = NULL;

            int x, x2, x3, x4, x5;

            cout << "Enter the x" << " ";
            cin >> x;
            cout << "Enter the x2" << " ";
            cin >> x2;
            cout << "Enter the x3" << " ";
            cin >> x3;
            cout << "Enter the x4" << " ";
            cin >> x4;
            cout << "Enter the x5" << " ";
            cin >> x5;

            // Insert 40 as last node
            insert_end(&head, x4);

            // Insert 10 at the beginning.
            insert_front(&head, x2);

            // Insert 30, after 20.
            insert_After(head->next, x3);

            // insert 20 at the head
            insert_front(&head, x);

            // Insert 50 at the end.
            insert_end(&head, x5);

            cout << "Doubly linked list is as follows: " << endl;
            displayList(head);

        }
    }
}

