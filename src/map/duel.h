// Copyright (c) Hercules Dev Team, licensed under GNU GPL.
// See the LICENSE file
// Portions Copyright (c) Athena Dev Teams

#ifndef MAP_DUEL_H
#define MAP_DUEL_H

#include "common/cbasetypes.h"

struct map_session_data;

struct duel {
	int members_count;
	int invites_count;
	int max_players_limit;
};

#define MAX_DUEL 1024

/*=====================================
* Interface : duel.h
* Generated by HerculesInterfaceMaker
* created by Susu
*-------------------------------------*/
struct duel_interface {

	/* vars */
	struct duel list[MAX_DUEL];
	int count;

	/* funcs */
	//Duel functions // [LuzZza]
	int (*create) (struct map_session_data* sd, const unsigned int maxpl);
	void (*invite) (const unsigned int did, struct map_session_data* sd, struct map_session_data* target_sd);
	void (*accept) (const unsigned int did, struct map_session_data* sd);
	void (*reject) (const unsigned int did, struct map_session_data* sd);
	void (*leave) (const unsigned int did, struct map_session_data* sd);
	void (*showinfo) (const unsigned int did, struct map_session_data* sd);
	int (*checktime) (struct map_session_data* sd);

	void (*init) (bool minimal);
	void (*final) (void);
};

struct duel_interface *duel;

#ifdef HERCULES_CORE
void duel_defaults(void);
#endif // HERCULES_CORE

#endif /* MAP_DUEL_H */
