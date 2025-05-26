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
            std::cout << "로그인한 사용자만 대여할 수 있습니다." << std::endl;
            return;
        }

        Member* member = dynamic_cast<Member*>(user);
        if (member == nullptr) {
            std::cout << "일반 사용자만 자전거를 대여할 수 있습니다." << std::endl;
            return;
        }

        Bicycle* bicycle = bicycleManager->findBicycleById(bicycleId);
        if (bicycle == nullptr) {
            std::cout << "해당 ID의 자전거가 존재하지 않습니다." << std::endl;
            return;
        }

        member->rent(*bicycle);

        return bicycle->getBicycleDetails();
    }
};