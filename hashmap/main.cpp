#include <iostream>
#include <ctime>
#include <string>

const int SIZE = 10;
struct Car{
    int year;
    int speed;
    std::string mark;
    Car():year(-1),speed(-1),mark(""){}
    Car(int god,int vel,std::string mar):year(god),speed(vel),mark(mar){}
    bool operator==(Car car1){
        if(year==car1.year&&speed==car1.speed&&mark==car1.mark){
            return 1;
        }
        return 0;

    }
};

class HashTable{
    Car cars[SIZE];
    int random[12];
    
    int hash(Car car){
        int index = car.year%SIZE;
        for(int p = 0;p<12;p++){
            if(cars[index].year==-1||cars[index].mark==car.mark&&cars[index].speed==car.speed&&cars[index].year==car.year){
                return index;
            }
            else{
                index = (index + random[p])%SIZE;
            }
        }
        return -1;
    } 
    public:
    HashTable(){
        std::cout<<"enter random"<<std::endl;
        for(int i = 0;i<12;i++){
            std::cin>>random[i];
        }
    }
    void add_element(Car temp){
        // Car temp;
        // std::cout<<"enter mark\n";
        // std::cin>>temp.mark;
        // std::cout<<"enter max speed\n";
        // std::cin>>temp.speed;
        // std::cout<<"enter year\n";
        // std::cin>>temp.year;
        if(hash(temp)==-1){
            std::cout<<"hash table is full\n";
            return;
        }
        cars[hash(temp)]=temp;
        
    }
    void show_all(){
        for(int i = 0;i<SIZE;i++){
            std::cout<<std::endl;
            std::cout<<i<<"\nMark: "<<cars[i].mark<<"\nSpeed: "<<cars[i].speed<<"\nYear: "<<cars[i].year<<std::endl;
        }
    }
    void find(Car car){
        if(hash(car)==-1){
            std::cout<<"there isn\'t your car in garage"<<std::endl;
            return;
        }
        if(cars[hash(car)]==car){
            std::cout<<"your car is on the "<<hash(car)<<" place in garage\n";
        }
        else{
            std::cout<<"i don\'t see this car in the garage\n";
        }
    }
    

    
};

int main(){
    srand(time(NULL));
    Car cars[8];
    // cars[0]={2020,90,"toyota"};
    // cars[1]={2006,180,"ford"};
    // cars[2]={1999,365,"volvo"};
    // cars[3]={1987,1000,"volga"};
    // cars[4]={1888,69,"bmw"};
    // cars[5]={2005,999,"mercedes"};
    // cars[6]={2088,90,"lexus"};
    // cars[7]={2177,90,"zhiguli"};
    for(int i = 0;i<8;i++){
        std::cout<<"enter car number "<<i<<std::endl;
        std::cin>>cars[i].mark;
        std::cin>>cars[i].year;
        std::cin>>cars[i].speed;
    }
    HashTable hashCars;
    for(int i = 0;i<8;i++){
        hashCars.add_element(cars[i]);
    }
    hashCars.show_all();
    int x=0;
    while(x!=4){
        Car temp;
        std::cin>>x;
        switch (x){
            case 1: 
                hashCars.show_all();
                break;
            case 2:
                std::cout<<"enter mark\n";
                std::cin>>temp.mark;
                std::cout<<"enter max speed\n";
                std::cin>>temp.speed;
                std::cout<<"enter year\n";
                std::cin>>temp.year;
                hashCars.add_element(temp);
                break;
            case 3:
                for(int i = 0 ; i < 8;i++){
                    std::cout<<i<<".\nMark: "<<cars[i].mark<<"\nSpeed: "<<cars[i].speed<<"\nYear: "<<cars[i].year<<std::endl;
                }
                std::cout<<"enter car to find in hash table\n";

                std::cout<<"enter mark\n";
                std::cin>>temp.mark;
                std::cout<<"enter max speed\n";
                std::cin>>temp.speed;
                std::cout<<"enter year\n";
                std::cin>>temp.year;
                hashCars.find(temp);
                break;
            default:
                break;

        }

    }
    hashCars.find(cars[6]);
    hashCars.find(cars[7]);
    
}