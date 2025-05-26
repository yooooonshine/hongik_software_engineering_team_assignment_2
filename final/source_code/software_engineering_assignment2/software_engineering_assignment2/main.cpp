// ��� ����
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

// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask();
void join();
void program_exit();

// ���� ����
ofstream out_fp;
ifstream in_fp;

int main()
{
	// ���� ������� ���� �ʱ�ȭ
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);

	doTask();


	out_fp.close();
	in_fp.close();

	return 0;
}

void doTask()
{
    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    // Manager ��ü ����
    UserManager* userManager = new UserManager();
    BicycleManager* bicycleManager = new BicycleManager();

    Login* login = new Login(userManager);

    // ������ ���̵� ����
    Admin* admin = new Admin("admin", "admin");
    userManager->addUser(*admin);


    while (!is_program_exit)
    {
        // �Է����Ͽ��� �޴� ���� 2���� �б�
        in_fp >> menu_level_1 >> menu_level_2;


        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:
                // 1 1 ȸ������
                AddMember * addMember = new AddMember(userManager);
                AddMemberUI* addMemberUI = new AddMemberUI(addMember);

                
                char ID[MAX_STRING], password[MAX_STRING], phoneNumber[MAX_STRING];
                in_fp >> ID >> password >> phoneNumber;

                addMemberUI->addNewMember(ID, password, phoneNumber);

                out_fp << "1.1. ȸ������" << endl;
                out_fp << ID << password << phoneNumber << endl;

                break;
            }
        case 2:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                // 2 1 �α���
                LoginUI* loginUI = new LoginUI(login);

                char ID[MAX_STRING], password[MAX_STRING];
                in_fp >> ID >> password;

                loginUI->login(ID, password);

                out_fp << "2.1. �α���" << endl;
                out_fp << ID << password << endl;

                break;
            }
            case 2:
            {
                // 2 2 �α׾ƿ�
                Logout* logout = new Logout(login);
                LogoutUI* logoutUI = new LogoutUI(logout);

                string id = logoutUI->logout();

                out_fp << "2.2. �α׾ƿ�" << endl;
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
                // 3 1 �����ŵ��
                EnrollBicycle* enrollBicycle = new EnrollBicycle(bicycleManager);
                EnrollBicycleUI* enrollBicycleUI = new EnrollBicycleUI(enrollBicycle);

                char ID[MAX_STRING], name[MAX_STRING];
                in_fp >> ID >> name;

                enrollBicycleUI->enrollBicycle(ID, name);


                out_fp << "3.1. ������ ���" << endl;
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
                // 4 1 �����Ŵ뿩
                RentBicycle* rentBicycle = new RentBicycle(login, bicycleManager);
                RentBicycleUI* rentBicycleUI = new RentBicycleUI(rentBicycle);

                char ID[MAX_STRING];
                in_fp >> ID;

                BicycleDetails bicycleDetails = rentBicycleUI->rentBicycle(ID);


                out_fp << "4.1. ������ �뿩" << endl;
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
                // 5 1 �����Ŵ뿩 ����Ʈ
                SelectRentedBicycle* selectRentedBicycle = new SelectRentedBicycle(login);
                SelectRentedBicycleUI* selectRentedBicycleUI = new SelectRentedBicycleUI(selectRentedBicycle);

                std::vector<BicycleDetails> details = selectRentedBicycleUI->searchRentedBicycle();

                out_fp << "5.1. ������ �뿩 ����Ʈ" << endl;
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
                // 6 1 ����
                is_program_exit = 1;
                break;
            }
            }
        }
        }
    }
}
