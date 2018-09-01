#ifndef WAR_INTERFACE
#define WAR_INTERFACE

enum UNIT { INFANTRY = 1, CAVALRY, TANKS, PLANES };

public ref class MAP_WAR {
public:
	MAP_WAR() : width(20), height(20), sizeOfCell(30) {}
	inline void Draw(System::Windows::Forms::PaintEventArgs^);
	int getWidth() { return width; }
	int getHeight() { return height; }
	int getSizeOfCell() { return sizeOfCell; }
private:
	const int width;
	const int height;
	const int sizeOfCell;
};

public ref class GLOBAL_PLAYER_WAR {
public:
	GLOBAL_PLAYER_WAR() : currentUnit(INFANTRY), currentPlayer(1) {}
	void GlobalReset() { currentPlayer = INFANTRY, currentPlayer = 1; }
	void changeCurrentUnit(UNIT u) { currentUnit = u; }
	void changeCurrentUnit(int u) { if (u == 1) currentUnit = INFANTRY; if (u == 2) currentUnit = CAVALRY; if (u == 3) currentUnit = TANKS; if (u == 4) currentUnit = PLANES; };
	void changeCurrentPlayer(int p) { currentPlayer = p; }
	UNIT getCurrentUnit() { return currentUnit; }
	int getCurrentPlayer() { return currentPlayer; }
	inline void NextPlayer();
protected:
	UNIT currentUnit;
	int currentPlayer;
};

public ref class PLAYER_WAR : public GLOBAL_PLAYER_WAR {
public:
	PLAYER_WAR() : death(false), bot(false), infantry(4), cavalry(2), tanks(2), planes(1) {}
	void PlayerReset() { infantry = 4, cavalry = 2, tanks = 2, planes = 1; }
	void isDeath() { death = true; }
	void isNotDeath() { death = false; }
	bool getDeath() { return death; }
	void isBot() { bot = true; };
	void isNotBot() { bot = false; };
	bool getBot() { return bot; }
	inline void UpdateArmy(UNIT);
	int getInfantry() { return infantry; }
	int getCavalry() { return cavalry; }
	int getTanks() { return tanks; }
	int getPlanes() { return planes; }
	void setScore(int s) { score = s; };
	int getScore() { return score; }
private:
	bool death;
	bool bot;
	int infantry;
	int cavalry;
	int tanks;
	int planes;
	int score;
};

public ref class LOGIC_WAR : public GLOBAL_PLAYER_WAR {
public:
	inline LOGIC_WAR();
	inline ~LOGIC_WAR();
	inline void Reset();
	inline void setAmountBot(int);
	int getAmountBot() { return amountBot; }
	void StartGame() { startGame = true; }
	void GameOver() { startGame = false; }
	bool getStartGame() { return startGame; }
	inline void UpdateGameField(int, int);
	inline void UpdateGraphics(System::Windows::Forms::PaintEventArgs^, System::Windows::Forms::Button ^, System::Windows::Forms::Label ^, System::Windows::Forms::Panel ^, System::Windows::Forms::Label ^);
	inline bool AbilityStep(int, int);
	inline void setGlobalMap(int, int);
	inline void setTowerMap();
	inline void setInfantryMap();
	inline void setCavalryMap();
	inline void setTanksMap();
	inline void setPlanesMap();
	PLAYER_WAR ^getPlayers(int ind) { return PLAYERS[ind]; };
	MAP_WAR ^getMap() { return MAP; }

	inline void BOT_MIND();
private:
	System::Collections::Generic::List<PLAYER_WAR ^> PLAYERS;
	MAP_WAR ^MAP;
	int amountBot;
	int deathCount;
	bool startGame;
	cli::array<array<int>^> ^globalMap;
	cli::array<array<bool>^> ^towerMap;
	cli::array<array<bool>^> ^infantryMap;
	cli::array<array<bool>^> ^cavalryMap;
	cli::array<array<bool>^> ^tanksMap;
	cli::array<array<bool>^> ^planesMap;
};

#endif