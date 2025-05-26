// 헤더 선언
#include <iostream>
#include <fstream>
#include <string>
#include "UserManager.cpp"
#include "AddMemberUI.cpp"
#include "Login.cpp"
#include "LoginUI.cpp"
#include "Admin.h"
#include "BicycleManager.cpp"
#include "Logout.cpp"
#include "LogoutUI.cpp"
#include "EnrollBicycle.cpp"
#include "EnrollBicycleUI.cpp"
#include "RentBicycle.cpp"
#include "RentBicycleUI.cpp"
#include "SelectRentedBicycle.cpp"
#include "SelectRentedBicycleUI.cpp"
#include "BicycleDetails.h"

using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join();
void program_exit();

// 변수 선언
ofstream out_fp;
ifstream in_fp;

int main()
{
	// 파일 입출력을 위한 초기화
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);

	doTask();


	out_fp.close();
	in_fp.close();

	return 0;
}

void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    // Manager 객체 생성
    UserManager* userManager = new UserManager();
    BicycleManager* bicycleManager = new BicycleManager();

    Login* login = new Login(userManager);

    // 관리자 아이디 생성
    Admin* admin = new Admin("admin", "admin");
    userManager->addUser(*admin);


    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        in_fp >> menu_level_1 >> menu_level_2;


        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:
                // 1 1 회원가입
                AddMember * addMember = new AddMember(userManager);
                AddMemberUI* addMemberUI = new AddMemberUI(addMember);

                
                char ID[MAX_STRING], password[MAX_STRING], phoneNumber[MAX_STRING];
                in_fp >> ID >> password >> phoneNumber;

                addMemberUI->addNewMember(ID, password, phoneNumber);

                out_fp << "1.1. 회원가입" << endl;
                out_fp << ID << password << phoneNumber << endl;

                break;
            }
        case 2:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                // 2 1 로그인
                LoginUI* loginUI = new LoginUI(login);

                char ID[MAX_STRING], password[MAX_STRING];
                in_fp >> ID >> password;

                loginUI->login(ID, password);

                out_fp << "2.1. 로그인" << endl;
                out_fp << ID << password << endl;

                break;
            }
            case 2:
            {
                // 2 2 로그아웃
                Logout* logout = new Logout(login);
                LogoutUI* logoutUI = new LogoutUI(logout);

                string id = logoutUI->logout();

                out_fp << "2.2. 로그아웃" << endl;
                out_fp << id << endl;

                break;
            }
            }
        }
        case 3:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                // 3 1 자전거등록
                EnrollBicycle* enrollBicycle = new EnrollBicycle(bicycleManager);
                EnrollBicycleUI* enrollBicycleUI = new EnrollBicycleUI(enrollBicycle);

                char ID[MAX_STRING], name[MAX_STRING];
                in_fp >> ID >> name;

                enrollBicycleUI->enrollBicycle(ID, name);


                out_fp << "3.1. 자전거 등록" << endl;
                out_fp << ID << name << endl;

                break;
            }
            }
        }
        case 4:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                // 4 1 자전거대여
                RentBicycle* rentBicycle = new RentBicycle(login, bicycleManager);
                RentBicycleUI* rentBicycleUI = new RentBicycleUI(rentBicycle);

                char ID[MAX_STRING];
                in_fp >> ID;

                BicycleDetails bicycleDetails = rentBicycleUI->rentBicycle(ID);


                out_fp << "4.1. 자전거 대여" << endl;
                out_fp << ID << bicycleDetails.name << endl;

                break;
            }
            }
        }
        case 5:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                // 5 1 자전거대여 리스트
                SelectRentedBicycle* selectRentedBicycle = new SelectRentedBicycle(login);
                SelectRentedBicycleUI* selectRentedBicycleUI = new SelectRentedBicycleUI(selectRentedBicycle);

                std::vector<BicycleDetails> details = selectRentedBicycleUI->searchRentedBicycle();

                out_fp << "5.1. 자전거 대여 리스트" << endl;
                for (const auto& bicycleDetails : details) {
                    out_fp << bicycleDetails.id << " " << bicycleDetails.name << endl;
                }

                break;
            }
            }
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                // 6 1 종료
                is_program_exit = 1;
                break;
            }
            }
        }
        }
    }
}
