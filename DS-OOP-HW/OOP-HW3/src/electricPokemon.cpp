#include <electricPokemon.h>

/* @Author
* Student Name: Serhat Sarı
* Student ID : 150200068
*/

electricPokemon::electricPokemon(std::string name, int hp,const int dmg, const int powerupchance, const int recharge) 
                : Pokemon{name,hp,dmg,powerupchance,recharge}{}
                
// Since pokemon does not have a default constructor, electricPokemon constructor calls the pokemon constructor
// in its member initalizer list with the given parameters in its constructor.

void electricPokemon::setConfusedCounter(int counter){

    m_confusedcounter = counter;

}

void electricPokemon::setPowerUpCounter(int counter){

    m_powerupcounter = counter;


}

int electricPokemon::getConfusedCounter(){

    return m_confusedcounter;

}

int electricPokemon::getPowerUpCounter(){

    return m_powerupcounter;
    
}