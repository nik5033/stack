#include "Stack.h"
#include<iostream>

using namespace std;

bool test_map()
{
	Number<int> type1;
	Number <double> type2;
	Complex type3;
	Stack answer;
	Union value;

	Stack stack;
	type1.Set(3);
	value.Set(type1);
	stack.push(value);

	type2.Set(6.78);
	value.Set(type2);
	stack.push(value);

	type3.Set(3.8,0.3);
	value.Set(type3);
	stack.push(value);

	type3.Set(0.0,5.0);
	value.Set(type3);
	stack.push(value);

	type1.Set(90);
	value.Set(type1);
	stack.push(value);


	type1.Set(13);
	value.Set(type1);
	answer.push(value);

	type2.Set(16.78);
	value.Set(type2);
	answer.push(value);

	type3.Set(13.8, 0.3);
	value.Set(type3);
	answer.push(value);

	type3.Set(10.0, 5.0);
	value.Set(type3);
	answer.push(value);

	type1.Set(100);
	value.Set(type1);
	answer.push(value);

	Union(*function)(Union);
	function = Plus_Ten_Real;
	Stack result(stack.Map(function));

	cout << "\nОжидаемый результат\n";
	answer.displaystack();
	cout << "\nИтоговый результат\n";
	result.displaystack();

	Node* current_answer = answer.Get_top();
	Node* current_result = result.Get_top();
	for(int i=0;i<5;i++)
	{
		if (!(current_answer->Get_value() == current_result->Get_value()))
			return false;
		current_answer = current_answer->Get_next();
		current_result = current_result->Get_next();
	}
	return true;
}

bool test_reduce()
{
	Number<int> type1;
	Number <double> type2;
	Complex type3;
	Union value;
	Stack answer;


	Stack stack;

	Union Const;
	Number<int> cons;
	cons.Set(7);
	Const.Set(cons);

	type1.Set(2);
	value.Set(type1);
	stack.push(value);

	type2.Set(7.78);
	value.Set(type2);
	stack.push(value);

	type3.Set(3.8, 3.45);
	value.Set(type1);
	stack.push(value);

	type3.Set(0.0, 5.7);
	value.Set(type1);
	stack.push(value);

	type1.Set(90);
	value.Set(type1);
	stack.push(value);

	type1.Set(90);
	value.Set(type1);
	answer.push(value);

	Union(*function)(Union,Union);
	function = ModCompare;
	Stack result(stack.Reduce(function,Const));

	cout << "\nОжидаемый результат\n";
	answer.displaystack();
	cout << "\nИтоговый результат\n";
	result.displaystack();

	if (!(answer.Get_top()->Get_value() == result.Get_top()->Get_value()))
		return false;
	return true;
}

bool test_where()
{
	Number<int> type1;
	Number <double> type2;
	Complex type3;
	Union value;
	Stack answer;


	Stack stack;

	type1.Set(35);
	value.Set(type1);
	stack.push(value);

	type2.Set(0.78);
	value.Set(type2);
	stack.push(value);

	type3.Set(3.8, 0.45);
	value.Set(type3);
	stack.push(value);

	type3.Set(1.0, 5.7);
	value.Set(type3);
	stack.push(value);

	type1.Set(90);
	value.Set(type1);
	stack.push(value);


	type1.Set(35);
	value.Set(type1);
	answer.push(value);

	type2.Set(0.78);
	value.Set(type2);
	answer.push(value);

	type1.Set(90);
	value.Set(type1);
	answer.push(value);

	bool(*function)(Union);
	function = ImageExist;
	Stack result(stack.Where(function));

	cout << "\nОжидаемый результат\n";
	answer.displaystack();
	cout << "\nИтоговый результат\n";
	result.displaystack();

	Node* current_answer = answer.Get_top();
	Node* current_result = result.Get_top();
	for (int i = 0; i < 3; i++)
	{
		if (!(current_answer->Get_value() == current_result->Get_value()))
			return false;
		current_answer = current_answer->Get_next();
		current_result = current_result->Get_next();
	}
	return true;
}

bool test_concatenation()
{
	Number<int> type1;
	Number <double> type2;
	Complex type3;
	Union value;
	Stack answer;


	Stack firststack;
	Stack secondstack;

	type2.Set(0.78);
	value.Set(type2);
	answer.push(value);
	firststack.push(value);

	type3.Set(6.0, 5.7);
	value.Set(type3);
	answer.push(value);
	firststack.push(value);

	type1.Set(0);
	value.Set(type1);
	answer.push(value);
	firststack.push(value);


	type3.Set(0, 67);
	value.Set(type3);
	answer.push(value);
	secondstack.push(value);

	type2.Set(78.7);
	value.Set(type2);
	answer.push(value);
	secondstack.push(value);

	type3.Set(9.0, 0.45);
	value.Set(type3);
	answer.push(value);
	secondstack.push(value);

	firststack.concatenation(secondstack);

	cout << "\nОжидаемый результат\n";
	answer.displaystack();
	cout << "\nИтоговый результат\n";
	firststack.displaystack();

	Node* current_answer = answer.Get_top();
	Node* current_result = firststack.Get_top();
	for (int i = 0; i < 6; i++)
	{
		if (!(current_answer->Get_value() == current_result->Get_value()))
			return false;
		current_answer = current_answer->Get_next();
		current_result = current_result->Get_next();
	}
	return true;
}

bool test_extraction()
{
	Number<int> type1;
	Number <double> type2;
	Complex type3;
	Union value;
	Stack answer;


	Stack stack;

	type2.Set(0.78);
	value.Set(type2);
	stack.push(value);

	type3.Set(6.0, 5.7);
	value.Set(type3);
	answer.push(value);
	stack.push(value);

	type1.Set(0);
	value.Set(type1);
	answer.push(value);
	stack.push(value);

	type2.Set(9.2);
	value.Set(type2);
	stack.push(value);


	int IndexMin=1;
	int IndexMax=2;

	
	Stack result(stack.extraction(IndexMin, IndexMax));

	cout << "\nОжидаемый результат\n";
	answer.displaystack();
	cout << "\nИтоговый результат\n";
	result.displaystack();

	Node* current_answer = answer.Get_top();
	Node* current_result = result.Get_top();
	for (int i=IndexMin; i <=IndexMax; i++)
	{
		if (!(current_answer->Get_value() == current_result->Get_value()))
			return false;
		current_answer = current_answer->Get_next();
		current_result = current_result->Get_next();
	}
	return true;
}

bool test_search_first()
{
	Number<int> type1;
	Number <double> type2;
	Complex type3;
	Stack answer;
	Union value;

	Stack MainStack;
	Stack SearStack;

	type2.Set(0.78);
	value.Set(type2);
	MainStack.push(value);

	type3.Set(6.0, 5.7);
	value.Set(type3);
	MainStack.push(value);

	type1.Set(0);
	value.Set(type1);
	MainStack.push(value);


	type3.Set(0, 67);
	value.Set(type3);
	MainStack.push(value);

	type2.Set(78);
	value.Set(type2);
	SearStack.push(value);

	type3.Set(9.0, 0.45);
	value.Set(type3);
	SearStack.push(value);

	cout << "\nОжидаемый результат:false\n";

	cout << "\nИтоговый результат"<< (MainStack.search(SearStack))<<endl;


	return !(MainStack.search(SearStack));
}

bool test_search_second()
{
	Number<int> type1;
	Number <double> type2;
	Complex type3; 
	Union value;
	Stack answer;


	Stack MainStack;
	Stack SearStack;

	type2.Set(0.78);
	value.Set(type2);
	MainStack.push(value);

	type1.Set(0);
	value.Set(type1);
	MainStack.push(value);


	type3.Set(0, 67);
	value.Set(type3);
	MainStack.push(value);

	type3.Set(6.0, 5.7);
	value.Set(type3);
	MainStack.push(value);

	type1.Set(0);
	value.Set(type1);
	SearStack.push(value);


	type3.Set(0, 67);
	value.Set(type3);
	SearStack.push(value);

	cout << "\nОжидаемый результат:true\n";

	cout << "\nИтоговый результат:" << (MainStack.search(SearStack))<<endl;

	return MainStack.search(SearStack);
}

bool test_merge()
{
	Number<int> type1;
	Number <double> type2;
	Complex type3;
	Union value;
	Stack answer;


	Stack firststack;
	Stack secondstack;

	type3.Set(0, 67);
	value.Set(type3);
	answer.push(value);
	secondstack.push(value);

	type2.Set(0.78);
	value.Set(type2);
	answer.push(value);
	firststack.push(value);

	type3.Set(9.0, 0.45);
	value.Set(type3);
	answer.push(value);
	secondstack.push(value);

	type3.Set(6.0, 5.7);
	value.Set(type3);
	answer.push(value);
	firststack.push(value);

	type2.Set(78);
	value.Set(type2);
	answer.push(value);
	secondstack.push(value);

	type1.Set(0);
	value.Set(type1);
	answer.push(value);
	firststack.push(value);

	Stack result;
	result.merge(firststack, secondstack);

	cout << "\nОжидаемый результат\n";
	answer.displaystack();
	cout << "\nИтоговый результат\n";
	result.displaystack();

	Node* current_answer = answer.Get_top();
	Node* current_result = result.Get_top();
	for (int i = 0; i < 5; i++)
	{
		if (!(current_answer->Get_value() == current_result->Get_value()))
			return false;
		current_answer = current_answer->Get_next();
		current_result = current_result->Get_next();
	}
	return true;
}

bool test_separate()
{
	Number<int> type1;
	Number <double> type2;
	Complex type3;
	Union value;
	Stack answerComp;
	Stack answerReal;
	Stack stack;

	type2.Set(3.78);
	value.Set(type2);
	answerReal.push(value);
	stack.push(value);

	type2.Set(6.78);
	value.Set(type2);
	answerReal.push(value);
	stack.push(value);

	type3.Set(3.8,7.8);
	value.Set(type3);
	answerComp.push(value);
	stack.push(value);

	type3.Set(0.98,6.0);
	value.Set(type3);
	answerComp.push(value);
	stack.push(value);

	type1.Set(90);
	value.Set(type1);
	answerReal.push(value);
	stack.push(value);
	
	Stack RealStack;
	Stack ComplexStack;

	stack.separate(ComplexStack, RealStack);


	cout << "\nОжидаемый результат \n";
	answerComp.displaystack();
	cout << "\nИтоговый результат\n";
	ComplexStack.displaystack();

	cout << "\nОжидаемый результат\n";
	answerReal.displaystack();
	cout << "\nИтоговый результат\n";
	RealStack.displaystack();

	Node* current_answerComp = answerComp.Get_top();
	Node* current_Comp = ComplexStack.Get_top();
	for (int i = 0; i < 3; i++)
	{
		if (!(current_answerComp->Get_value() == current_Comp->Get_value()))
			return false;
		current_answerComp = current_answerComp->Get_next();
		current_Comp = current_Comp->Get_next();
	}

	Node* current_answerReal = answerReal.Get_top();
	Node* current_Real = RealStack.Get_top();
	for (int i = 0; i < 2; i++)
	{
		if (!(current_answerReal->Get_value() == current_Real->Get_value()))
			return false;
		current_answerReal = current_answerReal->Get_next();
		current_Real = current_Real->Get_next();
	}

	return true;
}

void test()
{
	cout << "\t\tТест программы:\n";
	cout << "\tФункция Map\n";
	if (test_map())
		cout << "Тест пройден\n";
	else
		cout << "Тест не пройден\n";

	cout << endl;
	cout << "\tФункция reduce\n";
	if (test_reduce())
		cout << "Тест пройден\n";
	else
		cout << "Тест не пройден\n";

	cout << endl;
	cout << "\tФункция where\n";
	if (test_where())
		cout << "Тест пройден\n";
	else
		cout << "Тест не пройден\n";

	cout << endl;
	cout << "\tФункция конкатенация\n";
	if (test_concatenation())
		cout << "Тест пройден\n";
	else
		cout << "Тест не пройден\n";

	cout << endl;
	cout << "\tФункция извлечение подпоследовательности по индексам\n";
	if (test_extraction())
		cout << "Тест пройден\n";
	else
		cout << "Тест не пройден\n";

	cout << "\tФункция поиск на вхождение подпоследовательности №1.\n";
	if (test_search_first())
		cout << "Тест пройден\n";
	else
		cout << "Тест не пройден\n";
	cout << endl;

	cout << "\tФункция поиск на вхождение подпоследовательности №2.\n";
	if (test_search_second())
		cout << "Тест пройден\n";
	else
		cout << "Тест не пройден\n";

	cout << endl;
	cout << "\tФункция слияние.\n";
	if (test_merge())
		cout << "Тест пройден\n";
	else
		cout << "Тест не пройден\n";

	cout << endl;
	cout << "\tФункция разделение.\n";
	if (test_separate())
		cout << "Тест пройден\n";
	else
		cout << "Тест не пройден\n";
}

