#include <pokemon.h>

/* @Author
* Student Name: Serhat Sarı
* Student ID : 150200068
*/

class psychicPokemon : public Pokemon{

    private:
        int m_powerupcounter = 0; // Counter for how many rounds it has been since last power up.

    public:
        psychicPokemon(std::string,int,const int,const int, const int);
        int getPowerUpCounter();
        void setPowerUpCounter(int);
};