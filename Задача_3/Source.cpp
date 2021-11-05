#include <iostream>

using namespace std;

void PrintSquare(int number) // печать массива
{
	
	for (int i = 1; i <= 16; i++)
	{
		cout << (number & 1)<<" ";
		number >>= 1;                   // number= number >> 1 побитовый сдвиг 
		if (i % 4 == 0)
			cout << "\n";
		
	}
}


int OneCounts(int number)
{
	int counts{ 0 };

	//if (number & 1)
	//    counts++;

	for (int i = 0; i < 16; i++)
	{
		counts += (number & 1);
		number >>= 1;
	}
	return counts;
}

int main()
{	
	int n{}; // Выбор действия
	int cursellblack{}, cursquare{};

	setlocale(LC_ALL, "Rus");

	cout << "В квадрате 4Х4 каждую из 16 клеток покрасили в черный или белый цвет\n"
		 << "Затем в каждом из девяти квадратиков 2Х2, которые можно выделить в \n"
		 << "данном квадрате, \n"
		 << "подсчитали количество черных клеток. Получились числа 0,1,2,3,3,4,4,4,4.\n"
		 << "Сколько черных клеток может быть в большом квадрате? Укажите все варианты.\n";
	
	int userColors[5];
	cout << endl;
	cout << "Если вы хотите вручную задать количество клеток закрашенных\n" <<"черным в 9_ти квадоатах введите цифру 1\n";
	cin >> n;

	if(n==1)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "Введите количество квадратов с " << i << " закрашенными клетками в черный\n Максимальное количество  квадратов 9\n";
			cin >> userColors[i];
		}
	}
	else
	{
		userColors[0] = 1;
		userColors[1] = 1;
		userColors[2] = 1;
		userColors[3] = 2;
		userColors[4] = 4;
	}


	for (int number = 0; number < 65536; number++)
	{
		int mask{ 52224 };

		int currentColor[5]{};

		for (int i = 0; i < 9; i++)
		{
			int count = OneCounts(number & mask);
			currentColor[count]++;

			if ((i + 1) % 3)
				mask >>= 1;
			else
				mask >>= 2;
			
		}
		bool win{ true };

		for (int i = 0; i < 5; i++)
		{	
			win = win && (userColors[i] == currentColor[i]);
		}	
	    
		if (win)
		{
			PrintSquare(number);
			cout << "\n";
			cursquare++;
		}

	
	}

	
	cout << "Возможных решений  = "<< cursquare<<"\n";
	
	

	return 0;
}