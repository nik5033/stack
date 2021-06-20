#include <iostream>
#include <locale>
#include <cstdlib>
#include "Stack.h"
#include "Test.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	short int choice_test;
	cout << "Тест?(1-да,0-нет)\n";
	cin >> choice_test;
	if (choice_test == 1)
		test();

	int repite=0;
	do {
		cout << "Выберите функцию:\n";
		cout << "1-map\n2-reduce\n3-where";
		cout << "\n4-конкатенация\n5-извлечение подпоследовательности по индексам\n6-поиск на вхождение подпоследовательности\n7-слияние\n8-разделение\n";
		short int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Stack FirstStack;
			cout << "\nВведите элементы стека:\n";
			FirstStack.Enter();
			cout << "Стек:\n";
			FirstStack.displaystack();
			Union(*function)(Union);
			function = Plus_Ten_Real;
			Stack Keys(FirstStack.Map(function));
			cout << "Ключи:\n";
			Keys.displaystack();
			break;
		}
		case 2:
		{
			Stack FirstStack;
			cout << "\nВведите элементы стека:\n";
			FirstStack.Enter();
			cout << "Стек:\n";
			cout << "Введите константу:\n";
			Union Const;
			Const.Enter();
			FirstStack.displaystack();
			Union(*function)(Union, Union);
			function = ModCompare;
			Stack Keys(FirstStack.Reduce(function, Const));
			cout << "Новый стек:\n";
			Keys.displaystack();
			break;
		}
		case 3:
		{
			Stack FirstStack;
			cout << "\nВведите элементы стека:\n";
			FirstStack.Enter();
			cout << "Стек:\n";
			FirstStack.displaystack();
			bool(*function)(Union);
			function = ImageExist;
			Stack Keys(FirstStack.Where(function));
			cout << "Ключи:\n";
			Keys.displaystack();
			break;
		}
		case 4://done
		{
			Stack FirstStack;
			Stack SecondStack;
			cout << "\nВведите элементы первого стека:\n";
			FirstStack.Enter();
			cout << "\nВведите элементы второго стека:\n";
			SecondStack.Enter();
			cout << "Первый стек:\n";
			FirstStack.displaystack();
			cout << "Второй стек:\n";
			SecondStack.displaystack();
			FirstStack.concatenation(SecondStack);
			cout << "Результат:\n";
			FirstStack.displaystack();
			break;
		}
		case 5://done
		{
			cout << "Введите индексы, в пределах которых должна быть подпоследовательность:\n";
			int IndexMin;
			int IndexMax;
			IndexMin = enter_Index_min();
			IndexMax = enter_Index_Max(IndexMin);
			Stack OneStack;
			OneStack.Enter();
			cout << "\nВаш стек:\n";
			OneStack.displaystack();
			Stack NewStack(OneStack.extraction(IndexMin, IndexMax));
			cout << "\nПодпоследовательность:\n";
			NewStack.displaystack();
			break;
		}
		case 6://done
		{
			Stack MainStack;
			Stack SearStack;
			cout << "\nВведите элементы стека:\n";
			MainStack.Enter();
			cout << "\nВведите элементы подпоследовательности:\n";
			SearStack.Enter();
			cout << "Основной стек:\n";
			MainStack.displaystack();
			cout << "Подпоследовательность:\n";
			SearStack.displaystack();
			if (MainStack.search(SearStack))
				cout << "\nПодпоследовательность входит в стек\n";
			else
				cout << "\nПодпоследовательность не входит в стек\n";
			break;
		}
		case 7://done
		{
			Stack FirstStack;
			Stack SecondStack;
			cout << "\nВведите элементы первого стека:\n";
			FirstStack.Enter();
			cout << "\nВведите элементы второго стека:\n";
			SecondStack.Enter();
			cout << "Первый стек:\n";
			FirstStack.displaystack();
			cout << "Второй стек:\n";
			SecondStack.displaystack();
			Stack NewStack;
			NewStack.merge(FirstStack, SecondStack);
			cout << "Результат:\n";
			NewStack.displaystack();
			break;
		}
		case 8://done
		{
			Stack MyStack;
			cout << "\nВведите элементы стека:\n";
			MyStack.Enter();
			cout << "Стек:\n";
			MyStack.displaystack();
			Stack RealStack;
			Stack ComplexStack;
			MyStack.separate(ComplexStack, RealStack);
			cout << "Стек действительных чисел:\n";
			RealStack.displaystack();
			cout << "Стек комплексных чисел:\n";
			ComplexStack.displaystack();
			break;
		}
		default:
		{
			cout << "\nОшибка ввода\n";
			break;
		}
		}
		while (true)
		{
			cout << endl << "Повторить?(1-да,0-нет)" << endl;
			cin >> repite;
			if (!cin || repite!=0&&repite!=1)
			{
				cout << "Ошибка!!! Повторите ввод\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
	}while (repite==1);
}
