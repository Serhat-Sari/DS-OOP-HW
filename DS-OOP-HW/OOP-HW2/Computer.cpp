#include "Computer.h"

// Cuda begin

const string CUDA::render(){

    const string ans = "Video is rendered";
    return ans;

}

const string CUDA::trainModel(){

    const string ans = "AI Model is trained";
    return ans;
}

CUDA::CUDA(int num_of_cores) : numCores(num_of_cores){ // CUDA constructor with initializer list.

    cout << "CUDA is ready" << '\n';
} 


 // Cuda end

 // Alu begin

int ALU::add(int a, int b){
    return a+b;
}

int ALU::subtract(int a, int b){
    return a-b;
}

int ALU::multiply(int a, int b){
    return a*b;
}

ALU::ALU(int num_per_cores) : numPerCores(num_per_cores){ // ALU constructor with initializer list.

    cout << "ALU is ready" << '\n';
}

// alu end

// cpu begin

CPU::CPU(int a){ 

    ALU temp = {a}; // Calling ALU constructor with a as initializer list.
    alu = &temp; // Pointing the addres of temp to the ALU in the CPU.
    cout << "CPU is ready" << '\n';

}

int CPU::execute(string operation){
    
    int a,b;
    cout << "Enter two integers" << '\n';
    cin >> a >> b;
    if(operation == "add")
       return ans = alu->add(a,b);
    if(operation == "subtract")
       return ans = alu->subtract(a,b);
    if(operation == "multiply")
       return ans = alu->multiply(a,b);

        return 0;
}

// cpu end


// gpu begin


GPU::GPU(int a){  

    CUDA temp = {a}; // Calling CUDA constructor with a as initializer list.
    cuda = &temp; // Pointing the addres of temp to the CUDA in the GPU.
    cout << "GPU is ready" << '\n';

}



string GPU::execute(string operation){

    if(operation == "render")
       return ans = cuda->render();
    if(operation == "trainModel")
       return ans = cuda->trainModel();

        return "AVADA KEDAVRA"; // if operation is neither render or trainModel it returns the unforgivable.
}


// gpu end 


// computer begin

void Computer::operator+(GPU &name){
        if(!GPUCheck){ // If there is no GPU attached to the computer enter this block.
            attachedGPU = &name;
            GPUCheck = true; // From now on, there is a GPU attached to the computer.
            cout << "GPU is attached" << '\n';
        }
        else // If there is already an attached GPU to the computer enter this block.
            cout << "There is already a GPU" << '\n';
}

void Computer::operator+(CPU &cpu){
        if(!CPUCheck){ // If there is no CPU attached to the computer enter this block.
            this-> attachedCPU = &cpu;
            CPUCheck = true; // From now on, there is a CPU attached to the computer.
            cout << "CPU is attached" << '\n';
        }
        else // If there is already an attached CPU to the computer enter this block.
            cout << "There is already a CPU" << '\n';
}

void Computer::execute(string operation){
    if(operation == "render" || operation == "trainModel"){
       string ans = attachedGPU->execute(operation);
       cout << ans << '\n';
    }
    else{
        int ans = attachedCPU->execute(operation);
        cout << ans << '\n';
    }
}

Computer::Computer(){

    GPUCheck = false; // Since there is neither GPU or CPU attached to the computer
    CPUCheck = false; // in the beginning, both bool variables are false.

    cout << "Computer is ready" << '\n';

}

// computer end