#include "Game.h"
using namespace std;

int main(int argc, char *argv[]){  // NOTE: Input validity assumed
    string race; 
    while (cin >> race && race != "q"){
        MapItemType type;
        if (race == "s") type = SHADE;
        else if (race == "d") type = DROW;
        else if (race == "v") type = VAMPIRE;
        else if (race == "t") type = TROLL;
        else type = GOBLIN;
        auto game = make_unique<Game>(race, type);
        if (argc >= 2){
            string file = argv[1];
            game->InitByFile(file);
        }
        else {
            game->InitializeGame();
        }
        while (game->GameStatus()){
            int update = 1;
            string command;
            if (cin >> command){
                if (command == "u"){ // use potion
                    cin >> command;
                    BuffedPlayer &player = game->GetPlayer();
                    player.takePotion(command);
                } 
                else if (command == "a"){ // atk
                    cin >> command;
                    BuffedPlayer &player = game->GetPlayer();
                    player.attackNotify(command);
                }
                else if (command == "f"){ // frozen
                    if (update) update = 0;
                    else update = 1;
                }
                else if (command == "r"){ // restart
                    break;
                }
                else if (command == "q"){ // quit
                    return 0;
                }
                // player move
                else{
                    Map &map = game->GetMap();
                    BuffedPlayer &player = game->GetPlayer();
                    int row = player.GetRow();
                    int col = player.GetCol();
                    vector<CellType> ct = map.GetViews(row, col);
                    if (command == "nw") {
                        if (ct[0] == ROOM || ct[0] == PASSAGE || ct[0] == DOOR) {
                            player.SetRow(row-1);
                            player.SetCol(col-1);
                        }
                        else if (ct[0] == ASTAIR){
                            game->LevelUp();
                        }
                        else{ //
                            cout << "invalid move" << endl;
                        }
                    }
                    else if (command == "no") {
                        if (ct[1] == ROOM || ct[1] == PASSAGE || ct[1] == DOOR) {
                            player.SetRow(row-1);
                        }
                        else if (ct[1] == ASTAIR){
                            game->LevelUp();
                        }
                        else{ //
                            cout << "invalid move" << endl;
                        }
                    }
                    else if (command == "ne") {
                        if (ct[2] == ROOM || ct[2] == PASSAGE || ct[2] == DOOR) {
                            player.SetRow(row-1);
                            player.SetCol(col+1);
                        }
                        else if (ct[2] == ASTAIR){
                            game->LevelUp();
                        }
                        else{ //
                            cout << "invalid move" << endl;
                        }
                    }
                    else if (command == "we") {
                        if (ct[3] == ROOM || ct[3] == PASSAGE || ct[3] == DOOR) {
                            player.SetCol(col-1);
                        }
                        else if (ct[3] == ASTAIR){
                            game->LevelUp();
                        }
                        else{ //
                            cout << "invalid move" << endl;
                        }
                    }
                    else if (command == "ea") {
                        if (ct[5] == ROOM || ct[5] == PASSAGE || ct[5] == DOOR) {
                            player.SetCol(col+1);
                        }
                        else if (ct[5] == ASTAIR){
                            game->LevelUp();
                        }
                        else{ //
                            cout << "invalid move" << endl;
                        }
                    }
                    else if (command == "sw") {
                        if (ct[6] == ROOM || ct[6] == PASSAGE || ct[6] == DOOR) {
                            player.SetRow(row-1);
                            player.SetCol(col-1);
                        }
                        else if (ct[6] == ASTAIR){
                            game->LevelUp();
                        }
                        else{ //
                            cout << "invalid move" << endl;
                        }
                    }
                    else if (command == "so") {
                        if (ct[7] == ROOM || ct[7] == PASSAGE || ct[7] == DOOR) {
                            player.SetRow(row-1);
                        }
                        else if (ct[7] == ASTAIR){
                            game->LevelUp();
                        }
                        else{ //
                            cout << "invalid move" << endl;
                        }
                    }
                    else if (command == "se") {
                        if (ct[8] == ROOM || ct[8] == PASSAGE || ct[8] == DOOR) {
                            player.SetRow(row-1);
                            player.SetCol(col+1);
                        }
                        else if (ct[8] == ASTAIR){
                            game->LevelUp();
                        }
                        else{ //
                            cout << "invalid move" << endl;
                        }
                    }
                }
            }
            else { // EOF
                return 0;
            }
            if (update){
                game->UpdateGame();
            }
            game->Render();
        }

    }
}