#include<iostream> 
#include<cstring>

using namespace std;

class Position   
{
public:
         int x;
         int y;
};

class Robot 
{
public:
         Robot();                 /* default constructor, initialize at (0,0) */
         Robot(Position pos);     /* initialize at pos */
         void Move(char Dir);     /* Dir could be 'a', 's', 'd', 'w', for other characters, the robot don¡¯t move */
         Position GetPosition();  /* return current position */

private:
         Position currentPos;
};

Robot::Robot()
{
	currentPos.x=0; 
	currentPos.y=0;
}

Robot::Robot(Position pos)
{
	currentPos.x=pos.x;
	currentPos.y=pos.y;
}

void Robot::Move(char Dir)
{
	if(Dir=='w')  currentPos.x=currentPos.x-1;
	if(Dir=='a')  currentPos.y=currentPos.y-1;
	if(Dir=='s')  currentPos.x=currentPos.x+1;
	if(Dir=='d')  currentPos.y=currentPos.y+1;
}

Position Robot::GetPosition()
{
	return currentPos;
}


int main() 
{
    

	//while (1)
	//{
	    char char_map[12][27];
		string insert_title = "welcome";
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 27; j++)
			{
				if (i == 0 || i == 11 || j == 0 || j == 26)
					char_map[i][j] = '*';
				else if (i == 1 && j >= 10 && j <= 16)
					char_map[i][j] = insert_title[j-10];
				else
					char_map[i][j] = ' ';
			}
		}

		Position position_c;
		position_c.x = 5;
		position_c.y = 5;
		Robot robot_b(position_c);

		char_map[robot_b.GetPosition().x][robot_b.GetPosition().y] = '*';
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 27; j++)
				cout << char_map[i][j];
			cout << endl;
		}
	
		char dirt;
		while (cin >> dirt)
		{
			system("cls");
			robot_b.Move(dirt);
			char_map[robot_b.GetPosition().x][robot_b.GetPosition().y] = '*';
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 27; j++)
					cout << char_map[i][j];
				cout << endl;
			}

			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 27; j++)
				{
					if (i == 0 || i == 11 || j == 0 || j == 26)
						char_map[i][j] = '*';
					else if (i == 1 && j >= 10 && j <= 16)
						char_map[i][j] = insert_title[j - 10];
					else
						char_map[i][j] = ' ';
				}
			}


		}
		
			
	//}

	cin.get();
    return 0;
}
 
