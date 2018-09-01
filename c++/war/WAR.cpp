#include "WAR_INTERFACE.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
// MAP

void MAP_WAR::Draw(System::Windows::Forms::PaintEventArgs^  e) {
	System::Drawing::Graphics ^g = e->Graphics;
	System::Drawing::Pen ^p = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			g->DrawRectangle(p, sizeOfCell * j, sizeOfCell * i, sizeOfCell, sizeOfCell);
}

// GLOBAL

void GLOBAL_PLAYER_WAR::NextPlayer() {
	if (currentPlayer < 4) currentPlayer++;
	else currentPlayer = 1;
}

//PLAYER

void PLAYER_WAR::UpdateArmy(UNIT curUn) {
	if (curUn == INFANTRY) {
		if (infantry > 0) infantry--;
		else
			if (cavalry > 0) cavalry = 0;
			else if (tanks > 0) tanks = 0;
			else if (planes > 0) planes = 0;
	}
	if (curUn == CAVALRY) {
		if (cavalry > 0) cavalry--;
		else {
			if (tanks > 0) tanks = 0;
			else if (planes > 0) planes = 0;
			else if (infantry > 0) infantry = 0;
		}
	}
	if (curUn == TANKS) {
		if (tanks > 0) tanks--;
		else {
			if (planes > 0) planes = 0;
			else if (infantry > 0) infantry = 0;
			else if (cavalry > 0) cavalry = 0;
		}
	}
	if (curUn == PLANES) {
		if (planes > 0) planes--;
		else {
			if (infantry > 0) infantry = 0;
			else if (cavalry > 0) cavalry = 0;
			else if (tanks > 0) tanks = 0;
		}
	}
}

//LOGIC

LOGIC_WAR::LOGIC_WAR() {
	MAP = gcnew MAP_WAR();
	for (int i = 0; i < 4; i++) PLAYERS.Add(gcnew PLAYER_WAR());
	globalMap = gcnew cli::array<array<int> ^>(MAP->getHeight());
	towerMap = gcnew cli::array<array<bool> ^>(MAP->getHeight());
	infantryMap = gcnew cli::array<array<bool> ^>(MAP->getHeight());
	cavalryMap = gcnew cli::array<array<bool> ^>(MAP->getHeight());
	tanksMap = gcnew cli::array<array<bool> ^>(MAP->getHeight());
	planesMap = gcnew cli::array<array<bool> ^>(MAP->getHeight());
	for (int i = 0; i < MAP->getHeight(); i++) {
		globalMap[i] = gcnew cli::array<int>(MAP->getWidth());
		towerMap[i] = gcnew cli::array<bool>(MAP->getWidth());
		infantryMap[i] = gcnew cli::array<bool>(MAP->getWidth());
		cavalryMap[i] = gcnew cli::array<bool>(MAP->getWidth());
		tanksMap[i] = gcnew cli::array<bool>(MAP->getWidth());
		planesMap[i] = gcnew cli::array<bool>(MAP->getWidth());
		for (int j = 0; j < MAP->getWidth(); j++) {
			globalMap[i][j] = 0;
			towerMap[i][j] = false;
			infantryMap[i][j] = false;
			cavalryMap[i][j] = false;
			tanksMap[i][j] = false;
			planesMap[i][j] = false;
		}
	}
	for (int i = 0; i < MAP->getHeight(); i++) {
		for (int j = 0; j < MAP->getWidth(); j++) {
			if (i == 0 && j == 0) globalMap[i][j] = 10;
			else if (i == 0 && j == MAP->getWidth() - 1) globalMap[i][j] = 20;
			else if (i == MAP->getHeight() - 1 && j == 0) globalMap[i][j] = 30;
			else if (i == MAP->getHeight() - 1 && j == MAP->getWidth() - 1) globalMap[i][j] = 40;
			else globalMap[i][j] = 0;
		}
	}
	amountBot = 0;
	startGame = false;
}

LOGIC_WAR::~LOGIC_WAR() {
	delete MAP;
}

void LOGIC_WAR::Reset() {
	GlobalReset();
	deathCount = 0;
	amountBot = 0;
	for (int i = 0; i < 4; i++) {
		PLAYERS[i]->isNotBot();
		PLAYERS[i]->isNotDeath();
		PLAYERS[i]->setScore(0);
		PLAYERS[i]->PlayerReset();
	}
	for (int i = 0; i < MAP->getHeight(); i++) {
		for (int j = 0; j < MAP->getWidth(); j++) {
			if (i == 0 && j == 0) globalMap[i][j] = 10;
			else if (i == 0 && j == MAP->getWidth() - 1) globalMap[i][j] = 20;
			else if (i == MAP->getHeight() - 1 && j == 0) globalMap[i][j] = 30;
			else if (i == MAP->getHeight() - 1 && j == MAP->getWidth() - 1) globalMap[i][j] = 40;
			else globalMap[i][j] = 0;
			towerMap[i][j] = false;
			infantryMap[i][j] = false;
			cavalryMap[i][j] = false;
			tanksMap[i][j] = false;
			planesMap[i][j] = false;
		}
	}
}

void LOGIC_WAR::setAmountBot(int b) {
	amountBot = b;
	if (amountBot == 1)
		PLAYERS[1]->isBot();
	else if (amountBot == 2) {
		PLAYERS[1]->isBot();
		PLAYERS[2]->isBot();
	}
	else if (amountBot == 3) {
		PLAYERS[1]->isBot();
		PLAYERS[2]->isBot();
		PLAYERS[3]->isBot();
	}
	else if (amountBot == 4) {
		PLAYERS[0]->isBot();
		PLAYERS[1]->isBot();
		PLAYERS[2]->isBot();
		PLAYERS[3]->isBot();
	}
}

void LOGIC_WAR::UpdateGameField(int x, int y) {
	deathCount = 0;
	for (int i = 0; i < 4; i++)
		if (PLAYERS[i]->getDeath()) deathCount++;

	if (deathCount != 3 && getStartGame()) {
		if (!PLAYERS[currentPlayer - 1]->getBot()) {
			if (AbilityStep(x, y))
				setGlobalMap(x, y);
		}
		else
			while (PLAYERS[currentPlayer - 1]->getInfantry() +
				PLAYERS[currentPlayer - 1]->getCavalry() +
				PLAYERS[currentPlayer - 1]->getTanks() +
				PLAYERS[currentPlayer - 1]->getPlanes() != 0)
				BOT_MIND();
	}
	else if (deathCount == 3) {
		GameOver();
	}
}

void LOGIC_WAR::UpdateGraphics(System::Windows::Forms::PaintEventArgs^  e, System::Windows::Forms::Button ^check, System::Windows::Forms::Label ^l, System::Windows::Forms::Panel ^pa, System::Windows::Forms::Label ^cl) {
	System::Drawing::Graphics ^g = e->Graphics;
	System::Drawing::Pen ^p = gcnew System::Drawing::Pen(System::Drawing::Color::Black);

	if (PLAYERS[currentPlayer - 1]->getInfantry() +
		PLAYERS[currentPlayer - 1]->getCavalry() +
		PLAYERS[currentPlayer - 1]->getTanks() +
		PLAYERS[currentPlayer - 1]->getPlanes() == 0) {
		PLAYERS[currentPlayer - 1]->PlayerReset();
		NextPlayer();
	}

	while (PLAYERS[currentPlayer - 1]->getDeath())
		NextPlayer();

	if (currentPlayer == 1) check->BackColor = System::Drawing::Color::Red;
	if (currentPlayer == 2) check->BackColor = System::Drawing::Color::Blue;
	if (currentPlayer == 3) check->BackColor = System::Drawing::Color::Fuchsia;
	if (currentPlayer == 4) check->BackColor = System::Drawing::Color::Green;

	if (deathCount == 3) {
		l->Text = "Победил игрок: ";
		pa->Size = System::Drawing::Size(601, 601);
		cl->Location = System::Drawing::Point(150, 170);
		cl->Text = "Score\r\n\n" +
			"Red: " + System::Convert::ToSingle(PLAYERS[0]->getScore()) + "\r\n" +
			"Blue: " + System::Convert::ToSingle(PLAYERS[1]->getScore()) + "\r\n" +
			"Fuchsia: " + System::Convert::ToSingle(PLAYERS[2]->getScore()) + "\r\n" +
			"Green: " + System::Convert::ToSingle(PLAYERS[3]->getScore());
		for (int i = 0; i < 4; i++)
			if (PLAYERS[i]->getDeath() == false)
				if (i == 0) check->BackColor = System::Drawing::Color::Red;
				else if (i == 1) check->BackColor = System::Drawing::Color::Blue;
				else if (i == 2) check->BackColor = System::Drawing::Color::Fuchsia;
				else if (i == 3) check->BackColor = System::Drawing::Color::Green;
	}

	System::Drawing::Brush ^b;
	b = System::Drawing::Brushes::Black;

	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++) {
			if (globalMap[i][j] / 10 == 1) b = System::Drawing::Brushes::Red;
			if (globalMap[i][j] / 10 == 2) b = System::Drawing::Brushes::Blue;
			if (globalMap[i][j] / 10 == 3) b = System::Drawing::Brushes::Fuchsia;
			if (globalMap[i][j] / 10 == 4) b = System::Drawing::Brushes::Green;
			if (globalMap[i][j] / 100 != 0) b = System::Drawing::Brushes::Black;
			if (globalMap[i][j] / 100 == 1 || (globalMap[i][j] / 100 == 0 && globalMap[i][j] % 10 == 0 && globalMap[i][j] / 10 == 1))
				g->FillRectangle(System::Drawing::Brushes::Red, MAP->getSizeOfCell() * j, MAP->getSizeOfCell() * i, MAP->getSizeOfCell(), MAP->getSizeOfCell());
			if (globalMap[i][j] / 100 == 2 || (globalMap[i][j] / 100 == 0 && globalMap[i][j] % 10 == 0 && globalMap[i][j] / 10 == 2))
				g->FillRectangle(System::Drawing::Brushes::Blue, MAP->getSizeOfCell() * j, MAP->getSizeOfCell() * i, MAP->getSizeOfCell(), MAP->getSizeOfCell());
			if (globalMap[i][j] / 100 == 3 || (globalMap[i][j] / 100 == 0 && globalMap[i][j] % 10 == 0 && globalMap[i][j] / 10 == 3))
				g->FillRectangle(System::Drawing::Brushes::Fuchsia, MAP->getSizeOfCell() * j, MAP->getSizeOfCell() * i, MAP->getSizeOfCell(), MAP->getSizeOfCell());
			if (globalMap[i][j] / 100 == 4 || (globalMap[i][j] / 100 == 0 && globalMap[i][j] % 10 == 0 && globalMap[i][j] / 10 == 4))
				g->FillRectangle(System::Drawing::Brushes::Green, MAP->getSizeOfCell() * j, MAP->getSizeOfCell() * i, MAP->getSizeOfCell(), MAP->getSizeOfCell());
			if (globalMap[i][j] == -10)
				g->FillRectangle(System::Drawing::Brushes::Black, MAP->getSizeOfCell() * j, MAP->getSizeOfCell() * i, MAP->getSizeOfCell(), MAP->getSizeOfCell());
			if (globalMap[i][j] % 10 == 0 && globalMap[i][j] != 0)
				g->DrawString("Г", gcnew System::Drawing::Font("Microsoft Sans Serif", (float)7.2), System::Drawing::Brushes::Black, System::Drawing::PointF(MAP->getSizeOfCell() * j + (float)MAP->getSizeOfCell() / 4, MAP->getSizeOfCell() * i + (float)MAP->getSizeOfCell() / 4));
			if (globalMap[i][j] % 10 == 1 || globalMap[i][j] % 100 % 10 == 1)
				g->DrawString("П", gcnew System::Drawing::Font("Microsoft Sans Serif", (float)7.2), b, System::Drawing::PointF(MAP->getSizeOfCell() * j + (float)MAP->getSizeOfCell() / 4, MAP->getSizeOfCell() * i + (float)MAP->getSizeOfCell() / 4));
			if (globalMap[i][j] % 10 == 2 || globalMap[i][j] % 100 % 10 == 2)
				g->DrawString("К", gcnew System::Drawing::Font("Microsoft Sans Serif", (float)7.2), b, System::Drawing::PointF(MAP->getSizeOfCell() * j + (float)MAP->getSizeOfCell() / 4, MAP->getSizeOfCell() * i + (float)MAP->getSizeOfCell() / 4));
			if (globalMap[i][j] % 10 == 3 || globalMap[i][j] % 100 % 10 == 3)
				g->DrawString("Т", gcnew System::Drawing::Font("Microsoft Sans Serif", (float)7.2), b, System::Drawing::PointF(MAP->getSizeOfCell() * j + (float)MAP->getSizeOfCell() / 4, MAP->getSizeOfCell() * i + (float)MAP->getSizeOfCell() / 4));
			if (globalMap[i][j] % 10 == 4 || globalMap[i][j] % 100 % 10 == 4)
				g->DrawString("С", gcnew System::Drawing::Font("Microsoft Sans Serif", (float)7.2), b, System::Drawing::PointF(MAP->getSizeOfCell() * j + (float)MAP->getSizeOfCell() / 4, MAP->getSizeOfCell() * i + (float)MAP->getSizeOfCell() / 4));
		}
}

bool LOGIC_WAR::AbilityStep(int x, int y) {
	if (globalMap[y][x] / 10 == currentPlayer || globalMap[y][x] < 0) return false;
	if (globalMap[y][x] / 100 != 0) return false;
	if (PLAYERS[currentPlayer - 1]->getInfantry() +
		PLAYERS[currentPlayer - 1]->getCavalry() +
		PLAYERS[currentPlayer - 1]->getTanks() +
		PLAYERS[currentPlayer - 1]->getPlanes() == 0)
		return false;
	if (currentUnit == INFANTRY) {
		setInfantryMap();
		if (infantryMap[y][x]) return true;
	}
	else if (currentUnit == CAVALRY) {
		setCavalryMap();
		if (cavalryMap[y][x]) return true;
	}
	else if (currentUnit == TANKS) {
		setTanksMap();
		if (tanksMap[y][x]) return true;
	}
	else if (currentUnit == PLANES) {
		setPlanesMap();
		if (planesMap[y][x]) return true;
	}
	setTowerMap();
	if (towerMap[y][x]) return true;
	return false;
}

void LOGIC_WAR::setGlobalMap(int x, int y) {
	PLAYERS[currentPlayer - 1]->UpdateArmy(currentUnit);
	if (globalMap[y][x] == 0 && globalMap[y][x] >= 0)
		globalMap[y][x] = currentPlayer * 10 + currentUnit;
	else if (globalMap[y][x] >= 0 && globalMap[y][x] / 100 == 0) {
		if (globalMap[y][x] % 10 == 0) PLAYERS[currentPlayer - 1]->setScore(PLAYERS[currentPlayer - 1]->getScore() + 100);
		if (globalMap[y][x] % 10 == 1) PLAYERS[currentPlayer - 1]->setScore(PLAYERS[currentPlayer - 1]->getScore() + 1);
		if (globalMap[y][x] % 10 == 2) PLAYERS[currentPlayer - 1]->setScore(PLAYERS[currentPlayer - 1]->getScore() + 2);
		if (globalMap[y][x] % 10 == 3) PLAYERS[currentPlayer - 1]->setScore(PLAYERS[currentPlayer - 1]->getScore() + 3);
		if (globalMap[y][x] % 10 == 4) PLAYERS[currentPlayer - 1]->setScore(PLAYERS[currentPlayer - 1]->getScore() + 4);
		globalMap[y][x] += 100 * currentPlayer;
	}

	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++)
			if (globalMap[i][j] / 100 != 0 && globalMap[i][j] % 10 == 0)
				PLAYERS[(globalMap[i][j] % 100) / 10 - 1]->isDeath();

	for (int count = 0; count < 4; count++)
		if (PLAYERS[count]->getDeath())
			for (int i = 0; i < MAP->getHeight(); i++)
				for (int j = 0; j < MAP->getWidth(); j++)
					if (globalMap[i][j] / 100 == count + 1 || globalMap[i][j] / 10 == count + 1 || globalMap[i][j] % 100 == (count + 1) * 10)
						globalMap[i][j] = -10;
}

void LOGIC_WAR::setTowerMap() {
	int dethCount = 0;
	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++) {
			if (globalMap[i][j] / 100 == currentPlayer) dethCount++;
			towerMap[i][j] = false;
		}

	setInfantryMap();
	setCavalryMap();
	setTanksMap();
	setPlanesMap();

	for (int count = 0; count < dethCount; count++)
		for (int i = 0; i < MAP->getHeight(); i++)
			for (int j = 0; j < MAP->getWidth(); j++)
				if (globalMap[i][j] / 100 != 0 && globalMap[i][j] / 100 == currentPlayer)
					if (infantryMap[i][j] == true || cavalryMap[i][j] == true || tanksMap[i][j] == true || planesMap[i][j] == true || towerMap[i][j] == true)
						for (int i1 = i - 3; i1 < i + 4; i1++)
							for (int j1 = j - 3; j1 < j + 4; j1++)
								if (i1 >= 0 && j1 >= 0 && i1 < MAP->getHeight() && j1 < MAP->getWidth())
									towerMap[i1][j1] = true;

}

void LOGIC_WAR::setInfantryMap() {
	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getHeight(); j++)
			infantryMap[i][j] = false;


	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++)
			if (globalMap[i][j] / 10 == currentPlayer)
				for (int i1 = i - 1; i1 < i + 2; i1++)
					for (int j1 = j - 1; j1 < j + 2; j1++)
						if (i1 >= 0 && j1 >= 0 && i1 < MAP->getHeight() && j1 < MAP->getWidth())
							infantryMap[i1][j1] = true;

}

void LOGIC_WAR::setCavalryMap() {
	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getHeight(); j++)
			cavalryMap[i][j] = false;

	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++)
			if (globalMap[i][j] / 10 == currentPlayer)
				for (int i1 = i - 2; i1 < i + 3; i1++)
					for (int j1 = j - 2; j1 < j + 3; j1++)
						if ((abs(i1 - i) == 1 && abs(j1 - j) == 2) || (abs(i1 - i) == 2 && abs(j1 - j) == 1) || (i1 == i && j1 == j))
							if ((i1 >= 0 && j1 >= 0 && i1 < MAP->getHeight() && j1 < MAP->getWidth()))
								cavalryMap[i1][j1] = true;

}

void LOGIC_WAR::setTanksMap() {
	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getHeight(); j++)
			tanksMap[i][j] = false;

	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++)
			if (globalMap[i][j] / 10 == currentPlayer)
				for (int i1 = i - 2, j1 = j + 2; i1 <= i + 2, j1 >= j - 2; i1++, j1--) {
					if (j1 >= 0 && j1 < MAP->getWidth()) {
						tanksMap[i][j1] = true;
						if (i > j && j1 + abs(i - j) < MAP->getWidth() && j1 + abs(i - j) < MAP->getHeight())
							tanksMap[j1 + abs(i - j)][j1] = true;
					}
					if (i1 >= 0 && i1 < MAP->getHeight()) {
						tanksMap[i1][j] = true;
						if (i <= j && i1 + abs(i - j) < MAP->getWidth() && i1 + abs(i - j) < MAP->getHeight())
							tanksMap[i1][i1 + abs(i - j)] = true;
					}
					if (i1 >= 0 && i1 < MAP->getHeight() && j1 >= 0 && j1 < MAP->getWidth())
						tanksMap[i1][j1] = true;
				}
}

void LOGIC_WAR::setPlanesMap() {
	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getHeight(); j++)
			planesMap[i][j] = false;

	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++)
			if (globalMap[i][j] / 10 == currentPlayer)
				for (int i1 = i - 3, j1 = j + 3; i1 <= i + 3, j1 >= j - 3; i1++, j1--) {

					if (j1 >= 0 && j1 < MAP->getWidth()) {
						planesMap[i][j1] = true;
						if (i > j && j1 + abs(i - j) < MAP->getWidth() && j1 + abs(i - j) < MAP->getHeight())
							planesMap[j1 + abs(i - j)][j1] = true;
					}
					if (i1 >= 0 && i1 < MAP->getHeight()) {
						planesMap[i1][j] = true;
						if (i <= j && i1 + abs(i - j) < MAP->getWidth() && i1 + abs(i - j) < MAP->getHeight())
							planesMap[i1][i1 + abs(i - j)] = true;
					}
					if (i1 >= 0 && i1 < MAP->getHeight() && j1 >= 0 && j1 < MAP->getWidth())
						planesMap[i1][j1] = true;
				}
}

// LOGIC::BOT_MIND

void LOGIC_WAR::BOT_MIND() {

	if (PLAYERS[currentPlayer - 1]->getDeath())
		return;

	changeCurrentUnit(INFANTRY);
	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++)
			if (globalMap[i][j] / 10 == currentPlayer || globalMap[i][j] / 100 == currentPlayer)
				for (int i1 = i - 1; i1 < i + 2; i1++)
					for (int j1 = j - 1; j1 < j + 2; j1++)
						if (i1 >= 0 && j1 >= 0 && i1 < MAP->getHeight() && j1 < MAP->getWidth())
							if (AbilityStep(j1, i1) && globalMap[i1][j1] / 10 != currentPlayer && globalMap[i1][j1] != 0) {
								setGlobalMap(j1, i1);
								return;
							}


	changeCurrentUnit(CAVALRY);
	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++)
			if (globalMap[i][j] / 10 == currentPlayer || globalMap[i][j] / 100 == currentPlayer)
				for (int i1 = i - 2; i1 < i + 3; i1++)
					for (int j1 = j - 2; j1 < j + 3; j1++)
						if ((abs(i1 - i) == 1 && abs(j1 - j) == 2) || (abs(i1 - i) == 2 && abs(j1 - j) == 1) || (i1 != i && j1 != j))
							if ((i1 >= 0 && j1 >= 0 && i1 < MAP->getHeight() && j1 < MAP->getWidth()))
								if (AbilityStep(j1, i1) && globalMap[i1][j1] / 10 != currentPlayer && globalMap[i1][j1] != 0) {
									setGlobalMap(j1, i1);
									return;
								}

	changeCurrentUnit(TANKS);
	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++)
			if (globalMap[i][j] / 10 == currentPlayer || globalMap[i][j] / 100 == currentPlayer)
				for (int i1 = i - 2, j1 = j + 2; i1 <= i + 2, j1 >= j - 2; i1++, j1--) {
					if (j1 >= 0 && j1 < MAP->getWidth()) {
						if (AbilityStep(j1, i) && globalMap[i][j1] / 10 != currentPlayer && globalMap[i][j1] != 0) {
							setGlobalMap(j1, i);
							return;
						}
						if (i > j && j1 + abs(i - j) < MAP->getWidth() && j1 + abs(i - j) < MAP->getHeight())
							if (AbilityStep(j1, j1 + abs(i - j)) && globalMap[j1 + abs(i - j)][j1] / 10 != currentPlayer && globalMap[j1 + abs(i - j)][j1] != 0) {
								setGlobalMap(j1, j1 + abs(i - j));
								return;
							}
					}
					if (i1 >= 0 && i1 < MAP->getHeight()) {
						if (AbilityStep(j, i1) && globalMap[i1][j] / 10 != currentPlayer && globalMap[i1][j] != 0) {
							setGlobalMap(j, i1);
							return;
						}
						if (i <= j && i1 + abs(i - j) < MAP->getWidth() && i1 + abs(i - j) < MAP->getHeight())
							if (AbilityStep(i1 + abs(i - j), i1) && globalMap[i1][i1 + abs(i - j)] / 10 != currentPlayer && globalMap[i1][i1 + abs(i - j)] != 0) {
								setGlobalMap(i1 + abs(i - j), i1);
								return;
							}
					}
					if (i1 >= 0 && i1 < MAP->getHeight() && j1 >= 0 && j1 < MAP->getWidth())
						if (AbilityStep(j1, i1) && globalMap[i1][j1] / 10 != currentPlayer && globalMap[i1][j1] != 0) {
							setGlobalMap(j1, i1);
							return;
						}
				}

	changeCurrentUnit(PLANES);
	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++)
			if (globalMap[i][j] / 10 == currentPlayer || globalMap[i][j] / 100 == currentPlayer)
				for (int i1 = i - 3, j1 = j + 2; i1 <= i + 3, j1 >= j - 3; i1++, j1--) {
					if (j1 >= 0 && j1 < MAP->getWidth()) {
						if (AbilityStep(j1, i) && globalMap[i][j1] / 10 != currentPlayer && globalMap[i][j1] != 0) {
							setGlobalMap(j1, i);
							return;
						}
						if (i > j && j1 + abs(i - j) < MAP->getWidth() && j1 + abs(i - j) < MAP->getHeight())
							if (AbilityStep(j1, j1 + abs(i - j)) && globalMap[j1 + abs(i - j)][j1] / 10 != currentPlayer && globalMap[j1 + abs(i - j)][j1] != 0) {
								setGlobalMap(j1, j1 + abs(i - j));
								return;
							}
					}
					if (i1 >= 0 && i1 < MAP->getHeight()) {
						if (AbilityStep(j, i1) && globalMap[i1][j] / 10 != currentPlayer && globalMap[i1][j] != 0) {
							setGlobalMap(j, i1);
							return;
						}
						if (i <= j && i1 + abs(i - j) < MAP->getWidth() && i1 + abs(i - j) < MAP->getHeight())
							if (AbilityStep(i1 + abs(i - j), i1) && globalMap[i1][i1 + abs(i - j)] / 10 != currentPlayer && globalMap[i1][i1 + abs(i - j)] != 0) {
								setGlobalMap(i1 + abs(i - j), i1);
								return;
							}
					}
					if (i1 >= 0 && i1 < MAP->getHeight() && j1 >= 0 && j1 < MAP->getWidth())
						if (AbilityStep(j1, i1) && globalMap[i1][j1] / 10 != currentPlayer && globalMap[i1][j1] != 0) {
							setGlobalMap(j1, i1);
							return;
						}
				}

	double min_dis = 0x3f3f3f3f;
	int min_x = 0, min_y = 0;
	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++)
			if (globalMap[i][j] / 10 != currentPlayer && globalMap[i][j] / 100 == 0 && globalMap[i][j] > 0) {
				if (currentPlayer == 1) {
					if (sqrt(pow(i, 2) + pow(j, 2)) < min_dis) {
						min_dis = sqrt(pow(i, 2) + pow(j, 2));
						min_x = j;
						min_y = i;
					}
				}
				else if (currentPlayer == 2) {
					if (sqrt(pow(i, 2) + pow(MAP->getWidth() - j, 2)) < min_dis) {
						min_dis = sqrt(pow(i, 2) + pow(MAP->getWidth() - j, 2));
						min_x = j;
						min_y = i;
					}
				}
				else if (currentPlayer == 3) {
					if (sqrt(pow(MAP->getHeight() - i, 2) + pow(j, 2)) < min_dis) {
						min_dis = sqrt(pow(MAP->getHeight() - i, 2) + pow(j, 2));
						min_x = j;
						min_y = i;
					}
				}
				else if (currentPlayer == 4) {
					if (sqrt(pow(MAP->getHeight() - i, 2) + pow(MAP->getWidth() - j, 2)) < min_dis) {
						min_dis = sqrt(pow(MAP->getHeight() - i, 2) + pow(MAP->getWidth() - j, 2));
						min_x = j;
						min_y = i;
					}
				}
			}

	int choice_unit = rand() % 4;
	changeCurrentUnit(choice_unit + 1);

	min_dis = 0x3f3f3f3f;
	int min_x_to = 0, min_y_to = 0;
	for (int i = 0; i < MAP->getHeight(); i++)
		for (int j = 0; j < MAP->getWidth(); j++)
			if (AbilityStep(j, i) && globalMap[i][j] == 0)
				if (sqrt(pow(min_x - j, 2) + pow(min_y - i, 2)) < min_dis) {
					min_dis = sqrt(pow(min_x - j, 2) + pow(min_y - i, 2));
					min_x_to = j;
					min_y_to = i;
				}

	setGlobalMap(min_x_to, min_y_to);
	return;
}