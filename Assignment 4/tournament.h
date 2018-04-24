#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <string>
#include "creature.h"
#include "vampire.h"
#include "barbarian.h"
#include "blueMen.h"
#include "medusa.h"
#include "harryPotter.h"
#include "stack.h"
#include "queue.h"

class Tournament {
private:
	Creature *creature;
	Creature *C1;
	Creature *C2;
	Queue P1;
	Queue P2;
	Stack L;
	int numCreature;
	char select;
	std::string p1name, p2name;
	int win1, win2, round, count;
public:
	Tournament();
	void cMenu();
	void fighterQueue();
	void battle();
	void losers();
	void winner();
	void currScore();
};

#endif // !TOURNAMENT_H