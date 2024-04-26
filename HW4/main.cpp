#include <iostream>
using namespace std;
class isOX{
    private:
        int NUM;
        int OorX=0;
        bool isNULL=true;
    public:
        bool get_isNULL(){
            return isNULL;
        }
        int getOorX(){
            return OorX;
        }
        int getNUM(){
            return NUM;
        }
        void putOorX(int n){
            OorX=n+1;
            isNULL=false;
        }
        void putNUM(int n){
            NUM=n;
        }
};
class TicTacToe{
    private:
        isOX _isOX[10];
        int times=0;
        char OX[3]={'N','X','O'};
    public:
        void run(){
            for(int i=1;i<10;i++){
                _isOX[i].putNUM(i);
            }
            while(times<9){
                cout<<"-- Tic Tac Toe -- CSIE@CGU"<<endl<<"Player 1 (X) - Player 2 (O)"<<endl;
                draw();
                (times%2==0)?cout<<"player 1 ,請輸入1~9的數字:":cout<<"player 2 ,請輸入1~9的數字:";
                bool cin_check=false;
                while(!cin_check){
                    int _CIN;
                    cin>>_CIN;
                    cout<<endl;
                    if(_CIN>0&&_CIN<10&&_isOX[_CIN].get_isNULL()){
                        cin_check=true;
                        _isOX[_CIN].putOorX(times%2);
                        if(winwin(times%2))return;
                        times++;
                    }    
                    else cout<<"請重新輸入下一步:";
                }
            }
            draw();
            cout<<"==> game draw"<<endl;
            return;
        }
        void draw(){
            cout<<"     ■     ■     "<<endl;
            (_isOX[1].get_isNULL())?cout<<"  "<<_isOX[1].getNUM()<<"  ■":cout<<"  "<<OX[_isOX[1].getOorX()]<<"  ■";
            (_isOX[2].get_isNULL())?cout<<"  "<<_isOX[2].getNUM()<<"  ■":cout<<"  "<<OX[_isOX[2].getOorX()]<<"  ■";
            (_isOX[3].get_isNULL())?cout<<"  "<<_isOX[3].getNUM()<<"  ":cout<<"  "<<OX[_isOX[3].getOorX()]<<"  ";
            cout<<endl<<"     ■     ■     "<<endl<<"■■■■■■■■■■■■■■■■"<<endl<<"     ■     ■     "<<endl;   
            (_isOX[4].get_isNULL())?cout<<"  "<<_isOX[4].getNUM()<<"  ■":cout<<"  "<<OX[_isOX[4].getOorX()]<<"  ■";
            (_isOX[5].get_isNULL())?cout<<"  "<<_isOX[5].getNUM()<<"  ■":cout<<"  "<<OX[_isOX[5].getOorX()]<<"  ■";
            (_isOX[6].get_isNULL())?cout<<"  "<<_isOX[6].getNUM()<<"  ":cout<<"  "<<OX[_isOX[6].getOorX()]<<"  ";
            cout<<endl<<"     ■     ■     "<<endl<<"■■■■■■■■■■■■■■■■"<<endl<<"     ■     ■     "<<endl;   
            (_isOX[7].get_isNULL())?cout<<"  "<<_isOX[7].getNUM()<<"  ■":cout<<"  "<<OX[_isOX[7].getOorX()]<<"  ■";
            (_isOX[8].get_isNULL())?cout<<"  "<<_isOX[8].getNUM()<<"  ■":cout<<"  "<<OX[_isOX[8].getOorX()]<<"  ■";
            (_isOX[9].get_isNULL())?cout<<"  "<<_isOX[9].getNUM()<<"  ":cout<<"  "<<OX[_isOX[9].getOorX()]<<"  ";
            cout<<endl<<"     ■     ■     "<<endl;
        }
        bool winwin(int n){
            if((((_isOX[5].getOorX()==_isOX[4].getOorX()&&_isOX[5].getOorX()==_isOX[6].getOorX()))||
                ((_isOX[5].getOorX()==_isOX[2].getOorX()&&_isOX[5].getOorX()==_isOX[8].getOorX()))||
                ((_isOX[5].getOorX()==_isOX[1].getOorX()&&_isOX[5].getOorX()==_isOX[9].getOorX()))||
                ((_isOX[5].getOorX()==_isOX[3].getOorX()&&_isOX[5].getOorX()==_isOX[7].getOorX())))&&
                _isOX[5].getOorX()!=0){
                draw();
                (n==0)?cout<<"==>player 1 win"<<endl:cout<<"==>player 2 win"<<endl;
                }
            else if((((_isOX[1].getOorX()==_isOX[2].getOorX()&&_isOX[1].getOorX()==_isOX[3].getOorX()))||
                   ((_isOX[1].getOorX()==_isOX[4].getOorX()&&_isOX[1].getOorX()==_isOX[7].getOorX())))&&_isOX[1].getOorX()!=0){
                draw();
                (n==0)?cout<<"==>player 1 win"<<endl:cout<<"==>player 2 win"<<endl;
                }
            else if((((_isOX[3].getOorX()==_isOX[9].getOorX()&&_isOX[6].getOorX()==_isOX[9].getOorX()))||
                   ((_isOX[7].getOorX()==_isOX[9].getOorX()&&_isOX[8].getOorX()==_isOX[9].getOorX())))&&_isOX[9].getOorX()!=0){
                draw();
                (n==0)? cout<<"==>player 1 win"<<endl:cout<<"==>player 2 win"<<endl;
                }
            else return false;
            return true;
        }
};
int main()
{
    TicTacToe game;
    game.run();
    return 0;
}