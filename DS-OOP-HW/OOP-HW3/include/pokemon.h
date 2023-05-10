#include <iostream>

/* @Author
* Student Name: Serhat Sarı
* Student ID : 150200068
*/

#pragma once

class Pokemon {

    private:
        std::string const m_name; 
        int m_hp; 
        const int m_damage; 
        const int m_powerupchance;
        const int m_recharge;
        bool m_fainted = false,m_powerupstate = false ,m_terrain = false;
    public:
        Pokemon(std::string,int,const int,const int, const int); // Constructor
        std::string getName(); // Rest is setters and getters.
        int getHp();
        const int getDamage();
        const double getPowerupchance();
        const int getRecharge();
        bool getFainted();
        bool getPowerupstate();
        bool getTerrain();
        void setHp(int);
        void setFainted(bool);
        void setPowerupstate(int);
        void setTerrainInfo(bool);
};
