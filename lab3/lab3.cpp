﻿#include <iostream>
#include <cstring>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;

// Функции добавления элемента, просмотра списка
void spstore(void), review(void), del(char* name);
struct node* find(char* name); // функция нахождения элемента

struct node
{
	char inf[256];  // полезная информация
	int priority;
	struct node* next; // ссылка на следующий элемент 
};

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];
	int prior = 0;

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	scanf("%s", s);
	printf("Введите приоритет: ");
	scanf("%d", &prior);
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);
	p->priority = prior;
	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента (в конец)*/
void spstore(void)
{
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL || head->priority < p->priority)	// если списка нет, то устанавливаем голову списка
	{
		p->next = head;
		head = p;
		/*head = p;
		last = p;*/
	}
	else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец
	{
		for (struct node* i = head; i != NULL; i = i->next) {
			if (i->next) {
				if (i->next->priority < p->priority) {
					p->next = i->next;
					i->next = p;
					break;
				}
			}
			else
			{
				i->next = p;
				last = p;
				break;
			}
		}

		/*last->next = p;
		last = p;*/
	}
	return;
}

/* Просмотр содержимого списка. */
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
		printf("Имя - %s,%d", struc->inf, struc -> priority);
		struc = struc->next;
	}
	return;
}

/* Поиск элемента по содержимому. */
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	printf("Элемент не найден\n");
	return NULL;
}

/* Удаление элемента по содержимому. */
void del(char* name)
{
	struct node* struc = head; // указатель, проходящий по списку установлен на начало списка
	struct node* prev = NULL;// указатель на предшествующий удаляемому элемент
	int flag = 0;      // индикатор отсутствия удаляемого элемента в списке

	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		printf("Список пуст\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0) // если удаляемый элемент - первый
	{
		flag = 1;
		head = struc->next; // установливаем голову на следующий элемент
		free(struc);  // удаляем первый элемент
		struc = head; // устанавливаем указатель для продолжения поиска
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}

	while (struc) // проход по списку и поиск удаляемого элемента
	{
		if (strcmp(name, struc->inf) == 0) // если нашли, то
		{
			flag = 1;         // выставляем индикатор
			if (struc->next)  // если найденный элемент не последний в списке
			{
				prev->next = struc->next; // меняем указатели
				free(struc);		    // удаляем  элемент
				struc = prev->next; // устанавливаем указатель для продолжения поиска
			}
			else			// если найденный элемент последний в списке
			{
				prev->next = NULL; // обнуляем указатель предшествующего элемента
				free(struc);	// удаляем  элемент
				return;
			}
		}
		else // если не нашли, то
		{
			prev = struc; // устанавливаем указатели для продолжения поиска
			struc = struc->next;
		}
	}

	if (flag == 0)				// если флаг = 0, значит нужный элемент не найден
	{
		printf("Элемент не найден\n");
		return;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	char s[10];

	spstore();
	review();
	spstore();
	review();

	/*scanf("%s", s);
	f = find(s);
	printf("\n Найденный элемент %s \n", f->inf);*/

	return 0;
}
