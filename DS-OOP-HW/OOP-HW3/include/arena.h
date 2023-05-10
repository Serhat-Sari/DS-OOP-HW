#include <electricPokemon.h>
#include <psychicPokemon.h>

/* @Author
* Student Name: Serhat Sarı
* Student ID : 150200068
*/

class Arena{

    private:

    std::string m_terrain = "none";
    int m_rounds = 1;
    int m_head;
    electricPokemon* electric;
    psychicPokemon* psychic;
    int m_electricCounter = 0;
    int m_psychicCounter = 0;
    int m_terrainCounter = 0;

    public:
    Arena();
    void addPokemon(char,std::string,int,const int);
    void simulateBattle();
    void spawnTerrain();
    void restartTerrain();
    void printRoundStats(int,int);
    void printMatchResults();

};