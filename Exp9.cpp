#include<iostream>
#include<fstream>

using namespace std;

class student{
    private:
        char name[30];
        int rollNo, sem;
        float mMath, mPhysics, mEnglish, mHindi, mCS, mHistory, mTotal;
    public:
        void read(){
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter RollNO: ";
            cin>>rollNo;
            cout<<"Enter Semester: ";
            cin>>sem;
            cout<<"Enter Marks: ";
            cin>>mMath>>mPhysics>>mEnglish>>mHindi>>mCS>>mHistory;
            mTotal = mMath + mPhysics + mEnglish + mHindi + mCS + mHistory;
        }

        void display(){
            cout << "\n";
            cout << "Name: " << name << endl;
            cout << "Roll No: "<< rollNo << endl;
            cout << "Sem: " << sem << endl;
            cout<<"Math : "<<mMath<<endl;
            cout<<"Physics : "<<mPhysics<<endl;
            cout<<"English : "<<mEnglish<<endl;
            cout<<"Hindi : "<<mHindi<<endl;
            cout<<"CS : "<<mCS<<endl;
            cout<<"History : "<<mHistory<<endl;
            cout<<"Total : "<<mTotal<<endl;
        }

        bool chk(){
            if( mTotal > 300 )   return true;
            return false;
        }
};

int main(){
    fstream stuRegister, stuFail, stuPass;
    student stuObj;
    char ch = 'a';
    do{
        cout<<"\nMENU\n1).Input Student Data\n2).Display All Students\n3).Display Failed Students\n4).Display Passed Students\nPlease Enter Your Choice : ";
        cin>>ch;
        switch(ch){
            case '1':
                stuObj.read();
                stuRegister.open("Student.dat", ios::binary|ios::out|ios::app);
                stuFail.open("fail.dat", ios::binary|ios::out|ios::app);
                stuPass.open("pass.dat", ios::binary|ios::out|ios::app);
                stuRegister.write( (char*) &stuObj, sizeof(stuObj) );
                if(stuObj.chk())    
                    stuPass.write( (char*) &stuObj, sizeof(stuObj) );
                else
                    stuFail.write( (char*) &stuObj, sizeof(stuObj) );
                stuRegister.close();
                stuFail.close();
                stuPass.close();
                break;
            case '2':
                stuRegister.open("Student.dat", ios::binary|ios::in);
                while(1){
                    stuRegister.read((char*)&stuObj, sizeof(stuObj));
                    if(stuRegister.eof())   break;
                    stuObj.display();
                    cout<<endl;
                }
                stuRegister.close();
                break;
            case '3':
                stuFail.open("fail.dat", ios::binary|ios::in);
                while(1){
                    stuFail.read((char*)&stuObj, sizeof(stuObj));
                    if(stuFail.eof())   break;
                    stuObj.display();
                    cout<<endl;
                }
                stuPass.close();
                break;
            case '4':
                stuPass.open("pass.dat", ios::binary|ios::in);
                while(1){
                    stuPass.read((char*)&stuObj, sizeof(stuObj));
                    if(stuPass.eof())   break;
                    stuObj.display();
                    cout<<endl;
                }
                stuPass.close();
                break;
        }
    }while(ch != '0');
    return 0;
}
