#include <pokemon.h>

/* @Author
* Student Name: Serhat Sarı
* Student ID : 150200068
*/

class electricPokemon : public Pokemon{

    private:
        int m_powerupcounter = 0; // Counter for how many rounds it has been since last power up.
        int m_confusedcounter = 0; // Counter for how many rounds it has been since pokemon is confused.

    public:
        electricPokemon(std::string,int,const int,const int, const int);
        int getPowerUpCounter();
        void setPowerUpCounter(int);
        int getConfusedCounter();
        void setConfusedCounter(int);
};
