#include <iostream>
#include <string>
#include "Login.cpp"
#include "BicycleManager.h"
#include "Member.h"
#include "BicycleDetails.h"

class RentBicycle {
private:
    Login* login;
    BicycleManager* bicycleManager;

public:
    RentBicycle(Login* login, BicycleManager* bicycleManager)
        : login(login), bicycleManager(bicycleManager) {
    }

    BicycleDetails rentBicycle(const std::string& bicycleId) {
        User* user = login->getLoginUser();

        if (user == nullptr) {
            std::cout << "�α����� ����ڸ� �뿩�� �� �ֽ��ϴ�." << std::endl;
            return;
        }

        Member* member = dynamic_cast<Member*>(user);
        if (member == nullptr) {
            std::cout << "�Ϲ� ����ڸ� �����Ÿ� �뿩�� �� �ֽ��ϴ�." << std::endl;
            return;
        }

        Bicycle* bicycle = bicycleManager->findBicycleById(bicycleId);
        if (bicycle == nullptr) {
            std::cout << "�ش� ID�� �����Ű� �������� �ʽ��ϴ�." << std::endl;
            return;
        }

        member->rent(*bicycle);

        return bicycle->getBicycleDetails();
    }
};