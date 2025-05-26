#include <iostream>
#include "Login.h"
#include "Member.h"
#include "Bicycle.h"

class SelectRentedBicycle {
private:
    Login* login;

public:
    SelectRentedBicycle(Login* login) : login(login) {}

    std::vector<BicycleDetails> searchRentedBicycle() {
        std::vector<BicycleDetails> result;

        User* user = login->getLoginUser();
        if (user == nullptr) {
            std::cout << "로그인이 필요합니다." << std::endl;
            return;
        }

        Member* member = dynamic_cast<Member*>(user);
        if (member == nullptr) {
            std::cout << "일반 회원만 대여 목록을 조회할 수 있습니다." << std::endl;
            return;
        }

        const std::vector<Bicycle>& rentedBicycles = member->listBicycles();

        if (rentedBicycles.empty()) {
            std::cout << "대여한 자전거가 없습니다." << std::endl;
            return;
        }

        for (const auto& bike : rentedBicycles) {
            result.push_back(bike.getBicycleDetails());
        }

        return result;
    }
};