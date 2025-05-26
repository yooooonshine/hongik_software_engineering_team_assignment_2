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
            std::cout << "�α����� �ʿ��մϴ�." << std::endl;
            return;
        }

        Member* member = dynamic_cast<Member*>(user);
        if (member == nullptr) {
            std::cout << "�Ϲ� ȸ���� �뿩 ����� ��ȸ�� �� �ֽ��ϴ�." << std::endl;
            return;
        }

        const std::vector<Bicycle>& rentedBicycles = member->listBicycles();

        if (rentedBicycles.empty()) {
            std::cout << "�뿩�� �����Ű� �����ϴ�." << std::endl;
            return;
        }

        for (const auto& bike : rentedBicycles) {
            result.push_back(bike.getBicycleDetails());
        }

        return result;
    }
};