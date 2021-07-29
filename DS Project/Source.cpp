#include <iostream>	
#include <string>
#include <iomanip>
using namespace std;
struct student
{
	string  name, address;
	int acad_year, phone_num[5], section, id, counter=-1;
	student *next;
};
student *start = NULL;
void display(student x)
{
	cout << "============================================================================" << endl;
	cout << " Student Name : " << x.name << endl;
	cout << " Section : " << x.section << endl;
	cout << " Id : " << x.id << endl;;
	cout << " Academic Year " << x.acad_year << endl;
	cout << " His Address " << x.address << endl;
	for (x.counter; 0 >= x.counter;x.counter --)
	{
		cout << " Phone Number " << x.phone_num[x.counter] << endl;
	}
	cout << "============================================================================" << endl;
}
void add_student(student stud)
{
	student *q = start;
	student *temp = new student;
	temp->acad_year = stud.acad_year;
	temp->address = stud.address;
	temp->name = stud.name;
	for (int i = 0; i <= stud.counter; i++)
	{
		temp->phone_num[i] = stud.phone_num[i];
	}
	temp->id = stud.id;
	temp->section = stud.section;
	temp->next = NULL;                  
	if (start == NULL)
		start = temp;
	else
	{
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = temp;
	}
} 
void search(int id)
{
	student *q = start;  
	while (q != NULL)
	{
		if (q->id == id)
		{
			cout << setw(25) << "Studet Found !" << endl;
			 display(*q);
			return;
		}
			q =q->next;
	}
	if
		(q == NULL)
	{
		cout << setw(25) << "No Such Student Found" << endl;
		return;
	}
}
void delete_student(int id)
{ 
	student *temp = start, *prev;
	if (temp != NULL && temp->id == id)
	{
		start = temp->next;
		delete(temp);          
		return;
	}
	while (temp != NULL && temp->id != id)
	{
		prev = temp;
		temp = temp->next;
	} 
	if (temp == NULL) return;
	prev->next = temp->next;
	delete(temp);
}
void reset()
{
	int x;
	cout << "Are you sure you want to reset ?...press 1 to reset." << endl;
	cin >> x;
	if (x == 1)
	{
		start = new student;
		start = NULL;
		cout << "The List Had Been Reseted" << endl;
	}
	else
		return;
}
void edit_student(int id)
{
	int x;
	student *q = start;  
	while (q != NULL)
	{
		if (q->id == id)
		{
			cout << setw(25) << "Current Student Info." << endl;
			display(*q);
			retry:
			cout << "Enter 1 To Edit Name" << endl;
			cout << "Enter 2 To Edit Student Number" << endl;
			cout << "Enter 3 To Edit Student Address" << endl;
			cout << "Enter 4 To Edit Student ID " << endl;
			cout << "Enter 5 To Edit Student Section " << endl;
			cout << "Enter 6 To Edit Student Academic Year " << endl;
			cin >> x;
			switch (x)
			{
			case 1:
			{
				cout << endl << "Enter New Student  Name " << endl;
				cin >> q->name;
				break;
			}
			case 2:
			{
				cout << " Enter New Student Number " << endl;
				for (int i = 0; i <= q->counter; i++)
				{
					cin >> q->phone_num[i];
				}
				break;
			}
			case 3:
			{
				cout << " Enter New Student Address" << endl;
				cin >> q->address;
				break;
			}
			case 4:
			{
				cout << " Enter New Student Id " << endl;
				cin >> q->id;
				break;
			}
			case 5:
			{
				cout << " Enter New Student Section " << endl;
				cin >> q->section;
				break; 
			}
			case 6:
			{
				cout << "Enter New Academic Year " << endl;
				cin >> q->acad_year;
				break;
			}
			default:
			{
				cout << "Invalid Selection" << endl;
				goto retry;
			}
			}
			return;
		}
		q = q->next;
	}
	if
		(q == NULL)
	{
		cout << setw(25) << "No Such Student Found" << endl;
		return;
	}
}
void main()

{ 
	int i = 0;
	cout << setw(20) << "Student Registration" << endl;
	student stud;
start:
	cout << "============================================================================" << endl;
	cout << "-Press 1 to add student." << endl;
	cout << "-press 2 to delete student." << endl;
	cout << "-press 3 to search for student." << endl;
	cout << "-press 4 to display students info." << endl;
	cout << "-press 5 to reset students info." << endl;
	cout << "-Press 6 to edit student" << endl;
	cout << "-Press 0 to exit" << endl;
	int selection;
	cin >> selection;
	switch (selection)
	{
	case 1:
	{
		cout << "============================================================================" << endl;
		cout << "Enter Student Name " << endl;
		cin >> stud.name;
		do {
			i = 0;
			stud.counter ++;
			if (stud.counter == 5)
			{
				cout<< "You Have Reached The Maximun Of Phone Numbers -_-" << endl;
				stud.counter --;
				break;
			}
			cout << " Enter Student Number " << endl;
			cin >> stud.phone_num[stud.counter];
			cout << "Press 0 To Add Another Phone Number " << endl;
			cin >>i;
	
		} while (i == 0);
		cout << " Enter Student Address" << endl;
		cin >> stud.address;
		cout << " Enter Student Id " << endl;
		cin >> stud.id;
		cout << " Enter Student Section " << endl;
		cin >> stud.section;
		cout << " Academic Year " << endl;
		cin >> stud.acad_year;
		add_student(stud);
		cout << "============================================================================" << endl;
		break;
	}
	case 2:
	{	int id;
	cout << "============================================================================" << endl;
	cout << "Enter The Student's ID." << endl;
	cin >> id;
	delete_student(id);
	cout << "============================================================================" << endl;
	break;
	}
	case 3:
	{
		int id;
		cout << "============================================================================" << endl;
		cout << " Enter The Student's Id " << endl;
		cin >> id;
		search(id);
		cout << "============================================================================" << endl;
		break;
	}
	case 4:
	{
		cout << "============================================================================" << endl;
		student *temp = new student;
		temp = start;
		while (temp != NULL)
		{
			display(*temp);
			temp = temp->next;
		}

		break;
	}
	case 5:
	{
		cout << "============================================================================" << endl;
		reset();
		break;
	}
	case 6:
	{		cout << "============================================================================" << endl;
		int id;
		cout << "Enter The Student ID TO Edit" << endl;
		cin >> id;
			edit_student(id);
		break;
	}
	case 0: return;
	}
	goto start;
}