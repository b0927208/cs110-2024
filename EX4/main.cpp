#include <iostream>
#include <string>
using namespace std;
class Fueltank{
    private:
        int m_FueltankCapacity;
        int m_Gas_grade;
    public:
        Fueltank(int FueltankCapacity=3000,int Gas=98){
            m_FueltankCapacity=FueltankCapacity;
            m_Gas_grade=Gas;
        }
        int set_Gas_grade(int Gas_grade){
            m_Gas_grade=Gas_grade;
            return m_Gas_grade;
        }
        int get_Gas_grade(){
            return m_Gas_grade;
        }
        int get_F(){
            return m_FueltankCapacity;
        }
};
class Car {
    protected:
    Fueltank m_Fueltank;
    string m_DriveMode;
    private:
    int m_MaxSeating;
    int m_price;
    void m_UpdatePrice(int base=500000){
        m_price=m_MaxSeating*base;
    }
    public:
    string m_brand;
    string m_model;
    int m_year;

    Car(string x,string y,int z,int s){
        m_brand=x;
        m_model=y;
        m_year=z;
        m_MaxSeating=s;
        m_UpdatePrice();
        m_DriveMode="No-wheel";
    }
    int get_MaxSeatint(){
        return m_MaxSeating;
    }
    int get_Price(){
        return m_price;
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
    int get_Gas_grade(){
        return m_Fueltank.get_Gas_grade();
    }
    int set_Gas_grade(int gas){
        return m_Fueltank.set_Gas_grade(gas);
    }
    void fuel_up(int v,int gas){
        if(v<=m_Fueltank.get_F()&&gas==m_Fueltank.get_Gas_grade())cout<<"fuel_up: "<<v<<" Gas_grade: "<<gas<<endl;
        else if(v>m_Fueltank.get_F())cout<<"Erroe: FueltankCapacity: "<<m_Fueltank.get_F()<<"but fuel up: "<<v<<endl;
        else if(gas!=m_Fueltank.get_Gas_grade())cout<<"Error: Gas_grade: "<<m_Fueltank.get_Gas_grade()<<" Correct Gas_grade: "<<gas<<endl;
        
    }
    
};
class BMW_Car : public Car{

    public:
    BMW_Car(string y,int z,int s):Car("BMW",y,z,s){
        cout<<"Constructing BMW_Car\n";
        m_DriveMode="Rear-wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};
class AUDI_Car : public Car{

    public:
    AUDI_Car(string y,int z,int s):Car("Audi",y,z,s){
        cout<<"Constructing AUDI_Car\n";
        m_DriveMode="Front-wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};
class BENZ_Car : public Car{

    public:
    BENZ_Car(string y,int z,int s):Car("Benz",y,z,s){
        cout<<"Constructing BENZ_Car\n";
        m_DriveMode="Front-wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};
    
int main(){
    BMW_Car car_1("X5",2023,6);
    cout<<car_1.m_brand<<" : Max Seating = "<<car_1.get_DriveMode()<<endl;
    AUDI_Car car_2("A1",2021,2);
    cout<<car_2.m_brand<<" : Max Seating = "<<car_2.get_DriveMode()<<endl;
    BENZ_Car car_3("C-class",2022,5);
    cout<<car_3.m_brand<<" : Max Seating = "<<car_3.get_DriveMode()<<endl;
    car_2.set_Gas_grade(95);
    car_2.fuel_up(100,98);

}