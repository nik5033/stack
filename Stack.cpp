#include "Node.h"
#include <iostream>

using namespace std;

class Stack
{
private:
	int size;
	Node* top;
public:
	Stack(const Stack &other);
	Stack();
	~Stack();
	Node* Get_top();
	void push(Union value);
	Union pop();
	void displaystack();
	void Enter();//ввод элементов стека
	Stack extraction(int, int);//извлечение подпоследовательности
	void concatenation(Stack&);//слияние
	void merge(Stack &First, Stack &Second);
	bool search(Stack &other);
	Stack Map(Union(*Function)(Union));
	void separate(Stack &First, Stack &Second);
	Stack Where(bool(*Function)(Union));
	Stack Reduce(Union(*Function)(Union, Union), Union C);
	int enter_Index_min();
	int enter_Index_Max(int indexmin);
};

Stack::Stack(const Stack &other)
{
	Node* current = other.top;
	while (current->next != nullptr)
	{
		push(current->value);
		current = current->next;
	}
}

Stack::Stack()
{
	size = 0;
	top = nullptr;
}
Stack::~Stack()
{
	while (top != nullptr)
	{
		Node* toDelete = top;
		top = top->next;
		delete toDelete;
	}
}

Node* Stack::Get_top()
{
	return top;
}
void Stack::push(Union value)//добавление элемента
{
	if (size == 0)
	{
		top = new Node(value);
	}
	Node* newTop = new Node(value);
	newTop->next = top;
	top = newTop;
	size++;
}
Union Stack::pop()//удаление
{
	Node* oldtop = top;
	top = top->next;
	Union oldtopdata = oldtop->value;
	delete(oldtop);
	--size;
	return oldtopdata;
}
void Stack::displaystack()//показ элементов на экране
{
	Node* current = top;
	while (current->next != nullptr)
	{
		current->value.Show(); cout << endl;
		current = current->next;
	}
}

Stack Stack::extraction(int indexmin, int indexmax)//извлечение
{
	int count = this->size;
	Stack sequence;
	Node* current = top;
	for (int i = 0; i < count; i++)
	{
		if (i >= indexmin && i <= indexmax)
			sequence.push(pop());
		else
			pop();
	}
	return sequence;
}
void Stack::Enter()//ввод
{
	int size;
	while (true)
	{
		cout << "Введите размер стека:";
		cin >> size;
		if (!cin)
		{
			cout << "Ошибка!!! Повторите ввод\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		Union number;
		number.Enter();
		push(number);
	}
}
void Stack::concatenation(Stack &Second)//конкатенация
{
	Stack temp;
	while (Second.size != 0)
		temp.push(Second.pop());
	while (temp.size != 0)
		push(temp.pop());
}
void Stack::merge(Stack &First, Stack &Second)//слияние
{
	Stack current;

	for (int i = 0; First.size != 0 && Second.size != 0; i++)
	{
		if (i % 2 == 0)
			current.push(First.pop());
		else
			current.push(Second.pop());
	}
	if (First.size != 0)
		while (First.size != 0)
			current.push(First.pop());
	else
		while (Second.size != 0)
			current.push(Second.pop());
	while (current.size != 0)
		push(current.pop());
}
bool Stack::search(Stack &other)//поиск
{
	if (this->size < other.size)
		return false;
	Node* main = this->top;
	for (int i = 0; i < this->size - other.size; i++)
	{
		Node *currentmain = main;
		Node *currentother = other.top;
		for (int j = 0; j < other.size + 1; j++)
		{
			if (currentother->next == nullptr)
				return true;
			if (!(currentmain->value == currentother->value))
				break;
			currentmain = currentmain->next;
			currentother = currentother->next;
		}
		main = main->next;
	}
	return false;
}
void Stack::separate(Stack &Complex, Stack &Real)//разделение
{
	Stack Complextemp;
	Stack Realtemp;
	while (this->size != 0)
	{
		if (top->value.Get_Flag() == 3)
			Complextemp.push(pop());
		else
			Realtemp.push(pop());
	}
	while (Complextemp.size != 0)
		Complex.push(Complextemp.pop());
	while (Realtemp.size != 0)
		Real.push(Realtemp.pop());
}
Stack Stack::Map(Union(*Function)(Union))
{
	Stack newStack;
	Node*current = top;
	while (current->next != nullptr)
	{
		newStack.push((Function((current->value))));
		current = current->next;
	}
	return newStack;
}
Stack Stack::Where(bool(*Function)(Union))
{
	Stack newStack;
	Node*current = top;
	while (current->next != nullptr)
	{
		if (Function(current->value))
			newStack.push(current->value);
		current = current->next;
	}
	return newStack;
}

Stack Stack::Reduce(Union(*Function)(Union, Union), Union constant)
{
	Stack newStack;
	Node*current = top;
	Union result = Function(current->value, constant);
	while (current->next != nullptr)
	{
		current = current->next;
		Union tim = Function(current->value, result);
		result = tim;
	}
	newStack.push(result);
	return newStack;
}
int enter_Index_min()
{
	int IndexMin;
	while (true)
	{
		cout << "\nПервый индекс:";
		cin >> IndexMin;
		if (!cin)
		{
			cout << "Ошибка!!! Повторите ввод\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	return IndexMin;
}

int enter_Index_Max(int indexmin)
{
	int IndexMax;
	while (true)
	{
		cout << "\nВторой индекс:";
		cin >> IndexMax;
		if (!cin || IndexMax <= indexmin)
		{
			cout << "Ошибка!!! Повторите ввод\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	return IndexMax;
}

//функция для map
Union Plus_Ten_Real(Union number)
{
	Union newnum;

	switch (number.Get_Flag())
	{
	case 1:
	{
		Number<double> Add;
		Add.Set(number.Get1().Get_Real() + 10);
		newnum.Set(Add);
		break;
	}
	case 2:
	{
		Number<int> Add;
		Add.Set(number.Get2().Get_Real() + 10);
		newnum.Set(Add);
		break;
	}
	case 3:
	{
		Complex Add;
		Add.Set(number.Get3().Get_Real() + 10, number.Get3().Get_Im());
		newnum.Set(Add);
		break;
	}
	}
	return newnum;
}

//функция для where
bool ImageExist(Union number)
{
	switch (number.Get_Flag())
	{
	case 1:
		return true;
	case 2:
		return true;
	case 3:
		return false;
	}
}

//функция для reduce
Union ModCompare(Union First, Union Second)
{
	if (First.Module() > Second.Module())
		return First;
	else
		return Second;
}
