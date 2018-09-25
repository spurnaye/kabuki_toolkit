#include <stdafx.h>
#include <iostream>

#include "../../kabuki/f2_pico/f2_pico.h"

#include "maze_agent.h"
using namespace _;

int main(int args_count, char** args) {
  Print("\nPreprocessing Maze...\n");
  int width, height, page_columns = 20;
  char* tiles = PreprocessMaze(Maze1, width, height);

  Print("\nTesting Maze...\n");
  Maze maze(tiles, width, height, 1);

  Print("\nCreating Agent...\n");
  MazeAgent agent;
  agent.Print();

  Print(
      "\nEntering maze.\nControls: A/D moves left/right and W/D moves "
      "forward/stop/backwards.\nPress E to toggle autopilot on/off.\n\n");
  do {  // Main loop just scans for keyboard input.
    for (int i = page_columns; i > 0; --i) Print();
    maze.Print();
    // Get keyboard input.
    int key = ToUpper(CInKey());
    switch (key) {
      case 'A': {  // Turn left.
        agent.TurnLeft();
        break;
      }
      case 'D': {  // Move right.
        agent.TurnRight();
        break;
      }
      case 'E': {
        agent.AutopilotToggle();
        break;
      }
      case 'P': {  // Pause by spin waiting.
        for (int i = 0xfffffff; i > 0; --i)
          ;
        break;
      }
      case 'Q': {
        agent.ShutDown();
        break;
      }
      case 'S': {  // Move down.
        agent.Decelerate();
        break;
      }
      case 'W': {  // Move up.
        agent.Accellerate();
        break;
      }
      default: { break; }
    }
  } while (agent.Update());
  Print("\n\nExiting...");
  return 0;
}
