#include <iostream>
#include <string>

// Memento
class PlayerMemento {
public:
    PlayerMemento() : playerName(""), playerLevel(0) {}

    PlayerMemento(const std::string& playerName, int playerLevel)
        : playerName(playerName), playerLevel(playerLevel) {}

    std::string getPlayerName() const {
        return playerName;
    }

    int getPlayerLevel() const {
        return playerLevel;
    }

private:
    std::string playerName;
    int playerLevel;
};

// Originator
class Player {
public:
    Player(const std::string& playerName, int playerLevel)
        : playerName(playerName), playerLevel(playerLevel) {}

    std::string getPlayerName() const {
        return playerName;
    }

    int getPlayerLevel() const {
        return playerLevel;
    }

    void displayPlayerInfo() const {
        std::cout << "Nombre del jugador: " << playerName << std::endl;
        std::cout << "Nivel del jugador: " << playerLevel << std::endl;
    }

    PlayerMemento createMemento() const {
        return PlayerMemento(playerName, playerLevel);
    }

    void restoreFromMemento(const PlayerMemento& memento) {
        playerName = memento.getPlayerName();
        playerLevel = memento.getPlayerLevel();
    }

private:
    std::string playerName;
    int playerLevel;
};

// Caretaker
class Game {
public:
    Game(Player& player) : player(player), savedMemento(), isGameSaved(false) {}

    ~Game() {}

    void saveGame() {
        savedMemento = player.createMemento();
        isGameSaved = true;
        std::cout << "Juego guardado." << std::endl;
    }

    void loadGame() {
        if (isGameSaved) {
            player.restoreFromMemento(savedMemento);
            std::cout << "Juego cargado." << std::endl;
        } else {
            std::cout << "No hay juego guardado." << std::endl;
        }
    }

private:
    Player& player;
    PlayerMemento savedMemento;
    bool isGameSaved;
};

int main() {
    Player player("John Doe", 5);
    Game game(player);

    player.displayPlayerInfo();

    game.saveGame();

    player.displayPlayerInfo();

    player = Player("John Doe", 10);
    player.displayPlayerInfo();

    game.loadGame();

    player.displayPlayerInfo();

    return 0;
}


