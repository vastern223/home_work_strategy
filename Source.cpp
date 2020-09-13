#include<iostream>
#include<string>
#include <conio.h>
#include <ctime>
using namespace std;

class Motion
{
protected:

	int step;

public:

	virtual int Move()=0;
};


class Motion_plus_7 : public Motion
{

public:
	Motion_plus_7()
	{
		step = 7;
	}

	int Move()
	{
		return step;

	}
};


class Motion_plus_4 : public Motion
{

public:
	Motion_plus_4()
	{
		step = 4;
	}

	int Move()
	{
		return step;

	}
};

class Motion_plus_2 : public Motion
{

public:
	Motion_plus_2()
	{
		step = 2;
	}

	int Move()
	{
		return step;

	}
};



class Motion_minus_1 : public Motion
{

public:
	Motion_minus_1()
	{
		step = -1;
	}

	int Move()
	{
		return step;

	}
};

class Motion_minus_3 : public Motion
{

public:
	Motion_minus_3()
	{
		step = -3;
	}

	int Move()
	{
		return step;

	}
};

class Motion_minus_6 : public Motion
{

public:
	Motion_minus_6()
	{
		step = -6;
	}

	int Move()
	{
		return step;

	}
};



class Game_of_gates
{
private:
	Motion* motion;
	int size_maps;
	char** maps;
	//coordinates of the player
	int x = 0;
	int y = 1;
	//
	bool exit = false;

public:

	Game_of_gates()
	{
		motion = new Motion_plus_2;

		size_maps = 19;

		maps = new char* [size_maps];

		for (int i = 0; i < size_maps; i++)
		{
			maps[i] = new char[size_maps];
		}	

	}

	void Creating_map()
	{
		int rnd;

		for (int i = 0; i < size_maps; i++)
		{
			rnd = rand() % (size_maps - 3) + 1;

			for (int j = 0; j < size_maps; j++)
			{

				if (i % 5 == 0 && i != 0)
				{
					if (j != rnd && j != rnd + 1)
					{
						maps[i][j] = '|';
					}
					else
					{
						maps[i][j] = '-';
					}
				}

				else
				{
					maps[i][j] = '-';
				}
				if (j == 0 || j == size_maps - 1)
				{
					maps[i][j] = '|';
				}

			}
		}
	}

	void Move_player()
	{
		y += motion->Move();	
	}

	void Defeat_check()
	{
		if (maps[x][y] == '|' || y<0 || y > size_maps-1)
		{
			system("cls");
			cout << "you lost by hitting the wall" << endl;
			exit = true;
			system("pause");
		}
		else if (x == size_maps - 1)
		{
			system("cls");
			cout << "you won congratulations " << endl;
			exit = true;
			system("pause");
		}
	}

	void Show_maps()
	{
		Defeat_check();

		if (exit == true)return;

		for (int i = 0; i < size_maps; i++)
		{
			for (int j = 0; j < size_maps; j++)
			{
				if (x == i && y == j)
				{
					maps[x][y] = '+';
				}
				cout << maps[i][j];
			}
			cout << endl;
		}
	}

	void Game()
	{
		Creating_map();

		while (exit != true)
		{
			int choice = 0;
			system("cls");
			Show_maps();
			if (exit == true)return;

			cout << "\n 1-make a move" << endl;
			cout << " 2- strategy +7 steps" << endl;
			cout << " 3- strategy +4 steps" << endl;
			cout << " 4- strategy +2 steps" << endl;
			cout << " 5- strategy -1 steps" << endl;
			cout << " 6- strategy -3 steps" << endl;
			cout << " 7- strategy -6 steps" << endl;
			cout << " 8- exit" << endl;
			cout << "->";
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				maps[x][y] = '-';
				Move_player();
				x++;

			}
			break;

			case 2:
			{
				delete motion;
				motion = new Motion_plus_7;

			}
			break;
			case 3:
			{
				delete motion;
				motion = new Motion_plus_4;
			}
			break;
			case 4:
			{
				delete motion;
				motion = new Motion_plus_2;
			}
			break;
			case 5:
			{
				delete motion;
				motion = new Motion_minus_1;

			}
			break;
			case 6:
			{
				delete motion;
				motion = new Motion_minus_3;
			}
			break;
			case 7:
			{
				delete motion;
				motion = new Motion_minus_6;
			}
			break;
			case 8:
			{
				exit = true;
				system("cls");
			}
			break;
			}
		} 
	}

	~Game_of_gates() 
	{
		delete motion; 
	
		for (int i = 0; i < size_maps; i++)
		{
			delete[]  maps[i];
		}
		delete[]  maps;

	}



};


int main()
{
	srand(time(NULL));
	Game_of_gates gg;
	gg.Game();
	return 0;
}