#include <psychicPokemon.h>

/* @Author
* Student Name: Serhat Sarı
* Student ID : 150200068
*/

psychicPokemon::psychicPokemon(std::string name, int hp,const int dmg, const int powerupchance, const int recharge) 
                : Pokemon{name,hp,dmg,powerupchance,recharge}{}

//Same with electricPokemon constructor.

int psychicPokemon::getPowerUpCounter(){

    return m_powerupcounter;

}

void psychicPokemon::setPowerUpCounter(int counter){

    m_powerupcounter = counter;
    
}