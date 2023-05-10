#include <arena.h>

/* @Author
* Student Name: Serhat Sarı
* Student ID : 150200068
*/

Arena::Arena(){}

void Arena::addPokemon(char type, std::string name, int hp, const int damage){

    if(type == 'e'){ // If type is electric pokemon, enter this block.
        if(m_electricCounter == 0){ // If there is already an electric pokemon in the arena do not add 
                                    // this new one.
            electric = new electricPokemon(name,hp,damage,20,3);
            std::cout <<  "Electric Pokemon " << name << " has entered the arena." << '\n';
            std::cout <<  "Class: Electric" << '\n';
            std::cout <<  "       Name: " << name << '\n';
            std::cout <<  "       HP: " << hp << '\n';
            std::cout <<  "       Damage: " << damage << '\n';
            m_electricCounter++; // Indicates that we added one electric pokemon.
            std::cout << '\n';
            std::cout << '\n';
        }
    }
    else if(type == 'p'){ // If type is psychic pokemon, enter this block.
        if(m_psychicCounter == 0){ // If there is already an psychic pokemon in the arena do not add 
                                   // this new one.
            psychic = new psychicPokemon(name,hp,damage,30,5); 
            std::cout <<  "Psychic Pokemon " << name << " has entered the arena."<< '\n';
            std::cout <<  "Class: Psychic" << '\n';
            std::cout <<  "       Name: " << name << '\n';
            std::cout <<  "       HP: " << hp << '\n';
            std::cout <<  "       Damage: " << damage << '\n';
            m_psychicCounter++; // Indicates that we added one psychic pokemon.
            std::cout << '\n';
            std::cout << '\n';
        }
    }

}

void Arena::spawnTerrain(){

    /* It generates a number between 1 and 100. If this number is below and equal to 20
       terrain is electric, else if this number is above 20 and below equal to 40, terrain is
       psychic, else it is none.
    */

    int random = rand() % 100 +1;

    if(random <= 20)
        m_terrain = "electric";
    else if(random > 20 && random <= 40)
        m_terrain = "psychic";
    else
        m_terrain = "none";

    m_terrainCounter = 0; // Sets the counter for the terrain. 
                          //(How many rounds has passed since this terrain is selected.)

}

void Arena::restartTerrain(){

    m_terrain = "none";
    m_terrainCounter = 0;


}

void Arena::simulateBattle(){
        
    while(electric->getHp() > 0 && psychic->getHp() > 0){ // Game continues until one of them dies.
        
        if(m_terrain == "none"){ // If terrain is none, spawn new terrain.
            spawnTerrain();
            if(m_terrain != "none") // If new terrain is elec or psy, increase the counter.
                m_terrainCounter++;
        }
        else{ // If terrain is not none, enter this block.
            if(m_terrainCounter == 6){// It has been 5 rounds since last terrain is selected, either electric or psy.
                                      // Counter is suppose to be 6, else terrain will stay for 4 rounds then we will increment it
                                      // and next round counter will be 5 and new terrain will be selected.
                spawnTerrain();
                m_terrainCounter++;
            }
            else{ // If it hasn't been 5 rounds since last terrain is selected, just increment the counter.
                m_terrainCounter++;
            }
        }   

        m_head = rand() %100 + 1; // If head is below equal to 50 electric goes first, else psychic goes first.

        if(m_head <= 50){ // Electric pokemon attacks first.
            if(electric->getFainted() == true){ // Do no damage.
                electric->setConfusedCounter(electric->getConfusedCounter()+1); // Increase the confused counter.
                if(electric->getConfusedCounter() == 4){ // If confused counter reaches 3 rounds, reset the counter and set confused state to false.
                    electric->setConfusedCounter(0); 
                    electric->setFainted(false); // No more fainted.
                }
                if(electric->getPowerUpCounter() == 0){ // If pokemon can power up, get in this block. 
                    electric->setPowerupstate(20);
                    if(electric->getPowerupstate() == true){ // Pokemon is powered up.
                        // psychic->setHp(psychic->getHp()-electric->getDamage()*3);  Poke doesnt do any damage because it is fainted.
                        electric->setPowerUpCounter(electric->getPowerUpCounter()+1);
                    }
                    else{ // Poke couldn't power up.
                        // psychic->setHp(psychic->getHp()-electric->getDamage());  Poke doesnt do any damage because it is fainted.
                    }

                }
                else{ // If poke can not power up ( needs to wait for 3 rounds since last power up)
                    electric->setPowerUpCounter(electric->getPowerUpCounter()+1); // Increase the number of waited rounds.
                    if(electric->getPowerUpCounter() == 4){ // If poke waited for 3 rounds, reset the chances.
                        electric->setPowerUpCounter(0); 
                    }
                     //psychic->setHp(psychic->getHp()-electric->getDamage());  Poke doesnt do any damage because it is fainted.
                }

            }
            else{ // Do almost everything above but with damage.
                if(electric->getPowerUpCounter() == 0){ // If pokemon can power up, get in this block. 
                    electric->setPowerupstate(20);
                    if(electric->getPowerupstate() == true){ // Pokemon is powered up.
                        psychic->setHp(psychic->getHp()-electric->getDamage()*3);  // Hit the psychic pokemon with 3 times the electric pokemons damage.
                        electric->setPowerUpCounter(electric->getPowerUpCounter()+1);
                    }
                    else{ // Poke couldn't power up.
                         psychic->setHp(psychic->getHp()-electric->getDamage());   // Hit the psychic pokemon.
                    }

                }
                else{ // If poke can not power up ( needs to wait for 3 rounds since last power up)
                    electric->setPowerUpCounter(electric->getPowerUpCounter()+1); // Increase the number of waited rounds.
                    if(electric->getPowerUpCounter() == 4){ // If poke waited for 3 rounds, reset the chances.
                        electric->setPowerUpCounter(0); 
                    }
                     psychic->setHp(psychic->getHp()-electric->getDamage()); // Hit the psychic pokemon.
                }
                if(psychic->getHp() <= 0){ // If psychic pokemon dies after the attack.
                    psychic->setHp(0); // If psychic pokemons health is negative, set it to 0.
                    printRoundStats(m_rounds,m_head);
                    printMatchResults();
                    restartTerrain();
                    m_rounds = 1;
                    break; // End the loop.
                }
            } // Now psy attacks.

             if(psychic->getPowerUpCounter() == 0){ // If pokemon can power up, get in this block. 
                    psychic->setPowerupstate(30);
                    if(psychic->getPowerupstate() == true){ // Pokemon is powered up.

                        if(m_terrain == "psychic") // If terrain is psychic hit double damage.
                            electric->setHp(electric->getHp()-psychic->getDamage()*2); 
                        else // Hit normal damage.
                            electric->setHp(electric->getHp()-psychic->getDamage()); 
                        
                        if(m_terrain != "electric"){ // If terrain is not electric, confuse the electric pokemon.
                            electric->setFainted(true);
                            electric->setConfusedCounter(0);
                        }
        
                        psychic->setPowerUpCounter(psychic->getPowerUpCounter()+1);
                    }
                    else{ // Poke couldn't power up.
                        if(m_terrain == "psychic") // Hit double damage.
                            electric->setHp(electric->getHp()-psychic->getDamage()*2);   
                        else // Hit normal damage.
                            electric->setHp(electric->getHp()-psychic->getDamage()); 
                    }
            }
            else{ // If poke can not power up ( needs to wait for 5 rounds since last power up)
                psychic->setPowerUpCounter(psychic->getPowerUpCounter()+1); // Increase the number of waited rounds.
                if(psychic->getPowerUpCounter() == 6){ // If poke waited for 5 rounds, reset the chances.
                    psychic->setPowerUpCounter(0); 
                }
                    if(m_terrain == "psychic") // Hit double damage.
                        electric->setHp(electric->getHp()-psychic->getDamage()*2); 
                    else // Hit normal damage.
                        electric->setHp(electric->getHp()-psychic->getDamage()); 
                }
            if(electric->getHp() <= 0){ // If electric pokemon dies after the attack.
                electric->setHp(0);
                printRoundStats(m_rounds,m_head);
                printMatchResults();
                restartTerrain();
                m_rounds = 1;
                break;
            }
            printRoundStats(m_rounds,m_head);
            m_rounds++;
        }
        else{ // If heads is 0 psychic pokemon attacks first.
            if(psychic->getPowerUpCounter() == 0){ // If pokemon can power up, get in this block. 
                psychic->setPowerupstate(30);
                if(electric->getPowerupstate() == true){ // Pokemon is powered up.

                    if(m_terrain == "psychic") // If terrain is psychic hit double damage.
                        electric->setHp(electric->getHp()-psychic->getDamage()*2);
                    else
                        electric->setHp(electric->getHp()-psychic->getDamage());
                        
                    if(m_terrain != "electric"){ // If terrain is not electric, confuse the electric pokemon.
                        electric->setFainted(true);
                        electric->setConfusedCounter(0);
                    }
        
                    psychic->setPowerUpCounter(psychic->getPowerUpCounter()+1);
                }
                else{ // Poke couldn't power up.
                    if(m_terrain == "psychic")
                        electric->setHp(electric->getHp()-psychic->getDamage()*2);  
                    else
                        electric->setHp(electric->getHp()-psychic->getDamage()); 
                }
            }
            else{ // If poke can not power up ( needs to wait for 5 rounds since last power up)
                psychic->setPowerUpCounter(psychic->getPowerUpCounter()+1); // Increase the number of waited rounds.
                if(psychic->getPowerUpCounter() == 6){ // If poke waited for 5 rounds, reset the chances.
                    psychic->setPowerUpCounter(0); 
                }
                    if(m_terrain == "psychic") // Hit double damage.
                        electric->setHp(electric->getHp()-psychic->getDamage()*2); 
                    else // Hit normal damage.
                        electric->setHp(electric->getHp()-psychic->getDamage()); 
                }
            if(electric->getHp() <= 0){
                electric->setHp(0);
                printRoundStats(m_rounds,m_head);
                printMatchResults();
                restartTerrain();
                m_rounds = 1;
                break;
            }
            // Now electric pokemon attacks.
            if(electric->getFainted() == true){ // Do no damage.
                electric->setConfusedCounter(electric->getConfusedCounter()+1); // Increase the confused counter.
                if(electric->getConfusedCounter() == 4){ // If confused counter reaches 3 rounds, reset the counter and set confused state to false.
                    electric->setConfusedCounter(0); 
                    electric->setFainted(false); // No more fainted.
                }
                if(electric->getPowerUpCounter() == 0){ // If pokemon can power up, get in this block. 
                    electric->setPowerupstate(20);
                    if(electric->getPowerupstate() == true){ // Pokemon is powered up.
                        // psychic->setHp(psychic->getHp()-electric->getDamage()*3);  Poke doesnt do any damage because it is fainted.
                        electric->setPowerUpCounter(electric->getPowerUpCounter()+1); //
                    }
                    else{ // Poke couldn't power up.
                        // psychic->setHp(psychic->getHp()-electric->getDamage());  Poke doesnt do any damage because it is fainted.
                    }

                }
                else{ // If poke can not power up ( needs to wait for 3 rounds since last power up)
                    electric->setPowerUpCounter(electric->getPowerUpCounter()+1); // Increase the number of waited rounds.
                    if(electric->getPowerUpCounter() == 4){ // If poke waited for 3 rounds, reset the chances.
                        electric->setPowerUpCounter(0); 
                    }
                     //psychic->setHp(psychic->getHp()-electric->getDamage());  Poke doesnt do any damage because it is fainted.
                }

            }
            else{ // Do almost everything above but with damage.
                if(electric->getPowerUpCounter() == 0){ // If pokemon can power up, get in this block. 
                    electric->setPowerupstate(20);
                    if(electric->getPowerupstate() == true){ // Pokemon is powered up.
                        psychic->setHp(psychic->getHp()-electric->getDamage()*3);  
                        electric->setPowerUpCounter(electric->getPowerUpCounter()+1);
                    }
                    else{ // Poke couldn't power up.
                         psychic->setHp(psychic->getHp()-electric->getDamage());  
                    }

                }
                else{ // If poke can not power up ( needs to wait for 3 rounds since last power up)
                    electric->setPowerUpCounter(electric->getPowerUpCounter()+1); // Increase the number of waited rounds.
                    if(electric->getPowerUpCounter() == 4){ // If poke waited for 3 rounds, reset the chances.
                        electric->setPowerUpCounter(0); 
                    }
                     psychic->setHp(psychic->getHp()-electric->getDamage()); 
                }
    
            }
                if(psychic->getHp() <= 0){ // If psychic pokemon dies after the attack.
                    psychic->setHp(0);
                    printRoundStats(m_rounds,m_head);
                    printMatchResults();
                    restartTerrain();
                    m_rounds = 1;
                    break; // End the loop.
                }
            printRoundStats(m_rounds,m_head);
            m_rounds++;
        }

    }
}

void Arena::printRoundStats(int rounds, int head){

    std::cout << "Round: " << rounds << '\n';
    std::cout << "Current Terrain: " << m_terrain << '\n';
    if(head > 50)
        std::cout << psychic->getName() << " goes first.\n";
    else
        std::cout << electric->getName() << " goes first.\n";
    if(psychic->getPowerUpCounter() == 1)
        std::cout << psychic->getName() << " has initiated a power up.\n";
    if(electric->getPowerUpCounter() == 1)
        std::cout << electric->getName() << " has initiated a power up.\n";
    std::cout << electric->getName() << " HP: " << electric->getHp() << '\n';
    std::cout << psychic->getName() << " HP: " << psychic->getHp() << '\n';
    if(electric->getHp() > psychic->getHp())
        std::cout << electric->getName() << " is in the lead!\n";
    else
        std::cout << psychic->getName() << " is in the lead!\n";
    std::cout << '\n';
    std::cout << '\n';


}


void Arena::printMatchResults(){

    if(psychic->getHp() <= 0 ) // If psychic is dead, electric is won.
        std::cout << electric->getName() << " has won the match!\n";

    else if( electric->getHp() <= 0) // If electric is dead, psychic is won.
        std::cout << psychic->getName() << " has won the match!\n";

    std::cout << '\n';
    std::cout << '\n';

    m_electricCounter = 0;
    m_psychicCounter = 0;
    delete electric;
    delete psychic;
}