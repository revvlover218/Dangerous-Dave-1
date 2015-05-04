//Object IDs
enum IDS{ PLAYER, BULLET, ENEMY };

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
};

class TextAppearance		//Display Top and Bottom Text
{
public:

	void displayFont(const int&, const int&);
private:

};

class Walls
{
public:

	void topBottom(const int&, const int&);

};