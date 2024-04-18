#include <iostream>
#include <string>
using namespace std;

class Car {
    public:
    string m_brand;
    string m_model;
    int m_year;
    int m_MaxSeating;
    int m_price;
    Car(string x,string y,int z,int s){
        m_brand=x;
        m_brand=y;
        m_year=z;
        m_MaxSeating=s;
        m_price=m_MaxSeating*500000;
    }
    int get_MaxSeatint(){
        return m_MaxSeating;
    }
    int get_Price(){
        return m_price;
    }
    
};
    
int main(){
    Car car_1("BMW","X5",2023,6);
    Car car_2("Audi","A1",2021,2);
    cout<<car_1.m_brand<<" Max Seating = "<<car_1.get_MaxSeatint()<<endl;
    cout<<car_2.m_brand<<" Max Seating = "<<car_2.get_MaxSeatint()<<endl;
    cout<<car_1.m_brand<<" Price = "<<car_1.get_Price()<<endl;
    cout<<car_2.m_brand<<" Price = "<<car_2.get_Price()<<endl;
}
