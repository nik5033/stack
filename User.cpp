#include <iostream>
#include <locale>
#include <cstdlib>
#include "Stack.h"
#include "Test.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	short int choice_test;
	cout << "����?(1-��,0-���)\n";
	cin >> choice_test;
	if (choice_test == 1)
		test();

	int repite=0;
	do {
		cout << "�������� �������:\n";
		cout << "1-map\n2-reduce\n3-where";
		cout << "\n4-������������\n5-���������� ��������������������� �� ��������\n6-����� �� ��������� ���������������������\n7-�������\n8-����������\n";
		short int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Stack FirstStack;
			cout << "\n������� �������� �����:\n";
			FirstStack.Enter();
			cout << "����:\n";
			FirstStack.displaystack();
			Union(*function)(Union);
			function = Plus_Ten_Real;
			Stack Keys(FirstStack.Map(function));
			cout << "�����:\n";
			Keys.displaystack();
			break;
		}
		case 2:
		{
			Stack FirstStack;
			cout << "\n������� �������� �����:\n";
			FirstStack.Enter();
			cout << "����:\n";
			cout << "������� ���������:\n";
			Union Const;
			Const.Enter();
			FirstStack.displaystack();
			Union(*function)(Union, Union);
			function = ModCompare;
			Stack Keys(FirstStack.Reduce(function, Const));
			cout << "����� ����:\n";
			Keys.displaystack();
			break;
		}
		case 3:
		{
			Stack FirstStack;
			cout << "\n������� �������� �����:\n";
			FirstStack.Enter();
			cout << "����:\n";
			FirstStack.displaystack();
			bool(*function)(Union);
			function = ImageExist;
			Stack Keys(FirstStack.Where(function));
			cout << "�����:\n";
			Keys.displaystack();
			break;
		}
		case 4://done
		{
			Stack FirstStack;
			Stack SecondStack;
			cout << "\n������� �������� ������� �����:\n";
			FirstStack.Enter();
			cout << "\n������� �������� ������� �����:\n";
			SecondStack.Enter();
			cout << "������ ����:\n";
			FirstStack.displaystack();
			cout << "������ ����:\n";
			SecondStack.displaystack();
			FirstStack.concatenation(SecondStack);
			cout << "���������:\n";
			FirstStack.displaystack();
			break;
		}
		case 5://done
		{
			cout << "������� �������, � �������� ������� ������ ���� ���������������������:\n";
			int IndexMin;
			int IndexMax;
			IndexMin = enter_Index_min();
			IndexMax = enter_Index_Max(IndexMin);
			Stack OneStack;
			OneStack.Enter();
			cout << "\n��� ����:\n";
			OneStack.displaystack();
			Stack NewStack(OneStack.extraction(IndexMin, IndexMax));
			cout << "\n���������������������:\n";
			NewStack.displaystack();
			break;
		}
		case 6://done
		{
			Stack MainStack;
			Stack SearStack;
			cout << "\n������� �������� �����:\n";
			MainStack.Enter();
			cout << "\n������� �������� ���������������������:\n";
			SearStack.Enter();
			cout << "�������� ����:\n";
			MainStack.displaystack();
			cout << "���������������������:\n";
			SearStack.displaystack();
			if (MainStack.search(SearStack))
				cout << "\n��������������������� ������ � ����\n";
			else
				cout << "\n��������������������� �� ������ � ����\n";
			break;
		}
		case 7://done
		{
			Stack FirstStack;
			Stack SecondStack;
			cout << "\n������� �������� ������� �����:\n";
			FirstStack.Enter();
			cout << "\n������� �������� ������� �����:\n";
			SecondStack.Enter();
			cout << "������ ����:\n";
			FirstStack.displaystack();
			cout << "������ ����:\n";
			SecondStack.displaystack();
			Stack NewStack;
			NewStack.merge(FirstStack, SecondStack);
			cout << "���������:\n";
			NewStack.displaystack();
			break;
		}
		case 8://done
		{
			Stack MyStack;
			cout << "\n������� �������� �����:\n";
			MyStack.Enter();
			cout << "����:\n";
			MyStack.displaystack();
			Stack RealStack;
			Stack ComplexStack;
			MyStack.separate(ComplexStack, RealStack);
			cout << "���� �������������� �����:\n";
			RealStack.displaystack();
			cout << "���� ����������� �����:\n";
			ComplexStack.displaystack();
			break;
		}
		default:
		{
			cout << "\n������ �����\n";
			break;
		}
		}
		while (true)
		{
			cout << endl << "���������?(1-��,0-���)" << endl;
			cin >> repite;
			if (!cin || repite!=0&&repite!=1)
			{
				cout << "������!!! ��������� ����\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
	}while (repite==1);
}
