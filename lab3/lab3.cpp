#include <iostream>
#include <cstring>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS

//struct node* front = NULL, * rear = NULL; // указатели на начало и конец очереди
struct node* head = NULL; //указатель на вершину
void spstore(void), review(void), del(void);

//struct node* find(char* name); // функция нахождения элемента

struct node
{
	char inf[256];  // полезная информация
	//int priority;
	struct node* next; // ссылка на следующий элемент 
};

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
    scanf("%s", s);
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);
	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в стек элемента */
void spstore(void)
{
	struct node* p = NULL;
	p = get_struct();

	if (p == NULL) return;
	p->next = head; //добавили на вершину
	head = p;//подвинули указатель 

	//if (front == NULL) {  // если очередь пуста
	//	front = rear = p;  // новый элемент становится и началом, и концом очереди
	//}
	//else {
	//	rear->next = p;
	//	rear = p;
	//}
	return;
}

/* Просмотр содержимого стека. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
		return;
	}
	while (struc)
	{
		printf("Имя - %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}

///* Поиск элемента по содержимому. */
//struct node* find(char* name)
//{
//	struct node* struc = head;
//	if (head == NULL)
//	{
//		printf("Список пуст\n");
//	}
//	while (struc)
//	{
//		if (strcmp(name, struc->inf) == 0)
//		{
//			return struc;
//		}
//		struc = struc->next;
//	}
//	printf("Элемент не найден\n");
//	return NULL;
//}

/* Удаление элемента. */
void del(void)
{
	if (head == NULL) {
		printf("Стек пуст\n");
		return;
	}

	struct node* temp = head;  // временный указатель на вершину
	head = head->next;  // сдвигаем указатель на след элемент

	printf("Удален элемент: %s\n", temp->inf);
	free(temp);  //удаляем
}

int main()
{
	setlocale(LC_ALL, "rus");
	char s[10];

	spstore();
	spstore();
	review();
	del();
	review();
	/*scanf("%s", s);
	//f = find(s);
	//printf("\n Найденный элемент %s \n", f -> inf);*/

	return 0; 
}
