#include <iostream>
#include <string>

using namespace std;

class CUDA{ // Class for CUDA

        private:
            const int numCores; 
        public:
            CUDA(int); // Constructor that takes int as input for numCores
            const string render(); // Render function
            const string trainModel();  // trainModel function
};

class ALU{ // Class for ALU

        private:
            const int numPerCores = 0;
        public:
            ALU(int); //  Constructor that takes int as input for numPerCores
            int add(int,int); // Add
            int subtract(int,int); // Subtract
            int multiply(int,int); // Multiply
 };

class GPU{ // Class for GPU
        
    private:
        string ans;
        
    public: 
        GPU(int); // Constructor that takes int as input for numCores for its CUDA.
        string execute(string); // Execute function
        CUDA* cuda; //Pointer to CUDA.
};


 class CPU{ // Class for CPU
        
        private:
            int ans;

        public:
            CPU(int); // Constructor that takes int as input for numPerCores for its ALU.
            int execute(string); // Execute function
            ALU* alu; // Pointer to ALU
};

class Computer{ // Computer class.

    public: 
        Computer(); // Constructor.
        void operator+(CPU &name); // + operator overloader to attach CPU to computer.
        void operator+(GPU &name); // + operator overloader to attach GPU to computer.
        GPU* attachedGPU; // Poniter to GPU
        CPU* attachedCPU; // Pointer to CPU
        void execute(string); // Execute function that takes string as operation.

    private:
        bool GPUCheck = false, CPUCheck = false;  // Bool variables to check if there is an attached GPU or CPU in the computer.

};