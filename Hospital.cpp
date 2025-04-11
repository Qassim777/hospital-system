#include <iostream>

#include <string>

#include <cstring>

#include <fstream>

#include <cstdlib>

using namespace std;

struct date
{
    int day;
    int month;
    int year;
};
struct Patient
{
    string id;
    string name;
    string number;
    string gender;
    date birthday;
    int age;
};

int size = 1000;

void Add_patient(int &con, Patient data[], string med[], int dose[]); // function to add new patient

int search(string find, int cont, Patient data[]); // function to search for a spisfic  patient

void Update_patient(string update, int cont, Patient data[], string med[], int dose[]); // function to change details about a spisfic patient

void delete_patient(int &cont, Patient data[], string med[], int dose[]); // function to delete a patient from the system

void sort(int counter, Patient data[], string med[], int dosages[]); // function to sort patients names

void display(int cont, Patient data[], string med[], int dose[]); // function to display all the patient and their information

void saveData(int cont, string fileName, Patient pt[], string med[], int dose[]); // a function to save all the patients names and detailes in a file

int readFile(int num, string fileName, Patient data[], string med[], int dose[]); // a function to read all the information about patients and save them in arries

bool END(bool cond); // finction that reaurn false to end the program

void statistic(int cont, Patient data[], string med[], int dose[]);
//-----------------------------------The main function---------------------------------------

int main()
{
    cout << "----------------------------The begining of the program---------------------------" << endl;
    int counter = 0;
    int FIndIndex;
    string look;
    bool condition = true;
    Patient detail[size];
    string medicine[size];
    int doses[size];
    string updeate;
    string fName = "Patient.txt";
    int num = 0;
    counter = readFile(counter, fName, detail, medicine, doses);
    do
    {
        cout << "\nChoose from the menu: " << endl;
        cout << "1. Add new patient" << endl;
        cout << "2. Search for spicfic patient" << endl;
        cout << "3. Change patients deatails" << endl;
        cout << "4. Delete patient" << endl;
        cout << "5. sort patient names" << endl;
        cout << "6. Display all patient names" << endl;
        cout << "7. Exit the program and save the the information" << endl;
        ;
        cin >> num;
        switch (num)
        {
        case (1):
        {
            Add_patient(counter, detail, medicine, doses);
            break;
        }
        case (2):
        {
            cout << "\nEnter the ID of the patient you want to find: ";
            cin >> look;
            if (counter > 0)
            {
                FIndIndex = search(look, counter, detail);
                cout << "\nThe patient ID is " << detail[FIndIndex].id;
                cout << "\nThe patient name is " << detail[FIndIndex].name << " and his or her age is " << detail[FIndIndex].age << " and the gender is " << detail[FIndIndex].gender << endl
                     << " and her or his phone number is " << detail[FIndIndex].number << "\nhis or her date of birth is :" << detail[FIndIndex].birthday.day << "\\" << detail[FIndIndex].birthday.month << "\\" << detail[FIndIndex].birthday.year;
                cout << "\nThe name of his or her madication is " << medicine[FIndIndex] << " and the number of doses are: " << doses[FIndIndex] << endl;
            }
            break;
        }
        case (3):
        {
            cout << "\nEnter Patinet ID To Update: ";
            cin >> updeate;
            Update_patient(updeate, counter, detail, medicine, doses);
            break;
        }
        case (4):
        {
            delete_patient(counter, detail, medicine, doses);
            break;
        }
        case (5):
        {
            sort(counter, detail, medicine, doses);
            cout << "The names have been sorted.\n";
            break;
        }
        case (6):
        {
            display(counter, detail, medicine, doses);
            break;
        }
        case (7):
        {

            condition = END(condition);
            saveData(counter, fName, detail, medicine, doses);
            statistic(counter, detail, medicine, doses);
            break;
        }
        default:
            cout << "\nIncorrect menu selection." << endl;
        }
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    } while (condition);
    return 0;
}

void Add_patient(int &con, Patient data[], string med[], int dose[]) // function to add new patient
{
    {
        if (con < size)
        {
            string temp;
            bool check = true;
            cout << "Enter Patient ID: " << endl;
            cin >> temp;
            for (int i = 0; i < con; i++)
            {
                if (data[i].id == temp)
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                data[con].id = temp;
                cout << "Enter Patient name: " << endl;
                cin >> data[con].name;
                cout << "Enter Patient Gender(male-female): " << endl;
                cin >> data[con].gender;
                cout << "Enter Patient Phone Number: " << endl;
                cin >> data[con].number;
                cout << "Enter Patient Age: " << endl;
                cin >> data[con].age;
                cout << "Enter Patient day of birth: " << endl;
                cin >> data[con].birthday.day;
                cout << "Enter Patient month of birth: " << endl;
                cin >> data[con].birthday.month;
                cout << "Enter Patient year of birth: " << endl;
                cin >> data[con].birthday.year;
                cout << "Enter Patient medicine: " << endl;
                cin >> med[con];
                cout << "Enter Patient number of doses: " << endl;
                cin >> dose[con];
                cout << "A new patient has been added.\n";

                con++;
                return;
            }
            else
            {
                cout << "\nThe ID is already exist\n";
                return;
            }
        }
        else
        {
            cout << "\nThe array is filled\n";
            return;
        }
    }
}

int search(string find, int cont, Patient data[]) // function to search for a spisfic  patient
{
    for (int i = 0; i < cont; i++)
    {
        if (find == data[i].id)
            return i;
    }
    cout << "This name does not exist.\n";
    return -1;
}

void Update_patient(string update, int cont, Patient data[], string med[], int dose[]) // function to change details about a spisfic patient
{
    string change = "\nEnter waht you want to change\n1.  change Patient ID\n2.  change Patient name\n3.  change Patient Gender\n4.  change Patient Phone Number\n5.  change Patient Age\n6.  change Patient birthday\n7.  change Patient medicinen\n8.  change Patient number of doses\n";
    int choice;
    int UblIndex;
    UblIndex = search(update, cont, data);
    cout << change;
    cin >> choice;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    if (UblIndex > -1)
    {
        switch (choice) // switch function so the user choose what he or she want to change abou a patient
        {
        case (1):
        {
            cout << "Enter new Patient ID: " << endl;
            cin >> data[UblIndex].id;
            break;
        }
        case (2):
        {
            cout << "Enter new Patient name: " << endl;
            cin >> data[UblIndex].name;
            break;
        }

        case (3):
        {

            cout << "Enter new Patient Gender(male-female): " << endl;
            cin >> data[UblIndex].gender;
            break;
        }

        case (4):
        {
            cout << "Enter new Patient Phone Number: " << endl;
            cin >> data[UblIndex].number;
            break;
        }

        case (5):
        {
            cout << "Enter new Patient Age: " << endl;
            cin >> data[UblIndex].age;
            break;
        }

        case (6):
        {
            cout << "Enter new Patient day of birth: " << endl;
            cin >> data[UblIndex].birthday.day;
            cout << "Enter new Patient month of birth: " << endl;
            cin >> data[UblIndex].birthday.month;
            cout << "Enter new Patient year of birth: " << endl;
            cin >> data[UblIndex].birthday.year;
            break;
        }
        case (7):
        {
            cout << "Enter new Patient medicine: " << endl;
            cin >> med[UblIndex];
            break;
        }

        case (8):
        {
            cout << "Enter new Patient number of doses: " << endl;
            cin >> dose[UblIndex];
            break;
        }
        default:
        {
            cout << "\nIncorrect menu option." << endl;
        }
        }
        return;
    }
}

void delete_patient(int &cont, Patient data[], string med[], int dose[]) // function to delete a patient from the system
{
    string deleting;
    cout << "\nEnter the ID of the patient you want to delet: ";
    cin >> deleting;
    int delIndex;
    delIndex = search(deleting, cont, data);
    if (delIndex > -1)
    {
        for (int i = delIndex; i < cont - 1; i++)
        {
            data[i] = data[i + 1];
            med[i] = med[i + 1];
            dose[i] = dose[i + 1];
        }
        cont--;
        cout << "The name has been deleted.\n";
    }
    return;
}

void sort(int counter, Patient data[], string med[], int dosages[]) // function to sort patients names
{
    for (int i = 0; i < counter; i++)
        for (int j = 0; j < counter - 1; j++)
            if (data[j].name.compare(data[j + 1].name) > 0)
            {
                string tempstr;
                int tempint;
                Patient tempPa;
                tempPa = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tempPa;
                tempstr = med[j];
                med[j] = med[j + 1];
                med[j + 1] = tempstr;
                tempint = dosages[j];
                dosages[j] = dosages[j + 1];
                dosages[j + 1] = tempint;
            }
}

void display(int cont, Patient data[], string med[], int dose[]) // function to display all the patient and their information
{
    for (int i = 0; i < cont; i++)
    {
        cout << "\nThe patient ID is " << data[i].id;
        cout << "\nThe patient name is " << data[i].name << " and his or her age is " << data[i].age << " and the gender is " << data[i].gender << endl
             << " and her or his phone number is " << data[i].number << "\nhis or her date of birth is :" << data[i].birthday.day << "\\" << data[i].birthday.month << "\\" << data[i].birthday.year;
        cout << "\nThe name of his or her madication is " << med[i] << " and the number of doses are: " << dose[i] << endl;
    }
}

void saveData(int cont, string fileName, Patient pt[], string med[], int dose[]) // a function to save all the patients names and detailes in a file
{
    ofstream oFile;
    oFile.open(fileName.c_str(), ios::out);

    if (oFile.is_open())
    {
        for (int i = 0; i < cont; i++)
        {
            oFile << pt[i].id << endl;
            oFile << pt[i].name << endl;
            oFile << pt[i].number << endl;
            oFile << pt[i].gender << endl;
            oFile << pt[i].age << endl;
            oFile << pt[i].birthday.day << endl;
            oFile << pt[i].birthday.month << endl;
            oFile << pt[i].birthday.year << endl;
            oFile << med[i] << endl;
            oFile << dose[i] << endl;
        }
    }
    else
        cout << "Unable to open file or File Not exists" << endl;

    cout << "The information was saved Successfully  .. " << endl;
    oFile.close();
}

int readFile(int num, string fileName, Patient data[], string med[], int dose[]) // a function to read all the information about patients and save them in arries
{
    ifstream oFile;
    oFile.open(fileName.c_str(), ios::in);
    if (oFile.is_open())
    {
        while (!oFile.eof())
        {
            oFile >> data[num].id;
            oFile >> data[num].name;
            oFile >> data[num].number;
            oFile >> data[num].gender;
            oFile >> data[num].age;
            oFile >> data[num].birthday.day;
            oFile >> data[num].birthday.month;
            oFile >> data[num].birthday.year;
            oFile >> med[num];
            oFile >> dose[num];
            num++;
        }
        num--;
    }
    else
    {

        cout << "Unable to open file File Not exists\n";
    }
    oFile.close();

    return num;
}
bool END(bool cond) // finction that reaurn false to end the program
{
    cond = false;
    return cond;
}

void statistic(int cont, Patient data[], string med[], int dose[]) // finction that write the statistics about the project in a file
{
    double Avage; // avrage age of patient
    int NumFemale = 0;
    int NumMale = 0; // number of females and males patients

    int oldest = 0;  // the oldest patient
    int maxdoes = 0; // largest number of doses used on a patieent
    for (int i = 0; i < cont; i++)
    {
        Avage += data[i].age;
        if (data[i].gender == "male" || data[i].gender == "Male")
            NumMale++;
        else
            NumFemale++;

        if (data[oldest].age < data[i + 1].age)
            oldest = i + 1;

        if (dose[maxdoes] < dose[i + 1])
            maxdoes = i + 1;
    }
    Avage = Avage / cont;
    ofstream StaFile;
    string FName = "statistics.txt";
    StaFile.open(FName.c_str(), ios::out);
    if (StaFile.is_open())
    {
        StaFile << "Number of patients in the hospital is: " << cont << endl;
        StaFile << "The number of males patients in the hospital is: " << NumMale << endl;
        StaFile << "---------------------------------------------------------------------------------------------------------------------------" << endl;
        StaFile << "The number of female patients in the hospital is: " << NumFemale << endl;
        StaFile << "The average ages of patients is: " << Avage << endl;
        StaFile << "---------------------------------------------------------------------------------------------------------------------------" << endl;
        StaFile << "The age of the oldest patient is: " << data[oldest].age << endl;
        StaFile << "The biggest number of doses patient takes is: " << dose[maxdoes] << endl;
    }
    else
        cout << "Unable to open file or File Not exists" << endl;

    StaFile.close();
}
