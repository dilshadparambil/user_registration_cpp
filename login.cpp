#include <iostream>
#include <fstream>
#include <string>

class page{
    std::string uname,email,psswrd,searchname,searchpass,searchemail;
    std::fstream file;
    public:
    void login();
    void signup();
    void forgot();

}obj;

int main(){

    int choice;
    
    std::cout<<"1) login\n";
    std::cout<<"2) signup\n";
    std::cout<<"3) forgot password\n";
    std::cout<<"4) exit\n";
    std::cout<<"enter choice : ";
    std::cin>>choice;

    switch(choice){
        case 1 :
            obj.login();
            break;
        case 2 :
            obj.signup();
            break;
        case 3 :
            obj.forgot();
            break;
        case 4 :
            return 0;
        default :
            std::cout<<"invalid choice";
            break;
    }

   
}

void page::signup(){
    std::cin.ignore();
    std::cout<<"\nenter username : ";
    getline(std::cin,uname);
    std::cout<<"enter email : ";
    getline(std::cin,email);
    std::cout<<"enter password : ";
    getline(std::cin,psswrd);
    file.open("logindata.txt",std::ios::out|std::ios::app);
    file<<uname<<"*"<<email<<"*"<<psswrd<<std::endl;
    file.close();
}

void page::login(){
    std::cin.ignore();
    std::cout<<"------------login-------------\n";
    std::cout<<"enter username : ";
    getline(std::cin,searchname);
    std::cout<<"enter password : ";
    getline(std::cin,searchpass);

    file.open("logindata.txt",std::ios::in);
    getline(file,uname,'*');
    getline(file,email,'*');
    getline(file,psswrd,'\n');
    while(!file.eof()){
        
        if(uname==searchname){
            if (psswrd==searchpass)
            {
                std::cout<<"login successfull\n";
            }
            else{
                std::cout<<"login failed\npassword is incorrect\n";
            }
            
        }
        getline(file,uname,'*');
        getline(file,email,'*');
        getline(file,psswrd,'\n');

    }

    file.close();
}

void page::forgot(){
    std::cin.ignore();
    std::cout<<"enter username : ";
    getline(std::cin,searchname);
    std::cout<<"enter email : ";
    getline(std::cin,searchemail);
    
    file.open("logindata.txt",std::ios::in);
    
    bool flag=false;

    while(!file.eof()){
        getline(file,uname,'*');
        getline(file,email,'*');
        getline(file,psswrd,'\n');
        if(uname==searchname&&email==searchemail){
            std::cout<<"user found\n";
            std::cout<<"pasword is: "<<psswrd<<std::endl;
            flag=true;
            break;
        }
    }
    if(!flag){
        std::cout<<"not found....\n";
    }

    file.close();

}