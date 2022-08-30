#include <iostream>

class State {
    private: 
        std::string name;
        int population;

        std::string size(){
            if (population < 1000000)
            {
                return "small";
            }
            else if (population > 1000000 && population < 5000000)
            {
                return "medium";
            }
            else if (population > 5000000)
            {
                return "large";
            }
        }
        
    public:
        std::string setName(std::string stateName){
            name = stateName;
        } 
            
        int setPopulation (int statePopulation){
            population = statePopulation;
        }

        int getPopulation(){
            return population;
        }

        std::string getName()
        {
            return name;
        }

        const void printSize(){
            
            std::cout << getName() << ": " << size() << std::endl; 
        }

        State()
        {
            name = "N/a"; 
            population = 0;
        }
};

int main() {
  State state1;
  state1.printSize();
  state1.setPopulation(40000000);
  state1.setName("California");
  state1.printSize();
}