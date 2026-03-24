#include <stdio.h>
#include <string.h>
#include "dispatcher.h"
#include "comparators.h"

typedef struct Task{
	char ins[MAX_INSTRUCTION_LENGTH];
	bool (*executor)(int, int);
}Task_t;

void dispatch(Node_t ** root, ParsedCommand_t parsedCommand) {
    Task_t taskList[] = {
		(Task_t){"isEqual", isEqual},
		(Task_t){"isLess", isLess},
		(Task_t){"isGreater", isGreater}};
	
	for (unsigned int i = 0; i<sizeof(taskList)/sizeof(Task_t); i++){
		if (strncmp(taskList[i].ins, parsedCommand.instruction, MAX_INSTRUCTION_LENGTH) == 0){
			Predicate comparator=taskList[i].executor;
			removeIf(root, comparator, parsedCommand.argument);
			break;
		}
	}
}