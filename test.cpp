/// tarokh vatan

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;

 

int main() {
	struct Employee { //goroh employee ke tarif shode !
		char First_Name[50], Last_Name[50]; // fist name 50 char dar memory zakhire beshe (halate limit)
		char Part_Job[50]; //karmand che bakhshi kar mikone
		int Salary;
		long int TaxEMP_last; // saqfe daryafti dar pele qabli 
		int Start_Time; // shoro kari
		int Finish_Time; // payan kari
	};
	Employee Emp;
	char xlast_name[50];
	// system sakht va neveshtari file
	FILE* fp, * ft;
	fp = fopen("Database_Employee.txt", "rb+"); //baraye khandan va neveshtan dar mire vase marhale bad

	if (fp == NULL) {
		fp = fopen("Database_Employee.txt", "wb+");

		if (fp == NULL)
		{
			puts("Cannot open file");
			return 0;
		}
	}
	/////////////////////////////////////////
	long int recsize;
	recsize = sizeof(Employee);

	////////////////////
	//esm motaqayer ha
	char choice , another;
	
	// menu asli//
	while (1) {
		system("cls");
		cout << " \t\t\t\t\t|Welcome to program Employee salaries|" << endl;
		cout << " \t\t\t\t\t |Please Enter your select numbers !|" << endl;
		cout << "\n";
		cout << "\t\t\t\t\t\t------------------------" << endl;
		cout << "\t\t\t\t\t\t1) Add Employee" << "        |" << endl;
		cout << "\t\t\t\t\t\t2) List Employee" << "       |" << endl;
		cout << "\t\t\t\t\t\t3) Modify Employee" << "     |" << endl;
		cout << "\t\t\t\t\t\t4) Delete Employee" << "     |" << endl;
        cout << "\t\t\t\t\t\t5) Tax About" << "     |" << endl;
		cout << "\t\t\t\t\t\t6) About Program" << "       |" << endl;
		cout << "\t\t\t\t\t\t7) Exit" << "                |" << endl;
		cout << "\t\t\t\t\t\t------------------------" << endl;
		cout << "\t\t\t\t\t\tchoice : ";
		fflush(stdin); // vazife khali kardan baffuer jaryani ke be onvane parametr ersal mishe ro be ohde dare 
		//back system menu
        choice = getche();

		switch (choice) {
		case '1':
			fseek(fp, 0, SEEK_END);
			another = 'Y';
			while (another == 'Y' || another == 'y')
			{
				system("cls");
				cout << "Enter the First Name Employee : ";
				cin >> Emp.First_Name;
				cout << "Enter the Last Name Employee : ";
				cin >> Emp.Last_Name;
				cout << "Enter the part of job Employee  : ";
				cin >> Emp.Part_Job;
				cout << "Enter the Salary :";
				cin >> Emp.Salary;
				cout << "Enter the Tax : ";
				cin >> Emp.TaxEMP_last;
				cout << "Enter the start time employee : ";
				cin >> Emp.Start_Time;
				cout << "Enter the finish time employee : ";
				cin >> Emp.Finish_Time;
				fwrite(&Emp, recsize, 1, fp);
				cout << "\n Add Another Record (Y/N) ";
				fflush(stdin);
				another = getchar();
			}
			break;
		case '2':
			system("cls");
			rewind(fp);
			cout << "=== View the Records in the Database ===";
			cout << "\n";
			while (fread(&Emp, recsize, 1, fp) == 1) {
				cout << "\n";
				cout << "\n" <<"FIRST NAME : " << Emp.First_Name << setw(15) << "LAST NAME : "<< Emp.Last_Name << setw(20) <<"SALARY EMPLOYEE : " << Emp.Salary << " TOMAN" << setw(20) << "TAX EMPLOYEE : " << Emp.TaxEMP_last << setw(20) << "Start time  : " << Emp.Start_Time << setw(20) << "Finish time : " << Emp.Finish_Time;
			}
			cout << "\n\n";
			system("pause");
			break;
		case '3':
			system("cls");
			another = 'Y';
			while (another == 'Y' || another == 'y')
			{
				cout << "\n Enter the last name of the Employee : ";
				cin >> xlast_name;

				rewind(fp);
				while (fread(&Emp, recsize, 1, fp) == 1)
				{
					if (strcmp(Emp.Last_Name, xlast_name) == 0) //moqayese charecter ( bar hasbe meqdar alphabet)
					{
						cout << "Enter the First Name Employee : ";
						cin >> Emp.First_Name;
						cout << "Enter the Last Name Employee : ";
						cin >> Emp.Last_Name;
						cout << "Enter the part of job Employee  : ";
						cin >> Emp.Part_Job;
						cout << "Enter the Salary :";
						cin >> Emp.Salary;
                        cin >> Emp.TaxEMP_last;
						cout << "Enter the start time employee : ";
						cin >> Emp.Start_Time;
						cout << "Enter the finish time employee : ";
						cin >> Emp.Finish_Time;
						fseek(fp, -recsize, SEEK_CUR);
						fwrite(&Emp, recsize, 1, fp);
						break;
					}
					else
						cout << "record not found";
				}
				cout << "\n Modify Another Record (Y/N) ";
				fflush(stdin);
				another = getchar();
			}
			break;
		case '4':
			system("cls");
			another = 'Y';
			while (another == 'Y' || another == 'y')
			{
				cout << "\n Enter the last name of the student to delete : ";
				cin >> xlast_name;

				ft = fopen("temp.dat", "wb");

				rewind(fp);
				while (fread(&Emp, recsize, 1, fp) == 1)

					if (strcmp(Emp.Last_Name, xlast_name) != 0)
					{
						fwrite(&Emp, recsize, 1, ft);
					}
				fclose(fp);
				fclose(ft);
				remove("Database_Employee.txt");
				rename("temp.dat", "Database_Employee.txt");

				fp = fopen("Database_Employee.txt", "rb+");

				cout << "\n Delete Another Record (Y/N) ";
				fflush(stdin);
				another = getchar();
			}

			break;

		case '5':
			system("cls");
            cout << "0 - 5/600/000 toman --> tax free ! \n";
            cout << "5/600/000 - 15/000/000 toman | TAX = 0 - 940/000 TOMAN! --> %10 \n";
            cout << "15/000/000 - 25/000/000 toman | TAX = 940/000 - 1/500/000 TOMAN! --> %15 \n";
            cout << "25/000/000 - 35/000/000 toman | TAX = 1/500/000 - 2/000/000 ! TOMAN--> %20 \n";
            cout << "35/000/000 - unlimited | TAX = 2/000/000 - unlimited  ! TOMAN--> %30 \n";
			cout << "\n\n";
			system("pause");
			break;  
        case '6':
			system("cls");
			cout << "this program is licesens tehran institute of Technology and github tlauros \n";
			cout << "DEVELOPED BY TLAUROS (TAROKH VATAN)";
			cout << "\n\n";
			system("pause");
			break;


		case '7':
			fclose(fp);
			cout << "\n\n";
			cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE";
			cout << "\n\n";
			exit(0);
		}


		return 0;
	}
}