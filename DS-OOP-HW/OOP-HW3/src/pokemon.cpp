#include <pokemon.h>

/* @Author
* Student Name: Serhat Sarı
* Student ID : 150200068
*/


Pokemon::Pokemon(std::string name, int hp,const int dmg, const int powerupchance, const int recharge) : 
    m_name{name}, m_hp{hp}, m_damage{dmg}, m_powerupchance{powerupchance}, m_recharge{recharge}
{ // Constructor with initalizer list.
    bool m_fainted = false;
    bool m_terrain = false;
    bool m_powerupstate = false;
} 

std::string Pokemon::getName(){

    return m_name;

}

int Pokemon::getHp(){

    return m_hp;

}

const int Pokemon::getDamage(){

    return m_damage;
    
}

const double Pokemon::getPowerupchance(){

    return m_powerupchance;
    
}

const int Pokemon::getRecharge(){

    return m_recharge;
    
}

bool Pokemon::getFainted(){

    return m_fainted;
    
}

bool Pokemon::getPowerupstate(){

    return m_powerupstate;
    
}

bool Pokemon::getTerrain(){

    return m_terrain;
    
}

void Pokemon::setFainted(bool faint){

    m_fainted = faint;

}

void Pokemon::setHp(int hp){

    m_hp = hp;
    
}

void Pokemon::setTerrainInfo(bool terrain){

    m_terrain = terrain;
    
}

void Pokemon::setPowerupstate(int percentage){

    // It generates a random number between 1 and 100. If this number is smaller than the given percentage
    // (20 for electric, 30 for psychic), pokemon power ups.
    
    int possibility = rand() % 100 + 1;
    
    if(possibility <= percentage)
        m_powerupstate = true;
    
    else
        m_powerupstate = false;

}

