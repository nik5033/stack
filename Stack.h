#include "Node.h"

Union Plus_Ten_Real(Union);
bool ImageExist(Union number);
Union ModCompare(Union, Union);

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
};

int enter_Index_min();
int enter_Index_Max(int indexmin);