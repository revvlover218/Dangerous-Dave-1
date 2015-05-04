//Object IDs
enum IDS{ PLAYER, BULLET, ENEMY };

//Key ID
enum KEYS{ UP, DOWN, LEFT, RIGHT };

//Our Player
class Dave
{

private:
	int ID;
	int x;
	int y;
	int lives;
	int boundx;
	int boundy;
	int score;
	
public:
	//prototypes
	void InitDave(Dave &man);
	void DrawDave(Dave &man);
	void MoveDave(int, int, int, int, Dave &man);
};

class Level
{

public:
	void displayFont(const int&, const int&); //display font at the top and bottom of the screen
	void walls(const int&, const int&); //display the walls of the screen



};